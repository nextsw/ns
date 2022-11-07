#include "scroll_notification.hpp"
int ViewportNotificationMixin::depth() {
    return _depth;
}

void ViewportNotificationMixin::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("depth: $depth (${ depth == 0 ? "local" : "remote"})");
}

bool ViewportElementMixin::onNotification(Notification notification) {
    if (notification is ViewportNotificationMixin) {
        notification._depth = 1;
    }
    return false;
}

void ScrollNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("$metrics");
}

void ScrollStartNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    if (dragDetails != nullptr) {
        description.add("$dragDetails");
    }
}

ScrollUpdateNotification::ScrollUpdateNotification(BuildContext context, int depth, DragUpdateDetails dragDetails, Unknown, double scrollDelta) {
    {
        if (depth != nullptr) {
            _depth = depth;
        }
    }
}

void ScrollUpdateNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("scrollDelta: $scrollDelta");
    if (dragDetails != nullptr) {
        description.add("$dragDetails");
    }
}

OverscrollNotification::OverscrollNotification(BuildContext context, DragUpdateDetails dragDetails, Unknown, double overscroll, double velocity) {
    {
        assert(overscroll != nullptr);
        assert(overscroll.isFinite);
        assert(overscroll != 0.0);
        assert(velocity != nullptr);
    }
}

void OverscrollNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("overscroll: ${overscroll.toStringAsFixed(1)}");
    description.add("velocity: ${velocity.toStringAsFixed(1)}");
    if (dragDetails != nullptr) {
        description.add("$dragDetails");
    }
}

void ScrollEndNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    if (dragDetails != nullptr) {
        description.add("$dragDetails");
    }
}

void UserScrollNotification::debugFillDescription(List<String> description) {
    super.debugFillDescription(description);
    description.add("direction: $direction");
}

bool defaultScrollNotificationPredicate(ScrollNotification notification) {
    return notification.depth == 0;
}
