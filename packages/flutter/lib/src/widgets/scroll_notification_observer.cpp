#include "scroll_notification_observer.hpp"
bool _ScrollNotificationObserverScopeCls::updateShouldNotify(_ScrollNotificationObserverScope old) {
    return _scrollNotificationObserverState != old->_scrollNotificationObserverState;
}

_ScrollNotificationObserverScopeCls::_ScrollNotificationObserverScopeCls(Widget child, ScrollNotificationObserverState scrollNotificationObserverState) {
    {
        _scrollNotificationObserverState = scrollNotificationObserverState;
    }
}

ScrollNotificationObserverCls::ScrollNotificationObserverCls(Widget child, Key key) {
    {
        assert(child != nullptr);
    }
}

ScrollNotificationObserverState ScrollNotificationObserverCls::of(BuildContext context) {
    return context-><_ScrollNotificationObserverScope>dependOnInheritedWidgetOfExactType()?->_scrollNotificationObserverState;
}

ScrollNotificationObserverState ScrollNotificationObserverCls::createState() {
    return make<ScrollNotificationObserverStateCls>();
}

void ScrollNotificationObserverStateCls::addListener(ScrollNotificationCallback listener) {
    assert(_debugAssertNotDisposed());
    _listeners!->add(make<_ListenerEntryCls>(listener));
}

void ScrollNotificationObserverStateCls::removeListener(ScrollNotificationCallback listener) {
    assert(_debugAssertNotDisposed());
    for (_ListenerEntry entry : _listeners!) {
        if (entry->listener == listener) {
            entry->unlink();
            return;
        }
    }
}

Widget ScrollNotificationObserverStateCls::build(BuildContext context) {
    return <ScrollMetricsNotification>make<NotificationListenerCls>([=] (ScrollMetricsNotification notification) {
        _notifyListeners(make<_ConvertedScrollMetricsNotificationCls>(notification->metrics, notification->context, notification->depth));
        return false;
    }, <ScrollNotification>make<NotificationListenerCls>([=] (ScrollNotification notification) {
        _notifyListeners(notification);
        return false;
    }, make<_ScrollNotificationObserverScopeCls>(this, widget()->child)));
}

void ScrollNotificationObserverStateCls::dispose() {
    assert(_debugAssertNotDisposed());
    _listeners = nullptr;
    super->dispose();
}

bool ScrollNotificationObserverStateCls::_debugAssertNotDisposed() {
    assert([=] () {
        if (_listeners == nullptr) {
            throw make<FlutterErrorCls>(__s("A $runtimeType was used after being disposed.\nOnce you have called dispose() on a $runtimeType, it can no longer be used."));
        }
        return true;
    }());
    return true;
}

void ScrollNotificationObserverStateCls::_notifyListeners(ScrollNotification notification) {
    assert(_debugAssertNotDisposed());
    if (_listeners!->isEmpty()) {
        return;
    }
    List<_ListenerEntry> localListeners = <_ListenerEntry>of(_listeners!);
    for (_ListenerEntry entry : localListeners) {
        try {
            if (entry->list != nullptr) {
                entry->listener(notification);
            }
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widget library"), make<ErrorDescriptionCls>(__s("while dispatching notifications for $runtimeType")), [=] () {
                makeList(ArrayItem);
            }));
        };
    }
}
