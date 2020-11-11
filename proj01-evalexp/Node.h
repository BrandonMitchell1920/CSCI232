/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Node ADT
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef NODE_H
#define NODE_H

#include <memory>

template<class ItemType>
class Node
{
private:
   ItemType item; // A data item
   std::shared_ptr<Node<ItemType> > next; // Pointer to next node
   
public:
   // constructors
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, std::shared_ptr<Node<ItemType> > nextNodePtr);

   // destructor
   virtual ~Node();

   // accessor methods
   ItemType getItem() const ;
   std::shared_ptr<Node<ItemType> > getNext() const ;

   // mutator methods
   void setItem(const ItemType& anItem);
   void setNext(std::shared_ptr<Node<ItemType> > nextNodePtr);
}; // end Node

// template classes require implementation
#include "Node.cpp"
#endif