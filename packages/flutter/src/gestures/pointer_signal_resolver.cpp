#include "pointer_signal_resolver.hpp"
bool _isSameEvent(PointerSignalEvent event1, PointerSignalEvent event2) {
    return (event1.original ?? event1) == (event2.original ?? event2);
}

void PointerSignalResolver::register(PointerSignalResolvedCallback callback, PointerSignalEvent event) {
    assert(event != nullptr);
    assert(callback != nullptr);
    assert(_currentEvent == nullptr || _isSameEvent(_currentEvent!, event));
    if (_firstRegisteredCallback != nullptr) {
        return;
    }
    _currentEvent = event;
    _firstRegisteredCallback = callback;
}

void PointerSignalResolver::resolve(PointerSignalEvent event) {
    if (_firstRegisteredCallback == nullptr) {
        assert(_currentEvent == nullptr);
        return;
    }
    assert(_isSameEvent(_currentEvent!, event));
    ;
    _firstRegisteredCallback = nullptr;
    _currentEvent = nullptr;
}
