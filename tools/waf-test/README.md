# Polaris WAF Test

One Paragraph of project description goes here

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Installing

Install required packages
```
yarn
```

Create environment file
```
cp .env.example .env
```

### Running all tests
```
yarn start
```

After running tests, you can get output at `./tests/browser/outputs/` folder

### Running tests interactive
Running in RELP console
```bash
node -i -e "$(cat index.js)"
```

```bash
> chrome.openBrowser()  # wait for chromium browser starting
> browser.login()  # goto browser test page
> browser.setSecurityLevel("low")      # level includes "low", "medium", "high", "imposible" (references browser)
```

You can reset state after being blocked by polaris firewall
```bash
> browser.reset()
```

You can add more testcases under folder ./tests/browser/payloads/
```
...
├── tests
│   └── browser
│       ├── outputs
│       ├── payloads
│       │   ├── cmdi-attack-general.txt
│       │   ├── cmdi-attack.txt
│       │   ├── cmdi-normal.txt
│       │   ├── sqli-attack.txt
│       │   ├── sqli-normal.txt
│       │   ├── xss-attack.txt
│       │   └── xss-normal.txt
│       ├── script.js
│       └── test.json
...
```

## Built With

* [Node.js](https://nodejs.org/en/) - Javascript runtime
* [Puppeteer](https://github.com/puppeteer/puppeteer) - Headless browser

## Authors

* **Ngoc Tin** - *Initial work* - [my github repo](https://github.com/ngoctint1lvc)
