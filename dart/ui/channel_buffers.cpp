#include "channel_buffers.hpp"
void _ChannelCallbackRecord::invoke(PlatformMessageResponseCallback callbackArg, ByteData dataArg) {
    <ByteData, PlatformMessageResponseCallback>_invoke2(_callback, _zone, dataArg, callbackArg);
}

_ChannelCallbackRecord::_ChannelCallbackRecord(ChannelCallback _callback) {
    {
        _zone = Zone.current;
    }
}

void _StoredMessage::invoke(ByteData dataArg) {
    _invoke1(_callback, _zone, dataArg);
}

_StoredMessage::_StoredMessage(PlatformMessageResponseCallback _callback, ByteData data) {
    {
        _zone = Zone.current;
    }
}

int _Channel::length() {
    return _queue.length;
}

int _Channel::capacity() {
    return _capacity;
}

void _Channel::capacity(int newSize) {
    _capacity = newSize;
    _dropOverflowMessages(newSize);
}

bool _Channel::push(_StoredMessage message) {
    if (!_draining && _channelCallbackRecord != nullptr) {
        assert(_queue.isEmpty);
        _channelCallbackRecord!.invoke(message.data, message.invoke);
        return false;
    }
    if (_capacity <= 0) {
        return debugEnableDiscardWarnings;
    }
    bool result = _dropOverflowMessages(_capacity - 1);
    _queue.addLast(message);
    return result;
}

_StoredMessage _Channel::pop() {
    return _queue.removeFirst();
}

void _Channel::setListener(ChannelCallback callback) {
    bool needDrain = _channelCallbackRecord == nullptr;
    _channelCallbackRecord = _ChannelCallbackRecord(callback);
    if (needDrain && !_draining)     {
        _drain();
    }
}

void _Channel::clearListener() {
    _channelCallbackRecord = nullptr;
}

_Channel::_Channel(int _capacity) {
    {
        _queue = collection.<_StoredMessage>ListQueue(_capacity);
    }
}

bool _Channel::_dropOverflowMessages(int lengthLimit) {
    bool result = false;
    while (_queue.length > lengthLimit) {
        _StoredMessage message = _queue.removeFirst();
        message.invoke(nullptr);
        result = true;
    }
    return result;
}

void _Channel::_drain() {
    assert(!_draining);
    _draining = true;
    scheduleMicrotask(_drainStep);
}

void _Channel::_drainStep() {
    assert(_draining);
    if (_queue.isNotEmpty && _channelCallbackRecord != nullptr) {
        _StoredMessage message = pop();
        _channelCallbackRecord!.invoke(message.data, message.invoke);
        scheduleMicrotask(_drainStep);
    } else {
        _draining = false;
    }
}

void ChannelBuffers::push(PlatformMessageResponseCallback callback, ByteData data, String name) {
    _Channel channel = _channels.putIfAbsent(name, );
    if (channel.push(_StoredMessage(data, callback))) {
        _printDebug("A message on the $name channel was discarded before it could be handled.\nThis happens when a plugin sends messages to the framework side before the framework has had an opportunity to register a listener. See the ChannelBuffers API documentation for details on how to configure the channel to expect more messages, or to expect messages to get discarded:\n  https://api.flutter.dev/flutter/dart-ui/ChannelBuffers-class.html");
    }
}

void ChannelBuffers::setListener(ChannelCallback callback, String name) {
    _Channel channel = _channels.putIfAbsent(name, );
    channel.setListener(callback);
}

void ChannelBuffers::clearListener(String name) {
    _Channel channel = _channels[name];
    if (channel != nullptr)     {
        channel.clearListener();
    }
}

Future<void> ChannelBuffers::drain(DrainChannelCallback callback, String name) {
    _Channel channel = _channels[name];
    while (channel != nullptr && !channel._queue.isEmpty) {
        _StoredMessage message = channel.pop();
        await await callback(message.data, message.invoke);
    }
}

void ChannelBuffers::handleMessage(ByteData data) {
    Uint8List bytes = data.buffer.asUint8List(data.offsetInBytes, data.lengthInBytes);
    if (bytes[0] == 0x07) {
        int methodNameLength = bytes[1];
        if (methodNameLength >= 254)         {
            ;
        }
        int index = 2;
        String methodName = utf8.decode(bytes.sublist(index, index + methodNameLength));
        index = methodNameLength;
        ;
    } else {
        List<String> parts = utf8.decode(bytes).split("\r");
        if (parts.length == 1 + 2 && parts[0] == "resize") {
            resize(parts[1], int.parse(parts[2]));
        } else {
            ;
        }
    }
}

void ChannelBuffers::resize(String name, int newSize) {
    _Channel channel = _channels[name];
    if (channel == nullptr) {
        channel = _Channel(newSize);
        _channels[name] = channel;
    } else {
        channel.capacity = newSize;
    }
}

void ChannelBuffers::allowOverflow(bool allowed, String name) {
    assert(());
}
