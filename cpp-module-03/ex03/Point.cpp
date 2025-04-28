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

// void Point::setX(const Fixed& fp)
// {
//     this->x = fp;
// }

// void Point::setY(Fixed fp){}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}