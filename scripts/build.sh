#!/bin/sh
cd "${0%/*}" # cd to folder containing this file
cd ../build

cmake .. -Wno-dev
cmake --build . --parallel $(nproc)