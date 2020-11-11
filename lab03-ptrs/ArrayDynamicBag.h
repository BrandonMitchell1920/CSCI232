/*
 * Name:	Brandon Mitchell
 * Description:	A bag that dynamically resizes itself.  It inherits from 
 *				ArrayBag, but has different add and remove methods to account
 *				for the dynamic resizing.
 */
 
#ifndef DYNAMIC_ARRAY_BAG_H
#define DYNAMIC_ARRAY_BAG_H

#include "ArrayBag.h"

template<class ItemType, unsigned int ArraySize>
class ArrayDynamicBag : public ArrayBag<ItemType>
{
	private:
	
        // Won't change and will be the same for all instances of this classe
		static const unsigned char 
			HighWaterMark = 85,
			LowWaterMark = 65,
			ChangeAmount = 10;
		
        // Keep track of initial size and the current size (or max)
		const unsigned int initialSize;
        unsigned int currentMax;
	
	public:
	
        // Constructor, takes no parameters
		ArrayDynamicBag();
	
        // Override methods of parent class
		bool add(const ItemType & newEntry);
		bool remove(const ItemType & anEntry);
};

#include "ArrayDynamicBag.cpp"

#endif