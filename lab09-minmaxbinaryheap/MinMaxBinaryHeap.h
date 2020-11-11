/**
 *
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - MinMaxBinaryHeap
 * 
 * MinMaxBinaryHeap Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: A child of the BinaryHeap that can be min (default) or max 
 *              (by passing in false).  Will call BinaryHeap's bubbleUp or
 *              bubbleDown if min, else do exact same code as those functions,
 *              but with a flipped conditional.
 */

#ifndef MINMAXBINARYHEAP_H
#define MINMAXBINARYHEAP_H

#include <memory>

#include "TreeNode.h"
#include "BinaryHeap.h"

using std::shared_ptr;

template<class ItemType>
class MinMaxBinaryHeap : public BinaryHeap<ItemType>
{
    private:
        
        bool isMinHeap;
        
    protected:
        // Overrides the BinaryHeap method 
        // if heap is min-heap, perform the same bubbleDown as parent class
        // if heap is max-heap, bubble down root element to correct place 
        // in the heap such that the heap maintains the max-heap order property
        void bubbleDown();

        // Overrides the BinaryHeap method
        // if heap is min-heap, perform the same bubbleUp as parent class
        // if heap is max-heap, bubble the last inserted value up to the correct
        // place in the heap such that the heap maintains the max-heap order property
        void bubbleUp();

    public:
        // Default constructor - should make a min-heap
        MinMaxBinaryHeap();

        // Constructor
        // make a min-heap if parameter value is true
        // make a max-heap if parameter value is false
        MinMaxBinaryHeap(bool isMinHeap);
};

#include "MinMaxBinaryHeap.cpp"
#endif