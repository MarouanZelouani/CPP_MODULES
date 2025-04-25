#ifndef __FiXED_HPP
#define __FIXED_HPP

class Fixed 
{
private:
    int FixedPointValue;
    static const int FRACTION_VALUE = 8;

public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& obj);
    Fixed &operator=(const Fixed& obj);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif 