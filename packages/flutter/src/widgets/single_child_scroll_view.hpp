#ifndef SINGLE_CHILD_SCROLL_VIEW_H
#define SINGLE_CHILD_SCROLL_VIEW_H
#include <memory>

#include <math/math.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "notification_listener.hpp"
#include "primary_scroll_controller.hpp"
#include "scroll_controller.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scroll_view.hpp"
#include "scrollable.hpp"



class SingleChildScrollView : StatelessWidget {
public:
    Axis scrollDirection;

    bool reverse;

    EdgeInsetsGeometry padding;

    ScrollController controller;

    bool primary;

    ScrollPhysics physics;

    Widget child;

    DragStartBehavior dragStartBehavior;

    Clip clipBehavior;

    String restorationId;

    ScrollViewKeyboardDismissBehavior keyboardDismissBehavior;


     SingleChildScrollView(Widget child, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Unknown, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection);

    Widget build(BuildContext context);

private:

    AxisDirection _getDirection(BuildContext context);

};

class _SingleChildViewport : SingleChildRenderObjectWidget {
public:
    AxisDirection axisDirection;

    ViewportOffset offset;

    Clip clipBehavior;


    _RenderSingleChildViewport createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderSingleChildViewport renderObject);

    SingleChildRenderObjectElement createElement();

private:

     _SingleChildViewport(AxisDirection axisDirection, Unknown, Clip clipBehavior, ViewportOffset offset);

};

class _SingleChildViewportElement : SingleChildRenderObjectElement {
public:

private:

     _SingleChildViewportElement(_SingleChildViewport widget);

};

class _RenderSingleChildViewport : RenderBox {
public:

    AxisDirection axisDirection();

    void  axisDirection(AxisDirection value);

    Axis axis();

    ViewportOffset offset();

    void  offset(ViewportOffset value);

    double cacheExtent();

    void  cacheExtent(double value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    void setupParentData(RenderObject child);

    void attach(PipelineOwner owner);

    void detach();

    bool isRepaintBoundary();

    double computeMinIntrinsicWidth(double height);

    double computeMaxIntrinsicWidth(double height);

    double computeMinIntrinsicHeight(double width);

    double computeMaxIntrinsicHeight(double width);

    Size computeDryLayout(BoxConstraints constraints);

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    void dispose();

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    Rect describeApproximatePaintClip(RenderObject child);

    bool hitTestChildren(Offset position, BoxHitTestResult result);

    RevealedOffset getOffsetToReveal(double alignment, Rect rect, RenderObject target);

    void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    Rect describeSemanticsClip(RenderObject child);

private:
    AxisDirection _axisDirection;

    ViewportOffset _offset;

    double _cacheExtent;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


     _RenderSingleChildViewport(AxisDirection axisDirection, double cacheExtent, RenderBox child, Clip clipBehavior, ViewportOffset offset);

    void _hasScrolled();

    double _viewportExtent();

    double _minScrollExtent();

    double _maxScrollExtent();

    BoxConstraints _getInnerConstraints(BoxConstraints constraints);

    Offset _paintOffset();

    Offset _paintOffsetForPosition(double position);

    bool _shouldClipAtPaintOffset(Offset paintOffset);

};

#endif