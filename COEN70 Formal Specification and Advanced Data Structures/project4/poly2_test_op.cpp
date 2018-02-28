// FILE: sequence_test.cxx
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "poly2.h"  // With value_type defined as double
using namespace std;
using namespace coen70_lab4_2;

int main( )
{
    polynomial test;
    polynomial testAdd;
    polynomial testSub;
    polynomial testMult;
    polynomial testEq;
    
    test.assign_coef(4,5);
    test.assign_coef(2,3);
    test.assign_coef(1,0);
    
    // Equal
    testEq = test;
    cout << "Equal: " << testEq << endl;
    
    // Add
    testAdd = test + testEq;
    cout << "Add: " << testAdd << endl;
    
    // Mult
    testMult = test * testEq;
    cout << "Mult: " << testMult << endl;
    
    // Subtract
    test.assign_coef(6,8);
    testSub = test - testEq;
    cout << "Sub: " << testSub << endl;
}
