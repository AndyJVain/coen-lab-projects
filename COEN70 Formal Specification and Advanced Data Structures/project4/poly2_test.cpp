// FILE: sequence_test.cxx
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "poly2.h"  // With value_type defined as double
using namespace std;
using namespace coen70_lab4_2;

// PROTOTYPES for functions used by this test program:
void print_menu( );
char get_user_command( );
double get_coeff( );
unsigned int get_exp( );
double get_add( );
double get_x0( );
double get_x1( );
double get_x( );
unsigned int get_e( );

int main( )
{
    polynomial test;              // A polynomial that we'll perform tests on
    polynomial derivative;        // A polynomial that is the derivative
    polynomial antiderivative;    // A polynomial that is the antiderivative
    char choice;                // A command character entered by the user
    
    cout << "I have initialized an empty polynomial class." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'I': test.assign_coef(get_coeff( ),get_exp( ));
                      break;
            case 'A': test.add_to_coef(get_add( ),get_exp( ));
                      break;
            case '/': test.clear( );
                      break;
            case '+': derivative = test.derivative( );
                      cout << "The derivative is: ";
                      cout << derivative << endl;
                      break;
            case '-': antiderivative = test.antiderivative( );
                      cout << "The antiderivative is: ";
                      cout << antiderivative << endl;
                      break;
            case '=': cout << "The result is: " << test.definite_integral(get_x0( ),get_x1( )) << endl;
                      break;
            case 'C': cout << "The coefficient is: " << test.coefficient(get_exp( )) << endl;
                      break;
            case 'D': cout << "The degree is: " << test.degree( ) << endl;
                      break;
            case 'E': cout << "The polynomial value is: " << test.eval(get_x( )) << endl;
                      break;
            case 'Z': if (test.is_zero( ))
                          cout << "The polynomial is 0." << endl;
                      else 
                          cout << "The polynomial is not 0." << endl;
                      break;
            case 'N': cout << "The next term is: " << test.next_term(get_e( )) << endl;
                      break;
            case 'P': cout << "The previous term is: " << test.previous_term(get_e( )) << endl;
                      break;
            case 'O': cout << test << endl;
                      break;
            case 'Q': cout << "Ridicule is the best test of truth." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << " I   assign_coef(coefficient, exponent) function" << endl;
    cout << " A   add_to_coef(amount, exponent) function" << endl;
    cout << " /   clear( ) function" << endl;
    cout << " +   derivative( ) function" << endl;
    cout << " -   antiderivative( ) function" << endl;
    cout << " =   definite_integral(x0, x1) function" << endl;
    cout << " C   coefficient(exponent) function" << endl;
    cout << " D   degree( ) function" << endl;
    cout << " E   eval(double x) function" << endl;
    cout << " Z   is_zero( ) function" << endl;
    cout << " N   next_term(e) function" << endl;
    cout << " P   previous_term(e) function" << endl;
    cout << " O   Print the polynomial" << endl;
    cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

double get_coeff( )
// Library facilities used: iostream
{
    double result;
    
    cout << "Please enter a double for the coefficient: ";
    cin  >> result;
    return result;
}

unsigned int get_exp( )
{
    unsigned int result;
    
    cout << "Please enter the exponent: ";
    cin  >> result;
    return result;
}

double get_add( )
{
    double result;
    
    cout << "Please enter the amount to add: ";
    cin  >> result;
    return result;
}

double get_x0( )
{
    double result;
    
    cout << "Please enter the lower integral bounds: ";
    cin  >> result;
    return result;
}

double get_x1( )
{
    double result;
    
    cout << "Please enter the upper integral bounds: ";
    cin  >> result;
    return result;
}

double get_x( )
{
    double result;
    
    cout << "Please enter the x to evaluate the polynomial at: ";
    cin  >> result;
    return result;
}

unsigned int get_e( )
{
    unsigned int result;
    
    cout << "Please enter the exponent to check near: ";
    cin  >> result;
    return result;
}
