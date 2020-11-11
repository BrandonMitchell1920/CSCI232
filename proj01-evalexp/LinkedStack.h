/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Stack ADT - Linked List Definition
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <memory>

// Stack ADT Interface - Public Behaviors
#include "StackInterface.h"

// Node ADT Definition
#include "Node.h"

// Custom Exception Class for Violating Preconditions
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedStack : public StackInterface<ItemType>
{
private:
	// pointer to the first node in the list
	// first node is the top of the stack 
	std::shared_ptr<Node<ItemType> > topPtr;

public:
	// constructors
	LinkedStack();
	LinkedStack(const LinkedStack<ItemType>& aStack);

	// destructor
	virtual ~LinkedStack();
	
	// stack core operations
	bool isEmpty() const;
	bool push(const ItemType& newItem);
	bool pop();

	// throws a precondition violation if stack ADT is empty
	ItemType peek() const;
}; // end LinkedStack

// template class requires implementation
#include "LinkedStack.cpp"

#endif
