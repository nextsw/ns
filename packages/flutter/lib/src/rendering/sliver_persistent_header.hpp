#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_PERSISTENT_HEADER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_PERSISTENT_HEADER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"
#include "viewport.hpp"
#include "viewport_offset.hpp"

Rect _trim(Rect original, double bottom, double left, double right, double top);


class OverScrollHeaderStretchConfigurationCls : public ObjectCls {
public:
    double stretchTriggerOffset;

    AsyncCallback onStretchTrigger;


     OverScrollHeaderStretchConfigurationCls(AsyncCallback onStretchTrigger, double stretchTriggerOffset);

private:

};
using OverScrollHeaderStretchConfiguration = std::shared_ptr<OverScrollHeaderStretchConfigurationCls>;

class PersistentHeaderShowOnScreenConfigurationCls : public ObjectCls {
public:
    double minShowOnScreenExtent;

    double maxShowOnScreenExtent;


     PersistentHeaderShowOnScreenConfigurationCls(double maxShowOnScreenExtent, double minShowOnScreenExtent);

private:

};
using PersistentHeaderShowOnScreenConfiguration = std::shared_ptr<PersistentHeaderShowOnScreenConfigurationCls>;

class RenderSliverPersistentHeaderCls : public RenderSliverCls {
public:
    OverScrollHeaderStretchConfiguration stretchConfiguration;


     RenderSliverPersistentHeaderCls(RenderBox child, OverScrollHeaderStretchConfiguration stretchConfiguration);

    virtual double maxExtent();
    virtual double minExtent();
    virtual double childExtent();

    virtual void updateChild(double shrinkOffset, bool overlapsContent);

    virtual void markNeedsLayout();

    virtual void layoutChild(double scrollOffset, double maxExtent, bool overlapsContent);

    virtual double childMainAxisPosition(RenderObject child);

    virtual bool hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    double _lastStretchOffset;

    bool _needsUpdateChild;

    double _lastShrinkOffset;

    bool _lastOverlapsContent;


};
using RenderSliverPersistentHeader = std::shared_ptr<RenderSliverPersistentHeaderCls>;

class RenderSliverScrollingPersistentHeaderCls : public RenderSliverPersistentHeaderCls {
public:

     RenderSliverScrollingPersistentHeaderCls(RenderBox child, OverScrollHeaderStretchConfiguration stretchConfiguration);
    virtual double updateGeometry();

    virtual void performLayout();

    virtual double childMainAxisPosition(RenderBox child);

private:
    double _childPosition;


};
using RenderSliverScrollingPersistentHeader = std::shared_ptr<RenderSliverScrollingPersistentHeaderCls>;

class RenderSliverPinnedPersistentHeaderCls : public RenderSliverPersistentHeaderCls {
public:
    PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration;


     RenderSliverPinnedPersistentHeaderCls(RenderBox child, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, OverScrollHeaderStretchConfiguration stretchConfiguration);
    virtual void performLayout();

    virtual double childMainAxisPosition(RenderBox child);

    virtual void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

private:

};
using RenderSliverPinnedPersistentHeader = std::shared_ptr<RenderSliverPinnedPersistentHeaderCls>;

class FloatingHeaderSnapConfigurationCls : public ObjectCls {
public:
    Curve curve;

    Duration duration;


     FloatingHeaderSnapConfigurationCls(Curve curve, Duration duration);

private:

};
using FloatingHeaderSnapConfiguration = std::shared_ptr<FloatingHeaderSnapConfigurationCls>;

class RenderSliverFloatingPersistentHeaderCls : public RenderSliverPersistentHeaderCls {
public:
    FloatingHeaderSnapConfiguration snapConfiguration;

    PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration;


     RenderSliverFloatingPersistentHeaderCls(RenderBox child, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, OverScrollHeaderStretchConfiguration stretchConfiguration, TickerProvider vsync);

    virtual void detach();

    virtual TickerProvider vsync();

    virtual void  vsync(TickerProvider value);

    virtual double updateGeometry();

    virtual void updateScrollStartDirection(ScrollDirection direction);

    virtual void maybeStartSnapAnimation(ScrollDirection direction);

    virtual void maybeStopSnapAnimation(ScrollDirection direction);

    virtual void performLayout();

    virtual void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    virtual double childMainAxisPosition(RenderBox child);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    AnimationController _controller;

    Animation<double> _animation;

    double _lastActualScrollOffset;

    double _effectiveScrollOffset;

    ScrollDirection _lastStartedScrollDirection;

    double _childPosition;

    TickerProvider _vsync;


    virtual void _updateAnimation(Duration duration, double endValue, Curve curve);

};
using RenderSliverFloatingPersistentHeader = std::shared_ptr<RenderSliverFloatingPersistentHeaderCls>;

class RenderSliverFloatingPinnedPersistentHeaderCls : public RenderSliverFloatingPersistentHeaderCls {
public:

     RenderSliverFloatingPinnedPersistentHeaderCls(RenderBox child, PersistentHeaderShowOnScreenConfiguration showOnScreenConfiguration, FloatingHeaderSnapConfiguration snapConfiguration, OverScrollHeaderStretchConfiguration stretchConfiguration, TickerProvider vsync);
    virtual double updateGeometry();

private:

};
using RenderSliverFloatingPinnedPersistentHeader = std::shared_ptr<RenderSliverFloatingPinnedPersistentHeaderCls>;


#endif