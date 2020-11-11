/** PlainBox Implementation - Holds a single item that can be changed
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef PLAIN_BOX_IMP
#define PLAIN_BOX_IMP

// Compiler needs the PlainBox Type Declaration
#include "PlainBox.h"

// Default contructor
template<class ItemType>
PlainBox<ItemType>::PlainBox()
{
} // end default constructor

// Contructor that takes an initial item to place in the Box
template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem) : item(theItem)
{
} // end constructor

// Meethod for setting the item in the Box
template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem)
{
   item = theItem;
} // end setItem

// Method for returning the item presently held in the Box
template<class ItemType>
ItemType PlainBox<ItemType>::getItem() const
{
   return item;
} // end getItem
#endif