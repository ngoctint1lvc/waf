from invoke import task
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


def change_dir():
    working_dir = os.path.abspath(os.path.dirname(__file__))
    os.chdir(working_dir)


@task
def dns_reload(c):
    change_dir()
    c.run('sudo cp ./openresty/dnsmasq.conf /etc/dnsmasq.d/custom.conf')
    c.run('sudo service dnsmasq restart')


@task
def dns_start(c):
    change_dir()
    white_lists = [
        'clients4.google.com',
        'acbpro.com',
        'archive.ubuntu.com',
        'mirror.clearsky.vn',
        'download.docker.com',
        'repo.skype.com'
    ]
    with open("./openresty/dnsmasq.conf", "w") as fd:
        fd.write(f"address=/#/127.0.0.1\n")
        for domain in white_lists:
            fd.write(f"server=/{domain}/1.1.1.1\n")
    dns_reload(c)


@task
def dns_stop(c):
    change_dir()
    c.run('sudo rm -f /etc/dnsmasq.d/custom.conf')
    c.run('sudo service dnsmasq restart')


@task
def dns_debug(c, domain):
    change_dir()
    with open("./openresty/dnsmasq.conf", "w") as fd:
        fd.write(f"address=/{domain}/127.0.0.1\n")
    dns_reload(c)


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
def init(c):
    change_dir()
    print("[+] Stopping all running docker containers")
    c.run("zsh -c 'source ~/.zshrc; docker-container-stop'")
    print("[+] Starting docker-compose")
    c.run("docker-compose up -d", pty=True)
    init_terminal(c)
    init_vscode(c)
    dns_start(c)


@task
def init_terminal(c):
    c.run("terminator -l waf-luanvan", asynchronous=True)


@task
def reload(c):
    change_dir()
    c.run("docker-compose exec openresty nginx -s reload", pty=True)


@task
def restart(c):
    change_dir()
    c.run("docker-compose exec openresty supervisorctl restart all", pty=True)


@task
def log(c):
    change_dir()
    c.run('docker-compose logs -f --tail 100 openresty')


@task
def modsec_log_level(c, level):
    change_dir()
    level = int(level)
    if level < 1 or level > 9:
        print("[+] Invalid level")
        return
    print(f"[+] Change modsecurity log level to {level}")
    replace_file_regex("./openresty/modsecurity/modsecurity.conf",
                       'SecDebugLogLevel \\d', f'SecDebugLogLevel {level}')
    c.run("docker-compose exec openresty nginx -s reload", pty=True)


@task
def modsec_rebuild(c):
    change_dir()
    bash_cmd = 'cd /opt/modsecurity && make -j4 && make install && supervisorctl restart all'
    c.run("docker-compose exec openresty bash -c '{}'".format(bash_cmd), pty=True)


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
            '*.github.com'
        ]
    c.run('mkcert -cert-file ./openresty/nginx/ssl/localhost.pem -key-file ./openresty/nginx/ssl/localhost-key.pem ' + ' '.join(domains))
    c.run('docker-compose exec openresty nginx -s reload', pty=True)


@task
def test(c, url='https://ntsec.cf'):
    c.run(f'curl -ik -L {url}')


@task
def test_attack(c):
    change_dir()
    c.run('curl -ik -v http://ntsec.cf?x=' + quote_plus('; cat /etc/passwd'))


@task
def waf_mode(c, mode):
    change_dir()
    support_modes = ['LEARNING_ATTACK', 'LEARNING_NORMAL', 'NORMAL']
    if mode not in support_modes:
        print("Error: waf mode must be in " + ', '.join(support_modes))
        return
    print("[+] Change waf mode to " + mode)
    replace_file_regex("./openresty/modsecurity-crs/custom-rules.conf",
                       'setvar:tx.waf_mode=(LEARNING_NORMAL|LEARNING_NORMAL|NORMAL)', f'setvar:tx.waf_mode={mode}')
    c.run("docker-compose exec openresty nginx -s reload", pty=True)
