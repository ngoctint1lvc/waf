FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y apt-utils && \
    apt-get install -y net-tools iputils-ping wget supervisor \
        libpcre3-dev libssl-dev perl make build-essential curl \
        zlib1g zlib1g-dev libgeoip-dev git libtool automake autoconf

WORKDIR /root

RUN wget https://openresty.org/download/openresty-1.15.8.2.tar.gz && \
    tar -axf openresty-1.15.8.2.tar.gz

COPY ./ModSecurity /opt/ModSecurity

COPY ./ModSecurity-nginx /opt/ModSecurity-nginx

RUN (cd /opt/ModSecurity && \
    sh build.sh && \
    git submodule init && \
    git submodule update && \
    ./configure && \
    make && \
    make install)

RUN (cd openresty-1.15.8.2 && \
    ./configure -j4 \
        --with-pcre-jit \
        --with-ipv6 \
        --add-module=/opt/ModSecurity-nginx && \
    make -j4 && \
    make install)

ENV PATH="/usr/local/openresty/bin:/usr/local/openresty/nginx/sbin:${PATH}"

RUN mkdir -p /etc/modsecurity && mkdir -p /var/log/modsecurity && \
    cp /opt/ModSecurity/unicode.mapping /etc/modsecurity/unicode.mapping

# clean files
RUN rm -rf ./*

COPY run.sh /run.sh

CMD ["/run.sh"]