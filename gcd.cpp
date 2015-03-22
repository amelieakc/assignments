#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    printf("The numbers are larger=%d and smaller=%d\n", a, b);
    while (b != 0) {
    	  int r = a % b;
	  a = b;
	  b = r;
	  
	  }
    printf("Greatest common divisor is %d\n", a);

	return 0; 
}
