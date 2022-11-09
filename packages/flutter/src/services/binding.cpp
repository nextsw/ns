#include "binding.hpp"
void ServicesBindingCls::initInstances() {
    super->initInstances();
    _instance = this;
    _defaultBinaryMessenger = createBinaryMessenger();
    _restorationManager = createRestorationManager();
    _initKeyboard();
    initLicenses();
    SystemChannelsCls::system->setMessageHandler([=] (dynamic message)     {
        handleSystemMessage(((Object)message));
    });
    SystemChannelsCls::lifecycle->setMessageHandler(_handleLifecycleMessage);
    SystemChannelsCls::platform->setMethodCallHandler(_handlePlatformMessage);
    TextInputCls->ensureInitialized();
    readInitialLifecycleStateFromNativeWindow();
}

ServicesBinding ServicesBindingCls::instance() {
    return BindingBaseCls->checkInstance(_instance);
}

HardwareKeyboard ServicesBindingCls::keyboard() {
    return _keyboard;
}

KeyEventManager ServicesBindingCls::keyEventManager() {
    return _keyEventManager;
}

BinaryMessenger ServicesBindingCls::defaultBinaryMessenger() {
    return _defaultBinaryMessenger;
}

ChannelBuffers ServicesBindingCls::channelBuffers() {
    return ui->channelBuffers;
}

BinaryMessenger ServicesBindingCls::createBinaryMessenger() {
    return _DefaultBinaryMessengerCls->_();
}

void ServicesBindingCls::handleMemoryPressure() {
    rootBundle->clear();
}

Future<void> ServicesBindingCls::handleSystemMessage(Object systemMessage) {
    Map<String, dynamic> message = ((Map<String, dynamic>)systemMessage);
    String type = ((String)message["type"]);
    ;
    return;
}

void ServicesBindingCls::initLicenses() {
    LicenseRegistryCls->addLicense(_addLicenses);
}

void ServicesBindingCls::initServiceExtensions() {
    super->initServiceExtensions();
    assert([=] () {
        registerStringServiceExtension("evict", [=] ()         {
            "";
        }, [=] (String value) {
            evict(value);
        });
        return true;
    }());
}

void ServicesBindingCls::evict(String asset) {
    rootBundle->evict(asset);
}

void ServicesBindingCls::readInitialLifecycleStateFromNativeWindow() {
    if (lifecycleState != nullptr) {
        return;
    }
    AppLifecycleState state = _parseAppLifecycleMessage(platformDispatcher->initialLifecycleState);
    if (state != nullptr) {
        handleAppLifecycleStateChanged(state);
    }
}

RestorationManager ServicesBindingCls::restorationManager() {
    return _restorationManager;
}

RestorationManager ServicesBindingCls::createRestorationManager() {
    return make<RestorationManagerCls>();
}

void ServicesBindingCls::setSystemUiChangeCallback(SystemUiChangeCallback callback) {
    _systemUiChangeCallback = callback;
}

void ServicesBindingCls::_initKeyboard() {
    _keyboard = make<HardwareKeyboardCls>();
    _keyEventManager = make<KeyEventManagerCls>(_keyboard, RawKeyboardCls::instance);
    platformDispatcher->onKeyData = _keyEventManager->handleKeyData;
    SystemChannelsCls::keyEvent->setMessageHandler(_keyEventManager->handleRawKeyMessage);
}

Stream<LicenseEntry> ServicesBindingCls::_addLicenses() {
    StreamController<LicenseEntry> controller;
    controller = <LicenseEntry>make<StreamControllerCls>([=] () {
        String rawLicenses;
        if (kIsWeb) {
            rawLicenses = await rootBundle->loadString("NOTICES"false);
        } else {
            ByteData licenseBytes = await rootBundle->load("NOTICES.Z");
            List<int> unzippedBytes = await <List<int>, List<int>>compute(gzip->decode, licenseBytes->buffer->asUint8List()"decompressLicenses");
            rawLicenses = await <List<int>, String>compute(utf8->decode, unzippedBytes"utf8DecodeLicenses");
        }
        List<LicenseEntry> licenses = await <String, List<LicenseEntry>>compute(_parseLicenses, rawLicenses"parseLicenses");
        licenses->forEach(controller->add);
        await await controller->close();
    });
    return controller->stream;
}

List<LicenseEntry> ServicesBindingCls::_parseLicenses(String rawLicenses) {
    String licenseSeparator = "\n${'-' * 80}\n";
    List<LicenseEntry> result = makeList();
    List<String> licenses = rawLicenses->split(licenseSeparator);
    for (String license : licenses) {
        int split = license->indexOf("\n\n");
        if (split >= 0) {
            result->add(make<LicenseEntryWithLineBreaksCls>(license->substring(0, split)->split("\n"), license->substring(split + 2)));
        } else {
            result->add(make<LicenseEntryWithLineBreaksCls>(makeList(), license));
        }
    }
    return result;
}

Future<String> ServicesBindingCls::_handleLifecycleMessage(String message) {
    handleAppLifecycleStateChanged(_parseAppLifecycleMessage(message!)!);
    return nullptr;
}

Future<void> ServicesBindingCls::_handlePlatformMessage(MethodCall methodCall) {
    String method = methodCall->method;
    assert(method == "SystemChrome.systemUIChange");
    List<dynamic> args = ((List<dynamic>)methodCall->arguments);
    if (_systemUiChangeCallback != nullptr) {
        await await _systemUiChangeCallback!(((bool)args[0]));
    }
}

AppLifecycleState ServicesBindingCls::_parseAppLifecycleMessage(String message) {
    ;
    return nullptr;
}

Future<void> _DefaultBinaryMessengerCls::handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData message) {
    ui->channelBuffers->push(channel, message, [=] (ByteData data) {
        if (callback != nullptr) {
            callback(data);
        }
    });
}

Future<ByteData> _DefaultBinaryMessengerCls::send(String channel, ByteData message) {
    Completer<ByteData> completer = <ByteData>make<CompleterCls>();
    ui->PlatformDispatcherCls::instance->sendPlatformMessage(channel, message, [=] (ByteData reply) {
        try {
            completer->complete(reply);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, "services library", make<ErrorDescriptionCls>("during a platform message response callback")));
        };
    });
    return completer->future;
}

void _DefaultBinaryMessengerCls::setMessageHandler(String channel, MessageHandler handler) {
    if (handler == nullptr) {
        ui->channelBuffers->clearListener(channel);
    } else {
        ui->channelBuffers->setListener(channel, [=] (ByteData data,PlatformMessageResponseCallback callback) {
            ByteData response;
            try {
                response = await handler(data);
            } catch (Unknown exception) {
                FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, "services library", make<ErrorDescriptionCls>("during a platform message callback")));
            } finally {
                callback(response);
            };
        });
    }
}
