#!python

import os
import codecs
import subprocess
import sys
from urllib.parse import quote_plus

cmd = 'help' if len(sys.argv) < 2 else sys.argv[1]

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

    folder_uri = 'vscode-remote://attached-container+' + codecs.encode(b'{"containerName":"openresty"}', 'hex').decode() + '/opt/ModSecurity'
    os.system(f"code --folder-uri '{folder_uri}'")
elif cmd == 'init-terminal':
    os.popen('terminator -l waf-luanvan')
elif cmd == 'reload':
    os.system('docker-compose exec openresty nginx -s reload')
elif cmd == 'attack':
    os.system('curl -v http://nginx.test?x=' + quote_plus('; cat /etc/passwd'))
elif cmd == 'log':
    os.system('docker-compose logs -f --tail 100 openresty')
elif cmd == 'rebuild-modsec':
    bash_cmd = 'cd /opt/ModSecurity && make -j4 && make install && supervisorctl restart all'
    os.system("docker-compose exec openresty bash -c '{}'".format(bash_cmd))
elif cmd == 'restart':
    os.system('docker-compose exec openresty supervisorctl restart all')
else:
    print('''\
Command list:
init
init-terminal
reload
attack
log
rebuild-modsec
restart''')
