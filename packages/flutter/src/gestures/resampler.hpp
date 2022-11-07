#ifndef RESAMPLER_H
#define RESAMPLER_H
#include <memory>
#include "events.hpp"

#include <collection/collection.hpp>
#include "events.hpp"



class PointerEventResampler {
public:

    void addEvent(PointerEvent event);

    void sample(HandleEventCallback callback, Duration nextSampleTime, Duration sampleTime);

    void stop(HandleEventCallback callback);

    bool hasPendingEvents();

    bool isTracked();

    bool isDown();

private:
    Queue<PointerEvent> _queuedEvents;

    PointerEvent _last;

    PointerEvent _next;

    Offset _position;

    bool _isTracked;

    bool _isDown;

    int _pointerIdentifier;

    int _hasButtons;


    PointerEvent _toHoverEvent(int buttons, Offset delta, PointerEvent event, Offset position, Duration timeStamp);

    PointerEvent _toMoveEvent(int buttons, Offset delta, PointerEvent event, int pointerIdentifier, Offset position, Duration timeStamp);

    PointerEvent _toMoveOrHoverEvent(int buttons, Offset delta, PointerEvent event, bool isDown, int pointerIdentifier, Offset position, Duration timeStamp);

    Offset _positionAt(Duration sampleTime);

    void _processPointerEvents(Duration sampleTime);

    void _dequeueAndSampleNonHoverOrMovePointerEventsUntil(HandleEventCallback callback, Duration nextSampleTime, Duration sampleTime);

    void _samplePointerPosition(HandleEventCallback callback, Duration sampleTime);

};

#endif