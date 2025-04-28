#ifndef __FIXED_HPP
#define __FIXED_HPP

#include <iostream>

class Fixed 
{
private:
    int FixedPointValue;
    static const int FRACTIONAL_BITS = 8;

public:
    Fixed();
    Fixed(const int var);
    Fixed(const float var);
    ~Fixed();
    Fixed(const Fixed& obj);
    Fixed &operator=(const Fixed& obj);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    bool operator>(const Fixed& obj) const; 
    bool operator<(const Fixed& obj) const;
    bool operator<=(const Fixed& obj) const;
    bool operator>=(const Fixed& obj) const;
    bool operator==(const Fixed& obj) const;
    bool operator!=(const Fixed& obj) const;

    Fixed operator+(const Fixed& obj);
    Fixed operator-(const Fixed& obj);
    Fixed operator*(const Fixed& obj);
    Fixed operator/(const Fixed& obj);

    Fixed &operator++();
    Fixed &operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    static Fixed& min(Fixed& fp1, Fixed& fp2); 
    static Fixed& max(Fixed& fp1, Fixed& fp2);
    static const Fixed& min(const Fixed& fp1, const Fixed& fp2);
    static const Fixed& max(const Fixed& fp1, const Fixed& fp2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif 