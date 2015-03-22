//Amelie Cameron Assignment 5                                                                                                                                     
//This program takes in baseball league team names and win counts from the user and assigns it to two parallel arrays. Then it sorts the data and outputs the league standings according to win count.                                                                                                                             

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void initializeArrays(string teams[], int wins[], int size)
{
  for(int i=0; i< size; i++)
    {
      cout << "Please enter team name # " << i+1 << ": " << endl;
      cin >> teams[i];

      cout << "Please enter the wins for team # "<< i+1 << ": " << endl;
      cin >> wins[i];
    }
}

void sortData(string teams[], int wins[], int size)
{
  int i;
  int j;
  int max;
                                                                                                                                        
  for(i=0; i < size -1; i++)
    {
      max = i;
                                                                                                                                         
      for(j=i+1; j < size; j++)
        {
          if(wins[j] > wins[max])
	    {
	      max = j;
	    }
        }
      if(max != i)
        {
          swap(wins[i], wins[max]);
          swap(teams[i], teams[max]);
        }
    }
}

void displayData(string teams[], int wins[], int size)
{
  cout << "League Standings: " << endl;
  for(int i=0; i< size; i++)
    {
      cout << teams[i] << ": " << wins[i] << endl;
    }
}

int main()
{
  int size = 5;
  string teams[5];
  int wins[5];

  initializeArrays(teams, wins, size);

  sortData(teams, wins, size);

  displayData(teams, wins, size);

  return 0;
}
