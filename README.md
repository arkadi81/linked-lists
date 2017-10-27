# linked-lists

practice creating interface and implementation for linked lists in c, and utilization of the linked list library to solve assignment two from SENG 265 (UVIC, Fall 2017).

## Problem description
* Read the contents of a text file, record and output histogram of word lengths, word lists and count of individual word repetitions. Further description in spec in original assignment pdf.

## Usage

 * clone repo, then:

### Compile library and main testing file and run:
* gcc -c list.c
* gcc -Wall -std=c99 -o main main.c list.o
* ./main

### or use the shell script go.sh (included to run these automatically):
* ./go.sh
(if no permissions to run the script, first sudo chmod +x ./go.sh)

## Testing
* use provided ./test.sh (or amend the compilation commands for main.c above to test.c)

## TODO
- The use of countnv and printnv is a bit awkward. Would be nice to have wrappers for those
- see list.h for interface and spec
- Testing is now sporadic - develop proper spec with success and failure conditions
- develop more tailored counting and "apply" wrappers

