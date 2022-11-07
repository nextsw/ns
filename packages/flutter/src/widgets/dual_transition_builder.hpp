#ifndef DUAL_TRANSITION_BUILDER_H
#define DUAL_TRANSITION_BUILDER_H
#include <memory>

#include "basic.hpp"
#include "framework.hpp"



class DualTransitionBuilder : StatefulWidget {
public:
    Animation<double> animation;

    AnimatedTransitionBuilder forwardBuilder;

    AnimatedTransitionBuilder reverseBuilder;

    Widget child;


     DualTransitionBuilder(Animation<double> animation, Widget child, AnimatedTransitionBuilder forwardBuilder, Unknown, AnimatedTransitionBuilder reverseBuilder);

    State<DualTransitionBuilder> createState();

private:

};

class _DualTransitionBuilderState : State<DualTransitionBuilder> {
public:

    void initState();

    void didUpdateWidget(DualTransitionBuilder oldWidget);

    void dispose();

    Widget build(BuildContext context);

private:
    AnimationStatus _effectiveAnimationStatus;

    ProxyAnimation _forwardAnimation;

    ProxyAnimation _reverseAnimation;


    void _animationListener(AnimationStatus animationStatus);

    AnimationStatus _calculateEffectiveAnimationStatus(AnimationStatus current, AnimationStatus lastEffective);

    void _updateAnimations();

};

#endif