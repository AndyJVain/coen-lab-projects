/*
Andy Vainauskas
April 7, 2016
Thursday 9:15am
Project #2

This is part 1 of 2, a collection of functions that are used to manipulate data in an unsorted array by using sequential search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "set.h"

int findElement(SET *sp, char *elt);

struct set
{
	int count;
	int length;
	char **elts;	
};

//O(1)
//This creates a set
SET *createSet(int maxElts)
{
	SET *sp;
	sp = malloc(sizeof(SET));	//Allocates the memory space
	assert(sp != NULL);

	sp->count = 0;	//Creates the struct members
	sp->length = maxElts;
	sp->elts = malloc(sizeof(char*)*maxElts);
	assert(sp->elts != NULL);

	return sp;
}

//O(n)
//This removes the set
void destroySet(SET *sp)
{
	int i;

	for(i=0; i<sp->count; i++){	//Loops through to free the strings
		free(sp->elts[i]);
	}

	free(sp->elts);	//Frees the array of pointers
	free(sp);	//Frees the set
}

//O(1)
//This produces the number of elements
int numElements(SET *sp)
{
	return sp->count;
}

//O(n)
//This checks to see if there is a specific member within the set
bool hasElement(SET *sp, char *elt)
{
	if(findElement(sp, elt) != -1){	//Calls the find element function to loop through the pointer array
		return true;
	}
	return false;
}

//O(n)
//This searches for a specific element and outputs the position
int findElement(SET *sp, char *elt)
{
	int i;
	for(i=0; i<sp->count; i++){	//Loops through the array of pointers and strcmps to see if it matches
		if(strcmp(sp->elts[i], elt) == 0){
			return i;
		}
	}
	return -1;
}

//O(1)
//This creates an element
bool addElement(SET *sp, char *elt)
{
	assert(sp != NULL && elt != NULL);
	if(sp->count == sp->length || findElement(sp, elt) != -1){	//Checks to see if it isn't full
		return false;
	}

	elt = strdup(elt);	//Makes space for the string
	assert(elt != NULL);
	
	sp->elts[sp->count++] = elt;	//Adds the element
	return true;
}

//O(n)
//This removes an element
bool removeElement(SET *sp, char *elt)
{
	int pos = 0;

	assert(sp != NULL && elt != NULL);
	pos = findElement(sp, elt);
	
	if(pos != -1){	//Frees the memory if it finds the one to remove
		free(sp->elts[pos]);
		sp->elts[pos] = sp->elts[sp->count-1];
		sp->count--;
		return true;
	}
	return false;
}
