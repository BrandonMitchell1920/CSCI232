/** ToyBox Implementation - Has a color and holds a single item that can be changed
 * Implemented with Templates
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Added protected setColor method.
 */

#ifndef TOY_BOX_IMP
#define TOY_BOX_IMP

#include "ToyBox.h"

// sets the color of the box, protected method
template<class ItemType>
void ToyBox<ItemType>::setColor(const Color & theColor)
{
    boxColor = theColor;
}

// Default contructor - uses initializer to set Box color to Black
template<class ItemType>
ToyBox<ItemType>::ToyBox() : boxColor(BLACK)
{
}  // end default constructor

// Constructor setting initial Box Color using initializer
template<class ItemType>
ToyBox<ItemType>::ToyBox(const Color& theColor) : boxColor(theColor)
{
}  // end constructor

// Constructor setting initial Box Color and Item using initializers
template<class ItemType>
ToyBox<ItemType>::ToyBox(const ItemType& theItem, const Color& theColor)
   :PlainBox<ItemType>(theItem), boxColor(theColor) // Initialize item data fields
{
}  // end constructor

// Method returns the current color fo the Box
template<class ItemType>
Color ToyBox<ItemType>::getColor() const
{
   return boxColor;
}  // end getColor

#endif