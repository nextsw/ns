#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ROUTES
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ROUTES
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "basic.hpp"
#include "display_feature_sub_screen.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "modal_barrier.hpp"
#include "navigator.hpp"
#include "overlay.hpp"
#include "page_storage.hpp"
#include "primary_scroll_controller.hpp"
#include "restoration.hpp"
#include "scroll_controller.hpp"
#include "transitions.hpp"


template<typename T>
class OverlayRouteCls : public RouteCls<T> {
public:

     OverlayRouteCls(Unknown settings);
    virtual Iterable<OverlayEntry> createOverlayEntries();
    virtual List<OverlayEntry> overlayEntries();

    virtual void install();

    virtual bool finishedWhenPopped();

    virtual bool didPop(T result);

    virtual void dispose();

private:
    List<OverlayEntry> _overlayEntries;


};
template<typename T>
using OverlayRoute = std::shared_ptr<OverlayRouteCls<T>>;

template<typename T>
class TransitionRouteCls : public OverlayRouteCls<T> {
public:
    bool willDisposeAnimationController;


     TransitionRouteCls(Unknown settings);
    virtual Future<T> completed();

    virtual Duration transitionDuration();
    virtual Duration reverseTransitionDuration();

    virtual bool opaque();
    virtual bool finishedWhenPopped();

    virtual Animation<double> animation();

    virtual AnimationController controller();

    virtual Animation<double> secondaryAnimation();

    virtual AnimationController createAnimationController();

    virtual Animation<double> createAnimation();

    virtual void install();

    virtual TickerFuture didPush();

    virtual void didAdd();

    virtual void didReplace(Route<dynamic> oldRoute);

    virtual bool didPop(T result);

    virtual void didPopNext(Route<dynamic> nextRoute);

    virtual void didChangeNext(Route<dynamic> nextRoute);

    virtual bool canTransitionTo(TransitionRoute<dynamic> nextRoute);

    virtual bool canTransitionFrom(TransitionRoute<dynamic> previousRoute);

    virtual void dispose();

    virtual String debugLabel();

    virtual String toString();

private:
    Completer<T> _transitionCompleter;

    bool _popFinalized;

    Animation<double> _animation;

    AnimationController _controller;

    ProxyAnimation _secondaryAnimation;

    T _result;

    VoidCallback _trainHoppingListenerRemover;


    virtual void _handleStatusChanged(AnimationStatus status);

    virtual void _updateSecondaryAnimation(Route<dynamic> nextRoute);

    virtual void _setSecondaryAnimation(Animation<double> animation, Future<dynamic> disposed);

};
template<typename T>
using TransitionRoute = std::shared_ptr<TransitionRouteCls<T>>;

class LocalHistoryEntryCls : public ObjectCls {
public:
    VoidCallback onRemove;

    bool impliesAppBarDismissal;


     LocalHistoryEntryCls(bool impliesAppBarDismissal, VoidCallback onRemove);
    virtual void remove();

private:
    LocalHistoryRoute<dynamic> _owner;


    virtual void _notifyRemoved();

};
using LocalHistoryEntry = std::shared_ptr<LocalHistoryEntryCls>;

template<typename T>
class LocalHistoryRouteCls : public ObjectCls {
public:

    virtual void addLocalHistoryEntry(LocalHistoryEntry entry);

    virtual void removeLocalHistoryEntry(LocalHistoryEntry entry);

    virtual Future<RoutePopDisposition> willPop();

    virtual bool didPop(T result);

    virtual bool willHandlePopInternally();

private:
    List<LocalHistoryEntry> _localHistory;

    int _entriesImpliesAppBarDismissal;


};
template<typename T>
using LocalHistoryRoute = std::shared_ptr<LocalHistoryRouteCls<T>>;

class _DismissModalActionCls : public DismissActionCls {
public:
    BuildContext context;


    virtual bool isEnabled(DismissIntent intent);

    virtual Object invoke(DismissIntent intent);

private:

     _DismissModalActionCls(BuildContext context);
};
using _DismissModalAction = std::shared_ptr<_DismissModalActionCls>;

class _ModalScopeStatusCls : public InheritedWidgetCls {
public:
    bool isCurrent;

    bool canPop;

    bool impliesAppBarDismissal;

    Route<dynamic> route;


    virtual bool updateShouldNotify(_ModalScopeStatus old);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:

     _ModalScopeStatusCls(bool canPop, Widget child, bool impliesAppBarDismissal, bool isCurrent, Route<dynamic> route);

};
using _ModalScopeStatus = std::shared_ptr<_ModalScopeStatusCls>;

template<typename T>
class _ModalScopeCls : public StatefulWidgetCls {
public:
    ModalRoute<T> route;


    virtual _ModalScopeState<T> createState();

private:

     _ModalScopeCls(Key key, ModalRoute<T> route);
};
template<typename T>
using _ModalScope = std::shared_ptr<_ModalScopeCls<T>>;

template<typename T>
class _ModalScopeStateCls : public StateCls<_ModalScope<T>> {
public:
    FocusScopeNode focusScopeNode;

    ScrollController primaryScrollController;


    virtual void initState();

    virtual void didUpdateWidget(_ModalScope<T> oldWidget);

    virtual void didChangeDependencies();

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    Widget _page;

    Listenable _listenable;


    virtual void _forceRebuildPage();

    virtual bool _shouldIgnoreFocusRequest();

    virtual bool _shouldRequestFocus();

    virtual void _routeSetState(VoidCallback fn);

};
template<typename T>
using _ModalScopeState = std::shared_ptr<_ModalScopeStateCls<T>>;

template<typename T>
class ModalRouteCls : public TransitionRouteCls<T> {
public:
    ImageFilter filter;


     ModalRouteCls(ImageFilter filter, Unknown settings);
    template<typename T>
 static ModalRoute<T> of(BuildContext context);

    virtual void setState(VoidCallback fn);

    static RoutePredicate withName(String name);

    virtual Widget buildPage(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation);
    virtual Widget buildTransitions(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation, Widget child);

    virtual void install();

    virtual TickerFuture didPush();

    virtual void didAdd();

    virtual bool barrierDismissible();
    virtual bool semanticsDismissible();

    virtual Color barrierColor();
    virtual String barrierLabel();
    virtual Curve barrierCurve();

    virtual bool maintainState();
    virtual bool offstage();

    virtual void  offstage(bool value);

    virtual BuildContext subtreeContext();

    virtual Animation<double> animation();

    virtual Animation<double> secondaryAnimation();

    virtual Future<RoutePopDisposition> willPop();

    virtual void addScopedWillPopCallback(WillPopCallback callback);

    virtual void removeScopedWillPopCallback(WillPopCallback callback);

    virtual bool hasScopedWillPopCallback();

    virtual void didChangePrevious(Route<dynamic> previousRoute);

    virtual void changedInternalState();

    virtual void changedExternalState();

    virtual bool canPop();

    virtual bool impliesAppBarDismissal();

    virtual Iterable<OverlayEntry> createOverlayEntries();

    virtual String toString();

private:
    bool _offstage;

    ProxyAnimation _animationProxy;

    ProxyAnimation _secondaryAnimationProxy;

    List<WillPopCallback> _willPopCallbacks;

    GlobalKey<_ModalScopeState<T>> _scopeKey;

    GlobalKey _subtreeKey;

    PageStorageBucket _storageBucket;

    OverlayEntry _modalBarrier;

    Widget _modalScopeCache;

    OverlayEntry _modalScope;


    virtual Widget _buildModalBarrier(BuildContext context);

    virtual Widget _buildModalScope(BuildContext context);

};
template<typename T>
using ModalRoute = std::shared_ptr<ModalRouteCls<T>>;

template<typename T>
class PopupRouteCls : public ModalRouteCls<T> {
public:

     PopupRouteCls(ImageFilter filter, Unknown settings);
    virtual bool opaque();

    virtual bool maintainState();

private:

};
template<typename T>
using PopupRoute = std::shared_ptr<PopupRouteCls<T>>;

template<typename R>
class RouteObserverCls : public NavigatorObserverCls {
public:

    virtual bool debugObservingRoute(R route);

    virtual void subscribe(RouteAware routeAware, R route);

    virtual void unsubscribe(RouteAware routeAware);

    virtual void didPop(Route<dynamic> route, Route<dynamic> previousRoute);

    virtual void didPush(Route<dynamic> route, Route<dynamic> previousRoute);

private:
    Map<R, Set<RouteAware>> _listeners;


};
template<typename R>
using RouteObserver = std::shared_ptr<RouteObserverCls<R>>;

class RouteAwareCls : public ObjectCls {
public:

    virtual void didPopNext();

    virtual void didPush();

    virtual void didPop();

    virtual void didPushNext();

private:

};
using RouteAware = std::shared_ptr<RouteAwareCls>;

template<typename T>
class RawDialogRouteCls : public PopupRouteCls<T> {
public:
    Offset anchorPoint;


     RawDialogRouteCls(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, RoutePageBuilder pageBuilder, Unknown settings, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration);

    virtual bool barrierDismissible();

    virtual String barrierLabel();

    virtual Color barrierColor();

    virtual Duration transitionDuration();

    virtual Widget buildPage(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation);

    virtual Widget buildTransitions(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation, Widget child);

private:
    RoutePageBuilder _pageBuilder;

    bool _barrierDismissible;

    String _barrierLabel;

    Color _barrierColor;

    Duration _transitionDuration;

    RouteTransitionsBuilder _transitionBuilder;


};
template<typename T>
using RawDialogRoute = std::shared_ptr<RawDialogRouteCls<T>>;
template<typename T>
 Future<T> showGeneralDialog(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, BuildContext context, RoutePageBuilder pageBuilder, RouteSettings routeSettings, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration, bool useRootNavigator);


class FocusTrapCls : public SingleChildRenderObjectWidgetCls {
public:
    FocusScopeNode focusScopeNode;


     FocusTrapCls(Widget child, FocusScopeNode focusScopeNode, Key key);
    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

private:

};
using FocusTrap = std::shared_ptr<FocusTrapCls>;

class FocusTrapAreaCls : public SingleChildRenderObjectWidgetCls {
public:
    FocusNode focusNode;


     FocusTrapAreaCls(Widget child, FocusNode focusNode, Key key);
    virtual RenderObject createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, RenderObject renderObject);

private:

};
using FocusTrapArea = std::shared_ptr<FocusTrapAreaCls>;

class _RenderFocusTrapAreaCls : public RenderProxyBoxCls {
public:
    FocusNode focusNode;


private:

     _RenderFocusTrapAreaCls(FocusNode focusNode);
};
using _RenderFocusTrapArea = std::shared_ptr<_RenderFocusTrapAreaCls>;

class _RenderFocusTrapCls : public RenderProxyBoxWithHitTestBehaviorCls {
public:
    Rect currentFocusRect;

    Expando<BoxHitTestResult> cachedResults;


    virtual FocusScopeNode focusScopeNode();

    virtual void  focusScopeNode(FocusScopeNode value);

    virtual bool hitTest(BoxHitTestResult result, Offset position);

    virtual void handleEvent(PointerEvent event, HitTestEntry entry);

private:
    FocusScopeNode _focusScopeNode;

    FocusNode _previousFocus;


     _RenderFocusTrapCls(FocusScopeNode _focusScopeNode);
    virtual bool _shouldIgnoreEvents();

    virtual void _checkForUnfocus();

};
using _RenderFocusTrap = std::shared_ptr<_RenderFocusTrapCls>;


#endif