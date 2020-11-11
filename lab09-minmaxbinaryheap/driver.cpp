/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - MinMaxBinaryHeap
 * 
 * Driver Program
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Added in the requested tests.
 */

#include <memory>       // smart pointers
#include <algorithm>    // builtin iterator functions for_each
#include <iostream>     // for cout

#include "MinMaxBinaryHeap.h"

using std::cout;
using std::endl;
using std::string;

int main() 
{
    auto minHeapPtr = std::make_shared<MinMaxBinaryHeap<int>>();
    auto maxHeapPtr = std::make_shared<MinMaxBinaryHeap<int>>(false);
    
    // test and display the result of the isEmpty method n both heaps
    std::cout << "Method isEmpty() returns " << minHeapPtr->isEmpty() << " on "
                 "the min heap (should be 1)\nMethod isEmpty() returns " << 
                 maxHeapPtr->isEmpty() << " on the max heap (should be 1)\nIn "
                 "other words, both are initially empty\n";
                
    // insert the following integers into both heaps, in the order provided
    // 10, 20, 30, 40, 50, 2
    std::cout << "\nAdding the values {10, 20, 30, 40, 50, 2} in that order "
                 "to both Min and Max heaps\n";
    for (unsigned int num : {10, 20, 30, 40, 50, 2})
    {
        minHeapPtr->add(num);
        maxHeapPtr->add(num);
    }

    // test and display the result of the isEmpty method n both heaps
    std::cout << "\nNow, let's check if the heaps are empty\n";
    std::cout << "Method isEmpty() returns " << minHeapPtr->isEmpty() << " on "
                 "the min heap (should be 0)\nMethod isEmpty() returns " << 
                 maxHeapPtr->isEmpty() << " on the max heap (should be 0)\n";

    // display the heap contents of each heap with the toString() method
    std::cout << "\nDisplay heaps using toString() in preorder, note first "
                 "number is root\nMin: " << minHeapPtr->toString() << "\nMax: "
              << maxHeapPtr->toString() << "\n";
    
    // remove and display the min/max value of the heap from the corresponding
    // heap and display to the user
    std::cout << "\nRemove and display the min/max value of the heaps, i.e., "
                 "the root value\nMin: " << minHeapPtr->remove() << "\nMax: "
              << maxHeapPtr->remove() << "\n";

    // insert the integer 32 into both heaps
    std::cout << "\nInsert 32 into both heaps\n";
    minHeapPtr->add(32);
    maxHeapPtr->add(32);

    // display the heap contents of each heap with the toString() method
    std::cout << "\nDisplay heaps using toString() in preorder, note first "
                 "number is root\nMin: " << minHeapPtr->toString() << "\nMax: "
              << maxHeapPtr->toString() << "\n";  
}