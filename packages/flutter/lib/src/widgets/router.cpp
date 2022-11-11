#include "router.hpp"
template<typename T>
RouterConfigCls<T>::RouterConfigCls(BackButtonDispatcher backButtonDispatcher, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate) {
    {
        assert((routeInformationProvider == nullptr) == (routeInformationParser == nullptr));
    }
}

template<typename T>
RouterCls<T>::RouterCls(BackButtonDispatcher backButtonDispatcher, Key key, String restorationScopeId, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate) {
    {
        assert(routeInformationProvider == nullptr || routeInformationParser != nullptr, __s("A routeInformationParser must be provided when a routeInformationProvider is specified."));
        assert(routerDelegate != nullptr);
    }
}

template<typename T>
void RouterCls<T>::withConfig(RouterConfig<T> config, Key key, String restorationScopeId) {
    return <T>make<RouterCls>(key, config->routeInformationProvider, config->routeInformationParser, config->routerDelegate, config->backButtonDispatcher, restorationScopeId);
}

template<typename T>
template<typename T>
Router<T> RouterCls<T>::of(BuildContext context) {
    _RouterScope scope = context-><_RouterScope>dependOnInheritedWidgetOfExactType();
    assert([=] () {
        if (scope == nullptr) {
            throw make<FlutterErrorCls>(__s("Router operation requested with a context that does not include a Router.\nThe context used to retrieve the Router must be that of a widget that is a descendant of a Router widget."));
        }
        return true;
    }());
    return as<Router<T>>(scope!->routerState->widget());
}

template<typename T>
template<typename T>
Router<T> RouterCls<T>::maybeOf(BuildContext context) {
    _RouterScope scope = context-><_RouterScope>dependOnInheritedWidgetOfExactType();
    return as<Router<T>>(scope?->routerState->widget());
}

template<typename T>
void RouterCls<T>::navigate(BuildContext context, VoidCallback callback) {
    _RouterScope scope = as<_RouterScope>(context-><_RouterScope>getElementForInheritedWidgetOfExactType()!->widget());
    scope->routerState->_setStateWithExplicitReportStatus(RouteInformationReportingTypeCls::navigate, callback);
}

template<typename T>
void RouterCls<T>::neglect(BuildContext context, VoidCallback callback) {
    _RouterScope scope = as<_RouterScope>(context-><_RouterScope>getElementForInheritedWidgetOfExactType()!->widget());
    scope->routerState->_setStateWithExplicitReportStatus(RouteInformationReportingTypeCls::neglect, callback);
}

template<typename T>
State<Router<T>> RouterCls<T>::createState() {
    return <T>make<_RouterStateCls>();
}

template<typename T>
String _RouterStateCls<T>::restorationId() {
    return widget()->restorationScopeId;
}

template<typename T>
void _RouterStateCls<T>::initState() {
    super->initState();
    widget()->routeInformationProvider?->addListener(_handleRouteInformationProviderNotification);
    widget()->backButtonDispatcher?->addCallback(_handleBackButtonDispatcherNotification);
    widget()->routerDelegate->addListener(_handleRouterDelegateNotification);
}

template<typename T>
void _RouterStateCls<T>::restoreState(RestorationBucket oldBucket, bool initialRestore) {
    registerForRestoration(_routeInformation, __s("route"));
    if (_routeInformation->value() != nullptr) {
        assert(widget()->routeInformationParser != nullptr);
        _processRouteInformation(_routeInformation->value()!, [=] () {
            widget()->routerDelegate->setRestoredRoutePath;
        });
    } else {
        if (widget()->routeInformationProvider != nullptr) {
        _processRouteInformation(widget()->routeInformationProvider!->value, [=] () {
            widget()->routerDelegate->setInitialRoutePath;
        });
    }
;
    }}

template<typename T>
void _RouterStateCls<T>::didChangeDependencies() {
    _routeParsePending = true;
    super->didChangeDependencies();
    if (widget()->routeInformationProvider != nullptr && _routeParsePending) {
        _processRouteInformation(widget()->routeInformationProvider!->value, [=] () {
            widget()->routerDelegate->setNewRoutePath;
        });
    }
    _routeParsePending = false;
    _maybeNeedToReportRouteInformation();
}

template<typename T>
void _RouterStateCls<T>::didUpdateWidget(Router<T> oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->routeInformationProvider != oldWidget->routeInformationProvider || widget()->backButtonDispatcher != oldWidget->backButtonDispatcher || widget()->routeInformationParser != oldWidget->routeInformationParser || widget()->routerDelegate != oldWidget->routerDelegate) {
        _currentRouterTransaction = make<ObjectCls>();
    }
    if (widget()->routeInformationProvider != oldWidget->routeInformationProvider) {
        oldWidget->routeInformationProvider?->removeListener(_handleRouteInformationProviderNotification);
        widget()->routeInformationProvider?->addListener(_handleRouteInformationProviderNotification);
        if (oldWidget->routeInformationProvider?->value() != widget()->routeInformationProvider?->value) {
            _handleRouteInformationProviderNotification();
        }
    }
    if (widget()->backButtonDispatcher != oldWidget->backButtonDispatcher) {
        oldWidget->backButtonDispatcher?->removeCallback(_handleBackButtonDispatcherNotification);
        widget()->backButtonDispatcher?->addCallback(_handleBackButtonDispatcherNotification);
    }
    if (widget()->routerDelegate != oldWidget->routerDelegate) {
        oldWidget->routerDelegate->removeListener(_handleRouterDelegateNotification);
        widget()->routerDelegate->addListener(_handleRouterDelegateNotification);
        _maybeNeedToReportRouteInformation();
    }
}

template<typename T>
void _RouterStateCls<T>::dispose() {
    widget()->routeInformationProvider?->removeListener(_handleRouteInformationProviderNotification);
    widget()->backButtonDispatcher?->removeCallback(_handleBackButtonDispatcherNotification);
    widget()->routerDelegate->removeListener(_handleRouterDelegateNotification);
    _currentRouterTransaction = nullptr;
    super->dispose();
}

template<typename T>
Widget _RouterStateCls<T>::build(BuildContext context) {
    return make<UnmanagedRestorationScopeCls>(bucket, make<_RouterScopeCls>(widget()->routeInformationProvider, widget()->backButtonDispatcher, widget()->routeInformationParser, widget()->routerDelegate, this, make<BuilderCls>(widget()->routerDelegate->build)));
}

template<typename T>
void _RouterStateCls<T>::_scheduleRouteInformationReportingTask() {
    if (_routeInformationReportingTaskScheduled || widget()->routeInformationProvider == nullptr) {
        return;
    }
    assert(_currentIntentionToReport != nullptr);
    _routeInformationReportingTaskScheduled = true;
    SchedulerBindingCls::instance->addPostFrameCallback(_reportRouteInformation);
}

template<typename T>
void _RouterStateCls<T>::_reportRouteInformation(Duration timestamp) {
    assert(_routeInformationReportingTaskScheduled);
    _routeInformationReportingTaskScheduled = false;
    if (_routeInformation->value() != nullptr) {
        RouteInformation currentRouteInformation = _routeInformation->value()!;
        assert(_currentIntentionToReport != nullptr);
        widget()->routeInformationProvider!->routerReportsNewRouteInformation(currentRouteInformation, _currentIntentionToReport!);
    }
    _currentIntentionToReport = RouteInformationReportingTypeCls::none;
}

template<typename T>
RouteInformation _RouterStateCls<T>::_retrieveNewRouteInformation() {
    T configuration = widget()->routerDelegate->currentConfiguration;
    if (configuration == nullptr) {
        return nullptr;
    }
    return widget()->routeInformationParser?->restoreRouteInformation(configuration);
}

template<typename T>
void _RouterStateCls<T>::_setStateWithExplicitReportStatus(RouteInformationReportingType status, VoidCallback fn) {
    assert(status != nullptr);
    assert(status->index >= RouteInformationReportingTypeCls::neglect->index);
    assert([=] () {
        if (_currentIntentionToReport != nullptr && _currentIntentionToReport != RouteInformationReportingTypeCls::none && _currentIntentionToReport != status) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(__s("Both Router.navigate and Router.neglect have been called in this build cycle, and the Router cannot decide whether to report the route information. Please make sure only one of them is called within the same build cycle.")));
        }
        return true;
    }());
    _currentIntentionToReport = status;
    _scheduleRouteInformationReportingTask();
    fn();
}

template<typename T>
void _RouterStateCls<T>::_maybeNeedToReportRouteInformation() {
    _routeInformation->value() = _retrieveNewRouteInformation();
    _currentIntentionToReport |= RouteInformationReportingTypeCls::none;
    _scheduleRouteInformationReportingTask();
}

template<typename T>
void _RouterStateCls<T>::_processRouteInformation(RouteInformation information, ValueGetter<_RouteSetter<T>> delegateRouteSetter) {
    assert(_routeParsePending);
    _routeParsePending = false;
    _currentRouterTransaction = make<ObjectCls>();
    widget()->routeInformationParser!->parseRouteInformationWithDependencies(information, context())-><void>then(_processParsedRouteInformation(_currentRouterTransaction, delegateRouteSetter));
}

template<typename T>
_RouteSetter<T> _RouterStateCls<T>::_processParsedRouteInformation(Object transaction, ValueGetter<_RouteSetter<T>> delegateRouteSetter) {
    return [=] (T data) {
        if (_currentRouterTransaction != transaction) {
            return;
        }
        await await delegateRouteSetter()(data);
        if (_currentRouterTransaction == transaction) {
            _rebuild();
        }
    };
}

template<typename T>
void _RouterStateCls<T>::_handleRouteInformationProviderNotification() {
    assert(widget()->routeInformationProvider!->value != nullptr);
    _routeParsePending = true;
    _processRouteInformation(widget()->routeInformationProvider!->value, [=] () {
        widget()->routerDelegate->setNewRoutePath;
    });
}

template<typename T>
Future<bool> _RouterStateCls<T>::_handleBackButtonDispatcherNotification() {
    _currentRouterTransaction = make<ObjectCls>();
    return widget()->routerDelegate->popRoute()-><bool>then(_handleRoutePopped(_currentRouterTransaction));
}

template<typename T>
_AsyncPassthrough<bool> _RouterStateCls<T>::_handleRoutePopped(Object transaction) {
    return [=] (bool data) {
        if (transaction != _currentRouterTransaction) {
            return <bool>make<SynchronousFutureCls>(true);
        }
        _rebuild();
        return <bool>make<SynchronousFutureCls>(data);
    };
}

template<typename T>
Future<void> _RouterStateCls<T>::_rebuild(void value) {
    setState([=] () {
    });
    _maybeNeedToReportRouteInformation();
    return <void>make<SynchronousFutureCls>(value);
}

template<typename T>
void _RouterStateCls<T>::_handleRouterDelegateNotification() {
    setState([=] () {
    });
    _maybeNeedToReportRouteInformation();
}

bool _RouterScopeCls::updateShouldNotify(_RouterScope oldWidget) {
    return routeInformationProvider != oldWidget->routeInformationProvider || backButtonDispatcher != oldWidget->backButtonDispatcher || routeInformationParser != oldWidget->routeInformationParser || routerDelegate != oldWidget->routerDelegate || routerState != oldWidget->routerState;
}

_RouterScopeCls::_RouterScopeCls(BackButtonDispatcher backButtonDispatcher, Widget child, RouteInformationParser<Object> routeInformationParser, ValueListenable<RouteInformation> routeInformationProvider, RouterDelegate<Object> routerDelegate, _RouterState<Object> routerState) {
    {
        assert(routeInformationProvider == nullptr || routeInformationParser != nullptr);
        assert(routerDelegate != nullptr);
        assert(routerState != nullptr);
    }
}

template<typename T>
bool _CallbackHookProviderCls<T>::hasCallbacks() {
    return _callbacks->isNotEmpty();
}

template<typename T>
void _CallbackHookProviderCls<T>::addCallback(ValueGetter<T> callback) {
    return _callbacks->add(callback);
}

template<typename T>
void _CallbackHookProviderCls<T>::removeCallback(ValueGetter<T> callback) {
    return _callbacks->remove(callback);
}

template<typename T>
T _CallbackHookProviderCls<T>::invokeCallback(T defaultValue) {
    if (_callbacks->isEmpty()) {
        return defaultValue;
    }
    try {
        return _callbacks->single();
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widget library"), make<ErrorDescriptionCls>(__s("while invoking the callback for $runtimeType")), [=] () {
            makeList(ArrayItem);
        }));
        return defaultValue;
    };
}

bool BackButtonDispatcherCls::hasCallbacks() {
    return super->hasCallbacks || (_children->isNotEmpty());
}

Future<bool> BackButtonDispatcherCls::invokeCallback(Future<bool> defaultValue) {
    if (_children->isNotEmpty()) {
        List<ChildBackButtonDispatcher> children = _children->toList();
        int childIndex = children->length() - 1;
        InlineMethod;
        return children[childIndex]->notifiedByParent(defaultValue)-><bool>then(notifyNextChild);
    }
    return super->invokeCallback(defaultValue);
}

ChildBackButtonDispatcher BackButtonDispatcherCls::createChildBackButtonDispatcher() {
    return make<ChildBackButtonDispatcherCls>(this);
}

void BackButtonDispatcherCls::takePriority() {
    return _children->clear();
}

void BackButtonDispatcherCls::deferTo(ChildBackButtonDispatcher child) {
    assert(hasCallbacks());
    _children->remove(child);
    _children->add(child);
}

void BackButtonDispatcherCls::forget(ChildBackButtonDispatcher child) {
    return _children->remove(child);
}

void RootBackButtonDispatcherCls::addCallback(ValueGetter<Future<bool>> callback) {
    if (!hasCallbacks()) {
        WidgetsBindingCls::instance->addObserver(this);
    }
    super->addCallback(callback);
}

void RootBackButtonDispatcherCls::removeCallback(ValueGetter<Future<bool>> callback) {
    super->removeCallback(callback);
    if (!hasCallbacks()) {
        WidgetsBindingCls::instance->removeObserver(this);
    }
}

Future<bool> RootBackButtonDispatcherCls::didPopRoute() {
    return invokeCallback(<bool>value(false));
}

ChildBackButtonDispatcherCls::ChildBackButtonDispatcherCls(BackButtonDispatcher parent) {
    {
        assert(parent != nullptr);
    }
}

Future<bool> ChildBackButtonDispatcherCls::notifiedByParent(Future<bool> defaultValue) {
    return invokeCallback(defaultValue);
}

void ChildBackButtonDispatcherCls::takePriority() {
    parent->deferTo(this);
    super->takePriority();
}

void ChildBackButtonDispatcherCls::deferTo(ChildBackButtonDispatcher child) {
    assert(hasCallbacks());
    parent->deferTo(this);
    super->deferTo(child);
}

void ChildBackButtonDispatcherCls::removeCallback(ValueGetter<Future<bool>> callback) {
    super->removeCallback(callback);
    if (!hasCallbacks()) {
        parent->forget(this);
    }
}

State<BackButtonListener> BackButtonListenerCls::createState() {
    return make<_BackButtonListenerStateCls>();
}

void _BackButtonListenerStateCls::didChangeDependencies() {
    dispatcher?->removeCallback(widget()->onBackButtonPressed);
    BackButtonDispatcher rootBackDispatcher = RouterCls->of(context())->backButtonDispatcher;
    assert(rootBackDispatcher != nullptr, __s("The parent router must have a backButtonDispatcher to use this widget"));
    auto _c1 = rootBackDispatcher!->createChildBackButtonDispatcher();_c1.auto _c2 = addCallback(widget()->onBackButtonPressed);_c2.takePriority();_c2;dispatcher = _c1;
    super->didChangeDependencies();
}

void _BackButtonListenerStateCls::didUpdateWidget(BackButtonListener oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->onBackButtonPressed != widget()->onBackButtonPressed) {
        dispatcher?->removeCallback(oldWidget->onBackButtonPressed);
        dispatcher?->addCallback(widget()->onBackButtonPressed);
        dispatcher?->takePriority();
    }
}

void _BackButtonListenerStateCls::dispose() {
    dispatcher?->removeCallback(widget()->onBackButtonPressed);
    super->dispose();
}

Widget _BackButtonListenerStateCls::build(BuildContext context) {
    return widget()->child;
}

template<typename T>
Future<T> RouteInformationParserCls<T>::parseRouteInformation(RouteInformation routeInformation) {
    throw make<UnimplementedErrorCls>(__s("One of the parseRouteInformation or parseRouteInformationWithDependencies must be implemented"));
}

template<typename T>
Future<T> RouteInformationParserCls<T>::parseRouteInformationWithDependencies(RouteInformation routeInformation, BuildContext context) {
    return parseRouteInformation(routeInformation);
}

template<typename T>
RouteInformation RouteInformationParserCls<T>::restoreRouteInformation(T configuration) {
    return nullptr;
}

template<typename T>
Future<void> RouterDelegateCls<T>::setInitialRoutePath(T configuration) {
    return setNewRoutePath(configuration);
}

template<typename T>
Future<void> RouterDelegateCls<T>::setRestoredRoutePath(T configuration) {
    return setNewRoutePath(configuration);
}

template<typename T>
T RouterDelegateCls<T>::currentConfiguration() {
    return nullptr;
}

void RouteInformationProviderCls::routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type) {
}

PlatformRouteInformationProviderCls::PlatformRouteInformationProviderCls(RouteInformation initialRouteInformation) {
    {
        _value = initialRouteInformation;
    }
}

void PlatformRouteInformationProviderCls::routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type) {
    bool replace = type == RouteInformationReportingTypeCls::neglect || (type == RouteInformationReportingTypeCls::none && _valueInEngine->location == routeInformation->location);
    SystemNavigatorCls->selectMultiEntryHistory();
    SystemNavigatorCls->routeInformationUpdated(routeInformation->location!, routeInformation->state, replace);
    _value = routeInformation;
    _valueInEngine = routeInformation;
}

RouteInformation PlatformRouteInformationProviderCls::value() {
    return _value;
}

void PlatformRouteInformationProviderCls::addListener(VoidCallback listener) {
    if (!hasListeners) {
        WidgetsBindingCls::instance->addObserver(this);
    }
    super->addListener(listener);
}

void PlatformRouteInformationProviderCls::removeListener(VoidCallback listener) {
    super->removeListener(listener);
    if (!hasListeners) {
        WidgetsBindingCls::instance->removeObserver(this);
    }
}

void PlatformRouteInformationProviderCls::dispose() {
    if (hasListeners) {
        WidgetsBindingCls::instance->removeObserver(this);
    }
    super->dispose();
}

Future<bool> PlatformRouteInformationProviderCls::didPushRouteInformation(RouteInformation routeInformation) {
    assert(hasListeners);
    _platformReportsNewRouteInformation(routeInformation);
    return true;
}

Future<bool> PlatformRouteInformationProviderCls::didPushRoute(String route) {
    assert(hasListeners);
    _platformReportsNewRouteInformation(make<RouteInformationCls>(route));
    return true;
}

void PlatformRouteInformationProviderCls::_platformReportsNewRouteInformation(RouteInformation routeInformation) {
    if (_value == routeInformation) {
        return;
    }
    _value = routeInformation;
    _valueInEngine = routeInformation;
    notifyListeners();
}

template<typename T>
Future<bool> PopNavigatorRouterDelegateMixinCls<T>::popRoute() {
    NavigatorState navigator = navigatorKey()?->currentState();
    if (navigator == nullptr) {
        return <bool>make<SynchronousFutureCls>(false);
    }
    return navigator->maybePop();
}

RouteInformation _RestorableRouteInformationCls::createDefaultValue() {
    return nullptr;
}

void _RestorableRouteInformationCls::didUpdateValue(RouteInformation oldValue) {
    notifyListeners();
}

RouteInformation _RestorableRouteInformationCls::fromPrimitives(Object data) {
    if (data == nullptr) {
        return nullptr;
    }
    assert(is<List<Object>>(data) && data->length == 2);
    List<Object> castedData = as<List<Object>>(data);
    return make<RouteInformationCls>(as<String>(castedData->first), castedData->last);
}

Object _RestorableRouteInformationCls::toPrimitives() {
    return value() == nullptr? nullptr : makeList(ArrayItem, ArrayItem);
}
