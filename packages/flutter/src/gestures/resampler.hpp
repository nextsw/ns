#ifndef PACKAGES_FLUTTER_SRC_GESTURES_RESAMPLER
#define PACKAGES_FLUTTER_SRC_GESTURES_RESAMPLER
#include <base.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include "events.hpp"


class PointerEventResamplerCls : public ObjectCls {
public:

    virtual void addEvent(PointerEvent event);

    virtual void sample(Duration sampleTime, Duration nextSampleTime, HandleEventCallback callback);

    virtual void stop(HandleEventCallback callback);

    virtual bool hasPendingEvents();

    virtual bool isTracked();

    virtual bool isDown();

private:
    Queue<PointerEvent> _queuedEvents;

    PointerEvent _last;

    PointerEvent _next;

    Offset _position;

    bool _isTracked;

    bool _isDown;

    int _pointerIdentifier;

    int _hasButtons;


    virtual PointerEvent _toHoverEvent(PointerEvent event, Offset position, Offset delta, Duration timeStamp, int buttons);

    virtual PointerEvent _toMoveEvent(PointerEvent event, Offset position, Offset delta, int pointerIdentifier, Duration timeStamp, int buttons);

    virtual PointerEvent _toMoveOrHoverEvent(PointerEvent event, Offset position, Offset delta, int pointerIdentifier, Duration timeStamp, bool isDown, int buttons);

    virtual Offset _positionAt(Duration sampleTime);

    virtual void _processPointerEvents(Duration sampleTime);

    virtual void _dequeueAndSampleNonHoverOrMovePointerEventsUntil(Duration sampleTime, Duration nextSampleTime, HandleEventCallback callback);

    virtual void _samplePointerPosition(Duration sampleTime, HandleEventCallback callback);

};
using PointerEventResampler = std::shared_ptr<PointerEventResamplerCls>;


#endif