#ifndef CHANNEL_BUFFERS_H
#define CHANNEL_BUFFERS_H
#include <memory>




class _ChannelCallbackRecord {
public:

    void invoke(PlatformMessageResponseCallback callbackArg, ByteData dataArg);

private:
    ChannelCallback _callback;

    Zone _zone;


     _ChannelCallbackRecord(ChannelCallback _callback);

};

class _StoredMessage {
public:
    ByteData data;


    void invoke(ByteData dataArg);

private:
    PlatformMessageResponseCallback _callback;

    Zone _zone;


     _StoredMessage(PlatformMessageResponseCallback _callback, ByteData data);

};

class _Channel {
public:
    bool debugEnableDiscardWarnings;


    int length();

    int capacity();

    void  capacity(int newSize);

    bool push(_StoredMessage message);

    _StoredMessage pop();

    void setListener(ChannelCallback callback);

    void clearListener();

private:
    ListQueue<_StoredMessage> _queue;

    int _capacity;

    bool _draining;

    _ChannelCallbackRecord _channelCallbackRecord;


     _Channel(int _capacity);

    bool _dropOverflowMessages(int lengthLimit);

    void _drain();

    void _drainStep();

};

class ChannelBuffers {
public:
    static const int kDefaultBufferSize;

    static const String kControlChannelName;


     ChannelBuffers();

    void push(PlatformMessageResponseCallback callback, ByteData data, String name);

    void setListener(ChannelCallback callback, String name);

    void clearListener(String name);

    Future<void> drain(DrainChannelCallback callback, String name);

    void handleMessage(ByteData data);

    void resize(String name, int newSize);

    void allowOverflow(bool allowed, String name);

private:
    Map<String, _Channel> _channels;


};
ChannelBuffers channelBuffers;


#endif