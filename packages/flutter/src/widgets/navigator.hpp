#ifndef NAVIGATOR_H
#define NAVIGATOR_H
#include <memory>

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <convert/convert.hpp>
#include <developer/developer.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "heroes.hpp"
#include "overlay.hpp"
#include "restoration.hpp"
#include "restoration_properties.hpp"
#include "routes.hpp"
#include "ticker_provider.hpp"



enum RoutePopDisposition{
    pop,
    doNotPop,
    bubble,
} // end RoutePopDisposition

class Route<T> {
public:

     Route(RouteSettings settings);

    NavigatorState navigator();

    RouteSettings settings();

    ValueListenable<String> restorationScopeId();

    List<OverlayEntry> overlayEntries();

    void install();

    TickerFuture didPush();

    void didAdd();

    void didReplace(Route<dynamic> oldRoute);

    Future<RoutePopDisposition> willPop();

    bool willHandlePopInternally();

    T currentResult();

    Future<T> popped();

    bool didPop(T result);

    void didComplete(T result);

    void didPopNext(Route<dynamic> nextRoute);

    void didChangeNext(Route<dynamic> nextRoute);

    void didChangePrevious(Route<dynamic> previousRoute);

    void changedInternalState();

    void changedExternalState();

    void dispose();

    bool isCurrent();

    bool isFirst();

    bool hasActiveRouteBelow();

    bool isActive();

private:
    NavigatorState _navigator;

    RouteSettings _settings;

    ValueNotifier<String> _restorationScopeId;

    Completer<T> _popCompleter;


    void _updateSettings(RouteSettings newSettings);

    void _updateRestorationId(String restorationId);

};

class RouteSettings {
public:
    String name;

    Object arguments;


     RouteSettings(Object arguments, String name);

    RouteSettings copyWith(Object arguments, String name);

    String toString();

private:

};

class Page<T> : RouteSettings {
public:
    LocalKey key;

    String restorationId;


     Page(Unknown, LocalKey key, Unknown, String restorationId);

    bool canUpdate(Page<dynamic> other);

    Route<T> createRoute(BuildContext context);

    String toString();

private:

};

class NavigatorObserver {
public:

    NavigatorState navigator();

    void didPush(Route<dynamic> previousRoute, Route<dynamic> route);

    void didPop(Route<dynamic> previousRoute, Route<dynamic> route);

    void didRemove(Route<dynamic> previousRoute, Route<dynamic> route);

    void didReplace(Route<dynamic> newRoute, Route<dynamic> oldRoute);

    void didStartUserGesture(Route<dynamic> previousRoute, Route<dynamic> route);

    void didStopUserGesture();

private:
    NavigatorState _navigator;


};

class HeroControllerScope : InheritedWidget {
public:
    HeroController controller;


     HeroControllerScope(Unknown, HeroController controller, Unknown);

    void  none(Unknown, Unknown);

    static HeroController of(BuildContext context);

    bool updateShouldNotify(HeroControllerScope oldWidget);

private:

};

class RouteTransitionRecord {
public:

    Route<dynamic> route();

    bool isWaitingForEnteringDecision();

    bool isWaitingForExitingDecision();

    void markForPush();

    void markForAdd();

    void markForPop(dynamic result);

    void markForComplete(dynamic result);

    void markForRemove();

private:

};

class TransitionDelegate<T> {
public:

     TransitionDelegate();

    Iterable<RouteTransitionRecord> resolve(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes);

private:

    Iterable<RouteTransitionRecord> _transition(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes);

};

class DefaultTransitionDelegate<T> : TransitionDelegate<T> {
public:

     DefaultTransitionDelegate();

    Iterable<RouteTransitionRecord> resolve(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes);

private:

};

class Navigator : StatefulWidget {
public:
    List<Page<dynamic>> pages;

    PopPageCallback onPopPage;

    TransitionDelegate<dynamic> transitionDelegate;

    String initialRoute;

    RouteFactory onGenerateRoute;

    RouteFactory onUnknownRoute;

    List<NavigatorObserver> observers;

    String restorationScopeId;

    static const String defaultRouteName;

    RouteListFactory onGenerateInitialRoutes;

    bool reportsRouteUpdateToEngine;

    bool requestFocus;


     Navigator(String initialRoute, Unknown, List<NavigatorObserver> observers, RouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, PopPageCallback onPopPage, RouteFactory onUnknownRoute, List<Page<dynamic>> pages, bool reportsRouteUpdateToEngine, bool requestFocus, String restorationScopeId, TransitionDelegate<dynamic> transitionDelegate);

    static Future<T> pushNamed<T extends Object>(Object arguments, BuildContext context, String routeName);

    static String restorablePushNamed<T extends Object>(Object arguments, BuildContext context, String routeName);

    static Future<T> pushReplacementNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName);

    static String restorablePushReplacementNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName);

    static Future<T> popAndPushNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName);

    static String restorablePopAndPushNamed<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, String routeName);

    static Future<T> pushNamedAndRemoveUntil<T extends Object>(Object arguments, BuildContext context, String newRouteName, RoutePredicate predicate);

    static String restorablePushNamedAndRemoveUntil<T extends Object>(Object arguments, BuildContext context, String newRouteName, RoutePredicate predicate);

    static Future<T> push<T extends Object>(BuildContext context, Route<T> route);

    static String restorablePush<T extends Object>(Object arguments, BuildContext context, RestorableRouteBuilder<T> routeBuilder);

    static Future<T> pushReplacement<T extends Object, TO extends Object>(BuildContext context, Route<T> newRoute, TO result);

    static String restorablePushReplacement<T extends Object, TO extends Object>(Object arguments, BuildContext context, TO result, RestorableRouteBuilder<T> routeBuilder);

    static Future<T> pushAndRemoveUntil<T extends Object>(BuildContext context, Route<T> newRoute, RoutePredicate predicate);

    static String restorablePushAndRemoveUntil<T extends Object>(Object arguments, BuildContext context, RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate);

    static void replace<T extends Object>(BuildContext context, Route<T> newRoute, Route<dynamic> oldRoute);

    static String restorableReplace<T extends Object>(Object arguments, BuildContext context, RestorableRouteBuilder<T> newRouteBuilder, Route<dynamic> oldRoute);

    static void replaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, BuildContext context, Route<T> newRoute);

    static String restorableReplaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, Object arguments, BuildContext context, RestorableRouteBuilder<T> newRouteBuilder);

    static bool canPop(BuildContext context);

    static Future<bool> maybePop<T extends Object>(BuildContext context, T result);

    static void pop<T extends Object>(BuildContext context, T result);

    static void popUntil(BuildContext context, RoutePredicate predicate);

    static void removeRoute(BuildContext context, Route<dynamic> route);

    static void removeRouteBelow(Route<dynamic> anchorRoute, BuildContext context);

    static NavigatorState of(BuildContext context, bool rootNavigator);

    static NavigatorState maybeOf(BuildContext context, bool rootNavigator);

    static List<Route<dynamic>> defaultGenerateInitialRoutes(String initialRouteName, NavigatorState navigator);

    NavigatorState createState();

private:

};

enum _RouteLifecycle{
    staging,
    add,
    adding,
    push,
    pushReplace,
    pushing,
    replace,
    idle,
    pop,
    complete,
    remove,
    popping,
    removing,
    dispose,
    disposed,
} // end _RouteLifecycle

class _NotAnnounced : Route<void> {
public:

private:

};

class _RouteEntry : RouteTransitionRecord {
public:
    Route<dynamic> route;

    _RestorationInformation restorationInformation;

    static Route<dynamic> notAnnounced;

    _RouteLifecycle currentState;

    Route<dynamic> lastAnnouncedPreviousRoute;

    Route<dynamic> lastAnnouncedPoppedNextRoute;

    Route<dynamic> lastAnnouncedNextRoute;

    Object pendingResult;


    String restorationId();

    bool hasPage();

    bool canUpdateFrom(Page<dynamic> page);

    void handleAdd(NavigatorState navigator, Route<dynamic> previousPresent);

    void handlePush(bool isNewFirst, NavigatorState navigator, Route<dynamic> previous, Route<dynamic> previousPresent);

    void handleDidPopNext(Route<dynamic> poppedRoute);

    bool handlePop(NavigatorState navigator, Route<dynamic> previousPresent);

    void handleComplete();

    void handleRemoval(NavigatorState navigator, Route<dynamic> previousPresent);

    void didAdd(bool isNewFirst, NavigatorState navigator);

    void pop<T>(T result);

    void remove(bool isReplaced);

    void complete<T>(bool isReplaced, T result);

    void finalize();

    void dispose();

    bool willBePresent();

    bool isPresent();

    bool isPresentForRestoration();

    bool suitableForAnnouncement();

    bool suitableForTransitionAnimation();

    bool shouldAnnounceChangeToNext(Route<dynamic> nextRoute);

    static bool isPresentPredicate(_RouteEntry entry);

    static bool suitableForTransitionAnimationPredicate(_RouteEntry entry);

    static bool willBePresentPredicate(_RouteEntry entry);

    static _RouteEntryPredicate isRoutePredicate(Route<dynamic> route);

    bool isWaitingForEnteringDecision();

    bool isWaitingForExitingDecision();

    void markNeedsExitingDecision();

    void markForPush();

    void markForAdd();

    void markForPop(dynamic result);

    void markForComplete(dynamic result);

    void markForRemove();

    bool restorationEnabled();

    void  restorationEnabled(bool value);

private:
    bool _reportRemovalToObserver;

    bool _isWaitingForExitingDecision;


     _RouteEntry(_RouteLifecycle initialState, _RestorationInformation restorationInformation, Route<dynamic> route);

};

class _NavigatorObservation {
public:
    Route<dynamic> primaryRoute;

    Route<dynamic> secondaryRoute;


    void notify(NavigatorObserver observer);

private:

     _NavigatorObservation(Route<dynamic> primaryRoute, Route<dynamic> secondaryRoute);

};

class _NavigatorPushObservation : _NavigatorObservation {
public:

    void notify(NavigatorObserver observer);

private:

     _NavigatorPushObservation(Unknown, Unknown);

};

class _NavigatorPopObservation : _NavigatorObservation {
public:

    void notify(NavigatorObserver observer);

private:

     _NavigatorPopObservation(Unknown, Unknown);

};

class _NavigatorRemoveObservation : _NavigatorObservation {
public:

    void notify(NavigatorObserver observer);

private:

     _NavigatorRemoveObservation(Unknown, Unknown);

};

class _NavigatorReplaceObservation : _NavigatorObservation {
public:

    void notify(NavigatorObserver observer);

private:

     _NavigatorReplaceObservation(Unknown, Unknown);

};

class NavigatorState : State<Navigator> {
public:
    FocusScopeNode focusScopeNode;

    ValueNotifier<bool> userGestureInProgressNotifier;


    void initState();

    void restoreState(bool initialRestore, RestorationBucket oldBucket);

    void didToggleBucket(RestorationBucket oldBucket);

    String restorationId();

    void didChangeDependencies();

    void didUpdateWidget(Navigator oldWidget);

    void deactivate();

    void activate();

    void dispose();

    OverlayState overlay();

    Future<T> pushNamed<T extends Object>(Object arguments, String routeName);

    String restorablePushNamed<T extends Object>(Object arguments, String routeName);

    Future<T> pushReplacementNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName);

    String restorablePushReplacementNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName);

    Future<T> popAndPushNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName);

    String restorablePopAndPushNamed<T extends Object, TO extends Object>(Object arguments, TO result, String routeName);

    Future<T> pushNamedAndRemoveUntil<T extends Object>(Object arguments, String newRouteName, RoutePredicate predicate);

    String restorablePushNamedAndRemoveUntil<T extends Object>(Object arguments, String newRouteName, RoutePredicate predicate);

    Future<T> push<T extends Object>(Route<T> route);

    String restorablePush<T extends Object>(Object arguments, RestorableRouteBuilder<T> routeBuilder);

    Future<T> pushReplacement<T extends Object, TO extends Object>(Route<T> newRoute, TO result);

    String restorablePushReplacement<T extends Object, TO extends Object>(Object arguments, TO result, RestorableRouteBuilder<T> routeBuilder);

    Future<T> pushAndRemoveUntil<T extends Object>(Route<T> newRoute, RoutePredicate predicate);

    String restorablePushAndRemoveUntil<T extends Object>(Object arguments, RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate);

    void replace<T extends Object>(Route<T> newRoute, Route<dynamic> oldRoute);

    String restorableReplace<T extends Object>(Object arguments, RestorableRouteBuilder<T> newRouteBuilder, Route<dynamic> oldRoute);

    void replaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, Route<T> newRoute);

    String restorableReplaceRouteBelow<T extends Object>(Route<dynamic> anchorRoute, Object arguments, RestorableRouteBuilder<T> newRouteBuilder);

    bool canPop();

    Future<bool> maybePop<T extends Object>(T result);

    void pop<T extends Object>(T result);

    void popUntil(RoutePredicate predicate);

    void removeRoute(Route<dynamic> route);

    void removeRouteBelow(Route<dynamic> anchorRoute);

    void finalizeRoute(Route<dynamic> route);

    bool userGestureInProgress();

    void didStartUserGesture();

    void didStopUserGesture();

    Widget build(BuildContext context);

private:
    GlobalKey<OverlayState> _overlayKey;

    List<_RouteEntry> _history;

    _HistoryProperty _serializableHistory;

    Queue<_NavigatorObservation> _observedRouteAdditions;

    Queue<_NavigatorObservation> _observedRouteDeletions;

    bool _debugLocked;

    HeroController _heroControllerFromScope;

    List<NavigatorObserver> _effectiveObservers;

    RestorableNum<int> _rawNextPagelessRestorationScopeId;

    String _lastAnnouncedRouteName;

    bool _debugUpdatingPage;

    bool _flushingHistory;

    int _userGesturesInProgressCount;

    Set<int> _activePointers;


    int _nextPagelessRestorationScopeId();

    void _updateHeroController(HeroController newHeroController);

    void _updateEffectiveObservers();

    void _debugCheckDuplicatedPageKeys();

    Iterable<OverlayEntry> _allRouteOverlayEntries();

    void _updatePages();

    void _flushHistoryUpdates(bool rearrangeOverlay);

    void _flushObserverNotifications();

    void _flushRouteAnnouncement();

    _RouteEntry _getRouteBefore(int index, _RouteEntryPredicate predicate);

    int _getIndexBefore(int index, _RouteEntryPredicate predicate);

    _RouteEntry _getRouteAfter(int index, _RouteEntryPredicate predicate);

    Route<T> _routeNamed<T>(bool allowNull, Object arguments, String name);

    bool _debugCheckIsPagelessRoute(Route<dynamic> route);

    bool _debugIsStaticCallback(FunctionType callback);

    void _pushEntry(_RouteEntry entry);

    void _afterNavigation(Route<dynamic> route);

    void _pushReplacementEntry<TO extends Object>(_RouteEntry entry, TO result);

    void _pushEntryAndRemoveUntil(_RouteEntry entry, RoutePredicate predicate);

    void _replaceEntry(_RouteEntry entry, Route<dynamic> oldRoute);

    void _replaceEntryBelow(Route<dynamic> anchorRoute, _RouteEntry entry);

    Route<T> _getRouteById<T>(String id);

    int _userGesturesInProgress();

    void  _userGesturesInProgress(int value);

    void _handlePointerDown(PointerDownEvent event);

    void _handlePointerUpOrCancel(PointerEvent event);

    void _cancelActivePointers();

};

enum _RouteRestorationType{
    named,
    anonymous,
} // end _RouteRestorationType

class _RestorationInformation {
public:
    _RouteRestorationType type;


    void  named(Object arguments, String name, int restorationScopeId);

    void  anonymous(Object arguments, int restorationScopeId, RestorableRouteBuilder<Object> routeBuilder);

    void  fromSerializableData(Object data);

    int restorationScopeId();

    bool isRestorable();

    Object getSerializableData();

    List<Object> computeSerializableData();

    Route<dynamic> createRoute(NavigatorState navigator);

    _RouteEntry toRouteEntry(_RouteLifecycle initialState, NavigatorState navigator);

private:
    Object _serializableData;


     _RestorationInformation(_RouteRestorationType type);

};

class _NamedRestorationInformation : _RestorationInformation {
public:
    int restorationScopeId;

    String name;

    Object arguments;


    void  fromSerializableData(List<Object> data);

    List<Object> computeSerializableData();

    Route<dynamic> createRoute(NavigatorState navigator);

private:

     _NamedRestorationInformation(Object arguments, String name, int restorationScopeId);

};

class _AnonymousRestorationInformation : _RestorationInformation {
public:
    int restorationScopeId;

    RestorableRouteBuilder<Object> routeBuilder;

    Object arguments;


    void  fromSerializableData(List<Object> data);

    bool isRestorable();

    List<Object> computeSerializableData();

    Route<dynamic> createRoute(NavigatorState navigator);

private:

     _AnonymousRestorationInformation(Object arguments, int restorationScopeId, RestorableRouteBuilder<Object> routeBuilder);

};

class _HistoryProperty : RestorableProperty<Map<String, List<Object>>> {
public:

    void update(List<_RouteEntry> history);

    void clear();

    bool hasData();

    List<_RouteEntry> restoreEntriesForPage(NavigatorState navigator, _RouteEntry page);

    Map<String, List<Object>> createDefaultValue();

    Map<String, List<Object>> fromPrimitives(Object data);

    void initWithValue(Map<String, List<Object>> value);

    Object toPrimitives();

    bool enabled();

private:
    Map<String, List<Object>> _pageToPagelessRoutes;


    void _finalizePage(_RouteEntry page, Map<String, List<Object>> pageToRoutes, Set<String> pagesToRemove, List<Object> routes);

    bool _debugMapsEqual(Map<String, List<Object>> a, Map<String, List<Object>> b);

};

class RestorableRouteFuture<T> : RestorableProperty<String> {
public:
    NavigatorFinderCallback navigatorFinder;

    RoutePresentationCallback onPresent;

    RouteCompletionCallback<T> onComplete;


     RestorableRouteFuture(NavigatorFinderCallback navigatorFinder, RouteCompletionCallback<T> onComplete, RoutePresentationCallback onPresent);

    void present(Object arguments);

    bool isPresent();

    Route<T> route();

    String createDefaultValue();

    void initWithValue(String value);

    Object toPrimitives();

    String fromPrimitives(Object data);

    void dispose();

    bool enabled();

private:
    Route<T> _route;

    bool _disposed;


    NavigatorState _navigator();

    void _hookOntoRouteFuture(String id);

    static NavigatorState _defaultNavigatorFinder(BuildContext context);

};

#endif