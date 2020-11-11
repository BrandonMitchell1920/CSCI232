/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Node ADT Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef NODE_IMP
#define NODE_IMP

// Node ADT Definition
#include "Node.h"

/** default constructor
 * @pre - no precondition
 * @post - a new instance of the Node class
 */
template<class ItemType>
Node<ItemType>::Node()
{
} // end default constructor

/** constructor
 * @pre - no precondition
 * @post - a new instance of the Node class
 * @param anItem - an item of ItemType held by the Node instance
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem)
{
} // end constructor

/** constructor
 * @pre - no precondition
 * @post - a new instance of the Node class
 * @param anItem - an item of ItemType held by the Node instance
 * @param nextNodePtr - a pointer to an instance of the Node class
 */
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, shared_ptr<Node<ItemType> > nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} // end constructor

/** access the item held at the Node instance
 * @pre - an instance of the Node class
 * @post - no post condition
 * @return - the item held at the Node
 */
template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
   return item;
} // end getItem

/** access the next pointer held at the Node instance
 * @pre - an instance of the Node class
 * @post - no post condition
 * @return - the point to a Node instance
 */
template<class ItemType>
shared_ptr<Node<ItemType> > Node<ItemType>::getNext() const
{
   return next;
} // end getNext

/** set the item held at the Node instance
 * @pre - an instance of the Node class
 * @post - the Node is modified
 * @param anItem - an item to be set in the Node instance
 */
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
   item = anItem;
} // end setItem

/** set the a pointer to a Node instance
 * @pre - an instance of the Node class
 * @post - the Node is modified
 * @param nextNodePtr - the pointer to a Node instance
 */
template<class ItemType>
void Node<ItemType>::setNext(shared_ptr<Node<ItemType> > nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

#endif