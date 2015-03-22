#include "IntCollection.h"
#include <iostream>
using namespace std;

IntCollection::IntCollection()
{
  size = 0;
  data = new int[CHUNK_SIZE];
  capacity = CHUNK_SIZE;
}

IntCollection::~IntCollection() {
  delete [] data;
}

IntCollection::IntCollection(const IntCollection &c)
{				
  size = 0;
  capacity = CHUNK_SIZE;
  data = new int[CHUNK_SIZE];
  for(int i = 0; i < c.size; i++) {
    add(c.data[i]);
  }
}

void IntCollection::add(int value)
{
  int *newData;
  
  if ((size > 0) && (size % CHUNK_SIZE == 0))
    {
      capacity += CHUNK_SIZE;
      newData = new int[capacity];
      for (int i=0; i<size; i++)
	newData[i] = data[i];
      delete [] data;
      data = newData;
    }
  data[size++] = value;
}

int IntCollection::get(int index)
{  
  if (index<0 || index>=size)
    {
      cout << "ERROR: get() trying to access index out of range.\n";
      exit(1);
    }

  return data[index];
}

int IntCollection::getSize()
{
  return size;
}

IntCollection& IntCollection::operator=(const IntCollection &c)
{
  for(int i=0; i< c.size; i++)
    add(c.data[i]);
  return *this;
}

bool IntCollection:: operator==(const IntCollection &c)
{
  if(size != c.size)
    return false;
  for(int i = 0; i < c.size; i++)
    {
      if(data[i] != c.data[i])
	return false;
    }
  return true;
}

IntCollection& IntCollection::operator<<(int value)
{
  add(value);
  return *this;
}


