#include "plugins.hpp"
void CallbackHandleCls::fromRawHandle(int _handle)

int CallbackHandleCls::toRawHandle() {
    return _handle;
}

bool CallbackHandleCls::==(Object other) {
    if (runtimeType != other->runtimeType())     {
        return false;
    }
    return is<CallbackHandle>(other) && other->_handle == _handle;
}

int CallbackHandleCls::hashCode() {
    return _handle->hashCode;
}

CallbackHandle PluginUtilitiesCls::getCallbackHandle(std::function<void ()> callback) {
    assert(callback != nullptr, __s("'callback' must not be null."));
    return _forwardCache->putIfAbsent(callback, [=] () {
        int handle = _getCallbackHandle(callback);
        return handle != nullptr? CallbackHandleCls->fromRawHandle(handle) : nullptr;
    });
}

std::function<void ()> PluginUtilitiesCls::getCallbackFromHandle(CallbackHandle handle) {
    assert(handle != nullptr, __s("'handle' must not be null."));
    return _backwardCache->putIfAbsent(handle, [=] ()     {
        _getCallbackFromHandle(handle->toRawHandle());
    });
}

void PluginUtilitiesCls::_() {
    return ;
}
