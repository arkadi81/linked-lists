/* list.c linked list implementation, by Arkady Futerman 21071021 */

// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>


typedef struct {
	//data will go here, eg.
	char *name;
} list_data;

typedef struct el el; // defines a single list element
struct el {
	list_data data;
	el *next;
};

/* Single linked list usage
params: Head - pointer to top of list. if NULL list is empty
each element (el) in list has a data field (referenced as listp->data.field_name) and a next pointer.
*/

// INTERFACE
el *newitem(list_data data); // recieves data and creates a new list element, pointing to NULL. if fails to allocate memory, bails with exit(1)
el *addfront(el *listp, el *newp); // recieves destination list pointer listp and an element to add, returns pointer to top of list
el *addend(el *listp, el *newp); // adds newp at end (O(n)), returns pointer to beginning of list
el *lookup(el *listp, char* val); // looks up val in listp. returns NULL if not found. note, may need to be changed depending on implementation and problem
void apply(el *listp, void (*fn)(el*,void*), void *arg); // applies same function fn to every element.
/* function options: 
	- // apply(list,printnv, "element is %s\n"); prints all elemenet data info, subject to change with data structure
	- // int n = 0; apply (list, countnv, &n); printf("%d",n);  counts all elements
*/
void freeall(el *listp); // cleans up all list elements, frees memory
el *delitem(el *listp, char* val); // finds val item in list, removes, returns pointer to new list

void printnv(el *listp, void *arg); // service function for apply. prints out head to tail elements
void countnv(el *listp, void *arg); // service function for apply, counts elements
