#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_TABLE_BORDER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_TABLE_BORDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>


class TableBorderCls : public ObjectCls {
public:
    BorderSide top;

    BorderSide right;

    BorderSide bottom;

    BorderSide left;

    BorderSide horizontalInside;

    BorderSide verticalInside;

    BorderRadius borderRadius;


     TableBorderCls(BorderRadius borderRadius, BorderSide bottom, BorderSide horizontalInside, BorderSide left, BorderSide right, BorderSide top, BorderSide verticalInside);
    virtual void  all(BorderRadius borderRadius, Color color, BorderStyle style, double width);

    virtual void  symmetric(BorderSide inside, BorderSide outside);

    virtual EdgeInsets dimensions();

    virtual bool isUniform();

    virtual TableBorder scale(double t);

    static TableBorder lerp(TableBorder a, TableBorder b, double t);

    virtual void paint(Canvas canvas, Iterable<double> columns, Rect rect, Iterable<double> rows);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using TableBorder = std::shared_ptr<TableBorderCls>;


#endif