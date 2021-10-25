#!/bin/sh
cd "${0%/*}" # cd to folder containing this file

(sh build.sh) && cd .. && ./build/bin/tictactoe