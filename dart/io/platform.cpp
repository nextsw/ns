#include "platform.hpp"
int PlatformCls::numberOfProcessors() {
    return _numberOfProcessors;
}

String PlatformCls::pathSeparator() {
    return _pathSeparator;
}

String PlatformCls::localeName() {
    return _PlatformCls->localeName();
}

String PlatformCls::operatingSystem() {
    return _operatingSystem;
}

String PlatformCls::operatingSystemVersion() {
    return _operatingSystemVersion;
}

String PlatformCls::localHostname() {
    return _localHostname;
}

Map<String, String> PlatformCls::environment() {
    return _PlatformCls::environment;
}

String PlatformCls::executable() {
    return _PlatformCls::executable;
}

String PlatformCls::resolvedExecutable() {
    return _PlatformCls::resolvedExecutable;
}

Uri PlatformCls::script() {
    return _PlatformCls::script;
}

List<String> PlatformCls::executableArguments() {
    return _PlatformCls::executableArguments;
}

String PlatformCls::packageConfig() {
    return _PlatformCls::packageConfig;
}

String PlatformCls::version() {
    return _version;
}
