/*
 * Name:    Brandon Mitchell
 * Description: Implementation of the RegularPolygon class.
 */

#include "RegularPolygon.h"
#include "PrecondViolatedExcep.h"

bool RegularPolygon::rearrange()
{
    // Angle of vetex formed by center to two adjacent Coord2Ds, use to rotate
    double angle = 2 * PI / numSides(), curAngle = angle;
    
    // Use first point in listOfCoords as a reference to rotate other points
    Coord2D refCoord = listOfCoords.getEntry(1);
    
    // Replace Coord2D with new Coord2D
    listOfCoords.replace(1, refCoord);
    
    for (unsigned int i = 2; i <= numSides(); i++)
    {
        Coord2D newCoord;
        
        // Rotate refCoord about immovable center by increasing angle
        newCoord.x = center.x + (refCoord.x - center.x) * std::cos(curAngle) -
            (refCoord.y - center.y) * std::sin(curAngle);
        newCoord.y = center.y + (refCoord.x - center.x) * std::sin(curAngle) +
            (refCoord.y - center.y) * std::cos(curAngle);

		// Could just move the point, but replaing it works fine as well
        listOfCoords.replace(i, newCoord);

        curAngle += angle;
    }
    
    // Not too sure what to base the return on.  I guess I throw an error in
    // the add and remove functions if the polygon is not longer regular or
    // just empty
    return true;
}

// Non-parameterized constructor
RegularPolygon::RegularPolygon() {}

// Parameterized constructor, LinkedList<Coord2D> must form a regular polygon
RegularPolygon::RegularPolygon(const std::shared_ptr<LinkedList<Coord2D>> pointList)
{
	// Get length as I will need it a couple of times
	unsigned int length = pointList->getLength();
	
	// Need three points to form a legal polygon
	bool legalPolygon = length > 2;
	
    // Check all distances
	if (legalPolygon)
	{
		// All dists should be the same, get one to compare, first->last
		double compDist = pointList->getEntry(1).dist(pointList->getEntry(length));
		
		// One less than length as 0->1, 1->2, ..., two needed for dist
		// To be regular, all dists must be the same, or close enough
		for (unsigned int i = 1; i <= length - 1 && legalPolygon; i++)
		{
			// Current point and next point
			double tempDist = pointList->getEntry(i).dist(pointList->getEntry(i + 1));
			
			// EPSILON in case of floating point errors, close enough is good
            // enough
            legalPolygon = std::fabs(compDist - tempDist) < EPSILON;
		}
	}

    // Check all angles only if legalPolygon still true
    if (legalPolygon)
    {
        // Angle of point 1, use point 2 and last point, need for comparison
        double compAngle = pointList->getEntry(1).angle(pointList->getEntry(2), 
            pointList->getEntry(length));
            
        // Angle of last point, need to do this as angle function need three
        // points, put outside of for loop
        double lastAngle = pointList->getEntry(length).angle(pointList->getEntry(length - 1), 
            pointList->getEntry(1));
            
        // Compare two calculated angles before compaing all angles
        legalPolygon = std::fabs(compAngle - lastAngle) < EPSILON;
        
        for (unsigned int i = 2; i <= length - 1 && legalPolygon; i++)
        {
            double tempAngle = pointList->getEntry(i).angle(pointList->getEntry(i - 1), 
                pointList->getEntry(i + 1));
                
            // Angles are close enough, legalPolygon is still true
            legalPolygon = std::fabs(compAngle - tempAngle) < EPSILON;
        }
    }
    
    // If it's a regular polygon, set member variables, else throw expection
    if (legalPolygon)
    {
        listOfCoords = * pointList;

        // Center is average of all points, could just let it be (0, 0) and 
        // move all points as necessary
        for (unsigned int i = 1; i <= length; i++)
        {
            Coord2D tempCoord = listOfCoords.getEntry(i);
            center.x += tempCoord.x;
            center.y += tempCoord.y;
        }
        
        // Center, once set, will never change, polygon expanded or contracted
        // around this center
        center.x /= length;
        center.y /= length;
        
        // If regular polygon, radius is center to any point in polygon
        radius = center.dist(listOfCoords.getEntry(1));
    }
    else
    {
        throw PrecondViolatedExcep("\x1b[41;30mLinkedList of Coord2D points "
                                   "does not form a regular polygon!  Must "
                                   "pass a LinkedList of Coord2D points that "
                                   "form a regular polygon!\x1b[0m");
    }
}

// Add all Coord2D from pointList to our listOfCoords
bool RegularPolygon::add(const std::shared_ptr<LinkedList<Coord2D>> pointList)
{
    // Used default constructor (0 sides) and you aren't inserting enough
    // points in order to make a regular polygon.  Note, center defaults to 
    // (0, 0) 
    if (!numSides() && pointList->getLength() < 3)
    {
        throw PrecondViolatedExcep("\x1b[41;30mIf the default constructor is "
                                   "used, you must provide three or more "
                                   "points in the add() function to make a "
                                   "regular polygon!\x1b[0m");
    }
    
    double tempRadius = 0;
	for (signed int i = 1; i <= pointList->getLength(); i++)
    {
        // Center never moves, but points may be farther out than current 
        // radius, so set radius to the point farest out, expand / contract
        Coord2D tempCoord = pointList->getEntry(i);
        if (center.dist(tempCoord) > tempRadius) 
        {
            tempRadius = center.dist(tempCoord);
            
            // Insert largest first as it will be used as a reference point
            // If I didn't insert it first, I would have to normalize the 
            // vector and change its length to the correct radius
            listOfCoords.insert(1, tempCoord);
        }
        else {listOfCoords.insert(2, tempCoord);}
    }
    radius = tempRadius;

    return rearrange();
}

// Remove all Coord2D in pointList from listOfCoords
bool RegularPolygon::remove(const std::shared_ptr<LinkedList<Coord2D>> pointList)
{    
    // Loop through pointList, comparing each Coord2D to each Coord2D in our
    // listOfCoords, removing if equal
    for (signed int i = 1; i <= pointList->getLength(); i++)
    {
        bool found = false;
        for (signed int j = 1; j <= numSides() && !found; j++)
        {
            // I was having problems with this because my EPSILON was too 
            // small, but it wasn't THAT small, so I don't know why it was 
            // having problems, it works fine now with a larger EPSILON
            found = pointList->getEntry(i) == listOfCoords.getEntry(j);
            if (found) {listOfCoords.remove(j);}
        }
    }
    
    // You removed too many points!  Can't form a regular poly now!
    if (numSides() < 3)
    {
        throw PrecondViolatedExcep("\x1b[41;30mToo many points were removed "
                                   "from the polygon!  Must have at least "
                                   "three points in the poly at all "
                                   "times!\x1b[0m");
    }
        
    
    // Since no points are being added, no point will potentially alter the 
    // radius of the polygon
	return rearrange();
}

// Returns perimeter of the polygon
double RegularPolygon::perimeter() const
{
	return numSides() * sideLength();
}

// Returns the area of the polygon
double RegularPolygon::area() const
{
    return numSides() / 2 * std::pow(radius, 2) * std::sin(2 * PI / numSides());
}

// Returns the length of a side segment
double RegularPolygon::sideLength() const
{
    // Originally had listOfCoords.getEntry(1).dist(listOfCoords.getEntry(2))
    // but this way is independent of the positions of the Coord2Ds
    return 2 * radius * std::sin(PI / numSides());
}

// Returns the number of sides, or the length of the listOfCoords
double RegularPolygon::numSides() const {return listOfCoords.getLength();}

// Returns the radius of the polygon
double RegularPolygon::getRadius() const {return radius;}

// Returns the center incase it would be of any use
Coord2D RegularPolygon::getCenter() const {return center;}

// Returns the sum of the areas of the polygons
double RegularPolygon::operator + (const RegularPolygon & rightSide)
{
	// this for clarity
    return this->area() + rightSide.area();
}

// Used for printing out the listOfCoords, since LinkedList has a method, use
// it, and then define a method for Coord2D so both can be printed out
std::ostream & operator << (std::ostream & outStream, const RegularPolygon & rightSide)
{
	return outStream << rightSide.listOfCoords;
}