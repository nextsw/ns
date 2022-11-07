#ifndef TABLE_BORDER_H
#define TABLE_BORDER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/painting.hpp>



class TableBorder {
public:
    BorderSide top;

    BorderSide right;

    BorderSide bottom;

    BorderSide left;

    BorderSide horizontalInside;

    BorderSide verticalInside;

    BorderRadius borderRadius;


     TableBorder(BorderRadius borderRadius, BorderSide bottom, BorderSide horizontalInside, BorderSide left, BorderSide right, BorderSide top, BorderSide verticalInside);

    void  all(BorderRadius borderRadius, Color color, BorderStyle style, double width);

    void  symmetric(BorderSide inside, BorderSide outside);

    EdgeInsets dimensions();

    bool isUniform();

    TableBorder scale(double t);

    static TableBorder lerp(TableBorder a, TableBorder b, double t);

    void paint(Canvas canvas, Iterable<double> columns, Rect rect, Iterable<double> rows);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

#endif