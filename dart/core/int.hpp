#ifndef DART_CORE_INT
#define DART_CORE_INT
#include <base.hpp>

#include <dart/core/core.hpp>


class intCls : public numCls {
public:

    void  fromEnvironment(int defaultValue, String name);
    virtual int operator&(int other);
    virtual int operator|(int other);
    virtual int operator^(int other);
    virtual int operator~();
    virtual int operator<<(int shiftAmount);
    virtual int operator>>(int shiftAmount);
    virtual int operator>>>(int shiftAmount);
    virtual int modPow(int exponent, int modulus);
    virtual int modInverse(int modulus);
    virtual int gcd(int other);
    virtual bool isEven();
    virtual bool isOdd();
    virtual int bitLength();
    virtual int toUnsigned(int width);
    virtual int toSigned(int width);
    virtual int operator-() override;
    virtual int abs() override;
    virtual int sign() override;
    virtual int round() override;
    virtual int floor() override;
    virtual int ceil() override;
    virtual int truncate() override;
    virtual double roundToDouble() override;
    virtual double floorToDouble() override;
    virtual double ceilToDouble() override;
    virtual double truncateToDouble() override;
    virtual String toString() override;
    virtual String toRadixString(int radix);
    static int parse(std::function<int(String source)> onError, int radix, String source) override;
    static int tryParse(int radix, String source) override;
private:

};
using int = std::shared_ptr<intCls>;


#endif