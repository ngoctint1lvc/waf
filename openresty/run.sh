#!/bin/bash

set -x

# build modsecurity
cd /opt/modsecurity
if [ ! -f ./Makefile ]; then
    sh build.sh && ./configure --with-yajl --with-lua
fi
make -j4 && make install

# build openresty
cd /root/openresty
if [ ! -f ./Makefile ]; then
    ./configure -j4 \
    --with-pcre-jit \
    --with-compat \
    --with-http_ssl_module \
    --with-http_realip_module \
    --with-debug \
    --add-dynamic-module=/opt/modsecurity-nginx
fi
make -j4 && make install

ln -sf /proc/1/fd/1 /var/log/supervisor/supervisord.log
supervisord -n -c /etc/supervisor/supervisord.conf