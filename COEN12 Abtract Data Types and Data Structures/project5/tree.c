/*
Andy Vainauskas
May 19, 2016
Thursday 9:15am
Project #5

This is the implementation of treesort, which takes numbers in from the keyboard and sorts them from least to greatest.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"

void cutFromParent(struct tree *child);

typedef struct tree TREE;

struct tree{
	int data;
	TREE *left;
	TREE *right;
	TREE *parent;
};

/*
O(1)
This creates a tree by allocating memory for it and checking how to arrange and move its pointers.
*/
struct tree *createTree(int data, struct tree *left, struct tree *right)
{
	struct tree *new;	//This allocates memory for a new tree pointed to by new
	new = malloc(sizeof(struct tree));
	assert(new != NULL);
	new->parent = NULL;

	if(left != NULL){	//This checks if the left is a tree that already exists
		cutFromParent(left);
		left->parent = new;
	}
	if(right != NULL){	//This checks if the right is a tree that already exists
		cutFromParent(right);
		right->parent = new;
	}
	new->left = left;	//This sets the data and the left and right pointers
	new->right = right;
	new->data = data;
	return new;
}

/*
O(n)
This is a postorder function that destroys each part of the tree.
*/
void destroyTree(struct tree *root)
{
	if(root == NULL)	//This is the base case that checks if there is a leaf to delete
		return;

	destroyTree(root->left);	//This moves all the way to the end and frees the leaves bottom-up
	destroyTree(root->right);
	free(root);
}

/*
O(1)
This returns the data in the root that is passed in as a parameter.
*/
int getData(struct tree *root)
{
	return root->data;
}

/*
O(1)
This returns the left subtree that is pointed by root, which is passed in as a parameter.
*/
struct tree *getLeft(struct tree *root)
{
	return root->left;
}

/*
O(1)
This returns the right subtree that is pointed by root, which is passed in as a parameter.
*/
struct tree *getRight(struct tree *root)
{
	return root->right;
}

/*
O(1)
This returns the parent that is pointed by root, which is passed in as a parameter.
*/
struct tree *getParent(struct tree *root)
{	
	return root->parent;
}

/*
O(1)
This updates the left subtree of root, passed in as parameters, and rearranges the pointers accordingly.
*/
void setLeft(struct tree *root, struct tree *left)
{
	if(root->left != NULL){
		root->left->parent = NULL;	//Disconnects root's left if it exists
	}

	root->left = left;
	if(left != NULL && left->parent != NULL){	//Disconnects left from its parent and connects it to root's left
		cutFromParent(left);
		left->parent = root;
	}
}

/*
This updates the right subtree of root, passed in as parameters, and rearranges the pointers accordingly.
*/
void setRight(struct tree *root, struct tree *right)
{
	if(root->right != NULL){
		root->right->parent = NULL;	//Disconnects root's left if it exists
	}
	
	root->right = right;
	if(right != NULL && right->parent != NULL){	//Disconnects left from its parent and connects it to root's left
		cutFromParent(right);
		right->parent = root;
	}
}

/*
O(1)
This function checks if the child (passed in as a parameter) is either the left or right of its parent disconnects the child from the parent accordingly
*/
void cutFromParent(struct tree *child)
{
	if(child->parent == NULL){	//This checks if the parent exists. If it doesn't, there is no parent to cut from
		return;
	}

	if(child->parent->left == child){	//If it is the left child, it sets the parent's left pointer to null
		child->parent->left = NULL;
	}
	else{					//If it is the right child, it sets the parent's left pointer to null
		child->parent->right = NULL;
	}
}
