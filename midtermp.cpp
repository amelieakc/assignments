#include <iostream>
#include <cstdlib>

using namespace std;
int num[10];

void fibonacci(int* num, int size) {
  num[0] = 1;
  num[1] = 1;
  for(int i = 2; i< size; i++) {
   num[i] = num[i-1] + num[i-2];
  }
}
  int main() {
    fibonacci(num, 10);
  }
