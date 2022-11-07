#include "platform.hpp"
int Platform::numberOfProcessors() {
    return _numberOfProcessors;
}

String Platform::pathSeparator() {
    return _pathSeparator;
}

String Platform::localeName() {
    return _Platform.localeName();
}

String Platform::operatingSystem() {
    return _operatingSystem;
}

String Platform::operatingSystemVersion() {
    return _operatingSystemVersion;
}

String Platform::localHostname() {
    return _localHostname;
}

Map<String, String> Platform::environment() {
    return _Platform.environment;
}

String Platform::executable() {
    return _Platform.executable;
}

String Platform::resolvedExecutable() {
    return _Platform.resolvedExecutable;
}

Uri Platform::script() {
    return _Platform.script;
}

List<String> Platform::executableArguments() {
    return _Platform.executableArguments;
}

String Platform::packageConfig() {
    return _Platform.packageConfig;
}

String Platform::version() {
    return _version;
}
