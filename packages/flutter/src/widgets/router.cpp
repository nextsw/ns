#include "router.hpp"
RouterConfig::RouterConfig(BackButtonDispatcher backButtonDispatcher, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate) {
    {
        assert((routeInformationProvider == nullptr) == (routeInformationParser == nullptr));
    }
}

Router::Router(BackButtonDispatcher backButtonDispatcher, Unknown, String restorationScopeId, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate) {
    {
        assert(routeInformationProvider == nullptr || routeInformationParser != nullptr, "A routeInformationParser must be provided when a routeInformationProvider is specified.");
        assert(routerDelegate != nullptr);
    }
}

void Router::withConfig(RouterConfig<T> config, Key key, String restorationScopeId) {
    return <T>Router(key, config.routeInformationProvider, config.routeInformationParser, config.routerDelegate, config.backButtonDispatcher, restorationScopeId);
}

Router<T> Router::of<T extends Object>(BuildContext context) {
    _RouterScope scope = context.<_RouterScope>dependOnInheritedWidgetOfExactType();
    assert(());
    return (;
}

Router<T> Router::maybeOf<T extends Object>(BuildContext context) {
    _RouterScope scope = context.<_RouterScope>dependOnInheritedWidgetOfExactType();
    return (;
}

void Router::navigate(VoidCallback callback, BuildContext context) {
    _RouterScope scope = (;
    scope.routerState._setStateWithExplicitReportStatus(RouteInformationReportingType.navigate, callback);
}

void Router::neglect(VoidCallback callback, BuildContext context) {
    _RouterScope scope = (;
    scope.routerState._setStateWithExplicitReportStatus(RouteInformationReportingType.neglect, callback);
}

State<Router<T>> Router::createState() {
    return <T>_RouterState();
}

String _RouterState::restorationId() {
    return widget.restorationScopeId;
}

void _RouterState::initState() {
    super.initState();
    widget.routeInformationProvider?.addListener(_handleRouteInformationProviderNotification);
    widget.backButtonDispatcher?.addCallback(_handleBackButtonDispatcherNotification);
    widget.routerDelegate.addListener(_handleRouterDelegateNotification);
}

void _RouterState::restoreState(bool initialRestore, RestorationBucket oldBucket) {
    registerForRestoration(_routeInformation, "route");
    if (_routeInformation.value != nullptr) {
        assert(widget.routeInformationParser != nullptr);
        _processRouteInformation(_routeInformation.value!, );
    } else     {
        if (widget.routeInformationProvider != nullptr) {
        _processRouteInformation(widget.routeInformationProvider!.value, );
    }
;
    }}

void _RouterState::didChangeDependencies() {
    _routeParsePending = true;
    super.didChangeDependencies();
    if (widget.routeInformationProvider != nullptr && _routeParsePending) {
        _processRouteInformation(widget.routeInformationProvider!.value, );
    }
    _routeParsePending = false;
    _maybeNeedToReportRouteInformation();
}

void _RouterState::didUpdateWidget(Router<T> oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.routeInformationProvider != oldWidget.routeInformationProvider || widget.backButtonDispatcher != oldWidget.backButtonDispatcher || widget.routeInformationParser != oldWidget.routeInformationParser || widget.routerDelegate != oldWidget.routerDelegate) {
        _currentRouterTransaction = Object();
    }
    if (widget.routeInformationProvider != oldWidget.routeInformationProvider) {
        oldWidget.routeInformationProvider?.removeListener(_handleRouteInformationProviderNotification);
        widget.routeInformationProvider?.addListener(_handleRouteInformationProviderNotification);
        if (oldWidget.routeInformationProvider?.value != widget.routeInformationProvider?.value) {
            _handleRouteInformationProviderNotification();
        }
    }
    if (widget.backButtonDispatcher != oldWidget.backButtonDispatcher) {
        oldWidget.backButtonDispatcher?.removeCallback(_handleBackButtonDispatcherNotification);
        widget.backButtonDispatcher?.addCallback(_handleBackButtonDispatcherNotification);
    }
    if (widget.routerDelegate != oldWidget.routerDelegate) {
        oldWidget.routerDelegate.removeListener(_handleRouterDelegateNotification);
        widget.routerDelegate.addListener(_handleRouterDelegateNotification);
        _maybeNeedToReportRouteInformation();
    }
}

void _RouterState::dispose() {
    widget.routeInformationProvider?.removeListener(_handleRouteInformationProviderNotification);
    widget.backButtonDispatcher?.removeCallback(_handleBackButtonDispatcherNotification);
    widget.routerDelegate.removeListener(_handleRouterDelegateNotification);
    _currentRouterTransaction = nullptr;
    super.dispose();
}

Widget _RouterState::build(BuildContext context) {
    return UnmanagedRestorationScope(bucket, _RouterScope(widget.routeInformationProvider, widget.backButtonDispatcher, widget.routeInformationParser, widget.routerDelegate, this, Builder(widget.routerDelegate.build)));
}

void _RouterState::_scheduleRouteInformationReportingTask() {
    if (_routeInformationReportingTaskScheduled || widget.routeInformationProvider == nullptr) {
        return;
    }
    assert(_currentIntentionToReport != nullptr);
    _routeInformationReportingTaskScheduled = true;
    SchedulerBinding.instance.addPostFrameCallback(_reportRouteInformation);
}

void _RouterState::_reportRouteInformation(Duration timestamp) {
    assert(_routeInformationReportingTaskScheduled);
    _routeInformationReportingTaskScheduled = false;
    if (_routeInformation.value != nullptr) {
        RouteInformation currentRouteInformation = _routeInformation.value!;
        assert(_currentIntentionToReport != nullptr);
        widget.routeInformationProvider!.routerReportsNewRouteInformation(currentRouteInformation_currentIntentionToReport!);
    }
    _currentIntentionToReport = RouteInformationReportingType.none;
}

RouteInformation _RouterState::_retrieveNewRouteInformation() {
    T configuration = widget.routerDelegate.currentConfiguration;
    if (configuration == nullptr) {
        return nullptr;
    }
    return widget.routeInformationParser?.restoreRouteInformation(configuration);
}

void _RouterState::_setStateWithExplicitReportStatus(VoidCallback fn, RouteInformationReportingType status) {
    assert(status != nullptr);
    assert(status.index >= RouteInformationReportingType.neglect.index);
    assert(());
    _currentIntentionToReport = status;
    _scheduleRouteInformationReportingTask();
    fn();
}

void _RouterState::_maybeNeedToReportRouteInformation() {
    _routeInformation.value = _retrieveNewRouteInformation();
    _currentIntentionToReport = RouteInformationReportingType.none;
    _scheduleRouteInformationReportingTask();
}

void _RouterState::_processRouteInformation(ValueGetter<_RouteSetter<T>> delegateRouteSetter, RouteInformation information) {
    assert(_routeParsePending);
    _routeParsePending = false;
    _currentRouterTransaction = Object();
    widget.routeInformationParser!.parseRouteInformationWithDependencies(information, context).<void>then(_processParsedRouteInformation(_currentRouterTransaction, delegateRouteSetter));
}

_RouteSetter<T> _RouterState::_processParsedRouteInformation(ValueGetter<_RouteSetter<T>> delegateRouteSetter, Object transaction) {
    return ;
}

void _RouterState::_handleRouteInformationProviderNotification() {
    assert(widget.routeInformationProvider!.value != nullptr);
    _routeParsePending = true;
    _processRouteInformation(widget.routeInformationProvider!.value, );
}

Future<bool> _RouterState::_handleBackButtonDispatcherNotification() {
    _currentRouterTransaction = Object();
    return widget.routerDelegate.popRoute().<bool>then(_handleRoutePopped(_currentRouterTransaction));
}

_AsyncPassthrough<bool> _RouterState::_handleRoutePopped(Object transaction) {
    return ;
}

Future<void> _RouterState::_rebuild(void value) {
    setState();
    _maybeNeedToReportRouteInformation();
    return <void>SynchronousFuture(value);
}

void _RouterState::_handleRouterDelegateNotification() {
    setState();
    _maybeNeedToReportRouteInformation();
}

bool _RouterScope::updateShouldNotify(_RouterScope oldWidget) {
    return routeInformationProvider != oldWidget.routeInformationProvider || backButtonDispatcher != oldWidget.backButtonDispatcher || routeInformationParser != oldWidget.routeInformationParser || routerDelegate != oldWidget.routerDelegate || routerState != oldWidget.routerState;
}

_RouterScope::_RouterScope(BackButtonDispatcher backButtonDispatcher, Unknown, RouteInformationParser<Object> routeInformationParser, ValueListenable<RouteInformation> routeInformationProvider, RouterDelegate<Object> routerDelegate, _RouterState<Object> routerState) {
    {
        assert(routeInformationProvider == nullptr || routeInformationParser != nullptr);
        assert(routerDelegate != nullptr);
        assert(routerState != nullptr);
    }
}

bool _CallbackHookProvider::hasCallbacks() {
    return _callbacks.isNotEmpty;
}

void _CallbackHookProvider::addCallback(ValueGetter<T> callback) {
    return _callbacks.add(callback);
}

void _CallbackHookProvider::removeCallback(ValueGetter<T> callback) {
    return _callbacks.remove(callback);
}

T _CallbackHookProvider::invokeCallback(T defaultValue) {
    if (_callbacks.isEmpty) {
        return defaultValue;
    }
    ;
}

bool BackButtonDispatcher::hasCallbacks() {
    return super.hasCallbacks || (_children.isNotEmpty);
}

Future<bool> BackButtonDispatcher::invokeCallback(Future<bool> defaultValue) {
    if (_children.isNotEmpty) {
        List<ChildBackButtonDispatcher> children = _children.toList();
        int childIndex = children.length - 1;
        ;
        return children[childIndex].notifiedByParent(defaultValue).<bool>then(notifyNextChild);
    }
    return super.invokeCallback(defaultValue);
}

ChildBackButtonDispatcher BackButtonDispatcher::createChildBackButtonDispatcher() {
    return ChildBackButtonDispatcher(this);
}

void BackButtonDispatcher::takePriority() {
    return _children.clear();
}

void BackButtonDispatcher::deferTo(ChildBackButtonDispatcher child) {
    assert(hasCallbacks);
    _children.remove(child);
    _children.add(child);
}

void BackButtonDispatcher::forget(ChildBackButtonDispatcher child) {
    return _children.remove(child);
}

void RootBackButtonDispatcher::addCallback(ValueGetter<Future<bool>> callback) {
    if (!hasCallbacks) {
        WidgetsBinding.instance.addObserver(this);
    }
    super.addCallback(callback);
}

void RootBackButtonDispatcher::removeCallback(ValueGetter<Future<bool>> callback) {
    super.removeCallback(callback);
    if (!hasCallbacks) {
        WidgetsBinding.instance.removeObserver(this);
    }
}

Future<bool> RootBackButtonDispatcher::didPopRoute() {
    return invokeCallback(<bool>value(false));
}

ChildBackButtonDispatcher::ChildBackButtonDispatcher(BackButtonDispatcher parent) {
    {
        assert(parent != nullptr);
    }
}

Future<bool> ChildBackButtonDispatcher::notifiedByParent(Future<bool> defaultValue) {
    return invokeCallback(defaultValue);
}

void ChildBackButtonDispatcher::takePriority() {
    parent.deferTo(this);
    super.takePriority();
}

void ChildBackButtonDispatcher::deferTo(ChildBackButtonDispatcher child) {
    assert(hasCallbacks);
    parent.deferTo(this);
    super.deferTo(child);
}

void ChildBackButtonDispatcher::removeCallback(ValueGetter<Future<bool>> callback) {
    super.removeCallback(callback);
    if (!hasCallbacks) {
        parent.forget(this);
    }
}

State<BackButtonListener> BackButtonListener::createState() {
    return _BackButtonListenerState();
}

void _BackButtonListenerState::didChangeDependencies() {
    dispatcher?.removeCallback(widget.onBackButtonPressed);
    BackButtonDispatcher rootBackDispatcher = Router.of(context).backButtonDispatcher;
    assert(rootBackDispatcher != nullptr, "The parent router must have a backButtonDispatcher to use this widget");
    dispatcher = ;
    super.didChangeDependencies();
}

void _BackButtonListenerState::didUpdateWidget(BackButtonListener oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.onBackButtonPressed != widget.onBackButtonPressed) {
        dispatcher?.removeCallback(oldWidget.onBackButtonPressed);
        dispatcher?.addCallback(widget.onBackButtonPressed);
        dispatcher?.takePriority();
    }
}

void _BackButtonListenerState::dispose() {
    dispatcher?.removeCallback(widget.onBackButtonPressed);
    super.dispose();
}

Widget _BackButtonListenerState::build(BuildContext context) {
    return widget.child;
}

Future<T> RouteInformationParser::parseRouteInformation(RouteInformation routeInformation) {
    ;
}

Future<T> RouteInformationParser::parseRouteInformationWithDependencies(BuildContext context, RouteInformation routeInformation) {
    return parseRouteInformation(routeInformation);
}

RouteInformation RouteInformationParser::restoreRouteInformation(T configuration) {
    return nullptr;
}

Future<void> RouterDelegate::setInitialRoutePath(T configuration) {
    return setNewRoutePath(configuration);
}

Future<void> RouterDelegate::setRestoredRoutePath(T configuration) {
    return setNewRoutePath(configuration);
}

T RouterDelegate::currentConfiguration() {
    return nullptr;
}

void RouteInformationProvider::routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type) {
}

PlatformRouteInformationProvider::PlatformRouteInformationProvider(RouteInformation initialRouteInformation) {
    {
        _value = initialRouteInformation;
    }
}

void PlatformRouteInformationProvider::routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type) {
    bool replace = type == RouteInformationReportingType.neglect || (type == RouteInformationReportingType.none && _valueInEngine.location == routeInformation.location);
    SystemNavigator.selectMultiEntryHistory();
    SystemNavigator.routeInformationUpdated(routeInformation.location!, routeInformation.state, replace);
    _value = routeInformation;
    _valueInEngine = routeInformation;
}

RouteInformation PlatformRouteInformationProvider::value() {
    return _value;
}

void PlatformRouteInformationProvider::addListener(VoidCallback listener) {
    if (!hasListeners) {
        WidgetsBinding.instance.addObserver(this);
    }
    super.addListener(listener);
}

void PlatformRouteInformationProvider::removeListener(VoidCallback listener) {
    super.removeListener(listener);
    if (!hasListeners) {
        WidgetsBinding.instance.removeObserver(this);
    }
}

void PlatformRouteInformationProvider::dispose() {
    if (hasListeners) {
        WidgetsBinding.instance.removeObserver(this);
    }
    super.dispose();
}

Future<bool> PlatformRouteInformationProvider::didPushRouteInformation(RouteInformation routeInformation) {
    assert(hasListeners);
    _platformReportsNewRouteInformation(routeInformation);
    return true;
}

Future<bool> PlatformRouteInformationProvider::didPushRoute(String route) {
    assert(hasListeners);
    _platformReportsNewRouteInformation(RouteInformation(route));
    return true;
}

void PlatformRouteInformationProvider::_platformReportsNewRouteInformation(RouteInformation routeInformation) {
    if (_value == routeInformation) {
        return;
    }
    _value = routeInformation;
    _valueInEngine = routeInformation;
    notifyListeners();
}

Future<bool> PopNavigatorRouterDelegateMixin::popRoute() {
    NavigatorState navigator = navigatorKey?.currentState;
    if (navigator == nullptr) {
        return <bool>SynchronousFuture(false);
    }
    return navigator.maybePop();
}

RouteInformation _RestorableRouteInformation::createDefaultValue() {
    return nullptr;
}

void _RestorableRouteInformation::didUpdateValue(RouteInformation oldValue) {
    notifyListeners();
}

RouteInformation _RestorableRouteInformation::fromPrimitives(Object data) {
    if (data == nullptr) {
        return nullptr;
    }
    assert(data is List<Object> && data.length == 2);
    List<Object> castedData = (;
    return RouteInformation((, castedData.last);
}

Object _RestorableRouteInformation::toPrimitives() {
    return value == nullptr? nullptr : ;
}
