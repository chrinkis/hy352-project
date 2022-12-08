#!/bin/bash

mkdir -p build &&
    cd build &&
    cmake .. &&
    make hy352-project

if [[ $1 = "-p" ]]; then
    make src/main.cpp.i && 
        less CMakeFiles/hy352-project.dir/src/main.cpp.i
fi

if [[ $? -eq 0 && $1 = "-r" ]]; then
    echo
    echo "Executing:"
    echo "---"
    echo
    ./hy352-project
fi
