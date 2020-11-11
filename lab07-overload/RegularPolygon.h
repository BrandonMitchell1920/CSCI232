/*
 * Name:    Brandon Mitchell
 * Description: The RegularPolygon class.  It contains a LinkedList of Coord2D
 *              points.  I could have made the RegularPolygon a child of 
 *              LinkedList, but I thought the RegularPolygon was different
 *              enough to warrant its own unique class.  I added a few extra
 *              methods that might be useful to a user of the class, but were
 *              also useful for me when writing other methods.
 */
 
#pragma once

#include "Coord2D.h"
#include "LinkedList.h"
 
class RegularPolygon
{
	private:
	
        // All the Coord2Ds are stored in this
		LinkedList<Coord2D> listOfCoords;
        
        // Needed for various calcuations and to resize the polygon
        double radius;
        
        // Center is constant, needed for resizing polygon
        Coord2D center;
        
        // Moves all points after points have been added or removed
        bool rearrange();

	public:
	
        // Default constructor and parameterized constructor
		RegularPolygon();
		RegularPolygon(const std::shared_ptr<LinkedList<Coord2D>> pointList);
		
        // Add and remove points from LinkedList, rearrange afterwards
		bool add(const std::shared_ptr<LinkedList<Coord2D>> pointList);
		bool remove(const std::shared_ptr<LinkedList<Coord2D>> pointList);
		
        // Functions to get various info about the polygon
		double perimeter() const;
		double area() const;
        double sideLength() const;
        double numSides() const;
        double getRadius() const;
        Coord2D getCenter() const;
		
        // Add two polies together and print out poly
		double operator + (const RegularPolygon & rightSide);
		friend std::ostream & operator << (std::ostream & outStream, 
			const RegularPolygon & rightSide);
};