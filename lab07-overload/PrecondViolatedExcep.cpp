/**
 * F19 CSCI 232 Data Structures and Algorithms
 * 
 * Pre-Condition Violation Custom Exception Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include "PrecondViolatedExcep.h"  

PrecondViolatedExcep::PrecondViolatedExcep(const std::string & message)
         : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

