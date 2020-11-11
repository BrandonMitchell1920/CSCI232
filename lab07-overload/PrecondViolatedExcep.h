/**
 * F19 CSCI 232 Data Structures and Algorithms
 * 
 * Pre-Condition Violation Custom Exception Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */


#ifndef PRECOND_VIOLATED_EXCEP_H
#define PRECOND_VIOLATED_EXCEP_H

#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
public:
    PrecondViolatedExcep(const std::string & message = "");
}; // end PrecondViolatedExcep 
#endif
