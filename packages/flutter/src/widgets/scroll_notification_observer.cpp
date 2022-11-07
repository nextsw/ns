#include "scroll_notification_observer.hpp"
bool _ScrollNotificationObserverScope::updateShouldNotify(_ScrollNotificationObserverScope old) {
    return _scrollNotificationObserverState != old._scrollNotificationObserverState;
}

_ScrollNotificationObserverScope::_ScrollNotificationObserverScope(Unknown, ScrollNotificationObserverState scrollNotificationObserverState) {
    {
        _scrollNotificationObserverState = scrollNotificationObserverState;
    }
}

ScrollNotificationObserver::ScrollNotificationObserver(Widget child, Unknown) {
    {
        assert(child != nullptr);
    }
}

ScrollNotificationObserverState ScrollNotificationObserver::of(BuildContext context) {
    return context.<_ScrollNotificationObserverScope>dependOnInheritedWidgetOfExactType()?._scrollNotificationObserverState;
}

ScrollNotificationObserverState ScrollNotificationObserver::createState() {
    return ScrollNotificationObserverState();
}

void ScrollNotificationObserverState::addListener(ScrollNotificationCallback listener) {
    assert(_debugAssertNotDisposed());
    _listeners!.add(_ListenerEntry(listener));
}

void ScrollNotificationObserverState::removeListener(ScrollNotificationCallback listener) {
    assert(_debugAssertNotDisposed());
    for (_ListenerEntry entry : _listeners!) {
        if (entry.listener == listener) {
            entry.unlink();
            return;
        }
    }
}

Widget ScrollNotificationObserverState::build(BuildContext context) {
    return <ScrollMetricsNotification>NotificationListener(, <ScrollNotification>NotificationListener(, _ScrollNotificationObserverScope(this, widget.child)));
}

void ScrollNotificationObserverState::dispose() {
    assert(_debugAssertNotDisposed());
    _listeners = nullptr;
    super.dispose();
}

bool ScrollNotificationObserverState::_debugAssertNotDisposed() {
    assert(());
    return true;
}

void ScrollNotificationObserverState::_notifyListeners(ScrollNotification notification) {
    assert(_debugAssertNotDisposed());
    if (_listeners!.isEmpty) {
        return;
    }
    List<_ListenerEntry> localListeners = <_ListenerEntry>of(_listeners!);
    for (_ListenerEntry entry : localListeners) {
        ;
    }
}
