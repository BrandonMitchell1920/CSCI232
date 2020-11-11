/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Algebraic infix expression evaluator using postfix and a stack
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Added a bit of code for reading in the infix string and also 
 *              to get the values of the variables from the user.
 */ 
 
#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>

#include "Postfix.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

/* 
 * Obtain an infix algebraic expression from standard 
 * input, verify the expression is a valid expression, 
 * convert to a postfix expression, obtain values from 
 * the standard input for any variables present in the
 * expression, evaluate the postfix expression and 
 * send to standard output the
 * - Infix expression
 * - Postfix expression
 * - the result of the evaluation
 */
int main()
{    
    string infix = ""; // hold the infix expression from stdin
    std::unordered_map<unsigned char, double> values; 
    auto isChar = [](unsigned char ch)
        {
            return (ch >= 'a' && ch <= 'z');
        };

    // obtain the candidate infix expression from the stdin
    cout << "Please give infix expression: ";
    std::getline(cin, infix);
    
    // create an instance of Postfix class, passing in the
    // string with the candidate infix expression 
    // throw an exception if the expression is not valid
    Postfix pfix(infix);
    
    // output the infix expression
    cout << "Infix: " << pfix.getInfix() << endl;

    // output the postfix expression
    cout << "Postfix: " << pfix.getPostfix() << endl;

    // cycle through (unique) variables in postfix
    // expression and get values for each from the 
    // stdin and store in the variables int array
    bool varMessage = true;
    for (unsigned char ch : infix)
    {
        // Is a valid character and is currently not in values list
        if (isChar(ch) && values.find(ch) == values.end())
        {
            // So the message only displays once and not at all if it doesn't
            // need to
            if (varMessage)
            {
                std::cout << "Please provide values for all variables included "
                    "in the above expression.\n";
                varMessage = false;
            }
            
            double val;
            std::cout << ch << ": ";
            std::cin >> val;
            
            values.insert({ch, val});
        }
    }            

    // evaluate the postfix expression
    (void) pfix.eval(values);

    // output the result of evaluation
    cout << "Result: " << pfix.getResult() << endl;
    
    // signal success to our caller
    return EXIT_SUCCESS;
} // end main()
