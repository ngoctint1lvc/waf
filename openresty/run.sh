#!/bin/bash

set -x

ln -sf /proc/1/fd/1 /var/log/supervisor/supervisord.log
supervisord -n -c /etc/supervisor/supervisord.conf