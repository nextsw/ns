#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_CROSS_FADE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ANIMATED_CROSS_FADE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/rendering.hpp>
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

class AnimatedCrossFadeCls : public StatefulWidgetCls {
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


     AnimatedCrossFadeCls(AlignmentGeometry alignment, CrossFadeState crossFadeState, Duration duration, bool excludeBottomFocus, Widget firstChild, Curve firstCurve, Unknown key, AnimatedCrossFadeBuilder layoutBuilder, Duration reverseDuration, Widget secondChild, Curve secondCurve, Curve sizeCurve);

    static Widget defaultLayoutBuilder(Widget topChild, Key topChildKey, Widget bottomChild, Key bottomChildKey);

    virtual State<AnimatedCrossFade> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using AnimatedCrossFade = std::shared_ptr<AnimatedCrossFadeCls>;

class _AnimatedCrossFadeStateCls : public StateCls<AnimatedCrossFade> {
public:

    virtual void initState();

    virtual void dispose();

    virtual void didUpdateWidget(AnimatedCrossFade oldWidget);

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    AnimationController _controller;

    Animation<double> _firstAnimation;

    Animation<double> _secondAnimation;


    virtual Animation<double> _initAnimation(Curve curve, bool inverted);

    virtual bool _isTransitioning();

};
using _AnimatedCrossFadeState = std::shared_ptr<_AnimatedCrossFadeStateCls>;


#endif