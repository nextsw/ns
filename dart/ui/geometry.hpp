#ifndef DART_UI_GEOMETRY
#define DART_UI_GEOMETRY
#include <base.hpp>

#include <dart/core/core.hpp>


class OffsetBaseCls : public ObjectCls {
public:

     OffsetBaseCls(double _dx, double _dy);

    virtual bool isInfinite();

    virtual bool isFinite();

    virtual bool operator<(OffsetBase other);

    virtual bool operator<=(OffsetBase other);

    virtual bool operator>(OffsetBase other);

    virtual bool operator>=(OffsetBase other);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    double _dx;

    double _dy;


};
using OffsetBase = std::shared_ptr<OffsetBaseCls>;

class OffsetCls : public OffsetBaseCls {
public:
    static Offset zero;

    static Offset infinite;


     OffsetCls(double dx, double dy);

    virtual void  fromDirection(double direction, double distance);

    virtual double dx();

    virtual double dy();

    virtual double distance();

    virtual double distanceSquared();

    virtual double direction();

    virtual Offset scale(double scaleX, double scaleY);

    virtual Offset translate(double translateX, double translateY);

    virtual Offset operator-();

    virtual Offset operator-(Offset other);

    virtual Offset operator+(Offset other);

    virtual Offset operator*(double operand);

    virtual Offset operator/(double operand);

    virtual Offset operator~/(double operand);

    virtual Offset operator%(double operand);

    virtual Rect operator&(Size other);

    static Offset lerp(Offset a, Offset b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using Offset = std::shared_ptr<OffsetCls>;

class SizeCls : public OffsetBaseCls {
public:
    static Size zero;

    static Size infinite;


     SizeCls(double height, double width);

    virtual void  copy(Size source);

    virtual void  square(double dimension);

    virtual void  fromWidth(double width);

    virtual void  fromHeight(double height);

    virtual void  fromRadius(double radius);

    virtual double width();

    virtual double height();

    virtual double aspectRatio();

    virtual bool isEmpty();

    virtual OffsetBase operator-(OffsetBase other);

    virtual Size operator+(Offset other);

    virtual Size operator*(double operand);

    virtual Size operator/(double operand);

    virtual Size operator~/(double operand);

    virtual Size operator%(double operand);

    virtual double shortestSide();

    virtual double longestSide();

    virtual Offset topLeft(Offset origin);

    virtual Offset topCenter(Offset origin);

    virtual Offset topRight(Offset origin);

    virtual Offset centerLeft(Offset origin);

    virtual Offset center(Offset origin);

    virtual Offset centerRight(Offset origin);

    virtual Offset bottomLeft(Offset origin);

    virtual Offset bottomCenter(Offset origin);

    virtual Offset bottomRight(Offset origin);

    virtual bool contains(Offset offset);

    virtual Size flipped();

    static Size lerp(Size a, Size b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using Size = std::shared_ptr<SizeCls>;

class RectCls : public ObjectCls {
public:
    double left;

    double top;

    double right;

    double bottom;

    static Rect zero;

    static Rect largest;


    virtual void  fromLTRB(double bottom, double left, double right, double top);

    virtual void  fromLTWH(double height, double left, double top, double width);

    virtual void  fromCircle(Offset center, double radius);

    virtual void  fromCenter(Offset center, double height, double width);

    virtual void  fromPoints(Offset a, Offset b);

    virtual double width();

    virtual double height();

    virtual Size size();

    virtual bool hasNaN();

    virtual bool isInfinite();

    virtual bool isFinite();

    virtual bool isEmpty();

    virtual Rect shift(Offset offset);

    virtual Rect translate(double translateX, double translateY);

    virtual Rect inflate(double delta);

    virtual Rect deflate(double delta);

    virtual Rect intersect(Rect other);

    virtual Rect expandToInclude(Rect other);

    virtual bool overlaps(Rect other);

    virtual double shortestSide();

    virtual double longestSide();

    virtual Offset topLeft();

    virtual Offset topCenter();

    virtual Offset topRight();

    virtual Offset centerLeft();

    virtual Offset center();

    virtual Offset centerRight();

    virtual Offset bottomLeft();

    virtual Offset bottomCenter();

    virtual Offset bottomRight();

    virtual bool contains(Offset offset);

    static Rect lerp(Rect a, Rect b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:
    static double _giantScalar;


    virtual Float32List _getValue32();

};
using Rect = std::shared_ptr<RectCls>;

class RadiusCls : public ObjectCls {
public:
    double x;

    double y;

    static Radius zero;


    virtual void  circular(double radius);

    virtual void  elliptical(double x, double y);
    virtual Radius operator-();

    virtual Radius operator-(Radius other);

    virtual Radius operator+(Radius other);

    virtual Radius operator*(double operand);

    virtual Radius operator/(double operand);

    virtual Radius operator~/(double operand);

    virtual Radius operator%(double operand);

    static Radius lerp(Radius a, Radius b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using Radius = std::shared_ptr<RadiusCls>;

class RRectCls : public ObjectCls {
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

    static RRect zero;


    virtual void  fromLTRBXY(double bottom, double left, double radiusX, double radiusY, double right, double top);

    virtual void  fromLTRBR(double bottom, double left, Radius radius, double right, double top);

    virtual void  fromRectXY(double radiusX, double radiusY, Rect rect);

    virtual void  fromRectAndRadius(Radius radius, Rect rect);

    virtual void  fromLTRBAndCorners(double bottom, Radius bottomLeft, Radius bottomRight, double left, double right, double top, Radius topLeft, Radius topRight);

    virtual void  fromRectAndCorners(Radius bottomLeft, Radius bottomRight, Rect rect, Radius topLeft, Radius topRight);

    virtual Radius tlRadius();

    virtual Radius trRadius();

    virtual Radius brRadius();

    virtual Radius blRadius();

    virtual RRect shift(Offset offset);

    virtual RRect inflate(double delta);

    virtual RRect deflate(double delta);

    virtual double width();

    virtual double height();

    virtual Rect outerRect();

    virtual Rect safeInnerRect();

    virtual Rect middleRect();

    virtual Rect wideMiddleRect();

    virtual Rect tallMiddleRect();

    virtual bool isEmpty();

    virtual bool isFinite();

    virtual bool isRect();

    virtual bool isStadium();

    virtual bool isEllipse();

    virtual bool isCircle();

    virtual double shortestSide();

    virtual double longestSide();

    virtual bool hasNaN();

    virtual Offset center();

    virtual RRect scaleRadii();

    virtual bool contains(Offset point);

    static RRect lerp(RRect a, RRect b, double t);

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

    virtual void  _raw(double blRadiusX, double blRadiusY, double bottom, double brRadiusX, double brRadiusY, double left, double right, double tlRadiusX, double tlRadiusY, double top, double trRadiusX, double trRadiusY);

    virtual Float32List _getValue32();

    virtual double _getMin(double limit, double min, double radius1, double radius2);

};
using RRect = std::shared_ptr<RRectCls>;

class RSTransformCls : public ObjectCls {
public:

     RSTransformCls(double scos, double ssin, double tx, double ty);

    virtual void  fromComponents(double anchorX, double anchorY, double rotation, double scale, double translateX, double translateY);

    virtual double scos();

    virtual double ssin();

    virtual double tx();

    virtual double ty();

private:
    Float32List _value;


};
using RSTransform = std::shared_ptr<RSTransformCls>;


#endif