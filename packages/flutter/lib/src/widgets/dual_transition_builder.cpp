#include "dual_transition_builder.hpp"
DualTransitionBuilderCls::DualTransitionBuilderCls(Animation<double> animation, Widget child, AnimatedTransitionBuilder forwardBuilder, Key key, AnimatedTransitionBuilder reverseBuilder) {
    {
        assert(animation != nullptr);
        assert(forwardBuilder != nullptr);
        assert(reverseBuilder != nullptr);
    }
}

State<DualTransitionBuilder> DualTransitionBuilderCls::createState() {
    return make<_DualTransitionBuilderStateCls>();
}

void _DualTransitionBuilderStateCls::initState() {
    super->initState();
    _effectiveAnimationStatus = widget()->animation->status;
    widget()->animation->addStatusListener(_animationListener);
    _updateAnimations();
}

void _DualTransitionBuilderStateCls::didUpdateWidget(DualTransitionBuilder oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (oldWidget->animation != widget()->animation) {
        oldWidget->animation->removeStatusListener(_animationListener);
        widget()->animation->addStatusListener(_animationListener);
        _animationListener(widget()->animation->status);
    }
}

void _DualTransitionBuilderStateCls::dispose() {
    widget()->animation->removeStatusListener(_animationListener);
    super->dispose();
}

Widget _DualTransitionBuilderStateCls::build(BuildContext context) {
    return widget()->forwardBuilder(context, _forwardAnimation, widget()->reverseBuilder(context, _reverseAnimation, widget()->child));
}

void _DualTransitionBuilderStateCls::_animationListener(AnimationStatus animationStatus) {
    AnimationStatus oldEffective = _effectiveAnimationStatus;
    _effectiveAnimationStatus = _calculateEffectiveAnimationStatus(_effectiveAnimationStatus, animationStatus);
    if (oldEffective != _effectiveAnimationStatus) {
        _updateAnimations();
    }
}

AnimationStatus _DualTransitionBuilderStateCls::_calculateEffectiveAnimationStatus(AnimationStatus current, AnimationStatus lastEffective) {
    assert(current != nullptr);
    assert(lastEffective != nullptr);
    ;
}

void _DualTransitionBuilderStateCls::_updateAnimations() {
    ;
}
