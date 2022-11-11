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


    virtual Future<void> handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData data);

    virtual Future<ByteData> sendWithPostfix(String channel, ByteData message, String postfix);

    virtual Future<ByteData> send(String channel, ByteData message);

    virtual void setMessageHandler(String channel, MessageHandler handler);

private:

     _ProfiledBinaryMessengerCls(String channelTypeName, String codecTypeName, BinaryMessenger proxy);
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

void _debugRecordUpStream(ByteData bytes, String channelTypeName, String codecTypeName, String name);

void _debugRecordDownStream(ByteData bytes, String channelTypeName, String codecTypeName, String name);


template<typename T>
class BasicMessageChannelCls : public ObjectCls {
public:
    String name;

    MessageCodec<T> codec;


     BasicMessageChannelCls(BinaryMessenger binaryMessenger, MessageCodec<T> codec, String name);

    virtual BinaryMessenger binaryMessenger();

    virtual Future<T> send(T message);

    virtual void setMessageHandler(Future<T> handler(T message) );

private:
    BinaryMessenger _binaryMessenger;


};
template<typename T>
using BasicMessageChannel = std::shared_ptr<BasicMessageChannelCls<T>>;

class MethodChannelCls : public ObjectCls {
public:
    String name;

    MethodCodec codec;


     MethodChannelCls(BinaryMessenger binaryMessenger, MethodCodec codec, String name);

    virtual BinaryMessenger binaryMessenger();

    template<typename T>
 virtual Future<T> invokeMethod(dynamic arguments, String method);

    template<typename T>
 virtual Future<List<T>> invokeListMethod(dynamic arguments, String method);

    template<typename K, typename V>
 virtual Future<Map<K, V>> invokeMapMethod(dynamic arguments, String method);

    virtual void setMethodCallHandler(Future<dynamic> handler(MethodCall call) );

private:
    BinaryMessenger _binaryMessenger;


    template<typename T>
 virtual Future<T> _invokeMethod(dynamic arguments, String method, bool missingOk);

    virtual Future<ByteData> _handleAsMethodCall(Future<dynamic> handler(MethodCall call) , ByteData message);

};
using MethodChannel = std::shared_ptr<MethodChannelCls>;

class OptionalMethodChannelCls : public MethodChannelCls {
public:

     OptionalMethodChannelCls(Unknown binaryMessenger, Unknown codec, Unknown name);
    template<typename T>
 virtual Future<T> invokeMethod(dynamic arguments, String method);

private:

};
using OptionalMethodChannel = std::shared_ptr<OptionalMethodChannelCls>;

class EventChannelCls : public ObjectCls {
public:
    String name;

    MethodCodec codec;


     EventChannelCls(BinaryMessenger binaryMessenger, MethodCodec codec, String name);

    virtual BinaryMessenger binaryMessenger();

    virtual Stream<dynamic> receiveBroadcastStream(dynamic arguments);

private:
    BinaryMessenger _binaryMessenger;


};
using EventChannel = std::shared_ptr<EventChannelCls>;


#endif