/**
 * CSCI 232 Data Structures and Algorithms
 * 
 * Node Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef NODE_IMP
#define NODE_IMP

#include "Node.h"
#include <cstddef>

template<class ItemType>
Node<ItemType>::Node()
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     std::shared_ptr<Node<ItemType> > nextNodePtr)
               : item(anItem), next(nextNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType> > nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

template<class ItemType>
std::shared_ptr<Node<ItemType> > Node<ItemType>::getNext() const
{
   return next;
} // end getNext

#endif

