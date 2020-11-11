/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * Node Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef NODE_IMP
#define NODE_IMP

#include <cstddef>
#include <memory>

#include "Node.h"

using std::shared_ptr;

// Default Constructor
template<class ItemType>
Node<ItemType>::Node()
{
} // end default constructor

// Constructor with an item parameter
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{
} // end constructor

// Constructor with an item and pointer parameter
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     shared_ptr<Node<ItemType> > nextNodePtr)
               : item(anItem), next(nextNodePtr)
{
} // end constructor

// mutator to set the item stored in the node
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

// mutator to set the next pointer in the node
template<class ItemType>
void Node<ItemType>::setNext(shared_ptr<Node<ItemType> > nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

// accessor to return the item stored in the node
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

// accessor to return a pointer to the next node
template<class ItemType>
shared_ptr<Node<ItemType> > Node<ItemType>::getNext() const
{
   return next;
} // end getNext

#endif
