#ifndef SCROLL_NOTIFICATION_OBSERVER_H
#define SCROLL_NOTIFICATION_OBSERVER_H
#include <memory>

#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"
#include "scroll_notification.hpp"
#include "scroll_position.hpp"



class _ScrollNotificationObserverScope : InheritedWidget {
public:

    bool updateShouldNotify(_ScrollNotificationObserverScope old);

private:
    ScrollNotificationObserverState _scrollNotificationObserverState;


     _ScrollNotificationObserverScope(Unknown, ScrollNotificationObserverState scrollNotificationObserverState);

};

class _ListenerEntry : LinkedListEntry<_ListenerEntry> {
public:
    ScrollNotificationCallback listener;


private:

     _ListenerEntry(ScrollNotificationCallback listener);

};

class ScrollNotificationObserver : StatefulWidget {
public:
    Widget child;


     ScrollNotificationObserver(Widget child, Unknown);

    static ScrollNotificationObserverState of(BuildContext context);

    ScrollNotificationObserverState createState();

private:

};

class ScrollNotificationObserverState : State<ScrollNotificationObserver> {
public:

    void addListener(ScrollNotificationCallback listener);

    void removeListener(ScrollNotificationCallback listener);

    Widget build(BuildContext context);

    void dispose();

private:
    LinkedList<_ListenerEntry> _listeners;


    bool _debugAssertNotDisposed();

    void _notifyListeners(ScrollNotification notification);

};

class _ConvertedScrollMetricsNotification : ScrollUpdateNotification {
public:

private:

     _ConvertedScrollMetricsNotification(Unknown, Unknown, Unknown);

};

#endif