#ifndef DART_MATH_POINT
#define DART_MATH_POINT
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T>
class PointCls : public ObjectCls {
public:
    T x;

    T y;


     PointCls(T x, T y);

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Point<T> operator+(Point<T> other);

    virtual Point<T> operator-(Point<T> other);

    virtual Point<T> operator*(num factor);

    virtual double magnitude();

    virtual double distanceTo(Point<T> other);

    virtual T squaredDistanceTo(Point<T> other);

private:

};
template<typename T>
using Point = std::shared_ptr<PointCls<T>>;


#endif