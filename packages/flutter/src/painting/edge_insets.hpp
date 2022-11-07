#ifndef EDGE_INSETS_H
#define EDGE_INSETS_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"



class EdgeInsetsGeometry {
public:
    static const EdgeInsetsGeometry infinity;


     EdgeInsetsGeometry();

    bool isNonNegative();

    double horizontal();

    double vertical();

    double along(Axis axis);

    Size collapsedSize();

    EdgeInsetsGeometry flipped();

    Size inflateSize(Size size);

    Size deflateSize(Size size);

    EdgeInsetsGeometry subtract(EdgeInsetsGeometry other);

    EdgeInsetsGeometry add(EdgeInsetsGeometry other);

    EdgeInsetsGeometry clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min);

    EdgeInsetsGeometry -();

    EdgeInsetsGeometry *(double other);

    EdgeInsetsGeometry /(double other);

    EdgeInsetsGeometry ~/(double other);

    EdgeInsetsGeometry %(double other);

    static EdgeInsetsGeometry lerp(EdgeInsetsGeometry a, EdgeInsetsGeometry b, double t);

    EdgeInsets resolve(TextDirection direction);

    String toString();

    bool ==(Object other);

    int hashCode();

private:

    double _bottom();

    double _end();

    double _left();

    double _right();

    double _start();

    double _top();

};

class EdgeInsets : EdgeInsetsGeometry {
public:
    static const EdgeInsets zero;

    double left;

    double top;

    double right;

    double bottom;


    void  fromLTRB(double bottom, double left, double right, double top);

    void  all(double value);

    void  only(double bottom, double left, double right, double top);

    void  symmetric(double horizontal, double vertical);

    void  fromWindowPadding(double devicePixelRatio, WindowPadding padding);

    Offset topLeft();

    Offset topRight();

    Offset bottomLeft();

    Offset bottomRight();

    EdgeInsets flipped();

    Rect inflateRect(Rect rect);

    Rect deflateRect(Rect rect);

    EdgeInsetsGeometry subtract(EdgeInsetsGeometry other);

    EdgeInsetsGeometry add(EdgeInsetsGeometry other);

    EdgeInsetsGeometry clamp(EdgeInsetsGeometry max, EdgeInsetsGeometry min);

    EdgeInsets -(EdgeInsets other);

    EdgeInsets +(EdgeInsets other);

    EdgeInsets -();

    EdgeInsets *(double other);

    EdgeInsets /(double other);

    EdgeInsets ~/(double other);

    EdgeInsets %(double other);

    static EdgeInsets lerp(EdgeInsets a, EdgeInsets b, double t);

    EdgeInsets resolve(TextDirection direction);

    EdgeInsets copyWith(double bottom, double left, double right, double top);

private:

    double _left();

    double _top();

    double _right();

    double _bottom();

    double _start();

    double _end();

};

class EdgeInsetsDirectional : EdgeInsetsGeometry {
public:
    static const EdgeInsetsDirectional zero;

    double start;

    double top;

    double end;

    double bottom;


    void  fromSTEB(double bottom, double end, double start, double top);

    void  only(double bottom, double end, double start, double top);

    void  all(double value);

    bool isNonNegative();

    EdgeInsetsDirectional flipped();

    EdgeInsetsGeometry subtract(EdgeInsetsGeometry other);

    EdgeInsetsGeometry add(EdgeInsetsGeometry other);

    EdgeInsetsDirectional -(EdgeInsetsDirectional other);

    EdgeInsetsDirectional +(EdgeInsetsDirectional other);

    EdgeInsetsDirectional -();

    EdgeInsetsDirectional *(double other);

    EdgeInsetsDirectional /(double other);

    EdgeInsetsDirectional ~/(double other);

    EdgeInsetsDirectional %(double other);

    static EdgeInsetsDirectional lerp(EdgeInsetsDirectional a, EdgeInsetsDirectional b, double t);

    EdgeInsets resolve(TextDirection direction);

private:

    double _start();

    double _top();

    double _end();

    double _bottom();

    double _left();

    double _right();

};

class _MixedEdgeInsets : EdgeInsetsGeometry {
public:

    void  fromLRSETB(double _bottom, double _end, double _left, double _right, double _start, double _top);

    bool isNonNegative();

    _MixedEdgeInsets -();

    _MixedEdgeInsets *(double other);

    _MixedEdgeInsets /(double other);

    _MixedEdgeInsets ~/(double other);

    _MixedEdgeInsets %(double other);

    EdgeInsets resolve(TextDirection direction);

private:
    double _left;

    double _right;

    double _start;

    double _end;

    double _top;

    double _bottom;


};

#endif