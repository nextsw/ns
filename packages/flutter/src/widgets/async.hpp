#ifndef ASYNC_H
#define ASYNC_H
#include <memory>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include "framework.hpp"



class StreamBuilderBase<T, S> : StatefulWidget {
public:
    Stream<T> stream;


     StreamBuilderBase(Unknown, Stream<T> stream);

    S initial();

    S afterConnected(S current);

    S afterData(S current, T data);

    S afterError(S current, Object error, StackTrace stackTrace);

    S afterDone(S current);

    S afterDisconnected(S current);

    Widget build(BuildContext context, S currentSummary);

    State<StreamBuilderBase<T, S>> createState();

private:

};

class _StreamBuilderBaseState<T, S> : State<StreamBuilderBase<T, S>> {
public:

    void initState();

    void didUpdateWidget(StreamBuilderBase<T, S> oldWidget);

    Widget build(BuildContext context);

    void dispose();

private:
    StreamSubscription<T> _subscription;

    S _summary;


    void _subscribe();

    void _unsubscribe();

};

enum ConnectionState{
    none,
    waiting,
    active,
    done,
} // end ConnectionState

class AsyncSnapshot<T> {
public:
    ConnectionState connectionState;

    T data;

    Object error;

    StackTrace stackTrace;


    void  nothing();

    void  waiting();

    void  withData(T data, ConnectionState state);

    void  withError(Object error, StackTrace stackTrace, ConnectionState state);

    T requireData();

    AsyncSnapshot<T> inState(ConnectionState state);

    bool hasData();

    bool hasError();

    String toString();

    bool ==(Object other);

    int hashCode();

private:

    void  _(ConnectionState connectionState, T data, Object error, StackTrace stackTrace);

};

class StreamBuilder<T> : StreamBuilderBase<T, AsyncSnapshot<T>> {
public:
    AsyncWidgetBuilder<T> builder;

    T initialData;


     StreamBuilder(AsyncWidgetBuilder<T> builder, T initialData, Unknown, Unknown);

    AsyncSnapshot<T> initial();

    AsyncSnapshot<T> afterConnected(AsyncSnapshot<T> current);

    AsyncSnapshot<T> afterData(AsyncSnapshot<T> current, T data);

    AsyncSnapshot<T> afterError(AsyncSnapshot<T> current, Object error, StackTrace stackTrace);

    AsyncSnapshot<T> afterDone(AsyncSnapshot<T> current);

    AsyncSnapshot<T> afterDisconnected(AsyncSnapshot<T> current);

    Widget build(BuildContext context, AsyncSnapshot<T> currentSummary);

private:

};

class FutureBuilder<T> : StatefulWidget {
public:
    Future<T> future;

    AsyncWidgetBuilder<T> builder;

    T initialData;

    static bool debugRethrowError;


     FutureBuilder(AsyncWidgetBuilder<T> builder, Future<T> future, T initialData, Unknown);

    State<FutureBuilder<T>> createState();

private:

};

class _FutureBuilderState<T> : State<FutureBuilder<T>> {
public:

    void initState();

    void didUpdateWidget(FutureBuilder<T> oldWidget);

    Widget build(BuildContext context);

    void dispose();

private:
    Object _activeCallbackIdentity;

    AsyncSnapshot<T> _snapshot;


    void _subscribe();

    void _unsubscribe();

};

#endif