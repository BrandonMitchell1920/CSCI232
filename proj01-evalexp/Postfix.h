/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Postfix Class Definition
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Implemented required functions and added a couple of helper 
 *              functions like isChar() and isNum() to help with parsing.  
 *              Also, I changed eval to take a map as that was easier to work
 *              with than a primitive array.
 */
 
#include <string>           // For storing infix, postfix
#include <unordered_map>    // For storing vals and operator precedence
#include <set>              // For storing ops, valid chars
#include <algorithm>        // For stuff like count
#include <cmath>            // For std::pow

// use linked list stack ADT
#include "LinkedStack.h"

using std::string;

class Postfix
{
    private:
        string infix; // the infix expression from use
        string postfix; // the postfix expression calculated
        double result; // result of calculating postfix expression
        
        // convert the infix representation of an algebraic expression
        // to a postfix representation and store in instance variable
        void postfixFromInfix(); 

        // verify the infix expression is valid
        bool isInfixP() const;
        
        // Couple of helper functions
        bool isChar(const unsigned char ch) const;
        bool isNum(const unsigned char ch) const;

    public:
        // Constructor
        // provide an infix expression in infix param
        // verify the infix expression is valid 
        // convert the infix to a valid postfix expression
        Postfix(const string infix);

        // evaluate the algebraic postfix expression
        // using the int array pointed to by vars and
        // return the result and store in instance variable
        double eval(const std::unordered_map<unsigned char, double> & values);

        // accessor methods
        string getInfix() const;
        string getPostfix() const;
        double getResult() const;
}; // end postfix 
