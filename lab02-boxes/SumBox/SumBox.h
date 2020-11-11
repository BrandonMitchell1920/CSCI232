/** SumBox - Holds only a Integer sum of integers placed in the box
 *         - If the sum is + then the Box color is Black
 *         - If the sum is - then the Box color is Red
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#ifndef SUM_BOX_H
#define SUM_BOX_H

#include "ToyBox.h"

class SumBox : public ToyBox<int>
{
public:
   // Default Contructor
   SumBox();

   // Constructor takes an initial amount to place in SumBox
   SumBox(const int amount);

   // Method to set the item held in the PlainBox
   void setItem(const int amount);
   
}; // end ToyBox

#endif