#!/bin/sh
cd "${0%/*}" # cd to folder containing this file

sh build.sh && ./build/bin/tictactoe