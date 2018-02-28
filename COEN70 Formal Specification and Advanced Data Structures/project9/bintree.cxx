// FILE: bintree.cxx (template file)
// IMPLEMENTS: The functions of the bintree class.
// INVARIANT for the node class:
//   The data of a node is stored in data_field,
//   the link to the two children are stored in
//   left_field and right_field.

#include <cassert>      // Provides assert
#include <iostream>     // Provides cin and cout
#include <iomanip>      // Provides setw
#include <cstdlib>      // Provides NULL and size_t

using namespace std;

namespace coen70_lab9
{
    template <class Process, class BTNode>
    void inorder(Process f, BTNode* node_ptr)
    {
        if(node_ptr != NULL)
        {
            inorder(f, node_ptr->left( ));
            f(node_ptr->data( ));
            inorder(f, node_ptr->right( ));
        }
    }
    
    template <class Process, class BTNode>
    void preorder(Process f, BTNode* node_ptr)
    {
        if(node_ptr != NULL)
        {
            f(node_ptr->data( ));
            preorder(f, node_ptr->left( ));
            preorder(f, node_ptr->right( ));
        }
    }
    
    template <class Process, class BTNode>
    void postorder(Process f, BTNode* node_ptr)
    {
        if(node_ptr != NULL)
        {
            postorder(f, node_ptr->left( ));
            postorder(f, node_ptr->right( ));
            f(node_ptr->data( ));
        }
    }
    
    template <class Item, class SizeType>
    void print(binary_tree_node<Item>* node_ptr, SizeType depth)
    {
        if(node_ptr != NULL)
        {
            print(node_ptr->right( ), depth+1); // Recursively moves through tree
            cout << setw(4*depth) << "";        // Indents 4 times the width
            cout << node_ptr->data( ) << endl;
            print(node_ptr->left( ), depth+1);
        }
    }
    
    template <class Item>
    void tree_clear(binary_tree_node<Item>*& root_ptr)
    {
        if(root_ptr != NULL)
        {
            binary_tree_node<Item>* left = root_ptr->left( );
            binary_tree_node<Item>* right = root_ptr->right( );
            
            tree_clear(left);  // Clear left subtree
            tree_clear(right); // Clear right subtree
            delete root_ptr;    // return root node to the heap
            root_ptr = NULL;    // set root pointer to NULL
        }
    }
    
    template <class Item>
    binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr)
    {
        binary_tree_node<Item> *l_ptr;
        binary_tree_node<Item> *r_ptr;
        
        if(root_ptr == NULL)
            return NULL;
        else
        {
            // Copy the left sub_tree
            l_ptr = tree_copy(root_ptr->left( ));
            
            // Copy the right sub_tree
            r_ptr = tree_copy(root_ptr->right( ));
            
            // Copy the root node and set the root pointer
            return new binary_tree_node<Item>(root_ptr->data( ), l_ptr, r_ptr);
        }
    }
    
    template <class Item>
    std::size_t tree_size(const binary_tree_node<Item>* node_ptr)
    {
        if(node_ptr == NULL)
            return 0;
        
        // Recursively calls tree_size to return the total nodes
        return (tree_size(node_ptr->left( )) + tree_size(node_ptr->right( )) + 1);
    }
}
