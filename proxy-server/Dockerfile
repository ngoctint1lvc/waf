FROM ubuntu:18.04

WORKDIR /root

RUN apt-get update && apt-get install -y net-tools iputils-ping wget \
    libpcre3-dev libssl-dev perl make build-essential curl supervisor \
    zlib1g zlib1g-dev dnsmasq

RUN wget https://openresty.org/download/openresty-1.15.8.2.tar.gz && \
    tar -axf openresty-1.15.8.2.tar.gz

RUN (wget https://github.com/chobits/ngx_http_proxy_connect_module/archive/v0.0.1.tar.gz -O ./ngx_proxy_connect.tar.gz && \
    tar -axf ngx_proxy_connect.tar.gz) && \
    (cd openresty-1.15.8.2 && \
    ./configure -j4 \
        --with-pcre-jit \
        --with-compat \
        --with-http_ssl_module \
        --with-http_realip_module \
        --with-debug \
        --add-dynamic-module=/root/ngx_http_proxy_connect_module-0.0.1 && \
    wget https://raw.githubusercontent.com/chobits/ngx_http_proxy_connect_module/master/patch/proxy_connect_rewrite_101504.patch -O patches/proxy_connect_rewrite.patch && \
    patch -d build/nginx-1.15.8/ -p1 < patches/proxy_connect_rewrite.patch && \
    make -j4 && \
    make install)

ENV PATH="/usr/local/openresty/bin:/usr/local/openresty/nginx/sbin:${PATH}"

COPY ./nginx.conf /usr/local/openresty/nginx/conf/nginx.conf

COPY ./supervisor /etc/supervisor

COPY ./run.sh /run.sh

RUN chmod +x /run.sh

CMD /run.sh