#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : FixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed &Fixed::operator=(const Fixed& obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->FixedPointValue = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->FixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
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