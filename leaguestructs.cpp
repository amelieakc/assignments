//Amelie Cameron Assignment 8
//This program stores pairs of baseball team names and win counts into a sturct named WinRecord. The data is stored in a dynamically allocated array of WinRecord structs. The user determines how many teams they will enter and the data is initialized, sorted and displayed in order.

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;

#define MAX_CHAR_INPUT 50
#define MAX_INT_INPUT 4

struct WinRecord
{
  int wins;
  char* name;
};

void initializeData(WinRecord* standings, int size)
{
  char* winC = new char[MAX_INT_INPUT];
  for(int i = 0; i < size; ++i)
  {
    cout << "Enter team name # " << i+1 << " : " << endl;
    standings[i].name = new char[MAX_CHAR_INPUT];
    cin.getline(standings[i].name, MAX_CHAR_INPUT, '\n');
  
    cout << "Enter team # " << i+1 << "'s win count: " << endl;
    
    cin.getline(winC, MAX_INT_INPUT, '\n');
    standings[i].wins = atoi(winC);
    memset((void*)winC, '0', sizeof(winC));
  }
  delete winC;
}
  
void sortData(WinRecord* standings, int size)
{
  int i;
  int j;
  int max;

  for(i = 0; i < size-1; i++)
    {
      max = i;
      
      for(j = i+1; j < size; j++)
	{
	  if(standings[j].wins > standings[max].wins)
	    {
	      max = j;
	    }
	}
      if(max != i)
	{
	  swap(standings[i].wins, standings[max].wins);
	  swap(standings[i].name, standings[max].name);
	}
    }
}

void displayData(WinRecord* standings, int size)
{
  cout << "Win Record: " << endl;
  
  for(int i = 0; i < size; i++)
    {
      cout << standings[i].name << " : ";
      cout << standings[i].wins << endl;
    }
  cout << endl;

}

int main()
{

  WinRecord* standings = NULL;
  int size;

  cout << "How many baseball teams would you like to enter?: " << endl;
  char *s = new char[MAX_CHAR_INPUT];
  cin.getline(s, MAX_CHAR_INPUT);
  size = atoi(s);
  
  standings = new WinRecord[size];
  
  initializeData(standings, size);
  
  sortData(standings, size);

  displayData(standings, size);   

  for(int i = 0; i < size; ++i) {
    delete standings[i].name;
  }
  
  delete s;
  s = NULL;
  delete standings;
  standings = NULL;

  return 0;
}
