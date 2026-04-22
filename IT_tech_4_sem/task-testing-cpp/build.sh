#!/bin/bash

read -p "Введите количество ядер процессора: " num_cores

mkdir -p build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j$((${num_cores}+1))
make coverage_report -j$((${num_cores}+1))