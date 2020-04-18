#!/bin/bash

if [ "$1" = "nginx" ]; then
    docker-compose exec nginx-test tail -f /var/log/nginx/access-nginx.log \
        /var/log/nginx/error-nginx.log
else
    docker-compose exec openresty tail -f /usr/local/openresty/nginx/logs/error.log
fi
