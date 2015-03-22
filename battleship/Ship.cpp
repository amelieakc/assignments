//  Ship.cpp
//  Battleship
//

#include "Ship.h"

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(point originPoint, direction o, int l) 
{
  origin = originPoint;
  orientation = o;
  length = l;

  for(int i = 0; i < length; i++)
    {
      int x, y;
      if( o == HORIZONTAL)
	{
	x = origin.getX() + i;
	y = origin.getY();
	} 
      else  
	{
	  x = origin.getX();
	  y = origin.getY() + i;
	}
   
      point new_p(x, y);
      points.add(new_p);
    }  
} 

//*******************************************************************************************
//
//*******************************************************************************************

Ship::Ship(const Ship& s) 
{
  origin = s.origin;
  orientation = s.orientation;
  length = s.length;
  for(int i = 0; i < s.points.getSize(); i++)
    {
      points.add(s.points.get(i));
    }
  
}

//*******************************************************************************************
// Contains Point
//*******************************************************************************************

bool Ship::containsPoint(const point& p) const
{
  return points.contains(p);
}

//*******************************************************************************************
// Collides With
//*******************************************************************************************

bool Ship::collidesWith(const Ship& s) const
{
  for(int i = 0; i < points.getSize(); i++)
    {
      if(s.points.contains(points.get(i)))
	return true;
    }
 
  return false;
}

//*******************************************************************************************
// Shot Fired At Point
//*******************************************************************************************

void Ship::shotFiredAtPoint(const point& p)
{
  if(points.contains(p))
     hits.add(p);
}

//*******************************************************************************************
// Is Hit At Point
//*******************************************************************************************

bool Ship::isHitAtPoint(const point& p)
{
  for(int i = 0; i < hits.getSize(); i++)
    {
      if(hits.get(i) == p)
	return true;
    }
  return false;
}

//*******************************************************************************************
// Hit Count
//*******************************************************************************************

int Ship::hitCount() const
{
  return  hits.getSize();
}

//*******************************************************************************************
// Operator =
//*******************************************************************************************

const Ship& Ship::operator=(const Ship& s)
{
  points = s.points;
  hits = s.hits;
  length = s.length;
  orientation = s.orientation;
  origin = s.origin;

  return *this;
}


//*******************************************************************************************
//  Is Sunk
//*******************************************************************************************

bool Ship::isSunk() 
{
  return hitCount() == length;
}


