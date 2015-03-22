#include <iostream>
using namespace std;

void noNegatives(int *x) {
  if(*x < 0){
    *x = 0;
  }
}
int temp;
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

const int size = 2;

int main() {

  int x, y;
  int* p1;
  p1 = &x;
  *p1 = 99;
  cout << "Steps 5 & 6" << endl;
  cout << x << endl;
  cout << *p1 << endl;
  p1 = &y;
  *p1 = -300;
  cout << "Step 7 & 8" << endl;
  cout << y << endl;
  
  int temp;
  int* p2;
  p2 = &x;

  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  
  cout << "Step 9 & 10" << endl;
  cout << *p1 << endl;
  cout << *p2 << endl;
  cout << x << endl;
  cout << y << endl;

  cout << "Steps 11 & 12" << endl;
  noNegatives(&x);
  cout << x << endl;

  noNegatives(&y);
  cout << y << endl;

  cout << "Step 13" << endl;
  p2 = &x;
  cout << x << endl;

  p2 = &y;
  cout << y << endl;
  
  int a[size];
  p2 = &x;
  a[0] = *p2;
  p2 = &y;
  a[1] = *p2;
  cout << "Steps 14-18" << endl;
  cout << a[0] << endl;
  cout << a[1] << endl;
  
  cout << "Steps 19 & 20" << endl;
  cout << a[0] << endl;
  cout << a[1] << endl;
  p1 = &a[0];
  p2 = &a[1];
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
  a[0] = *p1;
  a[1] = *p2;

  cout << a[0] << endl;
  cout << a[1] << endl;
 
  cout << "Steps 21 & 22" << endl;
  swap(x, y);
    cout << x << endl;
    cout << y << endl;
  
    cout << "Step 23" << endl;
    swap(a[0], a[1]);
    cout << a[0] << endl;
    cout << a[1] << endl;

}


