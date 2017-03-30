#!/bin/bash
clear

g++ -std=c++11 `sdl2-config --cflags --libs` player.cpp -o player -lSDL2
