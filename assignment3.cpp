// Assignment 3 Amelie Cameron
// This program figures out a number chosen by a human user.
// The user thinks of a number between 1 and 100. The program guesses using binary search. The user will say if higher, lower, or correct.
 

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
using namespace std;

char getUserResponseToGuess(int guess) {
  char find;
  cout << "Is your number " << guess <<" ? (h / c / l):" << endl;
  cin >> find;
  return find;
}
 
int getMidpoint(int min, int max) {
  return (min + max) / 2;
}

int getRandomMidpoint(int min, int max) {
  int randomMidpoint = rand() % (max - min - 1) + 1;
  return min + randomMidpoint; 
}

bool shouldPlayAgain() {
  char answer;
  cout << "Would you like to play again? (y / n): " << endl;
  cin >> answer;
  
  if(answer == 'y') {
    return true; }
  else {
    cout << "That was fun! Goodbye." << endl;
    return false; }
}

int binary_search(int arr[], int imin, int imax) 
{
  int imid = getRandomMidpoint(imin, imax);
  // imid is the guess
  char find = getUserResponseToGuess(imid);
 
 if(find == 'l')
   return binary_search(arr, imin, imid-1);
 else if(find == 'h')
   return binary_search(arr, imid+1, imax);
 else if(find == 'c') {
   cout << imid <<" is the correct number!" << endl;
   return imid;
 } else {
   cout << "That character was not recognized." << endl;
   return -1;
 }
}

void playOneGame() {
  int arr[100];
  cout << "Choose a number between 1 and 100" << endl;
  cout << "I'll guess, please respond h for higher, l for lower, or c for correct" << endl;
  binary_search(arr,0, 99);
}

int main() {

  do {
    playOneGame();
  } while(shouldPlayAgain());
  
  return 0;
}
