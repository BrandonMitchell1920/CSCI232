/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * LinkedIterator Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef LINKED_ITERATOR_H
#define LINKED_ITERATOR_H

#include <memory>
#include <iterator>

#include "Node.h"

using std::iterator;
using std::input_iterator_tag;
using std::shared_ptr;

// Need the forward declaration since the 
// Iterator must refer to the type over which it iterates
template<class ItemType>
class LinkedListwIterator;

template <class ItemType>
class LinkedIterator : public iterator<input_iterator_tag, int>
{
private:
   // ADT associated with iterator - requires a forward declaration
   const shared_ptr<LinkedListwIterator<ItemType> > containerPtr;
   
   // Current location in collection - Requires the Node type
   // which is the element in the LinkedList implementation of LIST ADT
   shared_ptr<Node<ItemType> > currentItemPtr;
   
public:
   /** LinkedIterator Constructor
    * @param someList a pointer to a LinkedListwIterator<ItemType> list
    * @param nodePtr a pointer to a Node<ItemType>
    * @return a new LinkedIterator object
    */
   LinkedIterator(shared_ptr<LinkedListwIterator<ItemType> > someList,
                  shared_ptr<Node<ItemType> > nodePtr = nullptr);
   
   /** Dereferencing operator overload.
    @return The item at the position referenced by iterator. */
   const ItemType operator*();
   
   /** Prefix increment operator overload.
    @return  The iterator referencing the next position in the list. */
   LinkedIterator<ItemType> operator++();
   
   /** Equality operator overload.
    @param rightHandSide  a LinkedIterator for comparison.
    @return  True if this iterator references the same list and
       the same position as rightHandSide, false otherwise. */    
    bool operator==(const LinkedIterator<ItemType>& rightHandSide) const;
   
    /** Inequality operator overload.
     @param rightHandSide  a LinkedIterator for comparison.
     @return  True if this iterator does not reference the same
        list and the same position as rightHandSide, false otherwise. */
   bool operator!=(const LinkedIterator<ItemType>& rightHandSide) const;
}; // end LinkedIterator

#include "LinkedIterator.cpp"
#endif
