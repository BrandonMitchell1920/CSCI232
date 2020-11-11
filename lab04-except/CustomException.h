/*
 * Name:	Brandon Mitchell
 * Description:	Using C++ exception handling, we can create our own exceptions
 *				in order to help catch and respond to undesired circumstances.
 */

// Pragma once does the same, right?
#ifndef CUSTOM_ERROR_
#define CUSTOM_ERROR_
 
// For exceptions and strings
#include <stdexcept>
#include <string>

class TargetNotFoundError : std::logic_error
{
	public:
		
		// Constructor passes message to parent error
		TargetNotFoundError(std::string message = "") : 
			std::logic_error("Target not found: " + message) {}
			
		std::string what() {return std::logic_error::what();}
};

#endif