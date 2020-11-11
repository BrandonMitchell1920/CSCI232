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

#ifndef ARRAYBAG_H
#define ARRAYBAG_H

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	ItemType* items;  // pointer to an array of ItemType
    int itemCount;    // Current count of bag items 
    int maxItems;     // Holds the maximum items in the bag
   
    // Returns either the index of the element in the array items that
    // contains the given target or -1, if the array does not contain 
    // the target.
    int getIndexOf(const ItemType& target) const;

protected:
	void resize(int newSize);

public:
	ArrayBag(const int bagSize);    
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
    std::vector<ItemType> toVector() const;
   
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif