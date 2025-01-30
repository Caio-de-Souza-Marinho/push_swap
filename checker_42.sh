#!/bin/bash

iterations=$1
num_count=$2

# ANSI color codes
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"

for ((i = 1; i <= iterations; i++)); do
  args=$(shuf -i 1-50000 -n "$num_count" | tr '\n' ' ')
  result=$(./push_swap $args | ./checker_linux $args)
  count=$(./push_swap $args | wc -l)
  if [ "$result" == "OK" ]; then
    color_result="${GREEN}OK${RESET}"
  else
    color_result="${RED}KO${RESET}"
  fi
  echo -e "$color_result $count"
done
