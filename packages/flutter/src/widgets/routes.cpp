#include "routes.hpp"
List<OverlayEntry> OverlayRoute::overlayEntries() {
    return _overlayEntries;
}

void OverlayRoute::install() {
    assert(_overlayEntries.isEmpty);
    _overlayEntries.addAll(createOverlayEntries());
    super.install();
}

bool OverlayRoute::finishedWhenPopped() {
    return true;
}

bool OverlayRoute::didPop(T result) {
    bool returnValue = super.didPop(result);
    assert(returnValue);
    if (finishedWhenPopped) {
        navigator!.finalizeRoute(this);
    }
    return returnValue;
}

void OverlayRoute::dispose() {
    _overlayEntries.clear();
    super.dispose();
}

Future<T> TransitionRoute::completed() {
    return _transitionCompleter.future;
}

Duration TransitionRoute::reverseTransitionDuration() {
    return transitionDuration;
}

bool TransitionRoute::finishedWhenPopped() {
    return _controller!.status == AnimationStatus.dismissed && !_popFinalized;
}

Animation<double> TransitionRoute::animation() {
    return _animation;
}

AnimationController TransitionRoute::controller() {
    return _controller;
}

Animation<double> TransitionRoute::secondaryAnimation() {
    return _secondaryAnimation;
}

AnimationController TransitionRoute::createAnimationController() {
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    Duration duration = transitionDuration;
    Duration reverseDuration = reverseTransitionDuration;
    assert(duration != nullptr && duration >= Duration.zero);
    return AnimationController(duration, reverseDuration, debugLabel, navigator!);
}

Animation<double> TransitionRoute::createAnimation() {
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    assert(_controller != nullptr);
    return _controller!.view;
}

void TransitionRoute::install() {
    assert(!_transitionCompleter.isCompleted, "Cannot install a $runtimeType after disposing it.");
    _controller = createAnimationController();
    assert(_controller != nullptr, "$runtimeType.createAnimationController() returned null.");
    _animation = ;
    assert(_animation != nullptr, "$runtimeType.createAnimation() returned null.");
    super.install();
    if (_animation!.isCompleted && overlayEntries.isNotEmpty) {
        overlayEntries.first.opaque = opaque;
    }
}

TickerFuture TransitionRoute::didPush() {
    assert(_controller != nullptr, "$runtimeType.didPush called before calling install() or after calling dispose().");
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    super.didPush();
    return _controller!.forward();
}

void TransitionRoute::didAdd() {
    assert(_controller != nullptr, "$runtimeType.didPush called before calling install() or after calling dispose().");
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    super.didAdd();
    _controller!.value = _controller!.upperBound;
}

void TransitionRoute::didReplace(Route<dynamic> oldRoute) {
    assert(_controller != nullptr, "$runtimeType.didReplace called before calling install() or after calling dispose().");
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    if (oldRoute is TransitionRoute) {
        _controller!.value = oldRoute._controller!.value;
    }
    super.didReplace(oldRoute);
}

bool TransitionRoute::didPop(T result) {
    assert(_controller != nullptr, "$runtimeType.didPop called before calling install() or after calling dispose().");
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    _result = result;
    _controller!.reverse();
    return super.didPop(result);
}

void TransitionRoute::didPopNext(Route<dynamic> nextRoute) {
    assert(_controller != nullptr, "$runtimeType.didPopNext called before calling install() or after calling dispose().");
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    _updateSecondaryAnimation(nextRoute);
    super.didPopNext(nextRoute);
}

void TransitionRoute::didChangeNext(Route<dynamic> nextRoute) {
    assert(_controller != nullptr, "$runtimeType.didChangeNext called before calling install() or after calling dispose().");
    assert(!_transitionCompleter.isCompleted, "Cannot reuse a $runtimeType after disposing it.");
    _updateSecondaryAnimation(nextRoute);
    super.didChangeNext(nextRoute);
}

bool TransitionRoute::canTransitionTo(TransitionRoute<dynamic> nextRoute) {
    return true;
}

bool TransitionRoute::canTransitionFrom(TransitionRoute<dynamic> previousRoute) {
    return true;
}

void TransitionRoute::dispose() {
    assert(!_transitionCompleter.isCompleted, "Cannot dispose a $runtimeType twice.");
    _animation?.removeStatusListener(_handleStatusChanged);
    if (willDisposeAnimationController) {
        _controller?.dispose();
    }
    _transitionCompleter.complete(_result);
    super.dispose();
}

String TransitionRoute::debugLabel() {
    return objectRuntimeType(this, "TransitionRoute");
}

String TransitionRoute::toString() {
    return "${objectRuntimeType(this, 'TransitionRoute')}(animation: $_controller)";
}

void TransitionRoute::_handleStatusChanged(AnimationStatus status) {
    ;
}

void TransitionRoute::_updateSecondaryAnimation(Route<dynamic> nextRoute) {
    VoidCallback previousTrainHoppingListenerRemover = _trainHoppingListenerRemover;
    _trainHoppingListenerRemover = nullptr;
    if (nextRoute is TransitionRoute<dynamic> && canTransitionTo(nextRoute) && nextRoute.canTransitionFrom(this)) {
        Animation<double> current = _secondaryAnimation.parent;
        if (current != nullptr) {
            Animation<double> currentTrain = (current is TrainHoppingAnimation? current.currentTrain : current)!;
            Animation<double> nextTrain = nextRoute._animation!;
            if (currentTrain.value == nextTrain.value || nextTrain.status == AnimationStatus.completed || nextTrain.status == AnimationStatus.dismissed) {
                _setSecondaryAnimation(nextTrain, nextRoute.completed);
            } else {
                TrainHoppingAnimation newAnimation;
                ;
                _trainHoppingListenerRemover = ;
                nextTrain.addStatusListener(jumpOnAnimationEnd);
                newAnimation = TrainHoppingAnimation(currentTrain, nextTrain);
                _setSecondaryAnimation(newAnimation, nextRoute.completed);
            }
        } else {
            _setSecondaryAnimation(nextRoute._animation, nextRoute.completed);
        }
    } else {
        _setSecondaryAnimation(kAlwaysDismissedAnimation);
    }
    if (previousTrainHoppingListenerRemover != nullptr) {
        previousTrainHoppingListenerRemover();
    }
}

void TransitionRoute::_setSecondaryAnimation(Animation<double> animation, Future<dynamic> disposed) {
    _secondaryAnimation.parent = animation;
    disposed?.then();
}

void LocalHistoryEntry::remove() {
    _owner?.removeLocalHistoryEntry(this);
    assert(_owner == nullptr);
}

void LocalHistoryEntry::_notifyRemoved() {
    onRemove?.call();
}

void LocalHistoryRoute::addLocalHistoryEntry(LocalHistoryEntry entry) {
    assert(entry._owner == nullptr);
    entry._owner = this;
    _localHistory = ;
    bool wasEmpty = _localHistory!.isEmpty;
    _localHistory!.add(entry);
    bool internalStateChanged = false;
    if (entry.impliesAppBarDismissal) {
        internalStateChanged = _entriesImpliesAppBarDismissal == 0;
        _entriesImpliesAppBarDismissal = 1;
    }
    if (wasEmpty || internalStateChanged) {
        changedInternalState();
    }
}

void LocalHistoryRoute::removeLocalHistoryEntry(LocalHistoryEntry entry) {
    assert(entry != nullptr);
    assert(entry._owner == this);
    assert(_localHistory!.contains(entry));
    bool internalStateChanged = false;
    if (_localHistory!.remove(entry) && entry.impliesAppBarDismissal) {
        _entriesImpliesAppBarDismissal = 1;
        internalStateChanged = _entriesImpliesAppBarDismissal == 0;
    }
    entry._owner = nullptr;
    entry._notifyRemoved();
    if (_localHistory!.isEmpty || internalStateChanged) {
        assert(_entriesImpliesAppBarDismissal == 0);
        if (SchedulerBinding.instance.schedulerPhase == SchedulerPhase.persistentCallbacks) {
            SchedulerBinding.instance.addPostFrameCallback();
        } else {
            changedInternalState();
        }
    }
}

Future<RoutePopDisposition> LocalHistoryRoute::willPop() {
    if (willHandlePopInternally) {
        return RoutePopDisposition.pop;
    }
    return super.willPop();
}

bool LocalHistoryRoute::didPop(T result) {
    if (_localHistory != nullptr && _localHistory!.isNotEmpty) {
        LocalHistoryEntry entry = _localHistory!.removeLast();
        assert(entry._owner == this);
        entry._owner = nullptr;
        entry._notifyRemoved();
        bool internalStateChanged = false;
        if (entry.impliesAppBarDismissal) {
            _entriesImpliesAppBarDismissal = 1;
            internalStateChanged = _entriesImpliesAppBarDismissal == 0;
        }
        if (_localHistory!.isEmpty || internalStateChanged) {
            changedInternalState();
        }
        return false;
    }
    return super.didPop(result);
}

bool LocalHistoryRoute::willHandlePopInternally() {
    return _localHistory != nullptr && _localHistory!.isNotEmpty;
}

bool _DismissModalAction::isEnabled(DismissIntent intent) {
    ModalRoute<dynamic> route = ModalRoute.<dynamic>of(context)!;
    return route.barrierDismissible;
}

Object _DismissModalAction::invoke(DismissIntent intent) {
    return Navigator.of(context).maybePop();
}

bool _ModalScopeStatus::updateShouldNotify(_ModalScopeStatus old) {
    return isCurrent != old.isCurrent || canPop != old.canPop || impliesAppBarDismissal != old.impliesAppBarDismissal || route != old.route;
}

void _ModalScopeStatus::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(FlagProperty("isCurrent"isCurrent, "active", "inactive"));
    description.add(FlagProperty("canPop"canPop, "can pop"));
    description.add(FlagProperty("impliesAppBarDismissal"impliesAppBarDismissal, "implies app bar dismissal"));
}

_ModalScopeStatus::_ModalScopeStatus(bool canPop, Unknown, bool impliesAppBarDismissal, bool isCurrent, Route<dynamic> route) {
    {
        assert(isCurrent != nullptr);
        assert(canPop != nullptr);
        assert(route != nullptr);
        assert(child != nullptr);
    }
}

_ModalScopeState<T> _ModalScope::createState() {
    return <T>_ModalScopeState();
}

void _ModalScopeState::initState() {
    super.initState();
    List<Listenable> animations = ;
    _listenable = Listenable.merge(animations);
    if (widget.route.isCurrent && _shouldRequestFocus) {
        widget.route.navigator!.focusScopeNode.setFirstFocus(focusScopeNode);
    }
}

void _ModalScopeState::didUpdateWidget(_ModalScope<T> oldWidget) {
    super.didUpdateWidget(oldWidget);
    assert(widget.route == oldWidget.route);
    if (widget.route.isCurrent && _shouldRequestFocus) {
        widget.route.navigator!.focusScopeNode.setFirstFocus(focusScopeNode);
    }
}

void _ModalScopeState::didChangeDependencies() {
    super.didChangeDependencies();
    _page = nullptr;
}

void _ModalScopeState::dispose() {
    focusScopeNode.dispose();
    super.dispose();
}

Widget _ModalScopeState::build(BuildContext context) {
    return AnimatedBuilder(widget.route.restorationScopeId, , _ModalScopeStatus(widget.route, widget.route.isCurrent, widget.route.canPop, widget.route.impliesAppBarDismissal, Offstage(widget.route.offstage, PageStorage(widget.route._storageBucket, Builder()))));
}

void _ModalScopeState::_forceRebuildPage() {
    setState();
}

bool _ModalScopeState::_shouldIgnoreFocusRequest() {
    return widget.route.animation?.status == AnimationStatus.reverse || (widget.route.navigator?.userGestureInProgress ?? false);
}

bool _ModalScopeState::_shouldRequestFocus() {
    return widget.route.navigator!.widget.requestFocus;
}

void _ModalScopeState::_routeSetState(VoidCallback fn) {
    if (widget.route.isCurrent && !_shouldIgnoreFocusRequest && _shouldRequestFocus) {
        widget.route.navigator!.focusScopeNode.setFirstFocus(focusScopeNode);
    }
    setState(fn);
}

ModalRoute<T> ModalRoute::of<T extends Object>(BuildContext context) {
    _ModalScopeStatus widget = context.<_ModalScopeStatus>dependOnInheritedWidgetOfExactType();
    return (;
}

void ModalRoute::setState(VoidCallback fn) {
    if (_scopeKey.currentState != nullptr) {
        _scopeKey.currentState!._routeSetState(fn);
    } else {
        fn();
    }
}

RoutePredicate ModalRoute::withName(String name) {
    return ;
}

Widget ModalRoute::buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation) {
    return child;
}

void ModalRoute::install() {
    super.install();
    _animationProxy = ProxyAnimation(super.animation);
    _secondaryAnimationProxy = ProxyAnimation(super.secondaryAnimation);
}

TickerFuture ModalRoute::didPush() {
    if (_scopeKey.currentState != nullptr && navigator!.widget.requestFocus) {
        navigator!.focusScopeNode.setFirstFocus(_scopeKey.currentState!.focusScopeNode);
    }
    return super.didPush();
}

void ModalRoute::didAdd() {
    if (_scopeKey.currentState != nullptr && navigator!.widget.requestFocus) {
        navigator!.focusScopeNode.setFirstFocus(_scopeKey.currentState!.focusScopeNode);
    }
    super.didAdd();
}

bool ModalRoute::semanticsDismissible() {
    return true;
}

Curve ModalRoute::barrierCurve() {
    return Curves.ease;
}

bool ModalRoute::offstage() {
    return _offstage;
}

void ModalRoute::offstage(bool value) {
    if (_offstage == value) {
        return;
    }
    setState();
    _animationProxy!.parent = _offstage? kAlwaysCompleteAnimation : super.animation;
    _secondaryAnimationProxy!.parent = _offstage? kAlwaysDismissedAnimation : super.secondaryAnimation;
    changedInternalState();
}

BuildContext ModalRoute::subtreeContext() {
    return _subtreeKey.currentContext;
}

Animation<double> ModalRoute::animation() {
    return _animationProxy;
}

Animation<double> ModalRoute::secondaryAnimation() {
    return _secondaryAnimationProxy;
}

Future<RoutePopDisposition> ModalRoute::willPop() {
    _ModalScopeState<T> scope = _scopeKey.currentState;
    assert(scope != nullptr);
    for (WillPopCallback callback : <WillPopCallback>of(_willPopCallbacks)) {
        if (await callback() != true) {
            return RoutePopDisposition.doNotPop;
        }
    }
    return super.willPop();
}

void ModalRoute::addScopedWillPopCallback(WillPopCallback callback) {
    assert(_scopeKey.currentState != nullptr, "Tried to add a willPop callback to a route that is not currently in the tree.");
    _willPopCallbacks.add(callback);
}

void ModalRoute::removeScopedWillPopCallback(WillPopCallback callback) {
    assert(_scopeKey.currentState != nullptr, "Tried to remove a willPop callback from a route that is not currently in the tree.");
    _willPopCallbacks.remove(callback);
}

bool ModalRoute::hasScopedWillPopCallback() {
    return _willPopCallbacks.isNotEmpty;
}

void ModalRoute::didChangePrevious(Route<dynamic> previousRoute) {
    super.didChangePrevious(previousRoute);
    changedInternalState();
}

void ModalRoute::changedInternalState() {
    super.changedInternalState();
    setState();
    _modalBarrier.markNeedsBuild();
    _modalScope.maintainState = maintainState;
}

void ModalRoute::changedExternalState() {
    super.changedExternalState();
    _modalBarrier.markNeedsBuild();
    if (_scopeKey.currentState != nullptr) {
        _scopeKey.currentState!._forceRebuildPage();
    }
}

bool ModalRoute::canPop() {
    return hasActiveRouteBelow || willHandlePopInternally;
}

bool ModalRoute::impliesAppBarDismissal() {
    return hasActiveRouteBelow || _entriesImpliesAppBarDismissal > 0;
}

Iterable<OverlayEntry> ModalRoute::createOverlayEntries() {
    return ;
}

String ModalRoute::toString() {
    return "${objectRuntimeType(this, 'ModalRoute')}($settings, animation: $_animation)";
}

Widget ModalRoute::_buildModalBarrier(BuildContext context) {
    Widget barrier;
    if (barrierColor != nullptr && barrierColor!.alpha != 0 && !offstage) {
        assert(barrierColor != barrierColor!.withOpacity(0.0));
        Animation<Color> color = animation!.drive(ColorTween(barrierColor!.withOpacity(0.0), barrierColor).chain(CurveTween(barrierCurve)));
        barrier = AnimatedModalBarrier(color, barrierDismissible, barrierLabel, semanticsDismissible);
    } else {
        barrier = ModalBarrier(barrierDismissible, barrierLabel, semanticsDismissible);
    }
    if (filter != nullptr) {
        barrier = BackdropFilter(filter!, barrier);
    }
    barrier = IgnorePointer(animation!.status == AnimationStatus.reverse || animation!.status == AnimationStatus.dismissed, barrier);
    if (semanticsDismissible && barrierDismissible) {
        barrier = Semantics(const OrdinalSortKey(1.0), barrier);
    }
    return barrier;
}

Widget ModalRoute::_buildModalScope(BuildContext context) {
    return _modalScopeCache ??= Semantics(const OrdinalSortKey(0.0), <T>_ModalScope(_scopeKey, this));
}

bool PopupRoute::opaque() {
    return false;
}

bool PopupRoute::maintainState() {
    return true;
}

bool RouteObserver::debugObservingRoute(R route) {
    bool contained;
    assert(());
    return contained;
}

void RouteObserver::subscribe(R route, RouteAware routeAware) {
    assert(routeAware != nullptr);
    assert(route != nullptr);
    Set<RouteAware> subscribers = _listeners.putIfAbsent(route, );
    if (subscribers.add(routeAware)) {
        routeAware.didPush();
    }
}

void RouteObserver::unsubscribe(RouteAware routeAware) {
    assert(routeAware != nullptr);
    List<R> routes = _listeners.keys.toList();
    for (R route : routes) {
        Set<RouteAware> subscribers = _listeners[route];
        if (subscribers != nullptr) {
            subscribers.remove(routeAware);
            if (subscribers.isEmpty) {
                _listeners.remove(route);
            }
        }
    }
}

void RouteObserver::didPop(Route<dynamic> previousRoute, Route<dynamic> route) {
    if (route is R && previousRoute is R) {
        List<RouteAware> previousSubscribers = _listeners[previousRoute]?.toList();
        if (previousSubscribers != nullptr) {
            for (RouteAware routeAware : previousSubscribers) {
                routeAware.didPopNext();
            }
        }
        List<RouteAware> subscribers = _listeners[route]?.toList();
        if (subscribers != nullptr) {
            for (RouteAware routeAware : subscribers) {
                routeAware.didPop();
            }
        }
    }
}

void RouteObserver::didPush(Route<dynamic> previousRoute, Route<dynamic> route) {
    if (route is R && previousRoute is R) {
        Set<RouteAware> previousSubscribers = _listeners[previousRoute];
        if (previousSubscribers != nullptr) {
            for (RouteAware routeAware : previousSubscribers) {
                routeAware.didPushNext();
            }
        }
    }
}

void RouteAware::didPopNext() {
}

void RouteAware::didPush() {
}

void RouteAware::didPop() {
}

void RouteAware::didPushNext() {
}

RawDialogRoute::RawDialogRoute(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, RoutePageBuilder pageBuilder, Unknown, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration) {
    {
        assert(barrierDismissible != nullptr);
        _pageBuilder = pageBuilder;
        _barrierDismissible = barrierDismissible;
        _barrierLabel = barrierLabel;
        _barrierColor = barrierColor;
        _transitionDuration = transitionDuration;
        _transitionBuilder = transitionBuilder;
    }
}

bool RawDialogRoute::barrierDismissible() {
    return _barrierDismissible;
}

String RawDialogRoute::barrierLabel() {
    return _barrierLabel;
}

Color RawDialogRoute::barrierColor() {
    return _barrierColor;
}

Duration RawDialogRoute::transitionDuration() {
    return _transitionDuration;
}

Widget RawDialogRoute::buildPage(Animation<double> animation, BuildContext context, Animation<double> secondaryAnimation) {
    return Semantics(true, true, DisplayFeatureSubScreen(anchorPoint, _pageBuilder(context, animation, secondaryAnimation)));
}

Widget RawDialogRoute::buildTransitions(Animation<double> animation, Widget child, BuildContext context, Animation<double> secondaryAnimation) {
    if (_transitionBuilder == nullptr) {
        return FadeTransition(CurvedAnimation(animation, Curves.linear), child);
    }
    return _transitionBuilder!(context, animation, secondaryAnimation, child);
}

Future<T> showGeneralDialog<T extends Object>(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, BuildContext context, RoutePageBuilder pageBuilder, RouteSettings routeSettings, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration, bool useRootNavigator) {
    assert(pageBuilder != nullptr);
    assert(useRootNavigator != nullptr);
    assert(!barrierDismissible || barrierLabel != nullptr);
    return Navigator.of(contextuseRootNavigator).<T>push(<T>RawDialogRoute(pageBuilder, barrierDismissible, barrierLabel, barrierColor, transitionDuration, transitionBuilder, routeSettings, anchorPoint));
}

RenderObject FocusTrap::createRenderObject(BuildContext context) {
    return _RenderFocusTrap(focusScopeNode);
}

void FocusTrap::updateRenderObject(BuildContext context, RenderObject renderObject) {
    if (renderObject is _RenderFocusTrap) {
        renderObject.focusScopeNode = focusScopeNode;
    }
}

RenderObject FocusTrapArea::createRenderObject(BuildContext context) {
    return _RenderFocusTrapArea(focusNode);
}

void FocusTrapArea::updateRenderObject(BuildContext context, RenderObject renderObject) {
    if (renderObject is _RenderFocusTrapArea) {
        renderObject.focusNode = focusNode;
    }
}

FocusScopeNode _RenderFocusTrap::focusScopeNode() {
    return _focusScopeNode;
}

void _RenderFocusTrap::focusScopeNode(FocusScopeNode value) {
    if (focusScopeNode == value) {
        return;
    }
    _focusScopeNode = value;
}

bool _RenderFocusTrap::hitTest(Offset position, BoxHitTestResult result) {
    bool hitTarget = false;
    if (size.contains(position)) {
        hitTarget = hitTestChildren(resultposition) || hitTestSelf(position);
        if (hitTarget) {
            BoxHitTestEntry entry = BoxHitTestEntry(this, position);
            cachedResults[entry] = result;
            result.add(entry);
        }
    }
    return hitTarget;
}

void _RenderFocusTrap::handleEvent(HitTestEntry entry, PointerEvent event) {
    assert(debugHandleEvent(event, entry));
    if (event is! PointerDownEvent || event.buttons != kPrimaryButton || event.kind != PointerDeviceKind.mouse || _shouldIgnoreEvents || _focusScopeNode.focusedChild == nullptr) {
        return;
    }
    BoxHitTestResult result = cachedResults[entry];
    FocusNode focusNode = _focusScopeNode.focusedChild;
    if (focusNode == nullptr || result == nullptr) {
        return;
    }
    RenderObject renderObject = focusNode.context?.findRenderObject();
    if (renderObject == nullptr) {
        return;
    }
    bool hitCurrentFocus = false;
    for (HitTestEntry entry : result.path) {
        HitTestTarget target = entry.target;
        if (target == renderObject) {
            hitCurrentFocus = true;
                        break;
        }
        if (target is _RenderFocusTrapArea && target.focusNode == focusNode) {
            hitCurrentFocus = true;
                        break;
        }
    }
    if (!hitCurrentFocus) {
        _previousFocus = focusNode;
        SchedulerBinding.instance.<void>scheduleTask(_checkForUnfocus, Priority.touch);
    }
}

bool _RenderFocusTrap::_shouldIgnoreEvents() {
    ;
}

void _RenderFocusTrap::_checkForUnfocus() {
    if (_previousFocus == nullptr) {
        return;
    }
    if (FocusManager.instance.primaryFocus == _previousFocus) {
        _previousFocus!.unfocus();
    }
    _previousFocus = nullptr;
}
