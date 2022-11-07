#ifndef SLIVER_PERSISTENT_HEADER_H
#define SLIVER_PERSISTENT_HEADER_H
#include <memory>

#include <math/math.hpp>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/semantics.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "viewport.hpp"
#include "viewport_offset.hpp"


Rect _trim(double bottom, double left, Rect original, double right, double top);


class OverScrollHeaderStretchConfiguration {
public:
    double stretchTriggerOffset;

    AsyncCallback onStretchTrigger;


     OverScrollHeaderStretchConfiguration(AsyncCallback onStretchTrigger, double stretchTriggerOffset);

private:

};

class PersistentHeaderShowOnScreenConfiguration {
public:
    double minShowOnScreenExtent;

    double maxShowOnScreenExtent;


     PersistentHeaderShowOnScreenConfiguration(double maxShowOnScreenExtent, double minShowOnScreenExtent);

private:

};

class RenderSliverPersistentHeader : RenderSliver {
public:
    OverScrollHeaderStretchConfiguration stretchConfiguration;


     RenderSliverPersistentHeader(RenderBox child, OverScrollHeaderStretchConfiguration stretchConfiguration);

    double maxExtent();

    double minExtent();

    double childExtent();

    void updateChild(bool overlapsContent, double shrinkOffset);

    void markNeedsLayout();

    void layoutChild(double maxExtent, bool overlapsContent, double scrollOffset);

    double childMainAxisPosition(RenderObject child);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _lastStretchOffset;

    bool _needsUpdateChild;

    double _lastShrinkOffset;

    bool _lastOverlapsContent;


};

class RenderSliverScrollingPersistentHeader : RenderSliverPersistentHeader {
public:

     RenderSliverScrollingPersistentHeader(Unknown, Unknown);

    double updateGeometry();

    void performLayout();

    double childMainAxisPosition(RenderBox child);

private:
    double _childPosition;


};

class RenderSliverPinnedPersistentHeader : RenderSliverPersistentHeader {
public:
    PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration;


     RenderSliverPinnedPersistentHeader(Unknown, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, Unknown);

    void performLayout();

    double childMainAxisPosition(RenderBox child);

    void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

private:

};

class FloatingHeaderSnapConfiguration {
public:
    Curve curve;

    Duration duration;


     FloatingHeaderSnapConfiguration(Curve curve, Duration duration);

private:

};

class RenderSliverFloatingPersistentHeader : RenderSliverPersistentHeader {
public:
    FloatingHeaderSnapConfiguration snapConfiguration;

    PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration;


     RenderSliverFloatingPersistentHeader(Unknown, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, Unknown, TickerProvider vsync);

    void detach();

    TickerProvider vsync();

    void  vsync(TickerProvider value);

    double updateGeometry();

    void updateScrollStartDirection(ScrollDirection direction);

    void maybeStartSnapAnimation(ScrollDirection direction);

    void maybeStopSnapAnimation(ScrollDirection direction);

    void performLayout();

    void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    double childMainAxisPosition(RenderBox child);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    AnimationController _controller;

    Animation<double> _animation;

    double _lastActualScrollOffset;

    double _effectiveScrollOffset;

    ScrollDirection _lastStartedScrollDirection;

    double _childPosition;

    TickerProvider _vsync;


    void _updateAnimation(Curve curve, Duration duration, double endValue);

};

class RenderSliverFloatingPinnedPersistentHeader : RenderSliverFloatingPersistentHeader {
public:

     RenderSliverFloatingPinnedPersistentHeader(Unknown, Unknown, Unknown, Unknown, Unknown);

    double updateGeometry();

private:

};

#endif