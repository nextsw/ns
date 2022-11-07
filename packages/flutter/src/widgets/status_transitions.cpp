#include "status_transitions.hpp"
StatusTransitionWidget::StatusTransitionWidget(Animation<double> animation, Unknown) {
    {
        assert(animation != nullptr);
    }
}

State<StatusTransitionWidget> StatusTransitionWidget::createState() {
    return _StatusTransitionState();
}

void _StatusTransitionState::initState() {
    super.initState();
    widget.animation.addStatusListener(_animationStatusChanged);
}

void _StatusTransitionState::didUpdateWidget(StatusTransitionWidget oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.animation != oldWidget.animation) {
        oldWidget.animation.removeStatusListener(_animationStatusChanged);
        widget.animation.addStatusListener(_animationStatusChanged);
    }
}

void _StatusTransitionState::dispose() {
    widget.animation.removeStatusListener(_animationStatusChanged);
    super.dispose();
}

Widget _StatusTransitionState::build(BuildContext context) {
    return widget.build(context);
}

void _StatusTransitionState::_animationStatusChanged(AnimationStatus status) {
    setState();
}
