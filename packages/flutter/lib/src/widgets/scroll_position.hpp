#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_POSITION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_POSITION
#include <base.hpp>
#include "scroll_activity.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "notification_listener.hpp"
#include "page_storage.hpp"
#include "scroll_activity.hpp"
#include "scroll_context.hpp"
#include "scroll_metrics.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"


enum ScrollPositionAlignmentPolicy{
    explicit,
    keepVisibleAtEnd,
    keepVisibleAtStart,
} // end ScrollPositionAlignmentPolicy

class ScrollPositionCls : public ViewportOffsetCls {
public:
    ScrollPhysics physics;

    ScrollContext context;

    bool keepScrollOffset;

    String debugLabel;

    ValueNotifier<bool> isScrollingNotifier;


     ScrollPositionCls(ScrollContext context, String debugLabel, bool keepScrollOffset, ScrollPosition oldPosition, ScrollPhysics physics);

    virtual double minScrollExtent();

    virtual double maxScrollExtent();

    virtual bool hasContentDimensions();

    virtual double pixels();

    virtual bool hasPixels();

    virtual double viewportDimension();

    virtual bool hasViewportDimension();

    virtual bool haveDimensions();

    virtual void absorb(ScrollPosition other);

    virtual double setPixels(double newPixels);

    virtual void correctPixels(double value);

    virtual void correctBy(double correction);

    virtual void forcePixels(double value);

    virtual void saveScrollOffset();

    virtual void restoreScrollOffset();

    virtual void restoreOffset(bool initialRestore, double offset);

    virtual void saveOffset();

    virtual double applyBoundaryConditions(double value);

    virtual bool applyViewportDimension(double viewportDimension);

    virtual bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);

    virtual bool correctForNewDimensions(ScrollMetrics newPosition, ScrollMetrics oldPosition);

    virtual void applyNewDimensions();

    virtual Future<void> ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject object, RenderObject targetRenderObject);

    virtual Future<void> animateTo(Curve curve, Duration duration, double to) override;
    virtual void jumpTo(double value) override;
    virtual void pointerScroll(double delta);
    virtual Future<void> moveTo(bool clamp, Curve curve, Duration duration, double to);

    virtual bool allowImplicitScrolling();

    virtual void jumpToWithoutSettling(double value);
    virtual ScrollHoldController hold(VoidCallback holdCancelCallback);
    virtual Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);
    virtual ScrollActivity activity();

    virtual void beginActivity(ScrollActivity newActivity);

    virtual void didStartScroll();

    virtual void didUpdateScrollPositionBy(double delta);

    virtual void didEndScroll();

    virtual void didOverscrollBy(double value);

    virtual void didUpdateScrollDirection(ScrollDirection direction);

    virtual void didUpdateScrollMetrics();

    virtual bool recommendDeferredLoading(BuildContext context);

    virtual void dispose();

    virtual void notifyListeners();

    virtual void debugFillDescription(List<String> description);

private:
    double _minScrollExtent;

    double _maxScrollExtent;

    double _impliedVelocity;

    double _pixels;

    double _viewportDimension;

    bool _haveDimensions;

    bool _didChangeViewportDimensionOrReceiveCorrection;

    bool _pendingDimensions;

    ScrollMetrics _lastMetrics;

    bool _haveScheduledUpdateNotification;

    Axis _lastAxis;

    Set<SemanticsAction> _semanticActions;

    ScrollActivity _activity;


    virtual bool _isMetricsChanged();

    virtual void _updateSemanticActions();

};
using ScrollPosition = std::shared_ptr<ScrollPositionCls>;

class ScrollMetricsNotificationCls : public NotificationCls {
public:
    ScrollMetrics metrics;

    BuildContext context;


     ScrollMetricsNotificationCls(BuildContext context, ScrollMetrics metrics);
    virtual void debugFillDescription(List<String> description);

private:

};
using ScrollMetricsNotification = std::shared_ptr<ScrollMetricsNotificationCls>;


#endif