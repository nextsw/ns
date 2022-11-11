#ifndef DART_CORE_NUM
#define DART_CORE_NUM
#include <base.hpp>

#include <dart/core/core.hpp>


class numCls : public ObjectCls {
public:

    virtual bool operator==(Object other);
    virtual int hashCode();
    virtual int compareTo(num other);
    virtual num operator+(num other);
    virtual num operator-(num other);
    virtual num operator*(num other);
    virtual num operator%(num other);
    virtual double operator/(num other);
    virtual int operator~/(num other);
    virtual num operator-();
    virtual num remainder(num other);
    virtual bool operator<(num other);
    virtual bool operator<=(num other);
    virtual bool operator>(num other);
    virtual bool operator>=(num other);
    virtual bool isNaN();
    virtual bool isNegative();
    virtual bool isInfinite();
    virtual bool isFinite();
    virtual num abs();
    virtual num sign();
    virtual int round();
    virtual int floor();
    virtual int ceil();
    virtual int truncate();
    virtual double roundToDouble();
    virtual double floorToDouble();
    virtual double ceilToDouble();
    virtual double truncateToDouble();
    virtual num clamp(num lowerLimit, num upperLimit);
    virtual int toInt();
    virtual double toDouble();
    virtual String toStringAsFixed(int fractionDigits);
    virtual String toStringAsExponential(int fractionDigits);
    virtual String toStringAsPrecision(int precision);
    virtual String toString();
    static num parse(String input, std::function<num(String input)> onError);

    static num tryParse(String input);

private:

};
using num = std::shared_ptr<numCls>;


#endif