#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_BINDING
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_BINDING
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "basic_types.hpp"

#include <dart/core/core.hpp>
#include <dart/convert/convert.hpp>
#include <dart/developer/developer.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/meta/meta.hpp>
#include "assertions.hpp"
#include "basic_types.hpp"
#include "constants.hpp"
#include "debug.hpp"
#include "object.hpp"
#include "platform.hpp"
#include "print.hpp"


class BindingBaseCls : public ObjectCls {
public:
    static DebugReassembleConfig debugReassembleConfig;


     BindingBaseCls();

    virtual SingletonFlutterWindow window();

    virtual PlatformDispatcher platformDispatcher();

    virtual void initInstances();

    template<typename T>
 static T checkInstance(T instance);

    static Type debugBindingType();

    virtual void initServiceExtensions();

    virtual bool locked();

    virtual Future<void> lockEvents(std::function<Future<void>()> callback);

    virtual void unlocked();

    virtual Future<void> reassembleApplication();

    virtual Future<void> performReassemble();

    virtual void registerSignalServiceExtension(AsyncCallback callback, String name);

    virtual void registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter);

    virtual void registerNumericServiceExtension(AsyncValueGetter<double> getter, String name, AsyncValueSetter<double> setter);

    virtual void postEvent(Map<String, dynamic> eventData, String eventKind);

    virtual void registerStringServiceExtension(AsyncValueGetter<String> getter, String name, AsyncValueSetter<String> setter);

    virtual void registerServiceExtension(ServiceExtensionCallback callback, String name);

    virtual String toString();

private:
    bool _debugConstructed;

    static Type _debugInitializedType;

    static bool _debugServiceExtensionsRegistered;

    int _lockCount;


    virtual void _postExtensionStateChangedEvent(String name, dynamic value);

};
using BindingBase = std::shared_ptr<BindingBaseCls>;
Future<void> _exitApplication();


class DebugReassembleConfigCls : public ObjectCls {
public:
    String widgetName;


     DebugReassembleConfigCls(String widgetName);

private:

};
using DebugReassembleConfig = std::shared_ptr<DebugReassembleConfigCls>;


#endif