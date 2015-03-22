#include <iostream>
using namespace std;

double add_tax(double tax_rate, double& cost){
  cost = cost + cost * tax_rate;
}

int main(){
  double thing = 10.00;
  double tax = 0.06;
  add_tax(tax, thing);
  cout << thing << endl;
}
