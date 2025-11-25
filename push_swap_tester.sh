#!/bin/bash

# --------------------------
# Colors
# --------------------------
RED=$'\e[31m'
GREEN=$'\e[32m'
YELLOW=$'\e[1;33m'
RESET=$'\e[0m'

# --------------------------
# Functions
# --------------------------
shuffle_function() {
    shuf -i 0-9999 -n "$1"
}

sleep_function() {
    sleep 0.01
}

run_test() {
    local label=$1      # e.g., "1 number (no arguments)"
    local count=$2      # number of elements to shuffle
    local option=$3     # program option like "", "--simple", "--medium"

    echo -e "${YELLOW}${label}:${RESET}"
    echo -n "   "
    
    for n in {1..30}; do
        shuffle=$(shuffle_function "$count")
        result=$($program $option $shuffle | ./checker_os $shuffle)
        if [[ "$result" != "OK" ]]; then
            echo -ne "${RED}KO ${RESET}"
        else
            echo -ne "${GREEN}OK ${RESET}"
        fi
        sleep_function
    done
    echo -e "\n"
}

# --------------------------
# Prepare program
# --------------------------
bash make.sh > garbage.txt
rm -f garbage.txt

program="./push_swap"

# --------------------------
# Test cases
# --------------------------
declare -A tests

# Format: "label" = "number_of_elements option"
tests=(
    ["1 number (no arguments)"]="20"
    ["50 numbers (no arguments)"]="100"
    ["100 numbers (no arguments)"]="500"
    ["500 numbers (no arguments)"]="1"
    ["1 number (--simple)"]="20 --simple"
    ["50 numbers (--simple)"]="100 --simple"
    ["100 numbers (--simple)"]="500 --simple"
    ["500 numbers (--simple)"]="1 --simple"
    ["1 number (--medium)"]="20 --medium"
    ["50 numbers (--medium)"]="100 --medium"
    ["100 numbers (--medium)"]="500 --medium"
    ["500 numbers (--medium)"]="1 --medium"
)

# Run all tests
for label in "${!tests[@]}"; do
    args=(${tests[$label]})     # split string into array
    run_test "$label" "${args[0]}" "${args[1]}"
done
