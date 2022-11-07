#ifndef PLATFORM_CHANNEL_H
#define PLATFORM_CHANNEL_H
#include <memory>
#include "binary_messenger.hpp"
#include "message_codec.hpp"

#include <async/async.hpp>
#include <developer/developer.hpp>
#include <flutter/foundation.hpp>
#include "binary_messenger.hpp"
#include "binding.hpp"
#include "debug.hpp"
#include "message_codec.hpp"
#include "message_codecs.hpp"


bool _debugProfilePlatformChannelsIsRunning;

const Duration _debugProfilePlatformChannelsRate;

Expando<BinaryMessenger> _debugBinaryMessengers;


class _ProfiledBinaryMessenger {
public:
    BinaryMessenger proxy;

    String channelTypeName;

    String codecTypeName;


    Future<void> handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData data);

    Future<ByteData> sendWithPostfix(String channel, ByteData message, String postfix);

    Future<ByteData> send(String channel, ByteData message);

    void setMessageHandler(String channel, MessageHandler handler);

private:

     _ProfiledBinaryMessenger(String channelTypeName, String codecTypeName, BinaryMessenger proxy);

};

class _PlatformChannelStats {
public:
    String channel;

    String codec;

    String type;


    int upBytes();

    void addUpStream(int bytes);

    int downBytes();

    void addDownStream(int bytes);

    double averageUpPayload();

    double averageDownPayload();

private:
    int _upCount;

    int _upBytes;

    int _downCount;

    int _downBytes;


     _PlatformChannelStats(String channel, String codec, String type);

};
Map<String, _PlatformChannelStats> _debugProfilePlatformChannelsStats;

Future<void> _debugLaunchProfilePlatformChannels();

void _debugRecordUpStream(ByteData bytes, String channelTypeName, String codecTypeName, String name);

void _debugRecordDownStream(ByteData bytes, String channelTypeName, String codecTypeName, String name);


class BasicMessageChannel<T> {
public:
    String name;

    MessageCodec<T> codec;


     BasicMessageChannel(BinaryMessenger binaryMessenger, MessageCodec<T> codec, String name);

    BinaryMessenger binaryMessenger();

    Future<T> send(T message);

    void setMessageHandler(FunctionType handler);

private:
    BinaryMessenger _binaryMessenger;


};

class MethodChannel {
public:
    String name;

    MethodCodec codec;


     MethodChannel(BinaryMessenger binaryMessenger, MethodCodec codec, String name);

    BinaryMessenger binaryMessenger();

    Future<T> invokeMethod<T>(dynamic arguments, String method);

    Future<List<T>> invokeListMethod<T>(dynamic arguments, String method);

    Future<Map<K, V>> invokeMapMethod<K, V>(dynamic arguments, String method);

    void setMethodCallHandler(FunctionType handler);

private:
    BinaryMessenger _binaryMessenger;


    Future<T> _invokeMethod<T>(dynamic arguments, String method, bool missingOk);

    Future<ByteData> _handleAsMethodCall(FunctionType handler, ByteData message);

};

class OptionalMethodChannel : MethodChannel {
public:

     OptionalMethodChannel(Unknown, Unknown, Unknown);

    Future<T> invokeMethod<T>(dynamic arguments, String method);

private:

};

class EventChannel {
public:
    String name;

    MethodCodec codec;


     EventChannel(BinaryMessenger binaryMessenger, MethodCodec codec, String name);

    BinaryMessenger binaryMessenger();

    Stream<dynamic> receiveBroadcastStream(dynamic arguments);

private:
    BinaryMessenger _binaryMessenger;


};

#endif