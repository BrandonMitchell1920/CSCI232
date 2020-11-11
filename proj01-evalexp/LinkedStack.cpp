/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Stack ADT - Linked List Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKED_STACK_IMP
#define LINKED_STACK_IMP

// stack ADT linked list definition
#include "LinkedStack.h"

/** default constructor
 * @pre - no precondition
 * @post - a new instance of the LinkedStack class
 */
template<class ItemType>
LinkedStack<ItemType>::LinkedStack()
{
}  // end constructor

/** copy constructor
 * @pre - no precondition
 * @post - a new instance of the LinkedStack class
 * @param aStack - an instance of a LinkedStack
 */
template<class ItemType>
LinkedStack<ItemType>::LinkedStack(const LinkedStack<ItemType>& aStack)
{
   // Point to nodes in original chain
   std::shared_ptr<Node<ItemType> > origChainPtr = aStack.topPtr;
   
   if (origChainPtr == nullptr)
      topPtr = nullptr;  // Original stack is empty
   else
   {
      // Copy first node
      topPtr = std::make_shared<Node<ItemType> >();
      topPtr->setItem(origChainPtr->getItem());
      
      // Point to last node in new chain
      std::shared_ptr<Node<ItemType> > newChainPtr = topPtr;
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      // Copy remaining nodes
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         std::shared_ptr<Node<ItemType> > newNodePtr = std::make_shared<Node<ItemType> >(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
         
      newChainPtr->setNext(nullptr); // Flag end of chain
   }  // end if
}  // end copy constructor

/** destructor
 * @pre - an instance of the LinkedStack class
 * @post - the linked list is freed from memory
 */
template<class ItemType>
LinkedStack<ItemType>::~LinkedStack()
{
   topPtr = nullptr;
}  // end destructor

/** predicate for testing if the stack ADT contains items
 * @pre - an instance of the LinkedStack
 * @post - no post condition
 * @return - true if the stack ADT contains items, false otherwise
 */
template<class ItemType>
bool LinkedStack<ItemType>::isEmpty() const
{
	return topPtr == nullptr;
}  // end isEmpty

/** admit an item to the stack ADT
 * @pre - an instance of the LinkedStack
 * @post - a modified stack ADT
 * @param newEntry - an entry to admit to the stack ADT
 * @return - true if the item is added to the stack ADT, false otherwise
 */
template<class ItemType>
bool LinkedStack<ItemType>::push(const ItemType& newEntry) 
{
   // create a new node with the newEntry and the topPtr
   std::shared_ptr<Node<ItemType> > newNodePtr = std::make_shared<Node<ItemType> >(newEntry, topPtr);	

   // reset the topPtr to point to the new node - on top of stack ADT
   topPtr = newNodePtr;

   // return success to caller
	return true;
}  // end push

/** emit the item at the top of the stack ADT
 * @pre - an instance of the LinkedStack
 * @post - a modified stack ADT
 * @return - true if the item is emitted from the stack ADT, false otherwise
 */
template<class ItemType>
bool LinkedStack<ItemType>::pop()
{
   // determine result of operation
	bool result = false;

   // if the stack ADT is not empty
	if (!isEmpty())
	{
      // node to delete is node at top of the stack ADT
		std::shared_ptr<Node<ItemType> > nodeToDeletePtr = topPtr;

      // set the top of the stack ADT to the next node
		topPtr = topPtr->getNext();
		
		// return to the memory the node pointed to by 
      // the nodeToDeletePtr pointer
      nodeToDeletePtr->setNext(nullptr);
      nodeToDeletePtr = nullptr;
      
      // set the result of the operation
      result = true;
	}  // end if
   
   // return the result of the operation
	return result;	
}  // end pop

/** retrieve the item at the top of the stack ADT
 * @pre - a non-empty instance of the stack ADT
 * @post - no post condition
 * @return - the item at the top of the stack ADT
 * @throws - a PrecondViolationException if the stack ADT is empty
 */
template<class ItemType>	
ItemType LinkedStack<ItemType>::peek() const
{
   // Enforce precondition
   if (isEmpty())
      throw(PrecondViolatedExcep("peek() called with an empty stack."));
   
	// Stack is not empty; return top
	return topPtr->getItem();
}  // end peek

#endif