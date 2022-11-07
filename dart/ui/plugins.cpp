#include "plugins.hpp"
void CallbackHandle::fromRawHandle(int _handle)

int CallbackHandle::toRawHandle() {
    return _handle;
}

bool CallbackHandle::==(Object other) {
    if (runtimeType != other.runtimeType)     {
        return false;
    }
    return other is CallbackHandle && other._handle == _handle;
}

int CallbackHandle::hashCode() {
    return _handle.hashCode;
}

CallbackHandle PluginUtilities::getCallbackHandle(FunctionType callback) {
    assert(callback != nullptr, "'callback' must not be null.");
    return _forwardCache.putIfAbsent(callback, );
}

FunctionType PluginUtilities::getCallbackFromHandle(CallbackHandle handle) {
    assert(handle != nullptr, "'handle' must not be null.");
    return _backwardCache.putIfAbsent(handle, );
}

void PluginUtilities::_() {
    return ;
}
