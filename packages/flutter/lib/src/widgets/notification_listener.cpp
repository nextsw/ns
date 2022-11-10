#include "notification_listener.hpp"
void NotificationCls::dispatch(BuildContext target) {
    target?->dispatchNotification(this);
}

String NotificationCls::toString() {
    List<String> description = makeList();
    debugFillDescription(description);
    return __s("${objectRuntimeType(this, 'Notification')}(${description.join(", ")})");
}

void NotificationCls::debugFillDescription(List<String> description) {
}

template<typename T> Element NotificationListenerCls<T>::createElement() {
    return <T>make<_NotificationElementCls>(this);
}

template<typename T> bool _NotificationElementCls<T>::onNotification(Notification notification) {
    NotificationListener<T> listener = as<NotificationListener<T>>(widget);
    if (listener->onNotification != nullptr && is<T>(notification)) {
        return listener->onNotification!(notification);
    }
    return false;
}

template<typename T> void _NotificationElementCls<T>::notifyClients(ProxyWidget oldWidget) {
}
