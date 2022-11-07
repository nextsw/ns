#ifndef NOTIFICATION_LISTENER_H
#define NOTIFICATION_LISTENER_H
#include <memory>

#include <flutter/foundation.hpp>
#include "framework.hpp"



class Notification {
public:

     Notification();

    void dispatch(BuildContext target);

    String toString();

    void debugFillDescription(List<String> description);

private:

};

class NotificationListener<T extends Notification> : ProxyWidget {
public:
    NotificationListenerCallback<T> onNotification;


     NotificationListener(Unknown, Unknown, NotificationListenerCallback<T> onNotification);

    Element createElement();

private:

};

class _NotificationElement<T extends Notification> : ProxyElement {
public:

    bool onNotification(Notification notification);

    void notifyClients(ProxyWidget oldWidget);

private:

     _NotificationElement(NotificationListener<T> widget);

};

class LayoutChangedNotification : Notification {
public:

     LayoutChangedNotification();

private:

};

#endif