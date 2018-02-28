/*
Andy Vainauskas
May 19, 2016
Thursday 9:15am
Project 5

This is the dreaded Huffman code. Contains blood, sweat, and tears. Also contains the code that creates the Huffman tree to compress and uncompress a file.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "tree.h"
#define l(x) ((x)*2 +1)
#define r(x) ((x)*2 +2)
#define p(x) (((x)-1)/2)

typedef struct tree TREE;

void insert(TREE *t);
TREE *delete(void);
void print(TREE *t);

TREE *heap[257];
TREE *leaves[257];
int counts[257];
int count = 0;

int main(int argc, char *argv[])
{
	FILE *fp;
	TREE *l;
	TREE *r;
	int i;
	int c;	

	assert(argc == 3);	//Makes sure that the filename was given before running
	
	for(i=0; i<257; i++)	//Initializes the counts array with 0 for each index 
		counts[i] = 0;

	fp = fopen(argv[1], "rb");

	assert(fp != NULL);	//Checks for errors in opening the file

	while((c = fgetc(fp)) != EOF)	//Counts each letter in the file by incrementing the proper index of the counts array
		counts[c]++;

	fclose(fp);

	leaves[256] = createTree(0, NULL, NULL);	//This sets the EOF
	insert(leaves[256]);
	
	for(i=0; i<256; i++){	//This creates trees for each leaf and inserts them in the leaves array
		if(counts[i] != 0){
			leaves[i] = createTree(counts[i], NULL, NULL);
			insert(leaves[i]);
		}
	}

	while(count > 1){	//This creates the huffman tree by removing the two least priority trees and combining/inserting them
		l = delete();
		r = delete();
		insert(createTree((getData(l) + getData(r)), l, r)); 		
	}

	for(i=0; i<257; i++){	//This prints each leaf with the corresponding letter and number of times it occurrs
		if(leaves[i] != NULL){
			if(isprint(i) != 0){
				printf("%c: %d ", i, getData(leaves[i]));
			}
			else{
				printf("%03o: %d ", i, getData(leaves[i]));
			}
			print(leaves[i]);	//This calls the print function
			printf("\n");
		}
	}

	pack(argv[1], argv[2], leaves);	//This is the pack function to help compress the file
	return 1;
}

//This function inserts a tree into the priority queue, which keeps its priority order
void insert(TREE *t)
{	
	int index = count;
	while(index != 0 && getData(t) < getData(heap[p(index)])){	//Makes space for where the tree should go
		heap[index] = heap[p(index)];
		index = p(index);		
	}
	heap[index] = t;	//Inserts the tree
	count++;

	return;	
}

//This function returns the lowest priority tree and moves the last leaf in the array to the correct spot 
TREE *delete(void)
{
	int min = 0;
	TREE *x;
	int i;
	for(i = 1; i < count; i++){
		if(getData(heap[i]) < getData(heap[min])){	//This finds the least position
			min = i;
		}		
	}

	x = heap[min];	//This ensures the least priority tree is returned
	heap[min] = heap[--count];	//Also decrements the counter
	heap[count] = NULL;
	return x;
}

//This function prints out the correct 0s and 1s that are part of the Huffman tree
void print(TREE *t)
{
	if(getParent(t) == NULL){	//This makes sure there is a parent to print
		return;
	}

	if(getLeft(getParent(t)) == t){	//If the tree is the left child, print 0
		print(getParent(t)); //This recursively calls print
		printf("0");
	}
	else if(getRight(getParent(t)) == t){	//If the tree is the right child, print 1
		print(getParent(t));	//This recursively calls print
		printf("1");
	}
}
