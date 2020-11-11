/** PlainBox - Holds a single item that can be changed
 * Implemented without templates - using typedef for ItemType
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
    
#ifndef PLAIN_BOX_H
#define PLAIN_BOX_H

// Set the type of data stored in the box
typedef double ItemType;

// Declaration for the class PlainBox
// Note - not deriving from BoxInterface; Why?
class PlainBox
{
private:
   // Data field
   ItemType item;
   
public:
   // Default constructor
   PlainBox();
   
   // Parameterized constructor
   PlainBox(const ItemType& theItem);
   
   // Method to change the value of the data field
   void setItem(const ItemType& theItem);
   
   // Method to get the value of the data field
   ItemType getItem() const;
}; // end PlainBox
#endif
