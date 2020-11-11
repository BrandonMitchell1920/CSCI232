/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * LinkedList with Iterator Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKED_LIST_WITH_ITERATOR_H
#define LINKED_LIST_WITH_ITERATOR_H

#include <memory>

#include "LinkedIterator.h"
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

using std::shared_ptr;

template<class ItemType>
class LinkedListwIterator : 
   // adds a method - shared_from_this - returning a shared point to the instance
	public std::enable_shared_from_this<LinkedListwIterator<ItemType> >,
   // inherit from the standard LIST ADT interface
        public ListInterface<ItemType>
{
private:
   // Pointer to the first node in the chain
   shared_ptr<Node<ItemType> > headPtr; 

   // current number of items in the list
   int itemCount;
   
   // Locates a specified node in this linked list.
   // @pre  position is the number of the desired node;
   //       position >= 1 and position <= itemCount.
   // @post  The node is found and a pointer to it is returned.
   // @param position  The number of the node to locate.
   // @return  A pointer to the node at the given position.
   shared_ptr<Node<ItemType> > getNodeAt(int position) const;
   
public:
   // Constructors
   LinkedListwIterator();
   LinkedListwIterator(const LinkedListwIterator<ItemType>& aList);

   // Destructor
   virtual ~LinkedListwIterator();
   
   // test whether the LIST ADT is empty
   bool isEmpty() const;

   // return how many items are in the LIST ADT
   int getLength() const;

   // insert the entry at the provided position and return
   // the success or failure of this operation
   bool insert(int newPosition, const ItemType& newEntry);

   // remove the entry at the provided position and retrun
   // the success or failure of this operation
   bool remove(int position);

   // remove all items from the LIST ADT
   void clear();
   
   /** @throw PrecondViolatedExcep if position < 1 or
    position > getLength(). */
   ItemType getEntry(int position) const;
   
   /** @throw PrecondViolatedExcep if position < 1 or
    position > getLength(). */
   void replace(int position, const ItemType& newEntry);

   // provide the required iterator methods 
   // begin - returns an iterator with its currentItem being the first element in the list
   LinkedIterator<ItemType> begin();

   // provide the required iterator methods
   // end - returns an iterator with its currentItem being the last element in the list
   LinkedIterator<ItemType> end();
}; // end LinkedList

#include "LinkedListwIterator.cpp"
#endif 
