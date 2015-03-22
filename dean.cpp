#include <boost/algorithm/string.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
using namespace boost;


void print( vector <string> & v )
{
  for (size_t n = 0; n < v.size(); n++)
    cout << "\"" << v[ n ] << "\"\n";
  cout << endl;
}

int main () {
  cout << "Student Scores For The Dean's List\n";
  cout << "Student Name, Student Score\n";
  string line;
  ifstream myfile ("studentscores.txt");
  if (myfile.is_open())
    {
      string prev;
      // Get each line of input
      while (getline(myfile,line))
	{
	  vector <string> fields;
	  // Split on comma
	  split( fields, line, is_any_of( ", " ) );
	  string student_score = fields[3];

	  float value = atof(student_score.c_str());
	  if (value >= 3.6)
	    {
	      cout << line << endl;  
	    }
	}
      myfile.close();
    }

  else cout << "Unable to open file"; 

  return 0;
}
