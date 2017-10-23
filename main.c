#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h> // for tolower
#include "list.h"


int main(int argc, char *argv[]) {
	// testing list functions

	// first create list
	//char *name;

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

	
	apply(list,printnv,"Element is %s\n"); // tests ok

	int t = 0; 
	apply(list,countnv, &t);
	printf("number of counted items using countnv is %d\n", t);
	return 0;
}