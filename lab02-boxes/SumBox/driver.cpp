/** Driver for SumBox
 * 
 * CSCI 232 Data Structures and Algorithms
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: Added a setColor method to ToyBox and also implemented the
 *              setItem of SumBox.
 */
  
#include <iostream>
#include <string>

// Compiler needs the declaration of the SumBox object
#include "SumBox.h"

using std::string;
using std::cout;
using std::endl;

// Print out the balance of the SumBox and the Box color
// @param _sumBox the Box from which to obtain the item and color
void outputBalance(const SumBox& _sumBox)
{
    // string array of valid colors for the Box
    string validColors[2] = {"BLACK", "RED"};

    // get the balance from the Box item
    int balance = _sumBox.getItem();

    // get the current Box color
    Color boxColor = _sumBox.getColor();

    // output the Balance and Box color
    cout << "Balance: " << balance;
    cout << " (" << validColors[boxColor] << ")" << endl;
} // end outputBalance

// Main entry point for the program
int main()
{
   // create a SumBox in the stack
   SumBox pettyCash; // balance should be zero

   // set initial balance
   pettyCash.setItem(-3);
   
   // output current balance and Box color
   outputBalance(pettyCash);

   // a few more transactions
   pettyCash.setItem(23);
   pettyCash.setItem(14);
   pettyCash.setItem(25);

   // output current balance and Box color
   outputBalance(pettyCash);

   // some more transactions
   pettyCash.setItem(-34);
   pettyCash.setItem(5);
   pettyCash.setItem(-23);
   pettyCash.setItem(-12);

   // The following code will not compile if the setColor method in 
   // ToyBox.h is implement with access protected as opposed to public
   // If public access, then the following is possible and we would exceed
   // the color[] string above!
   //pettyCash.setColor(BLUE);

   // output current balance and Box color
   outputBalance(pettyCash);

   return 0;
} // end main
