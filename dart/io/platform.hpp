#ifndef PLATFORM_H
#define PLATFORM_H
#include <memory>




class Platform {
public:
    static bool isLinux;

    static bool isMacOS;

    static bool isWindows;

    static bool isAndroid;

    static bool isIOS;

    static bool isFuchsia;


    static int numberOfProcessors();

    static String pathSeparator();

    static String localeName();

    static String operatingSystem();

    static String operatingSystemVersion();

    static String localHostname();

    static Map<String, String> environment();

    static String executable();

    static String resolvedExecutable();

    static Uri script();

    static List<String> executableArguments();

    static String packageConfig();

    static String version();

private:
    static auto  _numberOfProcessors;

    static auto  _pathSeparator;

    static auto  _operatingSystem;

    static auto  _operatingSystemVersion;

    static auto  _localHostname;

    static auto  _version;


};

#endif