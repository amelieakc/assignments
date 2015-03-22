#include <iostream>
#include <string>
using namespace std;

int gcd(int larger, int smaller){
  if(smaller == 0)
    return larger;
  return gcd(smaller, larger % smaller);
}

int gcd1(int larger, int smaller){
  int remain;
  while(1){
    remain = larger % smaller;
    if(remain == 0)
      return smaller;
    else{
      larger = smaller;
      smaller = remain;
    }
  }
}

int main(int argc, const char* argv[]){
  if (argc < 3){
    cout << "USAGE: ./a.out <smaller_number> <larger_number>\n";
    return 1;
  }
  
  int smaller = atoi(argv[1]);
  int larger = atoi(argv[2]);
  int result = gcd(larger, smaller);
  cout << result << endl;
}
