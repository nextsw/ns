#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_HEROES
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_HEROES
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
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

class HeroCls : public StatefulWidgetCls {
public:
    Object tag;

    CreateRectTween createRectTween;

    Widget child;

    HeroFlightShuttleBuilder flightShuttleBuilder;

    HeroPlaceholderBuilder placeholderBuilder;

    bool transitionOnUserGestures;


     HeroCls(Widget child, CreateRectTween createRectTween, HeroFlightShuttleBuilder flightShuttleBuilder, Key key, HeroPlaceholderBuilder placeholderBuilder, Object tag, bool transitionOnUserGestures);

    virtual State<Hero> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

    static Map<Object, _HeroState> _allHeroesFor(BuildContext context, bool isUserGestureTransition, NavigatorState navigator);

};
using Hero = std::shared_ptr<HeroCls>;

class _HeroStateCls : public StateCls<Hero> {
public:

    virtual void startFlight(bool shouldIncludedChildInPlaceholder);

    virtual void endFlight(bool keepPlaceholder);

    virtual Widget build(BuildContext context);

private:
    GlobalKey<any> _key;

    Size _placeholderSize;

    bool _shouldIncludeChild;


};
using _HeroState = std::shared_ptr<_HeroStateCls>;

class _HeroFlightManifestCls : public ObjectCls {
public:
    HeroFlightDirection type;

    OverlayState overlay;

    Size navigatorSize;

    PageRoute<Object> fromRoute;

    PageRoute<Object> toRoute;

    _HeroState fromHero;

    _HeroState toHero;

    CreateRectTween createRectTween;

    HeroFlightShuttleBuilder shuttleBuilder;

    bool isUserGestureTransition;

    bool isDiverted;

    Rect fromHeroLocation;

    Rect toHeroLocation;

    bool isValid;


    virtual Object tag();

    virtual Animation<double> animation();

    virtual Tween<Rect> createHeroRectTween(Rect begin, Rect end);

    virtual String toString();

private:

     _HeroFlightManifestCls(CreateRectTween createRectTween, _HeroState fromHero, PageRoute<Object> fromRoute, bool isDiverted, bool isUserGestureTransition, Size navigatorSize, OverlayState overlay, HeroFlightShuttleBuilder shuttleBuilder, _HeroState toHero, PageRoute<Object> toRoute, HeroFlightDirection type);

    static Rect _boundingBoxFor(BuildContext context, BuildContext ancestorContext);

};
using _HeroFlightManifest = std::shared_ptr<_HeroFlightManifestCls>;

class _HeroFlightCls : public ObjectCls {
public:
    _OnFlightEnded onFlightEnded;

    Tween<Rect> heroRectTween;

    Widget shuttle;

    _HeroFlightManifest manifest;

    OverlayEntry overlayEntry;


    virtual void onTick();

    virtual void start(_HeroFlightManifest initialManifest);

    virtual void divert(_HeroFlightManifest newManifest);

    virtual void abort();

    virtual String toString();

private:
    Animation<double> _heroOpacity;

    ProxyAnimation _proxyAnimation;

    bool _aborted;

    static Animatable<double> _reverseTween;

    bool _scheduledPerformAnimationUpdate;


     _HeroFlightCls(_OnFlightEnded onFlightEnded);

    virtual Widget _buildOverlay(BuildContext context);

    virtual void _performAnimationUpdate(AnimationStatus status);

    virtual void _handleAnimationUpdate(AnimationStatus status);

};
using _HeroFlight = std::shared_ptr<_HeroFlightCls>;

class HeroControllerCls : public NavigatorObserverCls {
public:
    CreateRectTween createRectTween;


     HeroControllerCls(CreateRectTween createRectTween);
    virtual void didPush(Route<Object> route, Route<Object> previousRoute);

    virtual void didPop(Route<Object> route, Route<Object> previousRoute);

    virtual void didReplace(Route<Object> newRoute, Route<Object> oldRoute);

    virtual void didStartUserGesture(Route<Object> route, Route<Object> previousRoute);

    virtual void didStopUserGesture();

private:
    Map<Object, _HeroFlight> _flights;


    virtual void _maybeStartHeroTransition(Route<Object> fromRoute, Route<Object> toRoute, HeroFlightDirection flightType, bool isUserGestureTransition);

    virtual void _startHeroTransition(PageRoute<Object> from, PageRoute<Object> to, HeroFlightDirection flightType, bool isUserGestureTransition);

    virtual void _handleFlightEnded(_HeroFlight flight);

    virtual Widget _defaultHeroFlightShuttleBuilder(BuildContext flightContext, Animation<double> animation, HeroFlightDirection flightDirection, BuildContext fromHeroContext, BuildContext toHeroContext);

};
using HeroController = std::shared_ptr<HeroControllerCls>;

class HeroModeCls : public StatelessWidgetCls {
public:
    Widget child;

    bool enabled;


     HeroModeCls(Widget child, bool enabled, Key key);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using HeroMode = std::shared_ptr<HeroModeCls>;


#endif