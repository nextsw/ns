#ifndef PACKAGES_FLUTTER_SRC_PAINTING_NOTCHED_SHAPES
#define PACKAGES_FLUTTER_SRC_PAINTING_NOTCHED_SHAPES
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include "basic_types.hpp"
#include "borders.hpp"


class NotchedShapeCls : public ObjectCls {
public:

     NotchedShapeCls();
    virtual Path getOuterPath(Rect guest, Rect host);
private:

};
using NotchedShape = std::shared_ptr<NotchedShapeCls>;

class CircularNotchedRectangleCls : public NotchedShapeCls {
public:

     CircularNotchedRectangleCls();
    virtual Path getOuterPath(Rect guest, Rect host);

private:

};
using CircularNotchedRectangle = std::shared_ptr<CircularNotchedRectangleCls>;

class AutomaticNotchedShapeCls : public NotchedShapeCls {
public:
    ShapeBorder host;

    ShapeBorder guest;


     AutomaticNotchedShapeCls(ShapeBorder guest, ShapeBorder host);
    virtual Path getOuterPath(Rect guestRect, Rect hostRect);

private:

};
using AutomaticNotchedShape = std::shared_ptr<AutomaticNotchedShapeCls>;


#endif