//  Board.cpp
//  Battleship
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Board.h"
#include "Point.h"
#include "PointCollection.h"
#include "Ship.h"


Board::Board() {
  ships[0] = new Ship(point(0, 0), VERTICAL, 2);
  ships[1] = new Ship(point(2, 0), VERTICAL, 3);
  ships[2] = new Ship(point(4, 0), VERTICAL, 4);
  ships[3] = new Ship(point(6, 0), VERTICAL, 5);  
}

int Board::unsunkShipCount() {
  int unsunkShips = 0;
  for(int i = 0; i < NUM_SHIPS; i++) {
    if(!ships[i]->isSunk()) {
      unsunkShips++;
    }      
  }
  return unsunkShips;
}

bool Board::fireShot(int x, int y) {
  point *p = new point(x, y); 

  for(int i = 0; i < unsunkShipCount(); i++) {
    ships[i]->shotFiredAtPoint(*p);
    if(ships[i]->isHitAtPoint(*p))
      return true;
  }

  // there was a miss
  shots.add(*p);
  return false;
}

bool Board::anyShipHitAtPoint(const point& p) {
  for(int k = 0; k < NUM_SHIPS; k++) {
    if(ships[k]->isHitAtPoint(p)) {
      return true;
    }
  }
  return false;
}

void Board::display() {

  for(int i = 9; i >= 0; i--) {
    for(int j = 0; j < 9; j++) {
      // check all of the conditions
      point p(j, i);
      if(shots.contains(p)) {
	std::cout << " . ";
      } else if(anyShipHitAtPoint(p)) {
	std::cout << " X ";
      } else {
	std::cout << " ~ "; 
      }
    }
    std::cout << std::endl;
  }
}
