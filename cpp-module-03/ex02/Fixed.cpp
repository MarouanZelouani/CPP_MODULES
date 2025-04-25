#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : FixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}

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
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->FixedPointValue = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->FixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
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