#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_CONTAINER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_CONTAINER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "image.hpp"


class DecoratedBoxCls : public SingleChildRenderObjectWidgetCls {
public:
    Decoration decoration;

    DecorationPosition position;


     DecoratedBoxCls(Unknown child, Decoration decoration, Unknown key, DecorationPosition position);

    virtual RenderDecoratedBox createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderDecoratedBox renderObject);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using DecoratedBox = std::shared_ptr<DecoratedBoxCls>;

class ContainerCls : public StatelessWidgetCls {
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


     ContainerCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Color color, BoxConstraints constraints, Decoration decoration, Decoration foregroundDecoration, double height, Unknown key, EdgeInsetsGeometry margin, EdgeInsetsGeometry padding, Matrix4 transform, AlignmentGeometry transformAlignment, double width);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    virtual EdgeInsetsGeometry _paddingIncludingDecoration();

};
using Container = std::shared_ptr<ContainerCls>;

class _DecorationClipperCls : public CustomClipperCls<Path> {
public:
    TextDirection textDirection;

    Decoration decoration;


    virtual Path getClip(Size size);

    virtual bool shouldReclip(_DecorationClipper oldClipper);

private:

     _DecorationClipperCls(Decoration decoration, TextDirection textDirection);

};
using _DecorationClipper = std::shared_ptr<_DecorationClipperCls>;


#endif