/*
 * Name:    Brandon Mitchell
 * Description: Implementation of the class Coord2D.
 */
 
#include "Coord2D.h"

// Default constructor, initialize to zero
Coord2D::Coord2D() : x(0), y(0) {}

// Create Coord2D with specific x and y
Coord2D::Coord2D(double x, double y) : x(x), y(y) {}

// Calculate distance between two points
double Coord2D::dist(const Coord2D & other) const
{
    // Distance formula
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}

// Calculate angle in radians between three points
double Coord2D::angle(const Coord2D & point2, const Coord2D & point3) const
{
    // point1 is this, the instance that called the function, used for clarity
    // point1 is the vertx of the angle
    double dist12 = this->dist(point2);
    double dist13 = this->dist(point3);
    double dist23 = point2.dist(point3);
    
    // Returns angle in radians
    return std::acos((std::pow(dist12, 2) + std::pow(dist13, 2) - 
                      std::pow(dist23, 2)) / (2 * dist12 * dist13));
}

// Return x
double Coord2D::getX() const {return x;}

// Return y
double Coord2D::getY() const {return y;}

// Change the x value
void Coord2D::setX(double newX) {x = newX;}

// Change the y value
void Coord2D::setY(double newY) {y = newY;}

// Test for equivalancy
bool Coord2D::operator == (const Coord2D & rightSide)
{
    // In case of floating point errors, use this for clarity
    bool xMatch = std::fabs(this->x - rightSide.x) < EPSILON;
    bool yMatch = std::fabs(this->y - rightSide.y) < EPSILON;

    return xMatch && yMatch;
}

// Print out a single Coord2D
std::ostream & operator << (std::ostream & outStream, const Coord2D & rightSide)
{
    return outStream << '(' << rightSide.x << ", " << rightSide.y << ')';
}