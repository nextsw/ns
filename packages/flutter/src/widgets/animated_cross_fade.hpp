#ifndef ANIMATED_CROSS_FADE_H
#define ANIMATED_CROSS_FADE_H
#include <memory>

#include <flutter/rendering.hpp>
#include "animated_size.hpp"
#include "basic.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "ticker_provider.hpp"
#include "transitions.hpp"



enum CrossFadeState{
    showFirst,
    showSecond,
} // end CrossFadeState

class AnimatedCrossFade : StatefulWidget {
public:
    Widget firstChild;

    Widget secondChild;

    CrossFadeState crossFadeState;

    Duration duration;

    Duration reverseDuration;

    Curve firstCurve;

    Curve secondCurve;

    Curve sizeCurve;

    AlignmentGeometry alignment;

    AnimatedCrossFadeBuilder layoutBuilder;

    bool excludeBottomFocus;


     AnimatedCrossFade(AlignmentGeometry alignment, CrossFadeState crossFadeState, Duration duration, bool excludeBottomFocus, Widget firstChild, Curve firstCurve, Unknown, AnimatedCrossFadeBuilder layoutBuilder, Duration reverseDuration, Widget secondChild, Curve secondCurve, Curve sizeCurve);

    static Widget defaultLayoutBuilder(Widget bottomChild, Key bottomChildKey, Widget topChild, Key topChildKey);

    State<AnimatedCrossFade> createState();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

class _AnimatedCrossFadeState : State<AnimatedCrossFade> {
public:

    void initState();

    void dispose();

    void didUpdateWidget(AnimatedCrossFade oldWidget);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AnimationController _controller;

    Animation<double> _firstAnimation;

    Animation<double> _secondAnimation;


    Animation<double> _initAnimation(Curve curve, bool inverted);

    bool _isTransitioning();

};

#endif