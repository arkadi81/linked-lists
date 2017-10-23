#!/bin/bash
gcc -c list.c
gcc -Wall -std=c99 -o main main.c list.o
./main
