/**
 * CSCI232 Data Structures
 * 
 * Main Driver
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-498-5679
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Added in some tests to test the box's nesting cababilites.  I 
 *              put print statements in there (now removed) to see that the 
 *              recursion was working and that the boxes were nested.
 */

#include <iostream>
#include <string>

#include "BoxContainer.h"
#include "PlainBox.h"
#include "MagicBox.h"

void displayBoxItem(PlainBox<std::string>* box)
{
    std::cout << "The item in the box: ";
    std::cout << box->getItem() << std::endl;
}

/**
 * Main driver that will test the boxes
 */
int main()
{
	// Let's make some boxes in our stack frame
    PlainBox<std::string> myPlainBox("Basketball");
    MagicBox<std::string> myMagicBox("Volleyball");
    
    displayBoxItem(&myPlainBox); // myPlainBox's item is displayed
    displayBoxItem(&myMagicBox); // myMagicBox's item is displayed
    
    // Test a single nested BoxContainer's getItem()
	std::cout << "\nLet's nest a single box!  A PlainBox in a BoxContainer!\n"
	             "The original PlainBox holds " << myPlainBox.getItem();
	BoxContainer<PlainBox<std::string>> boxOne(& myPlainBox);
	std::cout << " and the PlainBox in a BoxContainer (1 level of nesting) "
	             "holds a " << boxOne.getItem() << " (should both be \""
				 "Basketball\")\n";

    // Test a single nested BoxContainer's setItem()                 
	std::cout << "\nLet's try setting the item of the PlainBox in the "
				 "BoxContainer!\nCalling setItem(\"Football\") on the nested"
				 " boxes!\n";
	boxOne.setItem("Football");
    std::cout << "Now the nested box holds a " << boxOne.getItem() 
			  << " (should be \"Football\")\n";
	
    // Test a three nested box
	std::cout << "\nLet's try to nest our level 1 nested box into a couple of "
				 "other BoxContainers!\nPass our box into the constructor of "
				 "the BoxContainer to nest.\n";
	BoxContainer<PlainBox<std::string>> boxTwo(& boxOne);
	BoxContainer<PlainBox<std::string>> boxThree(& boxTwo);
	std::cout << "Let's try to display it's item!  It should still be "
				 "\"Football\"\nThe PlainBox nested into three BoxContainers "
				 "has a " << boxThree.getItem() << " inside (should be "
				 "\"Football\")\n";
	std::cout << "Does setItem() still work?  Let's change it to "
	             "\"Tennis Ball\"!\n";
	boxThree.setItem("Tennis Ball");
	std::cout << "The triple nested box holds a " << boxThree.getItem()
	          << " (should be \"Tennis Ball\")\n";
	
    // Test a MagicBox nested ten deep
	std::cout << "\nFinal test!!!  Ten levels of nesting with a MagicBox! "
	             " The item should not change when set.\nInitial item is "
			  << myMagicBox.getItem();
			  
	BoxContainer<MagicBox<std::string>> b0(& myMagicBox);
	BoxContainer<MagicBox<std::string>> b1(& b0);
	BoxContainer<MagicBox<std::string>> b2(& b1);
	BoxContainer<MagicBox<std::string>> b3(& b2);
	BoxContainer<MagicBox<std::string>> b4(& b3);
	BoxContainer<MagicBox<std::string>> b5(& b4);
	BoxContainer<MagicBox<std::string>> b6(& b5);
	BoxContainer<MagicBox<std::string>> b7(& b6);
	BoxContainer<MagicBox<std::string>> b8(& b7);
	BoxContainer<MagicBox<std::string>> b9(& b8);

	std::cout << "\nThe box still holds " << b9.getItem() 
			  << " (should be \"Volleyball\") ";
	b9.setItem("This shouldn's work!");
	std::cout << "and calling setItem(\"This shouldn'T work!\") on the "
	             "box gives us " << b9.getItem() << " (should still "
				 "be \"Volleyball\")\n";
    
    return EXIT_SUCCESS;
}  // end main

