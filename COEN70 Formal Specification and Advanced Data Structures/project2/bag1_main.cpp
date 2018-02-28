// FILE: bag1_main.cpp
//
// Includes the main function to test the functionality of the bag1 class.

#include <iostream>	// Provides cout
#include <iostream>	// Provides EXIT_SUCCESS
#include <cassert>	// Provides assert
#include "bag1.h"	// Provides the header file
using namespace std;	// Allows all standard library items to be used
using namespace coen70_lab2;

int main( )
{
    int i;
    int size;
    bag b1;
    bag b2;

    b1.insert(7);
    b1.insert(2);
    b1.insert(7);
    b1.insert(7);
    b1.insert(3);
    
    b2.insert(2);
    b2.insert(7);

    b1 -= b2;

    size = b1.size( );
    
    cout << "Size: " << size << endl;
    
    b1.print_data( );
}
