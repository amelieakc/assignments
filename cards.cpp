
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> cards;

  int a;
  int num_count = 20;
  for(int i = 0; i < num_count; i++){
    cout << "Enter a number\n" << endl;
    cin >> a;
    cards.push_back(a);
  }
  
  int largest;
  int back;
  largest = cards.back();
  cards.pop_back();
  
  while(!cards.empty())
  {
    back = cards.back();
    
    if(back > largest){
      largest = back;
    }
    cards.pop_back();
  }
  cout << "The largest number is " << largest << endl;
}
  
 
  
  
