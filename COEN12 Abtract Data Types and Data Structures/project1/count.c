/*
Andy Vainauskas
March 31, 2016
Thursday 9:15am
Lab #1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 30

int main(int argc, char *argv[ ])
{

	FILE *fp;
	int counter = 0;
	int i;
	char word[MAX_WORD_LENGTH+1];

	if(argc == 1){	//Makes sure that the filename was given before running
		printf("The filename is missing!\n");
		return 1;
	}

	fp = fopen(argv[1], "r");

	if(fp == NULL){	//Checks for errors in opening the file
		printf("Can't access the file\n");
		return 1;
	}
	
	while(fscanf(fp, "%s", word) > 0){	//Traverses the file looking for characters
		counter++;	//Counts as a word
	}
	
	fclose(fp);
	printf("%d total words\n", counter);
	return 0;
}

