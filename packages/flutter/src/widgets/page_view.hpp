#ifndef PAGE_VIEW_H
#define PAGE_VIEW_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "basic.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "notification_listener.hpp"
#include "page_storage.hpp"
#include "scroll_configuration.hpp"
#include "scroll_context.hpp"
#include "scroll_controller.hpp"
#include "scroll_metrics.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "scroll_position_with_single_context.hpp"
#include "scroll_view.hpp"
#include "scrollable.hpp"
#include "sliver.hpp"
#include "sliver_fill.hpp"
#include "viewport.hpp"



class PageController : ScrollController {
public:
    int initialPage;

    bool keepPage;

    double viewportFraction;


     PageController(int initialPage, bool keepPage, double viewportFraction);

    double page();

    Future<void> animateToPage(Curve curve, Duration duration, int page);

    void jumpToPage(int page);

    Future<void> nextPage(Curve curve, Duration duration);

    Future<void> previousPage(Curve curve, Duration duration);

    ScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

    void attach(ScrollPosition position);

private:

};

class PageMetrics : FixedScrollMetrics {
public:
    double viewportFraction;


     PageMetrics(Unknown, Unknown, Unknown, Unknown, Unknown, double viewportFraction);

    PageMetrics copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction);

    double page();

private:

};

class _PagePosition : ScrollPositionWithSingleContext {
public:
    int initialPage;


    Future<void> ensureVisible(double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject object, RenderObject targetRenderObject);

    double viewportFraction();

    void  viewportFraction(double value);

    double getPageFromPixels(double pixels, double viewportDimension);

    double getPixelsFromPage(double page);

    double page();

    void saveScrollOffset();

    void restoreScrollOffset();

    void saveOffset();

    void restoreOffset(bool initialRestore, double offset);

    bool applyViewportDimension(double viewportDimension);

    void absorb(ScrollPosition other);

    bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);

    PageMetrics copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction);

private:
    double _pageToUseOnStartup;

    double _cachedPage;

    double _viewportFraction;


     _PagePosition(Unknown, int initialPage, bool keepPage, Unknown, Unknown, double viewportFraction);

    double _initialPageOffset();

};

class _ForceImplicitScrollPhysics : ScrollPhysics {
public:
    bool allowImplicitScrolling;


    _ForceImplicitScrollPhysics applyTo(ScrollPhysics ancestor);

private:

     _ForceImplicitScrollPhysics(bool allowImplicitScrolling, Unknown);

};

class PageScrollPhysics : ScrollPhysics {
public:

     PageScrollPhysics(Unknown);

    PageScrollPhysics applyTo(ScrollPhysics ancestor);

    Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

    bool allowImplicitScrolling();

private:

    double _getPage(ScrollMetrics position);

    double _getPixels(double page, ScrollMetrics position);

    double _getTargetPixels(ScrollMetrics position, Tolerance tolerance, double velocity);

};
PageController _defaultPageController;

const PageScrollPhysics _kPagePhysics;


class PageView : StatefulWidget {
public:
    bool allowImplicitScrolling;

    String restorationId;

    Axis scrollDirection;

    bool reverse;

    PageController controller;

    ScrollPhysics physics;

    bool pageSnapping;

    ValueChanged<int> onPageChanged;

    SliverChildDelegate childrenDelegate;

    DragStartBehavior dragStartBehavior;

    Clip clipBehavior;

    ScrollBehavior scrollBehavior;

    bool padEnds;


     PageView(bool allowImplicitScrolling, List<Widget> children, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Unknown, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    void  builder(bool allowImplicitScrolling, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Unknown, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    void  custom(bool allowImplicitScrolling, SliverChildDelegate childrenDelegate, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Unknown, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    State<PageView> createState();

private:

};

class _PageViewState : State<PageView> {
public:

    void initState();

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    int _lastReportedPage;


    AxisDirection _getDirection(BuildContext context);

};

#endif