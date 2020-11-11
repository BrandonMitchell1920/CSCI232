/** ToyBox - Has a color and holds a single item that can be changed
 * Implemented with Templates
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */


#ifndef TOY_BOX_H
#define TOY_BOX_H

#include "PlainBox.h"

enum Color {BLACK, RED, BLUE, GREEN, YELLOW, WHITE};

template<class ItemType>
class ToyBox : public PlainBox<ItemType>
{
private:
   // color of our Box - item is inherited from PlainBox
   Color boxColor;
public:
   // Default Contructor
   ToyBox();

   // Constructor takes an initial color for the Box
   ToyBox(const Color& theColor);

   // Constructor takes an initial color and item for the Box
   ToyBox(const ItemType& theItem, const Color& theColor);

   // Method returns the current color of the Box
   Color getColor() const;
}; // end ToyBox

#include "ToyBox.cpp"
#endif