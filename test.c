#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // for tolower
#include "list.h"


int main(int argc, char *argv[]) {
	// testing list functions

	// first create list
	//char *name;
	printf ("---------- Testing for implementation of linked list. Arkady Futerman, c2017 ------------ \n");

	list_data data;
	el *list = NULL;
	el *element = NULL;
	data.name ="alpha";
	element = newitem(data);
	if(element) {
		printf("creation of element ALPHA successful.\n");
	} else {
		printf("couldnt creat element ALPHA.Exiting...\n"); 
	}

	list = addfront(list,element);
	if (list) {
		printf("successfully added ALPHA to list.\n");
	} else {
		printf("couldn't add ALPHA to list.Exiting...\n");
	}

	// --------------------------------------------------------

	data.name ="bravo";
	element = newitem(data);
	if(element) {
		printf("creation of element BRAVO successful.\n");
	} else {
		printf("couldnt creat element BRAVO.Exiting...\n"); 
	}

	list = addfront(list,element);

	data.name ="charlie";
	element = newitem(data);
	if(element) {
		printf("creation of element CHARLIE successful.\n");
	} else {
		printf("couldnt creat element CHARLIE.Exiting...\n"); 
	}

	list = addend(list,element);

	printf("Elements are (front to back): ");
	apply(list,printnv,"%s "); // tests ok
	printf("\n");

	int t = 0; 
	apply(list,countnv, &t);
	printf("number of counted items using countnv is %d\n", t);

	// lets look for a thing. we can reuse element since the list already tracks all of the allocated memory
	element = lookup(list,"charlie"); // implementation at the point looks for text value. CASE SENSITIVE
	if (element) {printf("CHARLIE FOUND!\n");}

	// lets kill alpha
	list = delitem(list,"alpha"); // again, due to implementation, by string value


	// lets see what's left
	printf("alpha just got deleted...\n");
	printf("Elements are (front to back): ");
	apply(list,printnv,"%s "); // tests ok
	printf("\n");

	t=0; // t just grows, doesnt get reset, kinda awkward implementation
	apply(list,countnv, &t);
	printf("number of counted items using countnv is %d\n", t);


	printf("releasing all memory and exiting...\n");
	freeall(list);

	printf (" ------- END OF TESTING -----------  \n");
	return 0;
}