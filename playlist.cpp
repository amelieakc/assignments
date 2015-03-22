// Assignment 2: Array-based List Class for Playlists
// Amelie Cameron 
// This program uses an array-based list implementation to track songs in a playlist. By adding/ modifying setEntry, remove, and insert functions we can change the playlist and add/remove songs.

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

template<class ItemType>
class List
{
private:
  static const int CHUNK_SIZE=2;
  ItemType *list;
  int numItems;
  int maxItems;
public:
    List(
) { numItems = 0; maxItems = CHUNK_SIZE; 
    list = new ItemType[CHUNK_SIZE]; }
  ~List() { delete [] list; }

   bool isEmpty() { return numItems==0; }
  int getLength() { return numItems; }
  bool insert(int pos, const ItemType& item);
  bool remove(int pos);
    
   void clear() { numItems = 0; }

   ItemType getEntry(int pos) const throw(invalid_argument);

   void setEntry(int pos, const ItemType& item) throw(invalid_argument);

  void reallocate();
};

template<class ItemType>
void List<ItemType>::reallocate()
{
  maxItems *= 2;
  ItemType *newList = new ItemType[maxItems];
  for(int i = 0; i < numItems; i++) 
    { 
      newList[i] = list[i];
    }
  list = newList;
}

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
  bool canAdd;

  canAdd = ((pos > 0) && (pos <= numItems + 1));
  if (canAdd)
    {
       if(numItems + 1 > maxItems) {
      	reallocate();
      }
   for(int i=numItems; i>=pos; i--)
	list[i] = list[i-1];

      list[pos-1] = item;

      numItems++;
    }
 
  return canAdd;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const throw(invalid_argument)
{
  if(pos<1 || pos>numItems) {
    throw invalid_argument("ERROR: getEntry() using invalid position");
  }
  return list[pos-1];
}

template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item) throw(invalid_argument)
{
  if(pos<1 || pos>getLength()) {
    throw invalid_argument("ERROR: getEntry() using invalid position");
  }
  else {
    list[pos-1] = item;
  }
}

template<class ItemType>
bool List<ItemType>::remove(int pos)
{
   bool canRemove; 
  canRemove = ((pos > 0) && (pos <= numItems) && (numItems <= maxItems));
  if(canRemove)
    {
      cout << "Song # " << pos + 1 << " has been removed from the playlist." << endl;
       for (int i = pos; i <= numItems-1; i++) {
	 list[i] = list[i+1];
      }
      numItems--;
      return true;
    }
  return false;
}

int getTrack()
{
  bool inputCheck;
  int trackNumber;

  do
    {
      inputCheck = true;
      cout << "Please enter the track number you'd like to view: ";
      if (!(cin >> trackNumber))
	{
	  cout << "Please enter numbers only.\n";
	  cin.clear(); 
	  cin.ignore(10000,'\n');
	  inputCheck = false;
	}
    } while (!inputCheck);
  return trackNumber;
}

int main()
{
  List<string> songs;
  char goAgain = 'y';
  int trackNumber;
  string trackName;

  songs.insert(1, "One More Saturday Night");
  songs.insert(1, "Friday I'm in Love");
  songs.insert(3, "Sunday Morning Coming Down");
  songs.insert(4, "Blue Monday");
  songs.insert(1, "California Love");

  cout << "Original Playlist: " << endl;
  for(int i = 0; i < songs.getLength(); i++) {
    cout << i+1 << ": " << songs.getEntry(i+1) << endl;
  }
  cout << endl;
  
  songs.setEntry(1, "Amelie's Song");
  
  songs.remove(2);
  cout << endl;

  cout << "Altered Playlist (using setEntry and remove): " << endl;
  cout << "There are " << songs.getLength() << " tracks.\n";
  for(int i = 0; i < songs.getLength(); i++) {
    cout << i+1 << ": " << songs.getEntry(i+1) << endl;
  }
  cout << endl;
  
  while (goAgain!='n')
    {
      trackNumber = getTrack();
      try
	{
	  trackName = songs.getEntry(trackNumber);
	}
      catch (invalid_argument arg)
	{
	  cout << arg.what() << endl;
	  trackName = "No Track";
	}
      cout << "Your track name is " << trackName << endl;
      cout << "Go again? (y/n) ";
      cin >> goAgain;
    }

  cout << "Rock on!\n";
  return 0; 
}
