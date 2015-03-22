#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <boost/bind.hpp>


using namespace std;


void initializeData(vector<string> &names, vector<int> &scores, int size) {
  for(int i = 0; i < size; i++) {
    string player;
    cout << "Please enter the name for player # " << i + 1 << ": ";
    cin >> player;
    names.push_back (player);
  }
  for(int j = 0; j < size; j++) {
    int gamescore;
    cout << "Please enter the score for player # " << j + 1 << ": ";
    cin >> gamescore;
    scores.push_back (gamescore);
  }
}

void sortData(vector<string> &names, vector<int> &scores, int size) {
  vector<pair<string, int> > topscorers;
  for(int i = 0; i < size; i++) {
    topscorers.push_back(make_pair(names[i], scores[i]));
  }
  sort(topscorers.begin(), topscorers.end(),
       boost::bind(&std::pair<string, int>::second, _1) >
       boost::bind(&std::pair<string, int>::second, _2));
  for(int i = 0; i < size; i++) {
    names[i] = topscorers[i].first;
    scores[i] = topscorers[i].second;
  }
}

void displayData(vector<string> names, vector<int> scores, int size) {
  cout << "Top Scorers: " << endl;
  for(int i = 0; i < size; i++) {
    cout << names[i] << ": ";
    cout << scores[i] << endl;
  }
}

int main() {

  const int size = 5;
  vector<int> scores;
  vector<string> names;


  initializeData(names, scores, size);
  sortData(names, scores, size);
  displayData(names, scores, size);

  return 0;
}
