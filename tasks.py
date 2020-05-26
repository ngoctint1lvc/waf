from invoke import task, run
import codecs
import shutil
import os
from urllib.parse import quote_plus
import re


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


def change_dir(dir=None):
    working_dir = os.path.abspath(os.path.dirname(__file__))
    if dir:
        working_dir = os.path.join(working_dir, dir)
    os.chdir(working_dir)


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
def ip(c, container):
    '''
    Resolve IP of docker container with container name
    '''
    debug(get_container_ip(container))

@task
def dns_reload(c):
    openresty_ip = get_container_ip("openresty-waf")
    domains = ['dvwa.test', 'nginx.test', 'openresty.docker']
    config = '\n'.join(
        [f'address=/{domain}/{openresty_ip}' for domain in domains])
    c.run(
        f"sudo bash -c \"echo '{config}' > /etc/dnsmasq.d/docker-config.conf\"", pty=False)

    mongodb_ip = get_container_ip("waf-log-db")
    c.run(
        f"sudo bash -c 'echo \"address=/mongo.docker/{mongodb_ip}\" >> /etc/dnsmasq.d/docker-config.conf'", pty=False)

    c.run("sudo service dnsmasq restart", pty=False)


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
            '*.vzota.com.vn'
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


@task
def csic_transform(c):
    '''
    Transform CSIC 2010 dataset by passing it to openresty WAF
    Automatically change collection prefix to csic and revert back
    '''

    old_prefix = get_prefix(c)
    update_prefix(c, 'csic')

    change_dir('./tools/gen-traffic')
    c.run('node run.js csic-transform http://nginx.test -vv')

    update_prefix(c, old_prefix)


@task
def ecml_transform(c):
    '''
    Transform ECML PKDD dataset
    '''

    old_prefix = get_prefix(c)
    update_prefix(c, 'ecml_pkdd')
    change_dir('./tools/gen-traffic')
    c.run('node run.js ecml-transform http://nginx.test -vv')
    update_prefix(c, old_prefix)


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
    get_prefix(c)
    waf_mode(c)
    debug('Current DNS config')
    c.run("cat /etc/dnsmasq.d/docker-config.conf")


def debug(*msg):
    print('[+]', *msg)
