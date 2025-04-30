#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::~Point()
{}

Point::Point(const float f1, const float f2) : x(f1), y(f2)
{}

Point::Point (const Point& obj) : x(obj.x), y(obj.y) 
{}

Point &Point::operator=(const Point& obj)
{
    (void)obj;
    return *this;
}

bool Point::operator==(const Point& point)
{
    if (this->x == point.x && this->y == point.y)
        return true;
    return false;
}

Fixed Point::getX() const
{
    return x;
}

Fixed Point::getY() const
{
    return y;
}