// FILE: bintreetest.cpp
// An test file for the bintreee class.

#include <cassert>      // Provides assert
#include <iostream>     // Provides cout and cin
#include "bintree.h"   // With value_type defined as double
using namespace coen70_lab9;

void print_data(int data)
{
    cout << data << " ";
}

int main( )
{
    // Leaves
    binary_tree_node<int>* a = new binary_tree_node<int>(5, NULL, NULL);
    binary_tree_node<int>* b = new binary_tree_node<int>(19, NULL, NULL);
    binary_tree_node<int>* c = new binary_tree_node<int>(27, NULL, NULL);
    binary_tree_node<int>* d = new binary_tree_node<int>(30, NULL, NULL);
    
    // Children of Root
    binary_tree_node<int>* e = new binary_tree_node<int>(18, a, b);
    binary_tree_node<int>* f = new binary_tree_node<int>(28, NULL, NULL);
    f->set_left(c);
    f->set_right(d);
    
    // Root
    binary_tree_node<int>* root = new binary_tree_node<int>(25, e, f);
    
    // In, Pre, and Post Order
    inorder(print_data, root);
    cout << endl;
    preorder(print_data, root);
    cout << endl;
    postorder(print_data, root);
    cout << endl;
    
    // Tree Copy
    binary_tree_node<int>* new_tree = tree_copy(root);
    inorder(print_data, new_tree);
    cout << endl;
    
    // Tree Size
    cout << "These should be the same: " << endl;
    cout << tree_size(root) << endl;
    cout << tree_size(new_tree) << endl;
    
    // Print
    print(root,5);
    cout << endl;
    tree_clear(root);
    
    tree_clear(root);
    tree_clear(new_tree);
}
