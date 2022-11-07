#ifndef ROUTES_H
#define ROUTES_H
#include <memory>

#include <async/async.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
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



class OverlayRoute<T> : Route<T> {
public:

     OverlayRoute(Unknown);

    Iterable<OverlayEntry> createOverlayEntries();

    List<OverlayEntry> overlayEntries();

    void install();

    bool finishedWhenPopped();

    bool didPop(T result);

    void dispose();

private:
    List<OverlayEntry> _overlayEntries;


};

class TransitionRoute<T> : OverlayRoute<T> {
public:
    bool willDisposeAnimationController;


     TransitionRoute(Unknown);

    Future<T> completed();

    Duration transitionDuration();

    Duration reverseTransitionDuration();

    bool opaque();

    bool finishedWhenPopped();

    Animation<double> animation();

    AnimationController controller();

    Animation<double> secondaryAnimation();

    AnimationController createAnimationController();

    Animation<double> createAnimation();

    void install();

    TickerFuture didPush();

    void didAdd();

    void didReplace(Route<dynamic> oldRoute);

    bool didPop(T result);

    void didPopNext(Route<dynamic> nextRoute);

    void didChangeNext(Route<dynamic> nextRoute);

    bool canTransitionTo(TransitionRoute<dynamic> nextRoute);

    bool canTransitionFrom(TransitionRoute<dynamic> previousRoute);

    void dispose();

    String debugLabel();

    String toString();

private:
    Completer<T> _transitionCompleter;

    bool _popFinalized;

    Animation<double> _animation;

    AnimationController _controller;

    ProxyAnimation _secondaryAnimation;

    T _result;

    VoidCallback _trainHoppingListenerRemover;


    void _handleStatusChanged(AnimationStatus status);

    void _updateSecondaryAnimation(Route<dynamic> nextRoute);

    void _setSecondaryAnimation(Animation<double> animation, Future<dynamic> disposed);

};

class LocalHistoryEntry {
public:
    VoidCallback onRemove;

    bool impliesAppBarDismissal;


     LocalHistoryEntry(bool impliesAppBarDismissal, VoidCallback onRemove);

    void remove();

private:
    LocalHistoryRoute<dynamic> _owner;


    void _notifyRemoved();

};

class LocalHistoryRoute<T> {
public:

    void addLocalHistoryEntry(LocalHistoryEntry entry);

    void removeLocalHistoryEntry(LocalHistoryEntry entry);

    Future<RoutePopDisposition> willPop();

    bool didPop(T result);

    bool willHandlePopInternally();

private:
    List<LocalHistoryEntry> _localHistory;

    int _entriesImpliesAppBarDismissal;


};

class _DismissModalAction : DismissAction {
public:
    BuildContext context;


    bool isEnabled(DismissIntent intent);

    Object invoke(DismissIntent intent);

private:

     _DismissModalAction(BuildContext context);

};

class _ModalScopeStatus : InheritedWidget {
public:
    bool isCurrent;

    bool canPop;

    bool impliesAppBarDismissal;

    Route<dynamic> route;


    bool updateShouldNotify(_ModalScopeStatus old);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:

     _ModalScopeStatus(bool canPop, Unknown, bool impliesAppBarDismissal, bool isCurrent, Route<dynamic> route);

};

class _ModalScope<T> : StatefulWidget {
public:
    ModalRoute<T> route;


    _ModalScopeState<T> createState();

private:

     _ModalScope(Unknown, ModalRoute<T> route);

};

class _ModalScopeState<T> : State<_ModalScope<T>> {
public:
    FocusScopeNode focusScopeNode;

    ScrollController primaryScrollController;


    void initState();

    void didUpdateWidget(_ModalScope<T> oldWidget);

    void didChangeDependencies();

    void dispose();

    Widget build(BuildContext context);

private:
    Widget _page;

    Listenable _listenable;


    void _forceRebuildPage();

    bool _shouldIgnoreFocusRequest();

    bool _shouldRequestFocus();

    void _routeSetState(VoidCallback fn);

};

class ModalRoute<T> : TransitionRoute<T> {
public:
    ImageFilter filter;


     ModalRoute(ImageFilter filter, Unknown);

    static ModalRoute<T> of<T extends Object>(BuildContext context);

    void setState(VoidCallback fn);

    static RoutePredicate withName(String name);

    Widget buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation);

    Widget buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation);

    void install();

    TickerFuture didPush();

    void didAdd();

    bool barrierDismissible();

    bool semanticsDismissible();

    Color barrierColor();

    String barrierLabel();

    Curve barrierCurve();

    bool maintainState();

    bool offstage();

    void  offstage(bool value);

    BuildContext subtreeContext();

    Animation<double> animation();

    Animation<double> secondaryAnimation();

    Future<RoutePopDisposition> willPop();

    void addScopedWillPopCallback(WillPopCallback callback);

    void removeScopedWillPopCallback(WillPopCallback callback);

    bool hasScopedWillPopCallback();

    void didChangePrevious(Route<dynamic> previousRoute);

    void changedInternalState();

    void changedExternalState();

    bool canPop();

    bool impliesAppBarDismissal();

    Iterable<OverlayEntry> createOverlayEntries();

    String toString();

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


    Widget _buildModalBarrier(BuildContext context);

    Widget _buildModalScope(BuildContext context);

};

class PopupRoute<T> : ModalRoute<T> {
public:

     PopupRoute(Unknown, Unknown);

    bool opaque();

    bool maintainState();

private:

};

class RouteObserver<R extends Route<dynamic>> : NavigatorObserver {
public:

    bool debugObservingRoute(R route);

    void subscribe(R route, RouteAware routeAware);

    void unsubscribe(RouteAware routeAware);

    void didPop(Route<dynamic> previousRoute, Route<dynamic> route);

    void didPush(Route<dynamic> previousRoute, Route<dynamic> route);

private:
    Map<R, Set<RouteAware>> _listeners;


};

class RouteAware {
public:

    void didPopNext();

    void didPush();

    void didPop();

    void didPushNext();

private:

};

class RawDialogRoute<T> : PopupRoute<T> {
public:
    Offset anchorPoint;


     RawDialogRoute(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, RoutePageBuilder pageBuilder, Unknown, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration);

    bool barrierDismissible();

    String barrierLabel();

    Color barrierColor();

    Duration transitionDuration();

    Widget buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation);

    Widget buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation);

private:
    RoutePageBuilder _pageBuilder;

    bool _barrierDismissible;

    String _barrierLabel;

    Color _barrierColor;

    Duration _transitionDuration;

    RouteTransitionsBuilder _transitionBuilder;


};
Future<T> showGeneralDialog<T extends Object>(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, BuildContext context, RoutePageBuilder pageBuilder, RouteSettings routeSettings, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration, bool useRootNavigator);


class FocusTrap : SingleChildRenderObjectWidget {
public:
    FocusScopeNode focusScopeNode;


     FocusTrap(Widget child, FocusScopeNode focusScopeNode, Unknown);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

private:

};

class FocusTrapArea : SingleChildRenderObjectWidget {
public:
    FocusNode focusNode;


     FocusTrapArea(Unknown, FocusNode focusNode, Unknown);

    RenderObject createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, RenderObject renderObject);

private:

};

class _RenderFocusTrapArea : RenderProxyBox {
public:
    FocusNode focusNode;


private:

     _RenderFocusTrapArea(FocusNode focusNode);

};

class _RenderFocusTrap : RenderProxyBoxWithHitTestBehavior {
public:
    Rect currentFocusRect;

    Expando<BoxHitTestResult> cachedResults;


    FocusScopeNode focusScopeNode();

    void  focusScopeNode(FocusScopeNode value);

    bool hitTest(Offset position, BoxHitTestResult result);

    void handleEvent(HitTestEntry entry, PointerEvent event);

private:
    FocusScopeNode _focusScopeNode;

    FocusNode _previousFocus;


     _RenderFocusTrap(FocusScopeNode _focusScopeNode);

    bool _shouldIgnoreEvents();

    void _checkForUnfocus();

};

#endif