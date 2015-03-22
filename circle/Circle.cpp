#include <iostream>
#include <math.h>
#include "Circle.h"
using namespace std;

void Circle::setRadius(double r)
{
  radius = r;
};

void Circle::setX(double valueX)
{
  x = valueX;
};

void Circle::setY(double valueY)
{
  y = valueY;
};

double Circle::getRadius() const
{
  return radius;
};

double Circle::getX() const
{
  return x;
};

double Circle::getY() const
{
  return y;
};

double Circle::getArea() const
{
  return (radius * radius * 3.14);
};

bool Circle::containsPoint(double xValue, double yValue)
{
  bool status;
  double d;
  d = sqrt(pow((xValue - x), 2.0) + pow((yValue - y), 2.0));
  
  if(d <= radius)
    status = true;
   else
    status = false;
  return status;
};
