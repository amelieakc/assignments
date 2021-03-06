#include <cstdlib>
#include <iostream>
using namespace std;

class Node 
{  
public: 
  int data;
  Node* next;
};

class Stack 
{
private:
    Node* top1;
    int count;
    int maxnum;
  
public:
  Stack(int max)
  {
    top1 = NULL;
    maxnum = max;
    count = 0;
  }

  void pop()
  {
    if(top1 == NULL)
      cout << "Nothing on stack" << endl;
    else
      {
	Node* toPop = top1;
	top1 = top1->next;
	count--;
	delete(toPop);
      }
  }
 
  void push(int input)
  {
    if(count == maxnum)
      cout << "Stack is full" << endl;
    else
      {
	Node* newTop = new Node;
	if(top1 == NULL)
	  {
	    newTop->data = input;
	    newTop->next = NULL;
	    top1 = newTop;
	    count++;
	  }    
        else
	  {
	    newTop->data = input;
	    newTop->next = NULL;
	    top1 = newTop;
	    count++;
	  }
      }
  }
  
  void print()
  {
    Node* n = new Node;
    n = top1;
    while( n != NULL)
      {
	cout << n->data << " , ";
	n = n->next;
      }
  }

  bool empty();
  
  void top();
  
};

int main()
{
  Stack* calcStack = new Stack(5);
  calcStack->push(5);
  calcStack->push(6);
  calcStack->push(7);
  calcStack->push(8);
  calcStack->pop();
  calcStack->print();
  return 0;
}

