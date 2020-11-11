/** Driver for MagicBox
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <iostream>
#include <string>

#include "MagicBox.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
   string rabbit = "Rabbit";
   string wand = "Wand";
   
   MagicBox<string> magicHat;
   magicHat.setItem(rabbit);
   cout << "magicHat.getItem() = " << magicHat.getItem() << endl;
   
   magicHat.setItem(wand);
   // magicHat still holds the rabbit
   cout << "magicHat.getItem() = " << magicHat.getItem() << endl;
   
   return 0;
} // end main

