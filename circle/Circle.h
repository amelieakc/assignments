#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
 private:
  double x;
  double y;
  double radius;

 public:
  void setRadius(double);
  void setX(double);
  void setY(double);
  double getRadius() const;
  double getX() const;
  double getY() const;
  double getArea() const;
  bool containsPoint(double, double);

};

#endif
