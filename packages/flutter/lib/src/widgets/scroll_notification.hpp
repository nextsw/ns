#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_NOTIFICATION
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_NOTIFICATION
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"
#include "scroll_metrics.hpp"


class ViewportNotificationMixinCls : public ObjectCls {
public:

    virtual int depth();

    virtual void debugFillDescription(List<String> description);

private:
    int _depth;


};
using ViewportNotificationMixin = std::shared_ptr<ViewportNotificationMixinCls>;

class ViewportElementMixinCls : public ObjectCls {
public:

    virtual bool onNotification(Notification notification);

private:

};
using ViewportElementMixin = std::shared_ptr<ViewportElementMixinCls>;

class ScrollNotificationCls : public LayoutChangedNotificationCls {
public:
    ScrollMetrics metrics;

    BuildContext context;


     ScrollNotificationCls(BuildContext context, ScrollMetrics metrics);
    virtual void debugFillDescription(List<String> description);

private:

};
using ScrollNotification = std::shared_ptr<ScrollNotificationCls>;

class ScrollStartNotificationCls : public ScrollNotificationCls {
public:
    DragStartDetails dragDetails;


     ScrollStartNotificationCls(BuildContext context, DragStartDetails dragDetails, ScrollMetrics metrics);
    virtual void debugFillDescription(List<String> description);

private:

};
using ScrollStartNotification = std::shared_ptr<ScrollStartNotificationCls>;

class ScrollUpdateNotificationCls : public ScrollNotificationCls {
public:
    DragUpdateDetails dragDetails;

    double scrollDelta;


     ScrollUpdateNotificationCls(BuildContext context, int depth, DragUpdateDetails dragDetails, ScrollMetrics metrics, double scrollDelta);

    virtual void debugFillDescription(List<String> description);

private:

};
using ScrollUpdateNotification = std::shared_ptr<ScrollUpdateNotificationCls>;

class OverscrollNotificationCls : public ScrollNotificationCls {
public:
    DragUpdateDetails dragDetails;

    double overscroll;

    double velocity;


     OverscrollNotificationCls(BuildContext context, DragUpdateDetails dragDetails, ScrollMetrics metrics, double overscroll, double velocity);

    virtual void debugFillDescription(List<String> description);

private:

};
using OverscrollNotification = std::shared_ptr<OverscrollNotificationCls>;

class ScrollEndNotificationCls : public ScrollNotificationCls {
public:
    DragEndDetails dragDetails;


     ScrollEndNotificationCls(BuildContext context, DragEndDetails dragDetails, ScrollMetrics metrics);
    virtual void debugFillDescription(List<String> description);

private:

};
using ScrollEndNotification = std::shared_ptr<ScrollEndNotificationCls>;

class UserScrollNotificationCls : public ScrollNotificationCls {
public:
    ScrollDirection direction;


     UserScrollNotificationCls(BuildContext context, ScrollDirection direction, ScrollMetrics metrics);
    virtual void debugFillDescription(List<String> description);

private:

};
using UserScrollNotification = std::shared_ptr<UserScrollNotificationCls>;
bool defaultScrollNotificationPredicate(ScrollNotification notification);



#endif