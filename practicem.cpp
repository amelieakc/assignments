#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

double sum, average, value_1, value_2, value_3, value_4, value_5;
int mycount, i;
double values[5];

int main() {

  cout << "Enter 5 Double Values: " << endl;
  cin >> value_1;
  cin >> value_2;
  cin >> value_3;
  cin >> value_4;
  cin >> value_5;

double values[5] ={value_1, value_2, value_3, value_4, value_5};

  sum = value_1 + value_2 + value_3 + value_4 + value_5;
  average = sum / 5;

  cout << "Sum of the Values: " << sum << endl;
  cout << "Average of the Values: " << average << endl;
  mycount = 0;
  for(int i=0; i < 5; i++) {
    if(values[i] > average) {
      mycount++; 
}
  }
    cout << "Number of Values Larger Than Average: "<<  mycount << endl;

     
return 0;
}
