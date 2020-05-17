#!/bin/bash

set -x

# build modsecurity
cd /opt/modsecurity && \
    sh build.sh && \
    ./configure --with-yajl --with-lua && \
    make -j4 && \
    make install

# build openresty
(cd /root/openresty && \
    ./configure -j4 \
    --with-pcre-jit \
    --with-compat \
    --with-http_ssl_module \
    --with-http_realip_module \
    --with-debug \
    --add-dynamic-module=/opt/modsecurity-nginx && \
    make -j4 && \
    make install)

ln -sf /proc/1/fd/1 /var/log/supervisor/supervisord.log
supervisord -n -c /etc/supervisor/supervisord.conf