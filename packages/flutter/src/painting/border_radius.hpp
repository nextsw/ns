#ifndef PACKAGES_FLUTTER_SRC_PAINTING_BORDER_RADIUS
#define PACKAGES_FLUTTER_SRC_PAINTING_BORDER_RADIUS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"


class BorderRadiusGeometryCls : public ObjectCls {
public:

     BorderRadiusGeometryCls();
    virtual BorderRadiusGeometry subtract(BorderRadiusGeometry other);

    virtual BorderRadiusGeometry add(BorderRadiusGeometry other);

    virtual BorderRadiusGeometry operator-();
    virtual BorderRadiusGeometry operator*(double other);
    virtual BorderRadiusGeometry operator/(double other);
    virtual BorderRadiusGeometry operator~/(double other);
    virtual BorderRadiusGeometry operator%(double other);
    static BorderRadiusGeometry lerp(BorderRadiusGeometry a, BorderRadiusGeometry b, double t);

    virtual BorderRadius resolve(TextDirection direction);
    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    virtual Radius _topLeft();
    virtual Radius _topRight();
    virtual Radius _bottomLeft();
    virtual Radius _bottomRight();
    virtual Radius _topStart();
    virtual Radius _topEnd();
    virtual Radius _bottomStart();
    virtual Radius _bottomEnd();
};
using BorderRadiusGeometry = std::shared_ptr<BorderRadiusGeometryCls>;

class BorderRadiusCls : public BorderRadiusGeometryCls {
public:
    static BorderRadius zero;

    Radius topLeft;

    Radius topRight;

    Radius bottomLeft;

    Radius bottomRight;


    virtual void  all(Radius radius);

    virtual void  circular(double radius);

    virtual void  vertical(Radius bottom, Radius top);

    virtual void  horizontal(Radius left, Radius right);

    virtual void  only(Radius bottomLeft, Radius bottomRight, Radius topLeft, Radius topRight);
    virtual BorderRadius copyWith(Radius bottomLeft, Radius bottomRight, Radius topLeft, Radius topRight);

    virtual RRect toRRect(Rect rect);

    virtual BorderRadiusGeometry subtract(BorderRadiusGeometry other);

    virtual BorderRadiusGeometry add(BorderRadiusGeometry other);

    virtual BorderRadius operator-(BorderRadius other);

    virtual BorderRadius operator+(BorderRadius other);

    virtual BorderRadius operator-();

    virtual BorderRadius operator*(double other);

    virtual BorderRadius operator/(double other);

    virtual BorderRadius operator~/(double other);

    virtual BorderRadius operator%(double other);

    static BorderRadius lerp(BorderRadius a, BorderRadius b, double t);

    virtual BorderRadius resolve(TextDirection direction);

private:

    virtual Radius _topLeft();

    virtual Radius _topRight();

    virtual Radius _bottomLeft();

    virtual Radius _bottomRight();

    virtual Radius _topStart();

    virtual Radius _topEnd();

    virtual Radius _bottomStart();

    virtual Radius _bottomEnd();

};
using BorderRadius = std::shared_ptr<BorderRadiusCls>;

class BorderRadiusDirectionalCls : public BorderRadiusGeometryCls {
public:
    static BorderRadiusDirectional zero;

    Radius topStart;

    Radius topEnd;

    Radius bottomStart;

    Radius bottomEnd;


    virtual void  all(Radius radius);

    virtual void  circular(double radius);

    virtual void  vertical(Radius bottom, Radius top);

    virtual void  horizontal(Radius end, Radius start);

    virtual void  only(Radius bottomEnd, Radius bottomStart, Radius topEnd, Radius topStart);
    virtual BorderRadiusGeometry subtract(BorderRadiusGeometry other);

    virtual BorderRadiusGeometry add(BorderRadiusGeometry other);

    virtual BorderRadiusDirectional operator-(BorderRadiusDirectional other);

    virtual BorderRadiusDirectional operator+(BorderRadiusDirectional other);

    virtual BorderRadiusDirectional operator-();

    virtual BorderRadiusDirectional operator*(double other);

    virtual BorderRadiusDirectional operator/(double other);

    virtual BorderRadiusDirectional operator~/(double other);

    virtual BorderRadiusDirectional operator%(double other);

    static BorderRadiusDirectional lerp(BorderRadiusDirectional a, BorderRadiusDirectional b, double t);

    virtual BorderRadius resolve(TextDirection direction);

private:

    virtual Radius _topStart();

    virtual Radius _topEnd();

    virtual Radius _bottomStart();

    virtual Radius _bottomEnd();

    virtual Radius _topLeft();

    virtual Radius _topRight();

    virtual Radius _bottomLeft();

    virtual Radius _bottomRight();

};
using BorderRadiusDirectional = std::shared_ptr<BorderRadiusDirectionalCls>;

class _MixedBorderRadiusCls : public BorderRadiusGeometryCls {
public:

    virtual _MixedBorderRadius operator-();

    virtual _MixedBorderRadius operator*(double other);

    virtual _MixedBorderRadius operator/(double other);

    virtual _MixedBorderRadius operator~/(double other);

    virtual _MixedBorderRadius operator%(double other);

    virtual BorderRadius resolve(TextDirection direction);

private:
    Radius _topLeft;

    Radius _topRight;

    Radius _bottomLeft;

    Radius _bottomRight;

    Radius _topStart;

    Radius _topEnd;

    Radius _bottomStart;

    Radius _bottomEnd;


     _MixedBorderRadiusCls(Radius _bottomEnd, Radius _bottomLeft, Radius _bottomRight, Radius _bottomStart, Radius _topEnd, Radius _topLeft, Radius _topRight, Radius _topStart);
};
using _MixedBorderRadius = std::shared_ptr<_MixedBorderRadiusCls>;


#endif