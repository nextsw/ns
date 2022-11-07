#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <memory>




class _RectangleBase<T extends num> {
public:

    T left();

    T top();

    T width();

    T height();

    T right();

    T bottom();

    String toString();

    bool ==(Object other);

    int hashCode();

    Rectangle<T> intersection(Rectangle<T> other);

    bool intersects(Rectangle<num> other);

    Rectangle<T> boundingBox(Rectangle<T> other);

    bool containsRectangle(Rectangle<num> another);

    bool containsPoint(Point<num> another);

    Point<T> topLeft();

    Point<T> topRight();

    Point<T> bottomRight();

    Point<T> bottomLeft();

private:

     _RectangleBase();

};

class Rectangle<T extends num> : _RectangleBase<T> {
public:
    T left;

    T top;

    T width;

    T height;


     Rectangle(T height, T left, T top, T width);

    void  fromPoints(Point<T> a, Point<T> b);

private:

};

class MutableRectangle<T extends num> : _RectangleBase<T> {
public:
    T left;

    T top;


     MutableRectangle(T height, T left, T top, T width);

    void  fromPoints(Point<T> a, Point<T> b);

    T width();

    void  width(T width);

    T height();

    void  height(T height);

private:
    T _width;

    T _height;


};
T _clampToZero<T extends num>(T value);


#endif