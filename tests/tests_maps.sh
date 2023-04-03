#!/bin/bash

fail=0

echo -e "\033[0;35mTesting maps...\033[0m"
for file in ./tests/maps/*; do
    name=${file##*/}
    echo -n -e "\033[0;36m[\033[0;34m${name}\033[0;36m] "
    ./$1 $file > ./result_${name}.txt
    if [[ -z $(diff ./result_${name}.txt ./tests/maps_solved/${name}) ]]; then
        echo -e "\033[0;32mOK\033[0m"
        rm -f ./result_${name}.txt
    else
        echo -e "\033[0;31mFAIL\033[0m"
        ((fail=fail+1))
    fi
done
if [ $fail -eq 0 ]; then
    echo -e "\033[0;32mAll tests passed\033[0m"
else
    echo -e "\033[0;31mSome tests failed\033[0m"
fi