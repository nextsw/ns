#include "automatic_keep_alive.hpp"
State<AutomaticKeepAlive> AutomaticKeepAlive::createState() {
    return _AutomaticKeepAliveState();
}

void _AutomaticKeepAliveState::initState() {
    super.initState();
    _updateChild();
}

void _AutomaticKeepAliveState::didUpdateWidget(AutomaticKeepAlive oldWidget) {
    super.didUpdateWidget(oldWidget);
    _updateChild();
}

void _AutomaticKeepAliveState::dispose() {
    if (_handles != nullptr) {
        for (Listenable handle : _handles!.keys) {
            handle.removeListener(_handles![handle]!);
        }
    }
    super.dispose();
}

Widget _AutomaticKeepAliveState::build(BuildContext context) {
    return KeepAlive(_keepingAlive, _child);
}

void _AutomaticKeepAliveState::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super.debugFillProperties(description);
    description.add(FlagProperty("_keepingAlive"_keepingAlive, "keeping subtree alive"));
    description.add(<Map<Listenable, VoidCallback>>DiagnosticsProperty("handles", _handles_handles != nullptr? "${_handles!.length} active client${ _handles!.length == 1 ? "" : "s" }" : nullptr, "no notifications ever received"));
}

void _AutomaticKeepAliveState::_updateChild() {
    _child = <KeepAliveNotification>NotificationListener(_addClient, widget.child);
}

bool _AutomaticKeepAliveState::_addClient(KeepAliveNotification notification) {
    Listenable handle = notification.handle;
    _handles = ;
    assert(!_handles!.containsKey(handle));
    _handles![handle] = _createCallback(handle);
    handle.addListener(_handles![handle]!);
    if (!_keepingAlive) {
        _keepingAlive = true;
        ParentDataElement<KeepAliveParentDataMixin> childElement = _getChildElement();
        if (childElement != nullptr) {
            _updateParentDataOfChild(childElement);
        } else {
            SchedulerBinding.instance.addPostFrameCallback();
        }
    }
    return false;
}

ParentDataElement<KeepAliveParentDataMixin> _AutomaticKeepAliveState::_getChildElement() {
    assert(mounted);
    Element element = (;
    Element childElement;
    element.visitChildren();
    assert(childElement == nullptr || childElement is ParentDataElement<KeepAliveParentDataMixin>);
    return (;
}

void _AutomaticKeepAliveState::_updateParentDataOfChild(ParentDataElement<KeepAliveParentDataMixin> childElement) {
    childElement.applyWidgetOutOfTurn(();
}

VoidCallback _AutomaticKeepAliveState::_createCallback(Listenable handle) {
    return ;
}

KeepAliveNotification::KeepAliveNotification(Listenable handle) {
    {
        assert(handle != nullptr);
    }
}

void KeepAliveHandle::release() {
    notifyListeners();
}

void AutomaticKeepAliveClientMixin::updateKeepAlive() {
    if (wantKeepAlive) {
        if (_keepAliveHandle == nullptr) {
            _ensureKeepAlive();
        }
    } else {
        if (_keepAliveHandle != nullptr) {
            _releaseKeepAlive();
        }
    }
}

void AutomaticKeepAliveClientMixin::initState() {
    super.initState();
    if (wantKeepAlive) {
        _ensureKeepAlive();
    }
}

void AutomaticKeepAliveClientMixin::deactivate() {
    if (_keepAliveHandle != nullptr) {
        _releaseKeepAlive();
    }
    super.deactivate();
}

Widget AutomaticKeepAliveClientMixin::build(BuildContext context) {
    if (wantKeepAlive && _keepAliveHandle == nullptr) {
        _ensureKeepAlive();
    }
    return const _NullWidget();
}

void AutomaticKeepAliveClientMixin::_ensureKeepAlive() {
    assert(_keepAliveHandle == nullptr);
    _keepAliveHandle = KeepAliveHandle();
    KeepAliveNotification(_keepAliveHandle!).dispatch(context);
}

void AutomaticKeepAliveClientMixin::_releaseKeepAlive() {
    _keepAliveHandle!.release();
    _keepAliveHandle = nullptr;
}

Widget _NullWidget::build(BuildContext context) {
    ;
}
