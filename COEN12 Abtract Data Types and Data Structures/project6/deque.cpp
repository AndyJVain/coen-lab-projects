/*
Andy Vainauskas
June 2, 2016
Thursday 9:15am
Project #5

This is the implementation for The Maze Game. It uses a circular, doubly-linked list with a sentinal node. The only difference is that this is written in C++ instead of C.

*/

# include <cassert>
# include "deque.h"

/*
O(1)
This creates the deque and initializes its members
*/
Deque::Deque()
{	
	count = 0;
	head = new Node();
	assert(head != NULL);
	
	head->next = head;
	head->prev = head;

}

/*
O(n)
This deletes all the nodes using a do-while loop
*/
Deque::~Deque()
{
	Node *np = head; 
	Node *next;

	do {	//Loops though and deletes each individual node
		next = np->next;
		delete np;
		np = next;
	} while (np != head);
}

/*
O(1)
This creates a new node and inserts it with its new data right after the sentinel
*/
void Deque::addFirst(int x)
{
	Node *np, *sentinel;

	np = new Node();
	assert(np != NULL);
	np->data = x;

	count ++;
	sentinel = head;

	np->prev = sentinel;
	np->next = sentinel->next;

	sentinel->next->prev = np;
	sentinel->next = np;
}

/*
O(1)
This creates a new node and inserts it with its new data right before the sentinel
*/
void Deque::addLast(int x)
{
    Node *np, *sentinel;

    np = new Node();
    assert(np != NULL);
    np->data = x;

    sentinel = head;
    count ++;

    np->prev = sentinel->prev;
    np->next = sentinel;

    sentinel->prev->next = np;
    sentinel->prev = np;
}

/*
O(1)
This removes the node that the sentinel's next points to
*/
int Deque::removeFirst()
{
    int x;
    Node *np, *sentinel;


    assert(count > 0);
    sentinel = head;
    count --;

    np = sentinel->next;
    sentinel->next = np->next;
    np->next->prev = sentinel;

    x = np->data;
    delete np;
    return x;
}

/*
O(1)
This removes the node that the sentinel's prev points to
*/
int Deque::removeLast()
{
    int x;
    Node *np, *sentinel;

    assert(count > 0);
    sentinel = head;
    count --;

    np = sentinel->prev;
    sentinel->prev = np->prev;
    np->prev->next = sentinel;

    x = np->data;
    delete np;
    return x;
}

/*
O(1)
This returns the data in the first node, which the sentinel's next points to
*/
int Deque::getFirst()
{
    assert(count > 0);
    return head->next->data;
}

/*
O(1)
This returns the data in the last node, which the sentinel's prev points to
*/
int Deque::getLast()
{
    assert(count > 0);
    return head->prev->data;
}

/*
O(1)
This returns the number of nodes
*/
int Deque::size()
{
    return count;
}
