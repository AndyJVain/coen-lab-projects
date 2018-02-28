// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see statistician.h for documentation)

#include "statistician.h"	// Provides the statistician class definition
#include <cassert>		// Provides assert
#include <iostream>		// Provides cout
using namespace std;		// Allows all Standard Library items to be used 

statistician::statistician( )
{
	s_length = 0;
	s_sum = 0;
}

double statistician::last( ) const
{
	assert(s_length > 0);
	return s_last;
}

double statistician::mean( ) const
{
	assert(s_length > 0);
	return s_mean;
}

double statistician::smallest( ) const
{
	assert (s_length > 0);
	return s_smallest;
}

double statistician::largest( ) const
{
	assert (s_length > 0);	
	return s_largest;
}


void statistician::next_number(double num)
{
	// Updates the length
	s_length += 1;

	// Updates the last number
	s_last = num;

	// Updates the sum
	s_sum += num;

	// Updates the mean
	s_mean = s_sum / s_length;

	// Updates the smallest number
	// First number entered
	if (s_length == 1) 
		s_smallest = num;
	// Checks if the new number is smallest
	if (num < s_smallest)
		s_smallest = num;
		
	// Updates the largest number	
	// First number entered
	if (s_length == 1)
		s_largest = num;
	// Checks if the new number is largest
	if (num > s_largest) 
		s_largest = num;
}

void statistician::erase( )
{
	s_length = 0;
	s_last = 0;
	s_sum = 0;
	s_mean = 0;
	s_smallest = 0;
	s_largest = 0;	
}
