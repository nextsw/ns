#ifndef PACKAGES_FLUTTER_SRC_PAINTING_FRACTIONAL_OFFSET
#define PACKAGES_FLUTTER_SRC_PAINTING_FRACTIONAL_OFFSET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "alignment.hpp"
#include "basic_types.hpp"


class FractionalOffsetCls : public AlignmentCls {
public:
    static FractionalOffset topLeft;

    static FractionalOffset topCenter;

    static FractionalOffset topRight;

    static FractionalOffset centerLeft;

    static FractionalOffset center;

    static FractionalOffset centerRight;

    static FractionalOffset bottomLeft;

    static FractionalOffset bottomCenter;

    static FractionalOffset bottomRight;


     FractionalOffsetCls(double dx, double dy);

    virtual void  fromOffsetAndSize(Offset offset, Size size);

    virtual void  fromOffsetAndRect(Offset offset, Rect rect);

    virtual double dx();

    virtual double dy();

    virtual Alignment operator-(Alignment other);

    virtual Alignment operator+(Alignment other);

    virtual FractionalOffset operator-();

    virtual FractionalOffset operator*(double other);

    virtual FractionalOffset operator/(double other);

    virtual FractionalOffset operator~/(double other);

    virtual FractionalOffset operator%(double other);

    static FractionalOffset lerp(FractionalOffset a, FractionalOffset b, double t);

    virtual String toString();

private:

};
using FractionalOffset = std::shared_ptr<FractionalOffsetCls>;


#endif