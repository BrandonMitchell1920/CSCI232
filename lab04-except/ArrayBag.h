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
 * Modified By: Brandon Mitchell
 * Description: Add and remove now return an int instead of a bool.
 */

#ifndef ARRAYBAG_H
#define ARRAYBAG_H

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	ItemType* items; // pointer to an array of ItemType
  int itemCount;    // Current count of bag items 
  int maxItems;     // Holds the maximum items in the bag
   
  // Returns either the index of the element in the array items that
  // contains the given target or -1, if the array does not contain 
  // the target.
  
	// << UPDATE ME >> to accommodate exception handling
  int getIndexOf(const ItemType& target) const;   

public:
	ArrayBag(const int bagSize);
	~ArrayBag();

	int getCurrentSize() const;
	bool isEmpty() const;
	
	// << UPDATE ME >> to accommodate exception handling
	int add(const ItemType& newEntry);
	
	// << UPDATE ME >> to accommodate exception handling
	int remove(const ItemType& anEntry);
	
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
  std::vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
