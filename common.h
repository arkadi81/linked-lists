/* library of common functions
 * authored by ARKADY FUTERMAN 2017/10/22
 */


#include <stdio.h>
#include <stdlib.h>

typedef int dat;

int process_line(char *buffer, size_t size) {
	// helper function for read_multiline... does processing for single line of file
	printf("Retrieved line of length %zu :\n", size);
	printf("%s\n", buffer);
	return 1;
}

int read_multiline_file_to_dynamic_list(char *path, dat *dest) {
	// recieves path of file to read
	// uses getline to read contents of fp to dest.
	// may have to be modified depending on procedure for reading
	// *dest as pointer so that it is passed by reference and altered after

	FILE *fp;
	char *buffer = NULL;
	size_t bufsize = 64; // we don't know how much we're getting here, so read in set, small, chunks
	size_t read; // will be used to store length of current line read by getline

	fp = fopen(path, "r");
	if(fp == NULL) {
		printf("Cannot open file path: %s\n", path);
		exit(1);
	}

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL) {
		printf("Cannot allocate %zu byte buffer.\n", bufsize);
		exit(1);
	}

	while ((read = getline(&buffer, &bufsize, fp))!=-1) {
		process_line(buffer, read);
		
	}

	if(buffer) {
		free(buffer);
	}
	return 1;
	
}