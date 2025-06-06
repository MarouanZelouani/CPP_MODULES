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
    FixedPointValue = x << FRACTIONAL_BITS_NUMBER;
}

Fixed::Fixed(const float x)
{
    std::cout << "Float constructor called" << std::endl;
    FixedPointValue = (int)roundf(x * (1 << FRACTIONAL_BITS_NUMBER));
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
        FixedPointValue = obj.FixedPointValue;
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (FixedPointValue);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    FixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return (float)FixedPointValue / (1 << FRACTIONAL_BITS_NUMBER);
}

int Fixed::toInt( void ) const
{
    return FixedPointValue / (1 << FRACTIONAL_BITS_NUMBER);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}