#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NAVIGATOR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NAVIGATOR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <dart/convert/convert.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
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

template<typename T>
class RouteCls : public ObjectCls {
public:

     RouteCls(RouteSettings settings);

    virtual NavigatorState navigator();

    virtual RouteSettings settings();

    virtual ValueListenable<String> restorationScopeId();

    virtual List<OverlayEntry> overlayEntries();

    virtual void install();

    virtual TickerFuture didPush();

    virtual void didAdd();

    virtual void didReplace(Route<Object> oldRoute);

    virtual Future<RoutePopDisposition> willPop();

    virtual bool willHandlePopInternally();

    virtual T currentResult();

    virtual Future<T> popped();

    virtual bool didPop(T result);

    virtual void didComplete(T result);

    virtual void didPopNext(Route<Object> nextRoute);

    virtual void didChangeNext(Route<Object> nextRoute);

    virtual void didChangePrevious(Route<Object> previousRoute);

    virtual void changedInternalState();

    virtual void changedExternalState();

    virtual void dispose();

    virtual bool isCurrent();

    virtual bool isFirst();

    virtual bool hasActiveRouteBelow();

    virtual bool isActive();

private:
    NavigatorState _navigator;

    RouteSettings _settings;

    ValueNotifier<String> _restorationScopeId;

    Completer<T> _popCompleter;


    virtual void _updateSettings(RouteSettings newSettings);

    virtual void _updateRestorationId(String restorationId);

};
template<typename T>
using Route = std::shared_ptr<RouteCls<T>>;

class RouteSettingsCls : public ObjectCls {
public:
    String name;

    Object arguments;


     RouteSettingsCls(Object arguments, String name);
    virtual RouteSettings copyWith(Object arguments, String name);

    virtual String toString();

private:

};
using RouteSettings = std::shared_ptr<RouteSettingsCls>;

template<typename T>
class PageCls : public RouteSettingsCls {
public:
    LocalKey key;

    String restorationId;


     PageCls(Object arguments, LocalKey key, String name, String restorationId);
    virtual bool canUpdate(Page<Object> other);

    virtual Route<T> createRoute(BuildContext context);
    virtual String toString();

private:

};
template<typename T>
using Page = std::shared_ptr<PageCls<T>>;

class NavigatorObserverCls : public ObjectCls {
public:

    virtual NavigatorState navigator();

    virtual void didPush(Route<Object> route, Route<Object> previousRoute);

    virtual void didPop(Route<Object> route, Route<Object> previousRoute);

    virtual void didRemove(Route<Object> route, Route<Object> previousRoute);

    virtual void didReplace(Route<Object> newRoute, Route<Object> oldRoute);

    virtual void didStartUserGesture(Route<Object> route, Route<Object> previousRoute);

    virtual void didStopUserGesture();

private:
    NavigatorState _navigator;


};
using NavigatorObserver = std::shared_ptr<NavigatorObserverCls>;

class HeroControllerScopeCls : public InheritedWidgetCls {
public:
    HeroController controller;


     HeroControllerScopeCls(Widget child, HeroController controller, Key key);

    virtual void  none(Unknown child, Unknown key);

    static HeroController of(BuildContext context);

    virtual bool updateShouldNotify(HeroControllerScope oldWidget);

private:

};
using HeroControllerScope = std::shared_ptr<HeroControllerScopeCls>;

class RouteTransitionRecordCls : public ObjectCls {
public:

    virtual Route<Object> route();
    virtual bool isWaitingForEnteringDecision();
    virtual bool isWaitingForExitingDecision();
    virtual void markForPush();
    virtual void markForAdd();
    virtual void markForPop(Object result);
    virtual void markForComplete(Object result);
    virtual void markForRemove();
private:

};
using RouteTransitionRecord = std::shared_ptr<RouteTransitionRecordCls>;

template<typename T>
class TransitionDelegateCls : public ObjectCls {
public:

     TransitionDelegateCls();
    virtual Iterable<RouteTransitionRecord> resolve(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes);
private:

    virtual Iterable<RouteTransitionRecord> _transition(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes);

};
template<typename T>
using TransitionDelegate = std::shared_ptr<TransitionDelegateCls<T>>;

template<typename T>
class DefaultTransitionDelegateCls : public TransitionDelegateCls<T> {
public:

     DefaultTransitionDelegateCls();

    virtual Iterable<RouteTransitionRecord> resolve(Map<RouteTransitionRecord, RouteTransitionRecord> locationToExitingPageRoute, List<RouteTransitionRecord> newPageRouteHistory, Map<RouteTransitionRecord, List<RouteTransitionRecord>> pageRouteToPagelessRoutes);

private:

};
template<typename T>
using DefaultTransitionDelegate = std::shared_ptr<DefaultTransitionDelegateCls<T>>;

class NavigatorCls : public StatefulWidgetCls {
public:
    List<Page<Object>> pages;

    PopPageCallback onPopPage;

    TransitionDelegate<Object> transitionDelegate;

    String initialRoute;

    RouteFactory onGenerateRoute;

    RouteFactory onUnknownRoute;

    List<NavigatorObserver> observers;

    String restorationScopeId;

    static String defaultRouteName;

    RouteListFactory onGenerateInitialRoutes;

    bool reportsRouteUpdateToEngine;

    bool requestFocus;


     NavigatorCls(String initialRoute, Key key, List<NavigatorObserver> observers, RouteListFactory onGenerateInitialRoutes, RouteFactory onGenerateRoute, PopPageCallback onPopPage, RouteFactory onUnknownRoute, List<Page<Object>> pages, bool reportsRouteUpdateToEngine, bool requestFocus, String restorationScopeId, TransitionDelegate<Object> transitionDelegate);

    template<typename T>
 static Future<T> pushNamed(BuildContext context, String routeName, Object arguments);

    template<typename T>
 static String restorablePushNamed(BuildContext context, String routeName, Object arguments);

    template<typename T, typename TO>
 static Future<T> pushReplacementNamed(BuildContext context, String routeName, Object arguments, TO result);

    template<typename T, typename TO>
 static String restorablePushReplacementNamed(BuildContext context, String routeName, Object arguments, TO result);

    template<typename T, typename TO>
 static Future<T> popAndPushNamed(BuildContext context, String routeName, Object arguments, TO result);

    template<typename T, typename TO>
 static String restorablePopAndPushNamed(BuildContext context, String routeName, Object arguments, TO result);

    template<typename T>
 static Future<T> pushNamedAndRemoveUntil(BuildContext context, String newRouteName, RoutePredicate predicate, Object arguments);

    template<typename T>
 static String restorablePushNamedAndRemoveUntil(BuildContext context, String newRouteName, RoutePredicate predicate, Object arguments);

    template<typename T>
 static Future<T> push(BuildContext context, Route<T> route);

    template<typename T>
 static String restorablePush(BuildContext context, RestorableRouteBuilder<T> routeBuilder, Object arguments);

    template<typename T, typename TO>
 static Future<T> pushReplacement(BuildContext context, Route<T> newRoute, TO result);

    template<typename T, typename TO>
 static String restorablePushReplacement(BuildContext context, RestorableRouteBuilder<T> routeBuilder, Object arguments, TO result);

    template<typename T>
 static Future<T> pushAndRemoveUntil(BuildContext context, Route<T> newRoute, RoutePredicate predicate);

    template<typename T>
 static String restorablePushAndRemoveUntil(BuildContext context, RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate, Object arguments);

    template<typename T>
 static void replace(BuildContext context, Route<T> newRoute, Route<Object> oldRoute);

    template<typename T>
 static String restorableReplace(BuildContext context, Object arguments, RestorableRouteBuilder<T> newRouteBuilder, Route<Object> oldRoute);

    template<typename T>
 static void replaceRouteBelow(BuildContext context, Route<Object> anchorRoute, Route<T> newRoute);

    template<typename T>
 static String restorableReplaceRouteBelow(BuildContext context, Route<Object> anchorRoute, Object arguments, RestorableRouteBuilder<T> newRouteBuilder);

    static bool canPop(BuildContext context);

    template<typename T>
 static Future<bool> maybePop(BuildContext context, T result);

    template<typename T>
 static void pop(BuildContext context, T result);

    static void popUntil(BuildContext context, RoutePredicate predicate);

    static void removeRoute(BuildContext context, Route<Object> route);

    static void removeRouteBelow(BuildContext context, Route<Object> anchorRoute);

    static NavigatorState of(BuildContext context, bool rootNavigator);

    static NavigatorState maybeOf(BuildContext context, bool rootNavigator);

    static List<Route<Object>> defaultGenerateInitialRoutes(NavigatorState navigator, String initialRouteName);

    virtual NavigatorState createState();

private:

};
using Navigator = std::shared_ptr<NavigatorCls>;

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

class _NotAnnouncedCls : public RouteCls<void> {
public:

private:

};
using _NotAnnounced = std::shared_ptr<_NotAnnouncedCls>;

class _RouteEntryCls : public RouteTransitionRecordCls {
public:
    Route<Object> route;

    _RestorationInformation restorationInformation;

    static Route<Object> notAnnounced;

    _RouteLifecycle currentState;

    Route<Object> lastAnnouncedPreviousRoute;

    Route<Object> lastAnnouncedPoppedNextRoute;

    Route<Object> lastAnnouncedNextRoute;

    Object pendingResult;


    virtual String restorationId();

    virtual bool hasPage();

    virtual bool canUpdateFrom(Page<Object> page);

    virtual void handleAdd(NavigatorState navigator, Route<Object> previousPresent);

    virtual void handlePush(bool isNewFirst, NavigatorState navigator, Route<Object> previous, Route<Object> previousPresent);

    virtual void handleDidPopNext(Route<Object> poppedRoute);

    virtual bool handlePop(NavigatorState navigator, Route<Object> previousPresent);

    virtual void handleComplete();

    virtual void handleRemoval(NavigatorState navigator, Route<Object> previousPresent);

    virtual void didAdd(bool isNewFirst, NavigatorState navigator);

    template<typename T>
 virtual void pop(T result);

    virtual void remove(bool isReplaced);

    template<typename T>
 virtual void complete(T result, bool isReplaced);

    virtual void finalize();

    virtual void dispose();

    virtual bool willBePresent();

    virtual bool isPresent();

    virtual bool isPresentForRestoration();

    virtual bool suitableForAnnouncement();

    virtual bool suitableForTransitionAnimation();

    virtual bool shouldAnnounceChangeToNext(Route<Object> nextRoute);

    static bool isPresentPredicate(_RouteEntry entry);

    static bool suitableForTransitionAnimationPredicate(_RouteEntry entry);

    static bool willBePresentPredicate(_RouteEntry entry);

    static _RouteEntryPredicate isRoutePredicate(Route<Object> route);

    virtual bool isWaitingForEnteringDecision();

    virtual bool isWaitingForExitingDecision();

    virtual void markNeedsExitingDecision();

    virtual void markForPush();

    virtual void markForAdd();

    virtual void markForPop(Object result);

    virtual void markForComplete(Object result);

    virtual void markForRemove();

    virtual bool restorationEnabled();

    virtual void  restorationEnabled(bool value);

private:
    bool _reportRemovalToObserver;

    bool _isWaitingForExitingDecision;


     _RouteEntryCls(Route<Object> route, _RouteLifecycle initialState, _RestorationInformation restorationInformation);

};
using _RouteEntry = std::shared_ptr<_RouteEntryCls>;

class _NavigatorObservationCls : public ObjectCls {
public:
    Route<Object> primaryRoute;

    Route<Object> secondaryRoute;


    virtual void notify(NavigatorObserver observer);
private:

     _NavigatorObservationCls(Route<Object> primaryRoute, Route<Object> secondaryRoute);
};
using _NavigatorObservation = std::shared_ptr<_NavigatorObservationCls>;

class _NavigatorPushObservationCls : public _NavigatorObservationCls {
public:

    virtual void notify(NavigatorObserver observer);

private:

     _NavigatorPushObservationCls(Route<Object> primaryRoute, Route<Object> secondaryRoute);
};
using _NavigatorPushObservation = std::shared_ptr<_NavigatorPushObservationCls>;

class _NavigatorPopObservationCls : public _NavigatorObservationCls {
public:

    virtual void notify(NavigatorObserver observer);

private:

     _NavigatorPopObservationCls(Route<Object> primaryRoute, Route<Object> secondaryRoute);
};
using _NavigatorPopObservation = std::shared_ptr<_NavigatorPopObservationCls>;

class _NavigatorRemoveObservationCls : public _NavigatorObservationCls {
public:

    virtual void notify(NavigatorObserver observer);

private:

     _NavigatorRemoveObservationCls(Route<Object> primaryRoute, Route<Object> secondaryRoute);
};
using _NavigatorRemoveObservation = std::shared_ptr<_NavigatorRemoveObservationCls>;

class _NavigatorReplaceObservationCls : public _NavigatorObservationCls {
public:

    virtual void notify(NavigatorObserver observer);

private:

     _NavigatorReplaceObservationCls(Route<Object> primaryRoute, Route<Object> secondaryRoute);
};
using _NavigatorReplaceObservation = std::shared_ptr<_NavigatorReplaceObservationCls>;

class NavigatorStateCls : public StateCls<Navigator> {
public:
    FocusScopeNode focusScopeNode;

    ValueNotifier<bool> userGestureInProgressNotifier;


    virtual void initState();

    virtual void restoreState(RestorationBucket oldBucket, bool initialRestore);

    virtual void didToggleBucket(RestorationBucket oldBucket);

    virtual String restorationId();

    virtual void didChangeDependencies();

    virtual void didUpdateWidget(Navigator oldWidget);

    virtual void deactivate();

    virtual void activate();

    virtual void dispose();

    virtual OverlayState overlay();

    template<typename T>
 virtual Future<T> pushNamed(String routeName, Object arguments);

    template<typename T>
 virtual String restorablePushNamed(String routeName, Object arguments);

    template<typename T, typename TO>
 virtual Future<T> pushReplacementNamed(String routeName, Object arguments, TO result);

    template<typename T, typename TO>
 virtual String restorablePushReplacementNamed(String routeName, Object arguments, TO result);

    template<typename T, typename TO>
 virtual Future<T> popAndPushNamed(String routeName, Object arguments, TO result);

    template<typename T, typename TO>
 virtual String restorablePopAndPushNamed(String routeName, Object arguments, TO result);

    template<typename T>
 virtual Future<T> pushNamedAndRemoveUntil(String newRouteName, RoutePredicate predicate, Object arguments);

    template<typename T>
 virtual String restorablePushNamedAndRemoveUntil(String newRouteName, RoutePredicate predicate, Object arguments);

    template<typename T>
 virtual Future<T> push(Route<T> route);

    template<typename T>
 virtual String restorablePush(RestorableRouteBuilder<T> routeBuilder, Object arguments);

    template<typename T, typename TO>
 virtual Future<T> pushReplacement(Route<T> newRoute, TO result);

    template<typename T, typename TO>
 virtual String restorablePushReplacement(RestorableRouteBuilder<T> routeBuilder, Object arguments, TO result);

    template<typename T>
 virtual Future<T> pushAndRemoveUntil(Route<T> newRoute, RoutePredicate predicate);

    template<typename T>
 virtual String restorablePushAndRemoveUntil(RestorableRouteBuilder<T> newRouteBuilder, RoutePredicate predicate, Object arguments);

    template<typename T>
 virtual void replace(Route<T> newRoute, Route<Object> oldRoute);

    template<typename T>
 virtual String restorableReplace(Object arguments, RestorableRouteBuilder<T> newRouteBuilder, Route<Object> oldRoute);

    template<typename T>
 virtual void replaceRouteBelow(Route<Object> anchorRoute, Route<T> newRoute);

    template<typename T>
 virtual String restorableReplaceRouteBelow(Route<Object> anchorRoute, Object arguments, RestorableRouteBuilder<T> newRouteBuilder);

    virtual bool canPop();

    template<typename T>
 virtual Future<bool> maybePop(T result);

    template<typename T>
 virtual void pop(T result);

    virtual void popUntil(RoutePredicate predicate);

    virtual void removeRoute(Route<Object> route);

    virtual void removeRouteBelow(Route<Object> anchorRoute);

    virtual void finalizeRoute(Route<Object> route);

    virtual bool userGestureInProgress();

    virtual void didStartUserGesture();

    virtual void didStopUserGesture();

    virtual Widget build(BuildContext context);

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


    virtual int _nextPagelessRestorationScopeId();

    virtual void _updateHeroController(HeroController newHeroController);

    virtual void _updateEffectiveObservers();

    virtual void _debugCheckDuplicatedPageKeys();

    virtual Iterable<OverlayEntry> _allRouteOverlayEntries();

    virtual void _updatePages();

    virtual void _flushHistoryUpdates(bool rearrangeOverlay);

    virtual void _flushObserverNotifications();

    virtual void _flushRouteAnnouncement();

    virtual _RouteEntry _getRouteBefore(int index, _RouteEntryPredicate predicate);

    virtual int _getIndexBefore(int index, _RouteEntryPredicate predicate);

    virtual _RouteEntry _getRouteAfter(int index, _RouteEntryPredicate predicate);

    template<typename T>
 virtual Route<T> _routeNamed(String name, bool allowNull, Object arguments);

    virtual bool _debugCheckIsPagelessRoute(Route<Object> route);

    virtual bool _debugIsStaticCallback(std::function<void ()> callback);

    virtual void _pushEntry(_RouteEntry entry);

    virtual void _afterNavigation(Route<Object> route);

    template<typename TO>
 virtual void _pushReplacementEntry(_RouteEntry entry, TO result);

    virtual void _pushEntryAndRemoveUntil(_RouteEntry entry, RoutePredicate predicate);

    virtual void _replaceEntry(_RouteEntry entry, Route<Object> oldRoute);

    virtual void _replaceEntryBelow(_RouteEntry entry, Route<Object> anchorRoute);

    template<typename T>
 virtual Route<T> _getRouteById(String id);

    virtual int _userGesturesInProgress();

    virtual void  _userGesturesInProgress(int value);

    virtual void _handlePointerDown(PointerDownEvent event);

    virtual void _handlePointerUpOrCancel(PointerEvent event);

    virtual void _cancelActivePointers();

};
using NavigatorState = std::shared_ptr<NavigatorStateCls>;

enum _RouteRestorationType{
    named,
    anonymous,
} // end _RouteRestorationType

class _RestorationInformationCls : public ObjectCls {
public:
    _RouteRestorationType type;


    virtual void  named(Object arguments, String name, int restorationScopeId);
    virtual void  anonymous(Object arguments, int restorationScopeId, RestorableRouteBuilder<Object> routeBuilder);
    virtual void  fromSerializableData(Object data);

    virtual int restorationScopeId();
    virtual bool isRestorable();

    virtual Object getSerializableData();

    virtual List<Object> computeSerializableData();

    virtual Route<Object> createRoute(NavigatorState navigator);
    virtual _RouteEntry toRouteEntry(NavigatorState navigator, _RouteLifecycle initialState);

private:
    Object _serializableData;


     _RestorationInformationCls(_RouteRestorationType type);

};
using _RestorationInformation = std::shared_ptr<_RestorationInformationCls>;

class _NamedRestorationInformationCls : public _RestorationInformationCls {
public:
    int restorationScopeId;

    String name;

    Object arguments;


    virtual void  fromSerializableData(List<Object> data);

    virtual List<Object> computeSerializableData();

    virtual Route<Object> createRoute(NavigatorState navigator);

private:

     _NamedRestorationInformationCls(Object arguments, String name, int restorationScopeId);

};
using _NamedRestorationInformation = std::shared_ptr<_NamedRestorationInformationCls>;

class _AnonymousRestorationInformationCls : public _RestorationInformationCls {
public:
    int restorationScopeId;

    RestorableRouteBuilder<Object> routeBuilder;

    Object arguments;


    virtual void  fromSerializableData(List<Object> data);

    virtual bool isRestorable();

    virtual List<Object> computeSerializableData();

    virtual Route<Object> createRoute(NavigatorState navigator);

private:

     _AnonymousRestorationInformationCls(Object arguments, int restorationScopeId, RestorableRouteBuilder<Object> routeBuilder);

};
using _AnonymousRestorationInformation = std::shared_ptr<_AnonymousRestorationInformationCls>;

class _HistoryPropertyCls : public RestorablePropertyCls<Map<String, List<Object>>> {
public:

    virtual void update(List<_RouteEntry> history);

    virtual void clear();

    virtual bool hasData();

    virtual List<_RouteEntry> restoreEntriesForPage(_RouteEntry page, NavigatorState navigator);

    virtual Map<String, List<Object>> createDefaultValue();

    virtual Map<String, List<Object>> fromPrimitives(Object data);

    virtual void initWithValue(Map<String, List<Object>> value);

    virtual Object toPrimitives();

    virtual bool enabled();

private:
    Map<String, List<Object>> _pageToPagelessRoutes;


    virtual void _finalizePage(List<Object> routes, _RouteEntry page, Map<String, List<Object>> pageToRoutes, Set<String> pagesToRemove);

    virtual bool _debugMapsEqual(Map<String, List<Object>> a, Map<String, List<Object>> b);

};
using _HistoryProperty = std::shared_ptr<_HistoryPropertyCls>;

template<typename T>
class RestorableRouteFutureCls : public RestorablePropertyCls<String> {
public:
    NavigatorFinderCallback navigatorFinder;

    RoutePresentationCallback onPresent;

    RouteCompletionCallback<T> onComplete;


     RestorableRouteFutureCls(NavigatorFinderCallback navigatorFinder, RouteCompletionCallback<T> onComplete, RoutePresentationCallback onPresent);

    virtual void present(Object arguments);

    virtual bool isPresent();

    virtual Route<T> route();

    virtual String createDefaultValue();

    virtual void initWithValue(String value);

    virtual Object toPrimitives();

    virtual String fromPrimitives(Object data);

    virtual void dispose();

    virtual bool enabled();

private:
    Route<T> _route;

    bool _disposed;


    virtual NavigatorState _navigator();

    virtual void _hookOntoRouteFuture(String id);

    static NavigatorState _defaultNavigatorFinder(BuildContext context);

};
template<typename T>
using RestorableRouteFuture = std::shared_ptr<RestorableRouteFutureCls<T>>;


#endif