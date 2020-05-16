#!/bin/bash

set -x

cd /opt/ModSecurity
git pull
make -j4
make install

ln -sf /proc/1/fd/1 /var/log/supervisor/supervisord.log
supervisord -n -c /etc/supervisor/supervisord.conf