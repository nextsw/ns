#ifndef DART_MATH_RECTANGLE
#define DART_MATH_RECTANGLE
#include <base.hpp>

#include <dart/core/core.hpp>


template<typename T> class _RectangleBaseCls : public ObjectCls {
public:

    virtual T left();
    virtual T top();
    virtual T width();
    virtual T height();
    virtual T right();

    virtual T bottom();

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual Rectangle<T> intersection(Rectangle<T> other);

    virtual bool intersects(Rectangle<num> other);

    virtual Rectangle<T> boundingBox(Rectangle<T> other);

    virtual bool containsRectangle(Rectangle<num> another);

    virtual bool containsPoint(Point<num> another);

    virtual Point<T> topLeft();

    virtual Point<T> topRight();

    virtual Point<T> bottomRight();

    virtual Point<T> bottomLeft();

private:

     _RectangleBaseCls();
};
template<typename T> using _RectangleBase = std::shared_ptr<_RectangleBaseCls<T>>;

template<typename T> class RectangleCls : public _RectangleBaseCls<T> {
public:
    T left;

    T top;

    T width;

    T height;


     RectangleCls(T height, T left, T top, T width);

    virtual void  fromPoints(Point<T> a, Point<T> b);

private:

};
template<typename T> using Rectangle = std::shared_ptr<RectangleCls<T>>;

template<typename T> class MutableRectangleCls : public _RectangleBaseCls<T> {
public:
    T left;

    T top;


     MutableRectangleCls(T height, T left, T top, T width);

    virtual void  fromPoints(Point<T> a, Point<T> b);

    virtual T width();

    virtual void  width(T width);

    virtual T height();

    virtual void  height(T height);

private:
    T _width;

    T _height;


};
template<typename T> using MutableRectangle = std::shared_ptr<MutableRectangleCls<T>>;
template<typename T>  T _clampToZero(T value);



#endif