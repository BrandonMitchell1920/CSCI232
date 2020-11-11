/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Exception Handling
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */
 
/*
 * Modified by:	Brandon Mitchell
 * Description: Added in exception catching as now our ArrayBag methods can 
 *				throw exceptions!  These are caught and responded to.
 */

#include <cstddef>
#include <iostream>
#include <string>

#include "ArrayBag.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

// display bag size and contents
// using getCurrentSize and toVector methods of Bag ADT
template <typename AnyType>
void displayBag(BagInterface<AnyType> *bag)
{
     cout << "The bag contains " << bag->getCurrentSize()
          << " items:" << endl;
     vector<AnyType> bagItems = bag->toVector();
   
     int numberOfEntries = (int) bagItems.size();
     for (int i = 0; i < numberOfEntries; i++)
     {
          cout << bagItems[i] << " ";
     }  // end for
	cout << endl << endl;
}  // end displayBag

// unit test for Bag ADT 
// exercises all behaviors of the Interface
template <typename AnyType>
void bagTester(BagInterface<AnyType> *bag, int bagCapacity)
{
    cout << "isEmpty: returns " << bag->isEmpty() 
         << "; should be 1 (true)" << endl;
    displayBag(bag);

    string items[] = {"one", "two", "three", "four", "five", "one"};
    int itemsSize = sizeof(items)/sizeof(items[0]);

    cout << "Add 6 items to the bag: " << endl;
	
	try
	{
		for (int i = 0; (i < bagCapacity) && (i < itemsSize); i++)
		{
			bag->add(items[i]);
		}  // end for
	}
	catch (std::out_of_range & err)
	{
        // Note: the text will be in black letters with red backgroug so the 
        // user doesn't miss it in a sea of other output
		cout << "\n\x1b[41;30mError adding to bag!  Error message reports: " 
		     << err.what() << "\x1b[0m\n";
	}
	
    displayBag(bag);
   
    cout << "isEmpty: returns " << bag->isEmpty() 
         << "; should be 0 (false)" << endl;
	
    cout << "getCurrentSize: returns " << bag->getCurrentSize() 
         << "; should be 6" << endl;
   
    try 
	{
		cout << "Try to add another entry: add(\"extra\") returns " 
             << bag->add("extra") << endl;
	}
	catch (std::out_of_range & err)
	{
		cout << "\n\x1b[41;30mError adding to bag!  Error message reports: " 
		     << err.what() << "\x1b[0m\n";
	}
   
	try
	{
		cout << "contains(\"three\"): returns " << bag->contains("three")
			 << "; should be 1 (true)" << endl;
		cout << "contains(\"ten\"): returns " << bag->contains("ten")
			 << "; should be 0 (false)" << endl;
		cout << "getFrequencyOf(\"one\"): returns "
			 << bag->getFrequencyOf("one") << " should be 2" << endl;
		cout << "remove(\"one\"): returns " << bag->remove("one")
			 << "; should be 1 (true)" << endl;
		cout << "getFrequencyOf(\"one\"): returns "
			 << bag->getFrequencyOf("one") << " should be 1" << endl;
		cout << "remove(\"one\"): returns " << bag->remove("one")
			 << "; should be 1 (true)" << endl;
		cout << "remove(\"one\"): returns " << bag->remove("one")
			 << "; should be 0 (false)" << endl;
		cout << endl;
	}
	catch (std::out_of_range & err)
	{
        // Error when removing from an empty bag
		cout << "\n\x1b[41;30mError removing from bag!  Error message reports: " 
		     << err.what() << "\x1b[0m\n";
	}
	catch (TargetNotFoundError & err)
	{
        // Error when remvoing something not in a bag
		cout << "\n\x1b[41;30mError removing from bag!  Error message reports: " 
		     << err.what() << "\x1b[0m\n";
	}
   
    displayBag(bag);
   
    cout << "After clearing the bag, ";
    bag->clear();
   
    cout << "isEmpty: returns " << bag->isEmpty()
         << "; should be 1 (true)" << endl;
		 		 
}  // end bagTester

// main entry point for driver application
int main()
{
     // Set a pointer to a new ArrayBag of size bagCapacity
     // allocated on the memory Heap
     const int bagCapacity = 6;
     BagInterface<string> *myBag = new ArrayBag<string>(bagCapacity);

     // inform the user of unit testing and show the results
	cout << "Testing the Array-Based Bag:" << endl;
     cout << "The initial bag is empty." << endl;
	bagTester(myBag, bagCapacity);

     // inform the user the testing is complete
     cout << "All done!" << endl;
   
     // return to our caller (the shell) success
     return EXIT_SUCCESS; // defined in ctddef
}  // end main
