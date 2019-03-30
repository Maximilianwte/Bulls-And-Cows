#!/bin/bash  
echo "Starting to compile..."
g++ -c main.cpp
g++ -c Bull.cpp
g++ -o Bull main.o Bull.o
echo "Compiling & Linking finished."