#ifndef PACKAGES_FLUTTER_SRC_PAINTING_EDGE_INSETS
#define PACKAGES_FLUTTER_SRC_PAINTING_EDGE_INSETS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"


class EdgeInsetsGeometryCls : public ObjectCls {
public:
    static EdgeInsetsGeometry infinity;


     EdgeInsetsGeometryCls();
    virtual bool isNonNegative();

    virtual double horizontal();

    virtual double vertical();

    virtual double along(Axis axis);

    virtual Size collapsedSize();

    virtual EdgeInsetsGeometry flipped();

    virtual Size inflateSize(Size size);

    virtual Size deflateSize(Size size);

    virtual EdgeInsetsGeometry subtract(EdgeInsetsGeometry other);

    virtual EdgeInsetsGeometry add(EdgeInsetsGeometry other);

    virtual EdgeInsetsGeometry clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min);

    virtual EdgeInsetsGeometry operator-();
    virtual EdgeInsetsGeometry operator*(double other);
    virtual EdgeInsetsGeometry operator/(double other);
    virtual EdgeInsetsGeometry operator~/(double other);
    virtual EdgeInsetsGeometry operator%(double other);
    static EdgeInsetsGeometry lerp(EdgeInsetsGeometry a, EdgeInsetsGeometry b, double t);

    virtual EdgeInsets resolve(TextDirection direction);
    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    virtual double _bottom();
    virtual double _end();
    virtual double _left();
    virtual double _right();
    virtual double _start();
    virtual double _top();
};
using EdgeInsetsGeometry = std::shared_ptr<EdgeInsetsGeometryCls>;

class EdgeInsetsCls : public EdgeInsetsGeometryCls {
public:
    static EdgeInsets zero;

    double left;

    double top;

    double right;

    double bottom;


    virtual void  fromLTRB(double bottom, double left, double right, double top);
    virtual void  all(double value);

    virtual void  only(double bottom, double left, double right, double top);
    virtual void  symmetric(double horizontal, double vertical);

    virtual void  fromWindowPadding(double devicePixelRatio, WindowPadding padding);

    virtual Offset topLeft();

    virtual Offset topRight();

    virtual Offset bottomLeft();

    virtual Offset bottomRight();

    virtual EdgeInsets flipped();

    virtual Rect inflateRect(Rect rect);

    virtual Rect deflateRect(Rect rect);

    virtual EdgeInsetsGeometry subtract(EdgeInsetsGeometry other);

    virtual EdgeInsetsGeometry add(EdgeInsetsGeometry other);

    virtual EdgeInsetsGeometry clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min);

    virtual EdgeInsets operator-(EdgeInsets other);

    virtual EdgeInsets operator+(EdgeInsets other);

    virtual EdgeInsets operator-();

    virtual EdgeInsets operator*(double other);

    virtual EdgeInsets operator/(double other);

    virtual EdgeInsets operator~/(double other);

    virtual EdgeInsets operator%(double other);

    static EdgeInsets lerp(EdgeInsets a, EdgeInsets b, double t);

    virtual EdgeInsets resolve(TextDirection direction);

    virtual EdgeInsets copyWith(double bottom, double left, double right, double top);

private:

    virtual double _left();

    virtual double _top();

    virtual double _right();

    virtual double _bottom();

    virtual double _start();

    virtual double _end();

};
using EdgeInsets = std::shared_ptr<EdgeInsetsCls>;

class EdgeInsetsDirectionalCls : public EdgeInsetsGeometryCls {
public:
    static EdgeInsetsDirectional zero;

    double start;

    double top;

    double end;

    double bottom;


    virtual void  fromSTEB(double bottom, double end, double start, double top);
    virtual void  only(double bottom, double end, double start, double top);
    virtual void  all(double value);

    virtual bool isNonNegative();

    virtual EdgeInsetsDirectional flipped();

    virtual EdgeInsetsGeometry subtract(EdgeInsetsGeometry other);

    virtual EdgeInsetsGeometry add(EdgeInsetsGeometry other);

    virtual EdgeInsetsDirectional operator-(EdgeInsetsDirectional other);

    virtual EdgeInsetsDirectional operator+(EdgeInsetsDirectional other);

    virtual EdgeInsetsDirectional operator-();

    virtual EdgeInsetsDirectional operator*(double other);

    virtual EdgeInsetsDirectional operator/(double other);

    virtual EdgeInsetsDirectional operator~/(double other);

    virtual EdgeInsetsDirectional operator%(double other);

    static EdgeInsetsDirectional lerp(EdgeInsetsDirectional a, EdgeInsetsDirectional b, double t);

    virtual EdgeInsets resolve(TextDirection direction);

private:

    virtual double _start();

    virtual double _top();

    virtual double _end();

    virtual double _bottom();

    virtual double _left();

    virtual double _right();

};
using EdgeInsetsDirectional = std::shared_ptr<EdgeInsetsDirectionalCls>;

class _MixedEdgeInsetsCls : public EdgeInsetsGeometryCls {
public:

    virtual void  fromLRSETB(double _bottom, double _end, double _left, double _right, double _start, double _top);
    virtual bool isNonNegative();

    virtual _MixedEdgeInsets operator-();

    virtual _MixedEdgeInsets operator*(double other);

    virtual _MixedEdgeInsets operator/(double other);

    virtual _MixedEdgeInsets operator~/(double other);

    virtual _MixedEdgeInsets operator%(double other);

    virtual EdgeInsets resolve(TextDirection direction);

private:
    double _left;

    double _right;

    double _start;

    double _end;

    double _top;

    double _bottom;


};
using _MixedEdgeInsets = std::shared_ptr<_MixedEdgeInsetsCls>;


#endif