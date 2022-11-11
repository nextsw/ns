#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ROUTER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ROUTER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "navigator.hpp"
#include "restoration.hpp"
#include "restoration_properties.hpp"


class RouteInformationCls : public ObjectCls {
public:
    String location;

    Object state;


     RouteInformationCls(String location, Object state);
private:

};
using RouteInformation = std::shared_ptr<RouteInformationCls>;

template<typename T>
class RouterConfigCls : public ObjectCls {
public:
    RouteInformationProvider routeInformationProvider;

    RouteInformationParser<T> routeInformationParser;

    RouterDelegate<T> routerDelegate;

    BackButtonDispatcher backButtonDispatcher;


     RouterConfigCls(BackButtonDispatcher backButtonDispatcher, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate);

private:

};
template<typename T>
using RouterConfig = std::shared_ptr<RouterConfigCls<T>>;

template<typename T>
class RouterCls : public StatefulWidgetCls {
public:
    RouteInformationProvider routeInformationProvider;

    RouteInformationParser<T> routeInformationParser;

    RouterDelegate<T> routerDelegate;

    BackButtonDispatcher backButtonDispatcher;

    String restorationScopeId;


     RouterCls(BackButtonDispatcher backButtonDispatcher, Unknown key, String restorationScopeId, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate);

    virtual void  withConfig(RouterConfig<T> config, Key key, String restorationScopeId);

    template<typename T>
 static Router<T> of(BuildContext context);

    template<typename T>
 static Router<T> maybeOf(BuildContext context);

    static void navigate(VoidCallback callback, BuildContext context);

    static void neglect(VoidCallback callback, BuildContext context);

    virtual State<Router<T>> createState();

private:

};
template<typename T>
using Router = std::shared_ptr<RouterCls<T>>;

enum RouteInformationReportingType{
    none,
    neglect,
    navigate,
} // end RouteInformationReportingType

template<typename T>
class _RouterStateCls : public StateCls<Router<T>> {
public:

    virtual String restorationId();

    virtual void initState();

    virtual void restoreState(bool initialRestore, RestorationBucket oldBucket);

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(Router<T> oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    Object _currentRouterTransaction;

    RouteInformationReportingType _currentIntentionToReport;

    _RestorableRouteInformation _routeInformation;

    bool _routeParsePending;

    bool _routeInformationReportingTaskScheduled;


    virtual void _scheduleRouteInformationReportingTask();

    virtual void _reportRouteInformation(Duration timestamp);

    virtual RouteInformation _retrieveNewRouteInformation();

    virtual void _setStateWithExplicitReportStatus(VoidCallback fn, RouteInformationReportingType status);

    virtual void _maybeNeedToReportRouteInformation();

    virtual void _processRouteInformation(ValueGetter<_RouteSetter<T>> delegateRouteSetter, RouteInformation information);

    virtual _RouteSetter<T> _processParsedRouteInformation(ValueGetter<_RouteSetter<T>> delegateRouteSetter, Object transaction);

    virtual void _handleRouteInformationProviderNotification();

    virtual Future<bool> _handleBackButtonDispatcherNotification();

    virtual _AsyncPassthrough<bool> _handleRoutePopped(Object transaction);

    virtual Future<void> _rebuild(void value);

    virtual void _handleRouterDelegateNotification();

};
template<typename T>
using _RouterState = std::shared_ptr<_RouterStateCls<T>>;

class _RouterScopeCls : public InheritedWidgetCls {
public:
    ValueListenable<RouteInformation> routeInformationProvider;

    BackButtonDispatcher backButtonDispatcher;

    RouteInformationParser<Object> routeInformationParser;

    RouterDelegate<Object> routerDelegate;

    _RouterState<Object> routerState;


    virtual bool updateShouldNotify(_RouterScope oldWidget);

private:

     _RouterScopeCls(BackButtonDispatcher backButtonDispatcher, Unknown child, RouteInformationParser<Object> routeInformationParser, ValueListenable<RouteInformation> routeInformationProvider, RouterDelegate<Object> routerDelegate, _RouterState<Object> routerState);

};
using _RouterScope = std::shared_ptr<_RouterScopeCls>;

template<typename T>
class _CallbackHookProviderCls : public ObjectCls {
public:

    virtual bool hasCallbacks();

    virtual void addCallback(ValueGetter<T> callback);

    virtual void removeCallback(ValueGetter<T> callback);

    virtual T invokeCallback(T defaultValue);

private:
    ObserverList<ValueGetter<T>> _callbacks;


};
template<typename T>
using _CallbackHookProvider = std::shared_ptr<_CallbackHookProviderCls<T>>;

class BackButtonDispatcherCls : public _CallbackHookProviderCls<Future<bool>> {
public:

    virtual bool hasCallbacks();

    virtual Future<bool> invokeCallback(Future<bool> defaultValue);

    virtual ChildBackButtonDispatcher createChildBackButtonDispatcher();

    virtual void takePriority();

    virtual void deferTo(ChildBackButtonDispatcher child);

    virtual void forget(ChildBackButtonDispatcher child);

private:
    LinkedHashSet<ChildBackButtonDispatcher> _children;


};
using BackButtonDispatcher = std::shared_ptr<BackButtonDispatcherCls>;

class RootBackButtonDispatcherCls : public BackButtonDispatcherCls {
public:

     RootBackButtonDispatcherCls();
    virtual void addCallback(ValueGetter<Future<bool>> callback);

    virtual void removeCallback(ValueGetter<Future<bool>> callback);

    virtual Future<bool> didPopRoute();

private:

};
using RootBackButtonDispatcher = std::shared_ptr<RootBackButtonDispatcherCls>;

class ChildBackButtonDispatcherCls : public BackButtonDispatcherCls {
public:
    BackButtonDispatcher parent;


     ChildBackButtonDispatcherCls(BackButtonDispatcher parent);

    virtual Future<bool> notifiedByParent(Future<bool> defaultValue);

    virtual void takePriority();

    virtual void deferTo(ChildBackButtonDispatcher child);

    virtual void removeCallback(ValueGetter<Future<bool>> callback);

private:

};
using ChildBackButtonDispatcher = std::shared_ptr<ChildBackButtonDispatcherCls>;

class BackButtonListenerCls : public StatefulWidgetCls {
public:
    Widget child;

    ValueGetter<Future<bool>> onBackButtonPressed;


     BackButtonListenerCls(Widget child, Unknown key, ValueGetter<Future<bool>> onBackButtonPressed);
    virtual State<BackButtonListener> createState();

private:

};
using BackButtonListener = std::shared_ptr<BackButtonListenerCls>;

class _BackButtonListenerStateCls : public StateCls<BackButtonListener> {
public:
    BackButtonDispatcher dispatcher;


    virtual void didChangeDependencies();

    virtual void didUpdateWidget(BackButtonListener oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:

};
using _BackButtonListenerState = std::shared_ptr<_BackButtonListenerStateCls>;

template<typename T>
class RouteInformationParserCls : public ObjectCls {
public:

     RouteInformationParserCls();
    virtual Future<T> parseRouteInformation(RouteInformation routeInformation);

    virtual Future<T> parseRouteInformationWithDependencies(BuildContext context, RouteInformation routeInformation);

    virtual RouteInformation restoreRouteInformation(T configuration);

private:

};
template<typename T>
using RouteInformationParser = std::shared_ptr<RouteInformationParserCls<T>>;

template<typename T>
class RouterDelegateCls : public ListenableCls {
public:

    virtual Future<void> setInitialRoutePath(T configuration);

    virtual Future<void> setRestoredRoutePath(T configuration);

    virtual Future<void> setNewRoutePath(T configuration);
    virtual Future<bool> popRoute();
    virtual T currentConfiguration();

    virtual Widget build(BuildContext context);
private:

};
template<typename T>
using RouterDelegate = std::shared_ptr<RouterDelegateCls<T>>;

class RouteInformationProviderCls : public ValueListenableCls<RouteInformation> {
public:

    virtual void routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type);

private:

};
using RouteInformationProvider = std::shared_ptr<RouteInformationProviderCls>;

class PlatformRouteInformationProviderCls : public RouteInformationProviderCls {
public:

     PlatformRouteInformationProviderCls(RouteInformation initialRouteInformation);

    virtual void routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type);

    virtual RouteInformation value();

    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void dispose();

    virtual Future<bool> didPushRouteInformation(RouteInformation routeInformation);

    virtual Future<bool> didPushRoute(String route);

private:
    RouteInformation _value;

    RouteInformation _valueInEngine;


    virtual void _platformReportsNewRouteInformation(RouteInformation routeInformation);

};
using PlatformRouteInformationProvider = std::shared_ptr<PlatformRouteInformationProviderCls>;

template<typename T>
class PopNavigatorRouterDelegateMixinCls : public ObjectCls {
public:

    virtual GlobalKey<NavigatorState> navigatorKey();
    virtual Future<bool> popRoute();

private:

};
template<typename T>
using PopNavigatorRouterDelegateMixin = std::shared_ptr<PopNavigatorRouterDelegateMixinCls<T>>;

class _RestorableRouteInformationCls : public RestorableValueCls<RouteInformation> {
public:

    virtual RouteInformation createDefaultValue();

    virtual void didUpdateValue(RouteInformation oldValue);

    virtual RouteInformation fromPrimitives(Object data);

    virtual Object toPrimitives();

private:

};
using _RestorableRouteInformation = std::shared_ptr<_RestorableRouteInformationCls>;


#endif