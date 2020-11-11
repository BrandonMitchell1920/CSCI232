/** SumBox Implementation - Holds only a Integer sum of integers placed in the box
 *         - If the sum is + then the Box color is Black
 *         - If the sum is - then the Box color is Red
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
 /*
 * Modified by: Brandon Mitchell
 * Description: Implemented setItem method.  Changes color automatically if
 *              the added item changes the sign of the item.
 */

#ifndef SUM_BOX_IMP
#define SUM_BOX_IMP

#include "SumBox.h"

// Default contructor 
SumBox::SumBox() : ToyBox<int>(0, BLACK)
{
}  // end default constructor

// Constructor setting initial amount in Box
SumBox::SumBox(const int amount) 
{
   setItem(amount);
}  // end constructor

// Method set the item which is the sum of what is in the Box and 
// the new amount passed as a parameter - possibly change BoxColor
// based on the sign of the amount
void SumBox::setItem(const int amount)
{
   // get the current item from the Box instance
   signed int currentItem = getItem();

   // compute new amount for the Box instance
   signed int newAmount = currentItem + amount;

   // setItem from parent scope via scope resolution operator
   // to set the Box instance item to the computed newAmount
   PlainBox<signed int>::setItem(newAmount);

   // Determine if we need to change the Box color - in an efficient manner
   // if we need to change the box color, call the setColor method of 
   // our parent class - which has been extended with this methid
   if (newAmount < 0 and getColor() != RED) {setColor(RED);}
   else if (newAmount >= 0 and getColor() != BLACK) {setColor(BLACK);}

} // end setItem

#endif
