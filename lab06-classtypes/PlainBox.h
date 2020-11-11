/**
 * CSCI232 Data Structures
 * 
 * Plain Box
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-498-5679
 * Department of Computer Science, Montana Tech
 */
    
#ifndef PLAIN_BOX_H
#define PLAIN_BOX_H

#include "BoxInterface.h"

template<class ItemType>  
class PlainBox : public BoxInterface<ItemType>
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

#include "PlainBox.cpp" // Include the implementation file
#endif
