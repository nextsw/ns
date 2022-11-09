#ifndef PACKAGES_FLUTTER_SRC_PAINTING_ALIGNMENT
#define PACKAGES_FLUTTER_SRC_PAINTING_ALIGNMENT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic_types.hpp"


class AlignmentGeometryCls : public ObjectCls {
public:

     AlignmentGeometryCls();
    virtual AlignmentGeometry add(AlignmentGeometry other);

    virtual AlignmentGeometry operator-();
    virtual AlignmentGeometry operator*(double other);
    virtual AlignmentGeometry operator/(double other);
    virtual AlignmentGeometry operator~/(double other);
    virtual AlignmentGeometry operator%(double other);
    static AlignmentGeometry lerp(AlignmentGeometry a, AlignmentGeometry b, double t);

    virtual Alignment resolve(TextDirection direction);
    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    virtual double _x();
    virtual double _start();
    virtual double _y();
};
using AlignmentGeometry = std::shared_ptr<AlignmentGeometryCls>;

class AlignmentCls : public AlignmentGeometryCls {
public:
    double x;

    double y;

    static Alignment topLeft;

    static Alignment topCenter;

    static Alignment topRight;

    static Alignment centerLeft;

    static Alignment center;

    static Alignment centerRight;

    static Alignment bottomLeft;

    static Alignment bottomCenter;

    static Alignment bottomRight;


     AlignmentCls(double x, double y);

    virtual AlignmentGeometry add(AlignmentGeometry other);

    virtual Alignment operator-(Alignment other);

    virtual Alignment operator+(Alignment other);

    virtual Alignment operator-();

    virtual Alignment operator*(double other);

    virtual Alignment operator/(double other);

    virtual Alignment operator~/(double other);

    virtual Alignment operator%(double other);

    virtual Offset alongOffset(Offset other);

    virtual Offset alongSize(Size other);

    virtual Offset withinRect(Rect rect);

    virtual Rect inscribe(Rect rect, Size size);

    static Alignment lerp(Alignment a, Alignment b, double t);

    virtual Alignment resolve(TextDirection direction);

    virtual String toString();

private:

    virtual double _x();

    virtual double _start();

    virtual double _y();

    static String _stringify(double x, double y);

};
using Alignment = std::shared_ptr<AlignmentCls>;

class AlignmentDirectionalCls : public AlignmentGeometryCls {
public:
    double start;

    double y;

    static AlignmentDirectional topStart;

    static AlignmentDirectional topCenter;

    static AlignmentDirectional topEnd;

    static AlignmentDirectional centerStart;

    static AlignmentDirectional center;

    static AlignmentDirectional centerEnd;

    static AlignmentDirectional bottomStart;

    static AlignmentDirectional bottomCenter;

    static AlignmentDirectional bottomEnd;


     AlignmentDirectionalCls(double start, double y);

    virtual AlignmentGeometry add(AlignmentGeometry other);

    virtual AlignmentDirectional operator-(AlignmentDirectional other);

    virtual AlignmentDirectional operator+(AlignmentDirectional other);

    virtual AlignmentDirectional operator-();

    virtual AlignmentDirectional operator*(double other);

    virtual AlignmentDirectional operator/(double other);

    virtual AlignmentDirectional operator~/(double other);

    virtual AlignmentDirectional operator%(double other);

    static AlignmentDirectional lerp(AlignmentDirectional a, AlignmentDirectional b, double t);

    virtual Alignment resolve(TextDirection direction);

    virtual String toString();

private:

    virtual double _x();

    virtual double _start();

    virtual double _y();

    static String _stringify(double start, double y);

};
using AlignmentDirectional = std::shared_ptr<AlignmentDirectionalCls>;

class _MixedAlignmentCls : public AlignmentGeometryCls {
public:

    virtual _MixedAlignment operator-();

    virtual _MixedAlignment operator*(double other);

    virtual _MixedAlignment operator/(double other);

    virtual _MixedAlignment operator~/(double other);

    virtual _MixedAlignment operator%(double other);

    virtual Alignment resolve(TextDirection direction);

private:
    double _x;

    double _start;

    double _y;


     _MixedAlignmentCls(double _start, double _x, double _y);
};
using _MixedAlignment = std::shared_ptr<_MixedAlignmentCls>;

class TextAlignVerticalCls : public ObjectCls {
public:
    double y;

    static TextAlignVertical top;

    static TextAlignVertical center;

    static TextAlignVertical bottom;


     TextAlignVerticalCls(double y);

    virtual String toString();

private:

};
using TextAlignVertical = std::shared_ptr<TextAlignVerticalCls>;


#endif