/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Pointers 
 * 
 * Array Based Bag ADT
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Implemented the resize method.  It creates a new array with  
 *              more items or less items depending upon what is needed.
 */

#ifndef ARRAYBAG_IMP
#define ARRAYBAG_IMP

#include <iostream>
using namespace std;

#include <cstddef>

#include "ArrayBag.h"

template<class ItemType>
ArrayBag<ItemType>::ArrayBag(int bagSize): itemCount(0), maxItems(bagSize)
{
   items = new ItemType[maxItems];
}  // end default constructor

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

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
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
template<class ItemType>
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
   
   return result;
}  // end getIndexOf

// protected, Takes an int newSize, creates an array on the heap with that 
// size, copies data to it, and then deletes the old data and assigns the Items
// pointer to the new array.
template<class ItemType>
void ArrayBag<ItemType>::resize(int newSize)
{
	// Create new array
	ItemType * newItems = new ItemType[newSize];
    	
	// Assign values of items to new array
	for (signed int index = 0; index < itemCount; index++)
	{
		newItems[index] = items[index];
	}
	
    // Free memory, set items pointer to new array
    delete [] items;
    items = newItems;
    
    maxItems = newSize;
}

#endif