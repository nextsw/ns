#include "scroll_notification.hpp"
int ViewportNotificationMixinCls::depth() {
    return _depth;
}

void ViewportNotificationMixinCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("depth: $depth (${ depth == 0 ? "local" : "remote"})");
}

bool ViewportElementMixinCls::onNotification(Notification notification) {
    if (notification is ViewportNotificationMixin) {
        notification->_depth = 1;
    }
    return false;
}

void ScrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("$metrics");
}

void ScrollStartNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    if (dragDetails != nullptr) {
        description->add("$dragDetails");
    }
}

ScrollUpdateNotificationCls::ScrollUpdateNotificationCls(BuildContext context, int depth, DragUpdateDetails dragDetails, Unknown metrics, double scrollDelta) {
    {
        if (depth != nullptr) {
            _depth = depth;
        }
    }
}

void ScrollUpdateNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("scrollDelta: $scrollDelta");
    if (dragDetails != nullptr) {
        description->add("$dragDetails");
    }
}

OverscrollNotificationCls::OverscrollNotificationCls(BuildContext context, DragUpdateDetails dragDetails, Unknown metrics, double overscroll, double velocity) {
    {
        assert(overscroll != nullptr);
        assert(overscroll->isFinite);
        assert(overscroll != 0.0);
        assert(velocity != nullptr);
    }
}

void OverscrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("overscroll: ${overscroll.toStringAsFixed(1)}");
    description->add("velocity: ${velocity.toStringAsFixed(1)}");
    if (dragDetails != nullptr) {
        description->add("$dragDetails");
    }
}

void ScrollEndNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    if (dragDetails != nullptr) {
        description->add("$dragDetails");
    }
}

void UserScrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add("direction: $direction");
}

bool defaultScrollNotificationPredicate(ScrollNotification notification) {
    return notification->depth == 0;
}
