// FILE: sequence_main.cpp
//
// Includes the main function to test the functionality of the sequence class.

#include <iostream>	// Provides cout
#include <iostream>	// Provides EXIT_SUCCESS
#include <cassert>	// Provides assert
#include "sequence.h"	// Provides the header file
using namespace std;	// Allows all standard library items to be used
using namespace coen70_lab3;

int main( )
{
    sequence s1;
    sequence s2;
    sequence s3;
    
    // Test operators
    s1.insert(3);
    s1.insert(27);
    s1.insert(976);
    s1.insert(87);
    s1.insert(67);
    
    s2 += s1;
    
    cout << "These should be the same:" << endl;
    s1.print_sequence( );
    s2.print_sequence( );
    
    s2.insert_front(1.5);
    
    s3 = s1 + s2;
    
    cout << "These should be: (67, 87, 976, 27, 3, 1.5, 67, 87, 976, 27, 3,)" << endl;
    s3.print_sequence( );
}




