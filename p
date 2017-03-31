#!/bin/bash
clear

PATTERN=`cat s | tail -n1 | cut -d/ -f2`
NAME=`ls -1 song/$PATTERN.cpp | cut -d/ -f2 | cut -d. -f1`

mkdir -p bin
g++ -std=c++11 -I. -O3 `sdl2-config --cflags --libs` song/$NAME.cpp -o bin/$NAME -lSDL2
