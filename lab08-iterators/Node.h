/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - Iterators
 * 
 * Node Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef NODE_H
#define NODE_H

#include <memory>

using std::shared_ptr;

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   shared_ptr<Node<ItemType> > next; // Pointer to next node
   
   template<class friendItemType>
   friend class LinkedListwIterator;
   
public:
   // Constructors
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, shared_ptr<Node<ItemType> > nextNodePtr);

   // Accessors
   ItemType getItem() const ;
   shared_ptr<Node<ItemType> > getNext() const ;

   // Mutators
   void setItem(const ItemType& anItem);
   void setNext(shared_ptr<Node<ItemType> > nextNodePtr);
}; // end Node

#include "Node.cpp"
#endif
