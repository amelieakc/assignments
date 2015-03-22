#include <iostream>
using namespace std;

void prod(int a, int b, int c) {
  int product;
  product = a * b * c;
  cout << product << endl;
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  prod(a,b,c);

  return 0;
}
