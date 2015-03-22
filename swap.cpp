#include <iostream>

using namespace std;

void swap(int& num_1, int& num_2) {
  int temp = num_1;
  num_1 = num_2;
  num_2 = temp;
}

int main()
{
  int num_1, num_2;
  num_1 = 7;
  num_2 = 11;
  cout << "Number 1: " << num_1 << endl;
  cout << "Number 2: " << num_2 << endl;
  swap(num_1, num_2);
  cout << "Number 1: " << num_1 << endl;
  cout << "Number 2: " << num_2 << endl;
  return 0;
}
