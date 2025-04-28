#ifndef __FIXED_HPP
#define __FIXED_HPP

class Fixed 
{
private:
    int FixedPointValue;
    static const int FRACTIONAL_BITS_NUMBER = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& obj);
    Fixed &operator=(const Fixed& obj);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif 