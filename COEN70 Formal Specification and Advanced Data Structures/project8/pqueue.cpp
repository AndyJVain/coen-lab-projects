// FILE: pqueue.cpp
// IMPLEMENTS: The functions of the pqueue class.
// INVARIANT for the node class:
//   The data of a node is stored in data_field,
//   the link to the next node is stored in link_field,
//   and the priority is stored in priority_field.

#include "pqueue.h"
#include <cassert>      // Provides assert
#include <iostream>     // Provides cin and cout
#include <cstdlib>      // Provides NULL and size_t

using namespace std;

namespace coen70_lab8
{
    // Constructors
    PriorityQueue::PriorityQueue( )
    {
        head_ptr = NULL;
        many_nodes = 0;
    }
    
    PriorityQueue::PriorityQueue(const PriorityQueue& other)
    {
        head_ptr = NULL;
        many_nodes = 0;
        *this = other;
    }
    
    // Destructor
    PriorityQueue::~PriorityQueue( )
    {
        clear( );
        head_ptr = NULL;
    }
    
    // Modification Member Functions
    void PriorityQueue::operator =(const PriorityQueue& other)
    {
        // Checks for self assignment
        if(this == &other)
            return;
        
        // Clears the queue if it contained nodes to prepare for
        // copying over the PriorityQueue "other"
        clear( );
        
        // Copies over the PriorityQueue "other"
        node* temp = other.head_ptr;
        
        while(temp != NULL) {
            insert(temp->data( ),temp->priority( ));
            temp = temp->link( );
        }
    }
    
    void PriorityQueue::insert(const Item& entry, unsigned int priority)
    {
        // If the queue is empty
        if(head_ptr == NULL)
            head_ptr = new node(entry, priority);
        
        // If the queue is not empty
        else
        {
            // If inserting before the head
            if(head_ptr->priority( ) < priority)
                head_ptr = new node(entry, priority, head_ptr);
            
            // If inserting after the head
            else
            {
                node* temp = head_ptr;
                node* iter = head_ptr->link( );
                
                // Moves to find the correct place to insert
                while(iter != NULL && iter->priority( ) >= priority)
                {
                    temp = iter;
                    iter = iter->link( );
                }
                // Insert after temp and before iter
                node* newNode = new node(entry,priority,iter);
                temp->set_link(newNode);
            }
        }
        ++many_nodes;
    }
    
    PriorityQueue::Item PriorityQueue::get_front( )
    {
        // Checks that there is at least 1 node to return
        assert(size( ) > 0);

        // Returns the data after deleting the node
        node* remove = head_ptr;
        Item data = head_ptr->data( );
        head_ptr = head_ptr->link( );
        --many_nodes;
        delete remove;
        return data;
    }
    
    // Helper function for the assignment operator
    void PriorityQueue::clear( )
    {
        node* temp = head_ptr;
        
        // Moves the head_ptr throught the Priority Queue,
        // using temp to delete each node
        while(head_ptr != NULL)
        {
            head_ptr = head_ptr->link( );
            delete temp;
            temp = head_ptr;
        }
        many_nodes = 0;
    }
}
