/**
 * CSCI232 Data Structures
 * 
 * Magic Box
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-498-5679
 * Department of Computer Science, Montana Tech
 */

#ifndef MAGIC_BOX_H
#define MAGIC_BOX_H

#include "PlainBox.h"

template<class ItemType>
class MagicBox : public PlainBox<ItemType>
{
private:
   bool firstItemStored;

public:
   MagicBox();
   MagicBox(const ItemType& theItem);

   // Override setItem from Parent Class
   void setItem(const ItemType& theItem);
}; // end MagicBox

#include "MagicBox.cpp"
#endif

