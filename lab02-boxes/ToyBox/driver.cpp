/** Driver for ToyBox
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
#include <iostream>
#include <string>

#include "ToyBox.h"

using std::string;
using std::cout;
using std::endl;

int main()
{
   string favoriteToy = "Jack-in-the-Box";
   ToyBox<string> myToyCase(favoriteToy, RED); // A red toy box
   
   string oldToy = myToyCase.getItem();        // oldToy is a Jack-in-the-Box
   cout << "myToyCase.getItem() = " << oldToy << endl;
   
   favoriteToy = "Spinning Top";
   myToyCase.setItem(favoriteToy);             // myToyCase now holds a Spinning Top  
   cout << "myToyCase.getItem() = " << myToyCase.getItem() << endl;
   
   return 0;
} // end main
