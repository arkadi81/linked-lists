#!/bin/bash
gcc -c -Wall -std=c99 list.c
gcc -Wall -std=c99 -o test test.c list.o
./test
