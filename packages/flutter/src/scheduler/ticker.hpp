#ifndef TICKER_H
#define TICKER_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include "binding.hpp"



class TickerProvider {
public:

     TickerProvider();

    Ticker createTicker(TickerCallback onTick);

private:

};

class Ticker {
public:
    String debugLabel;


     Ticker(TickerCallback _onTick, String debugLabel);

    bool muted();

    void  muted(bool value);

    bool isTicking();

    bool isActive();

    TickerFuture start();

    DiagnosticsNode describeForError(String name);

    void stop(bool canceled);

    bool scheduled();

    bool shouldScheduleTick();

    void scheduleTick(bool rescheduling);

    void unscheduleTick();

    void absorbTicker(Ticker originalTicker);

    void dispose();

    String toString(bool debugIncludeStack);

private:
    TickerFuture _future;

    bool _muted;

    Duration _startTime;

    TickerCallback _onTick;

    int _animationId;

    StackTrace _debugCreationStack;


    void _tick(Duration timeStamp);

};

class TickerFuture {
public:

    void  complete();

    void whenCompleteOrCancel(VoidCallback callback);

    Future<void> orCancel();

    Stream<void> asStream();

    Future<void> catchError(FunctionType onError, FunctionType test);

    Future<R> then<R>(FunctionType onError, FunctionType onValue);

    Future<void> timeout(FunctionType onTimeout, Duration timeLimit);

    Future<void> whenComplete(FunctionType action);

    String toString();

private:
    Completer<void> _primaryCompleter;

    Completer<void> _secondaryCompleter;

    bool _completed;


    void  _();

    void _complete();

    void _cancel(Ticker ticker);

};

class TickerCanceled {
public:
    Ticker ticker;


     TickerCanceled(Ticker ticker);

    String toString();

private:

};

#endif