#ifndef NUM_H
#define NUM_H
#include <memory>




class num {
public:

    bool ==(Object other);

    int hashCode();

    int compareTo(num other);

    num +(num other);

    num -(num other);

    num *(num other);

    num %(num other);

    double /(num other);

    int ~/(num other);

    num -();

    num remainder(num other);

    bool <(num other);

    bool <=(num other);

    bool >(num other);

    bool >=(num other);

    bool isNaN();

    bool isNegative();

    bool isInfinite();

    bool isFinite();

    num abs();

    num sign();

    int round();

    int floor();

    int ceil();

    int truncate();

    double roundToDouble();

    double floorToDouble();

    double ceilToDouble();

    double truncateToDouble();

    num clamp(num lowerLimit, num upperLimit);

    int toInt();

    double toDouble();

    String toStringAsFixed(int fractionDigits);

    String toStringAsExponential(int fractionDigits);

    String toStringAsPrecision(int precision);

    String toString();

    static num parse(String input, FunctionType onError);

    static num tryParse(String input);

private:

};

#endif