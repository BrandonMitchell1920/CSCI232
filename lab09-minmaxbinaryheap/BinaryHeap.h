/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - MinMaxBinaryHeap
 * 
 * BinaryHeap Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Declaration of class, added in a few helper functions and an 
 *              extra variable to keep track of number of nodes.  Is pointer-
 *              based, not arraybased, so some things are a bit different.  
 *              Note bubbleUp() and bubbleDown() are now virtual.  This is 
 *              because remove and add is the same for child and pararent, but
 *              the bubbleUp()/bubbleDown() is not necessarily the same.  I 
 *              to stick mostly to the API given. 
 */

#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <memory>	// For shared_ptr
#include <bitset>	// For generating path to node
#include <vector>	// For storing nodes in path to newly added node
#include <string>	// For string stuff

#include "TreeNode.h"
#include "PrecondViolatedExcep.h"

using std::shared_ptr;
using std::string;

template<class ItemType>
class BinaryHeap
{
private:
    
	// Called by toString below, I didn't want to change the API we were
	// given, so I added this parameterized version that is called by the
	// normal one below
    std::string toString(std::shared_ptr<TreeNode<ItemType>> cur);
	
	// Recursively copy tree passed in constructor into this tree
	void fill(std::shared_ptr<TreeNode<ItemType>> cur);
   
protected:

    // Moved to protected so MinMax has access for its bubble up/down
    shared_ptr<TreeNode<ItemType>> root;

    // Keep track of number of nodes, needed to traverse tree
    unsigned int nodeCount;

    // performs a bubble down operation to place the element
    // that is at the root of the heap in the correct place
    // so that the heap maintains the min-heap order property
    
    // I made it and the one below virtual because I need to make sure the 
    // the correct bubble is called depending on which class called it as 
    // MinMax may or may not call this particular version depending on if it is
    // a min heap or a max heap
    virtual void bubbleDown();

    // performs a bubble up operation to place a newly inserted
    // element in its correct place so that the heap maintains 
    // the min-heap order property
    virtual void bubbleUp();

public:
    // Default Constructor - makes an empty Heap
    BinaryHeap();

    // Copy Constructor - makes a new heap from an existing one
    BinaryHeap(shared_ptr<BinaryHeap<ItemType>> aBinaryHeap);

    // adds an item to the Heap
    void add(ItemType anItem);

    // returns and remove the minimum value from the heap
    ItemType remove();

    // returns - but does not remove - the minimum value from the heap
    ItemType peek() const;

    // returns true fo the heap contains no entries
    bool isEmpty();

    // returns a string representation of the BinaryHeap with values
    // stored withing the heap structure and order properties
    string toString();
    
}; // end BinaryHeap

#include "BinaryHeap.cpp"
#endif