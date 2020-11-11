/** PlainBox Implementation - Holds a single item that can be changed
 * Implemented without templates - using typedef for ItemType
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
#include "PlainBoxTypeDef.h"

// Default Contructor
PlainBox::PlainBox()
{
} // end default constructor

// Contrustor passing in an initial item
PlainBox::PlainBox(const ItemType& theItem)
{
   item = theItem;
} // end constructor

// Method for setting the item in the Box
void PlainBox::setItem(const ItemType& theItem)
{
   item = theItem;
} // end setItem

// Method for returning the item presently held in the Box
ItemType PlainBox::getItem() const
{
   return item;
} // end getItem
#endif