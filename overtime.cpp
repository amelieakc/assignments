#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    
  string employee_name; 
  float hours, rate, gross_pay, regular_pay, overtime_pay, double_overtime_pay;

  employee_name = "Joe Sudds";
  hours = 45.50;
  rate = 10.34;

  if(hours <= 40) {
      gross_pay = hours * rate;
    } else {
      overtime_pay = (hours - 40) *(1.5 * rate);
      gross_pay = regular_pay + overtime_pay;
  }
 if(hours >= 60){
   overtime_pay = 20 *(1.5 * rate);
   double_overtime_pay = (hours - 60) *(2 * rate);
   gross_pay = regular_pay + overtime_pay + double_overtime_pay;
 }
 
 cout << "Employee Name: \n";
 cout <<  employee_name << endl;
 cout << "Employee's Hours: \n";
 cout << hours << endl;
 cout << "Pay Rate: \n";
 cout << rate << endl;
 cout << "Gross Pay: \n";
 cout << gross_pay << endl;

 return 0;

}
