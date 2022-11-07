#include "navigator.hpp"
Route::Route(RouteSettings settings) {
    {
        _settings = settings ?? const RouteSettings();
    }
}

NavigatorState Route::navigator() {
    return _navigator;
}

RouteSettings Route::settings() {
    return _settings;
}

ValueListenable<String> Route::restorationScopeId() {
    return _restorationScopeId;
}

List<OverlayEntry> Route::overlayEntries() {
    return const ;
}

void Route::install() {
}

TickerFuture Route::didPush() {
    return ;
}

void Route::didAdd() {
    if (navigator?.widget.requestFocus ?? false) {
        TickerFuture.complete().<void>then();
    }
}

void Route::didReplace(Route<dynamic> oldRoute) {
}

Future<RoutePopDisposition> Route::willPop() {
    return isFirst? RoutePopDisposition.bubble : RoutePopDisposition.pop;
}

bool Route::willHandlePopInternally() {
    return false;
}

T Route::currentResult() {
    return nullptr;
}

Future<T> Route::popped() {
    return _popCompleter.future;
}

bool Route::didPop(T result) {
    didComplete(result);
    return true;
}

void Route::didComplete(T result) {
    _popCompleter.complete(result ?? currentResult);
}

void Route::didPopNext(Route<dynamic> nextRoute) {
}

void Route::didChangeNext(Route<dynamic> nextRoute) {
}

void Route::didChangePrevious(Route<dynamic> previousRoute) {
}

void Route::changedInternalState() {
}

void Route::changedExternalState() {
}

void Route::dispose() {
    _navigator = nullptr;
}

bool Route::isCurrent() {
    if (_navigator == nullptr) {
        return false;
    }
    _RouteEntry currentRouteEntry = _navigator!._history.<_RouteEntry>cast().lastWhere();
    if (currentRouteEntry == nullptr) {
        return false;
    }
    return currentRouteEntry.route == this;
}

bool Route::isFirst() {
    if (_navigator == nullptr) {
        return false;
    }
    _RouteEntry currentRouteEntry = _navigator!._history.<_RouteEntry>cast().firstWhere();
    if (currentRouteEntry == nullptr) {
        return false;
    }
    return currentRouteEntry.route == this;
}

bool Route::hasActiveRouteBelow() {
    if (_navigator == nullptr) {
        return false;
    }
    for (_RouteEntry entry : _navigator!._history) {
        if (entry.route == this) {
            return false;
        }
        if (_RouteEntry.isPresentPredicate(entry)) {
            return true;
        }
    }
    return false;
}

bool Route::isActive() {
    if (_navigator == nullptr) {
        return false;
    }
    return _navigator!._history.<_RouteEntry>cast().firstWhere()?.isPresent ?? false;
}

void Route::_updateSettings(RouteSettings newSettings) {
    assert(newSettings != nullptr);
    if (_settings != newSettings) {
        _settings = newSettings;
        changedInternalState();
    }
}

void Route::_updateRestorationId(String restorationId) {
    _restorationScopeId.value = restorationId;
}

RouteSettings RouteSettings::copyWith(Object arguments, String name) {
    return RouteSettings(name ?? this.name, arguments ?? this.arguments);
}

String RouteSettings::toString() {
    return "${objectRuntimeType(this, 'RouteSettings')}("$name", $arguments)";
}

bool Page::canUpdate(Page<dynamic> other) {
    return other.runtimeType == runtimeType && other.key == key;
}

String Page::toString() {
    return "${objectRuntimeType(this, 'Page')}("$name", $key, $arguments)";
}

NavigatorState NavigatorObserver::navigator() {
    return _navigator;
}

void NavigatorObserver::didPush(Route<dynamic> previousRoute, Route<dynamic> route) {
}

void NavigatorObserver::didPop(Route<dynamic> previousRoute, Route<dynamic> route) {
}

void NavigatorObserver::didRemove(Route<dynamic> previousRoute, Route<dynamic> route) {
}

void NavigatorObserver::didReplace(Route<dynamic> newRoute, Route<dynamic> oldRoute) {
}

void NavigatorObserver::didStartUserGesture(Route<dynamic> previousRoute, Route<dynamic> route) {
}

void NavigatorObserver::didStopUserGesture() {
}

HeroControllerScope::HeroControllerScope(Unknown, HeroController controller, Unknown) {
    {
        assert(controller != nullptr);
    }
}

void HeroControllerScope::none(Unknown, Unknown)

HeroController HeroControllerScope::of(BuildContext context) {
    HeroControllerScope host = context.<HeroControllerScope>dependOnInheritedWidgetOfExactType();
    return host?.controller;
}

bool HeroControllerScope::updateShouldNotify(HeroControllerScope oldWidget) {
    return oldWidget.controller != controller;
}

Iterable<RouteTransitionRecord> TransitionDelegate::_transition(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes) {
    Iterable<RouteTransitionRecord> results = resolve(newPageRouteHistory, locationToExitingPageRoute, pageRouteToPagelessRoutes);
    assert(());
    return results;
}

DefaultTransitionDelegate::DefaultTransitionDelegate() {
    {
        super();
    }
}

Iterable<RouteTransitionRecord> DefaultTransitionDelegate::resolve(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes) {
    List<RouteTransitionRecord> results = ;
    ;
    handleExitingRoute(nullptr, newPageRouteHistory.isEmpty);
    for (RouteTransitionRecord pageRoute : newPageRouteHistory) {
        bool isLastIteration = newPageRouteHistory.last == pageRoute;
        if (pageRoute.isWaitingForEnteringDecision) {
            if (!locationToExitingPageRoute.containsKey(pageRoute) && isLastIteration) {
                pageRoute.markForPush();
            } else {
                pageRoute.markForAdd();
            }
        }
        results.add(pageRoute);
        handleExitingRoute(pageRoute, isLastIteration);
    }
    return results;
}

Navigator::Navigator(String initialRoute, Unknown, List<NavigatorObserver> observers, RouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, PopPageCallback onPopPage, RouteFactory onUnknownRoute, List<Page<dynamic>> pages, bool reportsRouteUpdateToEngine, bool requestFocus, String restorationScopeId, TransitionDelegate<dynamic> transitionDelegate) {
    {
        assert(pages != nullptr);
        assert(onGenerateInitialRoutes != nullptr);
        assert(transitionDelegate != nullptr);
        assert(observers != nullptr);
        assert(reportsRouteUpdateToEngine != nullptr);
    }
}

Future<T> Navigator::pushNamed<T extends Object>(Object arguments, BuildContext context, String routeName) {
    return Navigator.of(context).<T>pushNamed(routeNamearguments);
}

String Navigator::restorablePushNamed<T extends Object>(Object arguments, BuildContext context, String routeName) {
    return Navigator.of(context).<T>restorablePushNamed(routeNamearguments);
}

Future<T> Navigator::pushReplacementNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName) {
    return Navigator.of(context).<T, TO>pushReplacementNamed(routeNamearguments, result);
}

String Navigator::restorablePushReplacementNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName) {
    return Navigator.of(context).<T, TO>restorablePushReplacementNamed(routeNamearguments, result);
}

Future<T> Navigator::popAndPushNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName) {
    return Navigator.of(context).<T, TO>popAndPushNamed(routeNamearguments, result);
}

String Navigator::restorablePopAndPushNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName) {
    return Navigator.of(context).<T, TO>restorablePopAndPushNamed(routeNamearguments, result);
}

Future<T> Navigator::pushNamedAndRemoveUntil<T extends Object>(Object arguments, BuildContext context, String newRouteName, RoutePredicate predicate) {
    return Navigator.of(context).<T>pushNamedAndRemoveUntil(newRouteName, predicatearguments);
}

String Navigator::restorablePushNamedAndRemoveUntil<T extends Object>(Object arguments, BuildContext context, String newRouteName, RoutePredicate predicate) {
    return Navigator.of(context).<T>restorablePushNamedAndRemoveUntil(newRouteName, predicatearguments);
}

Future<T> Navigator::push<T extends Object>(BuildContext context, Route<T> route) {
    return Navigator.of(context).push(route);
}

String Navigator::restorablePush<T extends Object>(Object arguments, BuildContext context, RestorableRouteBuilder<T> routeBuilder) {
    return Navigator.of(context).restorablePush(routeBuilderarguments);
}

Future<T> Navigator::pushReplacement<T extends Object, TO extends Object>(BuildContext context, Route<T> newRoute, TO result) {
    return Navigator.of(context).<T, TO>pushReplacement(newRouteresult);
}

String Navigator::restorablePushReplacement<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, RestorableRouteBuilder<T> routeBuilder) {
    return Navigator.of(context).<T, TO>restorablePushReplacement(routeBuilderresult, arguments);
}

Future<T> Navigator::pushAndRemoveUntil<T extends Object>(BuildContext context, Route<T> newRoute, RoutePredicate predicate) {
    return Navigator.of(context).<T>pushAndRemoveUntil(newRoute, predicate);
}

String Navigator::restorablePushAndRemoveUntil<T extends Object>(Object arguments, BuildContext context, RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate) {
    return Navigator.of(context).<T>restorablePushAndRemoveUntil(newRouteBuilder, predicatearguments);
}

void Navigator::replace<T extends Object>(BuildContext context, Route<T> newRoute, Route<dynamic> oldRoute) {
    return Navigator.of(context).<T>replace(oldRoute, newRoute);
}

String Navigator::restorableReplace<T extends Object>(Object arguments, BuildContext context, RestorableRouteBuilder<T> newRouteBuilder, Route<dynamic> oldRoute) {
    return Navigator.of(context).<T>restorableReplace(oldRoute, newRouteBuilder, arguments);
}

void Navigator::replaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, BuildContext context, Route<T> newRoute) {
    return Navigator.of(context).<T>replaceRouteBelow(anchorRoute, newRoute);
}

String Navigator::restorableReplaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, Object arguments, BuildContext context, RestorableRouteBuilder<T> newRouteBuilder) {
    return Navigator.of(context).<T>restorableReplaceRouteBelow(anchorRoute, newRouteBuilder, arguments);
}

bool Navigator::canPop(BuildContext context) {
    NavigatorState navigator = Navigator.maybeOf(context);
    return navigator != nullptr && navigator.canPop();
}

Future<bool> Navigator::maybePop<T extends Object>(BuildContext context, T result) {
    return Navigator.of(context).<T>maybePop(result);
}

void Navigator::pop<T extends Object>(BuildContext context, T result) {
    Navigator.of(context).<T>pop(result);
}

void Navigator::popUntil(BuildContext context, RoutePredicate predicate) {
    Navigator.of(context).popUntil(predicate);
}

void Navigator::removeRoute(BuildContext context, Route<dynamic> route) {
    return Navigator.of(context).removeRoute(route);
}

void Navigator::removeRouteBelow(Route<dynamic> anchorRoute, BuildContext context) {
    return Navigator.of(context).removeRouteBelow(anchorRoute);
}

NavigatorState Navigator::of(BuildContext context, bool rootNavigator) {
    NavigatorState navigator;
    if (context is StatefulElement && context.state is NavigatorState) {
        navigator = (;
    }
    if (rootNavigator) {
        navigator = context.<NavigatorState>findRootAncestorStateOfType() ?? navigator;
    } else {
        navigator = navigator ?? context.<NavigatorState>findAncestorStateOfType();
    }
    assert(());
    return navigator!;
}

NavigatorState Navigator::maybeOf(BuildContext context, bool rootNavigator) {
    NavigatorState navigator;
    if (context is StatefulElement && context.state is NavigatorState) {
        navigator = (;
    }
    if (rootNavigator) {
        navigator = context.<NavigatorState>findRootAncestorStateOfType() ?? navigator;
    } else {
        navigator = navigator ?? context.<NavigatorState>findAncestorStateOfType();
    }
    return navigator;
}

List<Route<dynamic>> Navigator::defaultGenerateInitialRoutes(String initialRouteName, NavigatorState navigator) {
    List<Route<dynamic>> result = ;
    if (initialRouteName.startsWith("/") && initialRouteName.length > 1) {
        initialRouteName = initialRouteName.substring(1);
        assert(Navigator.defaultRouteName == "/");
        List<String> debugRouteNames;
        assert(());
        result.add(navigator.<dynamic>_routeNamed(Navigator.defaultRouteNamenullptr, true));
        List<String> routeParts = initialRouteName.split("/");
        if (initialRouteName.isNotEmpty) {
            String routeName = "";
            for (String part : routeParts) {
                routeName = "/$part";
                assert(());
                result.add(navigator.<dynamic>_routeNamed(routeNamenullptr, true));
            }
        }
        if (result.last == nullptr) {
            assert(());
            result.clear();
        }
    } else     {
        if (initialRouteName != Navigator.defaultRouteName) {
        result.add(navigator.<dynamic>_routeNamed(initialRouteNamenullptr, true));
    }
;
    }    result.removeWhere();
    if (result.isEmpty) {
        result.add(navigator.<dynamic>_routeNamed(Navigator.defaultRouteNamenullptr));
    }
    return result.<Route<dynamic>>cast();
}

NavigatorState Navigator::createState() {
    return NavigatorState();
}

String _RouteEntry::restorationId() {
    if (hasPage) {
        Page<Object> page = (;
        return page.restorationId != nullptr? "p+${page.restorationId}" : nullptr;
    }
    if (restorationInformation != nullptr) {
        return "r+${restorationInformation!.restorationScopeId}";
    }
    return nullptr;
}

bool _RouteEntry::hasPage() {
    return route.settings is Page;
}

bool _RouteEntry::canUpdateFrom(Page<dynamic> page) {
    if (!willBePresent) {
        return false;
    }
    if (!hasPage) {
        return false;
    }
    Page<dynamic> routePage = (;
    return page.canUpdate(routePage);
}

void _RouteEntry::handleAdd(NavigatorState navigator, Route<dynamic> previousPresent) {
    assert(currentState == _RouteLifecycle.add);
    assert(navigator != nullptr);
    assert(navigator._debugLocked);
    assert(route._navigator == nullptr);
    route._navigator = navigator;
    route.install();
    assert(route.overlayEntries.isNotEmpty);
    currentState = _RouteLifecycle.adding;
    navigator._observedRouteAdditions.add(_NavigatorPushObservation(route, previousPresent));
}

void _RouteEntry::handlePush(bool isNewFirst, NavigatorState navigator, Route<dynamic> previous, Route<dynamic> previousPresent) {
    assert(currentState == _RouteLifecycle.push || currentState == _RouteLifecycle.pushReplace || currentState == _RouteLifecycle.replace);
    assert(navigator != nullptr);
    assert(navigator._debugLocked);
    assert(route._navigator == nullptr, "The pushed route has already been used. When pushing a route, a new Route object must be provided.");
    _RouteLifecycle previousState = currentState;
    route._navigator = navigator;
    route.install();
    assert(route.overlayEntries.isNotEmpty);
    if (currentState == _RouteLifecycle.push || currentState == _RouteLifecycle.pushReplace) {
        TickerFuture routeFuture = route.didPush();
        currentState = _RouteLifecycle.pushing;
        routeFuture.whenCompleteOrCancel();
    } else {
        assert(currentState == _RouteLifecycle.replace);
        route.didReplace(previous);
        currentState = _RouteLifecycle.idle;
    }
    if (isNewFirst) {
        route.didChangeNext(nullptr);
    }
    if (previousState == _RouteLifecycle.replace || previousState == _RouteLifecycle.pushReplace) {
        navigator._observedRouteAdditions.add(_NavigatorReplaceObservation(route, previousPresent));
    } else {
        assert(previousState == _RouteLifecycle.push);
        navigator._observedRouteAdditions.add(_NavigatorPushObservation(route, previousPresent));
    }
}

void _RouteEntry::handleDidPopNext(Route<dynamic> poppedRoute) {
    route.didPopNext(poppedRoute);
    lastAnnouncedPoppedNextRoute = poppedRoute;
}

bool _RouteEntry::handlePop(NavigatorState navigator, Route<dynamic> previousPresent) {
    assert(navigator != nullptr);
    assert(navigator._debugLocked);
    assert(route._navigator == navigator);
    currentState = _RouteLifecycle.popping;
    if (route._popCompleter.isCompleted) {
        assert(hasPage);
        assert(pendingResult == nullptr);
        return true;
    }
    if (!route.didPop(pendingResult)) {
        currentState = _RouteLifecycle.idle;
        return false;
    }
    pendingResult = nullptr;
    return true;
}

void _RouteEntry::handleComplete() {
    route.didComplete(pendingResult);
    pendingResult = nullptr;
    assert(route._popCompleter.isCompleted);
    currentState = _RouteLifecycle.remove;
}

void _RouteEntry::handleRemoval(NavigatorState navigator, Route<dynamic> previousPresent) {
    assert(navigator != nullptr);
    assert(navigator._debugLocked);
    assert(route._navigator == navigator);
    currentState = _RouteLifecycle.removing;
    if (_reportRemovalToObserver) {
        navigator._observedRouteDeletions.add(_NavigatorRemoveObservation(route, previousPresent));
    }
}

void _RouteEntry::didAdd(bool isNewFirst, NavigatorState navigator) {
    route.didAdd();
    currentState = _RouteLifecycle.idle;
    if (isNewFirst) {
        route.didChangeNext(nullptr);
    }
}

void _RouteEntry::pop<T>(T result) {
    assert(isPresent);
    pendingResult = result;
    currentState = _RouteLifecycle.pop;
}

void _RouteEntry::remove(bool isReplaced) {
    assert(!hasPage || isWaitingForExitingDecision, "A page-based route cannot be completed using imperative api, provide a new list without the corresponding Page to Navigator.pages instead. ");
    if (currentState.index >= _RouteLifecycle.remove.index) {
        return;
    }
    assert(isPresent);
    _reportRemovalToObserver = !isReplaced;
    currentState = _RouteLifecycle.remove;
}

void _RouteEntry::complete<T>(bool isReplaced, T result) {
    assert(!hasPage || isWaitingForExitingDecision, "A page-based route cannot be completed using imperative api, provide a new list without the corresponding Page to Navigator.pages instead. ");
    if (currentState.index >= _RouteLifecycle.remove.index) {
        return;
    }
    assert(isPresent);
    _reportRemovalToObserver = !isReplaced;
    pendingResult = result;
    currentState = _RouteLifecycle.complete;
}

void _RouteEntry::finalize() {
    assert(currentState.index < _RouteLifecycle.dispose.index);
    currentState = _RouteLifecycle.dispose;
}

void _RouteEntry::dispose() {
    assert(currentState.index < _RouteLifecycle.disposed.index);
    currentState = _RouteLifecycle.disposed;
    Iterable<OverlayEntry> mountedEntries = route.overlayEntries.where();
    if (mountedEntries.isEmpty) {
        route.dispose();
    } else {
        int mounted = mountedEntries.length;
        assert(mounted > 0);
        for (OverlayEntry entry : mountedEntries) {
            VoidCallback listener;
            listener = ;
            entry.addListener(listener);
        }
    }
}

bool _RouteEntry::willBePresent() {
    return currentState.index <= _RouteLifecycle.idle.index && currentState.index >= _RouteLifecycle.add.index;
}

bool _RouteEntry::isPresent() {
    return currentState.index <= _RouteLifecycle.remove.index && currentState.index >= _RouteLifecycle.add.index;
}

bool _RouteEntry::isPresentForRestoration() {
    return currentState.index <= _RouteLifecycle.idle.index;
}

bool _RouteEntry::suitableForAnnouncement() {
    return currentState.index <= _RouteLifecycle.removing.index && currentState.index >= _RouteLifecycle.push.index;
}

bool _RouteEntry::suitableForTransitionAnimation() {
    return currentState.index <= _RouteLifecycle.remove.index && currentState.index >= _RouteLifecycle.push.index;
}

bool _RouteEntry::shouldAnnounceChangeToNext(Route<dynamic> nextRoute) {
    assert(nextRoute != lastAnnouncedNextRoute);
    return !(nextRoute == nullptr && lastAnnouncedPoppedNextRoute != nullptr && lastAnnouncedPoppedNextRoute == lastAnnouncedNextRoute);
}

bool _RouteEntry::isPresentPredicate(_RouteEntry entry) {
    return entry.isPresent;
}

bool _RouteEntry::suitableForTransitionAnimationPredicate(_RouteEntry entry) {
    return entry.suitableForTransitionAnimation;
}

bool _RouteEntry::willBePresentPredicate(_RouteEntry entry) {
    return entry.willBePresent;
}

_RouteEntryPredicate _RouteEntry::isRoutePredicate(Route<dynamic> route) {
    return ;
}

bool _RouteEntry::isWaitingForEnteringDecision() {
    return currentState == _RouteLifecycle.staging;
}

bool _RouteEntry::isWaitingForExitingDecision() {
    return _isWaitingForExitingDecision;
}

void _RouteEntry::markNeedsExitingDecision() {
    return _isWaitingForExitingDecision = true;
}

void _RouteEntry::markForPush() {
    assert(isWaitingForEnteringDecision && !isWaitingForExitingDecision, "This route cannot be marked for push. Either a decision has already been made or it does not require an explicit decision on how to transition in.");
    currentState = _RouteLifecycle.push;
}

void _RouteEntry::markForAdd() {
    assert(isWaitingForEnteringDecision && !isWaitingForExitingDecision, "This route cannot be marked for add. Either a decision has already been made or it does not require an explicit decision on how to transition in.");
    currentState = _RouteLifecycle.add;
}

void _RouteEntry::markForPop(dynamic result) {
    assert(!isWaitingForEnteringDecision && isWaitingForExitingDecision && isPresent, "This route cannot be marked for pop. Either a decision has already been made or it does not require an explicit decision on how to transition out.");
    <dynamic>pop(result);
    _isWaitingForExitingDecision = false;
}

void _RouteEntry::markForComplete(dynamic result) {
    assert(!isWaitingForEnteringDecision && isWaitingForExitingDecision && isPresent, "This route cannot be marked for complete. Either a decision has already been made or it does not require an explicit decision on how to transition out.");
    <dynamic>complete(result);
    _isWaitingForExitingDecision = false;
}

void _RouteEntry::markForRemove() {
    assert(!isWaitingForEnteringDecision && isWaitingForExitingDecision && isPresent, "This route cannot be marked for remove. Either a decision has already been made or it does not require an explicit decision on how to transition out.");
    remove();
    _isWaitingForExitingDecision = false;
}

bool _RouteEntry::restorationEnabled() {
    return route.restorationScopeId.value != nullptr;
}

void _RouteEntry::restorationEnabled(bool value) {
    assert(!value || restorationId != nullptr);
    route._updateRestorationId(value? restorationId : nullptr);
}

_RouteEntry::_RouteEntry(_RouteLifecycle initialState, _RestorationInformation restorationInformation, Route<dynamic> route) {
    {
        assert(route != nullptr);
        assert(initialState != nullptr);
        assert(initialState == _RouteLifecycle.staging || initialState == _RouteLifecycle.add || initialState == _RouteLifecycle.push || initialState == _RouteLifecycle.pushReplace || initialState == _RouteLifecycle.replace);
        currentState = initialState;
    }
}

void _NavigatorPushObservation::notify(NavigatorObserver observer) {
    observer.didPush(primaryRoute, secondaryRoute);
}

void _NavigatorPopObservation::notify(NavigatorObserver observer) {
    observer.didPop(primaryRoute, secondaryRoute);
}

void _NavigatorRemoveObservation::notify(NavigatorObserver observer) {
    observer.didRemove(primaryRoute, secondaryRoute);
}

void _NavigatorReplaceObservation::notify(NavigatorObserver observer) {
    observer.didReplace(primaryRoute, secondaryRoute);
}

void NavigatorState::initState() {
    super.initState();
    assert(());
    for (NavigatorObserver observer : widget.observers) {
        assert(observer.navigator == nullptr);
        observer._navigator = this;
    }
    _effectiveObservers = widget.observers;
    HeroControllerScope heroControllerScope = (;
    _updateHeroController(heroControllerScope?.controller);
    if (widget.reportsRouteUpdateToEngine) {
        SystemNavigator.selectSingleEntryHistory();
    }
}

void NavigatorState::restoreState(bool initialRestore, RestorationBucket oldBucket) {
    registerForRestoration(_rawNextPagelessRestorationScopeId, "id");
    registerForRestoration(_serializableHistory, "history");
    while (_history.isNotEmpty) {
        _history.removeLast().dispose();
    }
    assert(_history.isEmpty);
    _overlayKey = <OverlayState>GlobalKey();
    _history.addAll(_serializableHistory.restoreEntriesForPage(nullptr, this));
    for (Page<dynamic> page : widget.pages) {
        _RouteEntry entry = _RouteEntry(page.createRoute(context)_RouteLifecycle.add);
        assert(entry.route.settings == page, "The settings getter of a page-based Route must return a Page object. Please set the settings to the Page in the Page.createRoute method.");
        _history.add(entry);
        _history.addAll(_serializableHistory.restoreEntriesForPage(entry, this));
    }
    if (!_serializableHistory.hasData) {
        String initialRoute = widget.initialRoute;
        if (widget.pages.isEmpty) {
            initialRoute = initialRoute ?? Navigator.defaultRouteName;
        }
        if (initialRoute != nullptr) {
            _history.addAll(widget.onGenerateInitialRoutes(this, widget.initialRoute ?? Navigator.defaultRouteName).map());
        }
    }
    assert(_history.isNotEmpty, "All routes returned by onGenerateInitialRoutes are not restorable. Please make sure that all routes returned by onGenerateInitialRoutes have their RouteSettings defined with names that are defined in the app's routes table.");
    assert(!_debugLocked);
    assert(());
    _flushHistoryUpdates();
    assert(());
}

void NavigatorState::didToggleBucket(RestorationBucket oldBucket) {
    super.didToggleBucket(oldBucket);
    if (bucket != nullptr) {
        _serializableHistory.update(_history);
    } else {
        _serializableHistory.clear();
    }
}

String NavigatorState::restorationId() {
    return widget.restorationScopeId;
}

void NavigatorState::didChangeDependencies() {
    super.didChangeDependencies();
    _updateHeroController(HeroControllerScope.of(context));
    for (_RouteEntry entry : _history) {
        entry.route.changedExternalState();
    }
}

void NavigatorState::didUpdateWidget(Navigator oldWidget) {
    super.didUpdateWidget(oldWidget);
    assert(());
    if (oldWidget.observers != widget.observers) {
        for (NavigatorObserver observer : oldWidget.observers) {
            observer._navigator = nullptr;
        }
        for (NavigatorObserver observer : widget.observers) {
            assert(observer.navigator == nullptr);
            observer._navigator = this;
        }
        _updateEffectiveObservers();
    }
    if (oldWidget.pages != widget.pages && !restorePending) {
        assert(());
        _updatePages();
    }
    for (_RouteEntry entry : _history) {
        entry.route.changedExternalState();
    }
}

void NavigatorState::deactivate() {
    for (NavigatorObserver observer : _effectiveObservers) {
        observer._navigator = nullptr;
    }
    super.deactivate();
}

void NavigatorState::activate() {
    super.activate();
    for (NavigatorObserver observer : _effectiveObservers) {
        assert(observer.navigator == nullptr);
        observer._navigator = this;
    }
}

void NavigatorState::dispose() {
    assert(!_debugLocked);
    assert(());
    assert(());
    _updateHeroController(nullptr);
    focusScopeNode.dispose();
    for (_RouteEntry entry : _history) {
        entry.dispose();
    }
    super.dispose();
    assert(_debugLocked);
}

OverlayState NavigatorState::overlay() {
    return _overlayKey.currentState;
}

Future<T> NavigatorState::pushNamed<T extends Object>(Object arguments, String routeName) {
    return <T>push(<T>_routeNamed(routeNamearguments)!);
}

String NavigatorState::restorablePushNamed<T extends Object>(Object arguments, String routeName) {
    assert(routeName != nullptr);
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    _RouteEntry entry = _RestorationInformation.named(routeName, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.push);
    _pushEntry(entry);
    return entry.restorationId!;
}

Future<T> NavigatorState::pushReplacementNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName) {
    return <T, TO>pushReplacement(<T>_routeNamed(routeNamearguments)!result);
}

String NavigatorState::restorablePushReplacementNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName) {
    assert(routeName != nullptr);
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    _RouteEntry entry = _RestorationInformation.named(routeName, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.pushReplace);
    _pushReplacementEntry(entry, result);
    return entry.restorationId!;
}

Future<T> NavigatorState::popAndPushNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName) {
    <TO>pop(result);
    return <T>pushNamed(routeNamearguments);
}

String NavigatorState::restorablePopAndPushNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName) {
    <TO>pop(result);
    return restorablePushNamed(routeNamearguments);
}

Future<T> NavigatorState::pushNamedAndRemoveUntil<T extends Object>(Object arguments, String newRouteName, RoutePredicate predicate) {
    return <T>pushAndRemoveUntil(<T>_routeNamed(newRouteNamearguments)!, predicate);
}

String NavigatorState::restorablePushNamedAndRemoveUntil<T extends Object>(Object arguments, String newRouteName, RoutePredicate predicate) {
    assert(newRouteName != nullptr);
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    _RouteEntry entry = _RestorationInformation.named(newRouteName, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.push);
    _pushEntryAndRemoveUntil(entry, predicate);
    return entry.restorationId!;
}

Future<T> NavigatorState::push<T extends Object>(Route<T> route) {
    assert(_debugCheckIsPagelessRoute(route));
    _pushEntry(_RouteEntry(route_RouteLifecycle.push));
    return route.popped;
}

String NavigatorState::restorablePush<T extends Object>(Object arguments, RestorableRouteBuilder<T> routeBuilder) {
    assert(routeBuilder != nullptr);
    assert(_debugIsStaticCallback(routeBuilder), "The provided routeBuilder must be a static function.");
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    _RouteEntry entry = _RestorationInformation.anonymous(routeBuilder, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.push);
    _pushEntry(entry);
    return entry.restorationId!;
}

Future<T> NavigatorState::pushReplacement<T extends Object, TO extends Object>(Route<T> newRoute, TO result) {
    assert(newRoute != nullptr);
    assert(newRoute._navigator == nullptr);
    assert(_debugCheckIsPagelessRoute(newRoute));
    _pushReplacementEntry(_RouteEntry(newRoute_RouteLifecycle.pushReplace), result);
    return newRoute.popped;
}

String NavigatorState::restorablePushReplacement<T extends Object, TO extends Object>(Object arguments, TO result, RestorableRouteBuilder<T> routeBuilder) {
    assert(routeBuilder != nullptr);
    assert(_debugIsStaticCallback(routeBuilder), "The provided routeBuilder must be a static function.");
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    _RouteEntry entry = _RestorationInformation.anonymous(routeBuilder, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.pushReplace);
    _pushReplacementEntry(entry, result);
    return entry.restorationId!;
}

Future<T> NavigatorState::pushAndRemoveUntil<T extends Object>(Route<T> newRoute, RoutePredicate predicate) {
    assert(newRoute != nullptr);
    assert(newRoute._navigator == nullptr);
    assert(newRoute.overlayEntries.isEmpty);
    assert(_debugCheckIsPagelessRoute(newRoute));
    _pushEntryAndRemoveUntil(_RouteEntry(newRoute_RouteLifecycle.push), predicate);
    return newRoute.popped;
}

String NavigatorState::restorablePushAndRemoveUntil<T extends Object>(Object arguments, RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate) {
    assert(newRouteBuilder != nullptr);
    assert(_debugIsStaticCallback(newRouteBuilder), "The provided routeBuilder must be a static function.");
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    _RouteEntry entry = _RestorationInformation.anonymous(newRouteBuilder, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.push);
    _pushEntryAndRemoveUntil(entry, predicate);
    return entry.restorationId!;
}

void NavigatorState::replace<T extends Object>(Route<T> newRoute, Route<dynamic> oldRoute) {
    assert(!_debugLocked);
    assert(oldRoute != nullptr);
    assert(oldRoute._navigator == this);
    assert(newRoute != nullptr);
    _replaceEntry(_RouteEntry(newRoute_RouteLifecycle.replace), oldRoute);
}

String NavigatorState::restorableReplace<T extends Object>(Object arguments, RestorableRouteBuilder<T> newRouteBuilder, Route<dynamic> oldRoute) {
    assert(oldRoute != nullptr);
    assert(oldRoute._navigator == this);
    assert(newRouteBuilder != nullptr);
    assert(_debugIsStaticCallback(newRouteBuilder), "The provided routeBuilder must be a static function.");
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    assert(oldRoute != nullptr);
    _RouteEntry entry = _RestorationInformation.anonymous(newRouteBuilder, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.replace);
    _replaceEntry(entry, oldRoute);
    return entry.restorationId!;
}

void NavigatorState::replaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, Route<T> newRoute) {
    assert(newRoute != nullptr);
    assert(newRoute._navigator == nullptr);
    assert(anchorRoute != nullptr);
    assert(anchorRoute._navigator == this);
    _replaceEntryBelow(_RouteEntry(newRoute_RouteLifecycle.replace), anchorRoute);
}

String NavigatorState::restorableReplaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, Object arguments, RestorableRouteBuilder<T> newRouteBuilder) {
    assert(anchorRoute != nullptr);
    assert(anchorRoute._navigator == this);
    assert(newRouteBuilder != nullptr);
    assert(_debugIsStaticCallback(newRouteBuilder), "The provided routeBuilder must be a static function.");
    assert(debugIsSerializableForRestoration(arguments), "The arguments object must be serializable via the StandardMessageCodec.");
    assert(anchorRoute != nullptr);
    _RouteEntry entry = _RestorationInformation.anonymous(newRouteBuilder, arguments, _nextPagelessRestorationScopeId).toRouteEntry(this_RouteLifecycle.replace);
    _replaceEntryBelow(entry, anchorRoute);
    return entry.restorationId!;
}

bool NavigatorState::canPop() {
    Iterator<_RouteEntry> iterator = _history.where(_RouteEntry.isPresentPredicate).iterator;
    if (!iterator.moveNext()) {
        return false;
    }
    if (iterator.current.route.willHandlePopInternally) {
        return true;
    }
    if (!iterator.moveNext()) {
        return false;
    }
    return true;
}

Future<bool> NavigatorState::maybePop<T extends Object>(T result) {
    _RouteEntry lastEntry = _history.<_RouteEntry>cast().lastWhere();
    if (lastEntry == nullptr) {
        return false;
    }
    assert(lastEntry.route._navigator == this);
    RoutePopDisposition disposition = await lastEntry.route.willPop();
    assert(disposition != nullptr);
    if (!mounted) {
        return true;
    }
    _RouteEntry newLastEntry = _history.<_RouteEntry>cast().lastWhere();
    if (lastEntry != newLastEntry) {
        return true;
    }
    ;
}

void NavigatorState::pop<T extends Object>(T result) {
    assert(!_debugLocked);
    assert(());
    _RouteEntry entry = _history.lastWhere(_RouteEntry.isPresentPredicate);
    if (entry.hasPage) {
        if (widget.onPopPage!(entry.route, result) && entry.currentState == _RouteLifecycle.idle) {
            assert(entry.route._popCompleter.isCompleted);
            entry.currentState = _RouteLifecycle.pop;
        }
    } else {
        entry.<T>pop(result);
        assert(entry.currentState == _RouteLifecycle.pop);
    }
    if (entry.currentState == _RouteLifecycle.pop) {
        _flushHistoryUpdates(false);
    }
    assert(entry.currentState == _RouteLifecycle.idle || entry.route._popCompleter.isCompleted);
    assert(());
    _afterNavigation(entry.route);
}

void NavigatorState::popUntil(RoutePredicate predicate) {
    _RouteEntry candidate = _history.<_RouteEntry>cast().lastWhere();
    while (candidate != nullptr) {
        if (predicate(candidate.route)) {
            return;
        }
        pop();
        candidate = _history.<_RouteEntry>cast().lastWhere();
    }
}

void NavigatorState::removeRoute(Route<dynamic> route) {
    assert(route != nullptr);
    assert(!_debugLocked);
    assert(());
    assert(route._navigator == this);
    bool wasCurrent = route.isCurrent;
    _RouteEntry entry = _history.firstWhere(_RouteEntry.isRoutePredicate(route));
    assert(entry != nullptr);
    entry.remove();
    _flushHistoryUpdates(false);
    assert(());
    if (wasCurrent) {
        _afterNavigation(_history.<_RouteEntry>cast().lastWhere()?.route);
    }
}

void NavigatorState::removeRouteBelow(Route<dynamic> anchorRoute) {
    assert(!_debugLocked);
    assert(());
    assert(anchorRoute != nullptr);
    assert(anchorRoute._navigator == this);
    int anchorIndex = _history.indexWhere(_RouteEntry.isRoutePredicate(anchorRoute));
    assert(anchorIndex >= 0, "This Navigator does not contain the specified anchorRoute.");
    assert(_history[anchorIndex].isPresent, "The specified anchorRoute has already been removed from the Navigator.");
    int index = anchorIndex - 1;
    while (index >= 0) {
        if (_history[index].isPresent) {
                        break;
        }
        index = 1;
    }
    assert(index >= 0, "There are no routes below the specified anchorRoute.");
    _history[index].remove();
    _flushHistoryUpdates(false);
    assert(());
}

void NavigatorState::finalizeRoute(Route<dynamic> route) {
    bool wasDebugLocked;
    assert(());
    assert(_history.where(_RouteEntry.isRoutePredicate(route)).length == 1);
    int index = _history.indexWhere(_RouteEntry.isRoutePredicate(route));
    _RouteEntry entry = _history[index];
    if (entry.hasPage && entry.currentState.index < _RouteLifecycle.pop.index) {
        _observedRouteDeletions.add(_NavigatorPopObservation(route, _getRouteBefore(index - 1, _RouteEntry.willBePresentPredicate)?.route));
    } else {
        assert(entry.currentState == _RouteLifecycle.popping);
    }
    entry.finalize();
    if (!_flushingHistory) {
        _flushHistoryUpdates(false);
    }
    assert(());
}

bool NavigatorState::userGestureInProgress() {
    return userGestureInProgressNotifier.value;
}

void NavigatorState::didStartUserGesture() {
    _userGesturesInProgress = 1;
    if (_userGesturesInProgress == 1) {
        int routeIndex = _getIndexBefore(_history.length - 1, _RouteEntry.willBePresentPredicate);
        assert(routeIndex != nullptr);
        Route<dynamic> route = _history[routeIndex].route;
        Route<dynamic> previousRoute;
        if (!route.willHandlePopInternally && routeIndex > 0) {
            previousRoute = _getRouteBefore(routeIndex - 1, _RouteEntry.willBePresentPredicate)!.route;
        }
        for (NavigatorObserver observer : _effectiveObservers) {
            observer.didStartUserGesture(route, previousRoute);
        }
    }
}

void NavigatorState::didStopUserGesture() {
    assert(_userGesturesInProgress > 0);
    _userGesturesInProgress = 1;
    if (_userGesturesInProgress == 0) {
        for (NavigatorObserver observer : _effectiveObservers) {
            observer.didStopUserGesture();
        }
    }
}

Widget NavigatorState::build(BuildContext context) {
    assert(!_debugLocked);
    assert(_history.isNotEmpty);
    return HeroControllerScope.none(Listener(_handlePointerDown, _handlePointerUpOrCancel, _handlePointerUpOrCancel, AbsorbPointer(false, FocusScope(focusScopeNode, true, UnmanagedRestorationScope(bucket, Overlay(_overlayKey, overlay == nullptr? _allRouteOverlayEntries.toList(false) : const ))))));
}

int NavigatorState::_nextPagelessRestorationScopeId() {
    return _rawNextPagelessRestorationScopeId.value++;
}

void NavigatorState::_updateHeroController(HeroController newHeroController) {
    if (_heroControllerFromScope != newHeroController) {
        if (newHeroController != nullptr) {
            assert(());
            newHeroController._navigator = this;
        }
        if (_heroControllerFromScope?._navigator == this) {
            _heroControllerFromScope?._navigator = nullptr;
        }
        _heroControllerFromScope = newHeroController;
        _updateEffectiveObservers();
    }
}

void NavigatorState::_updateEffectiveObservers() {
    if (_heroControllerFromScope != nullptr) {
        _effectiveObservers = widget.observers + ;
    } else {
        _effectiveObservers = widget.observers;
    }
}

void NavigatorState::_debugCheckDuplicatedPageKeys() {
    assert(());
}

Iterable<OverlayEntry> NavigatorState::_allRouteOverlayEntries() {
    return ;
}

void NavigatorState::_updatePages() {
    assert(());
    bool needsExplicitDecision = false;
    int newPagesBottom = 0;
    int oldEntriesBottom = 0;
    int newPagesTop = widget.pages.length - 1;
    int oldEntriesTop = _history.length - 1;
    List<_RouteEntry> newHistory = ;
    Map<_RouteEntry, List<_RouteEntry>> pageRouteToPagelessRoutes = ;
    _RouteEntry previousOldPageRouteEntry;
    while (oldEntriesBottom <= oldEntriesTop) {
        _RouteEntry oldEntry = _history[oldEntriesBottom];
        assert(oldEntry != nullptr && oldEntry.currentState != _RouteLifecycle.disposed);
        if (!oldEntry.hasPage) {
            List<_RouteEntry> pagelessRoutes = pageRouteToPagelessRoutes.putIfAbsent(previousOldPageRouteEntry, );
            pagelessRoutes.add(oldEntry);
            oldEntriesBottom = 1;
            continue;
        }
        if (newPagesBottom > newPagesTop) {
                        break;
        }
        Page<dynamic> newPage = widget.pages[newPagesBottom];
        if (!oldEntry.canUpdateFrom(newPage)) {
                        break;
        }
        previousOldPageRouteEntry = oldEntry;
        oldEntry.route._updateSettings(newPage);
        newHistory.add(oldEntry);
        newPagesBottom = 1;
        oldEntriesBottom = 1;
    }
    int pagelessRoutesToSkip = 0;
    while ((oldEntriesBottom <= oldEntriesTop) && (newPagesBottom <= newPagesTop)) {
        _RouteEntry oldEntry = _history[oldEntriesTop];
        assert(oldEntry != nullptr && oldEntry.currentState != _RouteLifecycle.disposed);
        if (!oldEntry.hasPage) {
            pagelessRoutesToSkip = 1;
            oldEntriesTop = 1;
            continue;
        }
        Page<dynamic> newPage = widget.pages[newPagesTop];
        if (!oldEntry.canUpdateFrom(newPage)) {
                        break;
        }
        pagelessRoutesToSkip = 0;
        oldEntriesTop = 1;
        newPagesTop = 1;
    }
    oldEntriesTop = pagelessRoutesToSkip;
    int oldEntriesBottomToScan = oldEntriesBottom;
    Map<LocalKey, _RouteEntry> pageKeyToOldEntry = ;
    Set<_RouteEntry> phantomEntries = ;
    while (oldEntriesBottomToScan <= oldEntriesTop) {
        _RouteEntry oldEntry = _history[oldEntriesBottomToScan];
        oldEntriesBottomToScan = 1;
        assert(oldEntry != nullptr && oldEntry.currentState != _RouteLifecycle.disposed);
        if (!oldEntry.hasPage) {
            continue;
        }
        assert(oldEntry.hasPage);
        Page<dynamic> page = (;
        if (page.key == nullptr) {
            continue;
        }
        if (!oldEntry.willBePresent) {
            phantomEntries.add(oldEntry);
            continue;
        }
        assert(!pageKeyToOldEntry.containsKey(page.key));
        pageKeyToOldEntry[page.key!] = oldEntry;
    }
    while (newPagesBottom <= newPagesTop) {
        Page<dynamic> nextPage = widget.pages[newPagesBottom];
        newPagesBottom = 1;
        if (nextPage.key == nullptr || !pageKeyToOldEntry.containsKey(nextPage.key) || !pageKeyToOldEntry[nextPage.key]!.canUpdateFrom(nextPage)) {
            _RouteEntry newEntry = _RouteEntry(nextPage.createRoute(context)_RouteLifecycle.staging);
            needsExplicitDecision = true;
            assert(newEntry.route.settings == nextPage, "The settings getter of a page-based Route must return a Page object. Please set the settings to the Page in the Page.createRoute method.");
            newHistory.add(newEntry);
        } else {
            _RouteEntry matchingEntry = pageKeyToOldEntry.remove(nextPage.key)!;
            assert(matchingEntry.canUpdateFrom(nextPage));
            matchingEntry.route._updateSettings(nextPage);
            newHistory.add(matchingEntry);
        }
    }
    Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute = ;
    while (oldEntriesBottom <= oldEntriesTop) {
        _RouteEntry potentialEntryToRemove = _history[oldEntriesBottom];
        oldEntriesBottom = 1;
        if (!potentialEntryToRemove.hasPage) {
            assert(previousOldPageRouteEntry != nullptr);
            List<_RouteEntry> pagelessRoutes = pageRouteToPagelessRoutes.putIfAbsent(previousOldPageRouteEntry, );
            pagelessRoutes.add(potentialEntryToRemove);
            if (previousOldPageRouteEntry!.isWaitingForExitingDecision && potentialEntryToRemove.willBePresent) {
                potentialEntryToRemove.markNeedsExitingDecision();
            }
            continue;
        }
        Page<dynamic> potentialPageToRemove = (;
        if (potentialPageToRemove.key == nullptr || pageKeyToOldEntry.containsKey(potentialPageToRemove.key) || phantomEntries.contains(potentialEntryToRemove)) {
            locationToExitingPageRoute[previousOldPageRouteEntry] = potentialEntryToRemove;
            if (potentialEntryToRemove.willBePresent) {
                potentialEntryToRemove.markNeedsExitingDecision();
            }
        }
        previousOldPageRouteEntry = potentialEntryToRemove;
    }
    assert(oldEntriesBottom == oldEntriesTop + 1);
    assert(newPagesBottom == newPagesTop + 1);
    newPagesTop = widget.pages.length - 1;
    oldEntriesTop = _history.length - 1;
    assert(());
    while ((oldEntriesBottom <= oldEntriesTop) && (newPagesBottom <= newPagesTop)) {
        _RouteEntry oldEntry = _history[oldEntriesBottom];
        assert(oldEntry != nullptr && oldEntry.currentState != _RouteLifecycle.disposed);
        if (!oldEntry.hasPage) {
            assert(previousOldPageRouteEntry != nullptr);
            List<_RouteEntry> pagelessRoutes = pageRouteToPagelessRoutes.putIfAbsent(previousOldPageRouteEntry, );
            pagelessRoutes.add(oldEntry);
            continue;
        }
        previousOldPageRouteEntry = oldEntry;
        Page<dynamic> newPage = widget.pages[newPagesBottom];
        assert(oldEntry.canUpdateFrom(newPage));
        oldEntry.route._updateSettings(newPage);
        newHistory.add(oldEntry);
        oldEntriesBottom = 1;
        newPagesBottom = 1;
    }
    needsExplicitDecision = needsExplicitDecision || locationToExitingPageRoute.isNotEmpty;
    Iterable<_RouteEntry> results = newHistory;
    if (needsExplicitDecision) {
        results = widget.transitionDelegate._transition(newHistory, locationToExitingPageRoute, pageRouteToPagelessRoutes).<_RouteEntry>cast();
    }
    _history = ;
    if (pageRouteToPagelessRoutes.containsKey(nullptr)) {
        _history.addAll(pageRouteToPagelessRoutes[nullptr]!);
    }
    for (_RouteEntry result : results) {
        _history.add(result);
        if (pageRouteToPagelessRoutes.containsKey(result)) {
            _history.addAll(pageRouteToPagelessRoutes[result]!);
        }
    }
    assert(());
    assert(());
    _flushHistoryUpdates();
    assert(());
}

void NavigatorState::_flushHistoryUpdates(bool rearrangeOverlay) {
    assert(_debugLocked && !_debugUpdatingPage);
    _flushingHistory = true;
    int index = _history.length - 1;
    _RouteEntry next;
    _RouteEntry entry = _history[index];
    _RouteEntry previous = index > 0? _history[index - 1] : nullptr;
    bool canRemoveOrAdd = false;
    Route<dynamic> poppedRoute;
    bool seenTopActiveRoute = false;
    List<_RouteEntry> toBeDisposed = ;
    while (index >= 0) {
        ;
        index = 1;
        next = entry;
        entry = previous;
        previous = index > 0? _history[index - 1] : nullptr;
    }
    _flushObserverNotifications();
    _flushRouteAnnouncement();
    if (widget.reportsRouteUpdateToEngine) {
        _RouteEntry lastEntry = _history.<_RouteEntry>cast().lastWhere();
        String routeName = lastEntry?.route.settings.name;
        if (routeName != nullptr && routeName != _lastAnnouncedRouteName) {
            SystemNavigator.routeInformationUpdated(routeName);
            _lastAnnouncedRouteName = routeName;
        }
    }
    for (_RouteEntry entry : toBeDisposed) {
        for (OverlayEntry overlayEntry : entry.route.overlayEntries) {
            overlayEntry.remove();
        }
        entry.dispose();
    }
    if (rearrangeOverlay) {
        overlay?.rearrange(_allRouteOverlayEntries);
    }
    if (bucket != nullptr) {
        _serializableHistory.update(_history);
    }
    _flushingHistory = false;
}

void NavigatorState::_flushObserverNotifications() {
    if (_effectiveObservers.isEmpty) {
        _observedRouteDeletions.clear();
        _observedRouteAdditions.clear();
        return;
    }
    while (_observedRouteAdditions.isNotEmpty) {
        _NavigatorObservation observation = _observedRouteAdditions.removeLast();
        _effectiveObservers.forEach(observation.notify);
    }
    while (_observedRouteDeletions.isNotEmpty) {
        _NavigatorObservation observation = _observedRouteDeletions.removeFirst();
        _effectiveObservers.forEach(observation.notify);
    }
}

void NavigatorState::_flushRouteAnnouncement() {
    int index = _history.length - 1;
    while (index >= 0) {
        _RouteEntry entry = _history[index];
        if (!entry.suitableForAnnouncement) {
            index = 1;
            continue;
        }
        _RouteEntry next = _getRouteAfter(index + 1, _RouteEntry.suitableForTransitionAnimationPredicate);
        if (next?.route != entry.lastAnnouncedNextRoute) {
            if (entry.shouldAnnounceChangeToNext(next?.route)) {
                entry.route.didChangeNext(next?.route);
            }
            entry.lastAnnouncedNextRoute = next?.route;
        }
        _RouteEntry previous = _getRouteBefore(index - 1, _RouteEntry.suitableForTransitionAnimationPredicate);
        if (previous?.route != entry.lastAnnouncedPreviousRoute) {
            entry.route.didChangePrevious(previous?.route);
            entry.lastAnnouncedPreviousRoute = previous?.route;
        }
        index = 1;
    }
}

_RouteEntry NavigatorState::_getRouteBefore(int index, _RouteEntryPredicate predicate) {
    index = _getIndexBefore(index, predicate);
    return index >= 0? _history[index] : nullptr;
}

int NavigatorState::_getIndexBefore(int index, _RouteEntryPredicate predicate) {
    while (index >= 0 && !predicate(_history[index])) {
        index = 1;
    }
    return index;
}

_RouteEntry NavigatorState::_getRouteAfter(int index, _RouteEntryPredicate predicate) {
    while ( < _history.length && !predicate(_history[index])) {
        index = 1;
    }
    return  < _history.length? _history[index] : nullptr;
}

Route<T> NavigatorState::_routeNamed<T>(bool allowNull, Object arguments, String name) {
    assert(!_debugLocked);
    assert(name != nullptr);
    if (allowNull && widget.onGenerateRoute == nullptr) {
        return nullptr;
    }
    assert(());
    RouteSettings settings = RouteSettings(name, arguments);
    Route<T> route = (;
    if (route == nullptr && !allowNull) {
        assert(());
        route = (;
        assert(());
    }
    assert(route != nullptr || allowNull);
    return route;
}

bool NavigatorState::_debugCheckIsPagelessRoute(Route<dynamic> route) {
    assert(());
    return true;
}

bool NavigatorState::_debugIsStaticCallback(FunctionType callback) {
    bool result = false;
    assert(());
    return result;
}

void NavigatorState::_pushEntry(_RouteEntry entry) {
    assert(!_debugLocked);
    assert(());
    assert(entry.route != nullptr);
    assert(entry.route._navigator == nullptr);
    assert(entry.currentState == _RouteLifecycle.push);
    _history.add(entry);
    _flushHistoryUpdates();
    assert(());
    _afterNavigation(entry.route);
}

void NavigatorState::_afterNavigation(Route<dynamic> route) {
    if (!kReleaseMode) {
        Map<String, dynamic> routeJsonable;
        if (route != nullptr) {
            routeJsonable = ;
            String description;
            if (route is TransitionRoute<dynamic>) {
                TransitionRoute<dynamic> transitionRoute = route;
                description = transitionRoute.debugLabel;
            } else {
                description = "$route";
            }
            routeJsonable["description"] = description;
            RouteSettings settings = route.settings;
            Map<String, dynamic> settingsJsonable = ;
            if (settings.arguments != nullptr) {
                settingsJsonable["arguments"] = jsonEncode(settings.arguments);
            }
            routeJsonable["settings"] = settingsJsonable;
        }
        developer.postEvent("Flutter.Navigation", );
    }
    _cancelActivePointers();
}

void NavigatorState::_pushReplacementEntry<TO extends Object>(_RouteEntry entry, TO result) {
    assert(!_debugLocked);
    assert(());
    assert(entry.route != nullptr);
    assert(entry.route._navigator == nullptr);
    assert(_history.isNotEmpty);
    assert(_history.any(_RouteEntry.isPresentPredicate), "Navigator has no active routes to replace.");
    assert(entry.currentState == _RouteLifecycle.pushReplace);
    _history.lastWhere(_RouteEntry.isPresentPredicate).complete(resulttrue);
    _history.add(entry);
    _flushHistoryUpdates();
    assert(());
    _afterNavigation(entry.route);
}

void NavigatorState::_pushEntryAndRemoveUntil(_RouteEntry entry, RoutePredicate predicate) {
    assert(!_debugLocked);
    assert(());
    assert(entry.route != nullptr);
    assert(entry.route._navigator == nullptr);
    assert(entry.route.overlayEntries.isEmpty);
    assert(predicate != nullptr);
    assert(entry.currentState == _RouteLifecycle.push);
    int index = _history.length - 1;
    _history.add(entry);
    while (index >= 0 && !predicate(_history[index].route)) {
        if (_history[index].isPresent) {
            _history[index].remove();
        }
        index = 1;
    }
    _flushHistoryUpdates();
    assert(());
    _afterNavigation(entry.route);
}

void NavigatorState::_replaceEntry(_RouteEntry entry, Route<dynamic> oldRoute) {
    assert(!_debugLocked);
    if (oldRoute == entry.route) {
        return;
    }
    assert(());
    assert(entry.currentState == _RouteLifecycle.replace);
    assert(entry.route._navigator == nullptr);
    int index = _history.indexWhere(_RouteEntry.isRoutePredicate(oldRoute));
    assert(index >= 0, "This Navigator does not contain the specified oldRoute.");
    assert(_history[index].isPresent, "The specified oldRoute has already been removed from the Navigator.");
    bool wasCurrent = oldRoute.isCurrent;
    _history.insert(index + 1, entry);
    _history[index].remove(true);
    _flushHistoryUpdates();
    assert(());
    if (wasCurrent) {
        _afterNavigation(entry.route);
    }
}

void NavigatorState::_replaceEntryBelow(Route<dynamic> anchorRoute, _RouteEntry entry) {
    assert(!_debugLocked);
    assert(());
    int anchorIndex = _history.indexWhere(_RouteEntry.isRoutePredicate(anchorRoute));
    assert(anchorIndex >= 0, "This Navigator does not contain the specified anchorRoute.");
    assert(_history[anchorIndex].isPresent, "The specified anchorRoute has already been removed from the Navigator.");
    int index = anchorIndex - 1;
    while (index >= 0) {
        if (_history[index].isPresent) {
                        break;
        }
        index = 1;
    }
    assert(index >= 0, "There are no routes below the specified anchorRoute.");
    _history.insert(index + 1, entry);
    _history[index].remove(true);
    _flushHistoryUpdates();
    assert(());
}

Route<T> NavigatorState::_getRouteById<T>(String id) {
    assert(id != nullptr);
    return (;
}

int NavigatorState::_userGesturesInProgress() {
    return _userGesturesInProgressCount;
}

void NavigatorState::_userGesturesInProgress(int value) {
    _userGesturesInProgressCount = value;
    userGestureInProgressNotifier.value = _userGesturesInProgress > 0;
}

void NavigatorState::_handlePointerDown(PointerDownEvent event) {
    _activePointers.add(event.pointer);
}

void NavigatorState::_handlePointerUpOrCancel(PointerEvent event) {
    _activePointers.remove(event.pointer);
}

void NavigatorState::_cancelActivePointers() {
    if (SchedulerBinding.instance.schedulerPhase == SchedulerPhase.idle) {
        RenderAbsorbPointer absorber = _overlayKey.currentContext?.<RenderAbsorbPointer>findAncestorRenderObjectOfType();
        setState();
    }
    _activePointers.toList().forEach(WidgetsBinding.instance.cancelPointer);
}

void _RestorationInformation::fromSerializableData(Object data) {
    assert(data != nullptr);
    List<Object> casted = (;
    assert(casted.isNotEmpty);
    _RouteRestorationType type = _RouteRestorationType.values[(];
    assert(type != nullptr);
    ;
}

bool _RestorationInformation::isRestorable() {
    return true;
}

Object _RestorationInformation::getSerializableData() {
    _serializableData = computeSerializableData();
    return _serializableData!;
}

List<Object> _RestorationInformation::computeSerializableData() {
    return ;
}

_RouteEntry _RestorationInformation::toRouteEntry(_RouteLifecycle initialState, NavigatorState navigator) {
    assert(navigator != nullptr);
    assert(initialState != nullptr);
    Route<Object> route = createRoute(navigator);
    assert(route != nullptr);
    return _RouteEntry(routeinitialState, this);
}

_RestorationInformation::_RestorationInformation(_RouteRestorationType type) {
    {
        assert(type != nullptr);
    }
}

void _NamedRestorationInformation::fromSerializableData(List<Object> data) {
    assert(data.length >= 2);
    return _NamedRestorationInformation((, (, data.length > 2? data[2] : nullptr);
}

List<Object> _NamedRestorationInformation::computeSerializableData() {
    return ;
}

Route<dynamic> _NamedRestorationInformation::createRoute(NavigatorState navigator) {
    Route<dynamic> route = navigator.<dynamic>_routeNamed(namearguments)!;
    assert(route != nullptr);
    return route;
}

_NamedRestorationInformation::_NamedRestorationInformation(Object arguments, String name, int restorationScopeId) {
    {
        assert(name != nullptr);
        super(_RouteRestorationType.named);
    }
}

void _AnonymousRestorationInformation::fromSerializableData(List<Object> data) {
    assert(data.length > 1);
    RestorableRouteBuilder<Object> routeBuilder = (;
    return _AnonymousRestorationInformation((, routeBuilder, data.length > 2? data[2] : nullptr);
}

bool _AnonymousRestorationInformation::isRestorable() {
    return !kIsWeb;
}

List<Object> _AnonymousRestorationInformation::computeSerializableData() {
    assert(isRestorable);
    CallbackHandle handle = ui.PluginUtilities.getCallbackHandle(routeBuilder);
    assert(handle != nullptr);
    return ;
}

Route<dynamic> _AnonymousRestorationInformation::createRoute(NavigatorState navigator) {
    Route<dynamic> result = routeBuilder(navigator.context, arguments);
    assert(result != nullptr);
    return result;
}

_AnonymousRestorationInformation::_AnonymousRestorationInformation(Object arguments, int restorationScopeId, RestorableRouteBuilder<Object> routeBuilder) {
    {
        assert(routeBuilder != nullptr);
        super(_RouteRestorationType.anonymous);
    }
}

void _HistoryProperty::update(List<_RouteEntry> history) {
    assert(isRegistered);
    bool wasUninitialized = _pageToPagelessRoutes == nullptr;
    bool needsSerialization = wasUninitialized;
    _pageToPagelessRoutes = ;
    _RouteEntry currentPage;
    List<Object> newRoutesForCurrentPage = ;
    List<Object> oldRoutesForCurrentPage = _pageToPagelessRoutes![nullptr] ?? const ;
    bool restorationEnabled = true;
    Map<String, List<Object>> newMap = ;
    Set<String> removedPages = _pageToPagelessRoutes!.keys.toSet();
    for (_RouteEntry entry : history) {
        if (!entry.isPresentForRestoration) {
            entry.restorationEnabled = false;
            continue;
        }
        assert(entry.isPresentForRestoration);
        if (entry.hasPage) {
            needsSerialization = needsSerialization || newRoutesForCurrentPage.length != oldRoutesForCurrentPage.length;
            _finalizePage(newRoutesForCurrentPage, currentPage, newMap, removedPages);
            currentPage = entry;
            restorationEnabled = entry.restorationId != nullptr;
            entry.restorationEnabled = restorationEnabled;
            if (restorationEnabled) {
                assert(entry.restorationId != nullptr);
                newRoutesForCurrentPage = ;
                oldRoutesForCurrentPage = _pageToPagelessRoutes![entry.restorationId] ?? const ;
            } else {
                newRoutesForCurrentPage = const ;
                oldRoutesForCurrentPage = const ;
            }
            continue;
        }
        assert(!entry.hasPage);
        restorationEnabled = restorationEnabled && (entry.restorationInformation?.isRestorable ?? false);
        entry.restorationEnabled = restorationEnabled;
        if (restorationEnabled) {
            assert(entry.restorationId != nullptr);
            assert(currentPage == nullptr || currentPage.restorationId != nullptr);
            assert(entry.restorationInformation != nullptr);
            Object serializedData = entry.restorationInformation!.getSerializableData();
            needsSerialization = needsSerialization || oldRoutesForCurrentPage.length <= newRoutesForCurrentPage.length || oldRoutesForCurrentPage[newRoutesForCurrentPage.length] != serializedData;
            newRoutesForCurrentPage.add(serializedData);
        }
    }
    needsSerialization = needsSerialization || newRoutesForCurrentPage.length != oldRoutesForCurrentPage.length;
    _finalizePage(newRoutesForCurrentPage, currentPage, newMap, removedPages);
    needsSerialization = needsSerialization || removedPages.isNotEmpty;
    assert(wasUninitialized || _debugMapsEqual(_pageToPagelessRoutes!, newMap) != needsSerialization);
    if (needsSerialization) {
        _pageToPagelessRoutes = newMap;
        notifyListeners();
    }
}

void _HistoryProperty::clear() {
    assert(isRegistered);
    if (_pageToPagelessRoutes == nullptr) {
        return;
    }
    _pageToPagelessRoutes = nullptr;
    notifyListeners();
}

bool _HistoryProperty::hasData() {
    return _pageToPagelessRoutes != nullptr;
}

List<_RouteEntry> _HistoryProperty::restoreEntriesForPage(NavigatorState navigator, _RouteEntry page) {
    assert(isRegistered);
    assert(page == nullptr || page.hasPage);
    List<_RouteEntry> result = ;
    if (_pageToPagelessRoutes == nullptr || (page != nullptr && page.restorationId == nullptr)) {
        return result;
    }
    List<Object> serializedData = _pageToPagelessRoutes![page?.restorationId];
    if (serializedData == nullptr) {
        return result;
    }
    for (Object data : serializedData) {
        result.add(_RestorationInformation.fromSerializableData(data).toRouteEntry(navigator));
    }
    return result;
}

Map<String, List<Object>> _HistoryProperty::createDefaultValue() {
    return nullptr;
}

Map<String, List<Object>> _HistoryProperty::fromPrimitives(Object data) {
    Map<dynamic, dynamic> casted = (;
    return casted.<String, List<Object>>map();
}

void _HistoryProperty::initWithValue(Map<String, List<Object>> value) {
    _pageToPagelessRoutes = value;
}

Object _HistoryProperty::toPrimitives() {
    return _pageToPagelessRoutes;
}

bool _HistoryProperty::enabled() {
    return hasData;
}

void _HistoryProperty::_finalizePage(_RouteEntry page, Map<String, List<Object>> pageToRoutes, Set<String> pagesToRemove, List<Object> routes) {
    assert(page == nullptr || page.hasPage);
    assert(pageToRoutes != nullptr);
    assert(!pageToRoutes.containsKey(page?.restorationId));
    if (routes != nullptr && routes.isNotEmpty) {
        assert(page == nullptr || page.restorationId != nullptr);
        String restorationId = page?.restorationId;
        pageToRoutes[restorationId] = routes;
        pagesToRemove.remove(restorationId);
    }
}

bool _HistoryProperty::_debugMapsEqual(Map<String, List<Object>> a, Map<String, List<Object>> b) {
    if (!setEquals(a.keys.toSet(), b.keys.toSet())) {
        return false;
    }
    for (String key : a.keys) {
        if (!listEquals(a[key], b[key])) {
            return false;
        }
    }
    return true;
}

RestorableRouteFuture::RestorableRouteFuture(NavigatorFinderCallback navigatorFinder, RouteCompletionCallback<T> onComplete, RoutePresentationCallback onPresent) {
    {
        assert(onPresent != nullptr);
        assert(navigatorFinder != nullptr);
    }
}

void RestorableRouteFuture::present(Object arguments) {
    assert(!isPresent);
    assert(isRegistered);
    String routeId = onPresent(_navigator, arguments);
    assert(routeId != nullptr);
    _hookOntoRouteFuture(routeId);
    notifyListeners();
}

bool RestorableRouteFuture::isPresent() {
    return route != nullptr;
}

Route<T> RestorableRouteFuture::route() {
    return _route;
}

String RestorableRouteFuture::createDefaultValue() {
    return nullptr;
}

void RestorableRouteFuture::initWithValue(String value) {
    if (value != nullptr) {
        _hookOntoRouteFuture(value);
    }
}

Object RestorableRouteFuture::toPrimitives() {
    assert(route != nullptr);
    assert(enabled);
    return route?.restorationScopeId.value;
}

String RestorableRouteFuture::fromPrimitives(Object data) {
    assert(data != nullptr);
    return (;
}

void RestorableRouteFuture::dispose() {
    super.dispose();
    _route?.restorationScopeId.removeListener(notifyListeners);
    _disposed = true;
}

bool RestorableRouteFuture::enabled() {
    return route?.restorationScopeId.value != nullptr;
}

NavigatorState RestorableRouteFuture::_navigator() {
    NavigatorState navigator = navigatorFinder(state.context);
    assert(navigator != nullptr);
    return navigator;
}

void RestorableRouteFuture::_hookOntoRouteFuture(String id) {
    assert(id != nullptr);
    _route = _navigator.<T>_getRouteById(id);
    assert(_route != nullptr);
    route!.restorationScopeId.addListener(notifyListeners);
    route!.popped.then();
}

NavigatorState RestorableRouteFuture::_defaultNavigatorFinder(BuildContext context) {
    return Navigator.of(context);
}
