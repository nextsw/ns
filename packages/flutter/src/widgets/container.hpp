#ifndef CONTAINER_H
#define CONTAINER_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "image.hpp"



class DecoratedBox : SingleChildRenderObjectWidget {
public:
    Decoration decoration;

    DecorationPosition position;


     DecoratedBox(Unknown, Decoration decoration, Unknown, DecorationPosition position);

    RenderDecoratedBox createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderDecoratedBox renderObject);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class Container : StatelessWidget {
public:
    Widget child;

    AlignmentGeometry alignment;

    EdgeInsetsGeometry padding;

    Color color;

    Decoration decoration;

    Decoration foregroundDecoration;

    BoxConstraints constraints;

    EdgeInsetsGeometry margin;

    Matrix4 transform;

    AlignmentGeometry transformAlignment;

    Clip clipBehavior;


     Container(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Decoration decoration, Decoration foregroundDecoration, double height, Unknown, EdgeInsetsGeometry margin, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    EdgeInsetsGeometry _paddingIncludingDecoration();

};

class _DecorationClipper : CustomClipper<Path> {
public:
    TextDirection textDirection;

    Decoration decoration;


    Path getClip(Size size);

    bool shouldReclip(_DecorationClipper oldClipper);

private:

     _DecorationClipper(Decoration decoration, TextDirection textDirection);

};

#endif