// FILE: sequence.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "sequence.h"
#include <cassert>    // Provides assert
#include <iostream>
#include <cstdlib>    // Provides NULL and size_t

using namespace std;

namespace coen70_lab7
{
    // CONSTRUCTORS and DESTRUCTOR
    sequence::sequence( )
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
    }
    
    sequence::sequence(const sequence& source)
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        many_nodes = 0;
        *this = source;
    }
    
    sequence::~sequence( )
    {
        list_clear(head_ptr);
        many_nodes = 0;
    }
    
    void sequence::start( )
    {
        // Checks to see if there is a node to start at
        if(many_nodes == 0)
            return;
        
        cursor = head_ptr;
        precursor = NULL;
    }
    
    void sequence::end( )
    {
        if(many_nodes == 0)
            return;
     
        // Checks if there is only 1 (so precursor is not set)
        if(many_nodes == 1)
        {
            cursor = head_ptr;
            precursor = NULL;
        }
        
        // Moves cursor to the end, and precursor to the end - 1
        else
        {
            cursor = list_locate(head_ptr, many_nodes);
            precursor = list_locate(head_ptr, many_nodes - 1);
        }
    }
    
    void sequence::advance( )
    {
        // Checks if there is a current item
        if(is_item( ) == true)
        {
            // If the cursor is at the end, then set both to NULL
            if(cursor == tail_ptr)
            {
                precursor = NULL;
                cursor = NULL;
            }
            // Advance both pointers forward one
            else
            {
                precursor = cursor;
                cursor = cursor->link( );
            }
        }
    }
    
    void sequence::insert(const value_type& entry)
    {
        // If the cursor isn't pointing to anything (insert at front)
        if(is_item( ) == false)
        {
            // If there aren't any nodes (set the tail)
            if(many_nodes == 0)
            {
                list_head_insert(head_ptr, entry);
                tail_ptr = head_ptr;
                cursor = head_ptr;
                precursor = NULL;
            }
            // If there are nodes (don't move the tail)
            else
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
        }
        
        // If the cursor is pointing to something (insert before)
        else
        {
            // If the cursor is at the head
            if(cursor == head_ptr)
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            
            // If the cursor is at the tail or in the middle
            else
            {
                list_insert(precursor,entry);
                cursor = precursor->link( );
            }
        }
        many_nodes++;
    }
    
    void sequence::attach(const value_type& entry)
    {
        // If the cursor isn't pointing to anything (insert at end)
        if(is_item( ) == false)
        {
            // If there aren't any nodes (set the tail)
            if(many_nodes == 0)
            {
                list_head_insert(head_ptr, entry);
                tail_ptr = head_ptr;
                cursor = head_ptr;
                precursor = NULL;
            }
            // If there are nodes (don't move the tail)
            else
            {
                precursor = tail_ptr;
                cursor = tail_ptr;
                list_insert(cursor, entry);
                cursor = cursor->link( );
                tail_ptr = cursor;
            }
        }
    
        // If the cursor is pointing to something (insert after)
        else
        {
            // If the cursor is at the head
            if(cursor == head_ptr)
            {
                // If there is only 1 node (set the tail)
                if(many_nodes == 1)
                {
                    list_insert(cursor, entry);
                    precursor = head_ptr;
                    cursor = cursor->link( );
                    tail_ptr = cursor;
                }
                // If there is more than one node (don't set the tail)
                else
                {
                    list_insert(cursor, entry);
                    precursor = head_ptr;
                    cursor = cursor->link( );
                }

            }
            // If the cursor is at the tail (set the tail)
            else if(cursor == tail_ptr && cursor != head_ptr)
            {
                list_insert(cursor, entry);
                precursor = cursor;
                cursor = cursor->link( );
                tail_ptr = cursor;
            }
            // If the cursor is in the middle (don't set the tail)
            else
            {
                list_insert(cursor,entry);
                precursor = cursor;
                cursor = cursor->link( );
            }
        }
        many_nodes++;
    }
    
    void sequence::operator =(const sequence& source)
    {
        // Checks for self assignment
        if(this == &source)
            return;
        
        // If there is no current item
        if(source.is_item( ) == false)
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            cursor = NULL;
            precursor = NULL;
        }
        // If there is a current item
        else
        {
            // If the current item is at the head
            if(source.cursor == source.head_ptr)
            {
                list_copy(source.head_ptr, head_ptr, tail_ptr);
                precursor = NULL;
                cursor = head_ptr;
            }
            // If it is not at the head
            else
            {
                list_piece(source.head_ptr, source.cursor, head_ptr, precursor);
                list_piece(source.cursor, source.tail_ptr->link( ), cursor, tail_ptr);
                
                precursor->set_link(cursor);
            }
        }
        many_nodes = source.many_nodes;
    }
    
    void sequence::remove_current( )
    {
        assert(is_item( ) == true);
        
        // If removing at the head
        if(cursor == head_ptr)
        {
            // If removing the only node
            if(many_nodes == 1)
            {
                list_head_remove(head_ptr);
                precursor = NULL;
                cursor = NULL;
                head_ptr = NULL;
                tail_ptr = NULL;
            }
            // If removing the head when there are multiple nodes
            else
            {
                list_head_remove(head_ptr);
                cursor = head_ptr;
                precursor = NULL;
            }
        }
        // If removing at the tail
        else if(cursor == tail_ptr)
        {
            list_remove(precursor);
            tail_ptr = precursor;
            precursor = NULL;
            cursor = NULL;
        }
        // If removing in the middle
        else
        {
            cursor = cursor->link( );
            list_remove(precursor);
        }
        many_nodes--;
    }
    
    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size( ) const
    {
        return many_nodes;
    }
    
    bool sequence::is_item( ) const
    {
        if(cursor != NULL)
            return true;
        else
            return false;
    }
    
    sequence::value_type sequence::current( ) const
    {
        assert(is_item( ) == true);
        
        return cursor->data( );
    }
}
