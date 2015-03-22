#include <iostream>
using namespace std;

double avg(int a, double b){
  double sum = a + b;
  double avg = sum / 2;
  return avg;
}

bool in_order( int a, int b, int c){
  if( a <= b <= c) 
    return true;
  return false;
}

    
bool is_number(char a){
  try {
    float(a);
    return true;
  } catch (int e) { 
    cout << e << endl;
  }
}

int main(){
  char a = 'b';
  cout << is_number(a) << endl;
}
