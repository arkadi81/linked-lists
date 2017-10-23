#!/bin/bash
gcc -c list.c
gcc -Wall -std=c99 -o test test.c list.o
./test
