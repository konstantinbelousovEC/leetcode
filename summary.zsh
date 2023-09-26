#!/bin/zsh

total_problems=$(find . -maxdepth 1 -type f -name "*.cpp" | grep -c .)
echo "\e[32mtotal:\e[0m\t\e[32m${total_problems}\e[0m"

easy_problems=$(find . -maxdepth 1 -type f -name "easy*.cpp" | grep -c .)
echo "\e[34measy:\e[0m\t\e[34m${easy_problems}\e[0m"

medium_problems=$(find . -maxdepth 1 -type f -name "medium*.cpp" | grep -c .)
echo "\e[38;5;208mmedium:\e[0m\t\e[38;5;208m${medium_problems}\e[0m"

hard_problems=$(find . -maxdepth 1 -type f -name "hard*.cpp" | grep -c .)
echo -e "\e[31mhard:\e[0m\t\e[31m${hard_problems}\e[0m"