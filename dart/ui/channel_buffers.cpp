#include "channel_buffers.hpp"
void _ChannelCallbackRecordCls::invoke(ByteData dataArg, PlatformMessageResponseCallback callbackArg) {
    <ByteData, PlatformMessageResponseCallback>_invoke2(_callback, _zone, dataArg, callbackArg);
}

_ChannelCallbackRecordCls::_ChannelCallbackRecordCls(ChannelCallback _callback) {
    {
        _zone = ZoneCls::current;
    }
}

void _StoredMessageCls::invoke(ByteData dataArg) {
    _invoke1(_callback, _zone, dataArg);
}

_StoredMessageCls::_StoredMessageCls(ByteData data, PlatformMessageResponseCallback _callback) {
    {
        _zone = ZoneCls::current;
    }
}

int _ChannelCls::length() {
    return _queue->length();
}

int _ChannelCls::capacity() {
    return _capacity;
}

void _ChannelCls::capacity(int newSize) {
    _capacity = newSize;
    _dropOverflowMessages(newSize);
}

bool _ChannelCls::push(_StoredMessage message) {
    if (!_draining && _channelCallbackRecord != nullptr) {
        assert(_queue->isEmpty());
        _channelCallbackRecord!->invoke(message->data, message->invoke);
        return false;
    }
    if (_capacity <= 0) {
        return debugEnableDiscardWarnings;
    }
    bool result = _dropOverflowMessages(_capacity - 1);
    _queue->addLast(message);
    return result;
}

_StoredMessage _ChannelCls::pop() {
    return _queue->removeFirst();
}

void _ChannelCls::setListener(ChannelCallback callback) {
    bool needDrain = _channelCallbackRecord == nullptr;
    _channelCallbackRecord = make<_ChannelCallbackRecordCls>(callback);
    if (needDrain && !_draining) {
        _drain();
    }
}

void _ChannelCls::clearListener() {
    _channelCallbackRecord = nullptr;
}

_ChannelCls::_ChannelCls(int _capacity) {
    {
        _queue = collection-><_StoredMessage>make<ListQueueCls>(_capacity);
    }
}

bool _ChannelCls::_dropOverflowMessages(int lengthLimit) {
    bool result = false;
    while (_queue->length() > lengthLimit) {
        _StoredMessage message = _queue->removeFirst();
        message->invoke(nullptr);
        result = true;
    }
    return result;
}

void _ChannelCls::_drain() {
    assert(!_draining);
    _draining = true;
    scheduleMicrotask(_drainStep);
}

void _ChannelCls::_drainStep() {
    assert(_draining);
    if (_queue->isNotEmpty() && _channelCallbackRecord != nullptr) {
        _StoredMessage message = pop();
        _channelCallbackRecord!->invoke(message->data, message->invoke);
        scheduleMicrotask(_drainStep);
    } else {
        _draining = false;
    }
}

void ChannelBuffersCls::push(String name, ByteData data, PlatformMessageResponseCallback callback) {
    _Channel channel = _channels->putIfAbsent(name, [=] () {
    make<_ChannelCls>();
});
    if (channel->push(make<_StoredMessageCls>(data, callback))) {
        _printDebug(__sf("A message on the %s channel was discarded before it could be handled.\nThis happens when a plugin sends messages to the framework side before the framework has had an opportunity to register a listener. See the ChannelBuffers API documentation for details on how to configure the channel to expect more messages, or to expect messages to get discarded:\n  https://api.flutter.dev/flutter/dart-ui/ChannelBuffers-class.html", name));
    }
}

void ChannelBuffersCls::setListener(String name, ChannelCallback callback) {
    _Channel channel = _channels->putIfAbsent(name, [=] () {
    make<_ChannelCls>();
});
    channel->setListener(callback);
}

void ChannelBuffersCls::clearListener(String name) {
    _Channel channel = _channels[name];
    if (channel != nullptr) {
        channel->clearListener();
    }
}

Future<void> ChannelBuffersCls::drain(String name, DrainChannelCallback callback) {
    _Channel channel = _channels[name];
    while (channel != nullptr && !channel->_queue->isEmpty()) {
        _StoredMessage message = channel->pop();
        await await callback(message->data, message->invoke);
    }
}

void ChannelBuffersCls::handleMessage(ByteData data) {
    Uint8List bytes = data->buffer()->asUint8List(data->offsetInBytes(), data->lengthInBytes());
    if (bytes[0] == 0x07) {
        int methodNameLength = bytes[1];
        if (methodNameLength >= 254) {
            throw make<ExceptionCls>(__sf("Unrecognized message sent to %s (method name too long)", kControlChannelName));
        }
        int index = 2;
        String methodName = utf8->decode(bytes->sublist(index, index + methodNameLength));
        index += methodNameLength;
        ;
    } else {
        List<String> parts = utf8->decode(bytes)->split(__s("\r"));
        if (parts->length() == 1 + 2 && parts[0] == __s("resize")) {
            resize(parts[1], intValue->parse(parts[2]));
        } else {
            throw make<ExceptionCls>(__sf("Unrecognized message %s sent to %s.", parts, kControlChannelName));
        }
    }
}

void ChannelBuffersCls::resize(String name, int newSize) {
    _Channel channel = _channels[name];
    if (channel == nullptr) {
        channel = make<_ChannelCls>(newSize);
        _channels[name] = channel;
    } else {
        channel->capacity() = newSize;
    }
}

void ChannelBuffersCls::allowOverflow(String name, bool allowed) {
    assert([=] () {
        _Channel channel = _channels[name];
        if (channel == nullptr && allowed) {
            channel = make<_ChannelCls>();
            _channels[name] = channel;
        }
        channel?->debugEnableDiscardWarnings = !allowed;
        return true;
    }());
}
