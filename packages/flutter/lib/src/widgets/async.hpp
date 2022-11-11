#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ASYNC
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ASYNC
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "framework.hpp"


template<typename T, typename S>
class StreamBuilderBaseCls : public StatefulWidgetCls {
public:
    Stream<T> stream;


     StreamBuilderBaseCls(Key key, Stream<T> stream);
    virtual S initial();
    virtual S afterConnected(S current);

    virtual S afterData(S current, T data);
    virtual S afterError(S current, Object error, StackTrace stackTrace);

    virtual S afterDone(S current);

    virtual S afterDisconnected(S current);

    virtual Widget build(BuildContext context, S currentSummary);
    virtual State<StreamBuilderBase<T, S>> createState();

private:

};
template<typename T, typename S>
using StreamBuilderBase = std::shared_ptr<StreamBuilderBaseCls<T, S>>;

template<typename T, typename S>
class _StreamBuilderBaseStateCls : public StateCls<StreamBuilderBase<T, S>> {
public:

    virtual void initState();

    virtual void didUpdateWidget(StreamBuilderBase<T, S> oldWidget);

    virtual Widget build(BuildContext context);

    virtual void dispose();

private:
    StreamSubscription<T> _subscription;

    S _summary;


    virtual void _subscribe();

    virtual void _unsubscribe();

};
template<typename T, typename S>
using _StreamBuilderBaseState = std::shared_ptr<_StreamBuilderBaseStateCls<T, S>>;

enum ConnectionState{
    none,
    waiting,
    active,
    done,
} // end ConnectionState

template<typename T>
class AsyncSnapshotCls : public ObjectCls {
public:
    ConnectionState connectionState;

    T data;

    Object error;

    StackTrace stackTrace;


    virtual void  nothing();

    virtual void  waiting();

    virtual void  withData(ConnectionState state, T data);

    virtual void  withError(ConnectionState state, Object error, StackTrace stackTrace);

    virtual T requireData();

    virtual AsyncSnapshot<T> inState(ConnectionState state);

    virtual bool hasData();

    virtual bool hasError();

    virtual String toString();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:

    virtual void  _(ConnectionState connectionState, T data, Object error, StackTrace stackTrace);

};
template<typename T>
using AsyncSnapshot = std::shared_ptr<AsyncSnapshotCls<T>>;

template<typename T>
class StreamBuilderCls : public StreamBuilderBaseCls<T, AsyncSnapshot<T>> {
public:
    AsyncWidgetBuilder<T> builder;

    T initialData;


     StreamBuilderCls(AsyncWidgetBuilder<T> builder, T initialData, Key key, Stream<T> stream);

    virtual AsyncSnapshot<T> initial();

    virtual AsyncSnapshot<T> afterConnected(AsyncSnapshot<T> current);

    virtual AsyncSnapshot<T> afterData(AsyncSnapshot<T> current, T data);

    virtual AsyncSnapshot<T> afterError(AsyncSnapshot<T> current, Object error, StackTrace stackTrace);

    virtual AsyncSnapshot<T> afterDone(AsyncSnapshot<T> current);

    virtual AsyncSnapshot<T> afterDisconnected(AsyncSnapshot<T> current);

    virtual Widget build(BuildContext context, AsyncSnapshot<T> currentSummary);

private:

};
template<typename T>
using StreamBuilder = std::shared_ptr<StreamBuilderCls<T>>;

template<typename T>
class FutureBuilderCls : public StatefulWidgetCls {
public:
    Future<T> future;

    AsyncWidgetBuilder<T> builder;

    T initialData;

    static bool debugRethrowError;


     FutureBuilderCls(AsyncWidgetBuilder<T> builder, Future<T> future, T initialData, Key key);

    virtual State<FutureBuilder<T>> createState();

private:

};
template<typename T>
using FutureBuilder = std::shared_ptr<FutureBuilderCls<T>>;

template<typename T>
class _FutureBuilderStateCls : public StateCls<FutureBuilder<T>> {
public:

    virtual void initState();

    virtual void didUpdateWidget(FutureBuilder<T> oldWidget);

    virtual Widget build(BuildContext context);

    virtual void dispose();

private:
    Object _activeCallbackIdentity;

    AsyncSnapshot<T> _snapshot;


    virtual void _subscribe();

    virtual void _unsubscribe();

};
template<typename T>
using _FutureBuilderState = std::shared_ptr<_FutureBuilderStateCls<T>>;


#endif