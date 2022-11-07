#ifndef DRAGGABLE_SCROLLABLE_SHEET_H
#define DRAGGABLE_SCROLLABLE_SHEET_H
#include <memory>

#include <math/math.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "inherited_notifier.hpp"
#include "layout_builder.hpp"
#include "notification_listener.hpp"
#include "scroll_activity.hpp"
#include "scroll_context.hpp"
#include "scroll_controller.hpp"
#include "scroll_notification.hpp"
#include "scroll_physics.hpp"
#include "scroll_position.hpp"
#include "scroll_position_with_single_context.hpp"
#include "scroll_simulation.hpp"



class DraggableScrollableController : ChangeNotifier {
public:

    double size();

    double pixels();

    double sizeToPixels(double size);

    bool isAttached();

    double pixelsToSize(double pixels);

    Future<void> animateTo(Curve curve, Duration duration, double size);

    void jumpTo(double size);

    void reset();

private:
    _DraggableScrollableSheetScrollController _attachedController;

    Set<AnimationController> _animationControllers;


    void _assertAttached();

    void _attach(_DraggableScrollableSheetScrollController scrollController);

    void _onExtentReplaced(_DraggableSheetExtent previousExtent);

    void _detach();

    void _disposeAnimationControllers();

};

class DraggableScrollableSheet : StatefulWidget {
public:
    double initialChildSize;

    double minChildSize;

    double maxChildSize;

    bool expand;

    bool snap;

    List<double> snapSizes;

    DraggableScrollableController controller;

    ScrollableWidgetBuilder builder;


     DraggableScrollableSheet(ScrollableWidgetBuilder builder, DraggableScrollableController controller, bool expand, double initialChildSize, Unknown, double maxChildSize, double minChildSize, bool snap, List<double> snapSizes);

    State<DraggableScrollableSheet> createState();

private:

};

class DraggableScrollableNotification : Notification {
public:
    double extent;

    double minExtent;

    double maxExtent;

    double initialExtent;

    BuildContext context;


     DraggableScrollableNotification(BuildContext context, double extent, double initialExtent, double maxExtent, double minExtent);

    void debugFillDescription(List<String> description);

private:

};

class _DraggableSheetExtent {
public:
    double minSize;

    double maxSize;

    bool snap;

    List<double> snapSizes;

    double initialSize;

    VoidCallback onSizeChanged;

    double availablePixels;

    bool hasDragged;


    bool isAtMin();

    bool isAtMax();

    double currentSize();

    double currentPixels();

    double additionalMinSize();

    double additionalMaxSize();

    List<double> pixelSnapSizes();

    void startActivity(VoidCallback onCanceled);

    void addPixelDelta(BuildContext context, double delta);

    void updateSize(BuildContext context, double newSize);

    double pixelsToSize(double pixels);

    double sizeToPixels(double size);

    void dispose();

    _DraggableSheetExtent copyWith(double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes);

private:
    VoidCallback _cancelActivity;

    ValueNotifier<double> _currentSize;


     _DraggableSheetExtent(ValueNotifier<double> currentSize, bool hasDragged, double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes);

};

class _DraggableScrollableSheetState : State<DraggableScrollableSheet> {
public:

    void initState();

    void didUpdateWidget(DraggableScrollableSheet oldWidget);

    void didChangeDependencies();

    Widget build(BuildContext context);

    void dispose();

private:
    _DraggableScrollableSheetScrollController _scrollController;

    _DraggableSheetExtent _extent;


    List<double> _impliedSnapSizes();

    void _setExtent();

    void _replaceExtent(DraggableScrollableSheet oldWidget);

    String _snapSizeErrorMessage(int invalidIndex);

};

class _DraggableScrollableSheetScrollController : ScrollController {
public:
    _DraggableSheetExtent extent;

    VoidCallback onPositionDetached;


    _DraggableScrollableSheetScrollPosition createScrollPosition(ScrollContext context, ScrollPosition oldPosition, ScrollPhysics physics);

    void debugFillDescription(List<String> description);

    _DraggableScrollableSheetScrollPosition position();

    void reset();

    void detach(ScrollPosition position);

private:

     _DraggableScrollableSheetScrollController(_DraggableSheetExtent extent);

};

class _DraggableScrollableSheetScrollPosition : ScrollPositionWithSingleContext {
public:
    FunctionType getExtent;


    bool listShouldScroll();

    _DraggableSheetExtent extent();

    void absorb(ScrollPosition other);

    void beginActivity(ScrollActivity newActivity);

    bool applyContentDimensions(double maxScrollSize, double minScrollSize);

    void applyUserOffset(double delta);

    void dispose();

    void goBallistic(double velocity);

    Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

private:
    VoidCallback _dragCancelCallback;

    Set<AnimationController> _ballisticControllers;


     _DraggableScrollableSheetScrollPosition(Unknown, FunctionType getExtent, Unknown, Unknown);

    bool _isAtSnapSize();

    bool _shouldSnap();

};

class DraggableScrollableActuator : StatelessWidget {
public:
    Widget child;


     DraggableScrollableActuator(Widget child, Unknown);

    static bool reset(BuildContext context);

    Widget build(BuildContext context);

private:
    _ResetNotifier _notifier;


};

class _ResetNotifier : ChangeNotifier {
public:

    bool sendReset();

private:
    bool _wasCalled;


};

class _InheritedResetNotifier : InheritedNotifier<_ResetNotifier> {
public:

    static bool shouldReset(BuildContext context);

private:

     _InheritedResetNotifier(Unknown, _ResetNotifier notifier);

    bool _sendReset();

};

class _SnappingSimulation : Simulation {
public:
    double position;

    double velocity;

    static const double minimumSpeed;


    double dx(double time);

    bool isDone(double time);

    double x(double time);

private:
    double _pixelSnapSize;


     _SnappingSimulation(double initialVelocity, List<double> pixelSnapSize, double position, Unknown);

    double _getSnapSize(double initialVelocity, List<double> pixelSnapSizes);

};

#endif