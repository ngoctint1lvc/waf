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
chmod +x dev.sh
./dev.sh
```

To quickly spawn a shell into docker services, run those commands
```bash
./run.sh    # openresty waf service,
./run.sh dvwa   # dvwa service
./run.sh nginx  # nginx service
```

## Deployment
TODO


## Authors

* **ngoctin** - [my github repo](https://github.com/ngoctint1lvc)
