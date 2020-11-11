/** MagicBox Implementation - Only holds the first item that get set
 * Implemented with Templates
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef MAGIC_BOX_IMP
#define MAGIC_BOX_IMP

#include "MagicBox.h"

// Default Constructor
template<class ItemType>
MagicBox<ItemType>::MagicBox()
   :firstItemStored(false) // Initialize whether item is stored
{
} // end default constructor

// Constructor that takes and initial item to store in PlainBox
template<class ItemType>
MagicBox<ItemType>::MagicBox(const ItemType& theItem)
   :firstItemStored(false) // Initialize whether item is stored
{
   setItem(theItem);   // Set the item in the PlainBox
} // end constructor

// Method to set the item held in the PlainBox
template<class ItemType>
void MagicBox<ItemType>::setItem(const ItemType& theItem)
{
   // Determine if we have already set an Item 
   // If not, then set the item - otherwise, simply return
   if (!firstItemStored)
   {
      // Use the Scope resolution Operator to identify which 
      // setItem to use - in this case, the public method from
      // the PlainBox class - to set the item
      PlainBox<ItemType>::setItem(theItem);

      // Indicate an item has been set so we don't set one
      // ever again for this instance of the MagicBox
      firstItemStored = true; 
   } // end if
} // end setItem

#endif