#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PAGE_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_PAGE_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
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


class PageControllerCls : public ScrollControllerCls {
public:
    int initialPage;

    bool keepPage;

    double viewportFraction;


     PageControllerCls(int initialPage, bool keepPage, double viewportFraction);

    virtual double page();

    virtual Future<void> animateToPage(int page, Curve curve, Duration duration);

    virtual void jumpToPage(int page);

    virtual Future<void> nextPage(Curve curve, Duration duration);

    virtual Future<void> previousPage(Curve curve, Duration duration);

    virtual ScrollPosition createScrollPosition(ScrollPhysics physics, ScrollContext context, ScrollPosition oldPosition);

    virtual void attach(ScrollPosition position);

private:

};
using PageController = std::shared_ptr<PageControllerCls>;

class PageMetricsCls : public FixedScrollMetricsCls {
public:
    double viewportFraction;


     PageMetricsCls(AxisDirection axisDirection, Unknown maxScrollExtent, Unknown minScrollExtent, Unknown pixels, Unknown viewportDimension, double viewportFraction);
    virtual PageMetrics copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction);

    virtual double page();

private:

};
using PageMetrics = std::shared_ptr<PageMetricsCls>;

class _PagePositionCls : public ScrollPositionWithSingleContextCls {
public:
    int initialPage;


    virtual Future<void> ensureVisible(RenderObject object, double alignment, ScrollPositionAlignmentPolicy alignmentPolicy, Curve curve, Duration duration, RenderObject targetRenderObject);

    virtual double viewportFraction();

    virtual void  viewportFraction(double value);

    virtual double getPageFromPixels(double pixels, double viewportDimension);

    virtual double getPixelsFromPage(double page);

    virtual double page();

    virtual void saveScrollOffset();

    virtual void restoreScrollOffset();

    virtual void saveOffset();

    virtual void restoreOffset(double offset, bool initialRestore);

    virtual bool applyViewportDimension(double viewportDimension);

    virtual void absorb(ScrollPosition other);

    virtual bool applyContentDimensions(double minScrollExtent, double maxScrollExtent);

    virtual PageMetrics copyWith(AxisDirection axisDirection, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension, double viewportFraction);

private:
    double _pageToUseOnStartup;

    double _cachedPage;

    double _viewportFraction;


     _PagePositionCls(ScrollContext context, int initialPage, bool keepPage, Unknown oldPosition, ScrollPhysics physics, double viewportFraction);

    virtual double _initialPageOffset();

};
using _PagePosition = std::shared_ptr<_PagePositionCls>;

class _ForceImplicitScrollPhysicsCls : public ScrollPhysicsCls {
public:
    bool allowImplicitScrolling;


    virtual _ForceImplicitScrollPhysics applyTo(ScrollPhysics ancestor);

private:

     _ForceImplicitScrollPhysicsCls(bool allowImplicitScrolling, ScrollPhysics parent);

};
using _ForceImplicitScrollPhysics = std::shared_ptr<_ForceImplicitScrollPhysicsCls>;

class PageScrollPhysicsCls : public ScrollPhysicsCls {
public:

     PageScrollPhysicsCls(ScrollPhysics parent);
    virtual PageScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

    virtual bool allowImplicitScrolling();

private:

    virtual double _getPage(ScrollMetrics position);

    virtual double _getPixels(ScrollMetrics position, double page);

    virtual double _getTargetPixels(ScrollMetrics position, Tolerance tolerance, double velocity);

};
using PageScrollPhysics = std::shared_ptr<PageScrollPhysicsCls>;
PageController _defaultPageController;

PageScrollPhysics _kPagePhysics;


class PageViewCls : public StatefulWidgetCls {
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


     PageViewCls(bool allowImplicitScrolling, List<Widget> children, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Key key, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    virtual void  builder(bool allowImplicitScrolling, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, ChildIndexGetter findChildIndexCallback, IndexedWidgetBuilder itemBuilder, int itemCount, Key key, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    virtual void  custom(bool allowImplicitScrolling, SliverChildDelegate childrenDelegate, Clip clipBehavior, PageController controller, DragStartBehavior dragStartBehavior, Key key, ValueChanged<int> onPageChanged, bool padEnds, bool pageSnapping, ScrollPhysics physics, String restorationId, bool reverse, ScrollBehavior scrollBehavior, Axis scrollDirection);

    virtual State<PageView> createState();

private:

};
using PageView = std::shared_ptr<PageViewCls>;

class _PageViewStateCls : public StateCls<PageView> {
public:

    virtual void initState();

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    int _lastReportedPage;


    virtual AxisDirection _getDirection(BuildContext context);

};
using _PageViewState = std::shared_ptr<_PageViewStateCls>;


#endif