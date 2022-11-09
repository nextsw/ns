#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_FILL
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SLIVER_FILL
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"
#include "sliver.hpp"


class SliverFillViewportCls : public StatelessWidgetCls {
public:
    double viewportFraction;

    bool padEnds;

    SliverChildDelegate delegate;


     SliverFillViewportCls(SliverChildDelegate delegate, Unknown key, bool padEnds, double viewportFraction);

    virtual Widget build(BuildContext context);

private:

};
using SliverFillViewport = std::shared_ptr<SliverFillViewportCls>;

class _SliverFillViewportRenderObjectWidgetCls : public SliverMultiBoxAdaptorWidgetCls {
public:
    double viewportFraction;


    virtual RenderSliverFillViewport createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderSliverFillViewport renderObject);

private:

     _SliverFillViewportRenderObjectWidgetCls(Unknown delegate, double viewportFraction);

};
using _SliverFillViewportRenderObjectWidget = std::shared_ptr<_SliverFillViewportRenderObjectWidgetCls>;

class _SliverFractionalPaddingCls : public SingleChildRenderObjectWidgetCls {
public:
    double viewportFraction;


    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderSliverFractionalPadding renderObject);

private:

     _SliverFractionalPaddingCls(Widget sliver, double viewportFraction);

};
using _SliverFractionalPadding = std::shared_ptr<_SliverFractionalPaddingCls>;

class _RenderSliverFractionalPaddingCls : public RenderSliverEdgeInsetsPaddingCls {
public:

    virtual double viewportFraction();

    virtual void  viewportFraction(double newValue);

    virtual EdgeInsets resolvedPadding();

    virtual void performLayout();

private:
    SliverConstraints _lastResolvedConstraints;

    double _viewportFraction;

    EdgeInsets _resolvedPadding;


     _RenderSliverFractionalPaddingCls(double viewportFraction);

    virtual void _markNeedsResolution();

    virtual void _resolve();

};
using _RenderSliverFractionalPadding = std::shared_ptr<_RenderSliverFractionalPaddingCls>;

class SliverFillRemainingCls : public StatelessWidgetCls {
public:
    Widget child;

    bool hasScrollBody;

    bool fillOverscroll;


     SliverFillRemainingCls(Widget child, bool fillOverscroll, bool hasScrollBody, Unknown key);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using SliverFillRemaining = std::shared_ptr<SliverFillRemainingCls>;

class _SliverFillRemainingWithScrollableCls : public SingleChildRenderObjectWidgetCls {
public:

    virtual RenderSliverFillRemainingWithScrollable createRenderObject(BuildContext context);

private:

     _SliverFillRemainingWithScrollableCls(Unknown child);
};
using _SliverFillRemainingWithScrollable = std::shared_ptr<_SliverFillRemainingWithScrollableCls>;

class _SliverFillRemainingWithoutScrollableCls : public SingleChildRenderObjectWidgetCls {
public:

    virtual RenderSliverFillRemaining createRenderObject(BuildContext context);

private:

     _SliverFillRemainingWithoutScrollableCls(Unknown child);
};
using _SliverFillRemainingWithoutScrollable = std::shared_ptr<_SliverFillRemainingWithoutScrollableCls>;

class _SliverFillRemainingAndOverscrollCls : public SingleChildRenderObjectWidgetCls {
public:

    virtual RenderSliverFillRemainingAndOverscroll createRenderObject(BuildContext context);

private:

     _SliverFillRemainingAndOverscrollCls(Unknown child);
};
using _SliverFillRemainingAndOverscroll = std::shared_ptr<_SliverFillRemainingAndOverscrollCls>;


#endif