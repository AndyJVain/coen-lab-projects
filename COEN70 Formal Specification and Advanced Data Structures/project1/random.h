// FILE: random.h
// CLASS PROVIDED: RandGen
//
// CONSTRUCTORS for the RandGen class:
// 	RandGen( )
// 	   Postcondition: The seed, multiplier, increment, and modulus are set
//	   to the values in the example in the textbook. 
//
//	RandGen(int seed, int multiplier, int increment, int modulus) 
//	   Postcondition: The seed, multiplier, increment, and modulus are set
//	   to the values that the user enters.
//
// MODIFICATION MEMBER FUNCTIONS for the RandGen class:
// 	void next( )
// 	   Postcondition: The next number in the sequence is generated and returned. 
//
// 	void setSeed( )
// 	   Postcondition: A new seed is set.
//
// VALUE SEMANTICS for the RandGen class:
// 	Assignments and the copy constructor may be used with RandGen objects.

#ifndef random_h
#define random_h

class RandGen
{
public:
	// CONSTRUCTORS
	RandGen( );
	RandGen(int seed, int multiplier, int increment, int modulus);

	// MODIFICATION MEMBER FUNCTIONS
	int next( );
	void setSeed(int new_seed);	
private:
	int current_seed;
	int current_multiplier;
	int current_increment;
	int current_modulus;	

};

#endif
