#ifndef NOTCHED_SHAPES_H
#define NOTCHED_SHAPES_H
#include <memory>

#include <math/math.hpp>
#include "basic_types.hpp"
#include "borders.hpp"



class NotchedShape {
public:

     NotchedShape();

    Path getOuterPath(Rect guest, Rect host);

private:

};

class CircularNotchedRectangle : NotchedShape {
public:

     CircularNotchedRectangle();

    Path getOuterPath(Rect guest, Rect host);

private:

};

class AutomaticNotchedShape : NotchedShape {
public:
    ShapeBorder host;

    ShapeBorder guest;


     AutomaticNotchedShape(ShapeBorder guest, ShapeBorder host);

    Path getOuterPath(Rect guestRect, Rect hostRect);

private:

};

#endif