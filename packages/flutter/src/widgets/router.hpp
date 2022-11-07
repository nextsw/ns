#ifndef ROUTER_H
#define ROUTER_H
#include <memory>

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "navigator.hpp"
#include "restoration.hpp"
#include "restoration_properties.hpp"



class RouteInformation {
public:
    String location;

    Object state;


     RouteInformation(String location, Object state);

private:

};

class RouterConfig<T> {
public:
    RouteInformationProvider routeInformationProvider;

    RouteInformationParser<T> routeInformationParser;

    RouterDelegate<T> routerDelegate;

    BackButtonDispatcher backButtonDispatcher;


     RouterConfig(BackButtonDispatcher backButtonDispatcher, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate);

private:

};

class Router<T> : StatefulWidget {
public:
    RouteInformationProvider routeInformationProvider;

    RouteInformationParser<T> routeInformationParser;

    RouterDelegate<T> routerDelegate;

    BackButtonDispatcher backButtonDispatcher;

    String restorationScopeId;


     Router(BackButtonDispatcher backButtonDispatcher, Unknown, String restorationScopeId, RouteInformationParser<T> routeInformationParser, RouteInformationProvider routeInformationProvider, RouterDelegate<T> routerDelegate);

    void  withConfig(RouterConfig<T> config, Key key, String restorationScopeId);

    static Router<T> of<T extends Object>(BuildContext context);

    static Router<T> maybeOf<T extends Object>(BuildContext context);

    static void navigate(VoidCallback callback, BuildContext context);

    static void neglect(VoidCallback callback, BuildContext context);

    State<Router<T>> createState();

private:

};

enum RouteInformationReportingType{
    none,
    neglect,
    navigate,
} // end RouteInformationReportingType

class _RouterState<T> : State<Router<T>> {
public:

    String restorationId();

    void initState();

    void restoreState(bool initialRestore, RestorationBucket oldBucket);

    void didChangeDependencies();

    void didUpdateWidget(Router<T> oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    Object _currentRouterTransaction;

    RouteInformationReportingType _currentIntentionToReport;

    _RestorableRouteInformation _routeInformation;

    bool _routeParsePending;

    bool _routeInformationReportingTaskScheduled;


    void _scheduleRouteInformationReportingTask();

    void _reportRouteInformation(Duration timestamp);

    RouteInformation _retrieveNewRouteInformation();

    void _setStateWithExplicitReportStatus(VoidCallback fn, RouteInformationReportingType status);

    void _maybeNeedToReportRouteInformation();

    void _processRouteInformation(ValueGetter<_RouteSetter<T>> delegateRouteSetter, RouteInformation information);

    _RouteSetter<T> _processParsedRouteInformation(ValueGetter<_RouteSetter<T>> delegateRouteSetter, Object transaction);

    void _handleRouteInformationProviderNotification();

    Future<bool> _handleBackButtonDispatcherNotification();

    _AsyncPassthrough<bool> _handleRoutePopped(Object transaction);

    Future<void> _rebuild(void value);

    void _handleRouterDelegateNotification();

};

class _RouterScope : InheritedWidget {
public:
    ValueListenable<RouteInformation> routeInformationProvider;

    BackButtonDispatcher backButtonDispatcher;

    RouteInformationParser<Object> routeInformationParser;

    RouterDelegate<Object> routerDelegate;

    _RouterState<Object> routerState;


    bool updateShouldNotify(_RouterScope oldWidget);

private:

     _RouterScope(BackButtonDispatcher backButtonDispatcher, Unknown, RouteInformationParser<Object> routeInformationParser, ValueListenable<RouteInformation> routeInformationProvider, RouterDelegate<Object> routerDelegate, _RouterState<Object> routerState);

};

class _CallbackHookProvider<T> {
public:

    bool hasCallbacks();

    void addCallback(ValueGetter<T> callback);

    void removeCallback(ValueGetter<T> callback);

    T invokeCallback(T defaultValue);

private:
    ObserverList<ValueGetter<T>> _callbacks;


};

class BackButtonDispatcher : _CallbackHookProvider<Future<bool>> {
public:

    bool hasCallbacks();

    Future<bool> invokeCallback(Future<bool> defaultValue);

    ChildBackButtonDispatcher createChildBackButtonDispatcher();

    void takePriority();

    void deferTo(ChildBackButtonDispatcher child);

    void forget(ChildBackButtonDispatcher child);

private:
    LinkedHashSet<ChildBackButtonDispatcher> _children;


};

class RootBackButtonDispatcher : BackButtonDispatcher {
public:

     RootBackButtonDispatcher();

    void addCallback(ValueGetter<Future<bool>> callback);

    void removeCallback(ValueGetter<Future<bool>> callback);

    Future<bool> didPopRoute();

private:

};

class ChildBackButtonDispatcher : BackButtonDispatcher {
public:
    BackButtonDispatcher parent;


     ChildBackButtonDispatcher(BackButtonDispatcher parent);

    Future<bool> notifiedByParent(Future<bool> defaultValue);

    void takePriority();

    void deferTo(ChildBackButtonDispatcher child);

    void removeCallback(ValueGetter<Future<bool>> callback);

private:

};

class BackButtonListener : StatefulWidget {
public:
    Widget child;

    ValueGetter<Future<bool>> onBackButtonPressed;


     BackButtonListener(Widget child, Unknown, ValueGetter<Future<bool>> onBackButtonPressed);

    State<BackButtonListener> createState();

private:

};

class _BackButtonListenerState : State<BackButtonListener> {
public:
    BackButtonDispatcher dispatcher;


    void didChangeDependencies();

    void didUpdateWidget(BackButtonListener oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:

};

class RouteInformationParser<T> {
public:

     RouteInformationParser();

    Future<T> parseRouteInformation(RouteInformation routeInformation);

    Future<T> parseRouteInformationWithDependencies(BuildContext context, RouteInformation routeInformation);

    RouteInformation restoreRouteInformation(T configuration);

private:

};

class RouterDelegate<T> : Listenable {
public:

    Future<void> setInitialRoutePath(T configuration);

    Future<void> setRestoredRoutePath(T configuration);

    Future<void> setNewRoutePath(T configuration);

    Future<bool> popRoute();

    T currentConfiguration();

    Widget build(BuildContext context);

private:

};

class RouteInformationProvider : ValueListenable<RouteInformation> {
public:

    void routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type);

private:

};

class PlatformRouteInformationProvider : RouteInformationProvider {
public:

     PlatformRouteInformationProvider(RouteInformation initialRouteInformation);

    void routerReportsNewRouteInformation(RouteInformation routeInformation, RouteInformationReportingType type);

    RouteInformation value();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void dispose();

    Future<bool> didPushRouteInformation(RouteInformation routeInformation);

    Future<bool> didPushRoute(String route);

private:
    RouteInformation _value;

    RouteInformation _valueInEngine;


    void _platformReportsNewRouteInformation(RouteInformation routeInformation);

};

class PopNavigatorRouterDelegateMixin<T> {
public:

    GlobalKey<NavigatorState> navigatorKey();

    Future<bool> popRoute();

private:

};

class _RestorableRouteInformation : RestorableValue<RouteInformation> {
public:

    RouteInformation createDefaultValue();

    void didUpdateValue(RouteInformation oldValue);

    RouteInformation fromPrimitives(Object data);

    Object toPrimitives();

private:

};

#endif