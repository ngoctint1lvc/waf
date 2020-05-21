#!/bin/bash

openresty_ip="$(ping openresty -c 1 | head -n 1 | grep -oP "\d+.\d+.\d+.\d+")"

echo "[+] WAF IP is $openresty_ip"

cat <<- HEREDOC > /etc/dnsmasq.d/custom.conf
address=/#/$openresty_ip
HEREDOC

echo "[+] Start dnsmasq service"
service dnsmasq start

cat <<- 'HEREDOC' > /etc/resolv.conf
nameserver 127.0.0.1
nameserver 127.0.0.11
nameserver 1.1.1.1
HEREDOC

mitmdump -p 8080 -k