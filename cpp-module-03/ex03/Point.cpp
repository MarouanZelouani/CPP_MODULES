#include "Point.hpp"

Point::Point() : x(0), y(0)
{}

Point::Point(const float f1, const float f2) : x(f1), y(f2)
{}

Point::Point (const Point& obj)
{
    *this = obj;
}

Point &Point::operator=(const Point& obj)
{
    if (this != &obj)
        *this = obj;
    return *this;
}

Point::~Point()
{}





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