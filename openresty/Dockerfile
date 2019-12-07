FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y apt-utils && \
    apt-get install -y net-tools iputils-ping wget supervisor

WORKDIR /root

RUN wget https://openresty.org/download/openresty-1.15.8.2.tar.gz && \
    tar -axf openresty-1.15.8.2.tar.gz

RUN apt-get install -y libpcre3-dev \
    libssl-dev perl make build-essential curl

RUN apt-get install -y zlib1g zlib1g-dev

RUN (cd openresty-1.15.8.2 && \
    ./configure -j4 \
        --with-pcre-jit \
        --with-ipv6 && \
    make -j4 && \
    make install)

ENV PATH="/usr/local/openresty/bin:/usr/local/openresty/nginx/sbin:${PATH}"

RUN apt-get install -y git luarocks gcc-5 g++-5

COPY ./lua-resty-waf ./lua-resty-waf

RUN (cd lua-resty-waf && \
    make CC=gcc-5 && \
    make install)

# # # clean files
# # RUN rm -rf ./*

COPY run.sh /run.sh

CMD ["/run.sh"]