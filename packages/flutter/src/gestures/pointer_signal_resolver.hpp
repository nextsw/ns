#ifndef POINTER_SIGNAL_RESOLVER_H
#define POINTER_SIGNAL_RESOLVER_H
#include <memory>
#include "events.hpp"

#include <flutter/foundation.hpp>
#include "events.hpp"


bool _isSameEvent(PointerSignalEvent event1, PointerSignalEvent event2);


class PointerSignalResolver {
public:

    void register(PointerSignalResolvedCallback callback, PointerSignalEvent event);

    void resolve(PointerSignalEvent event);

private:
    PointerSignalResolvedCallback _firstRegisteredCallback;

    PointerSignalEvent _currentEvent;


};

#endif