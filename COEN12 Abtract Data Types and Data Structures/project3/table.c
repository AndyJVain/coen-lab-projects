/*
Andy Vainauskas
April 30, 2016
Thursday 9:15am
Project #3

This is a collection of functions that uses hashing to manipulate data.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include "set.h"
#define EMPTY 0
#define FILLED 1
#define DELETED 2


int findElement(SET *sp, char *elt, bool *found);
unsigned hashString(char *s);

struct set
{
	int count;
	int length;
	char *flags;
	char **elts;
};

/*
O(1)
This is the hash function that is used in findElement, which tells the function the location to hash to
*/
unsigned hashString(char *s)
{
	unsigned hash = 0;
	
	while (*s != '\0')
		hash = 31 * hash + *s ++;

	return hash;
}

/*
O(1)
This creates a set with both the array of pointers and the array of flags
*/
SET *createSet(int maxElts)
{
	int i;
	SET *sp;
	sp = malloc(sizeof(SET));	//Allocates the memory space for the set
	assert(sp != NULL);

	sp->count = 0;	//Creates the struct members
	sp->length = maxElts;
	sp->flags = malloc(sizeof(char)*maxElts);
	sp->elts = malloc(sizeof(char*)*maxElts);
	assert(sp->elts != NULL);

	for(i=0; i<sp->length; i++){
		sp->flags[i] = EMPTY;
	}
	return sp;
}

/*
O(n)
This destroys the set by freeing all the elements and then the set itself
*/
void destroySet(SET *sp)
{
	int i;

	for(i=0; i<sp->length; i++){	//Loops through to free the filled positions in the hash table
		if(sp->flags[i] == FILLED){
			free(sp->elts[i]);
		}
	}
	
	free(sp->elts);		//Frees the hash table
	free(sp->flags);	//Frees the flag array
	free(sp); 		//Frees the set
}

/*
O(1)
This produces the number of elements
*/
int numElements(SET *sp)
{
	return sp->count;
}

/*
O(n)
This checks to see if there is a specific member within the hash table and returns true or false if it was or wasn't
*/
bool hasElement(SET *sp, char *elt)
{
	bool found;
	int x = findElement(sp, elt, &found);	//Updates the variable found so that it can be returned
	return found;
}

/*
O(n)
This searches for a specific element by using the hash function, and it returns the position of where to insert or delete, as well as if it found the element by updating a bool
*/
int findElement(SET *sp, char *elt, bool *found)
{
	int m = sp->length;
	int k = hashString(elt) % m;
	int i;
	int saved = -1;

	for(i=0; i<m; i++){	//Loops through the positions starting at the hash location and moving to the right
		int pos = (k+i) % m;
		
		if(sp->flags[pos] == EMPTY){	//Checks to see if the position is empty, then returns that position
			if(saved == -1){
				*found = false;
				return pos;
			}
			else{
				*found = false;	
				return saved;
			}
		}

		if(sp->flags[pos] == FILLED){	//Checks to see if the position is filled
			if(strcmp(elt, sp->elts[pos]) == 0){	//Checks if the elt matches what is in that location
				*found = true;	//Returns true if it is matched
				return pos;	//Returns it's position
			}
		}

		if(sp->flags[pos] == DELETED){	//Checks to see if the position is deleted
			if(saved == -1){	
				saved = pos;	//Remembers the position if it is the first deleted spot
			}	
		}	
	}
	*found = false;
	return saved;
}

//O(n)
//This creates an element by using the position produced by findElement while also updating the flag to FILLED
bool addElement(SET *sp, char *elt)
{
	bool found;
	int pos = findElement(sp, elt, &found);	//Finds the position of where to insert

	assert(sp != NULL && elt != NULL);
	if(sp->count == sp->length || found == true){	//Makes sure that the position was found
		return false;
	}	

	elt = strdup(elt);	//Allocates memory space for elt
	assert(elt != NULL);

	sp->elts[pos] = elt;	//Inserts the elt based on the hash function in findElement
	sp->flags[pos] = FILLED;	//Updates the flag
	sp->count++;
	return true;	
}

//O(n)
//This removes an element by using the position produced by findElement while also updating the flag to DELETED
bool removeElement(SET *sp, char *elt)
{
	bool found;
	int pos = findElement(sp, elt, &found);	//Finds the position to remove

	assert(sp != NULL && elt != NULL);	//Makes sure that sp and elt exist

	if(found == true){	//If it finds the position to remove
		free(sp->elts[pos]);	//Frees the memory space for the elt
		sp->flags[pos] = DELETED;	//Updates the flag
		sp->count--;
		return true;
	}
	return false;
}
