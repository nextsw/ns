#ifndef DART_UI_NATIVES
#define DART_UI_NATIVES
#include <base.hpp>

#include <dart/core/core.hpp>


class DartPluginRegistrantCls : public ObjectCls {
public:

    static void ensureInitialized();

private:
    static bool _wasInitialized;


    static void _ensureInitialized();
};
using DartPluginRegistrant = std::shared_ptr<DartPluginRegistrantCls>;
void _print(String arg);

void _printDebug(String arg);


class _LoggerCls : public ObjectCls {
public:

private:

    static void _printString(String s);
    static void _printDebugString(String s);
};
using _Logger = std::shared_ptr<_LoggerCls>;
Endian _kFakeHostEndian;

Future<ServiceExtensionResponse> _scheduleFrame(String method, Map<String, String> parameters);

void _setupHooks();

List<int> saveCompilationTrace();

void _scheduleMicrotask(void callback() );
int _getCallbackHandle(void  closure() );
void  Function() _getCallbackFromHandle(int handle);
_PrintClosure _getPrintClosure();

_ScheduleImmediateClosure _getScheduleMicrotaskClosure();

bool _impellerEnabled;



#endif