/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Postfix Class Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Implemented the required features.  Can convert infix, evaluate
 *              postifix, and (the most complicated part) parse infix and 
 *              inform the user of what the problem is.  Some checks are also
 *              done in eval to prevent division by zero.
 */

// the postfix class definition
#include "Postfix.h"

// Determine if a char is alphabetical
bool Postfix::isChar(const unsigned char ch) const
{
    return (ch >= 'a' && ch <= 'z');
}

// Determine is a char is numerical
bool Postfix::isNum(const unsigned char ch) const
{
    return (ch >= '0' && ch <= '9');
}
  
/** constructor
 * @pre - a no precondition
 * @post - a new instance of the Postfix class
 * @param infix - an algebraic infix expression
 */
Postfix::Postfix(const string infix) : infix(infix)
{
	if (isInfixP()) {postfixFromInfix();}
} // end constructor

/** verify the expression in the infix instance variable is valid
 * @pre - an infix expression stored in the instance variable
 * @return - true if expression is valid, false otherwise
 */
bool Postfix::isInfixP() const
{
    // Set of valid, non-alphabetical/numerical characters
    std::set<unsigned char> 
        validCh = {'+', '-', '/', '*', '^', '(', ')', ' ', '.'};
        
    // Set of just ops
    std::set<unsigned char> ops = {'+', '-', '/', '*', '^'};
    
    // Make sure all characters in infix string are valid characters
    for (unsigned int index = 0; index < infix.length(); index++)
    {
        // Valid? do nothing
        if (isChar(infix[index])) {}
        else if (isNum(infix[index])) {}
        else if (validCh.find(infix[index]) != validCh.end()) {}
        
        // Not valid, throw error, inform user of invalid char
        else 
        {
            std::string message = "\nInvalid character \"" + 
                std::string(1, infix[index]) + "\" at index " + 
                std::to_string(index) + "\n" + infix + "\n" + 
                std::string(index, ' ') + "^";
            throw PrecondViolatedExcep(message);
        }
    }

    // Check that parentheses are valid and balanced
    LinkedStack<unsigned char> stack;
    for (unsigned int index = 0; index < infix.length(); index++)
    {
        // Push open parentheses onto stack
        if (infix[index] == '(') {stack.push('(');}
        
        // Remove close parentheses
        else if (infix[index] == ')')
        {
            // If stack isn't empty, pop, else display error to user
            if (!stack.isEmpty())
            {
                stack.pop();
            }
            else
            {
                std::string message = "\nClose parentheses has no matching "
                    "open parentheses at index " + std::to_string(index) +
                    "\n" + infix + "\n" + std::string(index, ' ') + "^";
                throw PrecondViolatedExcep(message);
            }
        }
    }
    
    // If the stack isn't empty, then an open parentheses is still on it
    if (!stack.isEmpty())
    {
        std::string message = "\nMissing one or more close parentheses\n" 
            + infix;
        throw PrecondViolatedExcep(message);
    }

    // For verifiying overall structure of infix
    unsigned int right;
    signed int left;
    bool validR, validL;
    unsigned int numOps = 0, numVars = 0;
    
    // An absolute beast of a loop.  Verify the structure of the infix by 
    // checking each operator, variable, and literal.  Probably some repeated 
    // code that could be condensed, but it is mainly that there is just a lot
    // to check inorder to verify it.
    for (unsigned int index = 0; index < infix.length(); index++)
    {
        // Set all values before conditionals
        left = right = index;
        validL = validR = false;
        
        // For each operator ...
        if (ops.find(infix[index]) != ops.end())
        {
            // Determine if minus sign is a negative or operator
            if (infix[index] == '-')
            {
				// Has a number to right, to be a negative number, it must be
				// a part of the num and not floating five spaces away
                if ((index + 1 < infix.length() && isNum(infix[index + 1])) || 
                    (index + 2 < infix.length() && infix[index + 1] == '.' && 
                    isNum(infix[index + 2])))
                {
					// A lot of this code is repeated elsewhere, but certain
					// things are changed depending on what exactly is okay
					// in that instance, so I can't really slap it in a
					// function
                    signed int tempLeft = left;
                    bool negCheck = true, isNeg = false;
                    while (negCheck)
                    {
                        // Hit another op, is negative
                        if (--tempLeft < 0 || ops.find(infix[tempLeft]) != 
                            ops.end())
                        {
                            isNeg = true;
                            negCheck = false;
                        }
                        
                        // Hit another num/char, neg not part of this num
                        else if (isChar(infix[tempLeft]) || 
                            isNum(infix[tempLeft]))
                        {
                            negCheck = false;
                        }
                    }
                    
                    // If it is negative, I don't need to check the stuff
                    // below as it isn't an operator
                    if (isNeg) {continue;}
                }
            }
            
            numOps++;
    
            // Check that the right side has a valid operand
            while (!validR)
            {
                // Invalid if out of bounds
                if (++right >= infix.length())
                {
                    std::string message = "\nOperator \"" + 
                        std::string(1, infix[index]) + "\" at index " + 
                        std::to_string(index) + " has no matching right "
                        "operand\n" + infix + "\n" + 
                        std::string(index, ' ') + "^";
                    throw PrecondViolatedExcep(message);
                }
				
                // Assume infix is valid if another operand is hit, note I
				// don't check if the num is a decimal or not here as I 
				// ignore decimals and already have check negatives above
				// Assume valid in parentheses, will be checked later
                else if (isChar(infix[right]) || isNum(infix[right]) || 
					infix[right] == '(')
                {
                    validR = true;
                }
                
                else if (ops.find(infix[right]) != ops.end())
                {
                    bool error = true;
                    if (infix[right] == '-')
                    {
                        // Is a negative, is fine
                        unsigned int len = infix.length();
                        if ((right + 1 < len && isNum(infix[right + 1])) || 
                            (right + 2 < len && infix[right + 1] == '.' && 
                            isNum(infix[right + 2])))
                        {
                            error = false;
                        }
                    }
                    
                    if (error)
                    {
                        std::string message = "\nOperator \"" + 
                            std::string(1, infix[index]) + "\" at index " + 
                            std::to_string(index) + " has no matching right "
                            "operand\n" + infix + "\n" + 
                            std::string(index, ' ') + "^";
                        throw PrecondViolatedExcep(message);
                    }
                }
                
                // If a close parentheses is ecountered
                else if (infix[right] == ')')
                {
                    std::string message = "\nInvalid close parentheses at "
                        "index " + std::to_string(right) + ", make sure no "
                        "operands are missing\n" + infix + "\n" + 
                        std::string(right, ' ') + "^";
                    throw PrecondViolatedExcep(message);                    
                }
            }
            
            // Check left side, note, don't need to check for negative as
            // negative can't be on right side of a number or varible
            while (!validL)
            {               
                // Invalid if out of bounds, another operator is ecountered
                // Note the second part of conditional will never trigger as it
                // involves hitting an op on the left side, but the op on the 
                // left side would have already triggered an exception when its
                // right side was being checked
                if (--left < 0 || ops.find(infix[left]) != ops.end())
                {                    
                    std::string message = "\nOperator \"" + 
                        std::string(1, infix[index]) + "\" at index " + 
                        std::to_string(index) + " has no matching left "
                        "operand\n" + infix + "\n" + 
                        std::string(index, ' ') + "^";
                    throw PrecondViolatedExcep(message);
                }
                
				// Assume infix is valid if another operand is hit
                else if (isChar(infix[left]) || isNum(infix[left]) || 
					infix[left] == ')')
                {
                    validL = true;
                }
				
                // If an open parentheses is encoutered
                else if (infix[left] == '(')
                {
                    std::string message = "\nInvalid open parentheses at "
                        "index " + std::to_string(left) + ", make sure no "
                        "operands are missing\n" + infix + "\n" + 
                        std::string(left, ' ') + "^";
                    throw PrecondViolatedExcep(message);                 
                }
            }
        }
       
        // Check each char
        else if (isChar(infix[index]))
        {
            numVars++;
            
            // Assume not valid until proven as such
            while (!validR)
            {
                // Last char in string, hit a op
                if (++right >= infix.length() || ops.find(infix[right]) != 
                    ops.end() || infix[right] == ')')
                {
                    validR = true;
                }
                
                // Operands (variables) can only be single chars
                else if (isChar(infix[right]))
                {
                    std::string message = "\nInvalid operand (variable) at " +
                        std::to_string(index) + ", only single char [a - z] "
                        "variables are supported\n" + infix + "\n" + 
                        std::string(index, ' ') + "^";
                    throw PrecondViolatedExcep(message);
                }
                
                // Hit a numberal literal, assume missing operator
                else if (isNum(infix[right]))
                {
                    std::string message = "\nInvalid operand (variable) at " +
                        std::to_string(index) + ", make sure no operators are "
                        "missing\n" + infix + "\n" + std::string(index, ' ') + 
                        "^";
                    throw PrecondViolatedExcep(message);
                }
                
                // Hit an open parentheses
                else if (infix[right] == '(')
                {
                    std::string message = "\nInvalid open parentheses at " +
                        std::to_string(right) + ", make sure no operators are "
                        "missing\n" + infix + "\n" + std::string(right, ' ') + 
                        "^";
                    throw PrecondViolatedExcep(message);                    
                }
            }
            
            while (!validL)
            {
                // Last char in string, hit a op
                if (--left < 0 || ops.find(infix[left]) != ops.end() || 
					infix[left] == '(')
                {
                    validL = true;
                }
                
                // Operands (variables) can only be single chars, this will 
                // never trigger as if a variable is 'aa', the first 'a' would
                // trigger an exception above
                else if (isChar(infix[left]))
                {
                    std::string message = "\nInvalid operand (variable) at " +
                        std::to_string(index) + ", only single char [a - z] "
                        "variables are supported\n" + infix + "\n" + 
                        std::string(index, ' ') + "^";
                    throw PrecondViolatedExcep(message);
                }
                
                // Hit a numeral literal, don't need to check as numerals are
				// checked
                else if (isNum(infix[left]))
                {
                    std::string message = "\nInvalid operand (variable) at " +
                        std::to_string(index) + ", make sure no operators are "
                        "missing\n" + infix + "\n" + std::string(index, ' ') +
                        "^";
                    throw PrecondViolatedExcep(message);
                }
                
                // Hit a close parentheses
                else if (infix[left] == ')')
                {
                    std::string message = "\nInvalid close parentheses at " +
                        std::to_string(left) + ", make sure no operators are "
                        "missing\n" + infix + "\n" + std::string(left, ' ') + 
                        "^";
                    throw PrecondViolatedExcep(message);                    
                }
            }
        }
        
        // Check each integer or decimal literal
        else if (isNum(infix[index]))
        {
            numVars++;
            
            do 
            {
                index++;
            } 
            while (isNum(infix[index]) || infix[index] == '.');            
            
			// For .3, etc., decimals that don't start with integer
			if (left && infix[left - 1] == '.') {left--;}
            if (left && infix[left - 1] == '-') 
            {
                signed int tempLeft = left - 1;
                bool negCheck = true;
                while (negCheck)
                {
                    // Another op, must be a negative num
                    if (--tempLeft < 0 || ops.find(infix[tempLeft]) != 
                        ops.end())
                    {
                        left--;
                        negCheck = false;
                    }
                    
                    // Hit another num/char, neg not part of this num
                    else if (isChar(infix[tempLeft]) || isNum(infix[tempLeft]))
                    {
                        negCheck = false;
                    }
                }
            }
			
            std::string num = infix.substr(left, index-- - left);
            right = index;
            
            if (count(num.begin(), num.end(), '.') > 1)
            {
                std::string message = "\nInvalid variable (decimal literal) "
                    "at index " + std::to_string(left) + ", remove extra "
                    "decimal point(s)\n" + infix + "\n" + 
                    std::string(left, ' ') + "^";
                throw PrecondViolatedExcep(message);
            }
            
            while (!validR)
            {
                // Last char in string, hit a op
                if (++right >= infix.length() || ops.find(infix[right]) != 
                    ops.end() || infix[right] == ')')
                {
                    validR = true;
                }
                
                // Hit another num that isn't part of this num
                else if (isNum(infix[right]) || infix[right] == '.')
                {
                    std::string message = "\nInvalid operand (numeral literal) "
                        "at " + std::to_string(right) + ", make sure no "
                        "operators are missing\n" + infix + "\n" + 
                        std::string(right, ' ') + "^";
                    throw PrecondViolatedExcep(message);
                }
                
                // Hit an open parentheses
                else if (infix[right] == '(')
                {
                    std::string message = "\nInvalid open parentheses at " +
                        std::to_string(right) + ", make sure no operators are "
                        "missing\n" + infix + "\n" + std::string(right, ' ') + 
                        "^";
                    throw PrecondViolatedExcep(message);                    
                }
            }
            
            while (!validL)
            {
                // Last char in string, hit a op
                if (--left < 0 || ops.find(infix[left]) != ops.end() || 
                    infix[left] == '(')
                {
                    validL = true;
                }
                
                // Hit another num not part of this num, won't happen as an
                // exception above will trigger before this one can
                else if (isNum(infix[left]) || infix[left] == '.')
                {
                    std::string message = "\nInvalid operand (numeral literal) "
                        "at " + std::to_string(left) + ", make sure no "
                        "operators are missing\n" + infix + "\n" + 
                        std::string(left, ' ') + "^";
                    throw PrecondViolatedExcep(message);
                }
                
                // Hit a close parentheses
                else if (infix[left] == ')')
                {
                    std::string message = "\nInvalid close parentheses at " +
                        std::to_string(left) + ", make sure no operators are "
                        "missing\n" + infix + "\n" + std::string(left, ' ') + 
                        "^";
                    throw PrecondViolatedExcep(message);                    
                }
            }
        }
        
        // A final check for misplaced decimal points.  They are allowed, but
        // can only be part of a number
        else if (infix[index] == '.')
        {
            // Is part of a num, do nothing, will always have a num on left,
            // but not right
            if (index + 1 < infix.length() && isNum(infix[index + 1])) {}
            
            // Not part of a num, freak out
            else
            {
                std::string message = "\nStray decimal point at index " + 
                    std::to_string(index) + ", remove unnecessary demicals\n" +
                    infix + "\n" + std::string(index, ' ') + "^";
                throw PrecondViolatedExcep(message);   
            }
        }
    }
    
    // A sort of catch for certain things that could be hard to check for above
    // All ops must be sandwiched between two operands, so there should be one
    // less op than operands
    if (numOps + 1 != numVars)
    {
        std::string message = "\nInvalid number of operators compared to "
            "operands, \"" + std::to_string(numOps) + "\" compared to \"" +
            std::to_string(numVars) + "\", \nshould be one less operators "
            "compared to operands, make sure all operators are balanced\n" + 
            infix;
        throw PrecondViolatedExcep(message);
    }

    // Just return true because it can't return false as it will error if 
    // something is wrong
    return true;
}

/** convert the infix representation of the algebraic
 * expression to a postfix representation
 * @pre - an instance of the Postfix class
 * @post - the postfix instance variable is set
 */
void Postfix::postfixFromInfix()
{
    // Stack to store operators
    LinkedStack<unsigned char> stack;
    
    // Determine that someting is an operator and its precendence
    std::unordered_map<unsigned char, unsigned char> 
        ops = {{'+', 0}, {'-', 0}, {'/', 1}, {'*', 1}, {'^', 2}};
    
    // I put spaces inbetween operands and operators, there will be an extra 
    // space at the end, but this doesn't affect evaluation
    for (unsigned int index = 0; index < infix.length(); index++)
    {
        // Put char into postfix string
        if (isChar(infix[index])) {postfix += infix[index]; postfix += ' ';}
        
        // Push open parentheses onto stack
        else if (infix[index] == '(') {stack.push(infix[index]);}
        
        // Remove ops and parentheses, shouldn't error as we checked for 
        // balanced above
        else if (infix[index] == ')') 
        {
            unsigned char tempCh;
            while (!stack.isEmpty() && (tempCh = stack.peek()) != '(')
            {
                postfix += tempCh;
                postfix += ' ';
                stack.pop();
            }
            stack.pop();
        }
        
        // Hit an operator
        else if (ops.find(infix[index]) != ops.end()) 
        {
            // Need to check if it is a negative number inorder to properly 
            // slice the num
            if (infix[index] == '-')
            {
                if ((index + 1 < infix.length() && isNum(infix[index + 1])) || 
                    (index + 2 < infix.length() && infix[index + 1] == '.' && 
                    isNum(infix[index + 2])))
                {
                    signed int tempIndex = index;
                    bool negCheck = true, isNeg = false;
                    while (negCheck)
                    {
                        // Hit another op, is negative
                        if (--tempIndex < 0 || ops.find(infix[tempIndex]) != 
                            ops.end())
                        {
                            isNeg = true;
                            negCheck = false;
                        }
                        
                        // Hit another num/char, neg not part of this num
                        else if (isChar(infix[tempIndex]) || 
                            isNum(infix[tempIndex]))
                        {
                            negCheck = false;
                        }
                    }
                    
                    // If it is negative, I don't need to do the stuff below
                    if (isNeg) {continue;}
                }
            }
            
            unsigned char tempCh;
            
            // Slap ops on until we hit the open parentheses or an op of lower
            // precendence
            while (!stack.isEmpty() && (tempCh = stack.peek()) && 
                tempCh != '(' && ops[tempCh] >= ops[infix[index]])
            {
                postfix += tempCh;
                postfix += ' ';
                stack.pop();
            }
            stack.push(infix[index]);
        }
        
        // Hit a numeral literal
        else if (isNum(infix[index]))
        {
            bool isNeg = false;
            
            unsigned int start = index;
            do 
            {
                index++;
            } 
            while (isNum(infix[index]) || infix[index] == '.');
			
			// For .3, decimals that don't start with integer
			if (start && infix[start - 1] == '.') {start--;}
            if (start && infix[start - 1] == '-') 
            {
                signed int tempLeft = start - 1;
                bool negCheck = true;
                while (negCheck)
                {
                    // Another op, must be a negative num
                    if (--tempLeft < 0 || ops.find(infix[tempLeft]) != 
                        ops.end())
                    { 
                        isNeg = true;
                        negCheck = false;
                    }
                    
                    // Hit another num/char, neg not part of this num
                    else if (isChar(infix[tempLeft]) || isNum(infix[tempLeft]))
                    {
                        negCheck = false;
                    }
                }
            }
			
			// If there is something like .3, we need to add a zero or 
			// std::stod will not convert properly, or at least it messed up
            // with 3 - .4 and gave me -1, also it makes it look nice
            
            // Also, I do this formatting as it makes evaluating easier, 
            // espcially with negative numbers
            std::string num = infix.substr(start, index-- - start) + ' ';
			if (num[0] == '.') {num = "0" + num;}
            if (isNeg) {num = "-" + num;}
			postfix += num;
        }
    }
    
    // Remove all leftover ops
    while (!stack.isEmpty())
    {
        postfix += stack.peek();
        postfix += ' ';
        stack.pop();
    }
} // end postfixFromInfix

/** evaluate the postfix algebraic expression
 * @pre - an instance of the Postfix class
 * @post - no post condition
 * @param vars - reference to int array holding variable values
 * @return - the value of evaluating the expression
 */
double Postfix::eval(const std::unordered_map<unsigned char, double> & values)
{
    LinkedStack<double> stack;
    
    // Set of valid operators
    std::set<unsigned char> ops = {'+', '-', '/', '*', '^'};
        
    for (unsigned int index = 0; index < postfix.length(); index++)
    {
        // Push value of variable onto stack
        if (isChar(postfix[index])) {stack.push(values.at(postfix[index]));}
        
        // If it is a numeral literal, find end of num and convert to a double
        else if (isNum(postfix[index]))
        {
            unsigned int start = index;
            do
            {
                index++;
            }
            while (isNum(postfix[index]) || postfix[index] == '.');
			
			// Note I don't need a bunch of checks for negative as I already 
            // formatted everything with a space between it so I know it isn't 
            // an op
            if (start && postfix[start - 1] == '-') {start--;}
			
            stack.push(std::stod(postfix.substr(start, index-- - start)));
        }
        
        // Hit an operator
        else if (ops.find(postfix[index]) != ops.end())
        {         
            // Not a op, a negative
            if (postfix[index] == '-' && index + 1 < postfix.length() && 
                isNum(postfix[index + 1]))
            {
                continue;
            }
            
            // Get operands to use, pop stuff off of stack
            double second = stack.peek(); stack.pop();
            double first = stack.peek(); stack.pop();
            
            switch (postfix[index])
            {
                case '+': stack.push(first + second); break;
                case '-': stack.push(first - second); break;
                case '/': 
                    // In case the user tries to pull a fast one on me!
                    if (second != 0) {stack.push(first / second); break;}
                    else 
                    {
                        std::string message = "\nAttempted to divide by zero\n" 
                            + postfix;
                        throw std::logic_error(message);
                    }
                case '*': stack.push(first * second); break;
                case '^': stack.push(std::pow(first, second)); break;
            }
        }
    }

  return (result = stack.peek());
} // end eval

/** access the algebraic infix expression
 * @pre - an instance of the Postfix class
 * @post - no post condition
 * @return - a string representing the algebraic infix expression
 */
string Postfix::getInfix() const
{
  return infix;
} // end getInfix

/** access the algebraic postfix expression
 * @pre - an instance of the Postfix class
 * @post - no post condition
 * @return - a string representing the algebraic postfix expression
 */
string Postfix::getPostfix() const
{
  return postfix;
} //end getPostfix

/** access the result of evaluating the Postfix expressoin
 * @pre - an instance of the Postfix class
 * @post - no post condition
 * @return - a douple representing the result of postfix evaluation
 */
double Postfix::getResult() const
{
  return result;
} // end getResult
