#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int getMissingNo(int a[]) {
  vector<int> missing;
  bool there = false;
  for(int i = 1; i <= 10; i++) {
    for(int j = 0; j < 5; j++) {
      if(i == a[j]) {
	there = true;
	break;
      }
    }
    if(there == false)
      missing.push_back(i);
    there = false;
  } 
  cout << "You left out: ";
  for(int i = 0; i < missing.size(); ++i)
    cout << missing[i] << " ";
  cout << endl;
}

int main() {
  int value_1, value_2, value_3, value_4, value_5;
  
  cout << "Please enter 5 values between 1 and 10: ";
  cin >> value_1 >> value_2 >> value_3 >> value_4 >> value_5;
  int a[] = {value_1, value_2, value_3, value_4, value_5};
  getMissingNo(a);
}
