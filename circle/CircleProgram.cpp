//Amelie Cameron Assignment 9 Circle Class
//This program takes in x, y cocoordinates and the radius of a circle. Then using the distance formula to determine whether a given point is in the circle. Using a circle pointer, I entered new information for a new circle and tested various points to demonstrate the containsPoint function.  


#include <iostream>
#include <math.h>
#include "Circle.h"
using namespace std;

int main()
{
  Circle circle;
  double cX;
  double cY;
  double cRadius;
  double xValue;
  double yValue;
  Circle *circleptr = NULL;
  circleptr = &circle;

  cout << "Enter the x coordinate of the center of your circle: " << endl;
  cin >> cX;
  cout << "Enter the y coordinate of the center of your circle: " << endl;
  cin >> cY;
  cout << "Enter the radius of your circle: " << endl;
  cin >> cRadius;
  cout << "Enter an x coordinate: " << endl;
  cin >> xValue;
  cout << "Enter a y coordinate: " << endl;
  cin >> yValue;
  
  circle.setX(cX);
  circle.setY(cY);
  circle.setRadius(cRadius);

  cout << "Circle radius: " << circle.getRadius() << endl;
  cout << "Circle center coordinates: " << circle.getX() << " , "  << circle.getY() << endl;
  cout << "Circle area: " << circle.getArea() << endl;
  cout << "Is the point " << xValue << ", " << yValue << " in the circle? (0 false, 1 true) " << circle.containsPoint(xValue, yValue) << endl;

  circleptr->setX(4);
  circleptr->setY(5);
  circleptr->setRadius(2);
  cout << endl;
  cout << "New circle radius: " <<circleptr->getRadius() << endl;
  cout << "New circle center coordinates: " << circleptr->getX() << " , " << circleptr->getY() << endl;
  cout << "Is the point " << 4 << " , " << 5 << " in the circle? (0 false, 1 true) " << circleptr->containsPoint(4, 5) << endl;
  cout << "Is the point " << 100 << " , " << 500 << " in the circle? (0 false, 1 true) " << circleptr->containsPoint(100, 500) << endl;
  
  delete circleptr;
  circleptr = NULL;

  return 0;
}
