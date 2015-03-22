//Amelie Cameron Assignment 4
// This program reads in 5 cards (values 2-9, no face cards/suits) then analyzes and prints out the hand they represent

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int size = 5;

bool containsPair(int hand[]);
bool containsTwoPair(int hand[]);
bool containsThreeOfaKind(int hand[]);
bool containsStraight(int hand[]);
bool containsFullHouse(int hand[]);
bool containsFourOfaKind(int hand[]);

bool containsPair(int hand[])
{

  for(int i=0; i< size -1; i++)
    {
      if(hand[i] == hand[i+1])
	{
	  return true;
	}
    }
  return false;
}


bool containsTwoPair(int hand[])
{
  int numPair = 0;
  int i = 0;
  while(i < (size - 1))
    {
      if(hand[i] == hand[i+1])
	{
	  numPair += 1;
	  i += 2;
	  if(numPair ==2)
	    {
	      return true;
	    }
	  continue;
	}
      i++;
    }
  return false;
}


bool containsThreeOfaKind(int hand[])
{
  for(int i=0; i< size -2; i++)
    {
      if((hand[i] == hand[i+1]) && (hand[i] == hand[i+2]))
	{
	  return true;
	}
    }
  return false;
}


bool containsStraight(int hand[])
{
  for(int i=0; i< size-1; i++) 
    {
      if(hand[i] != (hand[i+1]-1)) 
	{
	  return false;
	}
    }
  return true;
}


bool containsFullHouse(int hand[])
{

  bool hasTriple = false;
  bool hasDouble = false;
  int i = 0;
  while(i < (size - 1))
    {
      if((hand[i] == hand[i+1]) && (hand[i] == hand[i+2]) && hasTriple == false)
	{
	  hasTriple = true;
	  i += 3;
	  continue;
	}
      if(hand[i] == hand[i+1])
	{
	  hasDouble = true;
	  i += 2;
	}
     
      if((hasDouble) && (hasTriple))
	{
	  return true;
	}
      i++;
    }

  return false;
} 


bool containsFourOfaKind(int hand[])
{
  for(int i=0; i< size -3; i++)
    {
      if((hand[i] == hand[i+1]) && (hand[i] == hand[i+2]) && (hand[i] == hand[i+3]))
	{
	  return true;
	}
    }
  return false;
}


int main() {

  int card_1, card_2, card_3, card_4, card_5;
  
  cout << "Enter 5 numeric cards, no face cards. Use 2 - 9." << endl;
  cin >> card_1;
  cin >> card_2;
  cin >> card_3;
  cin >> card_4;
  cin >> card_5;
  
  int hand[] = {card_1, card_2, card_3, card_4, card_5};

    sort(hand, hand + size);
    
   if((hand[0] < 2) || (hand[4] > 9))
      {
	cout << "The card values are out of range (2-9 only)" << endl;
	return 1;
      } 

   if (containsFourOfaKind(hand)) 
    {
      cout << "Four of a Kind" << endl;
    }
    else if (containsFullHouse(hand))
    {
      cout << "Full House" << endl;
    }
    else if (containsStraight(hand))
    {
      cout << "Straight" << endl;
    }
    else if (containsThreeOfaKind(hand))
    {
      cout << "Three of a Kind" << endl;
    }
    else if (containsTwoPair(hand))
    {
      cout << "Two Pairs" << endl;
    }
    else if (containsPair(hand))
    {
      cout << "One Pair" << endl;
    }
    else
    {
      cout << "High Card" << endl;
    }
    return 0;
  }

