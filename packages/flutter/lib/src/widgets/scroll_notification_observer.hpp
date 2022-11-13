#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_NOTIFICATION_OBSERVER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SCROLL_NOTIFICATION_OBSERVER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"
#include "scroll_notification.hpp"
#include "scroll_position.hpp"


class _ScrollNotificationObserverScopeCls : public InheritedWidgetCls {
public:

    virtual bool updateShouldNotify(_ScrollNotificationObserverScope old);

private:
    ScrollNotificationObserverState _scrollNotificationObserverState;


     _ScrollNotificationObserverScopeCls(Widget child, ScrollNotificationObserverState scrollNotificationObserverState);

};
using _ScrollNotificationObserverScope = std::shared_ptr<_ScrollNotificationObserverScopeCls>;

class _ListenerEntryCls : public LinkedListEntryCls<_ListenerEntry> {
public:
    ScrollNotificationCallback listener;


private:

     _ListenerEntryCls(ScrollNotificationCallback listener);
};
using _ListenerEntry = std::shared_ptr<_ListenerEntryCls>;

class ScrollNotificationObserverCls : public StatefulWidgetCls {
public:
    Widget child;


     ScrollNotificationObserverCls(Widget child, Key key);

    static ScrollNotificationObserverState of(BuildContext context);

    virtual ScrollNotificationObserverState createState();

private:

};
using ScrollNotificationObserver = std::shared_ptr<ScrollNotificationObserverCls>;

class ScrollNotificationObserverStateCls : public StateCls<ScrollNotificationObserver> {
public:

    virtual void addListener(ScrollNotificationCallback listener);

    virtual void removeListener(ScrollNotificationCallback listener);

    virtual Widget build(BuildContext context);

    virtual void dispose();

private:
    LinkedList<_ListenerEntry> _listeners;


    virtual bool _debugAssertNotDisposed();

    virtual void _notifyListeners(ScrollNotification notification);

};
using ScrollNotificationObserverState = std::shared_ptr<ScrollNotificationObserverStateCls>;

class _ConvertedScrollMetricsNotificationCls : public ScrollUpdateNotificationCls {
public:

private:

     _ConvertedScrollMetricsNotificationCls(BuildContext context, int depth, ScrollMetrics metrics);
};
using _ConvertedScrollMetricsNotification = std::shared_ptr<_ConvertedScrollMetricsNotificationCls>;


#endif