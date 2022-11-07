#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <memory>




class OffsetBase {
public:

     OffsetBase(double _dx, double _dy);

    bool isInfinite();

    bool isFinite();

    bool <(OffsetBase other);

    bool <=(OffsetBase other);

    bool >(OffsetBase other);

    bool >=(OffsetBase other);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    double _dx;

    double _dy;


};

class Offset : OffsetBase {
public:
    static const Offset zero;

    static const Offset infinite;


     Offset(double dx, double dy);

    void  fromDirection(double direction, double distance);

    double dx();

    double dy();

    double distance();

    double distanceSquared();

    double direction();

    Offset scale(double scaleX, double scaleY);

    Offset translate(double translateX, double translateY);

    Offset -();

    Offset -(Offset other);

    Offset +(Offset other);

    Offset *(double operand);

    Offset /(double operand);

    Offset ~/(double operand);

    Offset %(double operand);

    Rect &(Size other);

    static Offset lerp(Offset a, Offset b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class Size : OffsetBase {
public:
    static const Size zero;

    static const Size infinite;


     Size(double height, double width);

    void  copy(Size source);

    void  square(double dimension);

    void  fromWidth(double width);

    void  fromHeight(double height);

    void  fromRadius(double radius);

    double width();

    double height();

    double aspectRatio();

    bool isEmpty();

    OffsetBase -(OffsetBase other);

    Size +(Offset other);

    Size *(double operand);

    Size /(double operand);

    Size ~/(double operand);

    Size %(double operand);

    double shortestSide();

    double longestSide();

    Offset topLeft(Offset origin);

    Offset topCenter(Offset origin);

    Offset topRight(Offset origin);

    Offset centerLeft(Offset origin);

    Offset center(Offset origin);

    Offset centerRight(Offset origin);

    Offset bottomLeft(Offset origin);

    Offset bottomCenter(Offset origin);

    Offset bottomRight(Offset origin);

    bool contains(Offset offset);

    Size flipped();

    static Size lerp(Size a, Size b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class Rect {
public:
    double left;

    double top;

    double right;

    double bottom;

    static const Rect zero;

    static const Rect largest;


    void  fromLTRB(double bottom, double left, double right, double top);

    void  fromLTWH(double height, double left, double top, double width);

    void  fromCircle(Offset center, double radius);

    void  fromCenter(Offset center, double height, double width);

    void  fromPoints(Offset a, Offset b);

    double width();

    double height();

    Size size();

    bool hasNaN();

    bool isInfinite();

    bool isFinite();

    bool isEmpty();

    Rect shift(Offset offset);

    Rect translate(double translateX, double translateY);

    Rect inflate(double delta);

    Rect deflate(double delta);

    Rect intersect(Rect other);

    Rect expandToInclude(Rect other);

    bool overlaps(Rect other);

    double shortestSide();

    double longestSide();

    Offset topLeft();

    Offset topCenter();

    Offset topRight();

    Offset centerLeft();

    Offset center();

    Offset centerRight();

    Offset bottomLeft();

    Offset bottomCenter();

    Offset bottomRight();

    bool contains(Offset offset);

    static Rect lerp(Rect a, Rect b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:
    static const double _giantScalar;


    Float32List _getValue32();

};

class Radius {
public:
    double x;

    double y;

    static const Radius zero;


    void  circular(double radius);

    void  elliptical(double x, double y);

    Radius -();

    Radius -(Radius other);

    Radius +(Radius other);

    Radius *(double operand);

    Radius /(double operand);

    Radius ~/(double operand);

    Radius %(double operand);

    static Radius lerp(Radius a, Radius b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class RRect {
public:
    double left;

    double top;

    double right;

    double bottom;

    double tlRadiusX;

    double tlRadiusY;

    double trRadiusX;

    double trRadiusY;

    double brRadiusX;

    double brRadiusY;

    double blRadiusX;

    double blRadiusY;

    static const RRect zero;


    void  fromLTRBXY(double bottom, double left, double radiusX, double radiusY, double right, double top);

    void  fromLTRBR(double bottom, double left, Radius radius, double right, double top);

    void  fromRectXY(double radiusX, double radiusY, Rect rect);

    void  fromRectAndRadius(Radius radius, Rect rect);

    void  fromLTRBAndCorners(double bottom, Radius bottomLeft, Radius bottomRight, double left, double right, double top, Radius topLeft, Radius topRight);

    void  fromRectAndCorners(Radius bottomLeft, Radius bottomRight, Rect rect, Radius topLeft, Radius topRight);

    Radius tlRadius();

    Radius trRadius();

    Radius brRadius();

    Radius blRadius();

    RRect shift(Offset offset);

    RRect inflate(double delta);

    RRect deflate(double delta);

    double width();

    double height();

    Rect outerRect();

    Rect safeInnerRect();

    Rect middleRect();

    Rect wideMiddleRect();

    Rect tallMiddleRect();

    bool isEmpty();

    bool isFinite();

    bool isRect();

    bool isStadium();

    bool isEllipse();

    bool isCircle();

    double shortestSide();

    double longestSide();

    bool hasNaN();

    Offset center();

    RRect scaleRadii();

    bool contains(Offset point);

    static RRect lerp(RRect a, RRect b, double t);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

    void  _raw(double blRadiusX, double blRadiusY, double bottom, double brRadiusX, double brRadiusY, double left, double right, double tlRadiusX, double tlRadiusY, double top, double trRadiusX, double trRadiusY);

    Float32List _getValue32();

    double _getMin(double limit, double min, double radius1, double radius2);

};

class RSTransform {
public:

     RSTransform(double scos, double ssin, double tx, double ty);

    void  fromComponents(double anchorX, double anchorY, double rotation, double scale, double translateX, double translateY);

    double scos();

    double ssin();

    double tx();

    double ty();

private:
    Float32List _value;


};

#endif