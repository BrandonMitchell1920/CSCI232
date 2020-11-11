/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * LinkedIterator Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LinkedIterator_IMP
#define LinkedIterator_IMP

#include <iostream>
#include <memory>
#include <iterator>

#include "LinkedIterator.h"

using std::shared_ptr;

// Constructor taking a pointer to a LinkedListwIterator and a pointer to an element in the list
template <class ItemType>
LinkedIterator<ItemType>::
LinkedIterator(shared_ptr<LinkedListwIterator<ItemType> > someList, 
               shared_ptr<Node<ItemType> > nodePtr):
               containerPtr(someList), currentItemPtr(nodePtr)
{
}  // end constructor

// Dereference operator to return the item to which the iterator 
// is currently pointing within the LinkesListwIterator class
template <class ItemType>
const ItemType LinkedIterator<ItemType>::operator*()
{
   return currentItemPtr->getItem();
}  // end operator*

// increment the currentItem pointer to point to the next item in the 
// LinkedListwIterator list and return the iterator object
template <class ItemType>
LinkedIterator<ItemType> LinkedIterator<ItemType>::operator++()
{
   currentItemPtr = currentItemPtr->getNext();
   return *this;
}  // end prefix operator++

// return a boolean if the rightHandSide iterator is the same as this iterator
// same list and same element in the list determine equality
template <class ItemType>
bool LinkedIterator<ItemType>::operator==(const
                                          LinkedIterator<ItemType>& rightHandSide) const
{
   return ((containerPtr == rightHandSide.containerPtr) &&
           (currentItemPtr == rightHandSide.currentItemPtr));
}  // end operator==

// return a boolean if the rightHandSide iterator is the same as this iterator
// same list and same element in the list determine inequality
template <class ItemType>
bool LinkedIterator<ItemType>::operator!=(const
                                          LinkedIterator<ItemType>& rightHandSide) const
{
   return ((containerPtr != rightHandSide.containerPtr) ||
           (currentItemPtr != rightHandSide.currentItemPtr));
}  // end operator!=
#endif
