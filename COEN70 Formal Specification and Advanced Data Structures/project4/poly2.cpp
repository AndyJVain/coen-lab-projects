// FILE: poly2.cpp
// CLASS IMPLEMENTED: poly (see poly.h for documentation)

#include "poly2.h"	// Provides the sequence class definition
#include <cassert>		// Provides assert
#include <iostream>		// Provides cout
#include <climits>      // Provides UINT_MAX
#include <cmath>        // Provides power functions
using namespace std;	// Allows all Standard Library items to be used

namespace coen70_lab4_2
{
    void polynomial::update_current_degree( )
    {
        int i;
        
        // Loops through checking to find the largest non-zero
        for(i = coef_size; i >= 0; i--)
        {
            if(coef[i] != 0)
            {
                current_degree = i;
                break;
            }
        }
    }
    
    void polynomial::reallocateForExponent(unsigned int exponent)
    {
        int i;
        
        // Checks if new space needs to be added or not
        if(exponent >= coef_size)
        {
            double *temp = coef;
            coef_size = exponent + 1;
            coef = new double[coef_size];
            
            // Checks that the creation of the array was successful
            assert(coef != NULL);
            
            // Initialize coef array to 0
            for(i = 0; i < coef_size; i++)
            {
                coef[i] = 0.0;
            }
            
            // Copies the data over before deleting the temp
            if(temp != NULL)
            {
                for(i = 0; i <= current_degree; i++)
                {
                    coef[i] = temp[i];
                }
                delete [] temp;
            }
            current_degree = exponent;
        }
    }
    
    polynomial::polynomial(double c, unsigned int exponent)
    {
        coef_size = 0;
        current_degree = 0;
        coef = NULL;
        reallocateForExponent(exponent);
        coef[exponent] = c;
    }
    
    polynomial::polynomial(const polynomial& other)
    {
        coef_size = 0;
        current_degree = 0;
        coef = NULL;
        *this = other;
    }
    
    polynomial::~polynomial( )
    {
        delete [ ] coef;
    }
    
    void polynomial::assign_coef(double coefficient, unsigned int exponent)
    {
        reallocateForExponent(exponent);
        coef[exponent] = coefficient;
        update_current_degree( );
    }
    
    void polynomial::add_to_coef(double amount, unsigned int exponent)
    {
        reallocateForExponent(exponent);
        double new_amount = coef[exponent] + amount;
        coef[exponent] = new_amount;
        update_current_degree( );
    }
    
    void polynomial::clear( )
    {
        // Initialize coef array to 0
        int i;
        
        for (i = 0; i <= coef_size; i++)
            coef[i] = 0;
        
        update_current_degree( );
    }
    
    polynomial polynomial::antiderivative( ) const
    {
        assert(degree( ) < coef_size);
        
        polynomial result;
        
        // Antiderivative puts a coefficient in a degree 1 higher than
        // max degree
        result.reallocateForExponent(current_degree+1);
        int i;
        
        // Copy the coefficient array to result
        for(i = 0; i <= coef_size; i++)
            result.coef[i] = coef[i];
        
        // Compute the antiderivative
        for(i = current_degree; i >= 0; i--)
        {
            result.coef[i] = result.coef[i] / (i+1);
            result.coef[i+1] = result.coef[i];
        }
        
        // Set the constant term to 0 (because the antiderivative of a constant is 0)
        result.coef[0] = 0;
        
        // Update the current degree
        result.update_current_degree( );
        
        return result;
    }
    
    double polynomial::coefficient(unsigned int exponent) const
    {
        if(exponent > current_degree)
            return 0;
        else
            return coef[exponent];
    }
    
    double polynomial::definite_integral(double x0, double x1) const
    {
        double result;
        polynomial integral;
        integral.reallocateForExponent(current_degree+1);
        integral = this->antiderivative( );
        
        // Evaluates the integral for specific values
        result = integral.eval(x1) - integral.eval(x0);
        return result;
    }
    
    polynomial polynomial::derivative( ) const
    {
        polynomial result;
        result.reallocateForExponent(current_degree);
        int i;
        
        // Copy the coefficient array to result
        for(i = 0; i <= coef_size; i++)
            result.coef[i] = coef[i];
        
        // Set the constant term to 0 (because the derivative of a constant is 0)
        result.coef[0] = 0;
        
        // Compute the derivative
        for(i = 1; i <= current_degree; i++)
        {
            result.coef[i] = result.coef[i] * i;
            result.coef[i-1] = result.coef[i];
        }
        
        // Set the highest degree to 0 (because the highest degree was decreased
        // one degree, so there should not be a value in the previous highest degree)
        result.coef[current_degree] = 0;
        
        // Update the current degree
        result.update_current_degree( );
        
        return result;
    }

    double polynomial::eval(double x) const
    {
        double total = 0;
        int i = current_degree;
        
        // Calculates each polynomial element with a specific value for x
        while(i >= 0)
        {
            total += ((pow(x, i) * coef[i]));
            i--;
        }
        
        return total;
    }
    
    bool polynomial::is_zero( ) const
    {
        // Checks if there is a degree higher than 0
        if(current_degree == 0)
        {
            // Checks if the 0th degree is a constant
            if(coef[0] == 0)
                return true;
            else
                return false;
        }
        else {
            return false;
        }
    }
    
    unsigned int polynomial::next_term(unsigned int e) const
    {
        unsigned int n = 0;
        int i;
        
        // Loops through to find the next non-zero
        for(i = e; i <= current_degree; i++)
        {
            if(coef[i+1] != 0){
                n = i+1;
                return n;
            }
        }
        return n;
    }
    
    unsigned int polynomial::previous_term(unsigned int e) const
    {
        unsigned int n = UINT_MAX;
        int i;
        
        // Loops through to find the previous non-zero
        for(i = e; i >= 0; i--)
        {
            if(coef[i-1] != 0){
                n = i-1;
                return n;
            }
        }
        
        return n;
    }
    
    polynomial operator +(const polynomial& p1, const polynomial& p2)
    {
        polynomial result;
        unsigned int max_degree;
        int i;
        double coefficient;
        
        // Check to see which one has the higher degree
        if(p1.degree( ) >= p2.degree( ))
            max_degree = p1.degree( );
        else
            max_degree = p2.degree( );
        
        result.reallocateForExponent(max_degree);
        
        // Adds both together and puts the new value into result
        for(i = 0; i <= max_degree; i++)
        {
            coefficient = p1.coefficient(i) + p2.coefficient(i);
            result.add_to_coef(coefficient, i);
        }
        
        return result;
    }
    
    polynomial operator -(const polynomial& p1, const polynomial& p2)
    {
        polynomial result;
        unsigned int max_degree;
        int i;
        double coefficient;
        
        // Check to see which one has the higher degree
        if(p1.degree( ) >= p2.degree( ))
            max_degree = p1.degree( );
        else
            max_degree = p2.degree( );
        
        result.reallocateForExponent(max_degree);
        
        // Subtracts both and puts the new value into result
        for(i = 0; i <= max_degree; i++)
        {
            coefficient = p1.coefficient(i) - p2.coefficient(i);
            result.assign_coef(coefficient,i);
        }
        
        return result;
    }
    
    polynomial operator *(const polynomial& p1, const polynomial& p2)
    {
        unsigned int total_degree;
        total_degree = p1.degree( ) + p2.degree( );
        
        polynomial result;
        result.reallocateForExponent(total_degree+1);
        
        double amount;
        int i;
        int j;
    
        // Loops through, multiplying each term and adding it to the correct place
        for(i = 0; i <= p1.degree( ); i++)
        {
            for(j = 0; j <= p2.degree( ); j++)
            {
                amount = (p1.coefficient(i) * p2.coefficient(j));
                result.add_to_coef(amount,(i+j));
            }
        }

        return result;
    }
    
    polynomial& polynomial::operator =(const polynomial& other)
    {
        // Checks for self assignment
        if(this == &other)
            return *this;
        
        // Copies over each value from other
        coef_size = other.coef_size;
        current_degree = other.current_degree;
        reallocateForExponent(other.coef_size);
        copy(other.coef, other.coef + current_degree + 1, coef);
        
        return *this;
    }
    
    std::ostream& operator << (std::ostream& out, const polynomial& p)
    {
        unsigned int degree = p.degree( );
        unsigned int second_to_last_degree = 1;
        int i;
        
        // Finds the second to last degree
        for(i = degree; i > 0; i--)
        {
            if(p.previous_term(i) == 0 && p.coefficient(0) == 0)
            {
                second_to_last_degree = i;
            }
        }
        
        // Prints the special case for the highest degree
        if(degree > 1 && p.coefficient(degree) != 0)
        {
            out << p.coefficient(degree);
            
            // Checks if ^ is needed
            if(degree == 1)
            {
                out << "x";
            }
            else
            {
                out << "x^";
                out << p.degree( );
                out << " ";
            }
        }
        
        // Loops through to print the middle degrees
        if(degree > 1)
        {
            for(i = degree-1; i > 1; i--)
            {
                if(p.coefficient(i) != 0)
                {
                    // If it is negative
                    if(p.coefficient(i) < 0)
                    {
                        if(p.coefficient(degree) != 0)
                        {
                            out << "- ";
                        }
                        out << fabs(p.coefficient(i));
                        out << "x^";
                        out << i;
                        out << " ";
                    }
                    // If it is positive
                    else
                    {
                        if(p.coefficient(degree) != 0)
                        {
                            out << "+ ";
                        }
                        out << p.coefficient(i);
                        out << "x^";
                        out << i;
                        out << " ";
                    }
                }
            }
        }
        
        // Special case for 2nd to last degree
        if(p.coefficient(second_to_last_degree) < 0 && degree >= 1)
        {
            if(degree > 1)
            {
                out << "- ";
                out << fabs(p.coefficient(second_to_last_degree));
                out << "x ";
            }
            else{
                out << p.coefficient(second_to_last_degree);
                out << "x ";
            }
        }
        if(p.coefficient(second_to_last_degree) > 0 && degree >= 1)
        {
            if(degree > 1)
            {
                out << "+ ";
            }
            out << p.coefficient(second_to_last_degree);
            out << "x ";
        }
        
        // 0th degree
        if(p.coefficient(0) != 0)
        {
            // If the 0th degree is the highest degree, need to
            // format the correct placement of +/-
            if(degree == 0)
            {
                if(p.coefficient(0) < 0)
                {
                    out << "-";
                    out << fabs(p.coefficient(0));
                }
                else{
                    out << p.coefficient(0);
                }
            }
            else
            {
                if(p.coefficient(0) < 0)
                {
                    out << "- ";
                    out << fabs(p.coefficient(0));
                }
                else{
                    if(degree != 0)
                    {
                        out << "+ ";
                    }
                    out << p.coefficient(0);
                }
                
            }
        }
        return out;
    }
}
