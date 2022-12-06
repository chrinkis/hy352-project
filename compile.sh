#!/bin/bash

mkdir -p build &&
    cd build &&
    cmake .. &&
    make hy352-project

if [[ $? -eq 0 && $1 = "-r" ]]; then
    echo
    echo "Executing:"
    echo "---"
    echo
    ./hy352-project
fi
