#include "binding.hpp"
BindingBaseCls::BindingBaseCls() {
    {
        developer->TimelineCls->startSync("Framework initialization");
        assert([=] () {
            _debugConstructed = true;
            return true;
        }());
        assert(_debugInitializedType == nullptr);
        initInstances();
        assert(_debugInitializedType != nullptr);
        assert(!_debugServiceExtensionsRegistered);
        initServiceExtensions();
        assert(_debugServiceExtensionsRegistered);
        developer->postEvent("Flutter.FrameworkInitialization", makeMap(makeList(), makeList());
        developer->TimelineCls->finishSync();
    }
}

SingletonFlutterWindow BindingBaseCls::window() {
    return ui->window;
}

PlatformDispatcher BindingBaseCls::platformDispatcher() {
    return ui->PlatformDispatcherCls::instance;
}

void BindingBaseCls::initInstances() {
    assert(_debugInitializedType == nullptr);
    assert([=] () {
        _debugInitializedType = runtimeType;
        return true;
    }());
}

T BindingBaseCls::checkInstancetemplate<typename T : BindingBase> (T instance) {
    assert([=] () {
        if (_debugInitializedType == nullptr && instance == nullptr) {
            ;
        }
        if (instance == nullptr) {
            assert(_debugInitializedType == nullptr);
            ;
        }
        try {
            assert(instance != nullptr);
            if (instance->_debugConstructed && _debugInitializedType == nullptr) {
                ;
            }
            if (!instance->_debugConstructed) {
                ;
            }
        } catch (NoSuchMethodError null) {
            ;
        };
        return true;
    }());
    return instance!;
}

Type BindingBaseCls::debugBindingType() {
    return _debugInitializedType;
}

void BindingBaseCls::initServiceExtensions() {
    assert(!_debugServiceExtensionsRegistered);
    assert([=] () {
        registerSignalServiceExtension("reassemble", reassembleApplication);
        return true;
    }());
    if (!kReleaseMode) {
        if (!kIsWeb) {
            registerSignalServiceExtension("exit", _exitApplication);
        }
        registerStringServiceExtension("connectedVmServiceUri", [=] ()         {
            connectedVmServiceUri ?? "";
        }, [=] (String uri) {
            connectedVmServiceUri = uri;
        });
        registerStringServiceExtension("activeDevToolsServerAddress", [=] ()         {
            activeDevToolsServerAddress ?? "";
        }, [=] (String serverAddress) {
            activeDevToolsServerAddress = serverAddress;
        });
    }
    assert([=] () {
        String platformOverrideExtensionName = "platformOverride";
        registerServiceExtension(platformOverrideExtensionName, [=] (Map<String, String> parameters) {
            if (parameters->containsKey("value")) {
                ;
                _postExtensionStateChangedEvent(platformOverrideExtensionName, defaultTargetPlatform->toString()->substring("$TargetPlatform."->length));
                await await reassembleApplication();
            }
                    Map<String, dynamic> map1 = make<MapCls<>>();        map1.set("value", defaultTargetPlatform->toString()->substring("$TargetPlatform."->length));return list1;
        });
        String brightnessOverrideExtensionName = "brightnessOverride";
        registerServiceExtension(brightnessOverrideExtensionName, [=] (Map<String, String> parameters) {
            if (parameters->containsKey("value")) {
                ;
                _postExtensionStateChangedEvent(brightnessOverrideExtensionName, (debugBrightnessOverride ?? platformDispatcher->platformBrightness)->toString());
                await await reassembleApplication();
            }
                    Map<String, dynamic> map2 = make<MapCls<>>();        map2.set("value", (debugBrightnessOverride ?? platformDispatcher->platformBrightness)->toString());return list2;
        });
        return true;
    }());
    assert([=] () {
        _debugServiceExtensionsRegistered = true;
        return true;
    }());
}

bool BindingBaseCls::locked() {
    return _lockCount > 0;
}

Future<void> BindingBaseCls::lockEvents(Future<void> callback() ) {
    auto _c1 = developer->make<TimelineTaskCls>();_c1.start("Lock events");TimelineTask timelineTask = _c1;
    assert(callback != nullptr);
    _lockCount = 1;
    Future<void> future = callback();
    assert(future != nullptr, "The lockEvents() callback returned null; it should return a Future<void> that completes when the lock is to expire.");
    future->whenComplete([=] () {
        _lockCount = 1;
        if (!locked) {
            timelineTask->finish();
            unlocked();
        }
    });
    return future;
}

void BindingBaseCls::unlocked() {
    assert(!locked);
}

Future<void> BindingBaseCls::reassembleApplication() {
    return lockEvents(performReassemble);
}

Future<void> BindingBaseCls::performReassemble() {
    FlutterErrorCls->resetErrorCount();
    return <void>value();
}

void BindingBaseCls::registerSignalServiceExtension(AsyncCallback callback, String name) {
    assert(name != nullptr);
    assert(callback != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        await await callback();
        return makeMap(makeList(), makeList();
    });
}

void BindingBaseCls::registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey("enabled")) {
            await await setter(parameters["enabled"] == "true");
            _postExtensionStateChangedEvent(name, await getter()? "true" : "false");
        }
            Map<String, dynamic> map1 = make<MapCls<>>();    map1.set("enabled", await getter()? "true" : "false");return list1;
    });
}

void BindingBaseCls::registerNumericServiceExtension(AsyncValueGetter<double> getter, String name, AsyncValueSetter<double> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey(name)) {
            await await setter(double->parse(parameters[name]!));
            _postExtensionStateChangedEvent(name, (await getter())->toString());
        }
            Map<String, dynamic> map1 = make<MapCls<>>();    map1.set(name, (await getter())->toString());return list1;
    });
}

void BindingBaseCls::postEvent(Map<String, dynamic> eventData, String eventKind) {
    developer->postEvent(eventKind, eventData);
}

void BindingBaseCls::registerStringServiceExtension(AsyncValueGetter<String> getter, String name, AsyncValueSetter<String> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey("value")) {
            await await setter(parameters["value"]!);
            _postExtensionStateChangedEvent(name, await getter());
        }
            Map<String, dynamic> map1 = make<MapCls<>>();    map1.set("value", await getter());return list1;
    });
}

void BindingBaseCls::registerServiceExtension(ServiceExtensionCallback callback, String name) {
    assert(name != nullptr);
    assert(callback != nullptr);
    String methodName = "ext.flutter.$name";
    developer->registerExtension(methodName, [=] (String method,Map<String, String> parameters) {
        assert(method == methodName);
        assert([=] () {
            if (debugInstrumentationEnabled) {
                debugPrint("service extension method received: $method($parameters)");
            }
            return true;
        }());
        await await <void>debugInstrumentAction("Wait for outer event loop", [=] () {
            return <void>delayed(DurationCls::zero);
        });
        Map<String, dynamic> result;
        try {
            result = await callback(parameters);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, make<ErrorDescriptionCls>("during a service extension callback for "$method"")));
                    Map<String, String> map1 = make<MapCls<>>();        map1.set("exception", exception->toString());        map1.set("stack", stack->toString());        map1.set("method", method);return developer->ServiceExtensionResponseCls->error(developer->ServiceExtensionResponseCls::extensionError, json->encode(list1));
        };
        result["type"] = "_extensionType";
        result["method"] = method;
        return developer->ServiceExtensionResponseCls->result(json->encode(result));
    });
}

String BindingBaseCls::toString() {
    return "<${objectRuntimeType(this, 'BindingBase')}>";
}

void BindingBaseCls::_postExtensionStateChangedEvent(String name, dynamic value) {
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set("extension", "ext.flutter.$name");map1.set("value", value);postEvent("Flutter.ServiceExtensionStateChanged", list1);
}

Future<void> _exitApplication() {
    exit(0);
}

DebugReassembleConfigCls::DebugReassembleConfigCls(String widgetName) {
    {
        if (!kDebugMode) {
            ;
        }
    }
}
