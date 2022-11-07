#include "notification_listener.hpp"
void Notification::dispatch(BuildContext target) {
    target?.dispatchNotification(this);
}

String Notification::toString() {
    List<String> description = ;
    debugFillDescription(description);
    return "${objectRuntimeType(this, 'Notification')}(${description.join(", ")})";
}

void Notification::debugFillDescription(List<String> description) {
}

Element NotificationListener::createElement() {
    return <T>_NotificationElement(this);
}

bool _NotificationElement::onNotification(Notification notification) {
    NotificationListener<T> listener = (;
    if (listener.onNotification != nullptr && notification is T) {
        return listener.onNotification!(notification);
    }
    return false;
}

void _NotificationElement::notifyClients(ProxyWidget oldWidget) {
}
