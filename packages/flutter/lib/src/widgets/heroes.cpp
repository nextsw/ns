#include "heroes.hpp"
HeroCls::HeroCls(Widget child, CreateRectTween createRectTween, HeroFlightShuttleBuilder flightShuttleBuilder, Unknown key, HeroPlaceholderBuilder placeholderBuilder, Object tag, bool transitionOnUserGestures) {
    {
        assert(tag != nullptr);
        assert(transitionOnUserGestures != nullptr);
        assert(child != nullptr);
    }
}

State<Hero> HeroCls::createState() {
    return make<_HeroStateCls>();
}

void HeroCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Object>make<DiagnosticsPropertyCls>(__s("tag"), tag));
}

Map<Object, _HeroState> HeroCls::_allHeroesFor(BuildContext context, bool isUserGestureTransition, NavigatorState navigator) {
    assert(context != nullptr);
    assert(isUserGestureTransition != nullptr);
    assert(navigator != nullptr);
    Map<Object, _HeroState> result = makeMap(makeList(), makeList();
    InlineMethod;
    InlineMethod;
    context->visitChildElements(visitor);
    return result;
}

void _HeroStateCls::startFlight(bool shouldIncludedChildInPlaceholder) {
    _shouldIncludeChild = shouldIncludedChildInPlaceholder;
    assert(mounted());
    RenderBox box = as<RenderBox>(context()->findRenderObject()!);
    assert(box != nullptr && box->hasSize());
    setState([=] () {
        _placeholderSize = box->size();
    });
}

void _HeroStateCls::endFlight(bool keepPlaceholder) {
    if (keepPlaceholder || _placeholderSize == nullptr) {
        return;
    }
    _placeholderSize = nullptr;
    if (mounted()) {
        setState([=] () {
        });
    }
}

Widget _HeroStateCls::build(BuildContext context) {
    assert(context-><Hero>findAncestorWidgetOfExactType() == nullptr, __s("A Hero widget cannot be the descendant of another Hero widget."));
    bool showPlaceholder = _placeholderSize != nullptr;
    if (showPlaceholder && widget()->placeholderBuilder != nullptr) {
        return widget()->placeholderBuilder!(context, _placeholderSize!, widget()->child);
    }
    if (showPlaceholder && !_shouldIncludeChild) {
        return make<SizedBoxCls>(_placeholderSize!->width(), _placeholderSize!->height());
    }
    return make<SizedBoxCls>(_placeholderSize?->width(), _placeholderSize?->height(), make<OffstageCls>(showPlaceholder, make<TickerModeCls>(!showPlaceholder, make<KeyedSubtreeCls>(_key, widget()->child))));
}

Object _HeroFlightManifestCls::tag() {
    return fromHero->widget()->tag();
}

Animation<double> _HeroFlightManifestCls::animation() {
    return make<CurvedAnimationCls>((type == HeroFlightDirectionCls::push)? toRoute->animation()! : fromRoute->animation()!, CurvesCls::fastOutSlowIn, isDiverted? nullptr : CurvesCls::fastOutSlowIn->flipped);
}

Tween<Rect> _HeroFlightManifestCls::createHeroRectTween(Rect begin, Rect end) {
    CreateRectTween createRectTween = toHero->widget()->createRectTween | this->createRectTween;
    return createRectTween?->call(begin, end) | make<RectTweenCls>(begin, end);
}

String _HeroFlightManifestCls::toString() {
    return __s("_HeroFlightManifest($type tag: $tag from route: ${fromRoute.settings} to route: ${toRoute.settings} with hero: $fromHero to $toHero)${isValid ? '' : ', INVALID'}");
}

_HeroFlightManifestCls::_HeroFlightManifestCls(CreateRectTween createRectTween, _HeroState fromHero, PageRoute<dynamic> fromRoute, bool isDiverted, bool isUserGestureTransition, Size navigatorSize, OverlayState overlay, HeroFlightShuttleBuilder shuttleBuilder, _HeroState toHero, PageRoute<dynamic> toRoute, HeroFlightDirection type) {
    {
        assert(fromHero->widget()->tag() == toHero->widget()->tag());
    }
}

Rect _HeroFlightManifestCls::_boundingBoxFor(BuildContext context, BuildContext ancestorContext) {
    assert(ancestorContext != nullptr);
    RenderBox box = as<RenderBox>(context->findRenderObject()!);
    assert(box != nullptr && box->hasSize() && box->size()->isFinite());
    return MatrixUtilsCls->transformRect(box->getTransformTo(ancestorContext?->findRenderObject()), OffsetCls::zero & box->size());
}

void _HeroFlightCls::onTick() {
    RenderBox toHeroBox = (!_aborted && manifest->toHero->mounted())? as<RenderBox>(manifest->toHero->context()->findRenderObject()) : nullptr;
    Offset toHeroOrigin = toHeroBox != nullptr && toHeroBox->attached() && toHeroBox->hasSize()? toHeroBox->localToGlobal(OffsetCls::zero, as<RenderBox>(manifest->toRoute->subtreeContext()?->findRenderObject())) : nullptr;
    if (toHeroOrigin != nullptr && toHeroOrigin->isFinite()) {
        if (toHeroOrigin != heroRectTween->end!->topLeft) {
            Rect heroRectEnd = toHeroOrigin & heroRectTween->end!->size;
            heroRectTween = manifest->createHeroRectTween(heroRectTween->begin, heroRectEnd);
        }
    } else {
        if (_heroOpacity->isCompleted()) {
        _heroOpacity = _proxyAnimation->drive(_reverseTween->chain(make<CurveTweenCls>(make<IntervalCls>(_proxyAnimation->value(), 1.0))));
    }
;
    }    _aborted = toHeroOrigin == nullptr || !toHeroOrigin->isFinite();
}

void _HeroFlightCls::start(_HeroFlightManifest initialManifest) {
    assert(!_aborted);
    assert([=] () {
        Animation<double> initial = initialManifest->animation();
        assert(initial != nullptr);
        HeroFlightDirection type = initialManifest->type;
        assert(type != nullptr);
        ;
    }());
    manifest = initialManifest;
    bool shouldIncludeChildInPlaceholder;
    ;
    heroRectTween = manifest->createHeroRectTween(manifest->fromHeroLocation, manifest->toHeroLocation);
    manifest->fromHero->startFlight(shouldIncludeChildInPlaceholder);
    manifest->toHero->startFlight();
    manifest->overlay->insert(overlayEntry = make<OverlayEntryCls>(_buildOverlay));
    _proxyAnimation->addListener(onTick);
}

void _HeroFlightCls::divert(_HeroFlightManifest newManifest) {
    assert(manifest->tag() == newManifest->tag());
    if (manifest->type == HeroFlightDirectionCls::push && newManifest->type == HeroFlightDirectionCls::pop) {
        assert(newManifest->animation()->status() == AnimationStatusCls::reverse);
        assert(manifest->fromHero == newManifest->toHero);
        assert(manifest->toHero == newManifest->fromHero);
        assert(manifest->fromRoute == newManifest->toRoute);
        assert(manifest->toRoute == newManifest->fromRoute);
        _proxyAnimation->parent() = make<ReverseAnimationCls>(newManifest->animation());
        heroRectTween = <Rect>make<ReverseTweenCls>(heroRectTween);
    } else {
        if (manifest->type == HeroFlightDirectionCls::pop && newManifest->type == HeroFlightDirectionCls::push) {
        assert(newManifest->animation()->status() == AnimationStatusCls::forward);
        assert(manifest->toHero == newManifest->fromHero);
        assert(manifest->toRoute == newManifest->fromRoute);
        _proxyAnimation->parent() = newManifest->animation()->drive(<double>make<TweenCls>(manifest->animation()->value(), 1.0));
        if (manifest->fromHero != newManifest->toHero) {
            manifest->fromHero->endFlight(true);
            newManifest->toHero->startFlight();
            heroRectTween = manifest->createHeroRectTween(heroRectTween->end, newManifest->toHeroLocation);
        } else {
            heroRectTween = manifest->createHeroRectTween(heroRectTween->end, heroRectTween->begin);
        }
    } else {
        assert(manifest->fromHero != newManifest->fromHero);
        assert(manifest->toHero != newManifest->toHero);
        heroRectTween = manifest->createHeroRectTween(heroRectTween->evaluate(_proxyAnimation), newManifest->toHeroLocation);
        shuttle = nullptr;
        if (newManifest->type == HeroFlightDirectionCls::pop) {
            _proxyAnimation->parent() = make<ReverseAnimationCls>(newManifest->animation());
        } else {
            _proxyAnimation->parent() = newManifest->animation();
        }
        manifest->fromHero->endFlight(true);
        manifest->toHero->endFlight(true);
        newManifest->fromHero->startFlight(newManifest->type == HeroFlightDirectionCls::push);
        newManifest->toHero->startFlight();
        overlayEntry!->markNeedsBuild();
    }
;
    }    manifest = newManifest;
}

void _HeroFlightCls::abort() {
    _aborted = true;
}

String _HeroFlightCls::toString() {
    RouteSettings from = manifest->fromRoute->settings();
    RouteSettings to = manifest->toRoute->settings();
    Object tag = manifest->tag();
    return __s("HeroFlight(for: $tag, from: $from, to: $to ${_proxyAnimation.parent})");
}

_HeroFlightCls::_HeroFlightCls(_OnFlightEnded onFlightEnded) {
    {
            auto _c1 = make<ProxyAnimationCls>();    _c1.addStatusListener(_handleAnimationUpdate);_proxyAnimation = _c1;
    }
}

Widget _HeroFlightCls::_buildOverlay(BuildContext context) {
    assert(manifest != nullptr);
    shuttle |= manifest->shuttleBuilder(context, manifest->animation(), manifest->type, manifest->fromHero->context, manifest->toHero->context);
    assert(shuttle != nullptr);
    return make<AnimatedBuilderCls>(_proxyAnimation, shuttle, [=] (BuildContext context,Widget child) {
        Rect rect = heroRectTween->evaluate(_proxyAnimation)!;
        RelativeRect offsets = RelativeRectCls->fromSize(rect, manifest->navigatorSize);
        return make<PositionedCls>(offsets->top, offsets->right, offsets->bottom, offsets->left, make<IgnorePointerCls>(make<FadeTransitionCls>(_heroOpacity, child)));
    });
}

void _HeroFlightCls::_performAnimationUpdate(AnimationStatus status) {
    if (status == AnimationStatusCls::completed || status == AnimationStatusCls::dismissed) {
        _proxyAnimation->parent() = nullptr;
        assert(overlayEntry != nullptr);
        overlayEntry!->remove();
        overlayEntry = nullptr;
        manifest->fromHero->endFlight(status == AnimationStatusCls::completed);
        manifest->toHero->endFlight(status == AnimationStatusCls::dismissed);
        onFlightEnded(this);
        _proxyAnimation->removeListener(onTick);
    }
}

void _HeroFlightCls::_handleAnimationUpdate(AnimationStatus status) {
    if (manifest->fromRoute->navigator()?->userGestureInProgress() != true) {
        _performAnimationUpdate(status);
        return;
    }
    if (_scheduledPerformAnimationUpdate) {
        return;
    }
    NavigatorState navigator = manifest->fromRoute->navigator()!;
    InlineMethod;
    assert(navigator->userGestureInProgress());
    _scheduledPerformAnimationUpdate = true;
    navigator->userGestureInProgressNotifier->addListener(delayedPerformAnimationUpdate);
}

void HeroControllerCls::didPush(Route<dynamic> route, Route<dynamic> previousRoute) {
    assert(navigator() != nullptr);
    assert(route != nullptr);
    _maybeStartHeroTransition(previousRoute, route, HeroFlightDirectionCls::push, false);
}

void HeroControllerCls::didPop(Route<dynamic> route, Route<dynamic> previousRoute) {
    assert(navigator() != nullptr);
    assert(route != nullptr);
    if (!navigator()!->userGestureInProgress()) {
        _maybeStartHeroTransition(route, previousRoute, HeroFlightDirectionCls::pop, false);
    }
}

void HeroControllerCls::didReplace(Route<dynamic> newRoute, Route<dynamic> oldRoute) {
    assert(navigator() != nullptr);
    if (newRoute?->isCurrent() | false) {
        _maybeStartHeroTransition(oldRoute, newRoute, HeroFlightDirectionCls::push, false);
    }
}

void HeroControllerCls::didStartUserGesture(Route<dynamic> route, Route<dynamic> previousRoute) {
    assert(navigator() != nullptr);
    assert(route != nullptr);
    _maybeStartHeroTransition(route, previousRoute, HeroFlightDirectionCls::pop, true);
}

void HeroControllerCls::didStopUserGesture() {
    if (navigator()!->userGestureInProgress()) {
        return;
    }
    InlineMethod;
    List<_HeroFlight> invalidFlights = _flights->values()->where(isInvalidFlight)->toList(false);
    for (_HeroFlight flight : invalidFlights) {
        flight->_handleAnimationUpdate(AnimationStatusCls::dismissed);
    }
}

void HeroControllerCls::_maybeStartHeroTransition(Route<dynamic> fromRoute, Route<dynamic> toRoute, HeroFlightDirection flightType, bool isUserGestureTransition) {
    if (toRoute != fromRoute && is<PageRoute<dynamic>>(toRoute) && is<PageRoute<dynamic>>(fromRoute)) {
        PageRoute<dynamic> from = fromRoute;
        PageRoute<dynamic> to = toRoute;
        ;
        if (isUserGestureTransition && flightType == HeroFlightDirectionCls::pop && to->maintainState()) {
            _startHeroTransition(from, to, flightType, isUserGestureTransition);
        } else {
            to->offstage() = to->animation()!->value() == 0.0;
            WidgetsBindingCls::instance->addPostFrameCallback([=] (Duration value) {
                _startHeroTransition(from, to, flightType, isUserGestureTransition);
            });
        }
    }
}

void HeroControllerCls::_startHeroTransition(PageRoute<dynamic> from, PageRoute<dynamic> to, HeroFlightDirection flightType, bool isUserGestureTransition) {
    to->offstage() = false;
    NavigatorState navigator = this->navigator();
    OverlayState overlay = navigator?->overlay();
    if (navigator == nullptr || overlay == nullptr) {
        return;
    }
    RenderObject navigatorRenderObject = navigator->context()->findRenderObject();
    if (!is<RenderBox>(navigatorRenderObject)) {
        assert(false, __s("Navigator $navigator has an invalid RenderObject type ${navigatorRenderObject.runtimeType}."));
        return;
    }
    assert(navigatorRenderObject->hasSize);
    BuildContext fromSubtreeContext = from->subtreeContext();
    Map<Object, _HeroState> fromHeroes = fromSubtreeContext != nullptr? HeroCls->_allHeroesFor(fromSubtreeContext, isUserGestureTransition, navigator) : makeMap(makeList(), makeList();
    BuildContext toSubtreeContext = to->subtreeContext();
    Map<Object, _HeroState> toHeroes = toSubtreeContext != nullptr? HeroCls->_allHeroesFor(toSubtreeContext, isUserGestureTransition, navigator) : makeMap(makeList(), makeList();
    for (MapEntry<Object, _HeroState> fromHeroEntry : fromHeroes->entries()) {
        Object tag = fromHeroEntry->key;
        _HeroState fromHero = fromHeroEntry->value;
        _HeroState toHero = toHeroes[tag];
        _HeroFlight existingFlight = _flights[tag];
        _HeroFlightManifest manifest = toHero == nullptr? nullptr : make<_HeroFlightManifestCls>(flightType, overlay, navigatorRenderObject->size, from, to, fromHero, toHero, createRectTween, toHero->widget()->flightShuttleBuilder | fromHero->widget()->flightShuttleBuilder | _defaultHeroFlightShuttleBuilder, isUserGestureTransition, existingFlight != nullptr);
        if (manifest != nullptr && manifest->isValid) {
            toHeroes->remove(tag);
            if (existingFlight != nullptr) {
                existingFlight->divert(manifest);
            } else {
                            auto _c1 = make<_HeroFlightCls>(_handleFlightEnded);            _c1.start(manifest);_flights[tag] = _c1;
            }
        } else {
            existingFlight?->abort();
        }
    }
    for (_HeroState toHero : toHeroes->values()) {
        toHero->endFlight();
    }
}

void HeroControllerCls::_handleFlightEnded(_HeroFlight flight) {
    _flights->remove(flight->manifest->tag());
}

Widget HeroControllerCls::_defaultHeroFlightShuttleBuilder(BuildContext flightContext, Animation<double> animation, HeroFlightDirection flightDirection, BuildContext fromHeroContext, BuildContext toHeroContext) {
    Hero toHero = as<Hero>(toHeroContext->widget());
    MediaQueryData toMediaQueryData = MediaQueryCls->maybeOf(toHeroContext);
    MediaQueryData fromMediaQueryData = MediaQueryCls->maybeOf(fromHeroContext);
    if (toMediaQueryData == nullptr || fromMediaQueryData == nullptr) {
        return toHero->child;
    }
    EdgeInsets fromHeroPadding = fromMediaQueryData->padding;
    EdgeInsets toHeroPadding = toMediaQueryData->padding;
    return make<AnimatedBuilderCls>(animation, [=] (BuildContext context,Widget child) {
        return make<MediaQueryCls>(toMediaQueryData->copyWith((flightDirection == HeroFlightDirectionCls::push)? make<EdgeInsetsTweenCls>(fromHeroPadding, toHeroPadding)->evaluate(animation) : make<EdgeInsetsTweenCls>(toHeroPadding, fromHeroPadding)->evaluate(animation)), toHero->child);
    });
}

HeroModeCls::HeroModeCls(Widget child, bool enabled, Unknown key) {
    {
        assert(child != nullptr);
        assert(enabled != nullptr);
    }
}

Widget HeroModeCls::build(BuildContext context) {
    return child;
}

void HeroModeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("mode"), enabled, __s("enabled"), __s("disabled"), true));
}
