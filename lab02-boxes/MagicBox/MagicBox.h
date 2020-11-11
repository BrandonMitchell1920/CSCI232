/** MagicBox - Only holds the first item that get set
 * Implemented with Templates
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef MAGIC_BOX_H
#define MAGIC_BOX_H

#include "PlainBox.h"

// Indicates this is a template definition
// ItemType is satisfied by client of this ADT
template<class ItemType>
class MagicBox : public PlainBox<ItemType>
{
private:
   // Used to determine if we can set the item in the 
   // PlainBox we inherit
   bool firstItemStored;
   
public:
   // Default Contructor
   MagicBox();

   // Constructor that takes the initial item to place in PlainBox
   MagicBox(const ItemType& theItem);

   // Method to set the item held in the PlainBox
   void setItem(const ItemType& theItem);
}; // end MagicBox

#include "MagicBox.cpp"
#endif

