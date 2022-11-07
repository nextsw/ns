#include "platform_channel.hpp"
Future<void> _ProfiledBinaryMessenger::handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData data) {
    return proxy.handlePlatformMessage(channel, data, callback);
}

Future<ByteData> _ProfiledBinaryMessenger::sendWithPostfix(String channel, ByteData message, String postfix) {
    TimelineTask task = TimelineTask();
    _debugRecordUpStream(channelTypeName, "$channel$postfix", codecTypeName, message);
    task.start("Platform Channel send $channel$postfix");
    ByteData result;
    ;
    _debugRecordDownStream(channelTypeName, "$channel$postfix", codecTypeName, result);
    return result;
}

Future<ByteData> _ProfiledBinaryMessenger::send(String channel, ByteData message) {
    return sendWithPostfix(channel, "", message);
}

void _ProfiledBinaryMessenger::setMessageHandler(String channel, MessageHandler handler) {
    proxy.setMessageHandler(channel, handler);
}

int _PlatformChannelStats::upBytes() {
    return _upBytes;
}

void _PlatformChannelStats::addUpStream(int bytes) {
    _upCount = 1;
    _upBytes = bytes;
}

int _PlatformChannelStats::downBytes() {
    return _downBytes;
}

void _PlatformChannelStats::addDownStream(int bytes) {
    _downCount = 1;
    _downBytes = bytes;
}

double _PlatformChannelStats::averageUpPayload() {
    return _upBytes / _upCount;
}

double _PlatformChannelStats::averageDownPayload() {
    return _downBytes / _downCount;
}

Future<void> _debugLaunchProfilePlatformChannels() {
    if (!_debugProfilePlatformChannelsIsRunning) {
        _debugProfilePlatformChannelsIsRunning = true;
        await await <dynamic>delayed(_debugProfilePlatformChannelsRate);
        _debugProfilePlatformChannelsIsRunning = false;
        StringBuffer log = StringBuffer();
        log.writeln("Platform Channel Stats:");
        List<_PlatformChannelStats> allStats = _debugProfilePlatformChannelsStats.values.toList();
        allStats.sort();
        for (_PlatformChannelStats stats : allStats) {
            log.writeln("  (name:"${stats.channel}" type:"${stats.type}" codec:"${stats.codec}" upBytes:${stats.upBytes} upBytes_avg:${stats.averageUpPayload.toStringAsFixed(1)} downBytes:${stats.downBytes} downBytes_avg:${stats.averageDownPayload.toStringAsFixed(1)})");
        }
        debugPrint(log.toString());
        _debugProfilePlatformChannelsStats.clear();
    }
}

void _debugRecordUpStream(ByteData bytes, String channelTypeName, String codecTypeName, String name) {
    _PlatformChannelStats stats = _debugProfilePlatformChannelsStats[name] ??= _PlatformChannelStats(name, codecTypeName, channelTypeName);
    stats.addUpStream(bytes?.lengthInBytes ?? 0);
    _debugLaunchProfilePlatformChannels();
}

void _debugRecordDownStream(ByteData bytes, String channelTypeName, String codecTypeName, String name) {
    _PlatformChannelStats stats = _debugProfilePlatformChannelsStats[name] ??= _PlatformChannelStats(name, codecTypeName, channelTypeName);
    stats.addDownStream(bytes?.lengthInBytes ?? 0);
    _debugLaunchProfilePlatformChannels();
}

BasicMessageChannel::BasicMessageChannel(BinaryMessenger binaryMessenger, MessageCodec<T> codec, String name) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger;
    }
}

BinaryMessenger BasicMessageChannel::binaryMessenger() {
    BinaryMessenger result = _binaryMessenger ?? ServicesBinding.instance.defaultBinaryMessenger;
    return !kReleaseMode && debugProfilePlatformChannels? _debugBinaryMessengers[this] ??= _ProfiledBinaryMessenger(result, runtimeType.toString(), codec.runtimeType.toString()) : result;
}

Future<T> BasicMessageChannel::send(T message) {
    return codec.decodeMessage(await binaryMessenger.send(name, codec.encodeMessage(message)));
}

void BasicMessageChannel::setMessageHandler(FunctionType handler) {
    if (handler == nullptr) {
        binaryMessenger.setMessageHandler(name, nullptr);
    } else {
        binaryMessenger.setMessageHandler(name, );
    }
}

MethodChannel::MethodChannel(BinaryMessenger binaryMessenger, MethodCodec codec, String name) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger;
    }
}

BinaryMessenger MethodChannel::binaryMessenger() {
    BinaryMessenger result = _binaryMessenger ?? ServicesBinding.instance.defaultBinaryMessenger;
    return !kReleaseMode && debugProfilePlatformChannels? _debugBinaryMessengers[this] ??= _ProfiledBinaryMessenger(result, runtimeType.toString(), codec.runtimeType.toString()) : result;
}

Future<T> MethodChannel::invokeMethod<T>(dynamic arguments, String method) {
    return <T>_invokeMethod(methodfalse, arguments);
}

Future<List<T>> MethodChannel::invokeListMethod<T>(dynamic arguments, String method) {
    List<dynamic> result = await <List<dynamic>>invokeMethod(method, arguments);
    return result?.<T>cast();
}

Future<Map<K, V>> MethodChannel::invokeMapMethod<K, V>(dynamic arguments, String method) {
    Map<dynamic, dynamic> result = await <Map<dynamic, dynamic>>invokeMethod(method, arguments);
    return result?.<K, V>cast();
}

void MethodChannel::setMethodCallHandler(FunctionType handler) {
    assert(_binaryMessenger != nullptr || ServicesBinding.instance != nullptr, "Cannot set the method call handler before the binary messenger has been initialized. This happens when you call setMethodCallHandler() before the WidgetsFlutterBinding has been initialized. You can fix this by either calling WidgetsFlutterBinding.ensureInitialized() before this or by passing a custom BinaryMessenger instance to MethodChannel().");
    binaryMessenger.setMessageHandler(name, handler == nullptr? nullptr : );
}

Future<T> MethodChannel::_invokeMethod<T>(dynamic arguments, String method, bool missingOk) {
    assert(method != nullptr);
    ByteData input = codec.encodeMethodCall(MethodCall(method, arguments));
    ByteData result = !kReleaseMode && debugProfilePlatformChannels? await (().sendWithPostfix(name, "#$method", input) : await binaryMessenger.send(name, input);
    if (result == nullptr) {
        if (missingOk) {
            return nullptr;
        }
        ;
    }
    return (;
}

Future<ByteData> MethodChannel::_handleAsMethodCall(FunctionType handler, ByteData message) {
    MethodCall call = codec.decodeMethodCall(message);
    ;
}

Future<T> OptionalMethodChannel::invokeMethod<T>(dynamic arguments, String method) {
    return super.<T>_invokeMethod(methodtrue, arguments);
}

EventChannel::EventChannel(BinaryMessenger binaryMessenger, MethodCodec codec, String name) {
    {
        assert(name != nullptr);
        assert(codec != nullptr);
        _binaryMessenger = binaryMessenger;
    }
}

BinaryMessenger EventChannel::binaryMessenger() {
    return _binaryMessenger ?? ServicesBinding.instance.defaultBinaryMessenger;
}

Stream<dynamic> EventChannel::receiveBroadcastStream(dynamic arguments) {
    MethodChannel methodChannel = MethodChannel(name, codec);
    StreamController<dynamic> controller;
    controller = <dynamic>broadcast(, );
    return controller.stream;
}
