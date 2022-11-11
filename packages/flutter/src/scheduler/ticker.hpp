#ifndef PACKAGES_FLUTTER_SRC_SCHEDULER_TICKER
#define PACKAGES_FLUTTER_SRC_SCHEDULER_TICKER
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binding.hpp"


class TickerProviderCls : public ObjectCls {
public:

     TickerProviderCls();
    virtual Ticker createTicker(TickerCallback onTick);
private:

};
using TickerProvider = std::shared_ptr<TickerProviderCls>;

class TickerCls : public ObjectCls {
public:
    String debugLabel;


     TickerCls(TickerCallback _onTick, String debugLabel);

    virtual bool muted();

    virtual void  muted(bool value);

    virtual bool isTicking();

    virtual bool isActive();

    virtual TickerFuture start();

    virtual DiagnosticsNode describeForError(String name);

    virtual void stop(bool canceled);

    virtual bool scheduled();

    virtual bool shouldScheduleTick();

    virtual void scheduleTick(bool rescheduling);

    virtual void unscheduleTick();

    virtual void absorbTicker(Ticker originalTicker);

    virtual void dispose();

    virtual String toString(bool debugIncludeStack);

private:
    TickerFuture _future;

    bool _muted;

    Duration _startTime;

    TickerCallback _onTick;

    int _animationId;

    StackTrace _debugCreationStack;


    virtual void _tick(Duration timeStamp);

};
using Ticker = std::shared_ptr<TickerCls>;

class TickerFutureCls : public ObjectCls {
public:

    virtual void  complete();

    virtual void whenCompleteOrCancel(VoidCallback callback);

    virtual Future<void> orCancel();

    virtual Stream<void> asStream();

    virtual Future<void> catchError(std::function<void ()> onError, std::function<bool(Object )> test);

    template<typename R>
 virtual Future<R> then(std::function<FutureOr<R>(void value)> onValue, std::function<void ()> onError);

    virtual Future<void> timeout(Duration timeLimit, std::function<FutureOr<void>()> onTimeout);

    virtual Future<void> whenComplete(std::function<dynamic()> action);

    virtual String toString();

private:
    Completer<void> _primaryCompleter;

    Completer<void> _secondaryCompleter;

    bool _completed;


    virtual void  _();
    virtual void _complete();

    virtual void _cancel(Ticker ticker);

};
using TickerFuture = std::shared_ptr<TickerFutureCls>;

class TickerCanceledCls : public ObjectCls {
public:
    Ticker ticker;


     TickerCanceledCls(Ticker ticker);
    virtual String toString();

private:

};
using TickerCanceled = std::shared_ptr<TickerCanceledCls>;


#endif