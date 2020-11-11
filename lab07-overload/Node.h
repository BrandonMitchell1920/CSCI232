/**
 * CSCI 232 Data Structures and Algorithms
 * 
 * Node ADT Class
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
   ItemType        item; // A data item
   std::shared_ptr<Node<ItemType> > next; // Pointer to next node
   
public:
   Node();
   Node(const ItemType& anItem);
   Node(const ItemType& anItem, std::shared_ptr<Node<ItemType> > nextNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(std::shared_ptr<Node<ItemType> > nextNodePtr);
   ItemType getItem() const ;
   std::shared_ptr<Node<ItemType> > getNext() const ;

}; // end Node

#include "Node.cpp"
#endif
