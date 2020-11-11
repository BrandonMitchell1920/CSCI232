/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab09 - MinMaxBinaryHeap
 * 
 * TreeNode Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Implementation of TreeNode and its methods and new methods I 
 *              added.
 */

#ifndef TREENODE_IMP
#define TREENODE_IMP

#include <cstddef>

#include "TreeNode.h"

using std::shared_ptr;

template<class ItemType>
TreeNode<ItemType>::TreeNode() : left(nullptr), right(nullptr)
{
} // end default constructor

template<class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& anItem) : item(anItem), 
    left(nullptr), right(nullptr)
{
} // end constructor

template<class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& anItem, 
	shared_ptr<TreeNode<ItemType>> left,
	shared_ptr<TreeNode<ItemType>> right) : left(left), right(right) {}
// end constructor

template<class ItemType>
void TreeNode<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
} // end setItem

template<class ItemType>
ItemType TreeNode<ItemType>::getItem() const
{
	return item;
} // end getItem

template<class ItemType>
void TreeNode<ItemType>::setLeft(shared_ptr<TreeNode<ItemType>> newLeft)
{
	left = newLeft;
} // end setLeft

template<class ItemType>
shared_ptr<TreeNode<ItemType>> TreeNode<ItemType>::getLeft() const
{
	return left;
} // end getLeft

template<class ItemType>
void TreeNode<ItemType>::setRight(shared_ptr<TreeNode<ItemType>> newRight)
{
	right = newRight;
} // end setRight

template<class ItemType>
shared_ptr<TreeNode<ItemType>> TreeNode<ItemType>::getRight() const
{
	return right;
} // end getRight

#endif