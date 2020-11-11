/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * Precondition Violation Custom Exception Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include "PrecondViolatedExcep.h"  

using std::logic_error;
using std::string;

PrecondViolatedExcep::PrecondViolatedExcep(const string& message)
         : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

