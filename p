#!/bin/bash
clear

mkdir -p bin
g++ -std=c++11 -O3 `sdl2-config --cflags --libs` simple_house.cpp -o bin/simple_house -lSDL2
#g++ -std=c++11 -O3 `sdl2-config --cflags --libs` 2u_no_limits.cpp -o bin/2u_no_limits -lSDL2
