#include "platform_channel.hpp"
Future<void> _ProfiledBinaryMessengerCls::handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData data) {
    return proxy->handlePlatformMessage(channel, data, callback);
}

Future<ByteData> _ProfiledBinaryMessengerCls::sendWithPostfix(String channel, ByteData message, String postfix) {
    TimelineTask task = make<TimelineTaskCls>();
    _debugRecordUpStream(channelTypeName, __s("$channel$postfix"), codecTypeName, message);
    task->start(__s("Platform Channel send $channel$postfix"));
    ByteData result;
    try {
        result = await proxy->send(channel, message);
    } finally {
        task->finish();
    };
    _debugRecordDownStream(channelTypeName, __s("$channel$postfix"), codecTypeName, result);
    return result;
}

Future<ByteData> _ProfiledBinaryMessengerCls::send(String channel, ByteData message) {
    return sendWithPostfix(channel, __s(""), message);
}

void _ProfiledBinaryMessengerCls::setMessageHandler(String channel, MessageHandler handler) {
    proxy->setMessageHandler(channel, handler);
}

int _PlatformChannelStatsCls::upBytes() {
    return _upBytes;
}

void _PlatformChannelStatsCls::addUpStream(int bytes) {
    _upCount = 1;
    _upBytes = bytes;
}

int _PlatformChannelStatsCls::downBytes() {
    return _downBytes;
}

void _PlatformChannelStatsCls::addDownStream(int bytes) {
    _downCount = 1;
    _downBytes = bytes;
}

double _PlatformChannelStatsCls::averageUpPayload() {
    return _upBytes / _upCount;
}

double _PlatformChannelStatsCls::averageDownPayload() {
    return _downBytes / _downCount;
}

Future<void> _debugLaunchProfilePlatformChannels() {
    if (!_debugProfilePlatformChannelsIsRunning) {
        _debugProfilePlatformChannelsIsRunning = true;
        await await <dynamic>delayed(_debugProfilePlatformChannelsRate);
        _debugProfilePlatformChannelsIsRunning = false;
        StringBuffer log = make<StringBufferCls>();
        log->writeln(__s("Platform Channel Stats:"));
        List<_PlatformChannelStats> allStats = _debugProfilePlatformChannelsStats->values->toList();
        allStats->sort([=] (_PlatformChannelStats x,_PlatformChannelStats y)         {
            (y->upBytes + y->downBytes) - (x->upBytes + x->downBytes);
        });
        for (_PlatformChannelStats stats : allStats) {
            log->writeln(__s("  (name:"${stats.channel}" type:"${stats.type}" codec:"${stats.codec}" upBytes:${stats.upBytes} upBytes_avg:${stats.averageUpPayload.toStringAsFixed(1)} downBytes:${stats.downBytes} downBytes_avg:${stats.averageDownPayload.toStringAsFixed(1)})"));
        }
        debugPrint(log->toString());
        _debugProfilePlatformChannelsStats->clear();
    }
}

void _debugRecordUpStream(ByteData bytes, String channelTypeName, String codecTypeName, String name) {
    _PlatformChannelStats stats = _debugProfilePlatformChannelsStats[name] ??= make<_PlatformChannelStatsCls>(name, codecTypeName, channelTypeName);
    stats->addUpStream(bytes?->lengthInBytes or 0);
    _debugLaunchProfilePlatformChannels();
}

void _debugRecordDownStream(ByteData bytes, String channelTypeName, String codecTypeName, String name) {
    _PlatformChannelStats stats = _debugProfilePlatformChannelsStats[name] ??= make<_PlatformChannelStatsCls>(name, codecTypeName, channelTypeName);
    stats->addDownStream(bytes?->lengthInBytes or 0);
    _debugLaunchProfilePlatformChannels();
}

template<typename T> BasicMessageChannelCls<T>::BasicMessageChannelCls(BinaryMessenger binaryMessenger, MessageCodec<T> codec, String name) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger();
    }
}

template<typename T> BinaryMessenger BasicMessageChannelCls<T>::binaryMessenger() {
    BinaryMessenger result = _binaryMessenger or ServicesBindingCls::instance->defaultBinaryMessenger;
    return !kReleaseMode && debugProfilePlatformChannels? _debugBinaryMessengers[this] ??= make<_ProfiledBinaryMessengerCls>(result, runtimeType->toString(), codec->runtimeType->toString()) : result;
}

template<typename T> Future<T> BasicMessageChannelCls<T>::send(T message) {
    return codec->decodeMessage(await binaryMessenger()->send(name, codec->encodeMessage(message)));
}

template<typename T> void BasicMessageChannelCls<T>::setMessageHandler(Future<T> handler(T message) ) {
    if (handler == nullptr) {
        binaryMessenger()->setMessageHandler(name, nullptr);
    } else {
        binaryMessenger()->setMessageHandler(name, [=] (ByteData message) {
            return codec->encodeMessage(await handler(codec->decodeMessage(message)));
        });
    }
}

MethodChannelCls::MethodChannelCls(BinaryMessenger binaryMessenger, MethodCodec codec, String name) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger();
    }
}

BinaryMessenger MethodChannelCls::binaryMessenger() {
    BinaryMessenger result = _binaryMessenger or ServicesBindingCls::instance->defaultBinaryMessenger;
    return !kReleaseMode && debugProfilePlatformChannels? _debugBinaryMessengers[this] ??= make<_ProfiledBinaryMessengerCls>(result, runtimeType->toString(), codec->runtimeType->toString()) : result;
}

Future<T> MethodChannelCls::invokeMethodtemplate<typename T> (dynamic arguments, String method) {
    return <T>_invokeMethod(methodfalse, arguments);
}

Future<List<T>> MethodChannelCls::invokeListMethodtemplate<typename T> (dynamic arguments, String method) {
    List<dynamic> result = await <List<dynamic>>invokeMethod(method, arguments);
    return result?-><T>cast();
}

Future<Map<K, V>> MethodChannelCls::invokeMapMethodtemplate<typename K, typename V> (dynamic arguments, String method) {
    Map<dynamic, dynamic> result = await <Map<dynamic, dynamic>>invokeMethod(method, arguments);
    return result?-><K, V>cast();
}

void MethodChannelCls::setMethodCallHandler(Future<dynamic> handler(MethodCall call) ) {
    assert(_binaryMessenger != nullptr || ServicesBindingCls::instance != nullptr, __s("Cannot set the method call handler before the binary messenger has been initialized. This happens when you call setMethodCallHandler() before the WidgetsFlutterBinding has been initialized. You can fix this by either calling WidgetsFlutterBinding.ensureInitialized() before this or by passing a custom BinaryMessenger instance to MethodChannel()."));
    binaryMessenger()->setMessageHandler(name, handler == nullptr? nullptr : [=] (ByteData message)     {
        _handleAsMethodCall(message, handler);
    });
}

Future<T> MethodChannelCls::_invokeMethodtemplate<typename T> (dynamic arguments, String method, bool missingOk) {
    assert(method != nullptr);
    ByteData input = codec->encodeMethodCall(make<MethodCallCls>(method, arguments));
    ByteData result = !kReleaseMode && debugProfilePlatformChannels? await (as<_ProfiledBinaryMessenger>(binaryMessenger()))->sendWithPostfix(name, __s("#$method"), input) : await binaryMessenger()->send(name, input);
    if (result == nullptr) {
        if (missingOk) {
            return nullptr;
        }
        ;
    }
    return as<T>(codec->decodeEnvelope(result));
}

Future<ByteData> MethodChannelCls::_handleAsMethodCall(Future<dynamic> handler(MethodCall call) , ByteData message) {
    MethodCall call = codec->decodeMethodCall(message);
    try {
        return codec->encodeSuccessEnvelope(await handler(call));
    } catch (PlatformException e) {
        return codec->encodeErrorEnvelope(e->code, e->message, e->details);
    } catch (MissingPluginException null) {
        return nullptr;
    } catch (Unknown error) {
        return codec->encodeErrorEnvelope(__s("error"), error->toString());
    };
}

Future<T> OptionalMethodChannelCls::invokeMethodtemplate<typename T> (dynamic arguments, String method) {
    return super-><T>_invokeMethod(methodtrue, arguments);
}

EventChannelCls::EventChannelCls(BinaryMessenger binaryMessenger, MethodCodec codec, String name) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger();
    }
}

BinaryMessenger EventChannelCls::binaryMessenger() {
    return _binaryMessenger or ServicesBindingCls::instance->defaultBinaryMessenger;
}

Stream<dynamic> EventChannelCls::receiveBroadcastStream(dynamic arguments) {
    MethodChannel methodChannel = make<MethodChannelCls>(name, codec);
    StreamController<dynamic> controller;
    controller = <dynamic>broadcast([=] () {
        binaryMessenger()->setMessageHandler(name, [=] (ByteData reply) {
            if (reply == nullptr) {
                controller->close();
            } else {
                try {
                    controller->add(codec->decodeEnvelope(reply));
                } catch (PlatformException e) {
                    controller->addError(e);
                };
            }
            return nullptr;
        });
        try {
            await await methodChannel-><void>invokeMethod(__s("listen"), arguments);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__s("while activating platform stream on channel $name"))));
        };
    }, [=] () {
        binaryMessenger()->setMessageHandler(name, nullptr);
        try {
            await await methodChannel-><void>invokeMethod(__s("cancel"), arguments);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__s("while de-activating platform stream on channel $name"))));
        };
    });
    return controller->stream;
}
