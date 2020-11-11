/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Bag ADT
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */
 
 /*
  * Modified by:    Brandon Mitchell
  * Description:    Added some various tests of the bag's capabilities and 
  *                 behaviors.  Did not need to know how the bag worked due to
  *                 a well-documented API.
  */

#include <cstddef> 
#include <iostream>
#include <string>

#include "BagInterface.h" // BagInterface 
#include "Bag.h" // BagInterface points to Instances of Bag

using std::cout;
using std::cerr;
using std::endl;
using std::string;

/**
 * Driver to Test Bag ADT
 */
int main(int argc, char* argv[])
{
    // create a Bad Object and notify the user
    BagInterface<string> *myBag = new Bag<string>();
    cout << "Created a new bag." << endl;

    // let the user know if the bag is empty
    cout << "The bag is " << ((myBag->isEmpty()) ? "" : "not ") << "empty." << endl;

    // insert three (3) items into the bag and notify the user
    myBag->add("Apple");
    myBag->add("Grape");
    myBag->add("Orange");
    cout << "Added three (3) items to the bag." << endl;

    // let the user know if the bag is empty
    cout << "The bag is " << ((myBag->isEmpty()) ? "" : "not ") << "empty." << endl;
    
    // remove the second item
    myBag->remove("Grape");

    // print out the number of items
    cout << "Now, there are only " << myBag->getCurrentSize() << " items." << endl;

    // let the user know if the last item added is still in the bag
    cout << "The \"Orange\" is " << (myBag->contains("Orange") ? "" : "not ") << "there!" << endl;

    // add four (4) of the same item and notify the user
    for (unsigned char i = 0; i < 4; i++) {myBag->add("Lemon");}
    cout << "Four (4) \"Lemon\"s added!" << endl; 

    // let the user know the the size of the bag
    cout << "Wow!  The bag holds " << myBag->getCurrentSize() << " items!" << endl;

    // let the user know the frequency of the four items added
    cout << "\"Apple\" appears " << myBag->getFrequencyOf("Apple") << " times!" << endl;
    cout << "\"Grape\" appears " << myBag->getFrequencyOf("Grape") << " times!" << endl;
    cout << "\"Orange\" appears " << myBag->getFrequencyOf("Orange") << " times!" << endl;
    cout << "\"Lemon\" appears " << myBag->getFrequencyOf("Lemon") << " times!" << endl;

    // clear the bag and notify the user
    myBag->clear();
    cout << "The bag has been cleared!" << endl;

    // let the user know if the bag is empty
    cout << "The bag is " << ((myBag->isEmpty()) ? "" : "not ") << "empty." << endl;

    // return to our caller
    return EXIT_SUCCESS;
} // end main
