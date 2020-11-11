/** PlainBox - Holds a single item that can be changed
 * Implemented with Templates
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef PLAIN_BOX_H
#define PLAIN_BOX_H

#include "BoxInterface.h"

// Indicates this is a template definition
// ItemType is satisfied by client of this ADT
template<class ItemType> 

// Declaration for the class PlainBox
class PlainBox : BoxInterface<ItemType>
{
private:
   // Data field
   ItemType item;
   
public:
   // Default constructor
   PlainBox();
   
   // Parameterized constructor
   PlainBox(const ItemType& theItem);
   
   // Mutator method that can change the value of the data field
   void setItem(const ItemType& theItem);
   
   // Accessor method to get the value of the data field
   ItemType getItem() const;
}; // end PlainBox

// Compiles must see implementation file when class is template
#include "PlainBox.cpp" 
#endif