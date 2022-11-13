#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DRAGGABLE_SCROLLABLE_SHEET
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DRAGGABLE_SCROLLABLE_SHEET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/math/math.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
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


class DraggableScrollableControllerCls : public ChangeNotifierCls {
public:

    virtual double size();

    virtual double pixels();

    virtual double sizeToPixels(double size);

    virtual bool isAttached();

    virtual double pixelsToSize(double pixels);

    virtual Future<void> animateTo(double size, Curve curve, Duration duration);

    virtual void jumpTo(double size);

    virtual void reset();

private:
    _DraggableScrollableSheetScrollController _attachedController;

    Set<AnimationController> _animationControllers;


    virtual void _assertAttached();

    virtual void _attach(_DraggableScrollableSheetScrollController scrollController);

    virtual void _onExtentReplaced(_DraggableSheetExtent previousExtent);

    virtual void _detach();

    virtual void _disposeAnimationControllers();

};
using DraggableScrollableController = std::shared_ptr<DraggableScrollableControllerCls>;

class DraggableScrollableSheetCls : public StatefulWidgetCls {
public:
    double initialChildSize;

    double minChildSize;

    double maxChildSize;

    bool expand;

    bool snap;

    List<double> snapSizes;

    DraggableScrollableController controller;

    ScrollableWidgetBuilder builder;


     DraggableScrollableSheetCls(ScrollableWidgetBuilder builder, DraggableScrollableController controller, bool expand, double initialChildSize, Key key, double maxChildSize, double minChildSize, bool snap, List<double> snapSizes);

    virtual State<DraggableScrollableSheet> createState();

private:

};
using DraggableScrollableSheet = std::shared_ptr<DraggableScrollableSheetCls>;

class DraggableScrollableNotificationCls : public NotificationCls {
public:
    double extent;

    double minExtent;

    double maxExtent;

    double initialExtent;

    BuildContext context;


     DraggableScrollableNotificationCls(BuildContext context, double extent, double initialExtent, double maxExtent, double minExtent);

    virtual void debugFillDescription(List<String> description);

private:

};
using DraggableScrollableNotification = std::shared_ptr<DraggableScrollableNotificationCls>;

class _DraggableSheetExtentCls : public ObjectCls {
public:
    double minSize;

    double maxSize;

    bool snap;

    List<double> snapSizes;

    double initialSize;

    VoidCallback onSizeChanged;

    double availablePixels;

    bool hasDragged;


    virtual bool isAtMin();

    virtual bool isAtMax();

    virtual double currentSize();

    virtual double currentPixels();

    virtual double additionalMinSize();

    virtual double additionalMaxSize();

    virtual List<double> pixelSnapSizes();

    virtual void startActivity(VoidCallback onCanceled);

    virtual void addPixelDelta(double delta, BuildContext context);

    virtual void updateSize(double newSize, BuildContext context);

    virtual double pixelsToSize(double pixels);

    virtual double sizeToPixels(double size);

    virtual void dispose();

    virtual _DraggableSheetExtent copyWith(double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes);

private:
    VoidCallback _cancelActivity;

    ValueNotifier<double> _currentSize;


     _DraggableSheetExtentCls(ValueNotifier<double> currentSize, bool hasDragged, double initialSize, double maxSize, double minSize, VoidCallback onSizeChanged, bool snap, List<double> snapSizes);

};
using _DraggableSheetExtent = std::shared_ptr<_DraggableSheetExtentCls>;

class _DraggableScrollableSheetStateCls : public StateCls<DraggableScrollableSheet> {
public:

    virtual void initState();

    virtual void didUpdateWidget(DraggableScrollableSheet oldWidget);

    virtual void didChangeDependencies();

    virtual Widget build(BuildContext context);

    virtual void dispose();

private:
    _DraggableScrollableSheetScrollController _scrollController;

    _DraggableSheetExtent _extent;


    virtual List<double> _impliedSnapSizes();

    virtual void _setExtent();

    virtual void _replaceExtent(DraggableScrollableSheet oldWidget);

    virtual String _snapSizeErrorMessage(int invalidIndex);

};
using _DraggableScrollableSheetState = std::shared_ptr<_DraggableScrollableSheetStateCls>;

class _DraggableScrollableSheetScrollControllerCls : public ScrollControllerCls {
public:
    _DraggableSheetExtent extent;

    VoidCallback onPositionDetached;


    virtual _DraggableScrollableSheetScrollPosition createScrollPosition(ScrollPhysics physics, ScrollContext context, ScrollPosition oldPosition);

    virtual void debugFillDescription(List<String> description);

    virtual _DraggableScrollableSheetScrollPosition position();

    virtual void reset();

    virtual void detach(ScrollPosition position);

private:

     _DraggableScrollableSheetScrollControllerCls(_DraggableSheetExtent extent);

};
using _DraggableScrollableSheetScrollController = std::shared_ptr<_DraggableScrollableSheetScrollControllerCls>;

class _DraggableScrollableSheetScrollPositionCls : public ScrollPositionWithSingleContextCls {
public:
    std::function<_DraggableSheetExtent()> getExtent;


    virtual bool listShouldScroll();

    virtual _DraggableSheetExtent extent();

    virtual void absorb(ScrollPosition other);

    virtual void beginActivity(ScrollActivity newActivity);

    virtual bool applyContentDimensions(double minScrollSize, double maxScrollSize);

    virtual void applyUserOffset(double delta);

    virtual void dispose();

    virtual void goBallistic(double velocity);

    virtual Drag drag(DragStartDetails details, VoidCallback dragCancelCallback);

private:
    VoidCallback _dragCancelCallback;

    Set<AnimationController> _ballisticControllers;


     _DraggableScrollableSheetScrollPositionCls(ScrollContext context, std::function<_DraggableSheetExtent()> getExtent, ScrollPosition oldPosition, ScrollPhysics physics);
    virtual bool _isAtSnapSize();

    virtual bool _shouldSnap();

};
using _DraggableScrollableSheetScrollPosition = std::shared_ptr<_DraggableScrollableSheetScrollPositionCls>;

class DraggableScrollableActuatorCls : public StatelessWidgetCls {
public:
    Widget child;


     DraggableScrollableActuatorCls(Widget child, Key key);
    static bool reset(BuildContext context);

    virtual Widget build(BuildContext context);

private:
    _ResetNotifier _notifier;


};
using DraggableScrollableActuator = std::shared_ptr<DraggableScrollableActuatorCls>;

class _ResetNotifierCls : public ChangeNotifierCls {
public:

    virtual bool sendReset();

private:
    bool _wasCalled;


};
using _ResetNotifier = std::shared_ptr<_ResetNotifierCls>;

class _InheritedResetNotifierCls : public InheritedNotifierCls<_ResetNotifier> {
public:

    static bool shouldReset(BuildContext context);

private:

     _InheritedResetNotifierCls(Widget child, T notifier);
    virtual bool _sendReset();

};
using _InheritedResetNotifier = std::shared_ptr<_InheritedResetNotifierCls>;

class _SnappingSimulationCls : public SimulationCls {
public:
    double position;

    double velocity;

    static double minimumSpeed;


    virtual double dx(double time);

    virtual bool isDone(double time);

    virtual double x(double time);

private:
    double _pixelSnapSize;


     _SnappingSimulationCls(double initialVelocity, List<double> pixelSnapSize, double position, Tolerance tolerance);

    virtual double _getSnapSize(double initialVelocity, List<double> pixelSnapSizes);

};
using _SnappingSimulation = std::shared_ptr<_SnappingSimulationCls>;


#endif