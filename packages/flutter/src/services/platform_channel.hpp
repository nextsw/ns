#ifndef PACKAGES_FLUTTER_SRC_SERVICES_PLATFORM_CHANNEL
#define PACKAGES_FLUTTER_SRC_SERVICES_PLATFORM_CHANNEL
#include <base.hpp>
#include "binary_messenger.hpp"
#include "message_codec.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/developer/developer.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "binary_messenger.hpp"
#include "binding.hpp"
#include "debug.hpp"
#include "message_codec.hpp"
#include "message_codecs.hpp"

bool _debugProfilePlatformChannelsIsRunning;

Duration _debugProfilePlatformChannelsRate;

Expando<BinaryMessenger> _debugBinaryMessengers;


class _ProfiledBinaryMessengerCls : public ObjectCls {
public:
    BinaryMessenger proxy;

    String channelTypeName;

    String codecTypeName;


    virtual Future<void> handlePlatformMessage(String channel, ByteData data, PlatformMessageResponseCallback callback);

    virtual Future<ByteData> sendWithPostfix(String channel, String postfix, ByteData message);

    virtual Future<ByteData> send(String channel, ByteData message);

    virtual void setMessageHandler(String channel, MessageHandler handler);

private:

     _ProfiledBinaryMessengerCls(BinaryMessenger proxy, String channelTypeName, String codecTypeName);
};
using _ProfiledBinaryMessenger = std::shared_ptr<_ProfiledBinaryMessengerCls>;

class _PlatformChannelStatsCls : public ObjectCls {
public:
    String channel;

    String codec;

    String type;


    virtual int upBytes();

    virtual void addUpStream(int bytes);

    virtual int downBytes();

    virtual void addDownStream(int bytes);

    virtual double averageUpPayload();

    virtual double averageDownPayload();

private:
    int _upCount;

    int _upBytes;

    int _downCount;

    int _downBytes;


     _PlatformChannelStatsCls(String channel, String codec, String type);
};
using _PlatformChannelStats = std::shared_ptr<_PlatformChannelStatsCls>;
Map<String, _PlatformChannelStats> _debugProfilePlatformChannelsStats;

Future<void> _debugLaunchProfilePlatformChannels();

void _debugRecordUpStream(String channelTypeName, String name, String codecTypeName, ByteData bytes);

void _debugRecordDownStream(String channelTypeName, String name, String codecTypeName, ByteData bytes);


template<typename T>
class BasicMessageChannelCls : public ObjectCls {
public:
    String name;

    MessageCodec<T> codec;


     BasicMessageChannelCls(String name, MessageCodec<T> codec, BinaryMessenger binaryMessenger);

    virtual BinaryMessenger binaryMessenger();

    virtual Future<T> send(T message);

    virtual void setMessageHandler(std::function<Future<T>(T message)> handler);

private:
    BinaryMessenger _binaryMessenger;


};
template<typename T>
using BasicMessageChannel = std::shared_ptr<BasicMessageChannelCls<T>>;

class MethodChannelCls : public ObjectCls {
public:
    String name;

    MethodCodec codec;


     MethodChannelCls(String name, MethodCodec codec, BinaryMessenger binaryMessenger);

    virtual BinaryMessenger binaryMessenger();

    template<typename T>
 virtual Future<T> invokeMethod(String method, dynamic arguments);

    template<typename T>
 virtual Future<List<T>> invokeListMethod(String method, dynamic arguments);

    template<typename K, typename V>
 virtual Future<Map<K, V>> invokeMapMethod(String method, dynamic arguments);

    virtual void setMethodCallHandler(std::function<Future<dynamic>(MethodCall call)> handler);

private:
    BinaryMessenger _binaryMessenger;


    template<typename T>
 virtual Future<T> _invokeMethod(String method, dynamic arguments, bool missingOk);

    virtual Future<ByteData> _handleAsMethodCall(ByteData message, std::function<Future<dynamic>(MethodCall call)> handler);

};
using MethodChannel = std::shared_ptr<MethodChannelCls>;

class OptionalMethodChannelCls : public MethodChannelCls {
public:

     OptionalMethodChannelCls(String name, MethodCodec codec, Unknown binaryMessenger);
    template<typename T>
 virtual Future<T> invokeMethod(String method, dynamic arguments);

private:

};
using OptionalMethodChannel = std::shared_ptr<OptionalMethodChannelCls>;

class EventChannelCls : public ObjectCls {
public:
    String name;

    MethodCodec codec;


     EventChannelCls(String name, MethodCodec codec, BinaryMessenger binaryMessenger);

    virtual BinaryMessenger binaryMessenger();

    virtual Stream<dynamic> receiveBroadcastStream(dynamic arguments);

private:
    BinaryMessenger _binaryMessenger;


};
using EventChannel = std::shared_ptr<EventChannelCls>;


#endif