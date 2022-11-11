#include "automatic_keep_alive.hpp"
State<AutomaticKeepAlive> AutomaticKeepAliveCls::createState() {
    return make<_AutomaticKeepAliveStateCls>();
}

void _AutomaticKeepAliveStateCls::initState() {
    super->initState();
    _updateChild();
}

void _AutomaticKeepAliveStateCls::didUpdateWidget(AutomaticKeepAlive oldWidget) {
    super->didUpdateWidget(oldWidget);
    _updateChild();
}

void _AutomaticKeepAliveStateCls::dispose() {
    if (_handles != nullptr) {
        for (Listenable handle : _handles!->keys()) {
            handle->removeListener(_handles![handle]!);
        }
    }
    super->dispose();
}

Widget _AutomaticKeepAliveStateCls::build(BuildContext context) {
    return make<KeepAliveCls>(_keepingAlive, _child);
}

void _AutomaticKeepAliveStateCls::debugFillProperties(DiagnosticPropertiesBuilder description) {
    super->debugFillProperties(description);
    description->add(make<FlagPropertyCls>(__s("_keepingAlive")_keepingAlive, __s("keeping subtree alive")));
    description->add(<Map<Listenable, VoidCallback>>make<DiagnosticsPropertyCls>(__s("handles"), _handles_handles != nullptr? __s("${_handles!.length} active client${ _handles!.length == 1 ? "" : "s" }") : nullptr, __s("no notifications ever received")));
}

void _AutomaticKeepAliveStateCls::_updateChild() {
    _child = <KeepAliveNotification>make<NotificationListenerCls>(_addClient, widget->child);
}

bool _AutomaticKeepAliveStateCls::_addClient(KeepAliveNotification notification) {
    Listenable handle = notification->handle;
    _handles |= makeMap(makeList(), makeList();
    assert(!_handles!->containsKey(handle));
    _handles![handle] = _createCallback(handle);
    handle->addListener(_handles![handle]!);
    if (!_keepingAlive) {
        _keepingAlive = true;
        ParentDataElement<KeepAliveParentDataMixin> childElement = _getChildElement();
        if (childElement != nullptr) {
            _updateParentDataOfChild(childElement);
        } else {
            SchedulerBindingCls::instance->addPostFrameCallback([=] (Duration timeStamp) {
                if (!mounted) {
                    return;
                }
                ParentDataElement<KeepAliveParentDataMixin> childElement = _getChildElement();
                assert(childElement != nullptr);
                _updateParentDataOfChild(childElement!);
            });
        }
    }
    return false;
}

ParentDataElement<KeepAliveParentDataMixin> _AutomaticKeepAliveStateCls::_getChildElement() {
    assert(mounted);
    Element element = as<Element>(context);
    Element childElement;
    element->visitChildren([=] (Element child) {
        childElement = child;
    });
    assert(childElement == nullptr || is<ParentDataElement<KeepAliveParentDataMixin>>(childElement));
    return as<ParentDataElement<KeepAliveParentDataMixin>>(childElement);
}

void _AutomaticKeepAliveStateCls::_updateParentDataOfChild(ParentDataElement<KeepAliveParentDataMixin> childElement) {
    childElement->applyWidgetOutOfTurn(as<ParentDataWidget<KeepAliveParentDataMixin>>(build(context)));
}

VoidCallback _AutomaticKeepAliveStateCls::_createCallback(Listenable handle) {
    return [=] () {
        assert([=] () {
            if (!mounted) {
                throw make<FlutterErrorCls>(__s("AutomaticKeepAlive handle triggered after AutomaticKeepAlive was disposed.\nWidgets should always trigger their KeepAliveNotification handle when they are deactivated, so that they (or their handle) do not send spurious events later when they are no longer in the tree."));
            }
            return true;
        }());
        _handles!->remove(handle);
        if (_handles!->isEmpty()) {
            if (SchedulerBindingCls::instance->schedulerPhase->index < SchedulerPhaseCls::persistentCallbacks->index) {
                setState([=] () {
                    _keepingAlive = false;
                });
            } else {
                _keepingAlive = false;
                scheduleMicrotask([=] () {
                    if (mounted && _handles!->isEmpty()) {
                        setState([=] () {
                            assert(!_keepingAlive);
                        });
                    }
                });
            }
        }
    };
}

KeepAliveNotificationCls::KeepAliveNotificationCls(Listenable handle) {
    {
        assert(handle != nullptr);
    }
}

void KeepAliveHandleCls::release() {
    notifyListeners();
}

template<typename T>
void AutomaticKeepAliveClientMixinCls<T>::updateKeepAlive() {
    if (wantKeepAlive()) {
        if (_keepAliveHandle == nullptr) {
            _ensureKeepAlive();
        }
    } else {
        if (_keepAliveHandle != nullptr) {
            _releaseKeepAlive();
        }
    }
}

template<typename T>
void AutomaticKeepAliveClientMixinCls<T>::initState() {
    super->initState();
    if (wantKeepAlive()) {
        _ensureKeepAlive();
    }
}

template<typename T>
void AutomaticKeepAliveClientMixinCls<T>::deactivate() {
    if (_keepAliveHandle != nullptr) {
        _releaseKeepAlive();
    }
    super->deactivate();
}

template<typename T>
Widget AutomaticKeepAliveClientMixinCls<T>::build(BuildContext context) {
    if (wantKeepAlive() && _keepAliveHandle == nullptr) {
        _ensureKeepAlive();
    }
    return make<_NullWidgetCls>();
}

template<typename T>
void AutomaticKeepAliveClientMixinCls<T>::_ensureKeepAlive() {
    assert(_keepAliveHandle == nullptr);
    _keepAliveHandle = make<KeepAliveHandleCls>();
    make<KeepAliveNotificationCls>(_keepAliveHandle!)->dispatch(context);
}

template<typename T>
void AutomaticKeepAliveClientMixinCls<T>::_releaseKeepAlive() {
    _keepAliveHandle!->release();
    _keepAliveHandle = nullptr;
}

Widget _NullWidgetCls::build(BuildContext context) {
    throw make<FlutterErrorCls>(__s("Widgets that mix AutomaticKeepAliveClientMixin into their State must call super.build() but must ignore the return value of the superclass."));
}
