/**
 * CSCI232 Data Structures
 * 
 * Box Container Implementation
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

/*
 * Modified by: Brandon Mitchell
 * Description: Provided code for recursive setItem() and getItem() and 
 *              modified the constructor.
 */

#ifndef BOXCONTAINER_IMP
#define BOXCONTAINER_IMP

#include "BoxContainer.h"

template<template<typename> class BoxType, typename ItemType>
BoxContainer<BoxType<ItemType> >::BoxContainer(BoxInterface<ItemType> * aBox)
	: box(aBox) {} // end Constructor

template<template<typename> class BoxType, typename ItemType>
ItemType BoxContainer<BoxType<ItemType> >::getItem() const 
{
    return box->getItem();
} // end getItem

template<template<typename> class BoxType, typename ItemType>
BoxType<ItemType> BoxContainer<BoxType<ItemType> >::getBox() const 
{
    // return the box contained
    return box;
} // end getBox

template<template<typename> class BoxType, typename ItemType>
void BoxContainer<BoxType<ItemType> >::setItem(const ItemType& anItem)
{
    box->setItem(anItem); 
} // end setItem

template<template<typename> class BoxType, typename ItemType> 
void BoxContainer<BoxType<ItemType> >::setBox(BoxInterface<ItemType> * aBox)
{
    // set the box contained
    box = aBox;
} // end setBox

#endif