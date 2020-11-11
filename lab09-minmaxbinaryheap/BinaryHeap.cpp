/*
 * Name:    Brandon Mitchell
 * Description: Implemented the functions in BinaryHeap.h.  Using a pointer
 *              based heap is a pain.
 */
 
#ifndef BINARY_HEAP_IMP
#define BINARY_HEAP_IMP

#include <string>

#include "BinaryHeap.h"

// Called by other toString, takes an pointer to a node, so each tree can be
// passed in and traversed one by one recursivly
template<class ItemType>
std::string BinaryHeap<ItemType>::toString(std::shared_ptr<TreeNode<ItemType>> 
    cur)
{
    std::string ans = "";
    if (cur != nullptr)
    {
		// I am doing preorder traversal: root, left, right
        ans += std::to_string(cur->getItem()) + " ";
        ans += toString(cur->getLeft());
        ans += toString(cur->getRight());
        return ans;
    }
    else {return ans;}
}

// Used by copy constructor to recursivly traverse tree and fill it up with
// the other tree's values, deep copy
template<class ItemType>
void BinaryHeap<ItemType>::fill(std::shared_ptr<TreeNode<ItemType>> cur)
{
	if (cur != nullptr)
	{
        // Due to how the tree is visited, there should be no movements of
        // items, so it should be in the exact same order as original tree
		add(cur->getItem());
		fill(cur->getLeft());
		fill(cur->getRight());
	}
}

// bubbleDown() is called when an item is removed as removal is really a swap,
// so the root has to be lowered down the tree into its proper place
template<class ItemType>
void BinaryHeap<ItemType>::bubbleDown()
{
	// Reference to root
	std::shared_ptr<TreeNode<ItemType>> cur = root;
    bool done = false;
    
    while (!done)
    {
		// Get current node's children, and set largest to cur
        std::shared_ptr<TreeNode<ItemType>>
            left = cur->getLeft(),
            right = cur->getRight(),
            largest = cur;        
        
		// Change largest to which child is larger and swap and move down the
		// tree as needed until it has settled
        if (left != nullptr && left->getItem() < largest->getItem())
        {
            largest = left;
        }
        if (right != nullptr && right->getItem() < largest->getItem())
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

// When an item is put into the tree, we need to walk upwards to figure out
// where it belongs
template<class ItemType>
void BinaryHeap<ItemType>::bubbleUp()
{
    // Used to find node in question
    unsigned int start = 0;
    std::string path = std::bitset<32>(nodeCount).to_string();
    while (path[start] != '1' && ++start) {}
        
    // I figured I would just follow the tree back to the node I added, 
    // appending each parent-child node pair on a vector that can then be
    // used to bubble up.  I figured this was way simplier than any recursive
	// solution.
    std::vector<std::shared_ptr<TreeNode<ItemType>>> nodes;
    std::shared_ptr<TreeNode<ItemType>> cur = root;
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
    
    // Very similar to bubble up with an array since I am pretty much using an
    // array that only contains the nodes I need
    while (child >= 0 && parent >= 0 && (childItem = nodes[child]->getItem()) < 
        (parentItem = nodes[parent]->getItem()))
    {
		// Swap items and set child to parent and parent to its parent
        nodes[child]->setItem(parentItem);
        nodes[parent]->setItem(childItem);
        child = parent--;
    }
}

// Default constructor, intialize root to nullptr and nodeCount to 0
template<class ItemType>
BinaryHeap<ItemType>::BinaryHeap() : root(nullptr), nodeCount(0) {}

// Parameterized constructor, initalize root to node passed in and set 
// nodecount to zero
template<class ItemType>
BinaryHeap<ItemType>::BinaryHeap(shared_ptr<BinaryHeap<ItemType>> aBinaryHeap)
    : nodeCount(0) 
{
	fill(aBinaryHeap->root);
}

// Adds a node to the tree, keeping it balanced and calling bubbleUp() to 
// ensure min attribute is maintained
template<class ItemType>
void BinaryHeap<ItemType>::add(ItemType anItem)
{
	// Create new node
    std::shared_ptr<TreeNode<ItemType>> 
        newNode = std::make_shared<TreeNode<ItemType>>(anItem);

	// Special case, simply set root to this new node
    if (isEmpty()) 
    {
        root = newNode;
        nodeCount++;
    }
    else
    {
        // Covert nodeCount to bit string that can be used as a path to the 
        // correct spot
        unsigned int start = 0;
        std::string path = std::bitset<32>(++nodeCount).to_string();
        while (path[start] != '1' && ++start) {}
        
		// Start of path
        std::shared_ptr<TreeNode<ItemType>> cur = root;
        
        while (++start < path.length())
        {
			// Move to left node
            if (path[start] == '0')
            {
				// End of path
                if (cur->getLeft() == nullptr)
                {
                    cur->setLeft(newNode);
                }
                else {cur = cur->getLeft();}
            }
			
			// Move to right node
            else if (path[start] == '1')
            {
				// End of path
                if (cur->getRight() == nullptr)
                {
                    cur->setRight(newNode);
                }
                else {cur = cur->getRight();}
            }
        }
        bubbleUp();
    }
}

// Function remove() removes the root of the tree, places the last node in its
// place, and then swaps nodes inorder to preserve min attribute
template<class ItemType>
ItemType BinaryHeap<ItemType>::remove()
{	
	// Throw error if user attempts to remove something from an empty heap
    if (isEmpty()) 
    {
        throw PrecondViolatedExcep("Remove called on an empty heap");
    }
    
	// Get item to return later
    ItemType item = root->getItem(); 
    
	// Special case, simply set root to nullptr, no need to bubbleDown
    if (nodeCount == 1)
    {
        root = nullptr;
        nodeCount--;
    }
    else
    {
		// Used to find path to node that needs to be removed
        unsigned int start = 0;
        std::string path = std::bitset<32>(nodeCount--).to_string();
        while (path[start] != '1' && ++start) {}
        
		// Store nodes in vector to easily reference later, these nodes
		// form a path leading to the node I will swap with the root
        std::vector<std::shared_ptr<TreeNode<ItemType>>> nodes;
        std::shared_ptr<TreeNode<ItemType>> cur = root;
		nodes.push_back(cur);
            
		// While there are still characters in the string to check ...
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
			nodes.push_back(cur);
        }
        
		// Index of last node, node to be swapped, use to find leaf and its
		// parent from the list of nodes leading to it
        signed int index = nodes.size() - 1;
        std::shared_ptr<TreeNode<ItemType>> leaf = nodes[index], prev = 
            nodes[index - 1];
			
		// Swap items, "removing" the root
        root->setItem(leaf->getItem());
        
		// Right nodes are odd, left are even, know leaf is a child of prev,
		// but I don't know which child
        if ((nodeCount + 1) % 2) {prev->setRight(nullptr);}
        else {prev->setLeft(nullptr);}
        leaf = nullptr;

		// Call bubbleDown() to set swapped node in correct location
        bubbleDown();
    }
    
    return item;
}

// Assuming heap is not empty, returns the root item with out removing it
template<class ItemType>
ItemType BinaryHeap<ItemType>::peek() const
{
	if (isEmpty()) 
    {
        throw PrecondViolatedExcep("Peek called on an empty heap");
    }
    return root->getItem(); 
}

// Simply checks if nodeCount is zero or not, nodeCount was added to make
// locating nodes much easier
template<class ItemType>
bool BinaryHeap<ItemType>::isEmpty()
{
	return !nodeCount; 
}

// It calls a function by the same name that takes an argument, this is to 
// make it easier to make it recursive
template<class ItemType>
std::string BinaryHeap<ItemType>::toString()
{
	return toString(root);
}

#endif