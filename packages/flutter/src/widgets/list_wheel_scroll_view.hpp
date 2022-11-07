#ifndef LIST_WHEEL_SCROLL_VIEW_H
#define LIST_WHEEL_SCROLL_VIEW_H
#include <memory>

#include <collection/collection.hpp>
#include <math/math.hpp>
#include <flutter/physics.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
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



class ListWheelChildDelegate {
public:

    Widget build(BuildContext context, int index);

    int estimatedChildCount();

    int trueIndexOf(int index);

    bool shouldRebuild(ListWheelChildDelegate oldDelegate);

private:

};

class ListWheelChildListDelegate : ListWheelChildDelegate {
public:
    List<Widget> children;


     ListWheelChildListDelegate(List<Widget> children);

    int estimatedChildCount();

    Widget build(BuildContext context, int index);

    bool shouldRebuild(ListWheelChildListDelegate oldDelegate);

private:

};

class ListWheelChildLoopingListDelegate : ListWheelChildDelegate {
public:
    List<Widget> children;


     ListWheelChildLoopingListDelegate(List<Widget> children);

    int estimatedChildCount();

    int trueIndexOf(int index);

    Widget build(BuildContext context, int index);

    bool shouldRebuild(ListWheelChildLoopingListDelegate oldDelegate);

private:

};

class ListWheelChildBuilderDelegate : ListWheelChildDelegate {
public:
    NullableIndexedWidgetBuilder builder;

    int childCount;


     ListWheelChildBuilderDelegate(NullableIndexedWidgetBuilder builder, int childCount);

    int estimatedChildCount();

    Widget build(BuildContext context, int index);

    bool shouldRebuild(ListWheelChildBuilderDelegate oldDelegate);

private:

};

class FixedExtentScrollController : ScrollController {
public:
    int initialItem;


     FixedExtentScrollController(int initialItem);

    int selectedItem();

    Future<void> animateToItem(Curve curve, Duration duration, int itemIndex);

    void jumpToItem(int itemIndex);

    ScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

private:

};

class FixedExtentMetrics : FixedScrollMetrics {
public:
    int itemIndex;


     FixedExtentMetrics(Unknown, int itemIndex, Unknown, Unknown, Unknown, Unknown);

    FixedExtentMetrics copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

private:

};
int _getItemFromOffset(double itemExtent, double maxScrollExtent, double minScrollExtent, double offset);

double _clipOffsetToScrollableRange(double maxScrollExtent, double minScrollExtent, double offset);


class _FixedExtentScrollPosition : ScrollPositionWithSingleContext {
public:

    double itemExtent();

    int itemIndex();

    FixedExtentMetrics copyWith(AxisDirection axisDirection, int itemIndex, double maxScrollExtent, double minScrollExtent, double pixels, double viewportDimension);

private:

     _FixedExtentScrollPosition(Unknown, int initialItem, Unknown, Unknown);

    static double _getItemExtentFromScrollContext(ScrollContext context);

};

class _FixedExtentScrollable : Scrollable {
public:
    double itemExtent;


    _FixedExtentScrollableState createState();

private:

     _FixedExtentScrollable(Unknown, double itemExtent, Unknown, Unknown, Unknown, Unknown);

};

class _FixedExtentScrollableState : ScrollableState {
public:

    double itemExtent();

private:

};

class FixedExtentScrollPhysics : ScrollPhysics {
public:

     FixedExtentScrollPhysics(Unknown);

    FixedExtentScrollPhysics applyTo(ScrollPhysics ancestor);

    Simulation createBallisticSimulation(ScrollMetrics position, double velocity);

private:

};

class ListWheelScrollView : StatefulWidget {
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


     ListWheelScrollView(List<Widget> children, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Unknown, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier);

    void  useDelegate(ListWheelChildDelegate childDelegate, Clip clipBehavior, ScrollController controller, double diameterRatio, double itemExtent, Unknown, double magnification, double offAxisFraction, ValueChanged<int> onSelectedItemChanged, double overAndUnderCenterOpacity, double perspective, ScrollPhysics physics, bool renderChildrenOutsideViewport, String restorationId, ScrollBehavior scrollBehavior, double squeeze, bool useMagnifier);

    State<ListWheelScrollView> createState();

private:

};

class _ListWheelScrollViewState : State<ListWheelScrollView> {
public:
    ScrollController scrollController;


    void initState();

    void didUpdateWidget(ListWheelScrollView oldWidget);

    Widget build(BuildContext context);

private:
    int _lastReportedItemIndex;


    bool _handleScrollNotification(ScrollNotification notification);

};

class ListWheelElement : RenderObjectElement {
public:

     ListWheelElement(ListWheelViewport widget);

    RenderListWheelViewport renderObject();

    void update(ListWheelViewport newWidget);

    int childCount();

    void performRebuild();

    Widget retrieveWidget(int index);

    bool childExistsAt(int index);

    void createChild(RenderBox after, int index);

    void removeChild(RenderBox child);

    Element updateChild(Element child, Object newSlot, Widget newWidget);

    void insertRenderObjectChild(RenderObject child, int slot);

    void moveRenderObjectChild(RenderObject child, int newSlot, int oldSlot);

    void removeRenderObjectChild(RenderObject child, int slot);

    void visitChildren(ElementVisitor visitor);

    void forgetChild(Element child);

private:
    Map<int, Widget> _childWidgets;

    SplayTreeMap<int, Element> _childElements;


};

class ListWheelViewport : RenderObjectWidget {
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


     ListWheelViewport(ListWheelChildDelegate childDelegate, Clip clipBehavior, double diameterRatio, double itemExtent, Unknown, double magnification, double offAxisFraction, ViewportOffset offset, double overAndUnderCenterOpacity, double perspective, bool renderChildrenOutsideViewport, double squeeze, bool useMagnifier);

    ListWheelElement createElement();

    RenderListWheelViewport createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderListWheelViewport renderObject);

private:

};

#endif