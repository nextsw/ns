#ifndef HEROES_H
#define HEROES_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "binding.hpp"
#include "framework.hpp"
#include "implicit_animations.hpp"
#include "media_query.hpp"
#include "navigator.hpp"
#include "overlay.hpp"
#include "pages.hpp"
#include "routes.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"



enum HeroFlightDirection{
    push,
    pop,
} // end HeroFlightDirection

class Hero : StatefulWidget {
public:
    Object tag;

    CreateRectTween createRectTween;

    Widget child;

    HeroFlightShuttleBuilder flightShuttleBuilder;

    HeroPlaceholderBuilder placeholderBuilder;

    bool transitionOnUserGestures;


     Hero(Widget child, CreateRectTween createRectTween, HeroFlightShuttleBuilder flightShuttleBuilder, Unknown, HeroPlaceholderBuilder placeholderBuilder, Object tag, bool transitionOnUserGestures);

    State<Hero> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static Map<Object, _HeroState> _allHeroesFor(BuildContext context, bool isUserGestureTransition, NavigatorState navigator);

};

class _HeroState : State<Hero> {
public:

    void startFlight(bool shouldIncludedChildInPlaceholder);

    void endFlight(bool keepPlaceholder);

    Widget build(BuildContext context);

private:
    GlobalKey _key;

    Size _placeholderSize;

    bool _shouldIncludeChild;


};

class _HeroFlightManifest {
public:
    HeroFlightDirection type;

    OverlayState overlay;

    Size navigatorSize;

    PageRoute<dynamic> fromRoute;

    PageRoute<dynamic> toRoute;

    _HeroState fromHero;

    _HeroState toHero;

    CreateRectTween createRectTween;

    HeroFlightShuttleBuilder shuttleBuilder;

    bool isUserGestureTransition;

    bool isDiverted;

    Rect fromHeroLocation;

    Rect toHeroLocation;

    bool isValid;


    Object tag();

    Animation<double> animation();

    Tween<Rect> createHeroRectTween(Rect begin, Rect end);

    String toString();

private:

     _HeroFlightManifest(CreateRectTween createRectTween, _HeroState fromHero, PageRoute<dynamic> fromRoute, bool isDiverted, bool isUserGestureTransition, Size navigatorSize, OverlayState overlay, HeroFlightShuttleBuilder shuttleBuilder, _HeroState toHero, PageRoute<dynamic> toRoute, HeroFlightDirection type);

    static Rect _boundingBoxFor(BuildContext ancestorContext, BuildContext context);

};

class _HeroFlight {
public:
    _OnFlightEnded onFlightEnded;

    Tween<Rect> heroRectTween;

    Widget shuttle;

    _HeroFlightManifest manifest;

    OverlayEntry overlayEntry;


    void onTick();

    void start(_HeroFlightManifest initialManifest);

    void divert(_HeroFlightManifest newManifest);

    void abort();

    String toString();

private:
    Animation<double> _heroOpacity;

    ProxyAnimation _proxyAnimation;

    bool _aborted;

    static Animatable<double> _reverseTween;

    bool _scheduledPerformAnimationUpdate;


     _HeroFlight(_OnFlightEnded onFlightEnded);

    Widget _buildOverlay(BuildContext context);

    void _performAnimationUpdate(AnimationStatus status);

    void _handleAnimationUpdate(AnimationStatus status);

};

class HeroController : NavigatorObserver {
public:
    CreateRectTween createRectTween;


     HeroController(CreateRectTween createRectTween);

    void didPush(Route<dynamic> previousRoute, Route<dynamic> route);

    void didPop(Route<dynamic> previousRoute, Route<dynamic> route);

    void didReplace(Route<dynamic> newRoute, Route<dynamic> oldRoute);

    void didStartUserGesture(Route<dynamic> previousRoute, Route<dynamic> route);

    void didStopUserGesture();

private:
    Map<Object, _HeroFlight> _flights;


    void _maybeStartHeroTransition(HeroFlightDirection flightType, Route<dynamic> fromRoute, bool isUserGestureTransition, Route<dynamic> toRoute);

    void _startHeroTransition(HeroFlightDirection flightType, PageRoute<dynamic> from, bool isUserGestureTransition, PageRoute<dynamic> to);

    void _handleFlightEnded(_HeroFlight flight);

    Widget _defaultHeroFlightShuttleBuilder(Animation<double> animation, BuildContext flightContext, HeroFlightDirection flightDirection, BuildContext fromHeroContext, BuildContext toHeroContext);

};

class HeroMode : StatelessWidget {
public:
    Widget child;

    bool enabled;


     HeroMode(Widget child, bool enabled, Unknown);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif