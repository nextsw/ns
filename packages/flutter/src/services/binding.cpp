#include "binding.hpp"
void ServicesBinding::initInstances() {
    super.initInstances();
    _instance = this;
    _defaultBinaryMessenger = createBinaryMessenger();
    _restorationManager = createRestorationManager();
    _initKeyboard();
    initLicenses();
    SystemChannels.system.setMessageHandler();
    SystemChannels.lifecycle.setMessageHandler(_handleLifecycleMessage);
    SystemChannels.platform.setMethodCallHandler(_handlePlatformMessage);
    TextInput.ensureInitialized();
    readInitialLifecycleStateFromNativeWindow();
}

ServicesBinding ServicesBinding::instance() {
    return BindingBase.checkInstance(_instance);
}

HardwareKeyboard ServicesBinding::keyboard() {
    return _keyboard;
}

KeyEventManager ServicesBinding::keyEventManager() {
    return _keyEventManager;
}

BinaryMessenger ServicesBinding::defaultBinaryMessenger() {
    return _defaultBinaryMessenger;
}

ChannelBuffers ServicesBinding::channelBuffers() {
    return ui.channelBuffers;
}

BinaryMessenger ServicesBinding::createBinaryMessenger() {
    return const _DefaultBinaryMessenger._();
}

void ServicesBinding::handleMemoryPressure() {
    rootBundle.clear();
}

Future<void> ServicesBinding::handleSystemMessage(Object systemMessage) {
    Map<String, dynamic> message = (;
    String type = (;
    ;
    return;
}

void ServicesBinding::initLicenses() {
    LicenseRegistry.addLicense(_addLicenses);
}

void ServicesBinding::initServiceExtensions() {
    super.initServiceExtensions();
    assert(());
}

void ServicesBinding::evict(String asset) {
    rootBundle.evict(asset);
}

void ServicesBinding::readInitialLifecycleStateFromNativeWindow() {
    if (lifecycleState != nullptr) {
        return;
    }
    AppLifecycleState state = _parseAppLifecycleMessage(platformDispatcher.initialLifecycleState);
    if (state != nullptr) {
        handleAppLifecycleStateChanged(state);
    }
}

RestorationManager ServicesBinding::restorationManager() {
    return _restorationManager;
}

RestorationManager ServicesBinding::createRestorationManager() {
    return RestorationManager();
}

void ServicesBinding::setSystemUiChangeCallback(SystemUiChangeCallback callback) {
    _systemUiChangeCallback = callback;
}

void ServicesBinding::_initKeyboard() {
    _keyboard = HardwareKeyboard();
    _keyEventManager = KeyEventManager(_keyboard, RawKeyboard.instance);
    platformDispatcher.onKeyData = _keyEventManager.handleKeyData;
    SystemChannels.keyEvent.setMessageHandler(_keyEventManager.handleRawKeyMessage);
}

Stream<LicenseEntry> ServicesBinding::_addLicenses() {
    StreamController<LicenseEntry> controller;
    controller = <LicenseEntry>StreamController();
    return controller.stream;
}

List<LicenseEntry> ServicesBinding::_parseLicenses(String rawLicenses) {
    String licenseSeparator = "\n${'-' * 80}\n";
    List<LicenseEntry> result = ;
    List<String> licenses = rawLicenses.split(licenseSeparator);
    for (String license : licenses) {
        int split = license.indexOf("\n\n");
        if (split >= 0) {
            result.add(LicenseEntryWithLineBreaks(license.substring(0, split).split("\n"), license.substring(split + 2)));
        } else {
            result.add(LicenseEntryWithLineBreaks(const , license));
        }
    }
    return result;
}

Future<String> ServicesBinding::_handleLifecycleMessage(String message) {
    handleAppLifecycleStateChanged(_parseAppLifecycleMessage(message!)!);
    return nullptr;
}

Future<void> ServicesBinding::_handlePlatformMessage(MethodCall methodCall) {
    String method = methodCall.method;
    assert(method == "SystemChrome.systemUIChange");
    List<dynamic> args = (;
    if (_systemUiChangeCallback != nullptr) {
        await await _systemUiChangeCallback!(();
    }
}

AppLifecycleState ServicesBinding::_parseAppLifecycleMessage(String message) {
    ;
    return nullptr;
}

Future<void> _DefaultBinaryMessenger::handlePlatformMessage(PlatformMessageResponseCallback callback, String channel, ByteData message) {
    ui.channelBuffers.push(channel, message, );
}

Future<ByteData> _DefaultBinaryMessenger::send(String channel, ByteData message) {
    Completer<ByteData> completer = <ByteData>Completer();
    ui.PlatformDispatcher.instance.sendPlatformMessage(channel, message, );
    return completer.future;
}

void _DefaultBinaryMessenger::setMessageHandler(String channel, MessageHandler handler) {
    if (handler == nullptr) {
        ui.channelBuffers.clearListener(channel);
    } else {
        ui.channelBuffers.setListener(channel, );
    }
}
