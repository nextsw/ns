#include "status_transitions.hpp"
StatusTransitionWidgetCls::StatusTransitionWidgetCls(Animation<double> animation, Key key) {
    {
        assert(animation != nullptr);
    }
}

State<StatusTransitionWidget> StatusTransitionWidgetCls::createState() {
    return make<_StatusTransitionStateCls>();
}

void _StatusTransitionStateCls::initState() {
    super->initState();
    widget()->animation->addStatusListener(_animationStatusChanged);
}

void _StatusTransitionStateCls::didUpdateWidget(StatusTransitionWidget oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->animation != oldWidget->animation) {
        oldWidget->animation->removeStatusListener(_animationStatusChanged);
        widget()->animation->addStatusListener(_animationStatusChanged);
    }
}

void _StatusTransitionStateCls::dispose() {
    widget()->animation->removeStatusListener(_animationStatusChanged);
    super->dispose();
}

Widget _StatusTransitionStateCls::build(BuildContext context) {
    return widget()->build(context);
}

void _StatusTransitionStateCls::_animationStatusChanged(AnimationStatus status) {
    setState([=] () {
    });
}
