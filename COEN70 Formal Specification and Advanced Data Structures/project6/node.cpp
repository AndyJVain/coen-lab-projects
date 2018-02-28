// FILE: node.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field
//   and the link to the next node is stored in link_field.

#include "node.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t

using namespace std;

namespace coen70_lab7
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
        const node *cursor;
        size_t answer;

        answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;

        return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
    	head_ptr = new node(entry, head_ptr);
    }
    
    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
    	node *insert_ptr;

    	insert_ptr = new node(entry, previous_ptr->link( ));
    	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
    	const node *cursor;

    	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
    	    if (target == cursor->data( ))
        		return cursor;

    	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	node *cursor;
    	size_t i;

    	assert (0 < position);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
    	const node *cursor;
    	size_t i;

    	assert (position > 0);
    	cursor = head_ptr;
    	for (i = 1; (i < position) && (cursor != NULL); i++)
    	    cursor = cursor->link( );

    	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = head_ptr;
    	head_ptr = head_ptr->link( );
    	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
    	node *remove_ptr;

    	remove_ptr = previous_ptr->link( );
    	previous_ptr->set_link( remove_ptr->link( ) );
    	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
    	while (head_ptr != NULL)
    	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
    	head_ptr = NULL;
    	tail_ptr = NULL;

    	// Handle the case of the empty list.
    	if (source_ptr == NULL)
    	    return;

    	// Make the head node for the newly created list, and put data in it.
    	list_head_insert(head_ptr, source_ptr->data( ));
    	tail_ptr = head_ptr;

    	// Copy the rest of the nodes one at a time, adding at the tail of new list.
    	source_ptr = source_ptr->link( );
    	while (source_ptr != NULL)
    	{
    	    list_insert(tail_ptr, source_ptr->data( ));
    	    tail_ptr = tail_ptr->link( );
    	    source_ptr = source_ptr->link( );
    	}
    }
    
    void list_piece(node* start_ptr, node* end_ptr, node*& head_ptr, node*& tail_ptr)
    {
        // Set both head and tail to NULL
        head_ptr = NULL;
        tail_ptr = NULL;
        
        // If the start pointer is either NULL or at the same position as the end pointer
        if(start_ptr == NULL || start_ptr == end_ptr)
            return;
        
        // Insert the start at the head and set the tail pointer
        list_head_insert(head_ptr,start_ptr->data( ));
        tail_ptr = head_ptr;
        
        // Loops through inserting each piece
        for(start_ptr = start_ptr->link( ); start_ptr != NULL && start_ptr != end_ptr; start_ptr = start_ptr->link( ))
        {
            list_insert(tail_ptr,start_ptr->data( ));
            tail_ptr = tail_ptr->link( );
        }
    }

    size_t list_occurrences(node* head_ptr, const node::value_type& target)
    {
        node *cursor;
        size_t count;
        
        // Loops through and increments the count each time the data matches the target
        for(cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
        {
            if (target == cursor->data( ))
                count++;
        }

        return count;
    }

    void list_insert_at(node*& head_ptr, const node::value_type& entry, size_t position)
    {
        assert(position > 0 && position <= list_length(head_ptr) + 1);

        // Normally the insert would insert after the pointer, but if inserted
        // at position - 1, then it will insert at, not after
        list_insert(list_locate(head_ptr,position-1),entry);
    }

    node::value_type list_remove_at(node*& head_ptr, size_t position)
    {
        assert(position > 0 && position <= list_length(head_ptr));
        
        node::value_type deleted_value;
        node* cursor = head_ptr;
        node* deleted;
        
        int i;
        
        // Moves the cursor to the correct position
        for(i = 1; i < position; i++)
        {
            cursor = cursor->link( );
        }
        
        // Saves the data to be returned
        deleted = cursor->link( );
        deleted_value = deleted->data( );
        
        // Removes the node at the cursor(which is before the value to be deleted)
        list_remove(cursor);
        
        return deleted_value;
    }

    node* list_copy_segment(node* head_ptr, size_t start, size_t finish)
    {
        assert(1 <= start && start <= finish && finish <= list_length(head_ptr));
        
        node* start_ptr = head_ptr;
        node* end_ptr = head_ptr;
        node* new_head;
        node* new_tail;
        
        int i;

        // Move both the new_head and new_tail pointer to the start
        for(i = 1; i <= start; i++)
        {
            start_ptr = new_head->link( );
            end_ptr = new_tail->link( );
        }
        
        // Move the tail pointer to the end
        for(i = start; i <= finish + 1; i++)
        {
            end_ptr = new_tail->link( );
        }
        
        list_piece(start_ptr, end_ptr, new_head, new_tail);
        
        return new_head;
    }
}
