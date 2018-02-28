// FILE: random.cpp
// CLASS IMPLEMENTED: RandGen (See random.h for documentation)

#include <cassert>	// Provides assert
#include "random.h"	// Provides the RandGen class definition
using namespace std;	// Allows all Standard Library items to be used

RandGen::RandGen( )
{
	// Sets the values to the example in the book
	current_seed = 1;
	current_multiplier = 40;
	current_increment = 725;
	current_modulus = 729;
}

RandGen::RandGen(int seed, int multiplier, int increment, int modulus)
{
	current_seed = seed;
	current_multiplier = multiplier;
	current_increment = increment;
	current_modulus = modulus;	
}

int RandGen::next( )
{
	int new_seed;
	new_seed = (current_multiplier * current_seed + current_increment) % current_modulus;
	current_seed = new_seed;
	return new_seed;
}

void RandGen::setSeed(int new_seed)
{
	current_seed = new_seed;
}
