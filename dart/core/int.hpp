#ifndef INT_H
#define INT_H
#include <memory>




class int : num {
public:

    external void  fromEnvironment(int defaultValue, String name);

    int &(int other);

    int |(int other);

    int ^(int other);

    int ~();

    int <<(int shiftAmount);

    int >>(int shiftAmount);

    int >>>(int shiftAmount);

    int modPow(int exponent, int modulus);

    int modInverse(int modulus);

    int gcd(int other);

    bool isEven();

    bool isOdd();

    int bitLength();

    int toUnsigned(int width);

    int toSigned(int width);

    int -();

    int abs();

    int sign();

    int round();

    int floor();

    int ceil();

    int truncate();

    double roundToDouble();

    double floorToDouble();

    double ceilToDouble();

    double truncateToDouble();

    String toString();

    String toRadixString(int radix);

    external static int parse(FunctionType onError, int radix, String source);

    external static int tryParse(int radix, String source);

private:

};

#endif