// FILE: statistician_main.cpp
// 
// Includes the main function to test the functionality of the statistician class.

#include <iostream>		// Provides cout
#include <cstdlib>		// Provides EXIT_SUCCESS
#include <cassert>		// Provides assert
#include "statistician.h"	// Provides the header file
using namespace std;		// Allows all standard library items to be used

void display(statistician& s);

int main( ) 
{
	statistician s;

	s.next_number(-3.8);
	display(s);
	
	s.next_number(5.26);
	display(s);

	s.next_number(-7.54);
	display(s);

	s.next_number(0);
	display(s);

	s.erase( );
	display(s);

	s.next_number(18.982);
	display(s);

	return EXIT_SUCCESS;
}

// Updates the values
void display(statistician& s)
{
	cout << "Length: " << s.length( ) << endl;
	cout << "Sum: " << s.sum( ) << endl;
	cout << "Last number: " << s.last( ) << endl;
	cout << "Mean: " << s.mean( ) << endl;
	cout << "Smallest number: " << s.smallest( ) << endl;
	cout << "Largest number: " << s.largest( ) << endl;
	cout << endl;
}
