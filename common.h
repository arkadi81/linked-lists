/* library of common functions
 * authored by ARKADY FUTERMAN 2017/10/22
 */


#include <stdio.h>
#include <stdlib.h>

typedef int dat;

int process_line(char *buffer, size_t size) {
	/* helper function for read_multiline... does processing for single line of file

	tokenize line into individual words
	 - per word


	// check length of word

	// update counters of total words, individual words of corresponding length, and unique words of such length
	// look for word in the allotted length list... add new word to list or up counter of existing word

	*/
	printf("Retrieved line of length %zu :\n", size);
	printf("%s\n", buffer);
	return 1;
}

int read_multiline_file_to_dynamic_list(char *path) {
	// recieves path of file to read
	// uses getline to read contents of fp. Each line is processed using process_line(buf, size)
	// may have to be modified depending on procedure for reading
	//TODO: getline is still getting bigger chunks than allocated buffer - bug?

	FILE *fp;
	
	size_t bufsize = 64; // hopefully those are the chunk sizes... doesnt work though... bug?

	char *buffer = (char*)malloc(bufsize * sizeof(char));
	printf("size of char is %zu\n", sizeof(char));
	size_t read; // will be used to store length of current line read by getline

	fp = fopen(path, "r");
	if(fp == NULL) {
		printf("Cannot open file path: %s\n", path);
		exit(1);
	}

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