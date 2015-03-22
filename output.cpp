#include <iostream>
using namespace std;

const int LENGTH = 21;
char message [LENGTH];

int main() 

  cout << "Enter a sentence on the line below." << endl;
  int i = 0;

do{
    cin >> message [i];
    ++i;
  }

 while(i < LENGTH - 1 && message [i] != '\n');

message [i] = '\0';

cout << message << endl;
