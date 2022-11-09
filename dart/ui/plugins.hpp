#ifndef DART_UI_PLUGINS
#define DART_UI_PLUGINS
#include <base.hpp>

#include <dart/core/core.hpp>


class CallbackHandleCls : public ObjectCls {
public:

    virtual void  fromRawHandle(int _handle);

    virtual int toRawHandle();

    virtual bool operator==(Object other);

    virtual int hashCode();

private:
    int _handle;


};
using CallbackHandle = std::shared_ptr<CallbackHandleCls>;

class PluginUtilitiesCls : public ObjectCls {
public:

    static CallbackHandle getCallbackHandle(void  callback() );

    static void  Function() getCallbackFromHandle(CallbackHandle handle);

private:
    static Map<void  Function(), CallbackHandle> _forwardCache;

    static Map<CallbackHandle, void  Function()> _backwardCache;


    virtual void  _();

};
using PluginUtilities = std::shared_ptr<PluginUtilitiesCls>;


#endif