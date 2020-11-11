/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - MinMaxBinaryHeap
 * 
 * TreeNode Class
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Changed class to support a right and left node.  I misread the
 *              the assignment and thought we had to do a pointer based tree, 
 *              so this was far more difficult that it should have been.  Also
 *              added getters and setters for the left and right pointers.
 */

#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

using std::shared_ptr;

template<class ItemType>
class TreeNode
{
	private:
	
		ItemType item; // A data item
		shared_ptr<TreeNode<ItemType>> left, right; // Pointer to left, right node
   
	public:
	
		TreeNode();
		TreeNode(const ItemType& anItem);
		TreeNode(const ItemType& anItem, shared_ptr<TreeNode<ItemType>> left,
			shared_ptr<TreeNode<ItemType>> right);
			
		void setItem(const ItemType& anItem);
		ItemType getItem() const;
		
		void setLeft(shared_ptr<TreeNode<ItemType>> newLeft);
		shared_ptr<TreeNode<ItemType>> getLeft() const;
		
		void setRight(shared_ptr<TreeNode<ItemType>> newRight);
		shared_ptr<TreeNode<ItemType>> getRight() const;		

}; // end Node

#include "TreeNode.cpp"
#endif