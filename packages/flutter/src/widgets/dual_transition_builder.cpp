#include "dual_transition_builder.hpp"
DualTransitionBuilder::DualTransitionBuilder(Animation<double> animation, Widget child, AnimatedTransitionBuilder forwardBuilder, Unknown, AnimatedTransitionBuilder reverseBuilder) {
    {
        assert(animation != nullptr);
        assert(forwardBuilder != nullptr);
        assert(reverseBuilder != nullptr);
    }
}

State<DualTransitionBuilder> DualTransitionBuilder::createState() {
    return _DualTransitionBuilderState();
}

void _DualTransitionBuilderState::initState() {
    super.initState();
    _effectiveAnimationStatus = widget.animation.status;
    widget.animation.addStatusListener(_animationListener);
    _updateAnimations();
}

void _DualTransitionBuilderState::didUpdateWidget(DualTransitionBuilder oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.animation != widget.animation) {
        oldWidget.animation.removeStatusListener(_animationListener);
        widget.animation.addStatusListener(_animationListener);
        _animationListener(widget.animation.status);
    }
}

void _DualTransitionBuilderState::dispose() {
    widget.animation.removeStatusListener(_animationListener);
    super.dispose();
}

Widget _DualTransitionBuilderState::build(BuildContext context) {
    return widget.forwardBuilder(context, _forwardAnimation, widget.reverseBuilder(context, _reverseAnimation, widget.child));
}

void _DualTransitionBuilderState::_animationListener(AnimationStatus animationStatus) {
    AnimationStatus oldEffective = _effectiveAnimationStatus;
    _effectiveAnimationStatus = _calculateEffectiveAnimationStatus(_effectiveAnimationStatus, animationStatus);
    if (oldEffective != _effectiveAnimationStatus) {
        _updateAnimations();
    }
}

AnimationStatus _DualTransitionBuilderState::_calculateEffectiveAnimationStatus(AnimationStatus current, AnimationStatus lastEffective) {
    assert(current != nullptr);
    assert(lastEffective != nullptr);
    ;
}

void _DualTransitionBuilderState::_updateAnimations() {
    ;
}
