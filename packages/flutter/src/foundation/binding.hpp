#ifndef BINDING_H
#define BINDING_H
#include <memory>
#include <ui.hpp>
#include "basic_types.hpp"

#include <convert/convert.hpp>
#include <developer/developer.hpp>
#include <io/io.hpp>
#include <ui/ui.hpp>
#include <meta/meta.hpp>
#include "assertions.hpp"
#include "basic_types.hpp"
#include "constants.hpp"
#include "debug.hpp"
#include "object.hpp"
#include "platform.hpp"
#include "print.hpp"



class BindingBase {
public:
    static DebugReassembleConfig debugReassembleConfig;


     BindingBase();

    SingletonFlutterWindow window();

    PlatformDispatcher platformDispatcher();

    void initInstances();

    static T checkInstance<T extends BindingBase>(T instance);

    static Type debugBindingType();

    void initServiceExtensions();

    bool locked();

    Future<void> lockEvents(FunctionType callback);

    void unlocked();

    Future<void> reassembleApplication();

    Future<void> performReassemble();

    void registerSignalServiceExtension(AsyncCallback callback, String name);

    void registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter);

    void registerNumericServiceExtension(AsyncValueGetter<double> getter, String name, AsyncValueSetter<double> setter);

    void postEvent(Map<String, dynamic> eventData, String eventKind);

    void registerStringServiceExtension(AsyncValueGetter<String> getter, String name, AsyncValueSetter<String> setter);

    void registerServiceExtension(ServiceExtensionCallback callback, String name);

    String toString();

private:
    bool _debugConstructed;

    static Type _debugInitializedType;

    static bool _debugServiceExtensionsRegistered;

    int _lockCount;


    void _postExtensionStateChangedEvent(String name, dynamic value);

};
Future<void> _exitApplication();


class DebugReassembleConfig {
public:
    String widgetName;


     DebugReassembleConfig(String widgetName);

private:

};

#endif