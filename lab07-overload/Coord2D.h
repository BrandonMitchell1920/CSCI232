/*
 * Name:    Brandon Mitchell
 * Description: Class that represents a point in the 2D place.  Holds an x and
 *              y as a double, and has a few methods for determing angles or
 *              distances between two Coord2Ds.  Added a few extra methods.
 */

#pragma once

// Saw this back in CSCI135, possibility for distances to be very close, but
// slightly off due to floating point math stuff, use in comparisons.
// If I make it too small, my Coord2D == doesn't work for some reason
// but making it larger looses accuracy! :(
#define EPSILON 0.0001

#define PI 3.14159265358979323846264338327950288419716939937510582

#include <cmath>
#include <iostream>
#include <memory>
  
class Coord2D
{
	private:
		
		double x, y;
		
        // So RegularPolygon has direct access to private members
		friend class RegularPolygon;
		
	public:
	
		Coord2D();
		Coord2D(double x, double y);
        
        // Methods for determing distances and angles between points
        double dist(const Coord2D & other) const;
        double angle(const Coord2D & pointOne, const Coord2D & pointTwo) const;
        
		double getX() const;
		double getY() const;
		
		void setX(double newX);
		void setY(double newY);
        
        // For comparing two Coord2Ds and printing out Coord2Ds
        bool operator == (const Coord2D & rightSide);
        friend std::ostream & operator << (std::ostream & outStream, 
			const Coord2D & rightSide);
};