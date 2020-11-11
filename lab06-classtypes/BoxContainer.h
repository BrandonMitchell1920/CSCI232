/**
 * CSCI232 Data Structures
 * 
 * Box Container
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Changed the type of the box data member and the type of the 
 *              constructor's arguement to better implement nesting.
 */

#ifndef BOXCONTAINER_H
#define BOXCONTAINER_H

#include "BoxInterface.h"
#include "PlainBox.h"

// Outter Template for Nested Template
template <typename BoxType>
class BoxContainer;

// Inner Template for Nested Template
// Creating a class <typename> := class <template<typename>>
// <BoxType<ItemType>>
template <template <typename> class BoxType, typename ItemType>
class BoxContainer<BoxType<ItemType> > : public BoxInterface<ItemType>
{
    private:
	    // Note, since I changed this to a pointer, if a PlainBox or MagicBox
		// is inside many other boxContainers, chaning one will change them 
		// all.  A BoxInterface * was the only way I could get it to stop 
		// having type issues with the return value of ItemType.
        BoxInterface<ItemType> * box;

    public:
        // Constructor
        BoxContainer(BoxInterface<ItemType> * aBox);

        // Accessor method - for item in (nested) box 
        // recursively opens BoxContainers until MagicBox or PlainBox and then 
        // retrieves the item from such a box
        ItemType getItem() const;

        // Accessor method - for box
        BoxType<ItemType> getBox() const;

        // Mutator method - for item in (nested) box
        // recursively opens BoxContainers until MagicBox or PlainBox and then
        // sets the item for such a box
        void setItem(const ItemType& anItem);

        // Mutator method - for box
        void setBox(BoxInterface<ItemType> * aBox);
};
#include "BoxContainer.cpp"
#endif
