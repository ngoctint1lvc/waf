#!/bin/bash

if [ "$1" = 'nginx' ]; then
	docker-compose exec nginx-test bash -c '(cd /var/www/html/ && bash)'
elif [ "$1" = 'dvwa' ]; then
	docker-compose exec dvwa-test bash -c '(cd /var/log/apache2/ && bash)'
else
	docker-compose exec openresty bash -c '(cd /usr/local/openresty/nginx/logs && bash)'
fi 
