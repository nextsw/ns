#ifndef ALIGNMENT_H
#define ALIGNMENT_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include "basic_types.hpp"



class AlignmentGeometry {
public:

     AlignmentGeometry();

    AlignmentGeometry add(AlignmentGeometry other);

    AlignmentGeometry -();

    AlignmentGeometry *(double other);

    AlignmentGeometry /(double other);

    AlignmentGeometry ~/(double other);

    AlignmentGeometry %(double other);

    static AlignmentGeometry lerp(AlignmentGeometry a, AlignmentGeometry b, double t);

    Alignment resolve(TextDirection direction);

    String toString();

    bool ==(Object other);

    int hashCode();

private:

    double _x();

    double _start();

    double _y();

};

class Alignment : AlignmentGeometry {
public:
    double x;

    double y;

    static const Alignment topLeft;

    static const Alignment topCenter;

    static const Alignment topRight;

    static const Alignment centerLeft;

    static const Alignment center;

    static const Alignment centerRight;

    static const Alignment bottomLeft;

    static const Alignment bottomCenter;

    static const Alignment bottomRight;


     Alignment(double x, double y);

    AlignmentGeometry add(AlignmentGeometry other);

    Alignment -(Alignment other);

    Alignment +(Alignment other);

    Alignment -();

    Alignment *(double other);

    Alignment /(double other);

    Alignment ~/(double other);

    Alignment %(double other);

    Offset alongOffset(Offset other);

    Offset alongSize(Size other);

    Offset withinRect(Rect rect);

    Rect inscribe(Rect rect, Size size);

    static Alignment lerp(Alignment a, Alignment b, double t);

    Alignment resolve(TextDirection direction);

    String toString();

private:

    double _x();

    double _start();

    double _y();

    static String _stringify(double x, double y);

};

class AlignmentDirectional : AlignmentGeometry {
public:
    double start;

    double y;

    static const AlignmentDirectional topStart;

    static const AlignmentDirectional topCenter;

    static const AlignmentDirectional topEnd;

    static const AlignmentDirectional centerStart;

    static const AlignmentDirectional center;

    static const AlignmentDirectional centerEnd;

    static const AlignmentDirectional bottomStart;

    static const AlignmentDirectional bottomCenter;

    static const AlignmentDirectional bottomEnd;


     AlignmentDirectional(double start, double y);

    AlignmentGeometry add(AlignmentGeometry other);

    AlignmentDirectional -(AlignmentDirectional other);

    AlignmentDirectional +(AlignmentDirectional other);

    AlignmentDirectional -();

    AlignmentDirectional *(double other);

    AlignmentDirectional /(double other);

    AlignmentDirectional ~/(double other);

    AlignmentDirectional %(double other);

    static AlignmentDirectional lerp(AlignmentDirectional a, AlignmentDirectional b, double t);

    Alignment resolve(TextDirection direction);

    String toString();

private:

    double _x();

    double _start();

    double _y();

    static String _stringify(double start, double y);

};

class _MixedAlignment : AlignmentGeometry {
public:

    _MixedAlignment -();

    _MixedAlignment *(double other);

    _MixedAlignment /(double other);

    _MixedAlignment ~/(double other);

    _MixedAlignment %(double other);

    Alignment resolve(TextDirection direction);

private:
    double _x;

    double _start;

    double _y;


     _MixedAlignment(double _start, double _x, double _y);

};

class TextAlignVertical {
public:
    double y;

    static const TextAlignVertical top;

    static const TextAlignVertical center;

    static const TextAlignVertical bottom;


     TextAlignVertical(double y);

    String toString();

private:

};

#endif