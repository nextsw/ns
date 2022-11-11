#include "animated_cross_fade.hpp"
AnimatedCrossFadeCls::AnimatedCrossFadeCls(AlignmentGeometry alignment, CrossFadeState crossFadeState, Duration duration, bool excludeBottomFocus, Widget firstChild, Curve firstCurve, Unknown key, AnimatedCrossFadeBuilder layoutBuilder, Duration reverseDuration, Widget secondChild, Curve secondCurve, Curve sizeCurve) {
    {
        assert(firstChild != nullptr);
        assert(secondChild != nullptr);
        assert(firstCurve != nullptr);
        assert(secondCurve != nullptr);
        assert(sizeCurve != nullptr);
        assert(alignment != nullptr);
        assert(crossFadeState != nullptr);
        assert(duration != nullptr);
        assert(layoutBuilder != nullptr);
        assert(excludeBottomFocus != nullptr);
    }
}

Widget AnimatedCrossFadeCls::defaultLayoutBuilder(Widget topChild, Key topChildKey, Widget bottomChild, Key bottomChildKey) {
    return make<StackCls>(ClipCls::none, makeList(ArrayItem, ArrayItem));
}

State<AnimatedCrossFade> AnimatedCrossFadeCls::createState() {
    return make<_AnimatedCrossFadeStateCls>();
}

void AnimatedCrossFadeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<CrossFadeState>make<EnumPropertyCls>(__s("crossFadeState"), crossFadeState));
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, AlignmentCls::topCenter));
    properties->add(make<IntPropertyCls>(__s("duration"), duration->inMilliseconds(), __s("ms")));
    properties->add(make<IntPropertyCls>(__s("reverseDuration"), reverseDuration?->inMilliseconds(), __s("ms"), nullptr));
}

void _AnimatedCrossFadeStateCls::initState() {
    super->initState();
    _controller = make<AnimationControllerCls>(widget->duration, widget->reverseDuration, this);
    if (widget->crossFadeState == CrossFadeStateCls::showSecond) {
        _controller->value() = 1.0;
    }
    _firstAnimation = _initAnimation(widget->firstCurve, true);
    _secondAnimation = _initAnimation(widget->secondCurve, false);
    _controller->addStatusListener([=] (AnimationStatus status) {
        setState([=] () {
        });
    });
}

void _AnimatedCrossFadeStateCls::dispose() {
    _controller->dispose();
    super->dispose();
}

void _AnimatedCrossFadeStateCls::didUpdateWidget(AnimatedCrossFade oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget->duration != oldWidget->duration) {
        _controller->duration = widget->duration;
    }
    if (widget->reverseDuration != oldWidget->reverseDuration) {
        _controller->reverseDuration = widget->reverseDuration;
    }
    if (widget->firstCurve != oldWidget->firstCurve) {
        _firstAnimation = _initAnimation(widget->firstCurve, true);
    }
    if (widget->secondCurve != oldWidget->secondCurve) {
        _secondAnimation = _initAnimation(widget->secondCurve, false);
    }
    if (widget->crossFadeState != oldWidget->crossFadeState) {
        ;
    }
}

Widget _AnimatedCrossFadeStateCls::build(BuildContext context) {
    Key kFirstChildKey = <CrossFadeState>make<ValueKeyCls>(CrossFadeStateCls::showFirst);
    Key kSecondChildKey = <CrossFadeState>make<ValueKeyCls>(CrossFadeStateCls::showSecond);
    bool transitioningForwards = _controller->status() == AnimationStatusCls::completed || _controller->status() == AnimationStatusCls::forward;
    Key topKey;
    Widget topChild;
    Animation<double> topAnimation;
    Key bottomKey;
    Widget bottomChild;
    Animation<double> bottomAnimation;
    if (transitioningForwards) {
        topKey = kSecondChildKey;
        topChild = widget->secondChild;
        topAnimation = _secondAnimation;
        bottomKey = kFirstChildKey;
        bottomChild = widget->firstChild;
        bottomAnimation = _firstAnimation;
    } else {
        topKey = kFirstChildKey;
        topChild = widget->firstChild;
        topAnimation = _firstAnimation;
        bottomKey = kSecondChildKey;
        bottomChild = widget->secondChild;
        bottomAnimation = _secondAnimation;
    }
    bottomChild = make<TickerModeCls>(bottomKey, _isTransitioning(), make<IgnorePointerCls>(make<ExcludeSemanticsCls>(make<ExcludeFocusCls>(widget->excludeBottomFocus, make<FadeTransitionCls>(bottomAnimation, bottomChild)))));
    topChild = make<TickerModeCls>(topKey, true, make<IgnorePointerCls>(false, make<ExcludeSemanticsCls>(false, make<ExcludeFocusCls>(false, make<FadeTransitionCls>(topAnimation, topChild)))));
    return make<ClipRectCls>(make<AnimatedSizeCls>(widget->alignment, widget->duration, widget->reverseDuration, widget->sizeCurve, widget->layoutBuilder(topChild, topKey, bottomChild, bottomKey)));
}

void _AnimatedCrossFadeStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(<CrossFadeState>make<EnumPropertyCls>(__s("crossFadeState"), widget->crossFadeState));
    description->add(<AnimationController>make<DiagnosticsPropertyCls>(__s("controller"), _controller, false));
    description->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), widget->alignment, AlignmentCls::topCenter));
}

Animation<double> _AnimatedCrossFadeStateCls::_initAnimation(Curve curve, bool inverted) {
    Animation<double> result = _controller->drive(make<CurveTweenCls>(curve));
    if (inverted) {
        result = result->drive(<double>make<TweenCls>(1.0, 0.0));
    }
    return result;
}

bool _AnimatedCrossFadeStateCls::_isTransitioning() {
    return _controller->status() == AnimationStatusCls::forward || _controller->status() == AnimationStatusCls::reverse;
}
