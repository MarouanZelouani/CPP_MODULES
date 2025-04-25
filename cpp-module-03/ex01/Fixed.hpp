#ifndef __FiXED_HPP
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
};
    
std::ostream& operator<<(std::ostream& os, const Fixed& fp);

#endif 