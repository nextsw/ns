#ifndef SCROLL_POSITION_H
#define SCROLL_POSITION_H
#include <memory>
#include "scroll_activity.hpp"

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/physics.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
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

class ScrollPosition : ViewportOffset {
public:
    ScrollPhysics physics;

    ScrollContext context;

    bool keepScrollOffset;

    String debugLabel;

    ValueNotifier<bool> isScrollingNotifier;


     ScrollPosition(ScrollContext context, String debugLabel, bool keepScrollOffset, ScrollPosition oldPosition, ScrollPhysics physics);

    double minScrollExtent();

    double maxScrollExtent();

    bool hasContentDimensions();

    double pixels();

    bool hasPixels();

    double viewportDimension();

    bool hasViewportDimension();

    bool haveDimensions();

    void absorb(ScrollPosition other);

    double setPixels(double newPixels);

    void correctPixels(double value);

    void correctBy(double correction);

    void forcePixels(double value);

    void saveScrollOffset();

    void restoreScrollOffset();

    void restoreOffset(bool initialRestore, double offset);

    void saveOffset();

    double applyBoundaryConditions(double value);

    bool applyViewportDimension(double viewportDimension);

    bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);

    bool correctForNewDimensions(ScrollMetrics newPosition, ScrollMetrics oldPosition);

    void applyNewDimensions();

    Future<void> ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject object, RenderObject targetRenderObject);

    Future<void> animateTo(Curve curve, Duration duration, double to);

    void jumpTo(double value);

    void pointerScroll(double delta);

    Future<void> moveTo(bool clamp, Curve curve, Duration duration, double to);

    bool allowImplicitScrolling();

    void jumpToWithoutSettling(double value);

    ScrollHoldController hold(VoidCallback holdCancelCallback);

    Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

    ScrollActivity activity();

    void beginActivity(ScrollActivity newActivity);

    void didStartScroll();

    void didUpdateScrollPositionBy(double delta);

    void didEndScroll();

    void didOverscrollBy(double value);

    void didUpdateScrollDirection(ScrollDirection direction);

    void didUpdateScrollMetrics();

    bool recommendDeferredLoading(BuildContext context);

    void dispose();

    void notifyListeners();

    void debugFillDescription(List<String> description);

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


    bool _isMetricsChanged();

    void _updateSemanticActions();

};

class ScrollMetricsNotification : Notification {
public:
    ScrollMetrics metrics;

    BuildContext context;


     ScrollMetricsNotification(BuildContext context, ScrollMetrics metrics);

    void debugFillDescription(List<String> description);

private:

};

#endif