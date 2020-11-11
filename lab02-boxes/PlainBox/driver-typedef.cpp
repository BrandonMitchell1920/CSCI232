/** Driver for PlainBox
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
#include <iostream>
#include <string>

#include "PlainBoxTypeDef.h"

using std::string;
using std::cout;
using std::endl;

int main()
{

   PlainBox numberBox; // A box to hold a double
   
   double health = 6.5;
   numberBox.setItem(health);
   
   cout << "numberBox.getItem() = " << numberBox.getItem() << endl;
   
   return 0;
} // end main
