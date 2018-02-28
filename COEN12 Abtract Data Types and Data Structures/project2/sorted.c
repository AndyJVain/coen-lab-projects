/*
Andy Vainauskas
April 14, 2016
Thursday 9:15am
Project #2

This is part 2 of 2, a collection of functions that are used to manipulate data in a sorted array by using binary search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "set.h"

int findElement(SET *sp, char *elt, bool *found);

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
//This removes a set
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
	bool found;
	int x = findElement(sp, elt, &found);	//Updates the variable found so that it can be returned
	return found;
}

//O(logn)
//This searches for a specific element
int findElement(SET *sp, char *elt, bool *found)
{
	int lo, mid, hi, diff;
	lo = 0;
	hi = sp->count-1;	
	while(lo <= hi){	//Makes sure lo and hi don't cross each other
		mid = (lo + hi)/2;
		diff = strcmp(elt, sp->elts[mid]);
		if(diff<0)	//Excetutes checks for the binary search
			hi = mid-1;
		else if(diff>0)
			lo = mid+1;
		else{
			*found = true;
			return mid;
		}
	}
	*found = false;
	return lo;
}

//O(n)
//This creates an element
bool addElement(SET *sp, char *elt)
{
	bool found;
	int i;

	int pos = findElement(sp, elt, &found);	//Updates the correct value of found

	assert(sp != NULL && elt != NULL);
	if(sp->count == sp->length || found == true){	//This makes sure the place was found
		return false;
	}
	
	elt = strdup(elt);	//Allocates memory space for elt
	assert(elt != NULL);	

	for(i=sp->count; i>pos; i--){	//Loops through to shift the elts up one, starting from the end
		sp->elts[i] = sp->elts[i-1];	
	}
	
	sp->elts[pos] = elt;	//Inserts the elt
	sp->count++;
	return true;
}

//O(n)
//This removes an element
bool removeElement(SET *sp, char *elt)
{
	int i;
	bool found;
	int pos = findElement(sp, elt, &found);	//Finds the place to delete

	assert(sp != NULL && elt != NULL);
	
	if(found == true){	//If it finds the place
		free(sp->elts[pos]);	//Frees the memory space
		for(i=pos+1; i<sp->count; i++){	//Loops through to shift down, starting from the position
			sp->elts[i-1] = sp->elts[i];
		}
		sp->count--;
		return true;
	}
	return false;
}
