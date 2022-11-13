#include "scroll_notification.hpp"
int ViewportNotificationMixinCls::depth() {
    return _depth;
}

void ViewportNotificationMixinCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__sf("depth: %s (%s", depth(), depth() == 0? __s("local") : __s("remote)")));
}

bool ViewportElementMixinCls::onNotification(Notification notification) {
    if (is<ViewportNotificationMixin>(notification)) {
        as<ViewportNotificationMixinCls>(notification)->_depth += 1;
    }
    return false;
}

void ScrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__sf("%s", metrics));
}

void ScrollStartNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    if (dragDetails != nullptr) {
        description->add(__sf("%s", dragDetails));
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
    description->add(__sf("scrollDelta: %s", scrollDelta));
    if (dragDetails != nullptr) {
        description->add(__sf("%s", dragDetails));
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
    description->add(__sf("overscroll: %s", overscroll->toStringAsFixed(1)));
    description->add(__sf("velocity: %s", velocity->toStringAsFixed(1)));
    if (dragDetails != nullptr) {
        description->add(__sf("%s", dragDetails));
    }
}

void ScrollEndNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    if (dragDetails != nullptr) {
        description->add(__sf("%s", dragDetails));
    }
}

void UserScrollNotificationCls::debugFillDescription(List<String> description) {
    super->debugFillDescription(description);
    description->add(__sf("direction: %s", direction));
}

bool defaultScrollNotificationPredicate(ScrollNotification notification) {
    return notification->depth == 0;
}
