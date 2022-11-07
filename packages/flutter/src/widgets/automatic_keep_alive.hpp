#ifndef AUTOMATIC_KEEP_ALIVE_H
#define AUTOMATIC_KEEP_ALIVE_H
#include <memory>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "framework.hpp"
#include "notification_listener.hpp"
#include "sliver.hpp"



class AutomaticKeepAlive : StatefulWidget {
public:
    Widget child;


     AutomaticKeepAlive(Widget child, Unknown);

    State<AutomaticKeepAlive> createState();

private:

};

class _AutomaticKeepAliveState : State<AutomaticKeepAlive> {
public:

    void initState();

    void didUpdateWidget(AutomaticKeepAlive oldWidget);

    void dispose();

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder description);

private:
    Map<Listenable, VoidCallback> _handles;

    Widget _child;

    bool _keepingAlive;


    void _updateChild();

    bool _addClient(KeepAliveNotification notification);

    ParentDataElement<KeepAliveParentDataMixin> _getChildElement();

    void _updateParentDataOfChild(ParentDataElement<KeepAliveParentDataMixin> childElement);

    VoidCallback _createCallback(Listenable handle);

};

class KeepAliveNotification : Notification {
public:
    Listenable handle;


     KeepAliveNotification(Listenable handle);

private:

};

class KeepAliveHandle : ChangeNotifier {
public:

    void release();

private:

};

class AutomaticKeepAliveClientMixin<T extends StatefulWidget> {
public:

    bool wantKeepAlive();

    void updateKeepAlive();

    void initState();

    void deactivate();

    Widget build(BuildContext context);

private:
    KeepAliveHandle _keepAliveHandle;


    void _ensureKeepAlive();

    void _releaseKeepAlive();

};

class _NullWidget : StatelessWidget {
public:

    Widget build(BuildContext context);

private:

     _NullWidget();

};

#endif