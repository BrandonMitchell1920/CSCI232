/**
 * CSCI232 Data Structures
 * 
 * Plain Box
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-498-5679
 * Department of Computer Science, Montana Tech
 */

#ifndef PLAIN_BOX_IMP
#define PLAIN_BOX_IMP

#include "PlainBox.h"

template<class ItemType>
PlainBox<ItemType>::PlainBox()
{
} // end default constructor

template<class ItemType>
PlainBox<ItemType>::PlainBox(const ItemType& theItem)
{
   item = theItem;
} // end constructor

template<class ItemType>
void PlainBox<ItemType>::setItem(const ItemType& theItem)
{
   item = theItem;
} // end setItem

template<class ItemType>
ItemType PlainBox<ItemType>::getItem() const
{
   return item;
} // end getItem

#endif
