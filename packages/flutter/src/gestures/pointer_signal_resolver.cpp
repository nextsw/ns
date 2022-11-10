#include "pointer_signal_resolver.hpp"
bool _isSameEvent(PointerSignalEvent event1, PointerSignalEvent event2) {
    return (event1->original or event1) == (event2->original or event2);
}

void PointerSignalResolverCls::register(PointerSignalResolvedCallback callback, PointerSignalEvent event) {
    assert(event != nullptr);
    assert(callback != nullptr);
    assert(_currentEvent == nullptr || _isSameEvent(_currentEvent!, event));
    if (_firstRegisteredCallback != nullptr) {
        return;
    }
    _currentEvent = event;
    _firstRegisteredCallback = callback;
}

void PointerSignalResolverCls::resolve(PointerSignalEvent event) {
    if (_firstRegisteredCallback == nullptr) {
        assert(_currentEvent == nullptr);
        return;
    }
    assert(_isSameEvent(_currentEvent!, event));
    try {
        _firstRegisteredCallback!(_currentEvent!);
    } catch (Unknown exception) {
        InformationCollector collector;
        assert([=] () {
            collector = [=] ()             {
                makeList(ArrayItem);
            };
            return true;
        }());
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("gesture library"), make<ErrorDescriptionCls>(__s("while resolving a PointerSignalEvent")), collector));
    };
    _firstRegisteredCallback = nullptr;
    _currentEvent = nullptr;
}
