// Assignment 1: Amelie Cameron 
// This program prints out as many asterisks as the user wants.

#include <iostream>
using namespace std;

int main ()
{
  int count;
  char go_again = 'y';
  while(go_again != 'n')
  {
    cout << "How many asterisks would you like?: ";
    cin >> count;

    for (int i = 0; i < count; i++)
      {
	cout << "*";
      }

    cout << endl;
    cout << "Would you like to go again?: ";
    cin >> go_again;
  }
  return 0;
}
