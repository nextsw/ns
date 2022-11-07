#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include "arena.hpp"
#include "events.hpp"
#include "hit_test.hpp"
#include "pointer_router.hpp"
#include "pointer_signal_resolver.hpp"

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include "arena.hpp"
#include "converter.hpp"
#include "debug.hpp"
#include "events.hpp"
#include "hit_test.hpp"
#include "pointer_router.hpp"
#include "pointer_signal_resolver.hpp"
#include "resampler.hpp"



class SamplingClock {
public:

    DateTime now();

    Stopwatch stopwatch();

private:

};

class _Resampler {
public:

    void addOrDispatch(PointerEvent event);

    void sample(SamplingClock clock, Duration samplingOffset);

    void stop();

private:
    Map<int, PointerEventResampler> _resamplers;

    bool _frameCallbackScheduled;

    Duration _frameTime;

    Stopwatch _frameTimeAge;

    Duration _lastSampleTime;

    Duration _lastEventTime;

    HandleEventCallback _handlePointerEvent;

    _HandleSampleTimeChangedCallback _handleSampleTimeChanged;

    Duration _samplingInterval;

    Timer _timer;


     _Resampler(HandleEventCallback _handlePointerEvent, _HandleSampleTimeChangedCallback _handleSampleTimeChanged, Duration _samplingInterval);

    void _onSampleTimeChanged();

};
const Duration _defaultSamplingOffset;

const Duration _samplingInterval;


class GestureBinding {
public:
    PointerRouter pointerRouter;

    GestureArenaManager gestureArena;

    PointerSignalResolver pointerSignalResolver;

    bool resamplingEnabled;

    Duration samplingOffset;


    void initInstances();

    static GestureBinding instance();

    void unlocked();

    void cancelPointer(int pointer);

    void handlePointerEvent(PointerEvent event);

    void hitTest(Offset position, HitTestResult result);

    void dispatchEvent(PointerEvent event, HitTestResult hitTestResult);

    void handleEvent(HitTestEntry entry, PointerEvent event);

    void resetGestureBinding();

    SamplingClock debugSamplingClock();

private:
    static GestureBinding _instance;

    Queue<PointerEvent> _pendingPointerEvents;

    Map<int, HitTestResult> _hitTests;

    _Resampler _resampler;


    void _handlePointerDataPacket(PointerDataPacket packet);

    void _flushPointerEventQueue();

    void _handlePointerEventImmediately(PointerEvent event);

    void _handleSampleTimeChanged();

    SamplingClock _samplingClock();

};

class FlutterErrorDetailsForPointerEventDispatcher : FlutterErrorDetails {
public:
    PointerEvent event;

    HitTestEntry hitTestEntry;


     FlutterErrorDetailsForPointerEventDispatcher(Unknown, PointerEvent event, Unknown, HitTestEntry hitTestEntry, Unknown, Unknown, Unknown, Unknown);

private:

};

#endif