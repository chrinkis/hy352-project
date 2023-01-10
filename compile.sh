#!/bin/bash

if [[ $1 = "-m" ]]; then
    make clean &&
        make jsonlang &&
        make lib &&
        make demo

        exit
fi

if [[ $1 = "-t" ]]; then
    mkdir -p build &&
        cd build &&
        cmake .. &&
        make tests &&
        ./tests

        exit
fi

mkdir -p build &&
    cd build &&
    cmake .. &&
    make hy352-project

STATUS=$?

if [[ $1 = "-p" ]]; then
    make test/main.cpp.i &&
        less CMakeFiles/hy352-project.dir/test/main.cpp.i
fi

if [[ $STATUS -eq 0 && $1 = "-r" ]]; then
    echo
    echo "Executing:"
    echo "---"
    echo
    ./hy352-project
fi
