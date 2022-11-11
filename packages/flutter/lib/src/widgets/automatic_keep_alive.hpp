#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_AUTOMATIC_KEEP_ALIVE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_AUTOMATIC_KEEP_ALIVE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"
#include "sliver.hpp"


class AutomaticKeepAliveCls : public StatefulWidgetCls {
public:
    Widget child;


     AutomaticKeepAliveCls(Widget child, Unknown key);
    virtual State<AutomaticKeepAlive> createState();

private:

};
using AutomaticKeepAlive = std::shared_ptr<AutomaticKeepAliveCls>;

class _AutomaticKeepAliveStateCls : public StateCls<AutomaticKeepAlive> {
public:

    virtual void initState();

    virtual void didUpdateWidget(AutomaticKeepAlive oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    Map<Listenable, VoidCallback> _handles;

    Widget _child;

    bool _keepingAlive;


    virtual void _updateChild();

    virtual bool _addClient(KeepAliveNotification notification);

    virtual ParentDataElement<KeepAliveParentDataMixin> _getChildElement();

    virtual void _updateParentDataOfChild(ParentDataElement<KeepAliveParentDataMixin> childElement);

    virtual VoidCallback _createCallback(Listenable handle);

};
using _AutomaticKeepAliveState = std::shared_ptr<_AutomaticKeepAliveStateCls>;

class KeepAliveNotificationCls : public NotificationCls {
public:
    Listenable handle;


     KeepAliveNotificationCls(Listenable handle);

private:

};
using KeepAliveNotification = std::shared_ptr<KeepAliveNotificationCls>;

class KeepAliveHandleCls : public ChangeNotifierCls {
public:

    virtual void release();

private:

};
using KeepAliveHandle = std::shared_ptr<KeepAliveHandleCls>;

template<typename T>
class AutomaticKeepAliveClientMixinCls : public ObjectCls {
public:

    virtual bool wantKeepAlive();
    virtual void updateKeepAlive();

    virtual void initState();

    virtual void deactivate();

    virtual Widget build(BuildContext context);

private:
    KeepAliveHandle _keepAliveHandle;


    virtual void _ensureKeepAlive();

    virtual void _releaseKeepAlive();

};
template<typename T>
using AutomaticKeepAliveClientMixin = std::shared_ptr<AutomaticKeepAliveClientMixinCls<T>>;

class _NullWidgetCls : public StatelessWidgetCls {
public:

    virtual Widget build(BuildContext context);

private:

     _NullWidgetCls();
};
using _NullWidget = std::shared_ptr<_NullWidgetCls>;


#endif