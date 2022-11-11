#ifndef DART_CORE_DOUBLE
#define DART_CORE_DOUBLE
#include <base.hpp>

#include <dart/core/core.hpp>


class doubleCls : public numCls {
public:
    static double nan;

    static double infinity;

    static double negativeInfinity;

    static double minPositive;

    static double maxFinite;


    virtual double remainder(num other) override;
    virtual double operator+(num other) override;
    virtual double operator-(num other) override;
    virtual double operator*(num other) override;
    virtual double operator%(num other) override;
    virtual double operator/(num other) override;
    virtual int operator~/(num other) override;
    virtual double operator-() override;
    virtual double abs() override;
    virtual double sign() override;
    virtual int round() override;
    virtual int floor() override;
    virtual int ceil() override;
    virtual int truncate() override;
    virtual double roundToDouble() override;
    virtual double floorToDouble() override;
    virtual double ceilToDouble() override;
    virtual double truncateToDouble() override;
    virtual String toString() override;
    static double parse(String source, std::function<double(String source)> onError) override;
    static double tryParse(String source) override;
private:

};
using double = std::shared_ptr<doubleCls>;


#endif