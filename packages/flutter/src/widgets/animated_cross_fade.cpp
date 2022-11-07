#include "animated_cross_fade.hpp"
AnimatedCrossFade::AnimatedCrossFade(AlignmentGeometry alignment, CrossFadeState crossFadeState, Duration duration, bool excludeBottomFocus, Widget firstChild, Curve firstCurve, Unknown, AnimatedCrossFadeBuilder layoutBuilder, Duration reverseDuration, Widget secondChild, Curve secondCurve, Curve sizeCurve) {
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

Widget AnimatedCrossFade::defaultLayoutBuilder(Widget bottomChild, Key bottomChildKey, Widget topChild, Key topChildKey) {
    return Stack(Clip.none, );
}

State<AnimatedCrossFade> AnimatedCrossFade::createState() {
    return _AnimatedCrossFadeState();
}

void AnimatedCrossFade::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<CrossFadeState>EnumProperty("crossFadeState", crossFadeState));
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentAlignment.topCenter));
    properties.add(IntProperty("duration", duration.inMilliseconds"ms"));
    properties.add(IntProperty("reverseDuration", reverseDuration?.inMilliseconds"ms", nullptr));
}

void _AnimatedCrossFadeState::initState() {
    super.initState();
    _controller = AnimationController(widget.duration, widget.reverseDuration, this);
    if (widget.crossFadeState == CrossFadeState.showSecond) {
        _controller.value = 1.0;
    }
    _firstAnimation = _initAnimation(widget.firstCurve, true);
    _secondAnimation = _initAnimation(widget.secondCurve, false);
    _controller.addStatusListener();
}

void _AnimatedCrossFadeState::dispose() {
    _controller.dispose();
    super.dispose();
}

void _AnimatedCrossFadeState::didUpdateWidget(AnimatedCrossFade oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.duration != oldWidget.duration) {
        _controller.duration = widget.duration;
    }
    if (widget.reverseDuration != oldWidget.reverseDuration) {
        _controller.reverseDuration = widget.reverseDuration;
    }
    if (widget.firstCurve != oldWidget.firstCurve) {
        _firstAnimation = _initAnimation(widget.firstCurve, true);
    }
    if (widget.secondCurve != oldWidget.secondCurve) {
        _secondAnimation = _initAnimation(widget.secondCurve, false);
    }
    if (widget.crossFadeState != oldWidget.crossFadeState) {
        ;
    }
}

Widget _AnimatedCrossFadeState::build(BuildContext context) {
    Key kFirstChildKey = <CrossFadeState>ValueKey(CrossFadeState.showFirst);
    Key kSecondChildKey = <CrossFadeState>ValueKey(CrossFadeState.showSecond);
    bool transitioningForwards = _controller.status == AnimationStatus.completed || _controller.status == AnimationStatus.forward;
    Key topKey;
    Widget topChild;
    Animation<double> topAnimation;
    Key bottomKey;
    Widget bottomChild;
    Animation<double> bottomAnimation;
    if (transitioningForwards) {
        topKey = kSecondChildKey;
        topChild = widget.secondChild;
        topAnimation = _secondAnimation;
        bottomKey = kFirstChildKey;
        bottomChild = widget.firstChild;
        bottomAnimation = _firstAnimation;
    } else {
        topKey = kFirstChildKey;
        topChild = widget.firstChild;
        topAnimation = _firstAnimation;
        bottomKey = kSecondChildKey;
        bottomChild = widget.secondChild;
        bottomAnimation = _secondAnimation;
    }
    bottomChild = TickerMode(bottomKey, _isTransitioning, IgnorePointer(ExcludeSemantics(ExcludeFocus(widget.excludeBottomFocus, FadeTransition(bottomAnimation, bottomChild)))));
    topChild = TickerMode(topKey, true, IgnorePointer(false, ExcludeSemantics(false, ExcludeFocus(false, FadeTransition(topAnimation, topChild)))));
    return ClipRect(AnimatedSize(widget.alignment, widget.duration, widget.reverseDuration, widget.sizeCurve, widget.layoutBuilder(topChild, topKey, bottomChild, bottomKey)));
}

void _AnimatedCrossFadeState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(<CrossFadeState>EnumProperty("crossFadeState", widget.crossFadeState));
    description.add(<AnimationController>DiagnosticsProperty("controller", _controllerfalse));
    description.add(<AlignmentGeometry>DiagnosticsProperty("alignment", widget.alignmentAlignment.topCenter));
}

Animation<double> _AnimatedCrossFadeState::_initAnimation(Curve curve, bool inverted) {
    Animation<double> result = _controller.drive(CurveTween(curve));
    if (inverted) {
        result = result.drive(<double>Tween(1.0, 0.0));
    }
    return result;
}

bool _AnimatedCrossFadeState::_isTransitioning() {
    return _controller.status == AnimationStatus.forward || _controller.status == AnimationStatus.reverse;
}
