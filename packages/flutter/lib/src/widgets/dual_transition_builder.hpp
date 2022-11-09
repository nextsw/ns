#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DUAL_TRANSITION_BUILDER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DUAL_TRANSITION_BUILDER
#include <base.hpp>

#include <dart/core/core.hpp>
#include "basic.hpp"
#include "framework.hpp"


class DualTransitionBuilderCls : public StatefulWidgetCls {
public:
    Animation<double> animation;

    AnimatedTransitionBuilder forwardBuilder;

    AnimatedTransitionBuilder reverseBuilder;

    Widget child;


     DualTransitionBuilderCls(Animation<double> animation, Widget child, AnimatedTransitionBuilder forwardBuilder, Unknown key, AnimatedTransitionBuilder reverseBuilder);

    virtual State<DualTransitionBuilder> createState();

private:

};
using DualTransitionBuilder = std::shared_ptr<DualTransitionBuilderCls>;

class _DualTransitionBuilderStateCls : public StateCls<DualTransitionBuilder> {
public:

    virtual void initState();

    virtual void didUpdateWidget(DualTransitionBuilder oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    AnimationStatus _effectiveAnimationStatus;

    ProxyAnimation _forwardAnimation;

    ProxyAnimation _reverseAnimation;


    virtual void _animationListener(AnimationStatus animationStatus);

    virtual AnimationStatus _calculateEffectiveAnimationStatus(AnimationStatus current, AnimationStatus lastEffective);

    virtual void _updateAnimations();

};
using _DualTransitionBuilderState = std::shared_ptr<_DualTransitionBuilderStateCls>;


#endif