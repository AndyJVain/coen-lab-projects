/*
Andy Vainauskas
May 5, 2016
Thursday 9:15am
Project #4

This is the implementation for The Maze Game. It uses a circular, doubly-linked list with a sentinel node. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "deque.h"

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}NODE;

struct deque{
	int count;
	struct node *head;
};

/*
O(1)
This creates the deque by allocating memory for it and initializing its members
*/
DEQUE *createDeque(void)
{
	DEQUE *dp;
	dp = malloc(sizeof(DEQUE));
	assert(dp != NULL);
	
	dp->count = 0;
	dp->head = malloc(sizeof(NODE));
	assert(dp->head != NULL);		
	dp->head->next = dp->head;
	dp->head->prev = dp->head;
	
	return dp;
}

/*
O(n)
This frees all the nodes first by looping through using the number specified by count, and then frees the sentinal and then the deque entirely
*/
void destroyDeque(DEQUE *dp)
{
	NODE *np = dp->head->next;

	while(np != dp->head){
		np = np->next;
		free(np->prev);			
	}

	free(dp->head);
	free(dp);
}

/*
O(1)
This produces the number of nodes
*/
int numItems(DEQUE *dp)
{
	return dp->count;
}

/*
O(1)
This allocates memory for a new node and inserts it with its new data right after the sentinel
*/
void addFirst(DEQUE *dp, int x)
{
	NODE *np = malloc(sizeof(NODE));
	assert(np != NULL);	

	np->data = x;
	np->next = dp->head->next;
	np->prev = dp->head;
	dp->head->next = np;
	np->next->prev = np;
	
	dp->count++;
}

/*
O(1)
This allocates memory for a new node and inserts it with its new data right before the sentinel
*/
void addLast(DEQUE *dp, int x)
{
	NODE *np = malloc(sizeof(NODE));
	assert(np != NULL);

	np->data = x;
	np->next = dp->head;
	np->prev = dp->head->prev;
	dp->head->prev = np;
	np->prev->next = np;

	dp->count++;
}

/*
O(1)
This removes the node that the sentinel's next points to
*/
int removeFirst(DEQUE *dp)
{
	NODE *np = dp->head->next;
	assert(np != NULL);
	int data = np->data;

	dp->head->next = np->next;
	np->next->prev = dp->head;
	free(np);
	dp->count--;
	
	return data;
}

/*
O(1)
This removes the node that the sentinel's prev points to
*/
int removeLast(DEQUE *dp)
{
	NODE *np = dp->head->prev;
	assert(np != NULL);
	int data = np->data;

	dp->head->prev = np->prev;
	np->prev->next = dp->head;
	free(np);
	dp->count--;	

	return data;
}

/*
O(1)
This returns the data in the first node, which the sentinel's next points to
*/
int getFirst(DEQUE *dp)
{
	return dp->head->next->data;
}

/*
O(1)
This returns the data in the last node, which the sentinel's prev points to
*/
int getLast(DEQUE *dp)
{
	return dp->head->prev->data;
}


