//Amelie Cameron Assignment 11
//In this program I added a copy constructor and three overloaded operators( = , == , and << ) to the IntCollection class(a dynamic storage mechanism for storing integers.) 

#include "IntCollection.h"
#include <iostream>
using namespace std;

void print_collection(IntCollection &c)  {
  for(int i = 0; i < c.getSize(); i++)
    {
      cout << c.get(i) << endl;
    }
}

int main() 
{
  IntCollection c;
    
  cout << "Testing insertion operator" << endl;
  c << 45;
  c << -210;
  c << 77;
  c << 102;
  c << -39;

  cout << "IntCollection c : " << endl;
  print_collection(c);

  cout << "Size is " << c.getSize() << endl;
    
  cout << "Testing insertion operator END" << endl;
  cout << endl;
 
  cout << "Testing copy constructor (c to b)" << endl;

  IntCollection b = c;
  
  cout << "IntCollection b : " << endl;
  print_collection(b);

  cout << "Testing copy constructor END" << endl;
  cout << endl;

  cout << "Testing equals operator" << endl;
  cout << "true if c and b are the same, false if different" << endl;

  if(b == c)
    {
      cout << "true" << endl;
    }
  else 
    cout << "false" << endl;

  cout << "Testing equals operator END" << endl;
  cout << endl;

  cout << "Testing assignment operator (c to d)" << endl;

  IntCollection d;
  d = c;
  
  cout << "IntCollection d : " << endl;
  print_collection(d);

  cout << "Testing assignment operator END" << endl;
  cout << endl;
  return 0;

}
