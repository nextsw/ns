#ifndef BORDER_RADIUS_H
#define BORDER_RADIUS_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic_types.hpp"



class BorderRadiusGeometry {
public:

     BorderRadiusGeometry();

    BorderRadiusGeometry subtract(BorderRadiusGeometry other);

    BorderRadiusGeometry add(BorderRadiusGeometry other);

    BorderRadiusGeometry -();

    BorderRadiusGeometry *(double other);

    BorderRadiusGeometry /(double other);

    BorderRadiusGeometry ~/(double other);

    BorderRadiusGeometry %(double other);

    static BorderRadiusGeometry lerp(BorderRadiusGeometry a, BorderRadiusGeometry b, double t);

    BorderRadius resolve(TextDirection direction);

    String toString();

    bool ==(Object other);

    int hashCode();

private:

    Radius _topLeft();

    Radius _topRight();

    Radius _bottomLeft();

    Radius _bottomRight();

    Radius _topStart();

    Radius _topEnd();

    Radius _bottomStart();

    Radius _bottomEnd();

};

class BorderRadius : BorderRadiusGeometry {
public:
    static const BorderRadius zero;

    Radius topLeft;

    Radius topRight;

    Radius bottomLeft;

    Radius bottomRight;


    void  all(Radius radius);

    void  circular(double radius);

    void  vertical(Radius bottom, Radius top);

    void  horizontal(Radius left, Radius right);

    void  only(Radius bottomLeft, Radius bottomRight, Radius topLeft, Radius topRight);

    BorderRadius copyWith(Radius bottomLeft, Radius bottomRight, Radius topLeft, Radius topRight);

    RRect toRRect(Rect rect);

    BorderRadiusGeometry subtract(BorderRadiusGeometry other);

    BorderRadiusGeometry add(BorderRadiusGeometry other);

    BorderRadius -(BorderRadius other);

    BorderRadius +(BorderRadius other);

    BorderRadius -();

    BorderRadius *(double other);

    BorderRadius /(double other);

    BorderRadius ~/(double other);

    BorderRadius %(double other);

    static BorderRadius lerp(BorderRadius a, BorderRadius b, double t);

    BorderRadius resolve(TextDirection direction);

private:

    Radius _topLeft();

    Radius _topRight();

    Radius _bottomLeft();

    Radius _bottomRight();

    Radius _topStart();

    Radius _topEnd();

    Radius _bottomStart();

    Radius _bottomEnd();

};

class BorderRadiusDirectional : BorderRadiusGeometry {
public:
    static const BorderRadiusDirectional zero;

    Radius topStart;

    Radius topEnd;

    Radius bottomStart;

    Radius bottomEnd;


    void  all(Radius radius);

    void  circular(double radius);

    void  vertical(Radius bottom, Radius top);

    void  horizontal(Radius end, Radius start);

    void  only(Radius bottomEnd, Radius bottomStart, Radius topEnd, Radius topStart);

    BorderRadiusGeometry subtract(BorderRadiusGeometry other);

    BorderRadiusGeometry add(BorderRadiusGeometry other);

    BorderRadiusDirectional -(BorderRadiusDirectional other);

    BorderRadiusDirectional +(BorderRadiusDirectional other);

    BorderRadiusDirectional -();

    BorderRadiusDirectional *(double other);

    BorderRadiusDirectional /(double other);

    BorderRadiusDirectional ~/(double other);

    BorderRadiusDirectional %(double other);

    static BorderRadiusDirectional lerp(BorderRadiusDirectional a, BorderRadiusDirectional b, double t);

    BorderRadius resolve(TextDirection direction);

private:

    Radius _topStart();

    Radius _topEnd();

    Radius _bottomStart();

    Radius _bottomEnd();

    Radius _topLeft();

    Radius _topRight();

    Radius _bottomLeft();

    Radius _bottomRight();

};

class _MixedBorderRadius : BorderRadiusGeometry {
public:

    _MixedBorderRadius -();

    _MixedBorderRadius *(double other);

    _MixedBorderRadius /(double other);

    _MixedBorderRadius ~/(double other);

    _MixedBorderRadius %(double other);

    BorderRadius resolve(TextDirection direction);

private:
    Radius _topLeft;

    Radius _topRight;

    Radius _bottomLeft;

    Radius _bottomRight;

    Radius _topStart;

    Radius _topEnd;

    Radius _bottomStart;

    Radius _bottomEnd;


     _MixedBorderRadius(Radius _bottomEnd, Radius _bottomLeft, Radius _bottomRight, Radius _bottomStart, Radius _topEnd, Radius _topLeft, Radius _topRight, Radius _topStart);

};

#endif