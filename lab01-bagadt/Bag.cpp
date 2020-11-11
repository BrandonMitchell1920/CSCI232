/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Bag ADT
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */

#ifndef BAG_IMP
#define BAG_IMP

#include <cstddef>

#include "Bag.h"

/**
 * Default Constructor
 */
template<class ItemType>
Bag<ItemType>::Bag() : itemCount(0), maxItems(DEFAULT_BAG_SIZE)
{
}  // end default constructor

/**
 * get the number of items in the bag
 */
template<class ItemType>
int Bag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

/**
 * determine if the bag is empty
 */
template<class ItemType>
bool Bag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

/**
 * add an item to the bag
 */
template<class ItemType>
bool Bag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

/**
 * remove an item from the bag
 */
template<class ItemType>
bool Bag<ItemType>::remove(const ItemType& anEntry)
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

/**
 * remove all items from the bag
 */
template<class ItemType>
void Bag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

/**
 * get the number of instances of a given item in the bag
 */
template<class ItemType>
int Bag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int searchIndex = 0;
   while (searchIndex < itemCount)
   {
      if (items[searchIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      searchIndex++;
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

/**
 * determine if at least one instance of an item is in the bag
 */
template<class ItemType>
bool Bag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/**
 * return a vector representation of the bag contents
 */
template<class ItemType>
std::vector<ItemType> Bag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
   return bagContents;
}  // end toVector

/**
 * Private Method
 * return the index of the first occurance of the item in the bag
 */
template<class ItemType>
int Bag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   // if the bag is empty, itemCount is zero, so loop is skipped
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

#endif