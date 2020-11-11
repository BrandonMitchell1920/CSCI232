/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Exception Handling 
 * 
 * Array Based Bag ADT
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */
 
/*
 * Modified by:	Brandon Mitchell
 * Description: Certain methods can now throw exceptions!  The methods that
 *				can are add(), remove(), and getIndexOf().  These can be 
 *				caught and responded to if so desired.
 */ 
 
#ifndef ARRAYBAG_IMP
#define ARRAYBAG_IMP

#include <cstddef>

#include "ArrayBag.h"
#include "CustomException.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(int bagSize): itemCount(0), maxItems(bagSize)
{
   items = new ItemType[maxItems];
} // end constructor

template<class ItemType>
ArrayBag<ItemType>::~ArrayBag()
{
   delete [ ] items;
}  // end deconstructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType> // << UPDATE ME >> to accommodate Exception Handling
int ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
	else
	{
		// If there ain't room to add, then it full!!!
		throw std::out_of_range("Array out of bounds error!  "
		                        "Max size reached!");
	}
    
	return itemCount;
}  // end add

template<class ItemType> // << UPDATE ME >> to accommodate Exception Handling
int ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
	// Can't remove things if the bag is empty!
	if (isEmpty())
	{
		throw std::out_of_range("Array out of bounds error!  "
							    "Bag is empty!");
	}
	
    int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = locatedIndex > -1;
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return itemCount;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType> // << UPDATE ME >> to accommodate Exception Handling
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
    int result = -1;
	int searchIndex = 0;
   
	// If the bag is empty, itemCount is zero, so loop is skipped
	while (!found && (searchIndex < itemCount))
	{
		if (items[searchIndex] == target)
		{
			found = true;
			result = searchIndex;
		} 
		else
		{
			searchIndex++;
		}  // end if
	}  // end while
	
	if (!found)
	{	
		// Exit loop with the item not found
		throw TargetNotFoundError("Target not not in bag!");
	}
   
	return result;
}  // end getIndexOf

#endif
