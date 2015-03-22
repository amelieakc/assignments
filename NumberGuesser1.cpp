#include <iostream>
#include <algorithm>
#include "NumberGuesser.h"
using namespace std;

NumberGuesser::NumberGuesser(int low, int high)
{
  initial_low = low;
  initial_high = high;
  imin = low;
  imax = high;
}

void NumberGuesser::higher()
{
  imin = imid +1;
};

void NumberGuesser::lower()
{
  imax = imid -1;
};

int NumberGuesser::getCurrentGuess()
{
  imid = (imin + imax) / 2;
  if (imid < initial_low)
    imid = initial_low;
  else if (imid > initial_high)
    imid = initial_high;
  return imid;
};

void NumberGuesser::reset()
{
  imin = initial_low;
  imax = initial_high;
};
