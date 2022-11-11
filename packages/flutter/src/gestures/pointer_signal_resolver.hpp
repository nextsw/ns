#ifndef PACKAGES_FLUTTER_SRC_GESTURES_POINTER_SIGNAL_RESOLVER
#define PACKAGES_FLUTTER_SRC_GESTURES_POINTER_SIGNAL_RESOLVER
#include <base.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "events.hpp"

bool _isSameEvent(PointerSignalEvent event1, PointerSignalEvent event2);


class PointerSignalResolverCls : public ObjectCls {
public:

    virtual void register(PointerSignalEvent event, PointerSignalResolvedCallback callback);

    virtual void resolve(PointerSignalEvent event);

private:
    PointerSignalResolvedCallback _firstRegisteredCallback;

    PointerSignalEvent _currentEvent;


};
using PointerSignalResolver = std::shared_ptr<PointerSignalResolverCls>;


#endif