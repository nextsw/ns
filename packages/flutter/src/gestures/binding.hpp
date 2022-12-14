#ifndef PACKAGES_FLUTTER_SRC_GESTURES_BINDING
#define PACKAGES_FLUTTER_SRC_GESTURES_BINDING
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "arena.hpp"
#include "events.hpp"
#include "hit_test.hpp"
#include "pointer_router.hpp"
#include "pointer_signal_resolver.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "arena.hpp"
#include "converter.hpp"
#include "debug.hpp"
#include "events.hpp"
#include "hit_test.hpp"
#include "pointer_router.hpp"
#include "pointer_signal_resolver.hpp"
#include "resampler.hpp"


class SamplingClockCls : public ObjectCls {
public:

    virtual DateTime now();

    virtual Stopwatch stopwatch();

private:

};
using SamplingClock = std::shared_ptr<SamplingClockCls>;

class _ResamplerCls : public ObjectCls {
public:

    virtual void addOrDispatch(PointerEvent event);

    virtual void sample(Duration samplingOffset, SamplingClock clock);

    virtual void stop();

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


     _ResamplerCls(HandleEventCallback _handlePointerEvent, _HandleSampleTimeChangedCallback _handleSampleTimeChanged, Duration _samplingInterval);
    virtual void _onSampleTimeChanged();

};
using _Resampler = std::shared_ptr<_ResamplerCls>;
Duration _defaultSamplingOffset;

Duration _samplingInterval;


class GestureBindingCls : public ObjectCls {
public:
    PointerRouter pointerRouter;

    GestureArenaManager gestureArena;

    PointerSignalResolver pointerSignalResolver;

    bool resamplingEnabled;

    Duration samplingOffset;


    virtual void initInstances();

    static GestureBinding instance();

    virtual void unlocked();

    virtual void cancelPointer(int pointer);

    virtual void handlePointerEvent(PointerEvent event);

    virtual void hitTest(HitTestResult result, Offset position);

    virtual void dispatchEvent(PointerEvent event, HitTestResult hitTestResult);

    virtual void handleEvent(PointerEvent event, HitTestEntry<any> entry);

    virtual void resetGestureBinding();

    virtual SamplingClock debugSamplingClock();

private:
    static GestureBinding _instance;

    Queue<PointerEvent> _pendingPointerEvents;

    Map<int, HitTestResult> _hitTests;

    _Resampler _resampler;


    virtual void _handlePointerDataPacket(PointerDataPacket packet);

    virtual void _flushPointerEventQueue();

    virtual void _handlePointerEventImmediately(PointerEvent event);

    virtual void _handleSampleTimeChanged();

    virtual SamplingClock _samplingClock();

};
using GestureBinding = std::shared_ptr<GestureBindingCls>;

class FlutterErrorDetailsForPointerEventDispatcherCls : public FlutterErrorDetailsCls {
public:
    PointerEvent event;

    HitTestEntry<any> hitTestEntry;


     FlutterErrorDetailsForPointerEventDispatcherCls(DiagnosticsNode context, PointerEvent event, Object exception, HitTestEntry<any> hitTestEntry, InformationCollector informationCollector, String library, bool silent, StackTrace stack);
private:

};
using FlutterErrorDetailsForPointerEventDispatcher = std::shared_ptr<FlutterErrorDetailsForPointerEventDispatcherCls>;


#endif