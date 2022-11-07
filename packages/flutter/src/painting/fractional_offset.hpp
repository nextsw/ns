#ifndef FRACTIONAL_OFFSET_H
#define FRACTIONAL_OFFSET_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "alignment.hpp"
#include "basic_types.hpp"



class FractionalOffset : Alignment {
public:
    static const FractionalOffset topLeft;

    static const FractionalOffset topCenter;

    static const FractionalOffset topRight;

    static const FractionalOffset centerLeft;

    static const FractionalOffset center;

    static const FractionalOffset centerRight;

    static const FractionalOffset bottomLeft;

    static const FractionalOffset bottomCenter;

    static const FractionalOffset bottomRight;


     FractionalOffset(double dx, double dy);

    void  fromOffsetAndSize(Offset offset, Size size);

    void  fromOffsetAndRect(Offset offset, Rect rect);

    double dx();

    double dy();

    Alignment -(Alignment other);

    Alignment +(Alignment other);

    FractionalOffset -();

    FractionalOffset *(double other);

    FractionalOffset /(double other);

    FractionalOffset ~/(double other);

    FractionalOffset %(double other);

    static FractionalOffset lerp(FractionalOffset a, FractionalOffset b, double t);

    String toString();

private:

};

#endif