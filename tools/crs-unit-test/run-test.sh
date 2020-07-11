#!/bin/bash

test_all() {
    # Kill all background process when using Ctrl+C
    trap 'pkill py.test' INT

    echo "[+] Running java attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-944-APPLICATION-ATTACK-JAVA --output outputs/java-attack.csv &

    echo "[+] Running lfi attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-930-APPLICATION-ATTACK-LFI --output outputs/lfi-attack.csv &

    echo "[+] Running rfi attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-931-APPLICATION-ATTACK-RFI --output outputs/rfi-attack.csv &

    echo "[+] Running nodejs attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-934-APPLICATION-ATTACK-NODEJS --output outputs/nodejs-attack.csv &

    echo "[+] Running php attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-933-APPLICATION-ATTACK-PHP --output outputs/php-attack.csv &

    echo "[+] Running rce attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-932-APPLICATION-ATTACK-RCE --output outputs/rce-attack.csv &

    echo "[+] Running xss attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-941-APPLICATION-ATTACK-XSS --output outputs/xss-attack.csv &

    echo "[+] Running sqli attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-942-APPLICATION-ATTACK-SQLI --output outputs/sqli-attack.csv &

    echo "[+] Running protocol attack testcases"
    py.test --tb=no CRS_Tests.py -v --rule tests/REQUEST-921-PROTOCOL-ATTACK --output outputs/protocol-attack.csv &

    jobs

    wait
    echo ""
    echo "[+] Done"
}

test_all