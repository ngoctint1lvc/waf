FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y apt-utils && \
    apt-get install -y net-tools iputils-ping wget supervisor \
    libpcre3-dev libssl-dev perl make build-essential curl zip \
    zlib1g zlib1g-dev libgeoip-dev git libtool automake autoconf \
    cmake libxml2 libxml2-dev

WORKDIR /root

RUN wget https://openresty.org/download/openresty-1.15.8.2.tar.gz && \
    tar -axf openresty-1.15.8.2.tar.gz

# download and compile yajl
RUN (wget http://github.com/lloyd/yajl/zipball/2.1.0 -O yajl.zip && \
    unzip yajl.zip && mv lloyd* yajl && rm yajl.zip && \
    cd yajl && ./configure && make && make install)

RUN git clone --depth=1 https://github.com/ngoctint1lvc/ModSecurity.git /opt/ModSecurity

RUN git clone --depth=1 https://github.com/ngoctint1lvc/ModSecurity-nginx.git /opt/ModSecurity-nginx

RUN (cd /opt/ModSecurity && \
    sh build.sh && \
    git submodule init && \
    git submodule update && \
    ./configure --with-yajl && \
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

RUN mkdir -p /etc/modsecurity && \
    cp /opt/ModSecurity/unicode.mapping /etc/modsecurity/unicode.mapping

# clean files
# RUN rm -rf ./*

COPY run.sh /run.sh

CMD ["/run.sh"]