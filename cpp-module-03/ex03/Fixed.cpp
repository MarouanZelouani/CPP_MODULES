#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : FixedPointValue(0)
{}

Fixed::Fixed(const int x)
{
    this->FixedPointValue = x << FRACTIONAL_BITS;
}

Fixed::Fixed(const float x)
{
    int scaling_factor = 1 << FRACTIONAL_BITS;
    this->FixedPointValue = (int)roundf(x * scaling_factor);
}

Fixed::~Fixed()
{}

Fixed::Fixed(const Fixed& obj)
{
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
    if (this != &obj)
        this->FixedPointValue = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return (this->FixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    this->FixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)(this->FixedPointValue) / (1 << FRACTIONAL_BITS);
}

int Fixed::toInt( void ) const
{
    return this->FixedPointValue / (1 << FRACTIONAL_BITS);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}

bool Fixed::operator<(const Fixed& obj) const
{
    return this->FixedPointValue < obj.FixedPointValue;
}

bool Fixed::operator<=(const Fixed& obj) const
{
    return this->FixedPointValue <= obj.FixedPointValue;
}

bool Fixed::operator>(const Fixed& obj) const
{
    return this->FixedPointValue > obj.FixedPointValue;
}

bool Fixed::operator>=(const Fixed& obj) const
{
    return this->FixedPointValue >= obj.FixedPointValue;
}

bool Fixed::operator==(const Fixed& obj) const
{
    return this->FixedPointValue == obj.FixedPointValue;
}

bool Fixed::operator!=(const Fixed& obj) const
{
    return this->FixedPointValue != obj.FixedPointValue;
}

Fixed Fixed::operator+(const Fixed& obj)
{
    Fixed r;

    r.setRawBits(this->FixedPointValue + obj.FixedPointValue);
    return r;
}

Fixed Fixed::operator-(const Fixed& obj)
{
    Fixed r;

    r.setRawBits(this->FixedPointValue - obj.FixedPointValue);
    return r;
}

Fixed Fixed::operator*(const Fixed& obj)
{
    Fixed r;

    r.setRawBits((this->FixedPointValue * obj.FixedPointValue) >> this->FRACTIONAL_BITS);
    return r;
}

Fixed Fixed::operator/(const Fixed& obj)
{
    Fixed r;

    r.setRawBits((this->FixedPointValue << this->FRACTIONAL_BITS) / obj.FixedPointValue);
    return r;
}

Fixed &Fixed::operator++()
{
    this->FixedPointValue++;
    return *this;
}

Fixed &Fixed::operator--()
{
    this->FixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp = *this;

    this->FixedPointValue++;
    return tmp;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp = *this;

    this->FixedPointValue--;
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