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

    virtual void sample(HandleEventCallback callback, Duration nextSampleTime, Duration sampleTime);

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


    virtual PointerEvent _toHoverEvent(int buttons, Offset delta, PointerEvent event, Offset position, Duration timeStamp);

    virtual PointerEvent _toMoveEvent(int buttons, Offset delta, PointerEvent event, int pointerIdentifier, Offset position, Duration timeStamp);

    virtual PointerEvent _toMoveOrHoverEvent(int buttons, Offset delta, PointerEvent event, bool isDown, int pointerIdentifier, Offset position, Duration timeStamp);

    virtual Offset _positionAt(Duration sampleTime);

    virtual void _processPointerEvents(Duration sampleTime);

    virtual void _dequeueAndSampleNonHoverOrMovePointerEventsUntil(HandleEventCallback callback, Duration nextSampleTime, Duration sampleTime);

    virtual void _samplePointerPosition(HandleEventCallback callback, Duration sampleTime);

};
using PointerEventResampler = std::shared_ptr<PointerEventResamplerCls>;


#endif