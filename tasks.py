from invoke import task, run
import codecs
import shutil
import os
from urllib.parse import quote_plus
import re
from pprint import pprint

def change_dir(dir=None):
    working_dir = os.path.abspath(os.path.dirname(__file__))
    if dir:
        working_dir = os.path.join(working_dir, dir)
    os.chdir(working_dir)

change_dir()


def replace_file_regex(filepath, search, replace):
    with open(filepath, "r+") as f:
        content = f.read()
        content = re.sub(search, replace, content)
        f.seek(0)
        f.write(content)
        f.truncate()


def grep_file_regex(filepath, searchRegex):
    with open(filepath, "r") as fd:
        content = fd.read()
        return re.search(searchRegex, content)


@task
def up(c, build=False):
    change_dir()
    c.run("docker-compose up -d" + (' --build' if build else ''))
    dns_reload(c)
    config(c)


def get_container_ip(name):
    ip = run(
        r"docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' " + name, hide='out').stdout
    ip = ip.replace("\n", "")
    return ip


@task
def ip(c):
    '''
    Show all current container ips
    '''
    conainters = c.run(r"docker container ls --format '{{.Names}}'", hide='out').stdout.split("\r\n")[:-1]
    for container in conainters:
        debug(get_container_ip(container))

@task
def dns_reload(c):
    openresty_ip = get_container_ip("openresty-waf")
    dvwa_ip = get_container_ip("dvwa-test")
    nginx_ip = get_container_ip("nginx-test")
    mongodb_ip = get_container_ip("waf-log-db")
    # domains = ['dvwa.test', 'nginx.test', 'openresty.docker']

    config = f'''
address=/openresty.docker/{openresty_ip}
address=/dvwa.test/{dvwa_ip}
address=/nginx.test/{nginx_ip}
address=/mongo.docker/{mongodb_ip}
'''

    c.run(
        f"sudo bash -c \"echo '{config}' > /etc/dnsmasq.d/docker-config.conf\"", pty=False)

    c.run("sudo systemctl restart dnsmasq", pty=False)


@task
def init_vscode(c):
    change_dir()
    has_vscode = shutil.which("code")
    if not has_vscode:
        print("[x] Please install vscode")
        return
    c.run("code .")
    folder_uri = 'vscode-remote://attached-container+' + \
        codecs.encode(b'{"containerName":"waf_openresty_1"}',
                      'hex').decode() + '/opt/modsecurity'
    c.run(f"code --folder-uri '{folder_uri}'")


@task
def reload(c, proxy=False, all=False):
    change_dir()
    if all:
        c.run("docker-compose exec openresty nginx -s reload")
        c.run("docker-compose exec proxy-server nginx -s reload")
    elif proxy:
        c.run("docker-compose exec proxy-server nginx -s reload")
    else:
        c.run("docker-compose exec openresty nginx -s reload")


@task
def restart(c, proxy=False):
    change_dir()
    c.run("docker-compose exec openresty supervisorctl restart all")
    if proxy:
        c.run("docker-compose exec proxy-server supervisorctl restart all")


@task
def log(c, all=False, proxy=False, tail=100):
    change_dir()
    if all:
        services = ''
    elif proxy:
        services = 'proxy-server'
    else:
        services = 'openresty'
    c.run(f'docker-compose logs -f --tail {tail} {services}')


@task
def modsec_log_level(c, level):
    change_dir()
    level = int(level)
    if level < 1 or level > 9:
        debug("Invalid level")
        return
    debug(f"Change modsecurity log level to {level}")
    replace_file_regex("./openresty/modsecurity/modsecurity.conf",
                       'SecDebugLogLevel \\d', f'SecDebugLogLevel {level}')
    c.run("docker-compose exec openresty nginx -s reload")


@task
def modsec_rebuild(c):
    change_dir()
    bash_cmd = 'cd /opt/modsecurity && make -j4 && make install && supervisorctl restart all'
    c.run("docker-compose exec openresty bash -c '{}'".format(bash_cmd))


@task(iterable=['domains'])
def gen_ssl(c, domains=[]):
    change_dir()
    if len(domains) < 1:
        domains = [
            'google.com',
            '*.google.com',
            'messenger.com',
            '*.messenger.com',
            'facebook.com',
            '*.facebook.com',
            'youtube.com',
            '*.youtube.com',
            'github.com',
            '*.github.com',
            'hcmut.edu.vn',
            '*.hcmut.edu.vn',
            'vzota.com.vn',
            '*.vzota.com.vn',
            'overleaf.com',
            '*.overleaf.com',
            'discord.com',
            '*.discord.com'
        ]
    c.run('mkcert -cert-file ./openresty/nginx/ssl/localhost.pem -key-file ./openresty/nginx/ssl/localhost-key.pem ' + ' '.join(domains))
    c.run('docker-compose exec openresty nginx -s reload')


@task
def test(c, url='https://ntsec.cf', attack=False):
    if not attack:
        c.run(
            f'http_proxy=http://localhost:3004 https_proxy=http://localhost:3004 curl -ik -L {url}')
    else:
        c.run('http_proxy=http://localhost:3004 curl -ik -v http://ntsec.cf?x=' +
              quote_plus('; cat /etc/passwd'))


def waf_mode_update(c, mode):
    '''
    Update current WAF mode
    '''
    change_dir()
    mode = mode.upper()
    support_modes = ['LEARNING_ATTACK', 'LEARNING_NORMAL',
                     'LEARNING_UNKNOWN', 'PRODUCTION']
    if mode not in support_modes:
        print("Error: waf mode must be in " + ', '.join(support_modes))
        return
    debug("Change waf mode to " + mode)
    replace_file_regex("./openresty/modsecurity-crs/custom-rules.conf",
                       'setvar:TX.WAF_MODE=[\\w_]+\\b', f'setvar:TX.WAF_MODE={mode}')
    reload(c)
    waf_mode(c)


def waf_mode(c):
    '''
    Show current WAF mode
    '''
    change_dir()
    waf_mode = grep_file_regex(
        "./openresty/modsecurity-crs/custom-rules.conf", "setvar:TX.WAF_MODE=([\\w_]+)\\b").group(1)
    debug(f"Current waf mode is {waf_mode}")
    return waf_mode


@task
def csic_transform(c):
    '''
    Transform CSIC 2010 dataset by passing it to openresty WAF
    Automatically change collection prefix to csic and revert back
    '''

    old_config = config(c)
    pprint(old_config)
    change_dir('./tools/gen-traffic')
    try:
        c.run('MAX_BUFFER_SIZE=10 node run.js csic-transform http://nginx.test -vv')
    except:
        print("\n")
        debug("Interrupted")
    finally:
        config_update(c, prefix=old_config["prefix"], mode=old_config["mode"])


@task
def ecml_transform(c):
    '''
    Transform ECML PKDD dataset by passing it to openresty WAF
    Automatically change collection prefix to ecml_pkdd and revert back
    '''

    old_config = config(c)
    pprint(old_config)
    change_dir('./tools/gen-traffic')
    try:
        c.run('MAX_BUFFER_SIZE=50 node run.js ecml-transform http://nginx.test -vv')
    except:
        print("\n")
        debug("Interrupted")
    finally:
        config_update(c, prefix=old_config["prefix"], mode=old_config["mode"])


def update_prefix(c, prefix):
    change_dir()
    debug(f"Change collection prefix to '{prefix}'")
    replace_file_regex('.env', "COLLECTION_PREFIX=.*",
                       f"COLLECTION_PREFIX={prefix}")
    up(c)
    get_prefix(c)


def get_prefix(c):
    change_dir()
    prefix = grep_file_regex(".env", "COLLECTION_PREFIX=(.*)").group(1)
    debug(f"Current collection prefix is '{prefix}'")
    return prefix


@task
def config_update(c, prefix='', mode='learning_normal'):
    '''
    Update WAF config
    '''
    update_prefix(c, prefix)
    waf_mode_update(c, mode)


@task
def config(c):
    '''
    Get WAF config
    '''
    prefix = get_prefix(c)
    mode = waf_mode(c)
    debug('Current DNS config')
    c.run("cat /etc/dnsmasq.d/docker-config.conf")

    return {
        "prefix": prefix,
        "mode": mode
    }


def debug(*msg):
    print('[+]', *msg)


@task
def ml_rebuild(c):
    '''
    Rebuild ML model and restart WAF
    '''
    change_dir()
    c.run("docker-compose exec openresty bash -c 'cd /opt/modsecurity-crs/lua-scripts/ml-model && make'")
    restart(c)


@task(help={
    'name': 'decision_tree | random_forest'
})
def ml_update(c):
    '''
    Copy new model code and rebuild
    '''
    change_dir()
    from tools.ml_util.export_model import export_all

    export_all()

    for name in ['decision_tree', 'random_forest']:
        debug(f"Update model {name}")
        try:
            with open(f"./tools/ml_util/output/{name}.c", "r") as fd:
                model_C_code = fd.read()

            output_C_code = f'''
{model_C_code}

#define N_FEAFURES 159
#define STR_INDIR(s) #s
#define STR(s) STR_INDIR(s)
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

static int l_predict(lua_State *L) {{
    int nargs = lua_gettop(L);
    if (nargs < 1) {{
        lua_pushstring(L, "Missing positional argument: features (table)");
        lua_error(L);
    }}

    // ignore other arguments
    lua_settop(L, 1);

    luaL_checktype(L, 1, LUA_TTABLE);
    int input_table_length = lua_objlen(L, 1);
    printf("Input features: %d\\n", input_table_length);

    if (input_table_length != N_FEAFURES) {{
        lua_pushstring(L, "Wrong number of features (required " STR(N_FEAFURES) " features)");
        lua_error(L);
    }}

    float features[N_FEAFURES];
    int i = 0;
    lua_pushnil(L);
    while (lua_next(L, 1) != 0) {{
        features[i++] = luaL_checknumber(L, -1);
        lua_pop(L, 1);
    }}

    int result = predict(features);
    lua_pushnumber(L, result);
    return 1;
}}

static const struct luaL_reg funcs[] = {{
    {{ "predict", l_predict }},
    {{ NULL, NULL }}
}};

int luaopen_{name}(lua_State *L) {{
    luaL_register(L, "{name}", funcs);
    return 0;
}}
'''
            with open(f"./openresty/modsecurity-crs/lua-scripts/ml-model/{name}.c", "w+") as fd:
                fd.write(output_C_code)

        except Exception as e:
            debug("Failed to update model")
            debug(e)
        
    ml_rebuild(c)

@task
def pull_drive(c):
    change_dir("ml-model")
    c.run("rclone copy drive:/project/waf/train.ipynb .")
    c.run("rclone copy drive:/project/waf/saved-models ./saved-models")
    c.run("rclone copy drive:/project/waf/images ./images")