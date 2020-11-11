/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Linked List Class 
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <memory>

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

using std::shared_ptr;

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
   shared_ptr<Node<ItemType> > headPtr; // Pointer to first node in the chain;
                            // (contains the first entry in the list)
   int itemCount;           // Current count of list items 
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   shared_ptr<Node<ItemType> > getNodeAt(int position) const;

public:
   LinkedList();
   LinkedList(const LinkedList<ItemType>& aList);
   virtual ~LinkedList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool remove(int position);
   void clear();
   
   bool swap(shared_ptr<ListInterface<ItemType>> aList, 
                    unsigned int i, unsigned int j);
   bool contains(const ItemType & entry);
   
   /** @throw PrecondViolatedExcep if position < 1 or 
                                      position > getLength(). */
   ItemType getEntry(int position) const;

   /** @throw PrecondViolatedExcep if position < 1 or 
                                      position > getLength(). */
   void replace(int position, const ItemType& newEntry);
}; // end LinkedList

#include "LinkedList.cpp"
#endif 
