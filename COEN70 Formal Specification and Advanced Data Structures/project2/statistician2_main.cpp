// FILE: statistician_main.cpp
// 
// Includes the main function to test the functionality of the statistician class.

#include <iostream>		// Provides cout
#include <cstdlib>		// Provides EXIT_SUCCESS
#include <cassert>		// Provides assert
#include "statistician2.h"	// Provides the header file
using namespace std;		// Allows all standard library items to be used
using namespace coen70_lab2;

void display(statistician s);

int main( ) 
{
    statistician s1;
    statistician s2;
    statistician s3;
    
	// Test values in s1
	s1.next_number(5);
	s1.next_number(1);
	s1.next_number(87);
	
    cout << "s1" << endl;
	display(s1);

	// Test values in s2
	s2.next_number(32);
	s2.next_number(-10);
	s2.next_number(4);
    
	cout << "s2" << endl;
	display(s2);

	// Test overloaded operators
	cout << "s1 + s3" << endl;
	display(s1+s3);

	cout << "s1 + s2" << endl;
	display(s1+s2);

	s1 = s2;
	s3 = s2;
	cout << "s1 = s2 = s3" << endl;
	display(s1);
	display(s2);
    display(s3);

	return EXIT_SUCCESS;
}

// Updates the values
void display(statistician s)
{
	cout << "Length: " << s.length( ) << endl;
	cout << "Sum: " << s.sum( ) << endl;
	cout << "Last number: " << s.last( ) << endl;
	cout << "Mean: " << s.mean( ) << endl;
	cout << "Smallest number: " << s.smallest( ) << endl;
	cout << "Largest number: " << s.largest( ) << endl;
	cout << endl;
}
