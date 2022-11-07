#ifndef ASYNC_CAST_H
#define ASYNC_CAST_H
#include <memory>




class CastStream<S, T> : Stream<T> {
public:

     CastStream(Stream<S> _source);

    bool isBroadcast();

    StreamSubscription<T> listen(bool cancelOnError, FunctionType onData, FunctionType onDone, FunctionType onError);

    Stream<R> cast<R>();

private:
    Stream<S> _source;


};

class CastStreamSubscription<S, T> {
public:

     CastStreamSubscription(StreamSubscription<S> _source);

    Future cancel();

    void onData(FunctionType handleData);

    void onError(FunctionType handleError);

    void onDone(FunctionType handleDone);

    void pause(Future resumeSignal);

    void resume();

    bool isPaused();

    Future<E> asFuture<E>(E futureValue);

private:
    StreamSubscription<S> _source;

    Zone _zone;

    FunctionType _handleData;

    FunctionType _handleError;


    void _onData(S data);

};

class CastStreamTransformer<SS, ST, TS, TT> : StreamTransformerBase<TS, TT> {
public:

     CastStreamTransformer(StreamTransformer<SS, ST> _source);

    StreamTransformer<RS, RT> cast<RS, RT>();

    Stream<TT> bind(Stream<TS> stream);

private:
    StreamTransformer<SS, ST> _source;


};

class CastConverter<SS, ST, TS, TT> : Converter<TS, TT> {
public:

     CastConverter(Converter<SS, ST> _source);

    TT convert(TS input);

    Stream<TT> bind(Stream<TS> stream);

    Converter<RS, RT> cast<RS, RT>();

private:
    Converter<SS, ST> _source;


};

#endif