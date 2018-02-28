// FILE: statistician2.h
// CLASS PROVIDED: statistician
//
// CONSTRUCTOR for the statistician class:
// 	statistician( )
//         Postcondition: The length and the sum are both 0.
//
// MODIFICATION MEMBER FUNCTIONS for the statistician class:
// 	void next_number( )
// 	   Postcondition: a new number is added to the sequence, thereby
// 	   updating the private member variables. 
//
// 	void erase( )
// 	   Postcondition: the sequence of numbers is removed by setting the 
// 	   private member variables to 0.
//	
//	statistician operator =(const statistician& s2)
//	   Postcondition: This bag is the same as s2.
//
//	statistician operator +(const statistician& s2)
//	   Postcondition: This bag has the values of s2 added to the end of it.
//
// CONSTANT MEMBER FUNCTIONS for the statistician class:
// 	void length( )
// 	   Postcondition: The value returned is the total number of values
// 	   in the sequence.
//
// 	void last( )
//	   Precondition: The sequence is non-empty.
// 	   Postcondition: The value returned is the last number added to 
// 	   the sequence.
//
// 	void sum( )
// 	   Postcondition: The value returned is the sum of the numbers in 
// 	   the sequence.
//
// 	void mean( )
// 	   Precondition: The sequence is non-empty.
// 	   Postcondition: The value returned is the mean of the numbers in
// 	   the sequence.
//
// 	void smallest( )
// 	   Precondition: The sequence is non-empty.
// 	   Postcondition: The value returned is the smallest number in 
// 	   the sequence.
//
// 	void largest( )
// 	   Precondition: The sequence is non-empty. 
// 	   Postcondition: The value returned is the largest number in
// 	   the sequence.
//
// VALUE SEMANTICS for the statistician class:
// 	Assignments and the copy constructor may be used with semantics objects.

#ifndef statistician_h
#define statistician_h

namespace coen70_lab2
{
    class statistician
    {
    public:
        // CONSTRUCTORS
        statistician( );
        
        // MODIFICATION MEMBER FUNCTIONS
        void next_number(double num);
        void erase( );
        statistician operator =(const statistician& s2);
        statistician operator +(const statistician& s2);
        
        // CONSTANT MEMBER FUNCTIONS
        double length( ) const { return s_length; }
        double last( ) const;
        double sum( ) const { return s_sum; }
        double mean( ) const;
        double smallest( ) const;
        double largest( ) const;
        
    private:
        int s_length;
        double s_last;
        double s_sum;
        double s_mean;
        double s_smallest;
        double s_largest;
    };
}

#endif
