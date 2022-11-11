#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NOTIFICATION_LISTENER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_NOTIFICATION_LISTENER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "framework.hpp"


class NotificationCls : public ObjectCls {
public:

     NotificationCls();
    virtual void dispatch(BuildContext target);

    virtual String toString();

    virtual void debugFillDescription(List<String> description);

private:

};
using Notification = std::shared_ptr<NotificationCls>;

template<typename T>
class NotificationListenerCls : public ProxyWidgetCls {
public:
    NotificationListenerCallback<T> onNotification;


     NotificationListenerCls(Unknown child, Unknown key, NotificationListenerCallback<T> onNotification);
    virtual Element createElement();

private:

};
template<typename T>
using NotificationListener = std::shared_ptr<NotificationListenerCls<T>>;

template<typename T>
class _NotificationElementCls : public ProxyElementCls {
public:

    virtual bool onNotification(Notification notification);

    virtual void notifyClients(ProxyWidget oldWidget);

private:

     _NotificationElementCls(NotificationListener<T> widget);
};
template<typename T>
using _NotificationElement = std::shared_ptr<_NotificationElementCls<T>>;

class LayoutChangedNotificationCls : public NotificationCls {
public:

     LayoutChangedNotificationCls();
private:

};
using LayoutChangedNotification = std::shared_ptr<LayoutChangedNotificationCls>;


#endif