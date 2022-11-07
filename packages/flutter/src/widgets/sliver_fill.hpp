#ifndef SLIVER_FILL_H
#define SLIVER_FILL_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include "framework.hpp"
#include "sliver.hpp"



class SliverFillViewport : StatelessWidget {
public:
    double viewportFraction;

    bool padEnds;

    SliverChildDelegate delegate;


     SliverFillViewport(SliverChildDelegate delegate, Unknown, bool padEnds, double viewportFraction);

    Widget build(BuildContext context);

private:

};

class _SliverFillViewportRenderObjectWidget : SliverMultiBoxAdaptorWidget {
public:
    double viewportFraction;


    RenderSliverFillViewport createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderSliverFillViewport renderObject);

private:

     _SliverFillViewportRenderObjectWidget(Unknown, double viewportFraction);

};

class _SliverFractionalPadding : SingleChildRenderObjectWidget {
public:
    double viewportFraction;


    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderSliverFractionalPadding renderObject);

private:

     _SliverFractionalPadding(Widget sliver, double viewportFraction);

};

class _RenderSliverFractionalPadding : RenderSliverEdgeInsetsPadding {
public:

    double viewportFraction();

    void  viewportFraction(double newValue);

    EdgeInsets resolvedPadding();

    void performLayout();

private:
    SliverConstraints _lastResolvedConstraints;

    double _viewportFraction;

    EdgeInsets _resolvedPadding;


     _RenderSliverFractionalPadding(double viewportFraction);

    void _markNeedsResolution();

    void _resolve();

};

class SliverFillRemaining : StatelessWidget {
public:
    Widget child;

    bool hasScrollBody;

    bool fillOverscroll;


     SliverFillRemaining(Widget child, bool fillOverscroll, bool hasScrollBody, Unknown);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _SliverFillRemainingWithScrollable : SingleChildRenderObjectWidget {
public:

    RenderSliverFillRemainingWithScrollable createRenderObject(BuildContext context);

private:

     _SliverFillRemainingWithScrollable(Unknown);

};

class _SliverFillRemainingWithoutScrollable : SingleChildRenderObjectWidget {
public:

    RenderSliverFillRemaining createRenderObject(BuildContext context);

private:

     _SliverFillRemainingWithoutScrollable(Unknown);

};

class _SliverFillRemainingAndOverscroll : SingleChildRenderObjectWidget {
public:

    RenderSliverFillRemainingAndOverscroll createRenderObject(BuildContext context);

private:

     _SliverFillRemainingAndOverscroll(Unknown);

};

#endif