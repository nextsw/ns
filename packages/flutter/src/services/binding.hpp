#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <ui.hpp>
#include "binary_messenger.hpp"
#include "hardware_keyboard.hpp"
#include "restoration.hpp"

#include <async/async.hpp>
#include <convert/convert.hpp>
#include <io/io.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/scheduler.hpp>
#include "asset_bundle.hpp"
#include "binary_messenger.hpp"
#include "hardware_keyboard.hpp"
#include "message_codec.hpp"
#include "restoration.hpp"
#include "system_channels.hpp"
#include "text_input.hpp"



class ServicesBinding {
public:

    void initInstances();

    static ServicesBinding instance();

    HardwareKeyboard keyboard();

    KeyEventManager keyEventManager();

    BinaryMessenger defaultBinaryMessenger();

    ChannelBuffers channelBuffers();

    BinaryMessenger createBinaryMessenger();

    void handleMemoryPressure();

    Future<void> handleSystemMessage(Object systemMessage);

    void initLicenses();

    void initServiceExtensions();

    void evict(String asset);

    void readInitialLifecycleStateFromNativeWindow();

    RestorationManager restorationManager();

    RestorationManager createRestorationManager();

    void setSystemUiChangeCallback(SystemUiChangeCallback callback);

private:
    static ServicesBinding _instance;

    HardwareKeyboard _keyboard;

    KeyEventManager _keyEventManager;

    BinaryMessenger _defaultBinaryMessenger;

    RestorationManager _restorationManager;

    SystemUiChangeCallback _systemUiChangeCallback;


    void _initKeyboard();

    Stream<LicenseEntry> _addLicenses();

    static List<LicenseEntry> _parseLicenses(String rawLicenses);

    Future<String> _handleLifecycleMessage(String message);

    Future<void> _handlePlatformMessage(MethodCall methodCall);

    static AppLifecycleState _parseAppLifecycleMessage(String message);

};

class _DefaultBinaryMessenger : BinaryMessenger {
public:

    Future<void> handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData message);

    Future<ByteData> send(String channel, ByteData message);

    void setMessageHandler(String channel, MessageHandler handler);

private:

    void  _();

};

#endif