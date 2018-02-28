/*
Andy Vainauskas
June 2, 2016
Thursday 9:15am
Project #5

This header file contains the function declarations for the deque.cpp program.'

*/
 
# ifndef DEQUE_H
# define DEQUE_H

class Node{
	public:
		int data;
		Node *next;
		Node *prev;
};

class Deque{
	//Data
	int count;
	class Node *head;
	
	public:
		//Methods
		Deque();
		~Deque();
		int size();
		void addFirst(int x);
		void addLast(int x);
		int removeFirst();
		int removeLast();
		int getFirst();
		int getLast();
};

# endif /* DEQUE_H */
