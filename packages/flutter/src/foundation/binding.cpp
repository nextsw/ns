#include "binding.hpp"
BindingBase::BindingBase() {
    {
        developer.Timeline.startSync("Framework initialization");
        assert(());
        assert(_debugInitializedType == nullptr);
        initInstances();
        assert(_debugInitializedType != nullptr);
        assert(!_debugServiceExtensionsRegistered);
        initServiceExtensions();
        assert(_debugServiceExtensionsRegistered);
        developer.postEvent("Flutter.FrameworkInitialization", );
        developer.Timeline.finishSync();
    }
}

SingletonFlutterWindow BindingBase::window() {
    return ui.window;
}

PlatformDispatcher BindingBase::platformDispatcher() {
    return ui.PlatformDispatcher.instance;
}

void BindingBase::initInstances() {
    assert(_debugInitializedType == nullptr);
    assert(());
}

T BindingBase::checkInstance<T extends BindingBase>(T instance) {
    assert(());
    return instance!;
}

Type BindingBase::debugBindingType() {
    return _debugInitializedType;
}

void BindingBase::initServiceExtensions() {
    assert(!_debugServiceExtensionsRegistered);
    assert(());
    if (!kReleaseMode) {
        if (!kIsWeb) {
            registerSignalServiceExtension("exit", _exitApplication);
        }
        registerStringServiceExtension("connectedVmServiceUri", , );
        registerStringServiceExtension("activeDevToolsServerAddress", , );
    }
    assert(());
    assert(());
}

bool BindingBase::locked() {
    return _lockCount > 0;
}

Future<void> BindingBase::lockEvents(FunctionType callback) {
    TimelineTask timelineTask = ;
    assert(callback != nullptr);
    _lockCount = 1;
    Future<void> future = callback();
    assert(future != nullptr, "The lockEvents() callback returned null; it should return a Future<void> that completes when the lock is to expire.");
    future.whenComplete();
    return future;
}

void BindingBase::unlocked() {
    assert(!locked);
}

Future<void> BindingBase::reassembleApplication() {
    return lockEvents(performReassemble);
}

Future<void> BindingBase::performReassemble() {
    FlutterError.resetErrorCount();
    return <void>value();
}

void BindingBase::registerSignalServiceExtension(AsyncCallback callback, String name) {
    assert(name != nullptr);
    assert(callback != nullptr);
    registerServiceExtension(name, );
}

void BindingBase::registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, );
}

void BindingBase::registerNumericServiceExtension(AsyncValueGetter<double> getter, String name, AsyncValueSetter<double> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, );
}

void BindingBase::postEvent(Map<String, dynamic> eventData, String eventKind) {
    developer.postEvent(eventKind, eventData);
}

void BindingBase::registerStringServiceExtension(AsyncValueGetter<String> getter, String name, AsyncValueSetter<String> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, );
}

void BindingBase::registerServiceExtension(ServiceExtensionCallback callback, String name) {
    assert(name != nullptr);
    assert(callback != nullptr);
    String methodName = "ext.flutter.$name";
    developer.registerExtension(methodName, );
}

String BindingBase::toString() {
    return "<${objectRuntimeType(this, 'BindingBase')}>";
}

void BindingBase::_postExtensionStateChangedEvent(String name, dynamic value) {
    postEvent("Flutter.ServiceExtensionStateChanged", );
}

Future<void> _exitApplication() {
    exit(0);
}

DebugReassembleConfig::DebugReassembleConfig(String widgetName) {
    {
        if (!kDebugMode) {
            ;
        }
    }
}
