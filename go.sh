#!/bin/bash
gcc -c list.c
gcc -Wall -std=c99 -o -g main main.c list.o
valgrind ./main
