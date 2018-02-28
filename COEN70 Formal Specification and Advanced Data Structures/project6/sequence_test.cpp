// FILE: sequence_test.cxx
// An interactive test program for the new sequence class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "sequence.h"  // With value_type defined as double
using namespace std;
using namespace coen70_lab7;

// PROTOTYPES for functions used by this test program:
void print_menu( );
char get_user_command( );
double get_entry( );
void print_sequence(sequence& source);
void cheat_print(sequence& source);


int main( )
{
    sequence test;          // A sequence that we'll perform tests on
    sequence copy;          // A sequence that tests the copy constructor
    char choice;            // A command character entered by the user
    
    cout << "I have initialized an empty sequence class." << endl;

    do
    {
        print_menu( );
        choice = toupper(get_user_command( ));
        switch (choice)
        {
            case 'S': test.start( );
                      break;
            case 'E': test.end( );
                      break;
            case '+': test.advance( );
                      break;
            case 'I': test.insert(get_entry( ));
                      break;
            case 'A': test.attach(get_entry( ));
                      break;
            case '=': copy = test;
                      cout << "The copy is: " << endl;
                      print_sequence(copy);
                      break;
            case 'R': test.remove_current( );
                      break;
            case 'T': cout << "The size is: " << test.size( ) << endl;
                      break;
            case '?': if(test.is_item( ))
                          cout << "TRUE-there is a current item." << endl;
                      else
                          cout << "FALSE-there is no current item." << endl;
                      break;
            case 'C': cout << "The current item is: " << test.current( ) << endl;
                      break;
            case 'O': cheat_print(test);
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
    cout << " S   start( ) function" << endl;
    cout << " E   end( ) function" << endl;
    cout << " +   advance( ) function" << endl;
    cout << " I   insert(const value_type& entry) function" << endl;
    cout << " A   attach(const value_type& entry) function" << endl;
    cout << " =   assignment operator" << endl;
    cout << " R   remove_current( ) function" << endl;
    cout << " T   size( ) function" << endl;
    cout << " ?   is_item( ) function" << endl;
    cout << " C   current( ) function" << endl;
    cout << " O   Print the sequence" << endl;
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

double get_entry( )
{
    double result;
    
    cout << "Please enter the entry value: ";
    cin  >> result;
    return result;
}

void print_sequence(sequence& source)
{
    //source.start( );
    sequence output = source;

    output.start( );
    
    while(output.is_item( ) == true)
    {
        cout << output.current( ) << endl;
        output.advance( );
    }
}

void cheat_print(sequence& source)
{
    source.start( );
    
    while(source.is_item( ) == true)
    {
        cout << source.current( ) << endl;
        source.advance( );
    }
    source.start( );
}
