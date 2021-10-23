#!/bin/bash
cd "${0%/*}" # cd to folder containing this file

cd ../build
cmake ..
cmake --build . && cd ../ && ./build/bin/tictactoe