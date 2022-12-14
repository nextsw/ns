#include "platform_channel.hpp"
Future<void> _ProfiledBinaryMessengerCls::handlePlatformMessage(String channel, ByteData data, PlatformMessageResponseCallback callback) {
    return proxy->handlePlatformMessage(channel, data, callback);
}

Future<ByteData> _ProfiledBinaryMessengerCls::sendWithPostfix(String channel, String postfix, ByteData message) {
    TimelineTask task = make<TimelineTaskCls>();
    _debugRecordUpStream(channelTypeName, __sf("%s%s", channel, postfix), codecTypeName, message);
    task->start(__sf("Platform Channel send %s%s", channel, postfix));
    ByteData result;
    try {
        result = await proxy->send(channel, message);
    } finally {
        task->finish();
    };
    _debugRecordDownStream(channelTypeName, __sf("%s%s", channel, postfix), codecTypeName, result);
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
    _upCount += 1;
    _upBytes += bytes;
}

int _PlatformChannelStatsCls::downBytes() {
    return _downBytes;
}

void _PlatformChannelStatsCls::addDownStream(int bytes) {
    _downCount += 1;
    _downBytes += bytes;
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
        await <Object>delayed(_debugProfilePlatformChannelsRate);
        _debugProfilePlatformChannelsIsRunning = false;
        StringBuffer log = make<StringBufferCls>();
        log->writeln(__s("Platform Channel Stats:"));
        List<_PlatformChannelStats> allStats = _debugProfilePlatformChannelsStats->values->toList();
        allStats->sort([=] (_PlatformChannelStats x,_PlatformChannelStats y) {
            (y->upBytes + y->downBytes) - (x->upBytes + x->downBytes);
        });
        for (_PlatformChannelStats stats : allStats) {
            log->writeln(__sf("  (name:"%s" type:"%s" codec:"%s" upBytes:%s upBytes_avg:%s downBytes:%s downBytes_avg:%s)", stats->channel, stats->type, stats->codec, stats->upBytes, stats->averageUpPayload->toStringAsFixed(1), stats->downBytes, stats->averageDownPayload->toStringAsFixed(1)));
        }
        debugPrint(log->toString());
        _debugProfilePlatformChannelsStats->clear();
    }
}

void _debugRecordUpStream(String channelTypeName, String name, String codecTypeName, ByteData bytes) {
    _PlatformChannelStats stats = _debugProfilePlatformChannelsStats[name] ??= make<_PlatformChannelStatsCls>(name, codecTypeName, channelTypeName);
    stats->addUpStream(bytes?->lengthInBytes() | 0);
    _debugLaunchProfilePlatformChannels();
}

void _debugRecordDownStream(String channelTypeName, String name, String codecTypeName, ByteData bytes) {
    _PlatformChannelStats stats = _debugProfilePlatformChannelsStats[name] ??= make<_PlatformChannelStatsCls>(name, codecTypeName, channelTypeName);
    stats->addDownStream(bytes?->lengthInBytes() | 0);
    _debugLaunchProfilePlatformChannels();
}

template<typename T>
BasicMessageChannelCls<T>::BasicMessageChannelCls(String name, MessageCodec<T> codec, BinaryMessenger binaryMessenger) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger;
    }
}

template<typename T>
BinaryMessenger BasicMessageChannelCls<T>::binaryMessenger() {
    BinaryMessenger result = _binaryMessenger | ServicesBindingCls::instance->defaultBinaryMessenger;
    return !kReleaseMode && debugProfilePlatformChannels? _debugBinaryMessengers[this] ??= make<_ProfiledBinaryMessengerCls>(result, runtimeType->toString(), codec->runtimeType->toString()) : result;
}

template<typename T>
Future<T> BasicMessageChannelCls<T>::send(T message) {
    return codec->decodeMessage(await binaryMessenger()->send(name, codec->encodeMessage(message)));
}

template<typename T>
void BasicMessageChannelCls<T>::setMessageHandler(std::function<Future<T>(T message)> handler) {
    if (handler == nullptr) {
        binaryMessenger()->setMessageHandler(name, nullptr);
    } else {
        binaryMessenger()->setMessageHandler(name, [=] (ByteData message) {
            return codec->encodeMessage(await handler(codec->decodeMessage(message)));
        });
    }
}

MethodChannelCls::MethodChannelCls(String name, MethodCodec codec, BinaryMessenger binaryMessenger) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger;
    }
}

BinaryMessenger MethodChannelCls::binaryMessenger() {
    BinaryMessenger result = _binaryMessenger | ServicesBindingCls::instance->defaultBinaryMessenger;
    return !kReleaseMode && debugProfilePlatformChannels? _debugBinaryMessengers[this] ??= make<_ProfiledBinaryMessengerCls>(result, runtimeType->toString(), codec->runtimeType->toString()) : result;
}

template<typename T>
Future<T> MethodChannelCls::invokeMethod(String method, Object arguments) {
    return <T>_invokeMethod(method, false, arguments);
}

template<typename T>
Future<List<T>> MethodChannelCls::invokeListMethod(String method, Object arguments) {
    List<Object> result = await <List<Object>>invokeMethod(method, arguments);
    return result?-><T>cast();
}

template<typename K, typename V>
Future<Map<K, V>> MethodChannelCls::invokeMapMethod(String method, Object arguments) {
    Map<Object, Object> result = await <Map<Object, Object>>invokeMethod(method, arguments);
    return result?-><K, V>cast();
}

void MethodChannelCls::setMethodCallHandler(std::function<Future<Object>(MethodCall call)> handler) {
    assert(_binaryMessenger != nullptr || ServicesBindingCls::instance != nullptr, __s("Cannot set the method call handler before the binary messenger has been initialized. This happens when you call setMethodCallHandler() before the WidgetsFlutterBinding has been initialized. You can fix this by either calling WidgetsFlutterBinding.ensureInitialized() before this or by passing a custom BinaryMessenger instance to MethodChannel()."));
    binaryMessenger()->setMessageHandler(name, handler == nullptr? nullptr : [=] (ByteData message) {
        _handleAsMethodCall(message, handler);
    });
}

template<typename T>
Future<T> MethodChannelCls::_invokeMethod(String method, Object arguments, bool missingOk) {
    assert(method != nullptr);
    ByteData input = codec->encodeMethodCall(make<MethodCallCls>(method, arguments));
    ByteData result = !kReleaseMode && debugProfilePlatformChannels? await (as<_ProfiledBinaryMessenger>(binaryMessenger()))->sendWithPostfix(name, __sf("#%s", method), input) : await binaryMessenger()->send(name, input);
    if (result == nullptr) {
        if (missingOk) {
            return nullptr;
        }
        throw make<MissingPluginExceptionCls>(__sf("No implementation found for method %s on channel %s", method, name));
    }
    return as<T>(codec->decodeEnvelope(result));
}

Future<ByteData> MethodChannelCls::_handleAsMethodCall(ByteData message, std::function<Future<Object>(MethodCall call)> handler) {
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

template<typename T>
Future<T> OptionalMethodChannelCls::invokeMethod(String method, Object arguments) {
    return super-><T>_invokeMethod(method, true, arguments);
}

EventChannelCls::EventChannelCls(String name, MethodCodec codec, BinaryMessenger binaryMessenger) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger;
    }
}

BinaryMessenger EventChannelCls::binaryMessenger() {
    return _binaryMessenger | ServicesBindingCls::instance->defaultBinaryMessenger;
}

Stream<Object> EventChannelCls::receiveBroadcastStream(Object arguments) {
    MethodChannel methodChannel = make<MethodChannelCls>(name, codec);
    StreamController<Object> controller;
    controller = <Object>broadcast([=] () {
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
            await methodChannel-><void>invokeMethod(__s("listen"), arguments);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__sf("while activating platform stream on channel %s", name))));
        };
    }, [=] () {
        binaryMessenger()->setMessageHandler(name, nullptr);
        try {
            await methodChannel-><void>invokeMethod(__s("cancel"), arguments);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("services library"), make<ErrorDescriptionCls>(__sf("while de-activating platform stream on channel %s", name))));
        };
    });
    return controller->stream();
}
