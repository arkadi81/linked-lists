/* list.c linked list implementation, by Arkady Futerman 21071021 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char *name;
} list_data;

typedef struct el el;
struct el {
	list_data data;
	el *next;
};


void *emalloc(int n) {
	// wrapper function, never returns error. attempts to allocate memory for a new el, writes to stderr and exits if failure
	void *p;
	p = malloc(n);
	if (p==NULL) {
		fprintf(stderr, "malloc of %d bytes failed. Exiting..\n",n);
		printf("malloc didnt work bah...\n");
		exit(1);
	}
	return p;

}

el *newitem(list_data data) {
	// creates a new el item and returns it... doesnt add it to any lists yet
	el *newp;
	newp = (el *) emalloc(sizeof(el));
	newp->data = data;
	newp->next = NULL;
	return newp;
}

el *addfront(el *listp, el *newp) {
	// recieved target list listp, adds node newp in front
	newp->next = listp;
	return newp;

}

el *addend(el *listp, el *newp) {
	// in singly linked this is O(n)
	// adds newp to end of listp
	el *p;
	if (listp==NULL) {
		// if list is empty, add to front and return single element
		return newp;
	}
	for (p=listp; p->next!=NULL; p=p->next)
		; // traverse till end
	p->next = newp;
	return listp;
}

el *lookup(el *listp, char* val) {
	/* will return a link to the node where FIRST matching item is found,
	or a null if search fails. Will need to be amended per search detail */
	for (; listp!=NULL; listp=listp->next) {
		if (strncmp(val, listp->data.name,10)==0) {
			// 10 is arbitrary
			return listp;
		}
	}
	return NULL;
}

void apply(el *listp, void (*fn)(el*,void*), void *arg) {

	// will apply function fn to each element throughout the list
	// for debugging
	//printf("apply function initiated...\n");
	int n=1;
	for (; listp!=NULL; listp=listp->next) {
		//printf("apply loop %d under way...\n",n);
		//printf("data here is %s\n", listp->data.name);
		n++;
		(*fn)(listp,arg);
	}
	return;
}

void printnv(el *listp, void *arg) {
	// prints list contents, used with apply as in
	// apply(list,printnv, "element is %s\n");
	char *fmt;
	fmt = (char*) arg;
	//printf("printnv function attempting to print list item...\n");
	printf(fmt, listp->data.name);
	return;
}

void countnv(el *listp, void *arg) {
	// counts number of elements in list
	// only to be used with apply, usage
	/* int n = 0; apply (list, countnv, &n); printf("%d",n); */
	int *ip;

	ip = (int*) arg;
	(*ip)++;
}

void freeall(el *listp) {
	// frees entire list
	el *temp;
	for (; listp!=NULL; listp=temp) {
		temp=listp->next;
		//does this free data? i believe so?
		free(listp);
	}
}

el *delitem(el *listp, char* val) {
	/* will look for value matching val (to be amended in impelentation) and erase node if found */
	el *curr, *prev;
	prev = NULL;
	for (curr = listp; curr!=NULL; curr=curr->next) {
		if(strncmp(val, curr->data.name,10)==0) {
			if (prev == NULL) {
				listp = curr->next;
			} else {
				prev->next = curr->next;
			}
			free(curr);
			return listp;
		}
		prev = curr;
	}
	fprintf(stderr, "delitem: %s is not in list", val);
	exit(1);
}