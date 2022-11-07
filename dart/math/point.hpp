#ifndef POINT_H
#define POINT_H
#include <memory>




class Point<T extends num> {
public:
    T x;

    T y;


     Point(T x, T y);

    String toString();

    bool ==(Object other);

    int hashCode();

    Point<T> +(Point<T> other);

    Point<T> -(Point<T> other);

    Point<T> *(num factor);

    double magnitude();

    double distanceTo(Point<T> other);

    T squaredDistanceTo(Point<T> other);

private:

};

#endif