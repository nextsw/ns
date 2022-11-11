#include "routes.hpp"
template<typename T>
List<OverlayEntry> OverlayRouteCls<T>::overlayEntries() {
    return _overlayEntries;
}

template<typename T>
void OverlayRouteCls<T>::install() {
    assert(_overlayEntries->isEmpty());
    _overlayEntries->addAll(createOverlayEntries());
    super->install();
}

template<typename T>
bool OverlayRouteCls<T>::finishedWhenPopped() {
    return true;
}

template<typename T>
bool OverlayRouteCls<T>::didPop(T result) {
    bool returnValue = super->didPop(result);
    assert(returnValue);
    if (finishedWhenPopped()) {
        navigator()!->finalizeRoute(this);
    }
    return returnValue;
}

template<typename T>
void OverlayRouteCls<T>::dispose() {
    _overlayEntries->clear();
    super->dispose();
}

template<typename T>
Future<T> TransitionRouteCls<T>::completed() {
    return _transitionCompleter->future();
}

template<typename T>
Duration TransitionRouteCls<T>::reverseTransitionDuration() {
    return transitionDuration();
}

template<typename T>
bool TransitionRouteCls<T>::finishedWhenPopped() {
    return _controller!->status() == AnimationStatusCls::dismissed && !_popFinalized;
}

template<typename T>
Animation<double> TransitionRouteCls<T>::animation() {
    return _animation;
}

template<typename T>
AnimationController TransitionRouteCls<T>::controller() {
    return _controller;
}

template<typename T>
Animation<double> TransitionRouteCls<T>::secondaryAnimation() {
    return _secondaryAnimation;
}

template<typename T>
AnimationController TransitionRouteCls<T>::createAnimationController() {
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    Duration duration = transitionDuration();
    Duration reverseDuration = reverseTransitionDuration();
    assert(duration != nullptr && duration >= DurationCls::zero);
    return make<AnimationControllerCls>(duration, reverseDuration, debugLabel(), navigator()!);
}

template<typename T>
Animation<double> TransitionRouteCls<T>::createAnimation() {
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    assert(_controller != nullptr);
    return _controller!->view();
}

template<typename T>
void TransitionRouteCls<T>::install() {
    assert(!_transitionCompleter->isCompleted(), __s("Cannot install a $runtimeType after disposing it."));
    _controller = createAnimationController();
    assert(_controller != nullptr, __s("$runtimeType.createAnimationController() returned null."));
    auto _c1 = createAnimation();_c1.addStatusListener(_handleStatusChanged);_animation = _c1;
    assert(_animation != nullptr, __s("$runtimeType.createAnimation() returned null."));
    super->install();
    if (_animation!->isCompleted() && overlayEntries()->isNotEmpty()) {
        overlayEntries()->first->opaque = opaque();
    }
}

template<typename T>
TickerFuture TransitionRouteCls<T>::didPush() {
    assert(_controller != nullptr, __s("$runtimeType.didPush called before calling install() or after calling dispose()."));
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    super->didPush();
    return _controller!->forward();
}

template<typename T>
void TransitionRouteCls<T>::didAdd() {
    assert(_controller != nullptr, __s("$runtimeType.didPush called before calling install() or after calling dispose()."));
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    super->didAdd();
    _controller!->value() = _controller!->upperBound;
}

template<typename T>
void TransitionRouteCls<T>::didReplace(Route<dynamic> oldRoute) {
    assert(_controller != nullptr, __s("$runtimeType.didReplace called before calling install() or after calling dispose()."));
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    if (is<TransitionRoute<any>>(oldRoute)) {
        _controller!->value() = as<TransitionRouteCls>(oldRoute)->_controller!->value();
    }
    super->didReplace(oldRoute);
}

template<typename T>
bool TransitionRouteCls<T>::didPop(T result) {
    assert(_controller != nullptr, __s("$runtimeType.didPop called before calling install() or after calling dispose()."));
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    _result = result;
    _controller!->reverse();
    return super->didPop(result);
}

template<typename T>
void TransitionRouteCls<T>::didPopNext(Route<dynamic> nextRoute) {
    assert(_controller != nullptr, __s("$runtimeType.didPopNext called before calling install() or after calling dispose()."));
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    _updateSecondaryAnimation(nextRoute);
    super->didPopNext(nextRoute);
}

template<typename T>
void TransitionRouteCls<T>::didChangeNext(Route<dynamic> nextRoute) {
    assert(_controller != nullptr, __s("$runtimeType.didChangeNext called before calling install() or after calling dispose()."));
    assert(!_transitionCompleter->isCompleted(), __s("Cannot reuse a $runtimeType after disposing it."));
    _updateSecondaryAnimation(nextRoute);
    super->didChangeNext(nextRoute);
}

template<typename T>
bool TransitionRouteCls<T>::canTransitionTo(TransitionRoute<dynamic> nextRoute) {
    return true;
}

template<typename T>
bool TransitionRouteCls<T>::canTransitionFrom(TransitionRoute<dynamic> previousRoute) {
    return true;
}

template<typename T>
void TransitionRouteCls<T>::dispose() {
    assert(!_transitionCompleter->isCompleted(), __s("Cannot dispose a $runtimeType twice."));
    _animation?->removeStatusListener(_handleStatusChanged);
    if (willDisposeAnimationController) {
        _controller?->dispose();
    }
    _transitionCompleter->complete(_result);
    super->dispose();
}

template<typename T>
String TransitionRouteCls<T>::debugLabel() {
    return objectRuntimeType(this, __s("TransitionRoute"));
}

template<typename T>
String TransitionRouteCls<T>::toString() {
    return __s("${objectRuntimeType(this, 'TransitionRoute')}(animation: $_controller)");
}

template<typename T>
void TransitionRouteCls<T>::_handleStatusChanged(AnimationStatus status) {
    ;
}

template<typename T>
void TransitionRouteCls<T>::_updateSecondaryAnimation(Route<dynamic> nextRoute) {
    VoidCallback previousTrainHoppingListenerRemover = _trainHoppingListenerRemover;
    _trainHoppingListenerRemover = nullptr;
    if (is<TransitionRoute<dynamic>>(nextRoute) && canTransitionTo(nextRoute) && nextRoute->canTransitionFrom(this)) {
        Animation<double> current = _secondaryAnimation->parent();
        if (current != nullptr) {
            Animation<double> currentTrain = (is<TrainHoppingAnimation>(current)? current->currentTrain : current)!;
            Animation<double> nextTrain = nextRoute->_animation!;
            if (currentTrain->value() == nextTrain->value() || nextTrain->status() == AnimationStatusCls::completed || nextTrain->status() == AnimationStatusCls::dismissed) {
                _setSecondaryAnimation(nextTrain, nextRoute->completed);
            } else {
                TrainHoppingAnimation newAnimation;
                InlineMethod;
                _trainHoppingListenerRemover = [=] () {
                    nextTrain->removeStatusListener(jumpOnAnimationEnd);
                    newAnimation?->dispose();
                };
                nextTrain->addStatusListener(jumpOnAnimationEnd);
                newAnimation = make<TrainHoppingAnimationCls>(currentTrain, nextTrain, [=] () {
                    assert(_secondaryAnimation->parent() == newAnimation);
                    assert(newAnimation!->currentTrain == nextRoute->_animation);
                    _setSecondaryAnimation(newAnimation!->currentTrain, nextRoute->completed);
                    if (_trainHoppingListenerRemover != nullptr) {
                        _trainHoppingListenerRemover!();
                        _trainHoppingListenerRemover = nullptr;
                    }
                });
                _setSecondaryAnimation(newAnimation, nextRoute->completed);
            }
        } else {
            _setSecondaryAnimation(nextRoute->_animation, nextRoute->completed);
        }
    } else {
        _setSecondaryAnimation(kAlwaysDismissedAnimation);
    }
    if (previousTrainHoppingListenerRemover != nullptr) {
        previousTrainHoppingListenerRemover();
    }
}

template<typename T>
void TransitionRouteCls<T>::_setSecondaryAnimation(Animation<double> animation, Future<dynamic> disposed) {
    _secondaryAnimation->parent() = animation;
    disposed?->then([=] (dynamic _) {
        if (_secondaryAnimation->parent() == animation) {
            _secondaryAnimation->parent() = kAlwaysDismissedAnimation;
            if (is<TrainHoppingAnimation>(animation)) {
                as<TrainHoppingAnimationCls>(animation)->dispose();
            }
        }
    });
}

void LocalHistoryEntryCls::remove() {
    _owner?->removeLocalHistoryEntry(this);
    assert(_owner == nullptr);
}

void LocalHistoryEntryCls::_notifyRemoved() {
    onRemove?->call();
}

template<typename T>
void LocalHistoryRouteCls<T>::addLocalHistoryEntry(LocalHistoryEntry entry) {
    assert(entry->_owner == nullptr);
    entry->_owner = this;
    _localHistory |= makeList();
    bool wasEmpty = _localHistory!->isEmpty();
    _localHistory!->add(entry);
    bool internalStateChanged = false;
    if (entry->impliesAppBarDismissal) {
        internalStateChanged = _entriesImpliesAppBarDismissal == 0;
        _entriesImpliesAppBarDismissal += 1;
    }
    if (wasEmpty || internalStateChanged) {
        changedInternalState();
    }
}

template<typename T>
void LocalHistoryRouteCls<T>::removeLocalHistoryEntry(LocalHistoryEntry entry) {
    assert(entry != nullptr);
    assert(entry->_owner == this);
    assert(_localHistory!->contains(entry));
    bool internalStateChanged = false;
    if (_localHistory!->remove(entry) && entry->impliesAppBarDismissal) {
        _entriesImpliesAppBarDismissal -= 1;
        internalStateChanged = _entriesImpliesAppBarDismissal == 0;
    }
    entry->_owner = nullptr;
    entry->_notifyRemoved();
    if (_localHistory!->isEmpty() || internalStateChanged) {
        assert(_entriesImpliesAppBarDismissal == 0);
        if (SchedulerBindingCls::instance->schedulerPhase == SchedulerPhaseCls::persistentCallbacks) {
            SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration duration) {
                changedInternalState();
            });
        } else {
            changedInternalState();
        }
    }
}

template<typename T>
Future<RoutePopDisposition> LocalHistoryRouteCls<T>::willPop() {
    if (willHandlePopInternally()) {
        return RoutePopDispositionCls::pop;
    }
    return super->willPop();
}

template<typename T>
bool LocalHistoryRouteCls<T>::didPop(T result) {
    if (_localHistory != nullptr && _localHistory!->isNotEmpty()) {
        LocalHistoryEntry entry = _localHistory!->removeLast();
        assert(entry->_owner == this);
        entry->_owner = nullptr;
        entry->_notifyRemoved();
        bool internalStateChanged = false;
        if (entry->impliesAppBarDismissal) {
            _entriesImpliesAppBarDismissal -= 1;
            internalStateChanged = _entriesImpliesAppBarDismissal == 0;
        }
        if (_localHistory!->isEmpty() || internalStateChanged) {
            changedInternalState();
        }
        return false;
    }
    return super->didPop(result);
}

template<typename T>
bool LocalHistoryRouteCls<T>::willHandlePopInternally() {
    return _localHistory != nullptr && _localHistory!->isNotEmpty();
}

bool _DismissModalActionCls::isEnabled(DismissIntent intent) {
    ModalRoute<dynamic> route = ModalRouteCls-><dynamic>of(context)!;
    return route->barrierDismissible();
}

Object _DismissModalActionCls::invoke(DismissIntent intent) {
    return NavigatorCls->of(context)->maybePop();
}

bool _ModalScopeStatusCls::updateShouldNotify(_ModalScopeStatus old) {
    return isCurrent != old->isCurrent || canPop != old->canPop || impliesAppBarDismissal != old->impliesAppBarDismissal || route != old->route;
}

void _ModalScopeStatusCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(make<FlagPropertyCls>(__s("isCurrent"), isCurrent, __s("active"), __s("inactive")));
    description->add(make<FlagPropertyCls>(__s("canPop"), canPop, __s("can pop")));
    description->add(make<FlagPropertyCls>(__s("impliesAppBarDismissal"), impliesAppBarDismissal, __s("implies app bar dismissal")));
}

_ModalScopeStatusCls::_ModalScopeStatusCls(bool canPop, Widget child, bool impliesAppBarDismissal, bool isCurrent, Route<dynamic> route) {
    {
        assert(isCurrent != nullptr);
        assert(canPop != nullptr);
        assert(route != nullptr);
        assert(child != nullptr);
    }
}

template<typename T>
_ModalScopeState<T> _ModalScopeCls<T>::createState() {
    return <T>make<_ModalScopeStateCls>();
}

template<typename T>
void _ModalScopeStateCls<T>::initState() {
    super->initState();
    List<Listenable> list1 = make<ListCls<>>();if (widget()->route->animation != nullptr) {    list1.add(ArrayItem);}if (widget()->route->secondaryAnimation != nullptr) {    list1.add(ArrayItem);}List<Listenable> animations = list1;
    _listenable = ListenableCls->merge(animations);
    if (widget()->route->isCurrent && _shouldRequestFocus()) {
        widget()->route->navigator!->focusScopeNode->setFirstFocus(focusScopeNode);
    }
}

template<typename T>
void _ModalScopeStateCls<T>::didUpdateWidget(_ModalScope<T> oldWidget) {
    super->didUpdateWidget(oldWidget);
    assert(widget()->route == oldWidget->route);
    if (widget()->route->isCurrent && _shouldRequestFocus()) {
        widget()->route->navigator!->focusScopeNode->setFirstFocus(focusScopeNode);
    }
}

template<typename T>
void _ModalScopeStateCls<T>::didChangeDependencies() {
    super->didChangeDependencies();
    _page = nullptr;
}

template<typename T>
void _ModalScopeStateCls<T>::dispose() {
    focusScopeNode->dispose();
    super->dispose();
}

template<typename T>
Widget _ModalScopeStateCls<T>::build(BuildContext context) {
    return make<AnimatedBuilderCls>(widget()->route->restorationScopeId, [=] (BuildContext context,Widget child) {
        assert(child != nullptr);
        return make<RestorationScopeCls>(widget()->route->restorationScopeId->value, child!);
    }, make<_ModalScopeStatusCls>(widget()->route, widget()->route->isCurrent, widget()->route->canPop, widget()->route->impliesAppBarDismissal, make<OffstageCls>(widget()->route->offstage, make<PageStorageCls>(widget()->route->_storageBucket, make<BuilderCls>([=] (BuildContext context) {
        return make<ActionsCls>(list1, make<PrimaryScrollControllerCls>(primaryScrollController, make<FocusScopeCls>(focusScopeNode, make<FocusTrapCls>(focusScopeNode, make<RepaintBoundaryCls>(make<AnimatedBuilderCls>(_listenable, [=] (BuildContext context,Widget child) {
            return widget()->route->buildTransitions(context, widget()->route->animation!, widget()->route->secondaryAnimation!, make<AnimatedBuilderCls>(widget()->route->navigator?->userGestureInProgressNotifier | <bool>make<ValueNotifierCls>(false), [=] (BuildContext context,Widget child) {
                            Map<Type, Action<Intent>> map1 = make<MapCls<>>();            map1.set(DismissIntentCls, make<_DismissModalActionCls>(context));bool ignoreEvents = _shouldIgnoreFocusRequest();
                focusScopeNode->canRequestFocus() = !ignoreEvents;
                return make<IgnorePointerCls>(ignoreEvents, child);
            }, child));
        }, _page ??= make<RepaintBoundaryCls>(widget()->route->_subtreeKey, make<BuilderCls>([=] (BuildContext context) {
            return widget()->route->buildPage(context, widget()->route->animation!, widget()->route->secondaryAnimation!);
        }))))))));
    })))));
}

template<typename T>
void _ModalScopeStateCls<T>::_forceRebuildPage() {
    setState([=] () {
        _page = nullptr;
    });
}

template<typename T>
bool _ModalScopeStateCls<T>::_shouldIgnoreFocusRequest() {
    return widget()->route->animation?->status == AnimationStatusCls::reverse || (widget()->route->navigator?->userGestureInProgress | false);
}

template<typename T>
bool _ModalScopeStateCls<T>::_shouldRequestFocus() {
    return widget()->route->navigator!->widget->requestFocus;
}

template<typename T>
void _ModalScopeStateCls<T>::_routeSetState(VoidCallback fn) {
    if (widget()->route->isCurrent && !_shouldIgnoreFocusRequest() && _shouldRequestFocus()) {
        widget()->route->navigator!->focusScopeNode->setFirstFocus(focusScopeNode);
    }
    setState(fn);
}

template<typename T>
template<typename T>
ModalRoute<T> ModalRouteCls<T>::of(BuildContext context) {
    _ModalScopeStatus widget = context-><_ModalScopeStatus>dependOnInheritedWidgetOfExactType();
    return as<ModalRoute<T>>(widget?->route);
}

template<typename T>
void ModalRouteCls<T>::setState(VoidCallback fn) {
    if (_scopeKey->currentState() != nullptr) {
        _scopeKey->currentState()!->_routeSetState(fn);
    } else {
        fn();
    }
}

template<typename T>
RoutePredicate ModalRouteCls<T>::withName(String name) {
    return [=] (Route<dynamic> route) {
        return !route->willHandlePopInternally && is<ModalRoute<any>>(route) && route->settings->name == name;
    };
}

template<typename T>
Widget ModalRouteCls<T>::buildTransitions(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation, Widget child) {
    return child;
}

template<typename T>
void ModalRouteCls<T>::install() {
    super->install();
    _animationProxy = make<ProxyAnimationCls>(super->animation);
    _secondaryAnimationProxy = make<ProxyAnimationCls>(super->secondaryAnimation);
}

template<typename T>
TickerFuture ModalRouteCls<T>::didPush() {
    if (_scopeKey->currentState() != nullptr && navigator()!->widget()->requestFocus) {
        navigator()!->focusScopeNode->setFirstFocus(_scopeKey->currentState()!->focusScopeNode);
    }
    return super->didPush();
}

template<typename T>
void ModalRouteCls<T>::didAdd() {
    if (_scopeKey->currentState() != nullptr && navigator()!->widget()->requestFocus) {
        navigator()!->focusScopeNode->setFirstFocus(_scopeKey->currentState()!->focusScopeNode);
    }
    super->didAdd();
}

template<typename T>
bool ModalRouteCls<T>::semanticsDismissible() {
    return true;
}

template<typename T>
Curve ModalRouteCls<T>::barrierCurve() {
    return CurvesCls::ease;
}

template<typename T>
bool ModalRouteCls<T>::offstage() {
    return _offstage;
}

template<typename T>
void ModalRouteCls<T>::offstage(bool value) {
    if (_offstage == value) {
        return;
    }
    setState([=] () {
        _offstage = value;
    });
    _animationProxy!->parent() = _offstage? kAlwaysCompleteAnimation : super->animation;
    _secondaryAnimationProxy!->parent() = _offstage? kAlwaysDismissedAnimation : super->secondaryAnimation;
    changedInternalState();
}

template<typename T>
BuildContext ModalRouteCls<T>::subtreeContext() {
    return _subtreeKey->currentContext();
}

template<typename T>
Animation<double> ModalRouteCls<T>::animation() {
    return _animationProxy;
}

template<typename T>
Animation<double> ModalRouteCls<T>::secondaryAnimation() {
    return _secondaryAnimationProxy;
}

template<typename T>
Future<RoutePopDisposition> ModalRouteCls<T>::willPop() {
    _ModalScopeState<T> scope = _scopeKey->currentState();
    assert(scope != nullptr);
    for (WillPopCallback callback : <WillPopCallback>of(_willPopCallbacks)) {
        if (await callback() != true) {
            return RoutePopDispositionCls::doNotPop;
        }
    }
    return super->willPop();
}

template<typename T>
void ModalRouteCls<T>::addScopedWillPopCallback(WillPopCallback callback) {
    assert(_scopeKey->currentState() != nullptr, __s("Tried to add a willPop callback to a route that is not currently in the tree."));
    _willPopCallbacks->add(callback);
}

template<typename T>
void ModalRouteCls<T>::removeScopedWillPopCallback(WillPopCallback callback) {
    assert(_scopeKey->currentState() != nullptr, __s("Tried to remove a willPop callback from a route that is not currently in the tree."));
    _willPopCallbacks->remove(callback);
}

template<typename T>
bool ModalRouteCls<T>::hasScopedWillPopCallback() {
    return _willPopCallbacks->isNotEmpty();
}

template<typename T>
void ModalRouteCls<T>::didChangePrevious(Route<dynamic> previousRoute) {
    super->didChangePrevious(previousRoute);
    changedInternalState();
}

template<typename T>
void ModalRouteCls<T>::changedInternalState() {
    super->changedInternalState();
    setState([=] () {
    });
    _modalBarrier->markNeedsBuild();
    _modalScope->maintainState() = maintainState();
}

template<typename T>
void ModalRouteCls<T>::changedExternalState() {
    super->changedExternalState();
    _modalBarrier->markNeedsBuild();
    if (_scopeKey->currentState() != nullptr) {
        _scopeKey->currentState()!->_forceRebuildPage();
    }
}

template<typename T>
bool ModalRouteCls<T>::canPop() {
    return hasActiveRouteBelow() || willHandlePopInternally();
}

template<typename T>
bool ModalRouteCls<T>::impliesAppBarDismissal() {
    return hasActiveRouteBelow() || _entriesImpliesAppBarDismissal > 0;
}

template<typename T>
Iterable<OverlayEntry> ModalRouteCls<T>::createOverlayEntries() {
    return makeList(ArrayItem, ArrayItem);
}

template<typename T>
String ModalRouteCls<T>::toString() {
    return __s("${objectRuntimeType(this, 'ModalRoute')}($settings, animation: $_animation)");
}

template<typename T>
Widget ModalRouteCls<T>::_buildModalBarrier(BuildContext context) {
    Widget barrier;
    if (barrierColor() != nullptr && barrierColor()!->alpha() != 0 && !offstage()) {
        assert(barrierColor() != barrierColor()!->withOpacity(0.0));
        Animation<Color> color = animation()!->drive(make<ColorTweenCls>(barrierColor()!->withOpacity(0.0), barrierColor())->chain(make<CurveTweenCls>(barrierCurve())));
        barrier = make<AnimatedModalBarrierCls>(color, barrierDismissible(), barrierLabel(), semanticsDismissible());
    } else {
        barrier = make<ModalBarrierCls>(barrierDismissible(), barrierLabel(), semanticsDismissible());
    }
    if (filter != nullptr) {
        barrier = make<BackdropFilterCls>(filter!, barrier);
    }
    barrier = make<IgnorePointerCls>(animation()!->status() == AnimationStatusCls::reverse || animation()!->status() == AnimationStatusCls::dismissed, barrier);
    if (semanticsDismissible() && barrierDismissible()) {
        barrier = make<SemanticsCls>(make<OrdinalSortKeyCls>(1.0), barrier);
    }
    return barrier;
}

template<typename T>
Widget ModalRouteCls<T>::_buildModalScope(BuildContext context) {
    return _modalScopeCache ??= make<SemanticsCls>(make<OrdinalSortKeyCls>(0.0), <T>make<_ModalScopeCls>(_scopeKey, this));
}

template<typename T>
bool PopupRouteCls<T>::opaque() {
    return false;
}

template<typename T>
bool PopupRouteCls<T>::maintainState() {
    return true;
}

template<typename R>
bool RouteObserverCls<R>::debugObservingRoute(R route) {
    bool contained;
    assert([=] () {
        contained = _listeners->containsKey(route);
        return true;
    }());
    return contained;
}

template<typename R>
void RouteObserverCls<R>::subscribe(RouteAware routeAware, R route) {
    assert(routeAware != nullptr);
    assert(route != nullptr);
    Set<RouteAware> subscribers = _listeners->putIfAbsent(route, [=] () {
    makeSet();
});
    if (subscribers->add(routeAware)) {
        routeAware->didPush();
    }
}

template<typename R>
void RouteObserverCls<R>::unsubscribe(RouteAware routeAware) {
    assert(routeAware != nullptr);
    List<R> routes = _listeners->keys()->toList();
    for (R route : routes) {
        Set<RouteAware> subscribers = _listeners[route];
        if (subscribers != nullptr) {
            subscribers->remove(routeAware);
            if (subscribers->isEmpty()) {
                _listeners->remove(route);
            }
        }
    }
}

template<typename R>
void RouteObserverCls<R>::didPop(Route<dynamic> route, Route<dynamic> previousRoute) {
    if (is<R>(route) && is<R>(previousRoute)) {
        List<RouteAware> previousSubscribers = _listeners[previousRoute]?->toList();
        if (previousSubscribers != nullptr) {
            for (RouteAware routeAware : previousSubscribers) {
                routeAware->didPopNext();
            }
        }
        List<RouteAware> subscribers = _listeners[route]?->toList();
        if (subscribers != nullptr) {
            for (RouteAware routeAware : subscribers) {
                routeAware->didPop();
            }
        }
    }
}

template<typename R>
void RouteObserverCls<R>::didPush(Route<dynamic> route, Route<dynamic> previousRoute) {
    if (is<R>(route) && is<R>(previousRoute)) {
        Set<RouteAware> previousSubscribers = _listeners[previousRoute];
        if (previousSubscribers != nullptr) {
            for (RouteAware routeAware : previousSubscribers) {
                routeAware->didPushNext();
            }
        }
    }
}

void RouteAwareCls::didPopNext() {
}

void RouteAwareCls::didPush() {
}

void RouteAwareCls::didPop() {
}

void RouteAwareCls::didPushNext() {
}

template<typename T>
RawDialogRouteCls<T>::RawDialogRouteCls(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, RoutePageBuilder pageBuilder, Unknown settings, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration) {
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

template<typename T>
bool RawDialogRouteCls<T>::barrierDismissible() {
    return _barrierDismissible;
}

template<typename T>
String RawDialogRouteCls<T>::barrierLabel() {
    return _barrierLabel;
}

template<typename T>
Color RawDialogRouteCls<T>::barrierColor() {
    return _barrierColor;
}

template<typename T>
Duration RawDialogRouteCls<T>::transitionDuration() {
    return _transitionDuration;
}

template<typename T>
Widget RawDialogRouteCls<T>::buildPage(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation) {
    return make<SemanticsCls>(true, true, make<DisplayFeatureSubScreenCls>(anchorPoint, _pageBuilder(context, animation, secondaryAnimation)));
}

template<typename T>
Widget RawDialogRouteCls<T>::buildTransitions(BuildContext context, Animation<double> animation, Animation<double> secondaryAnimation, Widget child) {
    if (_transitionBuilder == nullptr) {
        return make<FadeTransitionCls>(make<CurvedAnimationCls>(animation, CurvesCls::linear), child);
    }
    return _transitionBuilder!(context, animation, secondaryAnimation, child);
}

template<typename T>
Future<T> showGeneralDialog(Offset anchorPoint, Color barrierColor, bool barrierDismissible, String barrierLabel, BuildContext context, RoutePageBuilder pageBuilder, RouteSettings routeSettings, RouteTransitionsBuilder transitionBuilder, Duration transitionDuration, bool useRootNavigator) {
    assert(pageBuilder != nullptr);
    assert(useRootNavigator != nullptr);
    assert(!barrierDismissible || barrierLabel != nullptr);
    return NavigatorCls->of(context, useRootNavigator)-><T>push(<T>make<RawDialogRouteCls>(pageBuilder, barrierDismissible, barrierLabel, barrierColor, transitionDuration, transitionBuilder, routeSettings, anchorPoint));
}

RenderObject FocusTrapCls::createRenderObject(BuildContext context) {
    return make<_RenderFocusTrapCls>(focusScopeNode);
}

void FocusTrapCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
    if (is<_RenderFocusTrap>(renderObject)) {
        as<_RenderFocusTrapCls>(renderObject)->focusScopeNode = focusScopeNode;
    }
}

RenderObject FocusTrapAreaCls::createRenderObject(BuildContext context) {
    return make<_RenderFocusTrapAreaCls>(focusNode);
}

void FocusTrapAreaCls::updateRenderObject(BuildContext context, RenderObject renderObject) {
    if (is<_RenderFocusTrapArea>(renderObject)) {
        as<_RenderFocusTrapAreaCls>(renderObject)->focusNode = focusNode;
    }
}

FocusScopeNode _RenderFocusTrapCls::focusScopeNode() {
    return _focusScopeNode;
}

void _RenderFocusTrapCls::focusScopeNode(FocusScopeNode value) {
    if (focusScopeNode() == value) {
        return;
    }
    _focusScopeNode = value;
}

bool _RenderFocusTrapCls::hitTest(BoxHitTestResult result, Offset position) {
    bool hitTarget = false;
    if (size()->contains(position)) {
        hitTarget = hitTestChildren(result, position) || hitTestSelf(position);
        if (hitTarget) {
            BoxHitTestEntry entry = make<BoxHitTestEntryCls>(this, position);
            cachedResults[entry] = result;
            result->add(entry);
        }
    }
    return hitTarget;
}

void _RenderFocusTrapCls::handleEvent(PointerEvent event, HitTestEntry<any> entry) {
    assert(debugHandleEvent(event, entry));
    if (!is<PointerDownEvent>(event) || event->buttons != kPrimaryButton || event->kind != PointerDeviceKindCls::mouse || _shouldIgnoreEvents() || _focusScopeNode->focusedChild() == nullptr) {
        return;
    }
    BoxHitTestResult result = cachedResults[entry];
    FocusNode focusNode = _focusScopeNode->focusedChild();
    if (focusNode == nullptr || result == nullptr) {
        return;
    }
    RenderObject renderObject = focusNode->context()?->findRenderObject();
    if (renderObject == nullptr) {
        return;
    }
    bool hitCurrentFocus = false;
    for (HitTestEntry<any> entry : result->path()) {
        HitTestTarget target = entry->target;
        if (target == renderObject) {
            hitCurrentFocus = true;
            break;
        }
        if (is<_RenderFocusTrapArea>(target) && target->focusNode == focusNode) {
            hitCurrentFocus = true;
            break;
        }
    }
    if (!hitCurrentFocus) {
        _previousFocus = focusNode;
        SchedulerBindingCls::instance-><void>scheduleTask(_checkForUnfocus, PriorityCls::touch);
    }
}

bool _RenderFocusTrapCls::_shouldIgnoreEvents() {
    ;
}

void _RenderFocusTrapCls::_checkForUnfocus() {
    if (_previousFocus == nullptr) {
        return;
    }
    if (FocusManagerCls::instance->primaryFocus == _previousFocus) {
        _previousFocus!->unfocus();
    }
    _previousFocus = nullptr;
}
