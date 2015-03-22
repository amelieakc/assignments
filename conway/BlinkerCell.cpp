#include "BlinkerCell.h"
#include "AbstractCell.h"
#include "ConwayWorld.h"


BlinkerCell::BlinkerCell() { }

bool BlinkerCell::willBeAliveInNextGeneration() {
  int count = neighborCount();
  if (isAlive()) {
    alive = false;
    return alive;
  } else {
    alive = true;
    return alive;
  }
}

bool BlinkerCell::isAlive() {
  return alive;
}

char BlinkerCell::displayChar() {
  return isAlive() ? 'B' : '.';
}
