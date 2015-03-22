//Amelie Cameron Assignment 13 Part 1                                                                          
//This program is a random number guesser which inherits from class NumberGuesser. It randomly selects a number between 1 and 10 and saves the value until a higher or lower function is called, then it changes the boundaries and selects a new random number.                                                                           

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RandomNumberGuesser.h"
using namespace std;


RandomNumberGuesser::RandomNumberGuesser(int l, int h) : NumberGuesser(l, h) {
  reset();
}

int RandomNumberGuesser::getCurrentGuess() {
  return guess;
}

void RandomNumberGuesser::reset() {
  int randomMidpoint = rand() % (high - low - 1) + 1;
  guess = low + randomMidpoint;

}

void RandomNumberGuesser::higher(){
  high = guess + 1;
  reset();
}
void RandomNumberGuesser::lower(){
  low = guess - 1;
  reset();
}

int main()
{
  srand (time(NULL));
  RandomNumberGuesser r(1,10);

  cout << r.getCurrentGuess() << endl;
  cout << r.getCurrentGuess() << endl;
  r.higher();
  cout << r.getCurrentGuess() << endl;
  cout << r.getCurrentGuess() << endl;
  r.lower();
  cout << r.getCurrentGuess() << endl;
  cout << r.getCurrentGuess() << endl;


  return 0;
}


