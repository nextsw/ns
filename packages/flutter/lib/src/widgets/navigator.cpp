#include "navigator.hpp"
template<typename T>
RouteCls<T>::RouteCls(RouteSettings settings) {
    {
        _settings = settings | make<RouteSettingsCls>();
    }
}

template<typename T>
NavigatorState RouteCls<T>::navigator() {
    return _navigator;
}

template<typename T>
RouteSettings RouteCls<T>::settings() {
    return _settings;
}

template<typename T>
ValueListenable<String> RouteCls<T>::restorationScopeId() {
    return _restorationScopeId;
}

template<typename T>
List<OverlayEntry> RouteCls<T>::overlayEntries() {
    return makeList();
}

template<typename T>
void RouteCls<T>::install() {
}

template<typename T>
TickerFuture RouteCls<T>::didPush() {
        });return             }        auto _c1 = TickerFutureCls->complete();        _c1.<void>then([=] (void _) {                if (navigator()?->widget()->requestFocus | false) {                    navigator()!->focusScopeNode->requestFocus();_c1;
}

template<typename T>
void RouteCls<T>::didAdd() {
    if (navigator()?->widget()->requestFocus | false) {
        TickerFutureCls->complete()-><void>then([=] (void _) {
            navigator()?->focusScopeNode->requestFocus();
        });
    }
}

template<typename T>
void RouteCls<T>::didReplace(Route<dynamic> oldRoute) {
}

template<typename T>
Future<RoutePopDisposition> RouteCls<T>::willPop() {
    return isFirst()? RoutePopDispositionCls::bubble : RoutePopDispositionCls::pop;
}

template<typename T>
bool RouteCls<T>::willHandlePopInternally() {
    return false;
}

template<typename T>
T RouteCls<T>::currentResult() {
    return nullptr;
}

template<typename T>
Future<T> RouteCls<T>::popped() {
    return _popCompleter->future();
}

template<typename T>
bool RouteCls<T>::didPop(T result) {
    didComplete(result);
    return true;
}

template<typename T>
void RouteCls<T>::didComplete(T result) {
    _popCompleter->complete(result | currentResult());
}

template<typename T>
void RouteCls<T>::didPopNext(Route<dynamic> nextRoute) {
}

template<typename T>
void RouteCls<T>::didChangeNext(Route<dynamic> nextRoute) {
}

template<typename T>
void RouteCls<T>::didChangePrevious(Route<dynamic> previousRoute) {
}

template<typename T>
void RouteCls<T>::changedInternalState() {
}

template<typename T>
void RouteCls<T>::changedExternalState() {
}

template<typename T>
void RouteCls<T>::dispose() {
    _navigator = nullptr;
}

template<typename T>
bool RouteCls<T>::isCurrent() {
    if (_navigator == nullptr) {
        return false;
    }
    _RouteEntry currentRouteEntry = _navigator!->_history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
    e != nullptr && _RouteEntryCls->isPresentPredicate(e);
}, [=] () {
    nullptr;
});
    if (currentRouteEntry == nullptr) {
        return false;
    }
    return currentRouteEntry->route == this;
}

template<typename T>
bool RouteCls<T>::isFirst() {
    if (_navigator == nullptr) {
        return false;
    }
    _RouteEntry currentRouteEntry = _navigator!->_history-><_RouteEntry>cast()->firstWhere([=] (_RouteEntry e) {
    e != nullptr && _RouteEntryCls->isPresentPredicate(e);
}, [=] () {
    nullptr;
});
    if (currentRouteEntry == nullptr) {
        return false;
    }
    return currentRouteEntry->route == this;
}

template<typename T>
bool RouteCls<T>::hasActiveRouteBelow() {
    if (_navigator == nullptr) {
        return false;
    }
    for (_RouteEntry entry : _navigator!->_history) {
        if (entry->route == this) {
            return false;
        }
        if (_RouteEntryCls->isPresentPredicate(entry)) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool RouteCls<T>::isActive() {
    if (_navigator == nullptr) {
        return false;
    }
    return _navigator!->_history-><_RouteEntry>cast()->firstWhere([=] (_RouteEntry e) {
        e != nullptr && _RouteEntryCls->isRoutePredicate(this)(e);
    }, [=] () {
        nullptr;
    })?->isPresent | false;
}

template<typename T>
void RouteCls<T>::_updateSettings(RouteSettings newSettings) {
    assert(newSettings != nullptr);
    if (_settings != newSettings) {
        _settings = newSettings;
        changedInternalState();
    }
}

template<typename T>
void RouteCls<T>::_updateRestorationId(String restorationId) {
    _restorationScopeId->value() = restorationId;
}

RouteSettings RouteSettingsCls::copyWith(Object arguments, String name) {
    return make<RouteSettingsCls>(name | this->name, arguments | this->arguments);
}

String RouteSettingsCls::toString() {
    return __s("${objectRuntimeType(this, 'RouteSettings')}("$name", $arguments)");
}

template<typename T>
bool PageCls<T>::canUpdate(Page<dynamic> other) {
    return other->runtimeType == runtimeType && other->key == key;
}

template<typename T>
String PageCls<T>::toString() {
    return __s("${objectRuntimeType(this, 'Page')}("$name", $key, $arguments)");
}

NavigatorState NavigatorObserverCls::navigator() {
    return _navigator;
}

void NavigatorObserverCls::didPush(Route<dynamic> route, Route<dynamic> previousRoute) {
}

void NavigatorObserverCls::didPop(Route<dynamic> route, Route<dynamic> previousRoute) {
}

void NavigatorObserverCls::didRemove(Route<dynamic> route, Route<dynamic> previousRoute) {
}

void NavigatorObserverCls::didReplace(Route<dynamic> newRoute, Route<dynamic> oldRoute) {
}

void NavigatorObserverCls::didStartUserGesture(Route<dynamic> route, Route<dynamic> previousRoute) {
}

void NavigatorObserverCls::didStopUserGesture() {
}

HeroControllerScopeCls::HeroControllerScopeCls(Widget child, HeroController controller, Key key) {
    {
        assert(controller != nullptr);
    }
}

void HeroControllerScopeCls::none(Widget child, Key key)

HeroController HeroControllerScopeCls::of(BuildContext context) {
    HeroControllerScope host = context-><HeroControllerScope>dependOnInheritedWidgetOfExactType();
    return host?->controller;
}

bool HeroControllerScopeCls::updateShouldNotify(HeroControllerScope oldWidget) {
    return oldWidget->controller != controller;
}

template<typename T>
Iterable<RouteTransitionRecord> TransitionDelegateCls<T>::_transition(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes) {
    Iterable<RouteTransitionRecord> results = resolve(newPageRouteHistory, locationToExitingPageRoute, pageRouteToPagelessRoutes);
    assert([=] () {
        List<RouteTransitionRecord> resultsToVerify = results->toList(false);
        Set<RouteTransitionRecord> exitingPageRoutes = locationToExitingPageRoute->values()->toSet();
        for (RouteTransitionRecord exitingPageRoute : exitingPageRoutes) {
            assert(!exitingPageRoute->isWaitingForExitingDecision);
            if (pageRouteToPagelessRoutes->containsKey(exitingPageRoute)) {
                for (RouteTransitionRecord pagelessRoute : pageRouteToPagelessRoutes[exitingPageRoute]!) {
                    assert(!pagelessRoute->isWaitingForExitingDecision);
                }
            }
        }
        int indexOfNextRouteInNewHistory = 0;
        for (_RouteEntry routeEntry : resultsToVerify-><_RouteEntry>cast()) {
            assert(routeEntry != nullptr);
            assert(!routeEntry->isWaitingForEnteringDecision && !routeEntry->isWaitingForExitingDecision);
            if (indexOfNextRouteInNewHistory >= newPageRouteHistory->length() || routeEntry != newPageRouteHistory[indexOfNextRouteInNewHistory]) {
                assert(exitingPageRoutes->contains(routeEntry));
                exitingPageRoutes->remove(routeEntry);
            } else {
                indexOfNextRouteInNewHistory += 1;
            }
        }
        assert(indexOfNextRouteInNewHistory == newPageRouteHistory->length() && exitingPageRoutes->isEmpty(), __s("The merged result from the $runtimeType.resolve does not include all required routes. Do you remember to merge all exiting routes?"));
        return true;
    }());
    return results;
}

template<typename T>
DefaultTransitionDelegateCls<T>::DefaultTransitionDelegateCls() : TransitionDelegate<T>() {
}

template<typename T>
Iterable<RouteTransitionRecord> DefaultTransitionDelegateCls<T>::resolve(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes) {
    List<RouteTransitionRecord> results = makeList();
    InlineMethod;
    handleExitingRoute(nullptr, newPageRouteHistory->isEmpty());
    for (RouteTransitionRecord pageRoute : newPageRouteHistory) {
        bool isLastIteration = newPageRouteHistory->last == pageRoute;
        if (pageRoute->isWaitingForEnteringDecision) {
            if (!locationToExitingPageRoute->containsKey(pageRoute) && isLastIteration) {
                pageRoute->markForPush();
            } else {
                pageRoute->markForAdd();
            }
        }
        results->add(pageRoute);
        handleExitingRoute(pageRoute, isLastIteration);
    }
    return results;
}

NavigatorCls::NavigatorCls(String initialRoute, Key key, List<NavigatorObserver> observers, RouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, PopPageCallback onPopPage, RouteFactory onUnknownRoute, List<Page<dynamic>> pages, bool reportsRouteUpdateToEngine, bool requestFocus, String restorationScopeId, TransitionDelegate<dynamic> transitionDelegate) {
    {
        assert(pages != nullptr);
        assert(onGenerateInitialRoutes != nullptr);
        assert(transitionDelegate != nullptr);
        assert(observers != nullptr);
        assert(reportsRouteUpdateToEngine != nullptr);
    }
}

template<typename T>
Future<T> NavigatorCls::pushNamed(BuildContext context, String routeName, Object arguments) {
    return NavigatorCls->of(context)-><T>pushNamed(routeName, arguments);
}

template<typename T>
String NavigatorCls::restorablePushNamed(BuildContext context, String routeName, Object arguments) {
    return NavigatorCls->of(context)-><T>restorablePushNamed(routeName, arguments);
}

template<typename T, typename TO>
Future<T> NavigatorCls::pushReplacementNamed(BuildContext context, String routeName, Object arguments, TO result) {
    return NavigatorCls->of(context)-><T, TO>pushReplacementNamed(routeName, arguments, result);
}

template<typename T, typename TO>
String NavigatorCls::restorablePushReplacementNamed(BuildContext context, String routeName, Object arguments, TO result) {
    return NavigatorCls->of(context)-><T, TO>restorablePushReplacementNamed(routeName, arguments, result);
}

template<typename T, typename TO>
Future<T> NavigatorCls::popAndPushNamed(BuildContext context, String routeName, Object arguments, TO result) {
    return NavigatorCls->of(context)-><T, TO>popAndPushNamed(routeName, arguments, result);
}

template<typename T, typename TO>
String NavigatorCls::restorablePopAndPushNamed(BuildContext context, String routeName, Object arguments, TO result) {
    return NavigatorCls->of(context)-><T, TO>restorablePopAndPushNamed(routeName, arguments, result);
}

template<typename T>
Future<T> NavigatorCls::pushNamedAndRemoveUntil(BuildContext context, String newRouteName, RoutePredicate predicate, Object arguments) {
    return NavigatorCls->of(context)-><T>pushNamedAndRemoveUntil(newRouteName, predicate, arguments);
}

template<typename T>
String NavigatorCls::restorablePushNamedAndRemoveUntil(BuildContext context, String newRouteName, RoutePredicate predicate, Object arguments) {
    return NavigatorCls->of(context)-><T>restorablePushNamedAndRemoveUntil(newRouteName, predicate, arguments);
}

template<typename T>
Future<T> NavigatorCls::push(BuildContext context, Route<T> route) {
    return NavigatorCls->of(context)->push(route);
}

template<typename T>
String NavigatorCls::restorablePush(BuildContext context, RestorableRouteBuilder<T> routeBuilder, Object arguments) {
    return NavigatorCls->of(context)->restorablePush(routeBuilder, arguments);
}

template<typename T, typename TO>
Future<T> NavigatorCls::pushReplacement(BuildContext context, Route<T> newRoute, TO result) {
    return NavigatorCls->of(context)-><T, TO>pushReplacement(newRoute, result);
}

template<typename T, typename TO>
String NavigatorCls::restorablePushReplacement(BuildContext context, RestorableRouteBuilder<T> routeBuilder, Object arguments, TO result) {
    return NavigatorCls->of(context)-><T, TO>restorablePushReplacement(routeBuilder, result, arguments);
}

template<typename T>
Future<T> NavigatorCls::pushAndRemoveUntil(BuildContext context, Route<T> newRoute, RoutePredicate predicate) {
    return NavigatorCls->of(context)-><T>pushAndRemoveUntil(newRoute, predicate);
}

template<typename T>
String NavigatorCls::restorablePushAndRemoveUntil(BuildContext context, RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate, Object arguments) {
    return NavigatorCls->of(context)-><T>restorablePushAndRemoveUntil(newRouteBuilder, predicate, arguments);
}

template<typename T>
void NavigatorCls::replace(BuildContext context, Route<T> newRoute, Route<dynamic> oldRoute) {
    return NavigatorCls->of(context)-><T>replace(oldRoute, newRoute);
}

template<typename T>
String NavigatorCls::restorableReplace(BuildContext context, Object arguments, RestorableRouteBuilder<T> newRouteBuilder, Route<dynamic> oldRoute) {
    return NavigatorCls->of(context)-><T>restorableReplace(oldRoute, newRouteBuilder, arguments);
}

template<typename T>
void NavigatorCls::replaceRouteBelow(BuildContext context, Route<dynamic> anchorRoute, Route<T> newRoute) {
    return NavigatorCls->of(context)-><T>replaceRouteBelow(anchorRoute, newRoute);
}

template<typename T>
String NavigatorCls::restorableReplaceRouteBelow(BuildContext context, Route<dynamic> anchorRoute, Object arguments, RestorableRouteBuilder<T> newRouteBuilder) {
    return NavigatorCls->of(context)-><T>restorableReplaceRouteBelow(anchorRoute, newRouteBuilder, arguments);
}

bool NavigatorCls::canPop(BuildContext context) {
    NavigatorState navigator = NavigatorCls->maybeOf(context);
    return navigator != nullptr && navigator->canPop();
}

template<typename T>
Future<bool> NavigatorCls::maybePop(BuildContext context, T result) {
    return NavigatorCls->of(context)-><T>maybePop(result);
}

template<typename T>
void NavigatorCls::pop(BuildContext context, T result) {
    NavigatorCls->of(context)-><T>pop(result);
}

void NavigatorCls::popUntil(BuildContext context, RoutePredicate predicate) {
    NavigatorCls->of(context)->popUntil(predicate);
}

void NavigatorCls::removeRoute(BuildContext context, Route<dynamic> route) {
    return NavigatorCls->of(context)->removeRoute(route);
}

void NavigatorCls::removeRouteBelow(BuildContext context, Route<dynamic> anchorRoute) {
    return NavigatorCls->of(context)->removeRouteBelow(anchorRoute);
}

NavigatorState NavigatorCls::of(BuildContext context, bool rootNavigator) {
    NavigatorState navigator;
    if (is<StatefulElement>(context) && is<NavigatorState>(context->state)) {
        navigator = as<NavigatorState>(context->state);
    }
    if (rootNavigator) {
        navigator = context-><NavigatorState>findRootAncestorStateOfType() | navigator;
    } else {
        navigator = navigator | context-><NavigatorState>findAncestorStateOfType();
    }
    assert([=] () {
        if (navigator == nullptr) {
            throw make<FlutterErrorCls>(__s("Navigator operation requested with a context that does not include a Navigator.\nThe context used to push or pop routes from the Navigator must be that of a widget that is a descendant of a Navigator widget."));
        }
        return true;
    }());
    return navigator!;
}

NavigatorState NavigatorCls::maybeOf(BuildContext context, bool rootNavigator) {
    NavigatorState navigator;
    if (is<StatefulElement>(context) && is<NavigatorState>(context->state)) {
        navigator = as<NavigatorState>(context->state);
    }
    if (rootNavigator) {
        navigator = context-><NavigatorState>findRootAncestorStateOfType() | navigator;
    } else {
        navigator = navigator | context-><NavigatorState>findAncestorStateOfType();
    }
    return navigator;
}

List<Route<dynamic>> NavigatorCls::defaultGenerateInitialRoutes(NavigatorState navigator, String initialRouteName) {
    List<Route<dynamic>> result = makeList();
    if (initialRouteName->startsWith(__s("/")) && initialRouteName->length() > 1) {
        initialRouteName = initialRouteName->substring(1);
        assert(NavigatorCls::defaultRouteName == __s("/"));
        List<String> debugRouteNames;
        assert([=] () {
            debugRouteNames = makeList(ArrayItem);
            return true;
        }());
        result->add(navigator-><dynamic>_routeNamed(NavigatorCls::defaultRouteName, nullptr, true));
        List<String> routeParts = initialRouteName->split(__s("/"));
        if (initialRouteName->isNotEmpty()) {
            String routeName = __s("");
            for (String part : routeParts) {
                routeName += __s("/$part");
                assert([=] () {
                    debugRouteNames!->add(routeName);
                    return true;
                }());
                result->add(navigator-><dynamic>_routeNamed(routeName, nullptr, true));
            }
        }
        if (result->last == nullptr) {
            assert([=] () {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(__s("Could not navigate to initial route.\nThe requested route name was: "/$initialRouteName"\nThere was no corresponding route in the app, and therefore the initial route specified will be ignored and "${Navigator.defaultRouteName}" will be used instead.")));
                return true;
            }());
            result->clear();
        }
    } else {
        if (initialRouteName != NavigatorCls::defaultRouteName) {
        result->add(navigator-><dynamic>_routeNamed(initialRouteName, nullptr, true));
    }
;
    }    result->removeWhere([=] (Route<dynamic> route) {
        route == nullptr;
    });
    if (result->isEmpty()) {
        result->add(navigator-><dynamic>_routeNamed(NavigatorCls::defaultRouteName, nullptr));
    }
    return result-><Route<dynamic>>cast();
}

NavigatorState NavigatorCls::createState() {
    return make<NavigatorStateCls>();
}

String _RouteEntryCls::restorationId() {
    if (hasPage()) {
        Page<Object> page = as<Page<Object>>(route->settings());
        return page->restorationId != nullptr? __s("p+${page.restorationId}") : nullptr;
    }
    if (restorationInformation != nullptr) {
        return __s("r+${restorationInformation!.restorationScopeId}");
    }
    return nullptr;
}

bool _RouteEntryCls::hasPage() {
    return is<Page<any>>(route->settings());
}

bool _RouteEntryCls::canUpdateFrom(Page<dynamic> page) {
    if (!willBePresent()) {
        return false;
    }
    if (!hasPage()) {
        return false;
    }
    Page<dynamic> routePage = as<Page<dynamic>>(route->settings());
    return page->canUpdate(routePage);
}

void _RouteEntryCls::handleAdd(NavigatorState navigator, Route<dynamic> previousPresent) {
    assert(currentState == _RouteLifecycleCls::add);
    assert(navigator != nullptr);
    assert(navigator->_debugLocked);
    assert(route->_navigator == nullptr);
    route->_navigator = navigator;
    route->install();
    assert(route->overlayEntries()->isNotEmpty());
    currentState = _RouteLifecycleCls::adding;
    navigator->_observedRouteAdditions->add(make<_NavigatorPushObservationCls>(route, previousPresent));
}

void _RouteEntryCls::handlePush(bool isNewFirst, NavigatorState navigator, Route<dynamic> previous, Route<dynamic> previousPresent) {
    assert(currentState == _RouteLifecycleCls::push || currentState == _RouteLifecycleCls::pushReplace || currentState == _RouteLifecycleCls::replace);
    assert(navigator != nullptr);
    assert(navigator->_debugLocked);
    assert(route->_navigator == nullptr, __s("The pushed route has already been used. When pushing a route, a new Route object must be provided."));
    _RouteLifecycle previousState = currentState;
    route->_navigator = navigator;
    route->install();
    assert(route->overlayEntries()->isNotEmpty());
    if (currentState == _RouteLifecycleCls::push || currentState == _RouteLifecycleCls::pushReplace) {
        TickerFuture routeFuture = route->didPush();
        currentState = _RouteLifecycleCls::pushing;
        routeFuture->whenCompleteOrCancel([=] () {
            if (currentState == _RouteLifecycleCls::pushing) {
                currentState = _RouteLifecycleCls::idle;
                assert(!navigator->_debugLocked);
                assert([=] () {
                    navigator->_debugLocked = true;
                    return true;
                }());
                navigator->_flushHistoryUpdates();
                assert([=] () {
                    navigator->_debugLocked = false;
                    return true;
                }());
            }
        });
    } else {
        assert(currentState == _RouteLifecycleCls::replace);
        route->didReplace(previous);
        currentState = _RouteLifecycleCls::idle;
    }
    if (isNewFirst) {
        route->didChangeNext(nullptr);
    }
    if (previousState == _RouteLifecycleCls::replace || previousState == _RouteLifecycleCls::pushReplace) {
        navigator->_observedRouteAdditions->add(make<_NavigatorReplaceObservationCls>(route, previousPresent));
    } else {
        assert(previousState == _RouteLifecycleCls::push);
        navigator->_observedRouteAdditions->add(make<_NavigatorPushObservationCls>(route, previousPresent));
    }
}

void _RouteEntryCls::handleDidPopNext(Route<dynamic> poppedRoute) {
    route->didPopNext(poppedRoute);
    lastAnnouncedPoppedNextRoute = poppedRoute;
}

bool _RouteEntryCls::handlePop(NavigatorState navigator, Route<dynamic> previousPresent) {
    assert(navigator != nullptr);
    assert(navigator->_debugLocked);
    assert(route->_navigator == navigator);
    currentState = _RouteLifecycleCls::popping;
    if (route->_popCompleter->isCompleted()) {
        assert(hasPage());
        assert(pendingResult == nullptr);
        return true;
    }
    if (!route->didPop(pendingResult)) {
        currentState = _RouteLifecycleCls::idle;
        return false;
    }
    pendingResult = nullptr;
    return true;
}

void _RouteEntryCls::handleComplete() {
    route->didComplete(pendingResult);
    pendingResult = nullptr;
    assert(route->_popCompleter->isCompleted());
    currentState = _RouteLifecycleCls::remove;
}

void _RouteEntryCls::handleRemoval(NavigatorState navigator, Route<dynamic> previousPresent) {
    assert(navigator != nullptr);
    assert(navigator->_debugLocked);
    assert(route->_navigator == navigator);
    currentState = _RouteLifecycleCls::removing;
    if (_reportRemovalToObserver) {
        navigator->_observedRouteDeletions->add(make<_NavigatorRemoveObservationCls>(route, previousPresent));
    }
}

void _RouteEntryCls::didAdd(bool isNewFirst, NavigatorState navigator) {
    route->didAdd();
    currentState = _RouteLifecycleCls::idle;
    if (isNewFirst) {
        route->didChangeNext(nullptr);
    }
}

template<typename T>
void _RouteEntryCls::pop(T result) {
    assert(isPresent());
    pendingResult = result;
    currentState = _RouteLifecycleCls::pop;
}

void _RouteEntryCls::remove(bool isReplaced) {
    assert(!hasPage() || isWaitingForExitingDecision(), __s("A page-based route cannot be completed using imperative api, provide a new list without the corresponding Page to Navigator.pages instead. "));
    if (currentState->index >= _RouteLifecycleCls::remove->index) {
        return;
    }
    assert(isPresent());
    _reportRemovalToObserver = !isReplaced;
    currentState = _RouteLifecycleCls::remove;
}

template<typename T>
void _RouteEntryCls::complete(T result, bool isReplaced) {
    assert(!hasPage() || isWaitingForExitingDecision(), __s("A page-based route cannot be completed using imperative api, provide a new list without the corresponding Page to Navigator.pages instead. "));
    if (currentState->index >= _RouteLifecycleCls::remove->index) {
        return;
    }
    assert(isPresent());
    _reportRemovalToObserver = !isReplaced;
    pendingResult = result;
    currentState = _RouteLifecycleCls::complete;
}

void _RouteEntryCls::finalize() {
    assert(currentState->index < _RouteLifecycleCls::dispose->index);
    currentState = _RouteLifecycleCls::dispose;
}

void _RouteEntryCls::dispose() {
    assert(currentState->index < _RouteLifecycleCls::disposed->index);
    currentState = _RouteLifecycleCls::disposed;
    Iterable<OverlayEntry> mountedEntries = route->overlayEntries()->where([=] (OverlayEntry e) {
    e->mounted;
});
    if (mountedEntries->isEmpty()) {
        route->dispose();
    } else {
        int mounted = mountedEntries->length();
        assert(mounted > 0);
        for (OverlayEntry entry : mountedEntries) {
            VoidCallback listener;
            listener = [=] () {
                assert(mounted > 0);
                assert(!entry->mounted);
                mounted--;
                entry->removeListener(listener);
                if (mounted == 0) {
                    assert(route->overlayEntries()->every([=] (OverlayEntry e) {
                        !e->mounted;
                    }));
                    route->dispose();
                }
            };
            entry->addListener(listener);
        }
    }
}

bool _RouteEntryCls::willBePresent() {
    return currentState->index <= _RouteLifecycleCls::idle->index && currentState->index >= _RouteLifecycleCls::add->index;
}

bool _RouteEntryCls::isPresent() {
    return currentState->index <= _RouteLifecycleCls::remove->index && currentState->index >= _RouteLifecycleCls::add->index;
}

bool _RouteEntryCls::isPresentForRestoration() {
    return currentState->index <= _RouteLifecycleCls::idle->index;
}

bool _RouteEntryCls::suitableForAnnouncement() {
    return currentState->index <= _RouteLifecycleCls::removing->index && currentState->index >= _RouteLifecycleCls::push->index;
}

bool _RouteEntryCls::suitableForTransitionAnimation() {
    return currentState->index <= _RouteLifecycleCls::remove->index && currentState->index >= _RouteLifecycleCls::push->index;
}

bool _RouteEntryCls::shouldAnnounceChangeToNext(Route<dynamic> nextRoute) {
    assert(nextRoute != lastAnnouncedNextRoute);
    return !(nextRoute == nullptr && lastAnnouncedPoppedNextRoute != nullptr && lastAnnouncedPoppedNextRoute == lastAnnouncedNextRoute);
}

bool _RouteEntryCls::isPresentPredicate(_RouteEntry entry) {
    return entry->isPresent();
}

bool _RouteEntryCls::suitableForTransitionAnimationPredicate(_RouteEntry entry) {
    return entry->suitableForTransitionAnimation();
}

bool _RouteEntryCls::willBePresentPredicate(_RouteEntry entry) {
    return entry->willBePresent();
}

_RouteEntryPredicate _RouteEntryCls::isRoutePredicate(Route<dynamic> route) {
    return [=] (_RouteEntry entry) {
        entry->route == route;
    };
}

bool _RouteEntryCls::isWaitingForEnteringDecision() {
    return currentState == _RouteLifecycleCls::staging;
}

bool _RouteEntryCls::isWaitingForExitingDecision() {
    return _isWaitingForExitingDecision;
}

void _RouteEntryCls::markNeedsExitingDecision() {
    return _isWaitingForExitingDecision = true;
}

void _RouteEntryCls::markForPush() {
    assert(isWaitingForEnteringDecision() && !isWaitingForExitingDecision(), __s("This route cannot be marked for push. Either a decision has already been made or it does not require an explicit decision on how to transition in."));
    currentState = _RouteLifecycleCls::push;
}

void _RouteEntryCls::markForAdd() {
    assert(isWaitingForEnteringDecision() && !isWaitingForExitingDecision(), __s("This route cannot be marked for add. Either a decision has already been made or it does not require an explicit decision on how to transition in."));
    currentState = _RouteLifecycleCls::add;
}

void _RouteEntryCls::markForPop(dynamic result) {
    assert(!isWaitingForEnteringDecision() && isWaitingForExitingDecision() && isPresent(), __s("This route cannot be marked for pop. Either a decision has already been made or it does not require an explicit decision on how to transition out."));
    <dynamic>pop(result);
    _isWaitingForExitingDecision = false;
}

void _RouteEntryCls::markForComplete(dynamic result) {
    assert(!isWaitingForEnteringDecision() && isWaitingForExitingDecision() && isPresent(), __s("This route cannot be marked for complete. Either a decision has already been made or it does not require an explicit decision on how to transition out."));
    <dynamic>complete(result);
    _isWaitingForExitingDecision = false;
}

void _RouteEntryCls::markForRemove() {
    assert(!isWaitingForEnteringDecision() && isWaitingForExitingDecision() && isPresent(), __s("This route cannot be marked for remove. Either a decision has already been made or it does not require an explicit decision on how to transition out."));
    remove();
    _isWaitingForExitingDecision = false;
}

bool _RouteEntryCls::restorationEnabled() {
    return route->restorationScopeId()->value() != nullptr;
}

void _RouteEntryCls::restorationEnabled(bool value) {
    assert(!value || restorationId() != nullptr);
    route->_updateRestorationId(value? restorationId() : nullptr);
}

_RouteEntryCls::_RouteEntryCls(Route<dynamic> route, _RouteLifecycle initialState, _RestorationInformation restorationInformation) {
    {
        assert(route != nullptr);
        assert(initialState != nullptr);
        assert(initialState == _RouteLifecycleCls::staging || initialState == _RouteLifecycleCls::add || initialState == _RouteLifecycleCls::push || initialState == _RouteLifecycleCls::pushReplace || initialState == _RouteLifecycleCls::replace);
        currentState = initialState;
    }
}

void _NavigatorPushObservationCls::notify(NavigatorObserver observer) {
    observer->didPush(primaryRoute, secondaryRoute);
}

void _NavigatorPopObservationCls::notify(NavigatorObserver observer) {
    observer->didPop(primaryRoute, secondaryRoute);
}

void _NavigatorRemoveObservationCls::notify(NavigatorObserver observer) {
    observer->didRemove(primaryRoute, secondaryRoute);
}

void _NavigatorReplaceObservationCls::notify(NavigatorObserver observer) {
    observer->didReplace(primaryRoute, secondaryRoute);
}

void NavigatorStateCls::initState() {
    super->initState();
    assert([=] () {
        if (widget()->pages != makeList()) {
            if (widget()->pages->isEmpty) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("The Navigator.pages must not be empty to use the Navigator.pages API")), __s("widget library"), StackTraceCls::current));
            } else {
                if (widget()->onPopPage == nullptr) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("The Navigator.onPopPage must be provided to use the Navigator.pages API")), __s("widget library"), StackTraceCls::current));
            }
;
            }        }
        return true;
    }());
    for (NavigatorObserver observer : widget()->observers) {
        assert(observer->navigator == nullptr);
        observer->_navigator = this;
    }
    _effectiveObservers = widget()->observers;
    HeroControllerScope heroControllerScope = as<HeroControllerScope>(context()-><HeroControllerScope>getElementForInheritedWidgetOfExactType()?->widget());
    _updateHeroController(heroControllerScope?->controller);
    if (widget()->reportsRouteUpdateToEngine) {
        SystemNavigatorCls->selectSingleEntryHistory();
    }
}

void NavigatorStateCls::restoreState(RestorationBucket oldBucket, bool initialRestore) {
    registerForRestoration(_rawNextPagelessRestorationScopeId, __s("id"));
    registerForRestoration(_serializableHistory, __s("history"));
    while (_history->isNotEmpty()) {
        _history->removeLast()->dispose();
    }
    assert(_history->isEmpty());
    _overlayKey = <OverlayState>make<GlobalKeyCls>();
    _history->addAll(_serializableHistory->restoreEntriesForPage(nullptr, this));
    for (Page<dynamic> page : widget()->pages) {
        _RouteEntry entry = make<_RouteEntryCls>(page->createRoute(context()), _RouteLifecycleCls::add);
        assert(entry->route->settings() == page, __s("The settings getter of a page-based Route must return a Page object. Please set the settings to the Page in the Page.createRoute method."));
        _history->add(entry);
        _history->addAll(_serializableHistory->restoreEntriesForPage(entry, this));
    }
    if (!_serializableHistory->hasData()) {
        String initialRoute = widget()->initialRoute;
        if (widget()->pages->isEmpty) {
            initialRoute = initialRoute | NavigatorCls::defaultRouteName;
        }
        if (initialRoute != nullptr) {
            _history->addAll(widget()->onGenerateInitialRoutes(this, widget()->initialRoute | NavigatorCls::defaultRouteName)->map([=] (Route<dynamic> route) {
                make<_RouteEntryCls>(route, _RouteLifecycleCls::add, route->settings->name != nullptr? _RestorationInformationCls->named(route->settings->name!, nullptr, _nextPagelessRestorationScopeId()) : nullptr);
            }));
        }
    }
    assert(_history->isNotEmpty(), __s("All routes returned by onGenerateInitialRoutes are not restorable. Please make sure that all routes returned by onGenerateInitialRoutes have their RouteSettings defined with names that are defined in the app's routes table."));
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
}

void NavigatorStateCls::didToggleBucket(RestorationBucket oldBucket) {
    super->didToggleBucket(oldBucket);
    if (bucket != nullptr) {
        _serializableHistory->update(_history);
    } else {
        _serializableHistory->clear();
    }
}

String NavigatorStateCls::restorationId() {
    return widget()->restorationScopeId;
}

void NavigatorStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _updateHeroController(HeroControllerScopeCls->of(context()));
    for (_RouteEntry entry : _history) {
        entry->route->changedExternalState();
    }
}

void NavigatorStateCls::didUpdateWidget(Navigator oldWidget) {
    super->didUpdateWidget(oldWidget);
    assert([=] () {
        if (widget()->pages != makeList()) {
            if (widget()->pages->isEmpty) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("The Navigator.pages must not be empty to use the Navigator.pages API")), __s("widget library"), StackTraceCls::current));
            } else {
                if (widget()->onPopPage == nullptr) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("The Navigator.onPopPage must be provided to use the Navigator.pages API")), __s("widget library"), StackTraceCls::current));
            }
;
            }        }
        return true;
    }());
    if (oldWidget->observers != widget()->observers) {
        for (NavigatorObserver observer : oldWidget->observers) {
            observer->_navigator = nullptr;
        }
        for (NavigatorObserver observer : widget()->observers) {
            assert(observer->navigator == nullptr);
            observer->_navigator = this;
        }
        _updateEffectiveObservers();
    }
    if (oldWidget->pages != widget()->pages && !restorePending) {
        assert([=] () {
            if (widget()->pages->isEmpty) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("The Navigator.pages must not be empty to use the Navigator.pages API")), __s("widget library"), StackTraceCls::current));
            }
            return true;
        }());
        _updatePages();
    }
    for (_RouteEntry entry : _history) {
        entry->route->changedExternalState();
    }
}

void NavigatorStateCls::deactivate() {
    for (NavigatorObserver observer : _effectiveObservers) {
        observer->_navigator = nullptr;
    }
    super->deactivate();
}

void NavigatorStateCls::activate() {
    super->activate();
    for (NavigatorObserver observer : _effectiveObservers) {
        assert(observer->navigator == nullptr);
        observer->_navigator = this;
    }
}

void NavigatorStateCls::dispose() {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert([=] () {
        for (NavigatorObserver observer : _effectiveObservers) {
            assert(observer->_navigator != this);
        }
        return true;
    }());
    _updateHeroController(nullptr);
    focusScopeNode->dispose();
    for (_RouteEntry entry : _history) {
        entry->dispose();
    }
    super->dispose();
    assert(_debugLocked);
}

OverlayState NavigatorStateCls::overlay() {
    return _overlayKey->currentState();
}

template<typename T>
Future<T> NavigatorStateCls::pushNamed(String routeName, Object arguments) {
    return <T>push(<T>_routeNamed(routeName, arguments)!);
}

template<typename T>
String NavigatorStateCls::restorablePushNamed(String routeName, Object arguments) {
    assert(routeName != nullptr);
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    _RouteEntry entry = _RestorationInformationCls->named(routeName, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::push);
    _pushEntry(entry);
    return entry->restorationId()!;
}

template<typename T, typename TO>
Future<T> NavigatorStateCls::pushReplacementNamed(String routeName, Object arguments, TO result) {
    return <T, TO>pushReplacement(<T>_routeNamed(routeName, arguments)!, result);
}

template<typename T, typename TO>
String NavigatorStateCls::restorablePushReplacementNamed(String routeName, Object arguments, TO result) {
    assert(routeName != nullptr);
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    _RouteEntry entry = _RestorationInformationCls->named(routeName, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::pushReplace);
    _pushReplacementEntry(entry, result);
    return entry->restorationId()!;
}

template<typename T, typename TO>
Future<T> NavigatorStateCls::popAndPushNamed(String routeName, Object arguments, TO result) {
    <TO>pop(result);
    return <T>pushNamed(routeName, arguments);
}

template<typename T, typename TO>
String NavigatorStateCls::restorablePopAndPushNamed(String routeName, Object arguments, TO result) {
    <TO>pop(result);
    return restorablePushNamed(routeName, arguments);
}

template<typename T>
Future<T> NavigatorStateCls::pushNamedAndRemoveUntil(String newRouteName, RoutePredicate predicate, Object arguments) {
    return <T>pushAndRemoveUntil(<T>_routeNamed(newRouteName, arguments)!, predicate);
}

template<typename T>
String NavigatorStateCls::restorablePushNamedAndRemoveUntil(String newRouteName, RoutePredicate predicate, Object arguments) {
    assert(newRouteName != nullptr);
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    _RouteEntry entry = _RestorationInformationCls->named(newRouteName, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::push);
    _pushEntryAndRemoveUntil(entry, predicate);
    return entry->restorationId()!;
}

template<typename T>
Future<T> NavigatorStateCls::push(Route<T> route) {
    assert(_debugCheckIsPagelessRoute(route));
    _pushEntry(make<_RouteEntryCls>(route, _RouteLifecycleCls::push));
    return route->popped();
}

template<typename T>
String NavigatorStateCls::restorablePush(RestorableRouteBuilder<T> routeBuilder, Object arguments) {
    assert(routeBuilder != nullptr);
    assert(_debugIsStaticCallback(routeBuilder), __s("The provided routeBuilder must be a static function."));
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    _RouteEntry entry = _RestorationInformationCls->anonymous(routeBuilder, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::push);
    _pushEntry(entry);
    return entry->restorationId()!;
}

template<typename T, typename TO>
Future<T> NavigatorStateCls::pushReplacement(Route<T> newRoute, TO result) {
    assert(newRoute != nullptr);
    assert(newRoute->_navigator == nullptr);
    assert(_debugCheckIsPagelessRoute(newRoute));
    _pushReplacementEntry(make<_RouteEntryCls>(newRoute, _RouteLifecycleCls::pushReplace), result);
    return newRoute->popped();
}

template<typename T, typename TO>
String NavigatorStateCls::restorablePushReplacement(RestorableRouteBuilder<T> routeBuilder, Object arguments, TO result) {
    assert(routeBuilder != nullptr);
    assert(_debugIsStaticCallback(routeBuilder), __s("The provided routeBuilder must be a static function."));
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    _RouteEntry entry = _RestorationInformationCls->anonymous(routeBuilder, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::pushReplace);
    _pushReplacementEntry(entry, result);
    return entry->restorationId()!;
}

template<typename T>
Future<T> NavigatorStateCls::pushAndRemoveUntil(Route<T> newRoute, RoutePredicate predicate) {
    assert(newRoute != nullptr);
    assert(newRoute->_navigator == nullptr);
    assert(newRoute->overlayEntries()->isEmpty());
    assert(_debugCheckIsPagelessRoute(newRoute));
    _pushEntryAndRemoveUntil(make<_RouteEntryCls>(newRoute, _RouteLifecycleCls::push), predicate);
    return newRoute->popped();
}

template<typename T>
String NavigatorStateCls::restorablePushAndRemoveUntil(RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate, Object arguments) {
    assert(newRouteBuilder != nullptr);
    assert(_debugIsStaticCallback(newRouteBuilder), __s("The provided routeBuilder must be a static function."));
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    _RouteEntry entry = _RestorationInformationCls->anonymous(newRouteBuilder, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::push);
    _pushEntryAndRemoveUntil(entry, predicate);
    return entry->restorationId()!;
}

template<typename T>
void NavigatorStateCls::replace(Route<T> newRoute, Route<dynamic> oldRoute) {
    assert(!_debugLocked);
    assert(oldRoute != nullptr);
    assert(oldRoute->_navigator == this);
    assert(newRoute != nullptr);
    _replaceEntry(make<_RouteEntryCls>(newRoute, _RouteLifecycleCls::replace), oldRoute);
}

template<typename T>
String NavigatorStateCls::restorableReplace(Object arguments, RestorableRouteBuilder<T> newRouteBuilder, Route<dynamic> oldRoute) {
    assert(oldRoute != nullptr);
    assert(oldRoute->_navigator == this);
    assert(newRouteBuilder != nullptr);
    assert(_debugIsStaticCallback(newRouteBuilder), __s("The provided routeBuilder must be a static function."));
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    assert(oldRoute != nullptr);
    _RouteEntry entry = _RestorationInformationCls->anonymous(newRouteBuilder, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::replace);
    _replaceEntry(entry, oldRoute);
    return entry->restorationId()!;
}

template<typename T>
void NavigatorStateCls::replaceRouteBelow(Route<dynamic> anchorRoute, Route<T> newRoute) {
    assert(newRoute != nullptr);
    assert(newRoute->_navigator == nullptr);
    assert(anchorRoute != nullptr);
    assert(anchorRoute->_navigator == this);
    _replaceEntryBelow(make<_RouteEntryCls>(newRoute, _RouteLifecycleCls::replace), anchorRoute);
}

template<typename T>
String NavigatorStateCls::restorableReplaceRouteBelow(Route<dynamic> anchorRoute, Object arguments, RestorableRouteBuilder<T> newRouteBuilder) {
    assert(anchorRoute != nullptr);
    assert(anchorRoute->_navigator == this);
    assert(newRouteBuilder != nullptr);
    assert(_debugIsStaticCallback(newRouteBuilder), __s("The provided routeBuilder must be a static function."));
    assert(debugIsSerializableForRestoration(arguments), __s("The arguments object must be serializable via the StandardMessageCodec."));
    assert(anchorRoute != nullptr);
    _RouteEntry entry = _RestorationInformationCls->anonymous(newRouteBuilder, arguments, _nextPagelessRestorationScopeId())->toRouteEntry(this, _RouteLifecycleCls::replace);
    _replaceEntryBelow(entry, anchorRoute);
    return entry->restorationId()!;
}

bool NavigatorStateCls::canPop() {
    Iterator<_RouteEntry> iterator = _history->where(_RouteEntryCls::isPresentPredicate)->iterator;
    if (!iterator->moveNext()) {
        return false;
    }
    if (iterator->current()->route->willHandlePopInternally) {
        return true;
    }
    if (!iterator->moveNext()) {
        return false;
    }
    return true;
}

template<typename T>
Future<bool> NavigatorStateCls::maybePop(T result) {
    _RouteEntry lastEntry = _history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
    e != nullptr && _RouteEntryCls->isPresentPredicate(e);
}, [=] () {
    nullptr;
});
    if (lastEntry == nullptr) {
        return false;
    }
    assert(lastEntry->route->_navigator == this);
    RoutePopDisposition disposition = await lastEntry->route->willPop();
    assert(disposition != nullptr);
    if (!mounted()) {
        return true;
    }
    _RouteEntry newLastEntry = _history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
    e != nullptr && _RouteEntryCls->isPresentPredicate(e);
}, [=] () {
    nullptr;
});
    if (lastEntry != newLastEntry) {
        return true;
    }
    ;
}

template<typename T>
void NavigatorStateCls::pop(T result) {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    _RouteEntry entry = _history->lastWhere(_RouteEntryCls::isPresentPredicate);
    if (entry->hasPage()) {
        if (widget()->onPopPage!(entry->route, result) && entry->currentState == _RouteLifecycleCls::idle) {
            assert(entry->route->_popCompleter->isCompleted());
            entry->currentState = _RouteLifecycleCls::pop;
        }
    } else {
        entry-><T>pop(result);
        assert(entry->currentState == _RouteLifecycleCls::pop);
    }
    if (entry->currentState == _RouteLifecycleCls::pop) {
        _flushHistoryUpdates(false);
    }
    assert(entry->currentState == _RouteLifecycleCls::idle || entry->route->_popCompleter->isCompleted());
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
    _afterNavigation(entry->route);
}

void NavigatorStateCls::popUntil(RoutePredicate predicate) {
    _RouteEntry candidate = _history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
    e != nullptr && _RouteEntryCls->isPresentPredicate(e);
}, [=] () {
    nullptr;
});
    while (candidate != nullptr) {
        if (predicate(candidate->route)) {
            return;
        }
        pop();
        candidate = _history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
            e != nullptr && _RouteEntryCls->isPresentPredicate(e);
        }, [=] () {
            nullptr;
        });
    }
}

void NavigatorStateCls::removeRoute(Route<dynamic> route) {
    assert(route != nullptr);
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert(route->_navigator == this);
    bool wasCurrent = route->isCurrent();
    _RouteEntry entry = _history->firstWhere(_RouteEntryCls->isRoutePredicate(route));
    assert(entry != nullptr);
    entry->remove();
    _flushHistoryUpdates(false);
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
    if (wasCurrent) {
        _afterNavigation(_history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
            e != nullptr && _RouteEntryCls->isPresentPredicate(e);
        }, [=] () {
            nullptr;
        })?->route);
    }
}

void NavigatorStateCls::removeRouteBelow(Route<dynamic> anchorRoute) {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert(anchorRoute != nullptr);
    assert(anchorRoute->_navigator == this);
    int anchorIndex = _history->indexWhere(_RouteEntryCls->isRoutePredicate(anchorRoute));
    assert(anchorIndex >= 0, __s("This Navigator does not contain the specified anchorRoute."));
    assert(_history[anchorIndex]->isPresent(), __s("The specified anchorRoute has already been removed from the Navigator."));
    int index = anchorIndex - 1;
    while (index >= 0) {
        if (_history[index]->isPresent()) {
            break;
        }
        index -= 1;
    }
    assert(index >= 0, __s("There are no routes below the specified anchorRoute."));
    _history[index]->remove();
    _flushHistoryUpdates(false);
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
}

void NavigatorStateCls::finalizeRoute(Route<dynamic> route) {
    bool wasDebugLocked;
    assert([=] () {
        wasDebugLocked = _debugLocked;
        _debugLocked = true;
        return true;
    }());
    assert(_history->where(_RouteEntryCls->isRoutePredicate(route))->length == 1);
    int index = _history->indexWhere(_RouteEntryCls->isRoutePredicate(route));
    _RouteEntry entry = _history[index];
    if (entry->hasPage() && entry->currentState->index < _RouteLifecycleCls::pop->index) {
        _observedRouteDeletions->add(make<_NavigatorPopObservationCls>(route, _getRouteBefore(index - 1, _RouteEntryCls::willBePresentPredicate)?->route));
    } else {
        assert(entry->currentState == _RouteLifecycleCls::popping);
    }
    entry->finalize();
    if (!_flushingHistory) {
        _flushHistoryUpdates(false);
    }
    assert([=] () {
        _debugLocked = wasDebugLocked!;
        return true;
    }());
}

bool NavigatorStateCls::userGestureInProgress() {
    return userGestureInProgressNotifier->value();
}

void NavigatorStateCls::didStartUserGesture() {
    _userGesturesInProgress() += 1;
    if (_userGesturesInProgress() == 1) {
        int routeIndex = _getIndexBefore(_history->length() - 1, _RouteEntryCls::willBePresentPredicate);
        assert(routeIndex != nullptr);
        Route<dynamic> route = _history[routeIndex]->route;
        Route<dynamic> previousRoute;
        if (!route->willHandlePopInternally() && routeIndex > 0) {
            previousRoute = _getRouteBefore(routeIndex - 1, _RouteEntryCls::willBePresentPredicate)!->route;
        }
        for (NavigatorObserver observer : _effectiveObservers) {
            observer->didStartUserGesture(route, previousRoute);
        }
    }
}

void NavigatorStateCls::didStopUserGesture() {
    assert(_userGesturesInProgress() > 0);
    _userGesturesInProgress() -= 1;
    if (_userGesturesInProgress() == 0) {
        for (NavigatorObserver observer : _effectiveObservers) {
            observer->didStopUserGesture();
        }
    }
}

Widget NavigatorStateCls::build(BuildContext context) {
    assert(!_debugLocked);
    assert(_history->isNotEmpty());
    return HeroControllerScopeCls->none(make<ListenerCls>(_handlePointerDown, _handlePointerUpOrCancel, _handlePointerUpOrCancel, make<AbsorbPointerCls>(false, make<FocusScopeCls>(focusScopeNode, true, make<UnmanagedRestorationScopeCls>(bucket, make<OverlayCls>(_overlayKey, overlay() == nullptr? _allRouteOverlayEntries()->toList(false) : makeList()))))));
}

int NavigatorStateCls::_nextPagelessRestorationScopeId() {
    return _rawNextPagelessRestorationScopeId->value++;
}

void NavigatorStateCls::_updateHeroController(HeroController newHeroController) {
    if (_heroControllerFromScope != newHeroController) {
        if (newHeroController != nullptr) {
            assert([=] () {
                if (newHeroController->navigator() != nullptr) {
                    NavigatorState previousOwner = newHeroController->navigator()!;
                    ServicesBindingCls::instance->addPostFrameCallback([=] (Duration timestamp) {
                        if (_heroControllerFromScope == newHeroController) {
                            bool hasHeroControllerOwnerShip = _heroControllerFromScope!->_navigator == this;
                            if (!hasHeroControllerOwnerShip || previousOwner->_heroControllerFromScope == newHeroController) {
                                NavigatorState otherOwner = hasHeroControllerOwnerShip? previousOwner : _heroControllerFromScope!->_navigator!;
                                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("A HeroController can not be shared by multiple Navigators. The Navigators that share the same HeroController are:\n- $this\n- $otherOwner\nPlease create a HeroControllerScope for each Navigator or use a HeroControllerScope.none to prevent subtree from receiving a HeroController.")), __s("widget library"), StackTraceCls::current));
                            }
                        }
                    });
                }
                return true;
            }());
            newHeroController->_navigator = this;
        }
        if (_heroControllerFromScope?->_navigator == this) {
            _heroControllerFromScope?->_navigator = nullptr;
        }
        _heroControllerFromScope = newHeroController;
        _updateEffectiveObservers();
    }
}

void NavigatorStateCls::_updateEffectiveObservers() {
    if (_heroControllerFromScope != nullptr) {
        _effectiveObservers = widget()->observers + makeList(ArrayItem);
    } else {
        _effectiveObservers = widget()->observers;
    }
}

void NavigatorStateCls::_debugCheckDuplicatedPageKeys() {
    assert([=] () {
        Set<Key> keyReservation = makeSet();
        for (Page<dynamic> page : widget()->pages) {
            LocalKey key = page->key;
            if (key != nullptr) {
                assert(!keyReservation->contains(key));
                keyReservation->add(key);
            }
        }
        return true;
    }());
}

Iterable<OverlayEntry> NavigatorStateCls::_allRouteOverlayEntries() {
    List<OverlayEntry> list1 = make<ListCls<>>();for (_RouteEntry entry : _history) {        ;    }{    list1.add(ArrayItem);}return list1;
}

void NavigatorStateCls::_updatePages() {
    assert([=] () {
        assert(!_debugUpdatingPage);
        _debugCheckDuplicatedPageKeys();
        _debugUpdatingPage = true;
        return true;
    }());
    bool needsExplicitDecision = false;
    int newPagesBottom = 0;
    int oldEntriesBottom = 0;
    int newPagesTop = widget()->pages->length - 1;
    int oldEntriesTop = _history->length() - 1;
    List<_RouteEntry> newHistory = makeList();
    Map<_RouteEntry, List<_RouteEntry>> pageRouteToPagelessRoutes = makeMap(makeList(), makeList();
    _RouteEntry previousOldPageRouteEntry;
    while (oldEntriesBottom <= oldEntriesTop) {
        _RouteEntry oldEntry = _history[oldEntriesBottom];
        assert(oldEntry != nullptr && oldEntry->currentState != _RouteLifecycleCls::disposed);
        if (!oldEntry->hasPage()) {
            List<_RouteEntry> pagelessRoutes = pageRouteToPagelessRoutes->putIfAbsent(previousOldPageRouteEntry, [=] () {
    makeList();
});
            pagelessRoutes->add(oldEntry);
            oldEntriesBottom += 1;
            continue;
        }
        if (newPagesBottom > newPagesTop) {
            break;
        }
        Page<dynamic> newPage = widget()->pages[newPagesBottom];
        if (!oldEntry->canUpdateFrom(newPage)) {
            break;
        }
        previousOldPageRouteEntry = oldEntry;
        oldEntry->route->_updateSettings(newPage);
        newHistory->add(oldEntry);
        newPagesBottom += 1;
        oldEntriesBottom += 1;
    }
    int pagelessRoutesToSkip = 0;
    while ((oldEntriesBottom <= oldEntriesTop) && (newPagesBottom <= newPagesTop)) {
        _RouteEntry oldEntry = _history[oldEntriesTop];
        assert(oldEntry != nullptr && oldEntry->currentState != _RouteLifecycleCls::disposed);
        if (!oldEntry->hasPage()) {
            pagelessRoutesToSkip += 1;
            oldEntriesTop -= 1;
            continue;
        }
        Page<dynamic> newPage = widget()->pages[newPagesTop];
        if (!oldEntry->canUpdateFrom(newPage)) {
            break;
        }
        pagelessRoutesToSkip = 0;
        oldEntriesTop -= 1;
        newPagesTop -= 1;
    }
    oldEntriesTop += pagelessRoutesToSkip;
    int oldEntriesBottomToScan = oldEntriesBottom;
    Map<LocalKey, _RouteEntry> pageKeyToOldEntry = makeMap(makeList(), makeList();
    Set<_RouteEntry> phantomEntries = makeSet();
    while (oldEntriesBottomToScan <= oldEntriesTop) {
        _RouteEntry oldEntry = _history[oldEntriesBottomToScan];
        oldEntriesBottomToScan += 1;
        assert(oldEntry != nullptr && oldEntry->currentState != _RouteLifecycleCls::disposed);
        if (!oldEntry->hasPage()) {
            continue;
        }
        assert(oldEntry->hasPage());
        Page<dynamic> page = as<Page<dynamic>>(oldEntry->route->settings());
        if (page->key == nullptr) {
            continue;
        }
        if (!oldEntry->willBePresent()) {
            phantomEntries->add(oldEntry);
            continue;
        }
        assert(!pageKeyToOldEntry->containsKey(page->key));
        pageKeyToOldEntry[page->key!] = oldEntry;
    }
    while (newPagesBottom <= newPagesTop) {
        Page<dynamic> nextPage = widget()->pages[newPagesBottom];
        newPagesBottom += 1;
        if (nextPage->key == nullptr || !pageKeyToOldEntry->containsKey(nextPage->key) || !pageKeyToOldEntry[nextPage->key]!->canUpdateFrom(nextPage)) {
            _RouteEntry newEntry = make<_RouteEntryCls>(nextPage->createRoute(context()), _RouteLifecycleCls::staging);
            needsExplicitDecision = true;
            assert(newEntry->route->settings() == nextPage, __s("The settings getter of a page-based Route must return a Page object. Please set the settings to the Page in the Page.createRoute method."));
            newHistory->add(newEntry);
        } else {
            _RouteEntry matchingEntry = pageKeyToOldEntry->remove(nextPage->key)!;
            assert(matchingEntry->canUpdateFrom(nextPage));
            matchingEntry->route->_updateSettings(nextPage);
            newHistory->add(matchingEntry);
        }
    }
    Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute = makeMap(makeList(), makeList();
    while (oldEntriesBottom <= oldEntriesTop) {
        _RouteEntry potentialEntryToRemove = _history[oldEntriesBottom];
        oldEntriesBottom += 1;
        if (!potentialEntryToRemove->hasPage()) {
            assert(previousOldPageRouteEntry != nullptr);
            List<_RouteEntry> pagelessRoutes = pageRouteToPagelessRoutes->putIfAbsent(previousOldPageRouteEntry, [=] () {
    makeList();
});
            pagelessRoutes->add(potentialEntryToRemove);
            if (previousOldPageRouteEntry!->isWaitingForExitingDecision() && potentialEntryToRemove->willBePresent()) {
                potentialEntryToRemove->markNeedsExitingDecision();
            }
            continue;
        }
        Page<dynamic> potentialPageToRemove = as<Page<dynamic>>(potentialEntryToRemove->route->settings());
        if (potentialPageToRemove->key == nullptr || pageKeyToOldEntry->containsKey(potentialPageToRemove->key) || phantomEntries->contains(potentialEntryToRemove)) {
            locationToExitingPageRoute[previousOldPageRouteEntry] = potentialEntryToRemove;
            if (potentialEntryToRemove->willBePresent()) {
                potentialEntryToRemove->markNeedsExitingDecision();
            }
        }
        previousOldPageRouteEntry = potentialEntryToRemove;
    }
    assert(oldEntriesBottom == oldEntriesTop + 1);
    assert(newPagesBottom == newPagesTop + 1);
    newPagesTop = widget()->pages->length - 1;
    oldEntriesTop = _history->length() - 1;
    assert([=] () {
        if (oldEntriesBottom <= oldEntriesTop) {
            return newPagesBottom <= newPagesTop && _history[oldEntriesBottom]->hasPage() && _history[oldEntriesBottom]->canUpdateFrom(widget()->pages[newPagesBottom]);
        } else {
            return newPagesBottom > newPagesTop;
        }
    }());
    while ((oldEntriesBottom <= oldEntriesTop) && (newPagesBottom <= newPagesTop)) {
        _RouteEntry oldEntry = _history[oldEntriesBottom];
        assert(oldEntry != nullptr && oldEntry->currentState != _RouteLifecycleCls::disposed);
        if (!oldEntry->hasPage()) {
            assert(previousOldPageRouteEntry != nullptr);
            List<_RouteEntry> pagelessRoutes = pageRouteToPagelessRoutes->putIfAbsent(previousOldPageRouteEntry, [=] () {
    makeList();
});
            pagelessRoutes->add(oldEntry);
            continue;
        }
        previousOldPageRouteEntry = oldEntry;
        Page<dynamic> newPage = widget()->pages[newPagesBottom];
        assert(oldEntry->canUpdateFrom(newPage));
        oldEntry->route->_updateSettings(newPage);
        newHistory->add(oldEntry);
        oldEntriesBottom += 1;
        newPagesBottom += 1;
    }
    needsExplicitDecision = needsExplicitDecision || locationToExitingPageRoute->isNotEmpty();
    Iterable<_RouteEntry> results = newHistory;
    if (needsExplicitDecision) {
        results = widget()->transitionDelegate->_transition(newHistory, locationToExitingPageRoute, pageRouteToPagelessRoutes)-><_RouteEntry>cast();
    }
    _history = makeList();
    if (pageRouteToPagelessRoutes->containsKey(nullptr)) {
        _history->addAll(pageRouteToPagelessRoutes[nullptr]!);
    }
    for (_RouteEntry result : results) {
        _history->add(result);
        if (pageRouteToPagelessRoutes->containsKey(result)) {
            _history->addAll(pageRouteToPagelessRoutes[result]!);
        }
    }
    assert([=] () {
        _debugUpdatingPage = false;
        return true;
    }());
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
}

void NavigatorStateCls::_flushHistoryUpdates(bool rearrangeOverlay) {
    assert(_debugLocked && !_debugUpdatingPage);
    _flushingHistory = true;
    int index = _history->length() - 1;
    _RouteEntry next;
    _RouteEntry entry = _history[index];
    _RouteEntry previous = index > 0? _history[index - 1] : nullptr;
    bool canRemoveOrAdd = false;
    Route<dynamic> poppedRoute;
    bool seenTopActiveRoute = false;
    List<_RouteEntry> toBeDisposed = makeList();
    while (index >= 0) {
        ;
        index -= 1;
        next = entry;
        entry = previous;
        previous = index > 0? _history[index - 1] : nullptr;
    }
    _flushObserverNotifications();
    _flushRouteAnnouncement();
    if (widget()->reportsRouteUpdateToEngine) {
        _RouteEntry lastEntry = _history-><_RouteEntry>cast()->lastWhere([=] (_RouteEntry e) {
    e != nullptr && _RouteEntryCls->isPresentPredicate(e);
}, [=] () {
    nullptr;
});
        String routeName = lastEntry?->route->settings()->name;
        if (routeName != nullptr && routeName != _lastAnnouncedRouteName) {
            SystemNavigatorCls->routeInformationUpdated(routeName);
            _lastAnnouncedRouteName = routeName;
        }
    }
    for (_RouteEntry entry : toBeDisposed) {
        for (OverlayEntry overlayEntry : entry->route->overlayEntries()) {
            overlayEntry->remove();
        }
        entry->dispose();
    }
    if (rearrangeOverlay) {
        overlay()?->rearrange(_allRouteOverlayEntries());
    }
    if (bucket != nullptr) {
        _serializableHistory->update(_history);
    }
    _flushingHistory = false;
}

void NavigatorStateCls::_flushObserverNotifications() {
    if (_effectiveObservers->isEmpty()) {
        _observedRouteDeletions->clear();
        _observedRouteAdditions->clear();
        return;
    }
    while (_observedRouteAdditions->isNotEmpty()) {
        _NavigatorObservation observation = _observedRouteAdditions->removeLast();
        _effectiveObservers->forEach(observation->notify);
    }
    while (_observedRouteDeletions->isNotEmpty()) {
        _NavigatorObservation observation = _observedRouteDeletions->removeFirst();
        _effectiveObservers->forEach(observation->notify);
    }
}

void NavigatorStateCls::_flushRouteAnnouncement() {
    int index = _history->length() - 1;
    while (index >= 0) {
        _RouteEntry entry = _history[index];
        if (!entry->suitableForAnnouncement()) {
            index -= 1;
            continue;
        }
        _RouteEntry next = _getRouteAfter(index + 1, _RouteEntryCls::suitableForTransitionAnimationPredicate);
        if (next?->route != entry->lastAnnouncedNextRoute) {
            if (entry->shouldAnnounceChangeToNext(next?->route)) {
                entry->route->didChangeNext(next?->route);
            }
            entry->lastAnnouncedNextRoute = next?->route;
        }
        _RouteEntry previous = _getRouteBefore(index - 1, _RouteEntryCls::suitableForTransitionAnimationPredicate);
        if (previous?->route != entry->lastAnnouncedPreviousRoute) {
            entry->route->didChangePrevious(previous?->route);
            entry->lastAnnouncedPreviousRoute = previous?->route;
        }
        index -= 1;
    }
}

_RouteEntry NavigatorStateCls::_getRouteBefore(int index, _RouteEntryPredicate predicate) {
    index = _getIndexBefore(index, predicate);
    return index >= 0? _history[index] : nullptr;
}

int NavigatorStateCls::_getIndexBefore(int index, _RouteEntryPredicate predicate) {
    while (index >= 0 && !predicate(_history[index])) {
        index -= 1;
    }
    return index;
}

_RouteEntry NavigatorStateCls::_getRouteAfter(int index, _RouteEntryPredicate predicate) {
    while ( < _history->length() && !predicate(_history[index])) {
        index += 1;
    }
    return  < _history->length()? _history[index] : nullptr;
}

template<typename T>
Route<T> NavigatorStateCls::_routeNamed(String name, bool allowNull, Object arguments) {
    assert(!_debugLocked);
    assert(name != nullptr);
    if (allowNull && widget()->onGenerateRoute == nullptr) {
        return nullptr;
    }
    assert([=] () {
        if (widget()->onGenerateRoute == nullptr) {
            throw make<FlutterErrorCls>(__s("Navigator.onGenerateRoute was null, but the route named "$name" was referenced.\nTo use the Navigator API with named routes (pushNamed, pushReplacementNamed, or pushNamedAndRemoveUntil), the Navigator must be provided with an onGenerateRoute handler.\nThe Navigator was:\n  $this"));
        }
        return true;
    }());
    RouteSettings settings = make<RouteSettingsCls>(name, arguments);
    Route<T> route = as<Route<T>>(widget()->onGenerateRoute!(settings));
    if (route == nullptr && !allowNull) {
        assert([=] () {
            if (widget()->onUnknownRoute == nullptr) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
            }
            return true;
        }());
        route = as<Route<T>>(widget()->onUnknownRoute!(settings));
        assert([=] () {
            if (route == nullptr) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
            }
            return true;
        }());
    }
    assert(route != nullptr || allowNull);
    return route;
}

bool NavigatorStateCls::_debugCheckIsPagelessRoute(Route<dynamic> route) {
    assert([=] () {
        if (is<Page<any>>(route->settings())) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(make<FlutterErrorCls>(__s("A page-based route should not be added using the imperative api. Provide a new list with the corresponding Page to Navigator.pages instead.")), __s("widget library"), StackTraceCls::current));
        }
        return true;
    }());
    return true;
}

bool NavigatorStateCls::_debugIsStaticCallback(std::function<void ()> callback) {
    bool result = false;
    assert([=] () {
        result = kIsWeb || ui->PluginUtilitiesCls->getCallbackHandle(callback) != nullptr;
        return true;
    }());
    return result;
}

void NavigatorStateCls::_pushEntry(_RouteEntry entry) {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert(entry->route != nullptr);
    assert(entry->route->_navigator == nullptr);
    assert(entry->currentState == _RouteLifecycleCls::push);
    _history->add(entry);
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
    _afterNavigation(entry->route);
}

void NavigatorStateCls::_afterNavigation(Route<dynamic> route) {
    if (!kReleaseMode) {
        Map<String, dynamic> routeJsonable;
        if (route != nullptr) {
            routeJsonable = makeMap(makeList(), makeList();
            String description;
            if (is<TransitionRoute<dynamic>>(route)) {
                TransitionRoute<dynamic> transitionRoute = as<TransitionRouteCls>(route);
                description = transitionRoute->debugLabel();
            } else {
                description = __s("$route");
            }
            routeJsonable[__s("description")] = description;
            RouteSettings settings = route->settings();
                    Map<String, dynamic> map1 = make<MapCls<>>();        map1.set(__s("name"), settings->name);Map<String, dynamic> settingsJsonable = list1;
            if (settings->arguments != nullptr) {
                settingsJsonable[__s("arguments")] = jsonEncode(settings->arguments, [=] (Object object) {
                    __s("$object");
                });
            }
            routeJsonable[__s("settings")] = settingsJsonable;
        }
            Map<String, dynamic> map2 = make<MapCls<>>();    map2.set(__s("route"), routeJsonable);developer->postEvent(__s("Flutter.Navigation"), list2);
    }
    _cancelActivePointers();
}

template<typename TO>
void NavigatorStateCls::_pushReplacementEntry(_RouteEntry entry, TO result) {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert(entry->route != nullptr);
    assert(entry->route->_navigator == nullptr);
    assert(_history->isNotEmpty());
    assert(_history->any(_RouteEntryCls::isPresentPredicate), __s("Navigator has no active routes to replace."));
    assert(entry->currentState == _RouteLifecycleCls::pushReplace);
    _history->lastWhere(_RouteEntryCls::isPresentPredicate)->complete(result, true);
    _history->add(entry);
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
    _afterNavigation(entry->route);
}

void NavigatorStateCls::_pushEntryAndRemoveUntil(_RouteEntry entry, RoutePredicate predicate) {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert(entry->route != nullptr);
    assert(entry->route->_navigator == nullptr);
    assert(entry->route->overlayEntries()->isEmpty());
    assert(predicate != nullptr);
    assert(entry->currentState == _RouteLifecycleCls::push);
    int index = _history->length() - 1;
    _history->add(entry);
    while (index >= 0 && !predicate(_history[index]->route)) {
        if (_history[index]->isPresent()) {
            _history[index]->remove();
        }
        index -= 1;
    }
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
    _afterNavigation(entry->route);
}

void NavigatorStateCls::_replaceEntry(_RouteEntry entry, Route<dynamic> oldRoute) {
    assert(!_debugLocked);
    if (oldRoute == entry->route) {
        return;
    }
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    assert(entry->currentState == _RouteLifecycleCls::replace);
    assert(entry->route->_navigator == nullptr);
    int index = _history->indexWhere(_RouteEntryCls->isRoutePredicate(oldRoute));
    assert(index >= 0, __s("This Navigator does not contain the specified oldRoute."));
    assert(_history[index]->isPresent(), __s("The specified oldRoute has already been removed from the Navigator."));
    bool wasCurrent = oldRoute->isCurrent();
    _history->insert(index + 1, entry);
    _history[index]->remove(true);
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
    if (wasCurrent) {
        _afterNavigation(entry->route);
    }
}

void NavigatorStateCls::_replaceEntryBelow(_RouteEntry entry, Route<dynamic> anchorRoute) {
    assert(!_debugLocked);
    assert([=] () {
        _debugLocked = true;
        return true;
    }());
    int anchorIndex = _history->indexWhere(_RouteEntryCls->isRoutePredicate(anchorRoute));
    assert(anchorIndex >= 0, __s("This Navigator does not contain the specified anchorRoute."));
    assert(_history[anchorIndex]->isPresent(), __s("The specified anchorRoute has already been removed from the Navigator."));
    int index = anchorIndex - 1;
    while (index >= 0) {
        if (_history[index]->isPresent()) {
            break;
        }
        index -= 1;
    }
    assert(index >= 0, __s("There are no routes below the specified anchorRoute."));
    _history->insert(index + 1, entry);
    _history[index]->remove(true);
    _flushHistoryUpdates();
    assert([=] () {
        _debugLocked = false;
        return true;
    }());
}

template<typename T>
Route<T> NavigatorStateCls::_getRouteById(String id) {
    assert(id != nullptr);
    return as<Route<T>>(_history-><_RouteEntry>cast()->firstWhere([=] (_RouteEntry entry) {
        entry!->restorationId == id;
    }, [=] () {
        nullptr;
    })?->route);
}

int NavigatorStateCls::_userGesturesInProgress() {
    return _userGesturesInProgressCount;
}

void NavigatorStateCls::_userGesturesInProgress(int value) {
    _userGesturesInProgressCount = value;
    userGestureInProgressNotifier->value = _userGesturesInProgress() > 0;
}

void NavigatorStateCls::_handlePointerDown(PointerDownEvent event) {
    _activePointers->add(event->pointer);
}

void NavigatorStateCls::_handlePointerUpOrCancel(PointerEvent event) {
    _activePointers->remove(event->pointer);
}

void NavigatorStateCls::_cancelActivePointers() {
    if (SchedulerBindingCls::instance->schedulerPhase == SchedulerPhaseCls::idle) {
        RenderAbsorbPointer absorber = _overlayKey->currentContext()?-><RenderAbsorbPointer>findAncestorRenderObjectOfType();
        setState([=] () {
            absorber?->absorbing() = true;
        });
    }
    _activePointers->toList()->forEach(WidgetsBindingCls::instance->cancelPointer);
}

void _RestorationInformationCls::fromSerializableData(Object data) {
    assert(data != nullptr);
    List<Object> casted = as<List<Object>>(data);
    assert(casted->isNotEmpty());
    _RouteRestorationType type = _RouteRestorationTypeCls::values[as<int>(casted[0]!)];
    assert(type != nullptr);
    ;
}

bool _RestorationInformationCls::isRestorable() {
    return true;
}

Object _RestorationInformationCls::getSerializableData() {
    _serializableData |= computeSerializableData();
    return _serializableData!;
}

List<Object> _RestorationInformationCls::computeSerializableData() {
    return makeList(ArrayItem);
}

_RouteEntry _RestorationInformationCls::toRouteEntry(NavigatorState navigator, _RouteLifecycle initialState) {
    assert(navigator != nullptr);
    assert(initialState != nullptr);
    Route<Object> route = createRoute(navigator);
    assert(route != nullptr);
    return make<_RouteEntryCls>(route, initialState, this);
}

_RestorationInformationCls::_RestorationInformationCls(_RouteRestorationType type) {
    {
        assert(type != nullptr);
    }
}

void _NamedRestorationInformationCls::fromSerializableData(List<Object> data) {
    assert(data->length() >= 2);
    return make<_NamedRestorationInformationCls>(as<int>(data[0]!), as<String>(data[1]!), data->length() > 2? data[2] : nullptr);
}

List<Object> _NamedRestorationInformationCls::computeSerializableData() {
    auto _c1 = super->computeSerializableData();_c1.addAll(List<Object> list2 = make<ListCls<>>();list2.add(ArrayItem);list2.add(ArrayItem);if (arguments != nullptr) {    list2.add(ArrayItem);}list2);return _c1;
}

Route<dynamic> _NamedRestorationInformationCls::createRoute(NavigatorState navigator) {
    Route<dynamic> route = navigator-><dynamic>_routeNamed(name, arguments)!;
    assert(route != nullptr);
    return route;
}

_NamedRestorationInformationCls::_NamedRestorationInformationCls(Object arguments, String name, int restorationScopeId) : _RestorationInformation(_RouteRestorationTypeCls::named) {
    {
        assert(name != nullptr);
    }
}

void _AnonymousRestorationInformationCls::fromSerializableData(List<Object> data) {
    assert(data->length() > 1);
    RestorableRouteBuilder<Object> routeBuilder = as<RestorableRouteBuilder>(ui->PluginUtilitiesCls->getCallbackFromHandle(ui->CallbackHandleCls->fromRawHandle(as<int>(data[1]!)))!);
    return make<_AnonymousRestorationInformationCls>(as<int>(data[0]!), routeBuilder, data->length() > 2? data[2] : nullptr);
}

bool _AnonymousRestorationInformationCls::isRestorable() {
    return !kIsWeb;
}

List<Object> _AnonymousRestorationInformationCls::computeSerializableData() {
    assert(isRestorable());
    CallbackHandle handle = ui->PluginUtilitiesCls->getCallbackHandle(routeBuilder);
    assert(handle != nullptr);
    auto _c1 = super->computeSerializableData();_c1.addAll(List<Object> list2 = make<ListCls<>>();list2.add(ArrayItem);list2.add(ArrayItem);if (arguments != nullptr) {    list2.add(ArrayItem);}list2);return _c1;
}

Route<dynamic> _AnonymousRestorationInformationCls::createRoute(NavigatorState navigator) {
    Route<dynamic> result = routeBuilder(navigator->context(), arguments);
    assert(result != nullptr);
    return result;
}

_AnonymousRestorationInformationCls::_AnonymousRestorationInformationCls(Object arguments, int restorationScopeId, RestorableRouteBuilder<Object> routeBuilder) : _RestorationInformation(_RouteRestorationTypeCls::anonymous) {
    {
        assert(routeBuilder != nullptr);
    }
}

void _HistoryPropertyCls::update(List<_RouteEntry> history) {
    assert(isRegistered());
    bool wasUninitialized = _pageToPagelessRoutes == nullptr;
    bool needsSerialization = wasUninitialized;
    _pageToPagelessRoutes |= makeMap(makeList(), makeList();
    _RouteEntry currentPage;
    List<Object> newRoutesForCurrentPage = makeList();
    List<Object> oldRoutesForCurrentPage = _pageToPagelessRoutes![nullptr] | makeList();
    bool restorationEnabled = true;
    Map<String, List<Object>> newMap = makeMap(makeList(), makeList();
    Set<String> removedPages = _pageToPagelessRoutes!->keys()->toSet();
    for (_RouteEntry entry : history) {
        if (!entry->isPresentForRestoration) {
            entry->restorationEnabled = false;
            continue;
        }
        assert(entry->isPresentForRestoration);
        if (entry->hasPage) {
            needsSerialization = needsSerialization || newRoutesForCurrentPage->length() != oldRoutesForCurrentPage->length();
            _finalizePage(newRoutesForCurrentPage, currentPage, newMap, removedPages);
            currentPage = entry;
            restorationEnabled = entry->restorationId != nullptr;
            entry->restorationEnabled = restorationEnabled;
            if (restorationEnabled) {
                assert(entry->restorationId != nullptr);
                newRoutesForCurrentPage = makeList();
                oldRoutesForCurrentPage = _pageToPagelessRoutes![entry->restorationId] | makeList();
            } else {
                newRoutesForCurrentPage = makeList();
                oldRoutesForCurrentPage = makeList();
            }
            continue;
        }
        assert(!entry->hasPage);
        restorationEnabled = restorationEnabled && (entry->restorationInformation?->isRestorable | false);
        entry->restorationEnabled = restorationEnabled;
        if (restorationEnabled) {
            assert(entry->restorationId != nullptr);
            assert(currentPage == nullptr || currentPage->restorationId() != nullptr);
            assert(entry->restorationInformation != nullptr);
            Object serializedData = entry->restorationInformation!->getSerializableData();
            needsSerialization = needsSerialization || oldRoutesForCurrentPage->length() <= newRoutesForCurrentPage->length() || oldRoutesForCurrentPage[newRoutesForCurrentPage->length()] != serializedData;
            newRoutesForCurrentPage->add(serializedData);
        }
    }
    needsSerialization = needsSerialization || newRoutesForCurrentPage->length() != oldRoutesForCurrentPage->length();
    _finalizePage(newRoutesForCurrentPage, currentPage, newMap, removedPages);
    needsSerialization = needsSerialization || removedPages->isNotEmpty();
    assert(wasUninitialized || _debugMapsEqual(_pageToPagelessRoutes!, newMap) != needsSerialization);
    if (needsSerialization) {
        _pageToPagelessRoutes = newMap;
        notifyListeners();
    }
}

void _HistoryPropertyCls::clear() {
    assert(isRegistered());
    if (_pageToPagelessRoutes == nullptr) {
        return;
    }
    _pageToPagelessRoutes = nullptr;
    notifyListeners();
}

bool _HistoryPropertyCls::hasData() {
    return _pageToPagelessRoutes != nullptr;
}

List<_RouteEntry> _HistoryPropertyCls::restoreEntriesForPage(_RouteEntry page, NavigatorState navigator) {
    assert(isRegistered());
    assert(page == nullptr || page->hasPage());
    List<_RouteEntry> result = makeList();
    if (_pageToPagelessRoutes == nullptr || (page != nullptr && page->restorationId() == nullptr)) {
        return result;
    }
    List<Object> serializedData = _pageToPagelessRoutes![page?->restorationId()];
    if (serializedData == nullptr) {
        return result;
    }
    for (Object data : serializedData) {
        result->add(_RestorationInformationCls->fromSerializableData(data)->toRouteEntry(navigator));
    }
    return result;
}

Map<String, List<Object>> _HistoryPropertyCls::createDefaultValue() {
    return nullptr;
}

Map<String, List<Object>> _HistoryPropertyCls::fromPrimitives(Object data) {
    Map<dynamic, dynamic> casted = as<Map<dynamic, dynamic>>(data!);
    return casted-><String, List<Object>>map([=] (dynamic key,dynamic value) {
        <String, List<Object>>make<MapEntryCls>(as<String>(key), <Object>from(as<List<dynamic>>(value)));
    });
}

void _HistoryPropertyCls::initWithValue(Map<String, List<Object>> value) {
    _pageToPagelessRoutes = value;
}

Object _HistoryPropertyCls::toPrimitives() {
    return _pageToPagelessRoutes;
}

bool _HistoryPropertyCls::enabled() {
    return hasData();
}

void _HistoryPropertyCls::_finalizePage(List<Object> routes, _RouteEntry page, Map<String, List<Object>> pageToRoutes, Set<String> pagesToRemove) {
    assert(page == nullptr || page->hasPage());
    assert(pageToRoutes != nullptr);
    assert(!pageToRoutes->containsKey(page?->restorationId()));
    if (routes != nullptr && routes->isNotEmpty()) {
        assert(page == nullptr || page->restorationId() != nullptr);
        String restorationId = page?->restorationId();
        pageToRoutes[restorationId] = routes;
        pagesToRemove->remove(restorationId);
    }
}

bool _HistoryPropertyCls::_debugMapsEqual(Map<String, List<Object>> a, Map<String, List<Object>> b) {
    if (!setEquals(a->keys()->toSet(), b->keys()->toSet())) {
        return false;
    }
    for (String key : a->keys()) {
        if (!listEquals(a[key], b[key])) {
            return false;
        }
    }
    return true;
}

template<typename T>
RestorableRouteFutureCls<T>::RestorableRouteFutureCls(NavigatorFinderCallback navigatorFinder, RouteCompletionCallback<T> onComplete, RoutePresentationCallback onPresent) {
    {
        assert(onPresent != nullptr);
        assert(navigatorFinder != nullptr);
    }
}

template<typename T>
void RestorableRouteFutureCls<T>::present(Object arguments) {
    assert(!isPresent());
    assert(isRegistered());
    String routeId = onPresent(_navigator(), arguments);
    assert(routeId != nullptr);
    _hookOntoRouteFuture(routeId);
    notifyListeners();
}

template<typename T>
bool RestorableRouteFutureCls<T>::isPresent() {
    return route() != nullptr;
}

template<typename T>
Route<T> RestorableRouteFutureCls<T>::route() {
    return _route;
}

template<typename T>
String RestorableRouteFutureCls<T>::createDefaultValue() {
    return nullptr;
}

template<typename T>
void RestorableRouteFutureCls<T>::initWithValue(String value) {
    if (value != nullptr) {
        _hookOntoRouteFuture(value);
    }
}

template<typename T>
Object RestorableRouteFutureCls<T>::toPrimitives() {
    assert(route() != nullptr);
    assert(enabled());
    return route()?->restorationScopeId()->value();
}

template<typename T>
String RestorableRouteFutureCls<T>::fromPrimitives(Object data) {
    assert(data != nullptr);
    return as<String>(data!);
}

template<typename T>
void RestorableRouteFutureCls<T>::dispose() {
    super->dispose();
    _route?->restorationScopeId()->removeListener(notifyListeners);
    _disposed = true;
}

template<typename T>
bool RestorableRouteFutureCls<T>::enabled() {
    return route()?->restorationScopeId()->value() != nullptr;
}

template<typename T>
NavigatorState RestorableRouteFutureCls<T>::_navigator() {
    NavigatorState navigator = navigatorFinder(state()->context());
    assert(navigator != nullptr);
    return navigator;
}

template<typename T>
void RestorableRouteFutureCls<T>::_hookOntoRouteFuture(String id) {
    assert(id != nullptr);
    _route = _navigator()-><T>_getRouteById(id);
    assert(_route != nullptr);
    route()!->restorationScopeId()->addListener(notifyListeners);
    route()!->popped()->then([=] (dynamic result) {
        if (_disposed) {
            return;
        }
        _route?->restorationScopeId()->removeListener(notifyListeners);
        _route = nullptr;
        notifyListeners();
        onComplete?->call(as<T>(result));
    });
}

template<typename T>
NavigatorState RestorableRouteFutureCls<T>::_defaultNavigatorFinder(BuildContext context) {
    return NavigatorCls->of(context);
}
