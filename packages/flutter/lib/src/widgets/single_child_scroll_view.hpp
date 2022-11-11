#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SINGLE_CHILD_SCROLL_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SINGLE_CHILD_SCROLL_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
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


class SingleChildScrollViewCls : public StatelessWidgetCls {
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


     SingleChildScrollViewCls(Widget child, Clip clipBehavior, ScrollController controller, DragStartBehavior dragStartBehavior, Key key, ScrollViewKeyboardDismissBehavior keyboardDismissBehavior, EdgeInsetsGeometry padding, ScrollPhysics physics, bool primary, String restorationId, bool reverse, Axis scrollDirection);

    virtual Widget build(BuildContext context);

private:

    virtual AxisDirection _getDirection(BuildContext context);

};
using SingleChildScrollView = std::shared_ptr<SingleChildScrollViewCls>;

class _SingleChildViewportCls : public SingleChildRenderObjectWidgetCls {
public:
    AxisDirection axisDirection;

    ViewportOffset offset;

    Clip clipBehavior;


    virtual _RenderSingleChildViewport createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderSingleChildViewport renderObject);

    virtual SingleChildRenderObjectElement createElement();

private:

     _SingleChildViewportCls(AxisDirection axisDirection, Widget child, Clip clipBehavior, ViewportOffset offset);

};
using _SingleChildViewport = std::shared_ptr<_SingleChildViewportCls>;

class _SingleChildViewportElementCls : public SingleChildRenderObjectElementCls {
public:

private:

     _SingleChildViewportElementCls(_SingleChildViewport widget);
};
using _SingleChildViewportElement = std::shared_ptr<_SingleChildViewportElementCls>;

class _RenderSingleChildViewportCls : public RenderBoxCls {
public:

    virtual AxisDirection axisDirection();

    virtual void  axisDirection(AxisDirection value);

    virtual Axis axis();

    virtual ViewportOffset offset();

    virtual void  offset(ViewportOffset value);

    virtual double cacheExtent();

    virtual void  cacheExtent(double value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual void setupParentData(RenderObject child);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual bool isRepaintBoundary();

    virtual double computeMinIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMinIntrinsicHeight(double width);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void dispose();

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual bool hitTestChildren(BoxHitTestResult result, Offset position);

    virtual RevealedOffset getOffsetToReveal(RenderObject target, double alignment, Rect rect);

    virtual void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual Rect describeSemanticsClip(RenderObject child);

private:
    AxisDirection _axisDirection;

    ViewportOffset _offset;

    double _cacheExtent;

    Clip _clipBehavior;

    LayerHandle<ClipRectLayer> _clipRectLayer;


     _RenderSingleChildViewportCls(AxisDirection axisDirection, double cacheExtent, RenderBox child, Clip clipBehavior, ViewportOffset offset);

    virtual void _hasScrolled();

    virtual double _viewportExtent();

    virtual double _minScrollExtent();

    virtual double _maxScrollExtent();

    virtual BoxConstraints _getInnerConstraints(BoxConstraints constraints);

    virtual Offset _paintOffset();

    virtual Offset _paintOffsetForPosition(double position);

    virtual bool _shouldClipAtPaintOffset(Offset paintOffset);

};
using _RenderSingleChildViewport = std::shared_ptr<_RenderSingleChildViewportCls>;


#endif