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

#include "PlainBox.h"

using std::string;
using std::cout;
using std::endl;

int main()
{

   PlainBox<double> numberBox; // A box to hold a double
   PlainBox<string> nameBox;   // A box to hold a string object
   
   double health = 6.5;
   numberBox.setItem(health);
   
   string secretName = "Rumpelstiltskin";
   nameBox.setItem(secretName);
   
   cout << "numberBox.getItem() = " << numberBox.getItem() << endl;
   cout << "nameBox() = " << nameBox.getItem() << endl;
   
   return 0;
} // end main
