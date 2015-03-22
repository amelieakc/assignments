#ifndef INTCOLLECTION_H
#define INTCOLLECTION_H 

const int CHUNK_SIZE = 5;

class IntCollection
{
 private:
  int size;
  int capacity;
  int* data;

 public:
  IntCollection();
  ~IntCollection();
  IntCollection(const IntCollection &c);
  void add(int value);
  int get(int index);
  int getSize();
  IntCollection& operator=(const IntCollection &c);
  bool operator==(const IntCollection &c);
  IntCollection& operator<<(int value);
};

#endif
