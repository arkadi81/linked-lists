/* library of common functions
 * authored by ARKADY FUTERMAN 2017/10/22
 */


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include <ctype.h>

void lcase(char *word) {
	int i;
	for (i=0; word[i]; i++) {
		word[i] = tolower(word[i]);
	}
}


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

void tokenize_line(char *buf,char* delimiters) {
	// recieves a buffer with a line of wording and a set of delimiters
	// breaks the line apart into words, applies PROCESS function to each word
	char *t;
	// only expected non std characters in the file are .,;()
	 

	// for 1.2, we need to account for sorting the array
	// for 1.3 we need to record information re each word (converted to lcase) and its incidence

	t = strtok(buf,delimiters);
	//int j;
	//data *temp_word_record;

	while (t) {
		lcase(t);
		
		// have we seen this word yet? if so, find it and aggregate, if not, add it
		/*j=0;
		temp_word_record = &words[strlen(t)-1]; // len 1 is stored in words[0]; // trying to work with pointers
		while (j<(*temp_word_record).distinct_word_count && strncmp(t,(*temp_word_record).word_list[j].word,strlen(t))!=0) {
			j++;
		}
		//at this point j is at first index that either is out of use or is at word that needs to be incremented
		if (strncmp(t,(*temp_word_record).word_list[j].word,strlen(t))!=0) {
			// word not detected in list, add it
			strncpy((*temp_word_record).word_list[j].word,t,MAX_WORD_SIZE);
			(*temp_word_record).distinct_word_count++;
		}
		// for either options, either if the word is new, or if its an existing word, increase total number of words and individual repeats
		(*temp_word_record).total_word_count++;
		(*temp_word_record).word_list[j].repeats++;
		
		num_words++;*/
		printf("%s\n", t);
		t = strtok(NULL,delimiters);
	}
	return;
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
	size_t len; // will be used to store length of current line read by getline

	fp = fopen(path, "r");
	if(fp == NULL) {
		printf("Cannot open file path: %s\n", path);
		exit(1);
	}

	if (buffer == NULL) {
		printf("Cannot allocate %zu byte buffer.\n", bufsize);
		exit(1);
	}

	while ((len = getline(&buffer, &bufsize, fp))!=-1) {
		tokenize_line(buffer," .,;()\n");
		
	}

	if(buffer) {
		free(buffer);
	}

	fclose(fp);
	return 1;
	
}