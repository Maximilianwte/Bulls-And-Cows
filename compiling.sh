#!/bin/bash  
echo "Starting to compile..."
g++ -c main.cpp -w
g++ -c Bull.cpp -w
g++ -o Bull main.o Bull.o 
echo "Compiling & Linking finished."