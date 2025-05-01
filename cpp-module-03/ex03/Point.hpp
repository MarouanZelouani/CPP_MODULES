#ifndef __POINT_HPP_
#define __POINT_HPP_

#include "Fixed.hpp"

class Point 
{
private:
    const Fixed  x;
    const Fixed  y;

public:
    Point();
    Point(const float f1, const float f2);
    Point(const Point& obj);
    ~Point();
    Point &operator=(const Point& obj);
    bool operator==(const Point& point);
    Fixed getX() const; 
    Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif