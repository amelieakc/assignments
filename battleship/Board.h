// Board.h
// Battleship
//

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Point.h"
#include "PointCollection.h"
#include "Ship.h"

#define MAX_SIZE 10
#define NUM_SHIPS 4

class Board
{
 private:
  Ship *ships[4];
  PointCollection shots;
  Ship* generateShipWithLength(int l);
  

 public:
  Board();
  Ship placeShip(int l);
  bool outOfBounds(const Ship& s);
  bool fireShot(int x, int y);
  bool anyShipHitAtPoint(const point& p);
  int unsunkShipCount();
  void display();
};

#endif
