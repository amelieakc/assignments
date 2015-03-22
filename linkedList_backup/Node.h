//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h 
    Listing 4-1 */
#ifndef _NODE
#define _NODE

template<class ItemType>
class Node
{
private:
   ItemType        item; // A data item
   Node<ItemType>* next; // Pointer to next node
   Node<ItemType>* prev;

public:
   Node();
   Node(const ItemType&);
   Node(const ItemType&, Node<ItemType>*, Node<ItemType>*);
   void setItem(const ItemType&);
   void setNext(Node<ItemType>*);
   void setPrev(Node<ItemType>*);
   ItemType getItem() const;
   Node<ItemType>* getNext() const;
   Node<ItemType>* getPrev() const;
}; // end Node

#endif
