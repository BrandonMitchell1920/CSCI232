/*
 * Name:	Brandon Mitchell
 * Description: The implemtation of ArrayDynamicBag.
 */

#ifndef DYNAMIC_ARRAY_BAG_IMP
#define DYNAMIC_ARRAY_BAG_IMP

#include <iostream>

#include "ArrayDynamicBag.h"

// Constructor, an ugly mess of syntax
template<class ItemType, unsigned int ArraySize>
ArrayDynamicBag<ItemType, ArraySize>::ArrayDynamicBag() 
    : ArrayBag<ItemType>::ArrayBag(ArraySize),
	  initialSize(ArraySize), currentMax(ArraySize) {}

// New add method, checks if the bag needs to be resized and will resize it as
// needed before adding
template<class ItemType, unsigned int ArraySize>
bool ArrayDynamicBag<ItemType, ArraySize>::add(const ItemType & newEntry)
{
	unsigned int newBagSize = ArrayBag<ItemType>::getCurrentSize() + 1;
	
    // Check if newBagSize is over the limit
	if (newBagSize * 100 > HighWaterMark * currentMax)
    {
        ArrayBag<ItemType>::resize((currentMax += ChangeAmount));
    }
    
    // Call parent function
    return ArrayBag<ItemType>::add(newEntry);
}

// New remove method, checks if the bag can be made smaller to free up some
// memory, resizes bag to the initial size, the current max size minus the
// change amount, or the total items in the bag, whichever is largest
template<class ItemType, unsigned int ArraySize>
bool ArrayDynamicBag<ItemType, ArraySize>::remove(const ItemType & anEntry)
{    

    if (!ArrayBag<ItemType>::isEmpty())
    {
        unsigned int newBagSize = ArrayBag<ItemType>::getCurrentSize() - 1;
        
        // Check if new size is below the limit, if so change the size
        if (newBagSize * 100 < LowWaterMark * currentMax)
        {	
            // Subtract changeAmount from currentMax and then compare it to the 
            // other two situations and change as needed
            signed int newMax = currentMax - ChangeAmount;
            
            if (newMax < ArrayBag<ItemType>::getCurrentSize())
            {
                newMax = ArrayBag<ItemType>::getCurrentSize();
            }
            if (newMax < (signed) initialSize) {newMax = initialSize;}

            ArrayBag<ItemType>::resize((currentMax = newMax));
        }
    }
    
    // Call parent function
    return ArrayBag<ItemType>::remove(anEntry);
}

#endif