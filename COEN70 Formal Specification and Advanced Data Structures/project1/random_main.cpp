// FILE: random_main.cpp
//
// Includes the main function to test the functionality of the random class.

#include <iostream>	// Provides cout
#include <iostream>	// Provides EXIT_SUCCESS
#include <cassert>	// Provides assert
#include "random.h"	// Provides the header file
using namespace std;	// Allows all standard library items to be used

int main( )
{
	int number;	
	RandGen r(20, 5, 2, 432);

	number = r.next( );
	cout << number << endl;

	number = r.next( );
	cout << number << endl;
	
	number = r.next( );
	cout << number << endl;

	r.setSeed(8);
	number = r.next( );	
	cout << number << endl;

	number = r.next( );
	cout << number << endl;
}
