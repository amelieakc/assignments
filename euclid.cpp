#include <iostream>
using namespace std;

int gcd(int x, int y)
{
  int temp = 0;
  if((x % y) == 0)
    {
      temp = y;
    }
  else
    {
      temp = gcd(y, x % y);
    }
  return temp;
}
int main()
{
  cout << gcd(12, 6) << endl;
  
  system("pause");
  return 0;
}

