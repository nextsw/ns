#ifndef PACKAGES_FLUTTER_SRC_SERVICES_BINDING
#define PACKAGES_FLUTTER_SRC_SERVICES_BINDING
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "binary_messenger.hpp"
#include "hardware_keyboard.hpp"
#include "restoration.hpp"

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/convert/convert.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "asset_bundle.hpp"
#include "binary_messenger.hpp"
#include "hardware_keyboard.hpp"
#include "message_codec.hpp"
#include "restoration.hpp"
#include "system_channels.hpp"
#include "text_input.hpp"


class ServicesBindingCls : public ObjectCls {
public:

    virtual void initInstances();

    static ServicesBinding instance();

    virtual HardwareKeyboard keyboard();

    virtual KeyEventManager keyEventManager();

    virtual BinaryMessenger defaultBinaryMessenger();

    virtual ChannelBuffers channelBuffers();

    virtual BinaryMessenger createBinaryMessenger();

    virtual void handleMemoryPressure();

    virtual Future<void> handleSystemMessage(Object systemMessage);

    virtual void initLicenses();

    virtual void initServiceExtensions();

    virtual void evict(String asset);

    virtual void readInitialLifecycleStateFromNativeWindow();

    virtual RestorationManager restorationManager();

    virtual RestorationManager createRestorationManager();

    virtual void setSystemUiChangeCallback(SystemUiChangeCallback callback);

private:
    static ServicesBinding _instance;

    HardwareKeyboard _keyboard;

    KeyEventManager _keyEventManager;

    BinaryMessenger _defaultBinaryMessenger;

    RestorationManager _restorationManager;

    SystemUiChangeCallback _systemUiChangeCallback;


    virtual void _initKeyboard();

    virtual Stream<LicenseEntry> _addLicenses();

    static List<LicenseEntry> _parseLicenses(String rawLicenses);

    virtual Future<String> _handleLifecycleMessage(String message);

    virtual Future<void> _handlePlatformMessage(MethodCall methodCall);

    static AppLifecycleState _parseAppLifecycleMessage(String message);

};
using ServicesBinding = std::shared_ptr<ServicesBindingCls>;

class _DefaultBinaryMessengerCls : public BinaryMessengerCls {
public:

    virtual Future<void> handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData message);

    virtual Future<ByteData> send(String channel, ByteData message);

    virtual void setMessageHandler(String channel, MessageHandler handler);

private:

    virtual void  _();
};
using _DefaultBinaryMessenger = std::shared_ptr<_DefaultBinaryMessengerCls>;


#endif