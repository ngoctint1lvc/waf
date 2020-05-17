FROM ubuntu:18.04

COPY ./openresty-1.15.8.3 /root/openresty

COPY ./modsecurity /opt/modsecurity

COPY ./modsecurity-nginx /opt/modsecurity-nginx

COPY ./modsecurity-crs /opt/modsecurity-crs

RUN apt-get update && \
    apt-get install -y apt-utils && \
    apt-get install -y net-tools iputils-ping wget supervisor \
    libpcre3-dev libssl-dev perl make build-essential curl zip \
    zlib1g zlib1g-dev libgeoip-dev git libtool automake autoconf \
    cmake libxml2 libxml2-dev

WORKDIR /root

# download and compile yajl
RUN (wget http://github.com/lloyd/yajl/zipball/2.1.0 -O yajl.zip && \
    unzip yajl.zip && mv lloyd* yajl && rm yajl.zip && \
    cd yajl && ./configure && make && make install && ldconfig)

# download and install lua
RUN apt-get update && \
    apt-get -y install lua5.1 liblua5.1-dev && \
    ln -sf /usr/bin/lua5.1 /usr/bin/lua

RUN mkdir -p /etc/modsecurity && \
    cp /opt/modsecurity/modsecurity.conf /etc/modsecurity/modsecurity.conf && \
    cp /opt/modsecurity/unicode.mapping /etc/modsecurity/unicode.mapping

# fix timezone problem
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata && \
    ln -fs /usr/share/zoneinfo/UTC /etc/localtime

# debug tools
RUN apt-get install -y bfs gdb && \
    (cd /root && git clone https://github.com/pwndbg/pwndbg && \
    cd pwndbg && ./setup.sh)

# install lua-mongo
RUN apt-get install -y luarocks && \
    (cd /opt && wget https://github.com/mongodb/mongo-c-driver/releases/download/1.16.2/mongo-c-driver-1.16.2.tar.gz && \
    tar -axf mongo-c-driver-1.16.2.tar.gz && \
    rm mongo-c-driver-1.16.2.tar.gz && \
    cd mongo-c-driver-1.16.2 && \
    mkdir cmake-build && \
    cd cmake-build && \
    cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF .. && \
    make install -j4) && \
    luarocks install lua-cjson && \
    luarocks install lua-mongo

# update path env
ENV PATH "/usr/local/openresty/bin:/usr/local/openresty/nginx/sbin:${PATH}"

COPY run.sh /run.sh

CMD ["/run.sh"]