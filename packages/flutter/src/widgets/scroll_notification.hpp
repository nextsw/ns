#ifndef SCROLL_NOTIFICATION_H
#define SCROLL_NOTIFICATION_H
#include <memory>

#include <flutter/gestures.hpp>
#include <flutter/rendering.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"
#include "scroll_metrics.hpp"



class ViewportNotificationMixin {
public:

    int depth();

    void debugFillDescription(List<String> description);

private:
    int _depth;


};

class ViewportElementMixin {
public:

    bool onNotification(Notification notification);

private:

};

class ScrollNotification : LayoutChangedNotification {
public:
    ScrollMetrics metrics;

    BuildContext context;


     ScrollNotification(BuildContext context, ScrollMetrics metrics);

    void debugFillDescription(List<String> description);

private:

};

class ScrollStartNotification : ScrollNotification {
public:
    DragStartDetails dragDetails;


     ScrollStartNotification(Unknown, DragStartDetails dragDetails, Unknown);

    void debugFillDescription(List<String> description);

private:

};

class ScrollUpdateNotification : ScrollNotification {
public:
    DragUpdateDetails dragDetails;

    double scrollDelta;


     ScrollUpdateNotification(BuildContext context, int depth, DragUpdateDetails dragDetails, Unknown, double scrollDelta);

    void debugFillDescription(List<String> description);

private:

};

class OverscrollNotification : ScrollNotification {
public:
    DragUpdateDetails dragDetails;

    double overscroll;

    double velocity;


     OverscrollNotification(BuildContext context, DragUpdateDetails dragDetails, Unknown, double overscroll, double velocity);

    void debugFillDescription(List<String> description);

private:

};

class ScrollEndNotification : ScrollNotification {
public:
    DragEndDetails dragDetails;


     ScrollEndNotification(BuildContext context, DragEndDetails dragDetails, Unknown);

    void debugFillDescription(List<String> description);

private:

};

class UserScrollNotification : ScrollNotification {
public:
    ScrollDirection direction;


     UserScrollNotification(BuildContext context, ScrollDirection direction, Unknown);

    void debugFillDescription(List<String> description);

private:

};
bool defaultScrollNotificationPredicate(ScrollNotification notification);


#endif