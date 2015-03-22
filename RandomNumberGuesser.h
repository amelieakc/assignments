#ifndef RANDOMNUMBERGUESSER_H
#define RANDOMNUMBERGUESSER_H

#include "NumberGuesser.h"
#include <iostream>

class RandomNumberGuesser : public NumberGuesser
{
 private:
  int guess;
  void reset();

 public:
  RandomNumberGuesser(int, int);
  virtual int getCurrentGuess();
  void higher();
  void lower();

};

#endif


