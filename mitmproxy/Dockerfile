FROM ubuntu:18.04

COPY ./app.py /app.py

COPY ./run.sh /run.sh

RUN apt-get update && \
    apt-get install -y python3 python3-pip dnsmasq iputils-ping && \
    pip3 install mitmproxy

RUN chmod +x /run.sh

CMD /run.sh