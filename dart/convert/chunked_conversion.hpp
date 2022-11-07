#ifndef CHUNKED_CONVERSION_H
#define CHUNKED_CONVERSION_H
#include <memory>




class ChunkedConversionSink<T> {
public:

     ChunkedConversionSink();

    void  withCallback(FunctionType callback);

    void add(T chunk);

    void close();

private:

};

class _SimpleCallbackSink<T> : ChunkedConversionSink<T> {
public:

    void add(T chunk);

    void close();

private:
    FunctionType _callback;

    List<T> _accumulated;


     _SimpleCallbackSink(FunctionType _callback);

};

class _ConverterStreamEventSink<S, T> {
public:

    void add(S o);

    void addError(Object error, StackTrace stackTrace);

    void close();

private:
    EventSink<T> _eventSink;

    Sink<S> _chunkedSink;


     _ConverterStreamEventSink(Converter<S, T> converter, EventSink<T> sink);

};

#endif