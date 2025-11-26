#!/bin/bash

# --------------------------
# Colors
# --------------------------
RED=$'\e[31m'
GREEN=$'\e[32m'
YELLOW=$'\e[1;33m'
BLUE=$'\e[34m'
RESET=$'\e[0m'

# --------------------------
# Functions
# --------------------------
shuffle() {
    shuf -i 0-9999 -n "$1"
}

sleep_f() {
    sleep 0.01
}

valid_outputs() {
    local num=$1
    local args=("" "--simple" "--medium" "--complex" "--adaptive" "--bench" "--simple --bench" "--medium --bench" "--complex --bench" "--adaptive --bench" "--bench --simple" "--bench --medium" "--bench --complex" "--bench --adaptive")
    for i in "${!args[@]}"; do
        if [[ "${args[$i]}" == "" ]]; then
            echo -n "${BLUE}(no arguments): ${RESET}"
        else
            echo -n "${BLUE}(${args[$i]}): ${RESET}"
        fi
        for x in {1..30}; do
            sh=$(shuffle "$num")
            result=$(./push_swap $sh | ./checker_os $sh)
            if [[ "$result" != "OK" ]]; then
                echo -ne "${RED}KO ${RESET}"
            else
                echo -ne "${GREEN}OK ${RESET}"
            fi
        done
        echo ""
    done
}

nums=("1" "10" "20" "50" "100" "500")
for i in "${nums[@]}"; do
    echo -e "${YELLOW}$i numbers:${RESET}"
    valid_outputs $i
done
