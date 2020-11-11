/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - MinMaxBinaryHeap
 * 
 * Precondition Violation Custom Exception Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef PRECOND_VIOLATED_EXCEP_H
#define PRECOND_VIOLATED_EXCEP_H

#include <stdexcept>
#include <string>

using std::logic_error;
using std::string;

class PrecondViolatedExcep : public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep 
#endif
