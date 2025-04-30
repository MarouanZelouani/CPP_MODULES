#include "Point.hpp"

Fixed calculateTriangleArea(Point const a, Point const b, Point const c)
{
    Fixed result;

    result = a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
    if (result < 0)
        result = result * -1;
    return  result / 2;
}

bool isPointOnEdge(Point a, Point b, Point point)
{
    if ((b.getX() - a.getX()) * (point.getY() - a.getY()) 
        != (b.getY() - a.getY()) * (point.getX() - a.getX()))
        return false;
    if (point.getY() < Fixed::min(a.getY(), b.getY()) || point.getY() > Fixed::max(a.getY(), b.getY()))
        return false;
    if (point.getX() < Fixed::min(a.getX(), b.getX()) || point.getX() > Fixed::max(a.getX(), b.getX()))
        return false;
    return true;
}

bool bsp( Point  a, Point  b, Point  c, Point  point)
{
    if (point == a || point == b || point == c)
        return false;
    if (isPointOnEdge(a, b, point) || isPointOnEdge(b, c, point) || isPointOnEdge(c, a, point))
        return false;
    Fixed Area_ABC = calculateTriangleArea(a, b, c);
    Fixed Area_PBC = calculateTriangleArea(point, b, c);
    Fixed Area_PCA = calculateTriangleArea(point, c, a);
    Fixed Area_PAB = calculateTriangleArea(point, a, b);

    Fixed alpha = Area_PBC / Area_ABC;
    Fixed beta = Area_PCA / Area_ABC;
    Fixed omega = Area_PAB / Area_ABC;

    return alpha >= 0 && beta >= 0 && omega >= 0 && alpha + beta + omega == 1;
}