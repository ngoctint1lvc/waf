# Web Application Firewall

This project is a web application firewall (WAF) based on ModSecurity Core Rule Set with some Machine Learning improvements. This project is currently under development and will release soon.

## How to run

### Prerequisites

To build and run this project, you must install docker and docker-compose first. Refer to the official docker documentation for the installation.

- https://docs.docker.com/get-docker/
- https://docs.docker.com/compose/install/

## Deployment
Clone and init submodule
```
git clone https://github.com/ngoctint1lvc/waf.git
cd waf/
git submodule update --init --recursive
```

Create `.env` file from `.env.example`
```conf
MONGODB_SERVER=log-db
MONGO_INITDB_ROOT_USERNAME=
MONGO_INITDB_ROOT_PASSWORD=
DEBUG=1
MONGO_EXPRESS_USERNAME=
MONGO_EXPRESS_PASSWORD=
COLLECTION_PREFIX=test
```

Add your certificate and private key in `openresty/nginx/ssl` folder
```
./openresty/nginx/ssl
├── localhost-key.pem
└── localhost.pem
```

Start all services
```
docker-compose -f docker-compose.prod.yml up -d
```

Redirect all traffic to http proxy server at port 80

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

## Authors

* **ngoctin** - [my github repo](https://github.com/ngoctint1lvc)
