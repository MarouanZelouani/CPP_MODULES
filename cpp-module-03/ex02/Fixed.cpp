#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
     std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int x)
{
    std::cout << "Int constructor called" << std::endl;
    FixedPointValue = x << FRACTIONAL_BITS;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    FixedPointValue = (int)roundf(x * (1 << FRACTIONAL_BITS));
}


Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
    if (this != &obj)
        this->FixedPointValue = obj.FixedPointValue;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return FixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    FixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)FixedPointValue / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt( void ) const
{
    return FixedPointValue / (1 << FRACTIONAL_BITS);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}

bool Fixed::operator<(const Fixed& obj) const
{
    return FixedPointValue < obj.FixedPointValue;
}

bool Fixed::operator<=(const Fixed& obj) const
{
    return FixedPointValue <= obj.FixedPointValue;
}

bool Fixed::operator>(const Fixed& obj) const
{
    return FixedPointValue > obj.FixedPointValue;
}

bool Fixed::operator>=(const Fixed& obj) const
{
    return FixedPointValue >= obj.FixedPointValue;
}

bool Fixed::operator==(const Fixed& obj) const
{
    return FixedPointValue == obj.FixedPointValue;
}

bool Fixed::operator!=(const Fixed& obj) const
{
    return FixedPointValue != obj.FixedPointValue;
}

Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed r;

    r.setRawBits(FixedPointValue + obj.FixedPointValue);
    return r;
}

Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed r;

    r.setRawBits(FixedPointValue - obj.FixedPointValue);
    return r;
}

Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed r;

    r.setRawBits((FixedPointValue * obj.FixedPointValue) >> FRACTIONAL_BITS);
    return r;
}

Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed r;

    r.setRawBits((FixedPointValue << FRACTIONAL_BITS) / obj.FixedPointValue);
    return r;
}

Fixed &Fixed::operator++()
{
    FixedPointValue++;
    return *this;
}

Fixed &Fixed::operator--()
{
    FixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    FixedPointValue++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;

    FixedPointValue--;
    return tmp;
}

Fixed &Fixed::min(Fixed& fp1, Fixed& fp2)
{
    if (fp1 < fp2)
        return fp1;
    return fp2;
}

Fixed &Fixed::max(Fixed& fp1, Fixed& fp2)
{
    if (fp1 > fp2)
        return fp1;
    return fp2;
}

const Fixed &Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
    if (fp1 < fp2)
        return fp1;
    return fp2;
}

const Fixed &Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
    if (fp1 > fp2)
        return fp1;
    return fp2;
}