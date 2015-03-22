#include <iostream>
#include <cmath>
using namespace std;

double stdev(double scores[], int pos_used, int size){
  double s, mean, sum;

  for(int n = 0; n < size; n++)
    sum += scores[n];
  mean = sum / pos_used;
  double formula = 0;
  for(int n = 0; n < size; n++){
    if(scores[n] == 0) 
      continue;
    formula += pow(scores[n] - mean, 2);
  }
  s = sqrt(formula /pos_used);
  return s;
}

int main()
{
  int pos_used, size;
  double scores[] = {90.3, 0, 0, 0, 0, 0, 0, 63.5, 80, 100, 72, 95, 100, 62, 98, 100};
  size = sizeof(scores) / sizeof(double);
  double s = stdev(scores, 10, size);
  cout << s << endl;
  return 0;
}
