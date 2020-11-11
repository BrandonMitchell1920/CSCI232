/*
 * Name:    Brandon Mitchell
 * Description: Implentation of MinMaxBinaryHeap.  Code for bubbleUp and 
 *              bubbleDown calls parent's version if min, else uses its own if
 *              max.
 */
 
#ifndef MIN_MAX_BINARY_HEAP_IMP
#define MIN_MAX_BINARY_HEAP_IMP

#include "MinMaxBinaryHeap.h"

template<class ItemType>
void MinMaxBinaryHeap<ItemType>::bubbleDown()
{    
    // If it is a min heap, call parent method, else perform same thing, but 
    // with a different conditional
	if (isMinHeap) {BinaryHeap<ItemType>::bubbleDown();}
    else
    {
        // Reference to root
        std::shared_ptr<TreeNode<ItemType>> cur = this->root;
        bool done = false;
        
        while (!done)
        {
            // Get current node's children, and set largest to cur
            std::shared_ptr<TreeNode<ItemType>>
                left = cur->getLeft(),
                right = cur->getRight(),
                largest = cur;        
            
            // Change largest to which child is larger and swap and move down 
            // the tree as needed until it has settled
            if (left != nullptr && left->getItem() > largest->getItem())
            {
                largest = left;
            }
            if (right != nullptr && right->getItem() > largest->getItem())
            {
                largest = right;
            }
            if (largest != cur)
            {
                // Swap items, moving larger values down the tree
                ItemType temp = cur->getItem();
                cur->setItem(largest->getItem());
                largest->setItem(temp);
                
                // Now compare the largest child's children
                cur = largest;
            }
            else {done = true;}
        }
    }
}

// Either calls parent's bubbleUp, or uses its own version with a greater than
// conditional instead, probably could reuse part of the code in a function
template<class ItemType>
void MinMaxBinaryHeap<ItemType>::bubbleUp()
{
    // If it is a min heap, call parent method, else perform same thing, but 
    // with a different conditional
	if (isMinHeap) {BinaryHeap<ItemType>::bubbleUp();}
    else
    {
        // Used to find node in question
        unsigned int start = 0;
        std::string path = std::bitset<32>(this->nodeCount).to_string();
        while (path[start] != '1' && ++start) {}
            
        // I figured I would just follow the tree back to the node I added, 
        // appending each parent-child node pair on a vector that can then be
        // used to bubble up.  I figured this was way simplier than any recursive
        // solution.
        std::vector<std::shared_ptr<TreeNode<ItemType>>> nodes;
        std::shared_ptr<TreeNode<ItemType>> cur = this->root;
        nodes.push_back(cur);
            
        while (++start < path.length())
        {        
            // Check left side
            if (path[start] == '0')
            {
                cur = cur->getLeft();
            }
            
            // Check right side
            else if (path[start] == '1')
            {
                cur = cur->getRight();
            }
            
            // Add each node to vector
            nodes.push_back(cur);
        }
            
        // Indices into vector of nodes leading to the new node
        signed int child = nodes.size() - 1, parent = child - 1;
        ItemType childItem, parentItem;
        
        // Very similar to bubble up with an array since I am pretty much using 
        // an array that only contains the nodes I need
        while (child >= 0 && parent >= 0 && (childItem = 
            nodes[child]->getItem()) > (parentItem = nodes[parent]->getItem()))
        {
            // Swap items and set child to parent and parent to its parent
            nodes[child]->setItem(parentItem);
            nodes[parent]->setItem(childItem);
            child = parent--;
        }
    }
}

// Default parameter, creates a min heap
template<class ItemType>
MinMaxBinaryHeap<ItemType>::MinMaxBinaryHeap() : isMinHeap(true) {}

// Parameterized constructor, takes a bool to determine if min or max heap
template<class ItemType>
MinMaxBinaryHeap<ItemType>::MinMaxBinaryHeap(bool isMinHeap) 
    : isMinHeap(isMinHeap) {}

#endif