#!/bin/bash
gcc -c -Wall -std=c99 list.c
gcc -Wall -std=c99 -o -g test test.c list.o
valgrind ./test
