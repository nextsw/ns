#ifndef PLUGINS_H
#define PLUGINS_H
#include <memory>




class CallbackHandle {
public:

    void  fromRawHandle(int _handle);

    int toRawHandle();

    bool ==(Object other);

    int hashCode();

private:
    int _handle;


};

class PluginUtilities {
public:

    static CallbackHandle getCallbackHandle(FunctionType callback);

    static FunctionType getCallbackFromHandle(CallbackHandle handle);

private:
    static Map<FunctionType, CallbackHandle> _forwardCache;

    static Map<CallbackHandle, FunctionType> _backwardCache;


    void  _();

};

#endif