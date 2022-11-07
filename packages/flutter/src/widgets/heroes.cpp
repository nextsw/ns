#include "heroes.hpp"
Hero::Hero(Widget child, CreateRectTween createRectTween, HeroFlightShuttleBuilder flightShuttleBuilder, Unknown, HeroPlaceholderBuilder placeholderBuilder, Object tag, bool transitionOnUserGestures) {
    {
        assert(tag != nullptr);
        assert(transitionOnUserGestures != nullptr);
        assert(child != nullptr);
    }
}

State<Hero> Hero::createState() {
    return _HeroState();
}

void Hero::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Object>DiagnosticsProperty("tag", tag));
}

Map<Object, _HeroState> Hero::_allHeroesFor(BuildContext context, bool isUserGestureTransition, NavigatorState navigator) {
    assert(context != nullptr);
    assert(isUserGestureTransition != nullptr);
    assert(navigator != nullptr);
    Map<Object, _HeroState> result = ;
    ;
    ;
    context.visitChildElements(visitor);
    return result;
}

void _HeroState::startFlight(bool shouldIncludedChildInPlaceholder) {
    _shouldIncludeChild = shouldIncludedChildInPlaceholder;
    assert(mounted);
    RenderBox box = (;
    assert(box != nullptr && box.hasSize);
    setState();
}

void _HeroState::endFlight(bool keepPlaceholder) {
    if (keepPlaceholder || _placeholderSize == nullptr) {
        return;
    }
    _placeholderSize = nullptr;
    if (mounted) {
        setState();
    }
}

Widget _HeroState::build(BuildContext context) {
    assert(context.<Hero>findAncestorWidgetOfExactType() == nullptr, "A Hero widget cannot be the descendant of another Hero widget.");
    bool showPlaceholder = _placeholderSize != nullptr;
    if (showPlaceholder && widget.placeholderBuilder != nullptr) {
        return widget.placeholderBuilder!(context, _placeholderSize!, widget.child);
    }
    if (showPlaceholder && !_shouldIncludeChild) {
        return SizedBox(_placeholderSize!.width, _placeholderSize!.height);
    }
    return SizedBox(_placeholderSize?.width, _placeholderSize?.height, Offstage(showPlaceholder, TickerMode(!showPlaceholder, KeyedSubtree(_key, widget.child))));
}

Object _HeroFlightManifest::tag() {
    return fromHero.widget.tag;
}

Animation<double> _HeroFlightManifest::animation() {
    return CurvedAnimation((type == HeroFlightDirection.push)? toRoute.animation! : fromRoute.animation!, Curves.fastOutSlowIn, isDiverted? nullptr : Curves.fastOutSlowIn.flipped);
}

Tween<Rect> _HeroFlightManifest::createHeroRectTween(Rect begin, Rect end) {
    CreateRectTween createRectTween = toHero.widget.createRectTween ?? this.createRectTween;
    return createRectTween?.call(begin, end) ?? RectTween(begin, end);
}

String _HeroFlightManifest::toString() {
    return "_HeroFlightManifest($type tag: $tag from route: ${fromRoute.settings} to route: ${toRoute.settings} with hero: $fromHero to $toHero)${isValid ? '' : ', INVALID'}";
}

_HeroFlightManifest::_HeroFlightManifest(CreateRectTween createRectTween, _HeroState fromHero, PageRoute<dynamic> fromRoute, bool isDiverted, bool isUserGestureTransition, Size navigatorSize, OverlayState overlay, HeroFlightShuttleBuilder shuttleBuilder, _HeroState toHero, PageRoute<dynamic> toRoute, HeroFlightDirection type) {
    {
        assert(fromHero.widget.tag == toHero.widget.tag);
    }
}

Rect _HeroFlightManifest::_boundingBoxFor(BuildContext ancestorContext, BuildContext context) {
    assert(ancestorContext != nullptr);
    RenderBox box = (;
    assert(box != nullptr && box.hasSize && box.size.isFinite);
    return MatrixUtils.transformRect(box.getTransformTo(ancestorContext?.findRenderObject()), Offset.zero & box.size);
}

void _HeroFlight::onTick() {
    RenderBox toHeroBox = (!_aborted && manifest.toHero.mounted)? ( : nullptr;
    Offset toHeroOrigin = toHeroBox != nullptr && toHeroBox.attached && toHeroBox.hasSize? toHeroBox.localToGlobal(Offset.zero() : nullptr;
    if (toHeroOrigin != nullptr && toHeroOrigin.isFinite) {
        if (toHeroOrigin != heroRectTween.end!.topLeft) {
            Rect heroRectEnd = toHeroOrigin & heroRectTween.end!.size;
            heroRectTween = manifest.createHeroRectTween(heroRectTween.begin, heroRectEnd);
        }
    } else     {
        if (_heroOpacity.isCompleted) {
        _heroOpacity = _proxyAnimation.drive(_reverseTween.chain(CurveTween(Interval(_proxyAnimation.value, 1.0))));
    }
;
    }    _aborted = toHeroOrigin == nullptr || !toHeroOrigin.isFinite;
}

void _HeroFlight::start(_HeroFlightManifest initialManifest) {
    assert(!_aborted);
    assert(());
    manifest = initialManifest;
    bool shouldIncludeChildInPlaceholder;
    ;
    heroRectTween = manifest.createHeroRectTween(manifest.fromHeroLocation, manifest.toHeroLocation);
    manifest.fromHero.startFlight(shouldIncludeChildInPlaceholder);
    manifest.toHero.startFlight();
    manifest.overlay.insert(overlayEntry = OverlayEntry(_buildOverlay));
    _proxyAnimation.addListener(onTick);
}

void _HeroFlight::divert(_HeroFlightManifest newManifest) {
    assert(manifest.tag == newManifest.tag);
    if (manifest.type == HeroFlightDirection.push && newManifest.type == HeroFlightDirection.pop) {
        assert(newManifest.animation.status == AnimationStatus.reverse);
        assert(manifest.fromHero == newManifest.toHero);
        assert(manifest.toHero == newManifest.fromHero);
        assert(manifest.fromRoute == newManifest.toRoute);
        assert(manifest.toRoute == newManifest.fromRoute);
        _proxyAnimation.parent = ReverseAnimation(newManifest.animation);
        heroRectTween = <Rect>ReverseTween(heroRectTween);
    } else     {
        if (manifest.type == HeroFlightDirection.pop && newManifest.type == HeroFlightDirection.push) {
        assert(newManifest.animation.status == AnimationStatus.forward);
        assert(manifest.toHero == newManifest.fromHero);
        assert(manifest.toRoute == newManifest.fromRoute);
        _proxyAnimation.parent = newManifest.animation.drive(<double>Tween(manifest.animation.value, 1.0));
        if (manifest.fromHero != newManifest.toHero) {
            manifest.fromHero.endFlight(true);
            newManifest.toHero.startFlight();
            heroRectTween = manifest.createHeroRectTween(heroRectTween.end, newManifest.toHeroLocation);
        } else {
            heroRectTween = manifest.createHeroRectTween(heroRectTween.end, heroRectTween.begin);
        }
    } else {
        assert(manifest.fromHero != newManifest.fromHero);
        assert(manifest.toHero != newManifest.toHero);
        heroRectTween = manifest.createHeroRectTween(heroRectTween.evaluate(_proxyAnimation), newManifest.toHeroLocation);
        shuttle = nullptr;
        if (newManifest.type == HeroFlightDirection.pop) {
            _proxyAnimation.parent = ReverseAnimation(newManifest.animation);
        } else {
            _proxyAnimation.parent = newManifest.animation;
        }
        manifest.fromHero.endFlight(true);
        manifest.toHero.endFlight(true);
        newManifest.fromHero.startFlight(newManifest.type == HeroFlightDirection.push);
        newManifest.toHero.startFlight();
        overlayEntry!.markNeedsBuild();
    }
;
    }    manifest = newManifest;
}

void _HeroFlight::abort() {
    _aborted = true;
}

String _HeroFlight::toString() {
    RouteSettings from = manifest.fromRoute.settings;
    RouteSettings to = manifest.toRoute.settings;
    Object tag = manifest.tag;
    return "HeroFlight(for: $tag, from: $from, to: $to ${_proxyAnimation.parent})";
}

_HeroFlight::_HeroFlight(_OnFlightEnded onFlightEnded) {
    {
        _proxyAnimation = ;
    }
}

Widget _HeroFlight::_buildOverlay(BuildContext context) {
    assert(manifest != nullptr);
    shuttle = manifest.shuttleBuilder(context, manifest.animation, manifest.type, manifest.fromHero.context, manifest.toHero.context);
    assert(shuttle != nullptr);
    return AnimatedBuilder(_proxyAnimation, shuttle, );
}

void _HeroFlight::_performAnimationUpdate(AnimationStatus status) {
    if (status == AnimationStatus.completed || status == AnimationStatus.dismissed) {
        _proxyAnimation.parent = nullptr;
        assert(overlayEntry != nullptr);
        overlayEntry!.remove();
        overlayEntry = nullptr;
        manifest.fromHero.endFlight(status == AnimationStatus.completed);
        manifest.toHero.endFlight(status == AnimationStatus.dismissed);
        onFlightEnded(this);
        _proxyAnimation.removeListener(onTick);
    }
}

void _HeroFlight::_handleAnimationUpdate(AnimationStatus status) {
    if (manifest.fromRoute.navigator?.userGestureInProgress != true) {
        _performAnimationUpdate(status);
        return;
    }
    if (_scheduledPerformAnimationUpdate) {
        return;
    }
    NavigatorState navigator = manifest.fromRoute.navigator!;
    ;
    assert(navigator.userGestureInProgress);
    _scheduledPerformAnimationUpdate = true;
    navigator.userGestureInProgressNotifier.addListener(delayedPerformAnimationUpdate);
}

void HeroController::didPush(Route<dynamic> previousRoute, Route<dynamic> route) {
    assert(navigator != nullptr);
    assert(route != nullptr);
    _maybeStartHeroTransition(previousRoute, route, HeroFlightDirection.push, false);
}

void HeroController::didPop(Route<dynamic> previousRoute, Route<dynamic> route) {
    assert(navigator != nullptr);
    assert(route != nullptr);
    if (!navigator!.userGestureInProgress) {
        _maybeStartHeroTransition(route, previousRoute, HeroFlightDirection.pop, false);
    }
}

void HeroController::didReplace(Route<dynamic> newRoute, Route<dynamic> oldRoute) {
    assert(navigator != nullptr);
    if (newRoute?.isCurrent ?? false) {
        _maybeStartHeroTransition(oldRoute, newRoute, HeroFlightDirection.push, false);
    }
}

void HeroController::didStartUserGesture(Route<dynamic> previousRoute, Route<dynamic> route) {
    assert(navigator != nullptr);
    assert(route != nullptr);
    _maybeStartHeroTransition(route, previousRoute, HeroFlightDirection.pop, true);
}

void HeroController::didStopUserGesture() {
    if (navigator!.userGestureInProgress) {
        return;
    }
    ;
    List<_HeroFlight> invalidFlights = _flights.values.where(isInvalidFlight).toList(false);
    for (_HeroFlight flight : invalidFlights) {
        flight._handleAnimationUpdate(AnimationStatus.dismissed);
    }
}

void HeroController::_maybeStartHeroTransition(HeroFlightDirection flightType, Route<dynamic> fromRoute, bool isUserGestureTransition, Route<dynamic> toRoute) {
    if (toRoute != fromRoute && toRoute is PageRoute<dynamic> && fromRoute is PageRoute<dynamic>) {
        PageRoute<dynamic> from = fromRoute;
        PageRoute<dynamic> to = toRoute;
        ;
        if (isUserGestureTransition && flightType == HeroFlightDirection.pop && to.maintainState) {
            _startHeroTransition(from, to, flightType, isUserGestureTransition);
        } else {
            to.offstage = to.animation!.value == 0.0;
            WidgetsBinding.instance.addPostFrameCallback();
        }
    }
}

void HeroController::_startHeroTransition(HeroFlightDirection flightType, PageRoute<dynamic> from, bool isUserGestureTransition, PageRoute<dynamic> to) {
    to.offstage = false;
    NavigatorState navigator = this.navigator;
    OverlayState overlay = navigator?.overlay;
    if (navigator == nullptr || overlay == nullptr) {
        return;
    }
    RenderObject navigatorRenderObject = navigator.context.findRenderObject();
    if (navigatorRenderObject is! RenderBox) {
        assert(false, "Navigator $navigator has an invalid RenderObject type ${navigatorRenderObject.runtimeType}.");
        return;
    }
    assert(navigatorRenderObject.hasSize);
    BuildContext fromSubtreeContext = from.subtreeContext;
    Map<Object, _HeroState> fromHeroes = fromSubtreeContext != nullptr? Hero._allHeroesFor(fromSubtreeContext, isUserGestureTransition, navigator) : const ;
    BuildContext toSubtreeContext = to.subtreeContext;
    Map<Object, _HeroState> toHeroes = toSubtreeContext != nullptr? Hero._allHeroesFor(toSubtreeContext, isUserGestureTransition, navigator) : const ;
    for (MapEntry<Object, _HeroState> fromHeroEntry : fromHeroes.entries) {
        Object tag = fromHeroEntry.key;
        _HeroState fromHero = fromHeroEntry.value;
        _HeroState toHero = toHeroes[tag];
        _HeroFlight existingFlight = _flights[tag];
        _HeroFlightManifest manifest = toHero == nullptr? nullptr : _HeroFlightManifest(flightType, overlay, navigatorRenderObject.size, from, to, fromHero, toHero, createRectTween, toHero.widget.flightShuttleBuilder ?? fromHero.widget.flightShuttleBuilder ?? _defaultHeroFlightShuttleBuilder, isUserGestureTransition, existingFlight != nullptr);
        if (manifest != nullptr && manifest.isValid) {
            toHeroes.remove(tag);
            if (existingFlight != nullptr) {
                existingFlight.divert(manifest);
            } else {
                _flights[tag] = ;
            }
        } else {
            existingFlight?.abort();
        }
    }
    for (_HeroState toHero : toHeroes.values) {
        toHero.endFlight();
    }
}

void HeroController::_handleFlightEnded(_HeroFlight flight) {
    _flights.remove(flight.manifest.tag);
}

Widget HeroController::_defaultHeroFlightShuttleBuilder(Animation<double> animation, BuildContext flightContext, HeroFlightDirection flightDirection, BuildContext fromHeroContext, BuildContext toHeroContext) {
    Hero toHero = (;
    MediaQueryData toMediaQueryData = MediaQuery.maybeOf(toHeroContext);
    MediaQueryData fromMediaQueryData = MediaQuery.maybeOf(fromHeroContext);
    if (toMediaQueryData == nullptr || fromMediaQueryData == nullptr) {
        return toHero.child;
    }
    EdgeInsets fromHeroPadding = fromMediaQueryData.padding;
    EdgeInsets toHeroPadding = toMediaQueryData.padding;
    return AnimatedBuilder(animation, );
}

HeroMode::HeroMode(Widget child, bool enabled, Unknown) {
    {
        assert(child != nullptr);
        assert(enabled != nullptr);
    }
}

Widget HeroMode::build(BuildContext context) {
    return child;
}

void HeroMode::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("mode"enabled, "enabled", "disabled", true));
}
