# Web Application Firewall

This project is a web application firewall (WAF) based on ModSecurity Core Rule Set with some Machine Learning improvements. This project is currently under development and will release soon.

## How to run

### Prerequisites

To build and run this project, you must install docker and docker-compose first. Refer to the official docker documentation for the installation.

- https://docs.docker.com/get-docker/
- https://docs.docker.com/compose/install/

### Installing

TODO

### How to develop

Clone this project and start all docker services. Two images for testing including DVWA and Nginx server.
```
git clone https://github.com/ngoctint1lvc/waf.git
cd waf/
git submodule update --init --recursive
```

Add 2 local dns record to your host files
```
127.0.0.1 dvwa.test
127.0.0.1 nginx.test
```

Start all containers
```
docker-compose up -d
```

Using `dev.py` script to for development (only work on ubuntu linux)
```bash
> python dev.py
Command list:
init
init-terminal
reload
attack
log
test [url]
gen-ssl
rebuild-modsec
update-dns
restart
```

## Deployment
TODO


## Authors

* **ngoctin** - [my github repo](https://github.com/ngoctint1lvc)
