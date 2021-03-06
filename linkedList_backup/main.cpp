//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations

using namespace std;

void displayList(ListInterface<string>* listPtr)
{

   for (int pos = 1; pos <= listPtr->getLength(); pos++)
   {
      cout << listPtr->getEntry(pos) << " ";
   } // end for
	cout << endl << endl;
}  // end displayList

void listTester()
{
  ListInterface<string>* listPtr = new LinkedList<string>();
  cout << "Testing the Link-Based List:" << endl;
  string data[] = {"one", "two", "three", "four", "five", "six"};
  
  cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
  for (int i = 0; i < 6; i++)
    {
      if (listPtr->insert(i + 1, data[i]))
	{
	  cout << "Inserted " << listPtr->getEntry(i + 1)
	       << " at position " << (i + 1) << endl;
	}
      else
	cout << "Cannot insert " << data[i] << " at position " << (i + 1)
	     << endl;
      
    }  // end for
  
  cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
  cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;
  
  cout << "The entry at position 4 is " << listPtr->getEntry(4) << "; should be four" << endl;
  cout << "After replacing the entry at position 3 with XXX: ";
  listPtr->setEntry(3, "XXX");
  displayList(listPtr);
 
  cout << "Removing from Front: " << endl;
  listPtr->remove(1); 
  displayList(listPtr);
  cout << "Removing from Middle: " << endl;
  listPtr->remove(2);
  displayList(listPtr);
   cout << "Removing from End: " << endl;
  listPtr->remove(4);
  displayList(listPtr);

 cout << "Inserting in Front: " << endl;
  listPtr->insert(1, "frontTest");
  displayList(listPtr);
  cout << "Inserting in Middle: " << endl;
  listPtr->insert(2, "middleTest");
  displayList(listPtr);
  cout << "Inserting into End: " << endl;
  listPtr->insert(6, "endTest");
  displayList(listPtr);
 


} // end listTester

void reverseTester()
{
  ListInterface<string>* listPtr2 = new LinkedList<string>();
  cout << "Testing the Reverse Function:" << endl;
  string data2[] = {"apple", "banana", "carrot", "date", "eggplant", "fig"};
  
  for (int i = 0; i < 6; i++)
    {
      if (listPtr2->insert(i + 1, data2[i]))
	{
	  cout << "Inserted " << listPtr2->getEntry(i + 1)
	       << " at position " << (i + 1) << endl;
	}
      else
	cout << "Cannot insert " << data2[i] << " at position " << (i + 1)
	     << endl;
      
    }  // end for
  cout << endl;
  cout << "Original List: " << endl;
  displayList(listPtr2);
  listPtr2->reverse();
  cout << "Reversed List: " << endl;
  displayList(listPtr2);

} // end reverseTester



int main()
{
   listTester();
   cout << endl;
   reverseTester();
   return 0;
}  // end main

/***** EXPECTED OUTPUT WITH CORRECT INSERT FUNCTION
Testing the Link-Based List:
isEmpty: returns 1; should be 1 (true)
Inserted one at position 1
Inserted two at position 2
Inserted three at position 3
Inserted four at position 4
Inserted five at position 5
Inserted six at position 6
The list contains 
one two three four five six 

isEmpty: returns 0; should be 0 (false)
getLength returns : 6; should be 6
The entry at position 4 is four; should be four
After replacing the entry at position 3 with XXX: The list contains 
one two XXX four five six */
