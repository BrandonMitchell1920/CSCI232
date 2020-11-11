/**
 * CSCI 232 Data Structures and Algorithms
 * 
 * Linked List Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKEDLIST_IMP
#define LINKEDLIST_IMP

#include <cassert>
#include <iostream>
#include <memory>

#include "LinkedList.h"

//********************************************************************************
// Overloaded Operators

template <class ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList<ItemType>& rightHandSide) const
{
   bool isEqual = true; // Assume equal
   
   // First check number of items is the same
   if (itemCount != rightHandSide.getLength())
      isEqual = false;
   else
   {  // Then compare items
      auto leftSidePtr = headPtr;
      auto rightSidePtr = rightHandSide.headPtr;
      
      while ((leftSidePtr != nullptr) && (rightSidePtr != nullptr) && isEqual)
      {
         ItemType leftItem = leftSidePtr->getItem();
         ItemType rightItem = rightSidePtr->getItem();
         isEqual = (leftItem == rightItem);
         
         leftSidePtr = leftSidePtr->getNext();
         rightSidePtr = rightSidePtr->getNext();
      }  // end whiile
   }  // end if
   
   return isEqual;
}  // end operator==

template <class ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList<ItemType>& rightHandSide)
{
   // Check for assignment to self
   if (this != &rightHandSide)
   {
      this->clear();                                  // Deallocate left-hand side
      headPtr = copyListNodes(rightHandSide.headPtr); // Copy nodes in right-hand side
      itemCount = rightHandSide.itemCount;            // Copy size of list
   }  // end if
   
   return *this;
} // end operator=

template <class ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList<ItemType>& rightHandSide) const
{
   LinkedList<ItemType> concatList;
   
   auto leftChainPtr = copyThisList();
   concatList.headPtr = leftChainPtr;
   auto rightChainPtr = copyListNodes(rightHandSide.headPtr);
   
   concatList.itemCount = itemCount;
   auto leftChainTailPtr = concatList.getNodeAt(itemCount);
   leftChainTailPtr->setNext(rightChainPtr);
   concatList.itemCount += rightHandSide.itemCount;
   
   return concatList;
}  // end operator+

template<class friendItemType>
std::ostream& operator<<(std::ostream& outStream, const LinkedList<friendItemType>& outputList)
{
   int position = 1;
   auto currPtr = outputList.headPtr;
   while (currPtr != nullptr)
   {
      outStream << position << "\t" << currPtr->getItem() << std::endl;
      currPtr = currPtr->getNext();
      position++;
   }
   return outStream;
} // end operator<<

//**********************************************************************
// Private methods for copying List for Overloaded Operators
// PRIVATE:
template <class ItemType>
std::shared_ptr<Node<ItemType> > LinkedList<ItemType>::copyThisList() const
{
   auto newChainPtr = std::make_shared<Node<ItemType> >();
   auto origChainPtr = headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      newChainPtr = nullptr;  // Original list is empty
   else
   {
      ItemType nextItem = origChainPtr->getItem();
      
      // Create first node in chain
      auto newNodePtr = std::make_shared<Node<ItemType> >(nextItem);
      
      newChainPtr = newNodePtr; // First node in new chain
      auto tailPtr = newNodePtr;     // Points to last node in new chain
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         newNodePtr.reset(new Node<ItemType>(nextItem));
         
         // Link new node to end of new chain
         tailPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         tailPtr = tailPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      tailPtr->setNext(nullptr);           // Flag end of chain
   }  // end if
   
   return newChainPtr;
}  // end copyThisList

template<class ItemType>
std::shared_ptr<Node<ItemType> > LinkedList<ItemType>::copyListNodes(std::shared_ptr<Node<ItemType> > origChainPtr) const
{
   std::shared_ptr<Node<ItemType> > newChainPtr;
   //Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      newChainPtr = nullptr;                      // Original list is empty
   else
   {
      ItemType nextItem = origChainPtr->getItem();
      
      // Create first node in chain
      auto newNodePtr = std::make_shared<Node<ItemType> >(nextItem);
      
      newChainPtr = newNodePtr;                  // First node in new chain
      auto tailPtr = newNodePtr;      // Points to last node in new chain
      
      // Advance original-chain pointer
      origChainPtr = origChainPtr->getNext();
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         nextItem = origChainPtr->getItem();
         
         // Create a new node containing the next item
         newNodePtr.reset(new Node<ItemType>(nextItem));
         
         // Link new node to end of new chain
         tailPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         tailPtr = tailPtr->getNext();
         
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      tailPtr->setNext(nullptr);                 // Flag end of chain
   }  // end if
   
   return newChainPtr;
}  // end copyListNodes


//**********************************************************************
//**********************************************************************

// List methods from previous chapters
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
   headPtr = copyListNodes(aList.headPtr);
   itemCount = aList.itemCount;
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
      auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);
      
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
         std::shared_ptr<Node<ItemType> > prevPtr = getNodeAt(newPosition - 1);
         
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
      std::shared_ptr<Node<ItemType> > curPtr;
      if (position == 1)
      {
         // Remove the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         auto prevPtr = getNodeAt(position - 1);
         
         // Point to node to delete
         curPtr = prevPtr->getNext();
         
         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if
      
      // Return node to system
      curPtr->setNext(nullptr);
      
      itemCount--;  // Decrease count of entries
   }  // end if
   
   return ableToRemove;
}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      std::shared_ptr<Node<ItemType> > nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      std::string message = "getEntry() called with an empty list or ";
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
      std::shared_ptr<Node<ItemType> > nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      std::string message = "replace() called with an invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end replace

template<class ItemType>
std::shared_ptr<Node<ItemType> > LinkedList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );
   
   // Count from the beginning of the chain
   std::shared_ptr<Node<ItemType> > curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();
      
   return curPtr;
}  // end getNodeAt

#endif
