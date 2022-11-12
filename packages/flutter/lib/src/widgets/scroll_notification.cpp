#include "scroll_notification.hpp"
int ViewportNotificationMixinCls::depth() {
    return _depth;
}

void ViewportNotificationMixinCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("depth: %s$%s"));
}

bool ViewportElementMixinCls::onNotification(Notification notification) {
    if (is<ViewportNotificationMixin>(notification)) {
        as<ViewportNotificationMixinCls>(notification)->_depth += 1;
    }
    return false;
}

void ScrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("%s)"));
}

void ScrollStartNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    if (dragDetails != nullptr) {
        description->add(__s("%s)"));
    }
}

ScrollUpdateNotificationCls::ScrollUpdateNotificationCls(BuildContext context, int depth, DragUpdateDetails dragDetails, ScrollMetrics metrics, double scrollDelta) {
    {
        if (depth != nullptr) {
            _depth = depth;
        }
    }
}

void ScrollUpdateNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("scrollDelta: %s)"));
    if (dragDetails != nullptr) {
        description->add(__s("%s)"));
    }
}

OverscrollNotificationCls::OverscrollNotificationCls(BuildContext context, DragUpdateDetails dragDetails, ScrollMetrics metrics, double overscroll, double velocity) {
    {
        assert(overscroll != nullptr);
        assert(overscroll->isFinite());
        assert(overscroll != 0.0);
        assert(velocity != nullptr);
    }
}

void OverscrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("overscroll: %s)"));
    description->add(__s("velocity: %s)"));
    if (dragDetails != nullptr) {
        description->add(__s("%s)"));
    }
}

void ScrollEndNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    if (dragDetails != nullptr) {
        description->add(__s("%s)"));
    }
}

void UserScrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__s("direction: %s)"));
}

bool defaultScrollNotificationPredicate(ScrollNotification notification) {
    return notification->depth == 0;
}
