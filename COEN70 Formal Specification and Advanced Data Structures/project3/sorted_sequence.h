// FILE: sorted_sequence.h
// CLASS PROVIDED: sequence (part of the namespace scu_coen70)
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
// typedef ____ value_type
// sequence::value_type is the data type of the items in the sequence. It
// may be any of the C++ built-in types (int, char, etc.), or a class with a
// default constructor, an assignment operator, and a copy constructor.
//
// typedef ____ size_type
// sequence::size_type is the data type of any variable that keeps track of
// how many items are in a sequence.
//
// static const size_type CAPACITY = _____
// sequence::CAPACITY is the maximum number of items that a sequence can hold.
//
// CONSTRUCTOR for the sequence class:
//  sequence( )
//    Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void end( )
//     Precondition: The sequence is not empty.
//     Postcondition: The current item is now the last item in the sequence.
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
//   void remove_front( );
//     Precondition: is_item( ) returns true
//     Postcondition: The item at the front of the sequence has been removed from
//     the sequence, and the current item points at the front of the sequence.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the value that is found at the
//     current index.
//
// VALUE SEMANTICS for the sequence class:
//   Assignments and the copy constructor may be used with sequence objects.

#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <cstdlib>  // Provides size_t

namespace coen70_lab3
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;
        static const size_type CAPACITY = 50;
        
        // CONSTRUCTOR
        sequence( );
        
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void end( );
        void advance( );
        void insert(const value_type& entry);
        void remove_current( );
        void remove_front( );
        
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        bool is_item( ) const;
        value_type current( ) const;
        size_type index( ) const { return current_index; }
        void print_sequence( ) const;
    
    private:
        // PRIVATE DATA
        value_type data[CAPACITY];  // The array to store items
        size_type used;             // How much of array is used
        size_type current_index;    // The current position
    };
    
    sequence operator +(sequence& lhs, sequence& rhs);
    sequence operator +=(sequence& lhs, sequence& rhs);
}

#endif /*SEQUENCE_H*/
