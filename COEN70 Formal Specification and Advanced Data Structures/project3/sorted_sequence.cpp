// FILE: sequence.cpp
// CLASS IMPLEMENTED: sequence (see sequence for documentation)

#include "sorted_sequence.h"	// Provides the sequence class definition
#include <cassert>		// Provides assert
#include <iostream>		// Provides cout
using namespace std;	// Allows all Standard Library items to be used

namespace coen70_lab3
{
    sequence::sequence( )
    {
        used = 0;
        current_index = 0;
    }

    void sequence::start( )
    {
        // Checks to see if the sequence is empty or not
        if(used != 0)
            current_index = 0;
        else
            cout << "There are no items in the sequence to start." << endl;
    }
    
    void sequence::end( )
    {
        assert(used != 0);
        
        current_index = used - 1;
    }

    void sequence::advance( )
    {
        assert(is_item( ) == true);
        
        current_index++;
    }

    void sequence::insert(const value_type& entry)
    {
        assert(size( ) < CAPACITY);
     
        int i;
        
        current_index = 0;
        
        // If there are no items in the sequence, then the number is inserted
        // at the beginning
        if(used == 0)
        {
            data[current_index] = entry;
            used++;
        }
        else
        {
            // Traverses to the correct spot (in order) to insert the number
            while(data[current_index] < entry)
            {
                if(current_index != used)
                    current_index++;
                else
                    break;
            }
            // If there is an item (i.e. the index isn't at the end of the sequence,
            // then shift the sequence down one and insert the number
            if(is_item( ) == true)
            {
                for(i = used; i > current_index; i--)
                {
                    data[i] = data[i-1];
                }
            
                data[current_index] = entry;
                used++;
            }
            // If the number is inserted at the end, don't shift any numbers,
            // just insert directly
            else
            {
                data[current_index] = entry;
                used++;
            }
        }
    }
    
    void sequence::remove_current( )
    {
        assert(is_item( ) == true);
        
        int i;
        
        // This moves all the data down one space, thus "removing" the
        // current item
        for(i = current_index; i < used; i++)
        {
            data[i] = data[i+1];
        }
        used--;
    }
    
    void sequence::remove_front( )
    {
        assert(size( ) != 0);
        
        // Moves the current_index to the front, then removes
        // the current item
        start( );
        remove_current( );
    }
    
    bool sequence::is_item( ) const
    {
        // Checks to see if the index is within the range of
        // the number in the sequence
        if(current_index < used)
            return true;
        else
            return false;
    }
    
    sequence::value_type sequence::current( ) const
    {
        assert(is_item( ) == true);
        
        return data[current_index];
    }
    
    // Helper function to print the sequence
    void sequence::print_sequence( ) const
    {
        int i;
        
        cout << "Sequence is:" << endl;
        
        for(i = 0; i < used; i++)
        {
            cout << data[i] << ", ";
        }
        
        cout << endl;
    }
    
    sequence operator +(sequence& lhs, sequence& rhs)
    {
        sequence result;
        
        // Uses the += operator to create a sequence object to return
        result += lhs;
        result += rhs;
        
        return result;
    }
    
    sequence operator +=(sequence& lhs, sequence& rhs)
    {
        int i;
        rhs.start( );
        
        // Adds the contents of rhs to the end of lhs
        for(i = 0; i < rhs.size( ); i++)
        {
            lhs.insert(rhs.current( ));
            rhs.advance( );
        }
        return lhs;
    }
}
