#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_LIST_WHEEL_SCROLL_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_LIST_WHEEL_SCROLL_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "notification_listener.hpp"
#include "scroll_configuration.hpp"
#include "scroll_context.hpp"
#include "scroll_controller.hpp"
#include "scroll_metrics.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "scroll_position_with_single_context.hpp"
#include "scrollable.hpp"


class ListWheelChildDelegateCls : public ObjectCls {
public:

    virtual Widget build(BuildContext context, int index);
    virtual int estimatedChildCount();
    virtual int trueIndexOf(int index);

    virtual bool shouldRebuild(ListWheelChildDelegate oldDelegate);
private:

};
using ListWheelChildDelegate = std::shared_ptr<ListWheelChildDelegateCls>;

class ListWheelChildListDelegateCls : public ListWheelChildDelegateCls {
public:
    List<Widget> children;


     ListWheelChildListDelegateCls(List<Widget> children);

    virtual int estimatedChildCount();

    virtual Widget build(BuildContext context, int index);

    virtual bool shouldRebuild(ListWheelChildListDelegate oldDelegate);

private:

};
using ListWheelChildListDelegate = std::shared_ptr<ListWheelChildListDelegateCls>;

class ListWheelChildLoopingListDelegateCls : public ListWheelChildDelegateCls {
public:
    List<Widget> children;


     ListWheelChildLoopingListDelegateCls(List<Widget> children);

    virtual int estimatedChildCount();

    virtual int trueIndexOf(int index);

    virtual Widget build(BuildContext context, int index);

    virtual bool shouldRebuild(ListWheelChildLoopingListDelegate oldDelegate);

private:

};
using ListWheelChildLoopingListDelegate = std::shared_ptr<ListWheelChildLoopingListDelegateCls>;

class ListWheelChildBuilderDelegateCls : public ListWheelChildDelegateCls {
public:
    NullableIndexedWidgetBuilder builder;

    int childCount;


     ListWheelChildBuilderDelegateCls(NullableIndexedWidgetBuilder builder, int childCount);

    virtual int estimatedChildCount();

    virtual Widget build(BuildContext context, int index);

    virtual bool shouldRebuild(ListWheelChildBuilderDelegate oldDelegate);

private:

};
using ListWheelChildBuilderDelegate = std::shared_ptr<ListWheelChildBuilderDelegateCls>;

class FixedExtentScrollControllerCls : public ScrollControllerCls {
public:
    int initialItem;


     FixedExtentScrollControllerCls(int initialItem);

    virtual int selectedItem();

    virtual Future<void> animateToItem(Curve curve, Duration duration, int itemIndex);

    virtual void jumpToItem(int itemIndex);

    virtual ScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

private:

};
using FixedExtentScrollController = std::shared_ptr<FixedExtentScrollControllerCls>;

class FixedExtentMetricsCls : public FixedScrollMetricsCls {
public:
    int itemIndex;


     FixedExtentMetricsCls(Unknown axisDirection, int itemIndex, Unknown maxScrollExtent, Unknown minScrollExtent, Unknown pixels, Unknown viewportDimension);
    virtual FixedExtentMetrics copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

private:

};
using FixedExtentMetrics = std::shared_ptr<FixedExtentMetricsCls>;
int _getItemFromOffset(double itemExtent, double maxScrollExtent, double minScrollExtent, double offset);

double _clipOffsetToScrollableRange(double maxScrollExtent, double minScrollExtent, double offset);


class _FixedExtentScrollPositionCls : public ScrollPositionWithSingleContextCls {
public:

    virtual double itemExtent();

    virtual int itemIndex();

    virtual FixedExtentMetrics copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

private:

     _FixedExtentScrollPositionCls(Unknown context, int initialItem, Unknown oldPosition, Unknown physics);

    static double _getItemExtentFromScrollContext(ScrollContext context);

};
using _FixedExtentScrollPosition = std::shared_ptr<_FixedExtentScrollPositionCls>;

class _FixedExtentScrollableCls : public ScrollableCls {
public:
    double itemExtent;


    virtual _FixedExtentScrollableState createState();

private:

     _FixedExtentScrollableCls(Unknown controller, double itemExtent, Unknown physics, Unknown restorationId, Unknown scrollBehavior, Unknown viewportBuilder);
};
using _FixedExtentScrollable = std::shared_ptr<_FixedExtentScrollableCls>;

class _FixedExtentScrollableStateCls : public ScrollableStateCls {
public:

    virtual double itemExtent();

private:

};
using _FixedExtentScrollableState = std::shared_ptr<_FixedExtentScrollableStateCls>;

class FixedExtentScrollPhysicsCls : public ScrollPhysicsCls {
public:

     FixedExtentScrollPhysicsCls(Unknown parent);
    virtual FixedExtentScrollPhysics applyTo(ScrollPhysics ancestor);

    virtual Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

private:

};
using FixedExtentScrollPhysics = std::shared_ptr<FixedExtentScrollPhysicsCls>;

class ListWheelScrollViewCls : public StatefulWidgetCls {
public:
    ScrollController controller;

    ScrollPhysics physics;

    double diameterRatio;

    double perspective;

    double offAxisFraction;

    bool useMagnifier;

    double magnification;

    double overAndUnderCenterOpacity;

    double itemExtent;

    double squeeze;

    ValueChanged<int> onSelectedItemChanged;

    bool renderChildrenOutsideViewport;

    ListWheelChildDelegate childDelegate;

    Clip clipBehavior;

    String restorationId;

    ScrollBehavior scrollBehavior;


     ListWheelScrollViewCls(List<Widget> children, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Unknown key, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier);

    virtual void  useDelegate(ListWheelChildDelegate childDelegate, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Unknown key, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier);

    virtual State<ListWheelScrollView> createState();

private:

};
using ListWheelScrollView = std::shared_ptr<ListWheelScrollViewCls>;

class _ListWheelScrollViewStateCls : public StateCls<ListWheelScrollView> {
public:
    ScrollController scrollController;


    virtual void initState();

    virtual void didUpdateWidget(ListWheelScrollView oldWidget);

    virtual Widget build(BuildContext context);

private:
    int _lastReportedItemIndex;


    virtual bool _handleScrollNotification(ScrollNotification notification);

};
using _ListWheelScrollViewState = std::shared_ptr<_ListWheelScrollViewStateCls>;

class ListWheelElementCls : public RenderObjectElementCls {
public:

     ListWheelElementCls(ListWheelViewport widget);
    virtual RenderListWheelViewport renderObject();

    virtual void update(ListWheelViewport newWidget);

    virtual int childCount();

    virtual void performRebuild();

    virtual Widget retrieveWidget(int index);

    virtual bool childExistsAt(int index);

    virtual void createChild(RenderBox after, int index);

    virtual void removeChild(RenderBox child);

    virtual Element updateChild(Element child, Object newSlot, Widget newWidget);

    virtual void insertRenderObjectChild(RenderObject child, int slot);

    virtual void moveRenderObjectChild(RenderObject child, int newSlot, int oldSlot);

    virtual void removeRenderObjectChild(RenderObject child, int slot);

    virtual void visitChildren(ElementVisitor visitor);

    virtual void forgetChild(Element child);

private:
    Map<int, Widget> _childWidgets;

    SplayTreeMap<int, Element> _childElements;


};
using ListWheelElement = std::shared_ptr<ListWheelElementCls>;

class ListWheelViewportCls : public RenderObjectWidgetCls {
public:
    double diameterRatio;

    double perspective;

    double offAxisFraction;

    bool useMagnifier;

    double magnification;

    double overAndUnderCenterOpacity;

    double itemExtent;

    double squeeze;

    bool renderChildrenOutsideViewport;

    ViewportOffset offset;

    ListWheelChildDelegate childDelegate;

    Clip clipBehavior;


     ListWheelViewportCls(ListWheelChildDelegate childDelegate, Clip clipBehavior, double diameterRatio, double itemExtent, Unknown key, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier);

    virtual ListWheelElement createElement();

    virtual RenderListWheelViewport createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderListWheelViewport renderObject);

private:

};
using ListWheelViewport = std::shared_ptr<ListWheelViewportCls>;


#endif