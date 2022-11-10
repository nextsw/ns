#ifndef DART_CORE_BIGINT
#define DART_CORE_BIGINT
#include <base.hpp>

#include <dart/core/core.hpp>


class BigIntCls : public ObjectCls {
public:

    static BigInt zero();
    static BigInt one();
    static BigInt two();
    static BigInt parse(int radix, String source);
    static BigInt tryParse(int radix, String source);
    void  from(num value);
    virtual BigInt abs();
    virtual BigInt operator-();
    virtual BigInt operator+(BigInt other);
    virtual BigInt operator-(BigInt other);
    virtual BigInt operator*(BigInt other);
    virtual double operator/(BigInt other);
    virtual BigInt operator~/(BigInt other);
    virtual BigInt operator%(BigInt other);
    virtual BigInt remainder(BigInt other);
    virtual BigInt operator<<(int shiftAmount);
    virtual BigInt operator>>(int shiftAmount);
    virtual BigInt operator&(BigInt other);
    virtual BigInt operator|(BigInt other);
    virtual BigInt operator^(BigInt other);
    virtual BigInt operator~();
    virtual bool operator<(BigInt other);
    virtual bool operator<=(BigInt other);
    virtual bool operator>(BigInt other);
    virtual bool operator>=(BigInt other);
    virtual int compareTo(BigInt other);
    virtual int bitLength();
    virtual int sign();
    virtual bool isEven();
    virtual bool isOdd();
    virtual bool isNegative();
    virtual BigInt pow(int exponent);
    virtual BigInt modPow(BigInt exponent, BigInt modulus);
    virtual BigInt modInverse(BigInt modulus);
    virtual BigInt gcd(BigInt other);
    virtual BigInt toUnsigned(int width);
    virtual BigInt toSigned(int width);
    virtual bool isValidInt();
    virtual int toInt();
    virtual double toDouble();
    virtual String toString();
    virtual String toRadixString(int radix);
private:

};
using BigInt = std::shared_ptr<BigIntCls>;


#endif