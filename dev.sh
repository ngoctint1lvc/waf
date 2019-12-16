#!/bin/bash

if [ -z "$(grep dvwa.test /etc/hosts)" ] && [ -z "$(grep nginx.test /etc/hosts)" ]
then

cat <<HEREDOC | sudo tee -a /etc/hosts
# testing waf for thesis
127.0.0.1 dvwa.test
127.0.0.1 nginx.test
HEREDOC

fi

docker-compose up -d