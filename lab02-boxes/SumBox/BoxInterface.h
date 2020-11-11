/** BoxInterface - Operational Contract for Box Types
 * Specifies the methods that must be implements by Box Types
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
#ifndef BOX_INTERFACE_H
#define BOX_INTERFACE_H

// Templated Class allowing item Box holds to be any type
template <class ItemType>
class BoxInterface
{
public:
   // Set the item held in the Box
   virtual void setItem(const ItemType& theItem) = 0;

   // Return the item presently held in the Box
   virtual ItemType getItem() const = 0;

   // Destructor of the Box; Can not be pure virtual
   // but marking virtual allow overriding
   virtual ~BoxInterface() { }
}; // end BoxInterface
#endif
