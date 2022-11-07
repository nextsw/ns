#ifndef NATIVES_H
#define NATIVES_H
#include <memory>




class DartPluginRegistrant {
public:

    static void ensureInitialized();

private:
    static bool _wasInitialized;


    static void _ensureInitialized();

};
void _print(String arg);

void _printDebug(String arg);


class _Logger {
public:

private:

    static void _printString(String s);

    static void _printDebugString(String s);

};
const Endian _kFakeHostEndian;

Future<ServiceExtensionResponse> _scheduleFrame(String method, Map<String, String> parameters);

void _setupHooks();

List<int> saveCompilationTrace();

void _scheduleMicrotask(FunctionType callback);

int _getCallbackHandle(FunctionType closure);

FunctionType _getCallbackFromHandle(int handle);

_PrintClosure _getPrintClosure();

_ScheduleImmediateClosure _getScheduleMicrotaskClosure();

bool _impellerEnabled;


#endif