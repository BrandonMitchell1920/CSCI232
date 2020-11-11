/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * LinkedList with Iterator Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKEDLISTWITERATOR_IMP
#define LINKEDLISTWITERATOR_IMP

#include <cassert>
#include <memory>

#include "LinkedListwIterator.h"

using std::string;
using std::make_shared;
using std::shared_ptr;

// Default Constructor
template<class ItemType>
LinkedListwIterator<ItemType>::LinkedListwIterator() : headPtr(nullptr), 
						       itemCount(0)
{
}  // end default constructor

// Copy constructor - deep copy
template<class ItemType>
LinkedListwIterator<ItemType>::LinkedListwIterator(const LinkedListwIterator<ItemType>& aList) : itemCount(aList.itemCount)
{
   // Points to nodes in the original chain
   shared_ptr<Node<ItemType> > origChainPtr = aList.headPtr;
   
   if (origChainPtr == nullptr)
      // Original list is empty
      headPtr.reset();
   else
   {
      // Copy first node
      headPtr = make_shared<Node<ItemType> >();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      shared_ptr<Node<ItemType> > newChainPtr = headPtr; // Points to last node in new chain
      origChainPtr = origChainPtr->getNext(); // Advance original-chain pointer

      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         shared_ptr<Node<ItemType> > newNodePtr = make_shared<Node<ItemType> >(nextItem);
         
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

// Destructor
template<class ItemType>
LinkedListwIterator<ItemType>::~LinkedListwIterator()
{
   clear();
}  // end destructor

// Predicate to test if the LIST ADT is empty
template<class ItemType>
bool LinkedListwIterator<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

// Return the number of items in the LIST ADT
template<class ItemType>
int LinkedListwIterator<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

// Insert an entry into the LIST ADT at the given position
template<class ItemType>
bool LinkedListwIterator<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      shared_ptr<Node<ItemType> > newNodePtr = make_shared<Node<ItemType> >(newEntry);
      
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
         shared_ptr<Node<ItemType> > prevPtr = getNodeAt(newPosition - 1);
         
         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }  // end if
      
      itemCount++;  // Increase count of entries
   }  // end if
   
   return ableToInsert;
}  // end insert

// Remove the item at the provided position from the LIST ADT
template<class ItemType>
bool LinkedListwIterator<ItemType>::remove(int position)
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
         shared_ptr<Node<ItemType> > prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         shared_ptr<Node<ItemType> > curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

// remove all the items in the LIST ADT
template<class ItemType>
void LinkedListwIterator<ItemType>::clear()
{
   headPtr.reset();
   // headPtr = nullptr; // is OK also
   itemCount = 0;
}  // end clear

// return the item at the node at the given position in the LIST ADT
template<class ItemType>
ItemType LinkedListwIterator<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      shared_ptr<Node<ItemType> > nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end getEntry

// overwrite the item at the given position with the given entry
template<class ItemType>
void LinkedListwIterator<ItemType>::replace(int position, const ItemType& newEntry)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      shared_ptr<Node<ItemType> > nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      // auto gives const string literal
      string message = "replace() called with an invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end replace

// return a pointer to the node in the linked list at the given position of the LIST ADT
template<class ItemType>
shared_ptr<Node<ItemType> > LinkedListwIterator<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   shared_ptr<Node<ItemType> > curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
   
   return curPtr;
}  // end getNodeAt

// begin method required by iterator class
// returns an iterator with its currentItem referencing the first element of the LIST ADT
template <class ItemType>
LinkedIterator<ItemType> LinkedListwIterator<ItemType>::begin()
{
   shared_ptr<LinkedListwIterator<ItemType> > beginPtr = this->shared_from_this();

   return LinkedIterator<ItemType>(beginPtr, headPtr);
} // end begin

// end method required by iterator class
// returns an iterator with its currentItem referencing the last element of the LIST ADT
template <class ItemType>
LinkedIterator<ItemType> LinkedListwIterator<ItemType>::end()
{
   shared_ptr<LinkedListwIterator<ItemType> > endPtr = this->shared_from_this();

   return LinkedIterator<ItemType>(endPtr, nullptr);
} // end end

#endif
