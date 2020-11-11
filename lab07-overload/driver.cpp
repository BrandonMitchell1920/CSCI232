/**
 * CSCI 232 Data Structures and Algorithms
 * 
 * Lab07 Operator Overloading
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <iostream>
#include <string>

#include "LinkedList.h" // ADT list operations
#include "RegularPolygon.h"

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;

void displayList(shared_ptr<ListInterface<string> > listPtr)
{
    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        cout << listPtr->getEntry(pos) << " ";
    } // end for
	cout << endl;
}  // end displayList

int main()
{
    std::cout << "Testing the RegularPolygon class!!!\nFirst, create two "
                 "RegularPolygon instances, a triangle and a square!  "
                 "\nWarning: you must give a LinkedList<Coord2D> that forms a "
                 "regular polygon or an error will be thrown!\n";
    
    shared_ptr<LinkedList<Coord2D>> 
        squareL = std::make_shared<LinkedList<Coord2D>>(),
        triangleL = std::make_shared<LinkedList<Coord2D>>();
        
    squareL->insert(1, Coord2D(0, 0));
    squareL->insert(2, Coord2D(0, 1));
    squareL->insert(3, Coord2D(1, 1));
    squareL->insert(4, Coord2D(1, 0));
    
    triangleL->insert(1, Coord2D(2, 1));
    triangleL->insert(2, Coord2D(4.5, 5.33012701892));
    triangleL->insert(3, Coord2D(7, 1));
    
    RegularPolygon square(squareL), triangle(triangleL);
    
    std::cout << "\nAll right, a square and triangle have been created!\n"
                 "Let's use the overloaded << operator to take a peek at "
                 "their coords!\nNote: I overloaded the << operator for the "
                 "Coord2D class, so << on a RegularPolygon calls << on it's "
                 "LinkedList member variable.\n\n";
        
    std::cout << "The square!\n\n" << square;
    
    std::cout << "\nThe triangle!\n\n" << triangle;
        
    std::cout << "\nNow that we know their coordinates, lets get some basic "
                 "info about these two polygons!\n\n";
                 
    std::cout << "The square has ...\nArea:\t\t" << square.area() 
              << "\nPerimeter:\t" << square.perimeter() << "\nSide length:\t"
              << square.sideLength() << "\nRadius:\t\t" << square.getRadius()
              << "\nCenter:\t\t" << square.getCenter();

    std::cout << "\n\nThe triangle has ...\nArea:\t\t" << triangle.area() 
              << "\nPerimeter:\t" << triangle.perimeter() << "\nSide length:\t"
              << triangle.sideLength() << "\nRadius:\t\t" << triangle.getRadius()
              << "\nCenter:\t\t" << triangle.getCenter();

    std::cout << "\n\nLet's test the + operator!  The areas of the two "
                 "polygons will be added together!\nThe combined area is "
              << square + triangle << " (should be 11.8253).\n";
              
    std::cout << "\nLet's test the add function by adding three points to the "
                 "Triangle!\nPolygon should resize and change its radius to "
                 "accommodate the new point farthest away.\n";
                 
    std::shared_ptr<LinkedList<Coord2D>> 
        hexagon = std::make_shared<LinkedList<Coord2D>>();
        
    hexagon->insert(1, Coord2D(3, 3));
    hexagon->insert(2, Coord2D(9, 9));
    hexagon->insert(3, Coord2D(0, -0.0000231));
    
    std::cout << "The points being added are ...\n" << * hexagon;
    
    triangle.add(hexagon);
    
    std::cout << "\nThe triangle is now a hexagon!  Its coords are ...\n\n"
              << triangle << "\nNote the coord with the greatest distance "
                 "from center is now first.  This is because it is used as a "
                 "reference from which the rest of the polygon is created.  "
                 "As such, the polygon will shrink or expand depending upon "
                 "which point is furthest from the center.\n"
                 "Let's also view some information about the poly!";
                 
    std::cout << "\n\nThe hexagon has ...\nArea:\t\t" << triangle.area() 
              << "\nPerimeter:\t" << triangle.perimeter() << "\nSide length:\t"
              << triangle.sideLength() << "\nRadius:\t\t" << triangle.getRadius()
              << "\nCenter:\t\t" << triangle.getCenter() << "\n\nNote: if you "
                 "graph the points and a circle based at its center with its "
                 "radius, the circle should intersect all points!\n\nLet's "
                 "now test the remove function and turn this hexagon into a "
                 "squareagon!\n";
                 
    hexagon->clear();
    hexagon->insert(1, Coord2D(9, 9));
    hexagon->insert(2, Coord2D(0, -4.11325));
    hexagon->insert(3, Coord2D(-9999, 9999));
    
    std::cout << "The points to be removed are ...\n" << * hexagon << "\nNote "
                 "the second point is actually at -8.02955e-16, but I simply "
                 "check that the difference between two points is very small "
                 "to determine equality, so 0 is close enough.\nAlso, the "
                 "third point is not in the hexagon, so it won't be removed.\n"
                 "Finally, removing points does not change the radius as all "
                 "points maintain their distance from center; there is "
                 "nothing to base a change in radius off of.\n\n";
                 
    triangle.remove(hexagon);
    
    std::cout << "The hexagon is now a square!  Its coords are ...\n\n"
              << triangle << "\nAnd its other stats are ...\nArea:\t\t" 
              << triangle.area() << "\nPerimeter:\t" << triangle.perimeter() 
              << "\nSide length:\t" << triangle.sideLength() << "\nRadius:\t\t" 
              << triangle.getRadius() << "\nCenter:\t\t" << triangle.getCenter();
                 
    std::cout << "\n\nNote that (9, 9) was first, but it was removed, making "
                 "(1.0718, 9.6188) the first in the list.  It is still the "
                 "first after rearranging because the first point in the list "
                 "is used as a reference to build the rest of the polygon, "
                 "whether points are being removed or added!\n\n";
                
    // I removed the other tests since they weren't for the polygons!
    
    return 0;
}   // end main