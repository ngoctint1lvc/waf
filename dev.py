#!python

import os
import codecs
import subprocess
import sys
from urllib.parse import quote_plus

cmd = 'help' if len(sys.argv) < 2 else sys.argv[1]
args = sys.argv[2:]

if cmd == 'init':
    exit_code = os.system("docker-compose up -d")
    if exit_code != 0:
        print("[+] Failed to start docker-compose")
        print("[+] Trying to restart docker service")
        os.system("sudo systemctl start docker")
        print("[+] Stopping all running docker containers")
        os.system("docker container ls -q")
        containers = subprocess.check_output("docker container ls -q", shell = True).decode().split("\n")
        for container in containers:
            if container:
                os.system(f"docker stop {container}")
        print("[+] Starting docker-compose")
        os.system("docker-compose up -d")

    os.popen('terminator -l waf-luanvan')
    os.system("code .")

    folder_uri = 'vscode-remote://attached-container+' + codecs.encode(b'{"containerName":"openresty"}', 'hex').decode() + '/opt/modsecurity'
    os.system(f"code --folder-uri '{folder_uri}'")
elif cmd == 'init-terminal':
    os.popen('terminator -l waf-luanvan')
elif cmd == 'reload':
    os.system('docker-compose exec openresty nginx -s reload')
elif cmd == 'attack':
    os.system('curl -ik https://tin.acbpro.com?x=' + quote_plus('; cat /etc/passwd'))
elif cmd == 'log':
    os.system('docker-compose logs -f --tail 100 openresty')
elif cmd == 'rebuild-modsec':
    bash_cmd = 'cd /opt/modsecurity && make -j4 && make install && supervisorctl restart all'
    os.system("docker-compose exec openresty bash -c '{}'".format(bash_cmd))
elif cmd == 'restart':
    os.system('docker-compose exec openresty supervisorctl restart all')
elif cmd == 'gen-ssl':
    os.system('mkcert -cert-file ./openresty/nginx/ssl/localhost.pem -key-file ./openresty/nginx/ssl/localhost-key.pem ' + ' '.join(args))
    os.system('docker-compose exec openresty nginx -s reload')
elif cmd == 'test':
    url = args[0] if len(args) >= 1 else 'https://medium.com'
    os.system('curl -ik {}'.format(url))
elif cmd == 'update-dns':
    os.system('sudo cp ./openresty/dnsmasq.conf /etc/dnsmasq.d/custom.conf')
    os.system('sudo service dnsmasq restart')
else:
    print('''\
Command list:
init
init-terminal
reload
attack
log
test [url]
gen-ssl
rebuild-modsec
update-dns
restart''')
