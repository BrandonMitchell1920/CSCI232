/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab - Bag ADT
 * 
 * Phillip J. Curtiss, Associate Professor
 * Department of Computer Science, Montana Tech
 * pcurtiss@mtech.edu, 406-496-4807
 */

#ifndef BAG_H
#define BAG_H

#include <vector>

#include "BagInterface.h"

/**
 * Bag ADT - Container with no order; allow duplicates
 */
template<class ItemType>
class Bag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_BAG_SIZE = 6;  
	ItemType items[DEFAULT_BAG_SIZE]; // array of bag items
	int itemCount;                    // current count of bag items 
	int maxItems;                     // max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	/**
	 * Default constructor (default size is DEFAULT_BAG_SIZE)
	 * @pre Bag does not exist
	 * @post the Bag is initialized to hold DEFAULT_BAG_SIZE items
	 */
	Bag();

	/**
	 * Retrieve the number of items in the bad
	 * @return number of items in the bag
	 */
	int getCurrentSize() const;

	/**
	 * Determine if the bag is empty
	 * @return true if there is at least one item in the bag, false otherwise
	 */
	bool isEmpty() const;

	/**
	 * adds an item to the bag
	 * @param newEntry - the item to add to the bag
	 * @return true if the item was added, false otherwise
	 */ 
	bool add(const ItemType& newEntry);

	/**
	 * remove an item from the bag
	 * @param anEntry - the item to remove from the bag
	 * @return true if the item is removed from the bag, false otherwise
	 */ 
	bool remove(const ItemType& anEntry);

	/**
	 * remove all items from the bag
	 */
	void clear();

	/**
	 * determine if at least one instance of an item is in the bag
	 * @param anEntry - the item to determine if in the bag
	 * @return true if at least one instance of the item is in the bag, false otherwise
	 */
	bool contains(const ItemType& anEntry) const;

	/**
	 * the number of instances of a given item
	 * @param anEntry - the item for which the frequency is sought
	 * @return the number of instances of the item in the bag
	 */
	int getFrequencyOf(const ItemType& anEntry) const;

	/**
	 * provide the bag items in a vector format
	 * @return a vector of the items in the bag
	 */
    std::vector<ItemType> toVector() const;
};  // end Bag

#include "Bag.cpp"

#endif
