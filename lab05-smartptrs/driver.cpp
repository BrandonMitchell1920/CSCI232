/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Linked List Smart Pointer Driver 
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */

#include <iostream>
#include <string>
#include <memory>

// List ADT Operations
#include "LinkedList.h"

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;

template <typename AnyType>
void displayList(shared_ptr<ListInterface<AnyType> > listPtr)
{
   cout << "The list contains " << endl;
   for (int pos = 1; pos <= listPtr->getLength(); ++pos)
   {
      try
      {
         cout << listPtr->getEntry(pos) << " ";
      }
      catch(PrecondViolatedExcep& except)
      {
         cout << "Exception thrown getting entry inserted at position " << pos << endl;
         cout << except.what() << endl;
      }
   } // end for
   cout << endl;
}  // end displayList

void copyConstructorTester()
{
   // need to create a LinkedList<ItemType> pointer so,
   // when dereferenced, points to a LinkedList object for
   // copy constructor
	auto list = make_shared<LinkedList<string> >();

   // This pointer is of the correct type to pass into
   // the generic displayList function and points to the
   // same instance of the LinkedList<ItemType> pointed
   // top by the list pointer above
   shared_ptr<ListInterface<string> > ILPtr = list;
	
	string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; ++i)
   {
		cout << "Adding " << items[i] << endl;
      bool success = list->insert(1, items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the list." << endl;
	}

	displayList(ILPtr);

	shared_ptr<ListInterface<string> > copyOfList = make_shared<LinkedList<string> >(*list);
   cout << "Copy of list: ";
	displayList(copyOfList);
   
   cout << "The copied list: ";
	displayList(ILPtr);
}  // end copyConstructorTester

template <typename AnyType>
void listTester(shared_ptr<ListInterface<AnyType> > listPtr)
{
    shared_ptr<LinkedList<AnyType> > llptr = std::dynamic_pointer_cast<LinkedList<AnyType> >(listPtr);

   string data[] = {"one", "two", "three", "four", "five", "six"};
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   for (int i = 0; i < 6; i++)
   {
      if (listPtr->insert(i + 1, data[i]))
      {
         try
         {
            cout << "Inserted " << listPtr->getEntry(i + 1) << " at position " << (i + 1) << endl;
         } catch (PrecondViolatedExcep& except)
         {
            cout << "Exception thrown getting entry inserted at list end!" << endl;
            cout << except.what() << endl;
         }
      }
      else
         cout << "Cannot insert " << data[i] << " at position " << (i + 1) << endl;
   }  // end for
   
   displayList(listPtr);
   
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;
   
   try
   {
      cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
   }
   catch (PrecondViolatedExcep& except)
   {
      cout << "Exception thrown getting entry at position 4!" << endl;
      cout << except.what() << endl;
   }
   cout << "After replacing the entry at position 3 with XXX: ";
   try
   {
      listPtr->replace(3, "XXX");
   }
   catch (PrecondViolatedExcep& except)
   {
      cout << "Exception thrown getting entry at position 3!" << endl;
      cout << except.what() << endl;
   }
   displayList(listPtr);
   
   cout << "remove(2): returns " << listPtr->remove(2) << "; should be 1 (true)" << endl;
   cout << "remove(1): returns " << listPtr->remove(1) << "; should be 1 (true)" << endl;
   cout << "remove(6): returns " << listPtr->remove(6) << "; should be 0 (false)" << endl;
   displayList(listPtr);
   
   cout << "clear: " << endl;
   listPtr->clear();
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   
   try
   {
      cout << "Attempt an illegal retrieval from position 6: " << endl;
      listPtr->getEntry(6);
   }
   catch(PrecondViolatedExcep& e)
   {
      cout << e.what() << endl;
   }  // end try/catch
   
   try
   {
      cout << "Attempt an illegal replacement at position 6: " << endl;
      listPtr->replace(6, "YYY");
   }
   catch(PrecondViolatedExcep& e)
   {
      cout << e.what() << endl;
   }  // end try/catch
   
} // end listTester

template<class ItemType>
void flipList(shared_ptr<ListInterface<ItemType>> listPtr)
{
    cout << "\n\nCreating list for flipping!!!\n\n";
    
    // since swap is method of LinkedList, we need a LinkedList pointer
    // to the same object in memory as the ListInterface pointer
    shared_ptr<LinkedList<ItemType>> llptr = std::dynamic_pointer_cast<LinkedList<ItemType>>(listPtr);

    // borrowed from the above code
    string data[] = {"one", "two", "three", "four", "five", "six", "seven"};
    cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
    for (int i = 0; i < 7; i++)
    {
        if (listPtr->insert(i + 1, data[i]))
        {
            try
            {
                cout << "Inserted " << listPtr->getEntry(i + 1) << " at position " << (i + 1) << endl;
            } 
            catch (PrecondViolatedExcep& except)
            {
                cout << "Exception thrown getting entry inserted at list end!" << endl;
                cout << except.what() << endl;
            }
        }
        else
        {
            cout << "Cannot insert " << data[i] << " at position " << (i + 1) << endl;
        }
    }  // end for
   
    displayList(listPtr);
       
    cout << "\nFlipping list!!!\n\n";

    unsigned int i = 1, j = listPtr->getLength();
    
    // if odd, i == j at during loop so it exits, if odd, even, i > j during 
    // loop so it exits
    while (i < j)
    {
        llptr->swap(listPtr, i++, j--);
    }
    
    displayList(listPtr);
}

void testContains()
{    
    cout << "\nTesting contains() function!!!\n";
    
    shared_ptr<LinkedList<string>> llptr = std::make_shared<LinkedList<string>>();
    cout << "LinkedList().contains(\"item\") returns " 
         << llptr->contains("item") << " (should be 0, false)\n";
    
    llptr = std::make_shared<LinkedList<string>>();
    llptr->insert(1, "item");
    cout << "LinkedList().insert(1, \"item\").contains(\"item\") returns "
         << llptr->contains("item") << " (should be 1, true)\n";
         
    llptr = std::make_shared<LinkedList<string>>();
    llptr->insert(1, "item");
    cout << "LinkedList().insert(1, \"item\").contains(\"differentItem\") "
            "returns " << llptr->contains("differentItem") 
         << " (should be 0, false)\n";
         
    llptr->insert(1, "one");
    llptr->insert(2, "two");
    llptr->insert(3, "three");
    
    cout << "\naLinkedList.contains(item) => aLinkedList, contains() should "
            "not modify the original list.\n";
    displayList(std::dynamic_pointer_cast<ListInterface<string>>(llptr));
    cout << "contains(\"one\") returns " << llptr->contains("one") 
         << " (should be 1, true)\n";
    displayList(std::dynamic_pointer_cast<ListInterface<string>>(llptr));
}

int main()
{
   shared_ptr<ListInterface<string> > listPtr = std::make_shared<LinkedList<string> >();
   listTester(listPtr);
   copyConstructorTester();
   flipList(listPtr);
   testContains();
   return 0;
}  // end main

