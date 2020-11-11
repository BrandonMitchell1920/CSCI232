/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Pointers
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Added a test specfically for the new ArrayDynamicBag class.
 *              Since it can dynamically resize, adding more than the intial
 *              size is how it can be tested.  I tested it by adding print 
 *              statements into the add and remove methods to see that the size
 *              was updating like it was supposed to, but removed them for 
 *              the final project.
 */

#include <cstddef>
#include <iostream>
#include <string>

#include "ArrayBag.h"
#include "ArrayDynamicBag.h"

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
	for (int i = 0; (i < bagCapacity) && (i < itemsSize); i++)
     {
	     bag->add(items[i]);
	}  // end for
   
     displayBag(bag);
   
     cout << "isEmpty: returns " << bag->isEmpty() 
          << "; should be 0 (false)" << endl;
	
     cout << "getCurrentSize: returns " << bag->getCurrentSize() 
          << "; should be 6" << endl;
   
     cout << "Try to add another entry: add(\"extra\") returns " 
          << bag->add("extra") << endl;      
   
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
   
     displayBag(bag);
   
     cout << "After clearing the bag, ";
     bag->clear();
   
     cout << "isEmpty: returns " << bag->isEmpty()
          << "; should be 1 (true)" << endl;
}  // end bagTester

// A test for the ArrayDynamicBag, pratice adding and removing items and see 
// how that affects the max size
template<typename ItemType>
void anotherBagTester(BagInterface<ItemType> * bag)
{
    cout << "Bag should be empty.  isEmpty() returns " << bag->isEmpty() 
         << " (should be 1).\n\n";
         
    cout << "Adding \"Example\" to the bag.\n";
    bag->add("Example");
	displayBag(bag);
    cout << "Bag now has a size of " << bag->getCurrentSize() 
         << " (should be 1).\n\n";
    
    vector<string> array1 = {"one", "two", "three", "four", "five"},
                   array2 = {"A", "B", "C", "D", "E", "F", "G"};
	
    cout << "Adding five elements to bag.\n";
    for (string item : array1) {bag->add(item);}
    displayBag(bag);
    cout << "Bag now has a size of " << bag->getCurrentSize() 
         << " (should be 6).\n\n";    
    
    cout << "Adding seven elements to bag, should resize and accept new "
            "entries.\n";
    for (string item : array2) {bag->add(item);}    
    displayBag(bag);
    cout << "Bag now has a size of " << bag->getCurrentSize() 
         << " (should be 13).\n\n";  
         
    cout << "Removing first set of elements.\n";
    for (string item : array1) {bag->remove(item);}
    displayBag(bag);
    cout << "Bag now has a size of " << bag->getCurrentSize() 
         << " (should be 8).\n\n";   
         
    cout << "Removing second set of elements.\n";
    for (string item : array2) {bag->remove(item);}
    displayBag(bag);
    cout << "Bag now has a size of " << bag->getCurrentSize() 
         << " (should be 1).\n\n";   
         
    cout << "Remove last element.\n";
    bag->remove("Example");
    
    cout << "Bag should be empty.  isEmpty() returns " << bag->isEmpty() 
         << " (should be 1).\n\n";
         
    cout << "Add all elements back to ensure downsizing has worked without "
            "any weird issues.\n";
    for (string item : array1) {bag->add(item);}
    for (string item : array2) {bag->add(item);}
    displayBag(bag);
    cout << "Bag now has a size of " << bag->getCurrentSize() 
         << " (should be 12).\n\n"; 
         
    cout << "Remove all entries once again!\n";
    bag->clear();
    cout << "Bag should be empty.  isEmpty() returns " << bag->isEmpty() 
         << " (should be 1).\n\n";    
}

// main entry point for driver application
int main()
{
    // Set a pointer to a new ArrayBag of size bagCapacity
    // allocated on the memory Heap
    const int bagCapacity = 6;
    BagInterface<string> *myBag = new ArrayBag<string>(bagCapacity);

    // Set a pointer to a new ArrayDynamicBag of size bagCapcity
    // allocated on the memory heap
    BagInterface<string> * myDynamicBag = new ArrayDynamicBag<string, 
        bagCapacity>();

    // inform the user of unit testing and show the results
	cout << "Testing the Array-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
	bagTester(myBag, bagCapacity);
    
    // test the new ArrayDynamicBag
    cout << "\n\nTesting the ArrayDynamicBag.  Test its features that "
            "were in ArrayBag and test its unique features.\n";
    cout << "The initial bag is empty and has a size of " << bagCapacity 
         << "\n";
    bagTester(myDynamicBag, bagCapacity);
    anotherBagTester(myDynamicBag);

    // inform the user the testing is complete
    cout << "All done!" << endl;
   
    // return to our caller (the shell) success
    return EXIT_SUCCESS; // defined in ctddef
}   // end main