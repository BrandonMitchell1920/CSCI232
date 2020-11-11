/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Linked List Implementation 
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKED_LIST_IMP
#define LINKED_LIST_IMP

#include <cassert>

#include "LinkedList.h"  // List ADT

using std::string;
using std::make_shared;
using std::shared_ptr;
  
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) : itemCount(aList.itemCount)
{
   auto origChainPtr = aList.headPtr;  // Points to nodes in original chain

   if (origChainPtr == nullptr)
      headPtr.reset();  // Original list is empty
   else
   {
      // Copy first node
      headPtr = make_shared<Node<ItemType> >();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      auto newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item 
         auto newNodePtr = make_shared<Node<ItemType> >(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr); 
         
         // Advance pointer to new last node      
         newChainPtr = newChainPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry 
      auto newNodePtr = make_shared<Node<ItemType> >(newEntry);
      
      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr); 
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         auto prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext()); 
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove)
   {
      if (position == 1)
      {
         // Remove the first node in the chain
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         auto prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         auto curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   headPtr.reset();
   // headPtr = nullptr; // is OK also
   itemCount = 0;
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      auto nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
void LinkedList<ItemType>::replace(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      auto nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      // auto gives const string literal
      string message = "replace() called with an invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end replace

template<class ItemType>
shared_ptr<Node<ItemType> > LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   auto curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt
//  End of implementation file.

// swaps the items in pos i and j of list aList
template<class ItemType>
bool LinkedList<ItemType>::swap(shared_ptr<ListInterface<ItemType>> aList, 
                                unsigned int i, unsigned int j)
{
    // could use a try and catch instead
    bool inRange = (i >= 1) && (i <= (unsigned) aList->getLength()) && 
                   (j >= 1) && (j <= (unsigned) aList->getLength());
                   
	if (inRange)
    {
        // get items and then call replace to swap them
		ItemType itemI = aList->getEntry(i);
		ItemType itemJ = aList->getEntry(j);
        aList->replace(i, itemJ);
        aList->replace(j, itemI);  
    }
	
    return inRange;
}

// walks through list to see if an item is in it
template<class ItemType>
bool LinkedList<ItemType>::contains(const ItemType & entry)
{
    // weak pointer to walk list
	std::weak_ptr<Node<ItemType>> curPtr = headPtr;

	bool found = false;
	
	// while not at end of list and item hasn't been found
	while (curPtr.lock() != nullptr && !found)
	{
		if (curPtr.lock()->getItem() == entry) {found = true;}
		else {curPtr = curPtr.lock()->getNext();}
	}
	
	return found;
}

#endif