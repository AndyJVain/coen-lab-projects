// FILE: poly1.cpp
// CLASS IMPLEMENTED: poly (see poly.h for documentation)

#include "poly1.h"	// Provides the sequence class definition
#include <cassert>		// Provides assert
#include <iostream>		// Provides cout
#include <climits>      // Provides UINT_MAX
#include <cmath>        // Provides power functions
using namespace std;	// Allows all Standard Library items to be used

namespace coen70_lab4
{
    void polynomial::update_current_degree( )
    {
        int i;
        int max_degree = 0;
        
        // Loops through checking to find the largest non-zero
        for(i = 0; i <= MAXIMUM_DEGREE; i++)
        {
            if(coef[i] != 0)
                max_degree = i;
        }
        current_degree = max_degree;
    }
    
    polynomial::polynomial(double c, unsigned int exponent)
    {
        assert(exponent <= MAXIMUM_DEGREE);
        
        // Initialize coefficient array to 0
        int i;
        
        for (i = 0; i <= MAXIMUM_DEGREE; i++)
            coef[i] = 0;
        
        // Set the specified exponent and update current_degree
        coef[exponent] = c;
        current_degree = exponent;
    }
    
    void polynomial::assign_coef(double coefficient, unsigned int exponent)
    {
        assert(exponent <= MAXIMUM_DEGREE);
        
        coef[exponent] = coefficient;
        update_current_degree( );
    }
    
    void polynomial::add_to_coef(double amount, unsigned int exponent)
    {
        assert(exponent <= MAXIMUM_DEGREE);
     
        double new_amount = coef[exponent] + amount;
        coef[exponent] = new_amount;
        update_current_degree( );
    }
    
    void polynomial::clear( )
    {
        // Initialize coefficient array to 0
        int i;
        
        for (i = 0; i <= MAXIMUM_DEGREE; i++)
            coef[i] = 0;
        
        update_current_degree( );
    }
    
    polynomial polynomial::antiderivative( ) const
    {
        assert(degree( ) < MAXIMUM_DEGREE);
        
        polynomial result;
        int i;
        
        // Copy the coefficient array to result
        for(i = 0; i <= MAXIMUM_DEGREE; i++)
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
        if(exponent > MAXIMUM_DEGREE)
            return 0;
        else
            return coef[exponent];
    }
    
    double polynomial::definite_integral(double x0, double x1) const
    {
        double result;
        polynomial integral;
        integral = this->antiderivative( );
        
        // Evaluates the integral for specific values
        result = integral.eval(x1) - integral.eval(x0);
        return result;
    }
    
    polynomial polynomial::derivative( ) const
    {
        polynomial result;
        int i;
        
        // Copy the coefficient array to result
        for(i = 0; i <= MAXIMUM_DEGREE; i++)
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
        if(current_degree == 0)
        {
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
        
        // Adds both together and puts the new value into result
        for(i = 0; i <= max_degree; i++)
        {
            coefficient = p1.coefficient(i) + p2.coefficient(i);
            result.assign_coef(coefficient,i);
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
        assert(p1.degree( ) + p2.degree( ) <= polynomial::MAXIMUM_DEGREE);
        
        polynomial result;
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
