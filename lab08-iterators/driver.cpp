/**
 * CSCI232 Data Structures and Algorithms
 * 
 * Lab08 - Iterators
 * 
 * Main Driver
 * 
 * Phillip J. Curtiss, Associate Professor
 * pcurtiss@mtech.edu, 406-496-4807
 * Department of Computer Science, Montana Tech
 */
 
/*
 * Modified by: Brandon Mitchell
 * Description: A file full of people I need to get presents for is opened and
 *              LinkedLists are filled fill that info.  Using C++ iterators,
 *              I iterate over them to print out information and construct a 
 *              shopping list.
 *
 *              Also, gitlab messes up the formatting real bad sometimes.  I 
 *              don't know if my editor is doing something weird and gitlab is
 *              putting in extra tabs because of it.
 */

#include <memory>       // smart pointers
#include <algorithm>    // builtin iterator functions for_each
#include <iostream>     // for cout
#include <fstream>      // for file I/O

#include "LinkedListwIterator.h"

// #define makes it a const char *, which may cause problems
const std::string FILE_NAME = "giftlist.txt";

using std::cout;
using std::endl;
using std::string;

struct ListEntry 
{
    string name;
    string gift;
};

// Needed for find function
bool operator == (const ListEntry & left, const ListEntry & right)
{
	return left.name == right.name && left.gift == right.gift;
}

// Display the people and their gifts
void displayEntry(ListEntry entry) 
{
    cout << entry.name << " will receive " << entry.gift << endl;
}

struct GiftEntry 
{
    string gift;
    int count;
};

// For seeing if we need to add something to our shopping list, don't bother
// comparing count as that doesn't matter in this case
bool operator == (const GiftEntry & left, const GiftEntry & right)
{
	return left.gift == right.gift;
}

// For displaying the shopping list
void displayGift(GiftEntry gift)
{
	std::cout << gift.gift << ", Total: " << gift.count << std::endl;
}

int main() {
    auto naughty = std::make_shared<LinkedListwIterator<ListEntry> >();
    auto nice = std::make_shared<LinkedListwIterator<ListEntry> >();
    auto gifts = std::make_shared<LinkedListwIterator<std::string> >();

	auto shopList = std::make_shared<LinkedListwIterator<GiftEntry>>();
	
    // Open the file for reading
	std::ifstream inFile(FILE_NAME);
	
	// Make sure the file has opened without errors
	if (inFile.is_open())
	{
		// Which list they will go into and then their name and gift
		bool wasNice;
		std::string name, gift;
		
		// While we can still keep reading input ...
		while (inFile >> wasNice >> name)
		{
			// inFile.cur is at the space after the name, advance one so
			// when the gift is read in, there won't be an extra space
			inFile.seekg(1, inFile.cur);
			std::getline(inFile, gift);
			
			if (wasNice)
			{
				// Order doesn't really matter, does it?
				nice->insert(1, ListEntry{name, gift});
			}
			else
			{
				naughty->insert(1, ListEntry{name, gift});
			}
			
			// Save all gifts to list of gifts, iterate through later to make
			// our shopping list
			gifts->insert(1, gift);
		}
		
		inFile.close();
	}
	
	std::cout << "The nice list!!!\n";
	
    // Not as clean as just using a normal function that can be easily 
	// reused, but lambdas are cool.  I've used them in Python a lot, but
	// they are much more limited there (no conditionals, assignment. etc.)
	// Python also has a map function which is like for_each
	for_each(nice->begin(), nice->end(), [nice](ListEntry entry) 
	{
		// Get the ListIterator
		auto target = find(nice->begin(), nice->end(), entry);
		
		// Find the ListIterator's distance from list's beginning
		auto dist = distance(nice->begin(), target);
		
		// Display distance and then entry
		std::cout << "Distance: " << dist << " ";
		displayEntry(entry);
	});
	
	std::cout << "\nThe naughty list!!!\n";
	for_each(naughty->begin(), naughty->end(), [naughty](ListEntry entry) 
	{
		// Get the ListIterator		
		auto target = find(naughty->begin(), naughty->end(), entry);
		
		// Find the ListIterator's distance from list's beginning		
		auto dist = distance(naughty->begin(), target);
	
		// Display distance and then entry
		std::cout << "Distance: " << dist << " ";
		displayEntry(entry);
	});
	
	for_each(gifts->begin(), gifts->end(), [gifts, shopList](std::string gift)
	{
		// Get the count of the gift
		auto total = count(gifts->begin(), gifts->end(), gift);
		
		// Make an entry for the gift
		GiftEntry giftEntry{gift, (int) total};
		
		// If we haven't encountered the entry before, find returns the end of
		// the iterator, so we then know to add it to our shopping list
		if (find(shopList->begin(), shopList->end(), giftEntry) == shopList->end())
		{
			shopList->insert(1, giftEntry);
		}
	});
	
	std::cout << "\nMy shopping list!!!\n";
	for_each(shopList->begin(), shopList->end(), displayGift);
    
    return 0;
}