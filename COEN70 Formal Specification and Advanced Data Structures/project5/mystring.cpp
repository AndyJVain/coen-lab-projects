// FILE: mystring.cpp
// CLASS IMPLEMENTED: string (see mystring.h for documentation)
// INVARIANT for the string class:
//  1. The string is stored as a null-terminated string in the dynamic array that characters points to.
//  2. The total length of the dynamic array is stored in the member variable allocated.
//  3. The total number of characters prior to the null character is stored in current_length, which is always less than allocated.

#include "mystring.h"   // Provides the string class definition
#include <cassert>      // Provides assert
#include <iostream>		// Provides cout
#include <cstring>      // Provides string functions

namespace coen70_lab5
{
    // Constructor
    string::string(const char str[ ])
    {
        current_length = strlen(str);
        allocated = current_length + 1;
        sequence = new char [allocated];
        sequence[0] = '\0';
        strncpy(sequence,str,current_length);
    }
    
    // Copy constructor
    string::string(const string& source)
    {
        current_length = 0;
        allocated = 0;
        sequence = NULL;
        *this = source;
    }
    
    // Destructor
    string::~string( )
    {
        delete [ ] sequence;
    }
    
    void string::operator +=(const string& addend)
    {
        // Allocates proper memory space for the string with the new length
        reserve(current_length + addend.current_length);
        
        // Concatenates with the addend
        strncat(sequence, addend.sequence, addend.current_length);
        
        // Set the last space to the null character, and update the current_length
        sequence[allocated-1] = '\0';
        current_length += addend.current_length;
    }
    
    void string::operator +=(const char addend[ ])
    {
        // Create a new string from addend, then use the += operator to add it to *this
        string res(addend);
        *this += res;
    }
    
    void string::operator +=(char addend)
    {
        // Create a temporary string from the character, then use the += operator to add it to *this
        char temp[2];
        temp[0] = addend;
        temp[1] = '\0';
        string res(temp);
        *this += res;
    }
    
    void string::reserve(size_t n)
    {
        int i;
        
        // Checks if new space needs to be added or not
        if(n >= allocated)
        {
            // Create a temporary pointer pointing to sequence
            char *temp = sequence;
            allocated = n + 1;
            
            // Allocate space for a new, larger array
            sequence = new char[allocated];
            
            // Checks that the creation of the array was successful
            assert(sequence != NULL);
            
            // Add the null character
            sequence[0] = '\0';
            
            // Copies the data over before deleting the temp
            if(temp != NULL)
            {
                strncpy(sequence,temp,current_length+1);
                delete [] temp;
            }
        }
    }
    
    void string::operator =(const string& source)
    {
        // Checks for self-assignment
        if(this != &source)
        {
            // Allocates a array to match the size of source
            reserve(source.current_length);
            
            // Copies over the source, then updates allocated and current_length
            strncpy(sequence, source.sequence, source.current_length);
            allocated = source.allocated;
            current_length = source.current_length;
        }
    }
    
    void string::insert(const string& source, unsigned int position)
    {
        // Check to make sure the position to insert is within the bounds of the string
        assert(position <= current_length);
        
        // Create a temporary object to save the old string and allocate the larger size
        string old = *this;
        reserve(current_length + source.current_length);
        
        // Copies over the first half of the string up until the position
        sequence[0] = '\0';
        strncpy(sequence, old.sequence, position);
        
        // Concatenates the source to the end of the string, then adding the rest of
        // the old string to the end
        sequence[position] = '\0';
        strncat(sequence, source.sequence, source.current_length + 1);
        strncat(sequence, old.sequence + position, current_length - position);
        sequence[allocated - 1] = '\0';
        current_length += source.current_length;
    }
    
    void string::replace(char c, unsigned int position)
    {
        // Makes sure that the position is within the bounds of the string
        assert(position <= current_length);
        
        // Add the new character at the position
        sequence[position] = c;
    }
    
    char string::operator [ ](size_t position) const
    {
        // Checks that the position is less than the current length
        assert(position < current_length);
        return sequence[position];
    }
    
    int string::search(char c) const
    {
        int i;
        
        // Loops through checking each place in the array to see if it matches c
        for(i = 0; i < current_length; i++)
        {
            if(sequence[i] == c)
                // Outputs the position where c is found
                return i;
        }
        
        // If the letter isn't in the string, it outputs -1
        return -1;
    }
    
    unsigned int string::count(char c) const
    {
        int count = 0;
        int i;
        
        // Similar to search, but this keeps track of the occurrances and
        // returns the count
        for(i = 0; i < current_length; i++)
        {
            if(sequence[i] == c)
                count++;
        }
        return count;
    }
    
    std::ostream& operator <<(std::ostream& outs, const string& source)
    {
        outs << source.sequence;
        return outs;
    }
    
    bool operator ==(const string& s1, const string& s2)
    {
        return (strcmp(s1.sequence, s2.sequence) == 0);
    }
    
    bool operator !=(const string& s1, const string& s2)
    {
        return (strcmp(s1.sequence, s2.sequence) != 0);
    }
    
    bool operator >=(const string& s1, const string& s2)
    {
        return (strcmp(s1.sequence, s2.sequence) >= 0);
    }
    
    bool operator <=(const string& s1, const string& s2)
    {
        return (strcmp(s1.sequence, s2.sequence) <= 0);
    }
    
    bool operator > (const string& s1, const string& s2)
    {
        return (strcmp(s1.sequence, s2.sequence) > 0);
    }
    
    bool operator < (const string& s1, const string& s2)
    {
        return (strcmp(s1.sequence, s2.sequence) < 0);
    }
    
    string operator +(const string& s1, const string& s2)
    {
        // Makes a temp string and adds s1 and s2 to it
        string temp;
        temp += s1;
        temp += s2;
        
        return temp;
    }

    std::istream& operator >>(std::istream& ins, string& target)
    {
        // Ignores whitespace at the beginning
        while(ins && isspace(ins.peek()))
            ins.ignore( );
        
        // Creates a temp character where the ins will store individual characters
        char temp;
        target = "";
        
        // Continues while there is an input and there isn't whitespace in the next position
        while(ins && !isspace(ins.peek()))
        {
            // Stores a character in temp and adds it to the target
            ins >> temp;
            target += temp;
        }
        return ins;
    }

    void getline(std::istream& ins, string& target, char delimiter)
    {
        // Ignores whitespace at the beginning
        while(ins && isspace(ins.peek()))
            ins.ignore( );
        
        // Creates a temp character where the ins will store individual characters
        char temp;
        target = "";
        
        // Continues while there is an input and the next character isn't the delimeter
        while(ins && ins.peek( ) != delimiter)
        {
            // Stores a character in temp and adds it to the target
            ins >> temp;
            target += temp;
        }
    }
}

