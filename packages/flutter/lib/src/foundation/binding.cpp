#include "binding.hpp"
BindingBaseCls::BindingBaseCls() {
    {
        developer->TimelineCls->startSync(__s("Framework initialization"));
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
        developer->postEvent(__s("Flutter.FrameworkInitialization"), makeMap(makeList(), makeList());
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

template<typename T>
T BindingBaseCls::checkInstance(T instance) {
    assert([=] () {
        if (_debugInitializedType == nullptr && instance == nullptr) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        if (instance == nullptr) {
            assert(_debugInitializedType == nullptr);
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem, ArrayItem));
        }
        try {
            assert(instance != nullptr);
            if (instance->_debugConstructed && _debugInitializedType == nullptr) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
            }
            if (!instance->_debugConstructed) {
                throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
            }
        } catch (NoSuchMethodError null) {
            throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
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
        registerSignalServiceExtension(__s("reassemble"), reassembleApplication);
        return true;
    }());
    if (!kReleaseMode) {
        if (!kIsWeb) {
            registerSignalServiceExtension(__s("exit"), _exitApplication);
        }
        registerStringServiceExtension(__s("connectedVmServiceUri"), [=] () {
            connectedVmServiceUri | __s("");
        }, [=] (String uri) {
            connectedVmServiceUri = uri;
        });
        registerStringServiceExtension(__s("activeDevToolsServerAddress"), [=] () {
            activeDevToolsServerAddress | __s("");
        }, [=] (String serverAddress) {
            activeDevToolsServerAddress = serverAddress;
        });
    }
    assert([=] () {
        String platformOverrideExtensionName = __s("platformOverride");
        registerServiceExtension(platformOverrideExtensionName, [=] (Map<String, String> parameters) {
            if (parameters->containsKey(__s("value"))) {
                ;
                _postExtensionStateChangedEvent(platformOverrideExtensionName, defaultTargetPlatform->toString()->substring(__sf("%s.", TargetPlatformCls)->length()));
                await reassembleApplication();
            }
                    Map<String, Object> map1 = make<MapCls<>>();        map1.set(__s("value"), defaultTargetPlatform->toString()->substring(__sf("%s.", TargetPlatformCls)->length()));return list1;
        });
        String brightnessOverrideExtensionName = __s("brightnessOverride");
        registerServiceExtension(brightnessOverrideExtensionName, [=] (Map<String, String> parameters) {
            if (parameters->containsKey(__s("value"))) {
                ;
                _postExtensionStateChangedEvent(brightnessOverrideExtensionName, (debugBrightnessOverride | platformDispatcher()->platformBrightness())->toString());
                await reassembleApplication();
            }
                    Map<String, Object> map2 = make<MapCls<>>();        map2.set(__s("value"), (debugBrightnessOverride | platformDispatcher()->platformBrightness())->toString());return list2;
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

Future<void> BindingBaseCls::lockEvents(std::function<Future<void>()> callback) {
    auto _c1 = developer->make<TimelineTaskCls>();_c1.start(__s("Lock events"));TimelineTask timelineTask = _c1;
    assert(callback != nullptr);
    _lockCount += 1;
    Future<void> future = callback();
    assert(future != nullptr, __s("The lockEvents() callback returned null; it should return a Future<void> that completes when the lock is to expire."));
    future->whenComplete([=] () {
        _lockCount -= 1;
        if (!locked()) {
            timelineTask->finish();
            unlocked();
        }
    });
    return future;
}

void BindingBaseCls::unlocked() {
    assert(!locked());
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
        await callback();
        return makeMap(makeList(), makeList();
    });
}

void BindingBaseCls::registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey(__s("enabled"))) {
            await setter(parameters[__s("enabled")] == __s("true"));
            _postExtensionStateChangedEvent(name, await getter()? __s("true") : __s("false"));
        }
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("enabled"), await getter()? __s("true") : __s("false"));return list1;
    });
}

void BindingBaseCls::registerNumericServiceExtension(AsyncValueGetter<double> getter, String name, AsyncValueSetter<double> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey(name)) {
            await setter(double->parse(parameters[name]!));
            _postExtensionStateChangedEvent(name, (await getter())->toString());
        }
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(name, (await getter())->toString());return list1;
    });
}

void BindingBaseCls::postEvent(String eventKind, Map<String, Object> eventData) {
    developer->postEvent(eventKind, eventData);
}

void BindingBaseCls::registerStringServiceExtension(AsyncValueGetter<String> getter, String name, AsyncValueSetter<String> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey(__s("value"))) {
            await setter(parameters[__s("value")]!);
            _postExtensionStateChangedEvent(name, await getter());
        }
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("value"), await getter());return list1;
    });
}

void BindingBaseCls::registerServiceExtension(ServiceExtensionCallback callback, String name) {
    assert(name != nullptr);
    assert(callback != nullptr);
    String methodName = __sf("ext.flutter.%s", name);
    developer->registerExtension(methodName, [=] (String method,Map<String, String> parameters) {
        assert(method == methodName);
        assert([=] () {
            if (debugInstrumentationEnabled) {
                debugPrint(__sf("service extension method received: %s(%s)", method, parameters));
            }
            return true;
        }());
        await <void>debugInstrumentAction(__s("Wait for outer event loop"), [=] () {
            return <void>delayed(DurationCls::zero);
        });
        Map<String, Object> result;
        try {
            result = await callback(parameters);
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, make<ErrorDescriptionCls>(__sf("during a service extension callback for "%s"", method))));
                    Map<String, String> map1 = make<MapCls<>>();        map1.set(__s("exception"), exception->toString());        map1.set(__s("stack"), stack->toString());        map1.set(__s("method"), method);return developer->ServiceExtensionResponseCls->error(developer->ServiceExtensionResponseCls::extensionError, json->encode(list1));
        };
        result[__s("type")] = __s("_extensionType");
        result[__s("method")] = method;
        return developer->ServiceExtensionResponseCls->result(json->encode(result));
    });
}

String BindingBaseCls::toString() {
    return __sf("<%s>", objectRuntimeType(this, __s("BindingBase")));
}

void BindingBaseCls::_postExtensionStateChangedEvent(String name, Object value) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("extension"), __sf("ext.flutter.%s", name));map1.set(__s("value"), value);postEvent(__s("Flutter.ServiceExtensionStateChanged"), list1);
}

Future<void> _exitApplication() {
    exit(0);
}

DebugReassembleConfigCls::DebugReassembleConfigCls(String widgetName) {
    {
        if (!kDebugMode) {
            throw make<FlutterErrorCls>(__s("Cannot instantiate DebugReassembleConfig in profile or release mode."));
        }
    }
}
