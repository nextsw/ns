#include "notification_listener.hpp"
void NotificationCls::dispatch(BuildContext target) {
    target?->dispatchNotification(this);
}

String NotificationCls::toString() {
    List<String> description = makeList();
    debugFillDescription(description);
    return "${objectRuntimeType(this, 'Notification')}(${description.join(", ")})";
}

void NotificationCls::debugFillDescription(List<String> description) {
}

template<typename T : Notification> Element NotificationListenerCls<T>::createElement() {
    return <T>make<_NotificationElementCls>(this);
}

template<typename T : Notification> bool _NotificationElementCls<T>::onNotification(Notification notification) {
    NotificationListener<T> listener = ((NotificationListener<T>)widget);
    if (listener->onNotification != nullptr && notification is T) {
        return listener->onNotification!(notification);
    }
    return false;
}

template<typename T : Notification> void _NotificationElementCls<T>::notifyClients(ProxyWidget oldWidget) {
}
