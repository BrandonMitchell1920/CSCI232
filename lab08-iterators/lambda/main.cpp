/**
 * CSCI232 Data Structures and Algorithms
 *
 * Example of using a lambda expression with c++ algorithms; e.g. for_each
 *
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <cstddef>   // standard definitions 
#include <iostream>  // needed for cout, endl
#include <iomanip>   // output formatting
#include <algorithm> // needed for for_each, find, distance
#include <vector>    // collection class with iterator

using std::cout;
using std::endl;
using std::setw;
using std::internal;
using std::vector;

/**
 * Take an element from the list, the scaling factor,
 * and the element's distance from the start of the list
 * and display them to the output
 */
void displayElement(int element, int scale, int distance)
{
   // using internal to provide an internal representation of numbers
   // use setw to fix the width of the number field
   cout << "Element " << internal << setw(4) << element;
   cout << " scaled " << internal << setw(4) << element*scale;
   cout << " distance from start of list " << internal << setw(4) << distance;
   cout << endl;

   // return when done
   return;
}

/**
 * create a vector of integer and iterate over the list using the 
 * built-in iterator algorithms, and display a few facts for 
 * each element in the vector
 */
int main()
{
   // create a collection of ints in the vector collection class 
   // vector implements an interator class
   vector<int> myInts { 10, 20, 30, 40, 50 };

   // scale factor used to increase each element in myInts
   int a = 5;

   // lambda function for for_each - used to iterator over the collection
   // class whose iterators are given to the for_each() algorithm
   // lambda functions are of the form 
   // [](){ ... }
   // where [] - are the function closure capture set
   //       () - is the normal function parameter list
   //       {} - is the lambda function closure
   auto feFunc = [a, myInts](int iInt) {
	  // use find to locate the an iterator from myInts 
	  auto target = find(myInts.begin(), myInts.end(), iInt);

	  // the distaince of the element from the beginning of the myInts vector
	  auto dist = distance(myInts.begin(), target);

	  // display the element, the element scaled by a, and the distance in 
	  // the vector myInts
	  displayElement(iInt, a, dist);

	  // return when completed
	  return;
	 }; // end of lambda - don't forget the semicolon - it is an assignment!

   // iterate over the myInts vector collection and invoke the 
   // feFunc() lambda expression on each element -- let's do some work !
   for_each(myInts.begin(), myInts.end(), feFunc);

   // return to our caller signalling success
   return EXIT_SUCCESS;
}
