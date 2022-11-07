#ifndef DOUBLE_H
#define DOUBLE_H
#include <memory>




class double : num {
public:
    static const double nan;

    static const double infinity;

    static const double negativeInfinity;

    static const double minPositive;

    static const double maxFinite;


    double remainder(num other);

    double +(num other);

    double -(num other);

    double *(num other);

    double %(num other);

    double /(num other);

    int ~/(num other);

    double -();

    double abs();

    double sign();

    int round();

    int floor();

    int ceil();

    int truncate();

    double roundToDouble();

    double floorToDouble();

    double ceilToDouble();

    double truncateToDouble();

    String toString();

    external static double parse(FunctionType onError, String source);

    external static double tryParse(String source);

private:

};

#endif