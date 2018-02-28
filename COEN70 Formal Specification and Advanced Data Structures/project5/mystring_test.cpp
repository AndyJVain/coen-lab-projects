// FILE: mystring_test.cpp
// An interactive test program for the new sequence class

#include <cassert>      // Provides assert
#include <iostream>     // Provides cout and cin
#include <cstring>      // Provides string functions
#include "mystring.h"   // With value_type defined as double
using namespace coen70_lab5;
using std::cin;
using std::cout;
using std::endl;

int main( )
{
    // Constructor and [ ] test
    string test("Hello");
    cout << test << endl;
    cout << test[1] << " (should be e)" << endl;
    
    
    
    // Copy constructor test
    string copy(test);
    cout << "Test: " << test << endl;
    cout << "Copy: " << copy << endl;
    
    
    
    // += test
    string hello("Hello");
    string a;
    a += hello;
    a += ',';
    a += " World";
    cout << a << " (should be Hello, World)" << endl;
    
    
    
    // = test
    string equal;
    equal = a;
    cout << a << " (should be Hello, World)" << endl;
    
    
    
    
    // Insert test
    a.insert("Goodbye ",7);
    cout << a << " (should be Hello, Goodbye World)" << endl;
    
    
    
    
    // Replace test
    a.replace('S', 0);
    cout << a << " (should be Sello, Goodbye World)" << endl;

    
    
    
    // Search test
    int number_found = a.search('b');
    cout << number_found << " (should be 11)" << endl;
    
    
    
    
    // Count test
    int total = a.count('o');
    cout << total << " (should be 4)" << endl;
    
    
    
    
    // Operator test
    if(test == copy)
    {
        cout << "They are the same (should be this)" << endl;
    }
    
    if(test != copy)
    {
        cout << "You shouldn't see this." << endl;
    }
    
    string s1("ABCDE");
    string s2("FGHIJ");
    
    if(s1 >= s2)
    {
        cout << ">= You shouldn't see this" << endl;
    }
    
    if(s1 <= s2)
    {
        cout << "<= You should see this" << endl;
    }
    
    if(s1 > s2)
    {
        cout << "> You shouldn't see this" << endl;
    }
    
    if(s1 < s2)
    {
        cout << "< You should see this" << endl;
    }
    
    cout << s1 + s2 << endl;
    
    
    
    
    // Istream and getline test
    string in1;
    cin >> in1;
    cout << in1 << endl;
    
    string in2;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, in2, '?');
    cout << in2 << endl;
    
    
}
