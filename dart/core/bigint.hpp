#ifndef BIGINT_H
#define BIGINT_H
#include <memory>




class BigInt {
public:

    external static BigInt zero();

    external static BigInt one();

    external static BigInt two();

    external static BigInt parse(int radix, String source);

    external static BigInt tryParse(int radix, String source);

    external void  from(num value);

    BigInt abs();

    BigInt -();

    BigInt +(BigInt other);

    BigInt -(BigInt other);

    BigInt *(BigInt other);

    double /(BigInt other);

    BigInt ~/(BigInt other);

    BigInt %(BigInt other);

    BigInt remainder(BigInt other);

    BigInt <<(int shiftAmount);

    BigInt >>(int shiftAmount);

    BigInt &(BigInt other);

    BigInt |(BigInt other);

    BigInt ^(BigInt other);

    BigInt ~();

    bool <(BigInt other);

    bool <=(BigInt other);

    bool >(BigInt other);

    bool >=(BigInt other);

    int compareTo(BigInt other);

    int bitLength();

    int sign();

    bool isEven();

    bool isOdd();

    bool isNegative();

    BigInt pow(int exponent);

    BigInt modPow(BigInt exponent, BigInt modulus);

    BigInt modInverse(BigInt modulus);

    BigInt gcd(BigInt other);

    BigInt toUnsigned(int width);

    BigInt toSigned(int width);

    bool isValidInt();

    int toInt();

    double toDouble();

    String toString();

    String toRadixString(int radix);

private:

};

#endif