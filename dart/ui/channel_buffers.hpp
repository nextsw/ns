#ifndef DART_UI_CHANNEL_BUFFERS
#define DART_UI_CHANNEL_BUFFERS
#include <base.hpp>

#include <dart/core/core.hpp>


class _ChannelCallbackRecordCls : public ObjectCls {
public:

    virtual void invoke(ByteData dataArg, PlatformMessageResponseCallback callbackArg);

private:
    ChannelCallback _callback;

    Zone _zone;


     _ChannelCallbackRecordCls(ChannelCallback _callback);

};
using _ChannelCallbackRecord = std::shared_ptr<_ChannelCallbackRecordCls>;

class _StoredMessageCls : public ObjectCls {
public:
    ByteData data;


    virtual void invoke(ByteData dataArg);

private:
    PlatformMessageResponseCallback _callback;

    Zone _zone;


     _StoredMessageCls(ByteData data, PlatformMessageResponseCallback _callback);

};
using _StoredMessage = std::shared_ptr<_StoredMessageCls>;

class _ChannelCls : public ObjectCls {
public:
    bool debugEnableDiscardWarnings;


    virtual int length();

    virtual int capacity();

    virtual void  capacity(int newSize);

    virtual bool push(_StoredMessage message);

    virtual _StoredMessage pop();

    virtual void setListener(ChannelCallback callback);

    virtual void clearListener();

private:
    ListQueue<_StoredMessage> _queue;

    int _capacity;

    bool _draining;

    _ChannelCallbackRecord _channelCallbackRecord;


     _ChannelCls(int _capacity);

    virtual bool _dropOverflowMessages(int lengthLimit);

    virtual void _drain();

    virtual void _drainStep();

};
using _Channel = std::shared_ptr<_ChannelCls>;

class ChannelBuffersCls : public ObjectCls {
public:
    static int kDefaultBufferSize;

    static String kControlChannelName;


     ChannelBuffersCls();
    virtual void push(String name, ByteData data, PlatformMessageResponseCallback callback);

    virtual void setListener(String name, ChannelCallback callback);

    virtual void clearListener(String name);

    virtual Future<void> drain(String name, DrainChannelCallback callback);

    virtual void handleMessage(ByteData data);

    virtual void resize(String name, int newSize);

    virtual void allowOverflow(String name, bool allowed);

private:
    Map<String, _Channel> _channels;


};
using ChannelBuffers = std::shared_ptr<ChannelBuffersCls>;
ChannelBuffers channelBuffers;



#endif