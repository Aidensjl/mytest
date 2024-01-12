#!/usr/bin/bash

echo "running .........."

cd build
rm -rf *

# 一定要带DCMAKE_BUILD_TYPE=debug，否则无法debug
cmake .. -DCMAKE_BUILD_TYPE=debug
# cmake .. 

make