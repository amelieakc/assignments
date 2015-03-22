#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main () {
  double sum, average;
  string line;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
    {
      int counter = 0;
      while ( getline (myfile,line) )
	{
	  double result;
	  istringstream convert(line);
	  convert >> result;
	  cout << result << endl;
	  sum += result;
	  counter++;
	}

      myfile.close();

      average = sum / counter;
      cout << "The average of the numbers is: " << endl;
      cout << average << endl;

    }

  else cout << "Unable to open file"; 
  
  return 0;
}
