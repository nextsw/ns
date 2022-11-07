#include "_platform_io.hpp"
TargetPlatform defaultTargetPlatform() {
    TargetPlatform result;
    if (Platform.isAndroid) {
        result = platform.TargetPlatform.android;
    } else     {
        if (Platform.isIOS) {
        result = platform.TargetPlatform.iOS;
    } else     {
        if (Platform.isFuchsia) {
        result = platform.TargetPlatform.fuchsia;
    } else     {
        if (Platform.isLinux) {
        result = platform.TargetPlatform.linux;
    } else     {
        if (Platform.isMacOS) {
        result = platform.TargetPlatform.macOS;
    } else     {
        if (Platform.isWindows) {
        result = platform.TargetPlatform.windows;
    }
;
    };
    };
    };
    };
    }    assert(());
    if (platform.debugDefaultTargetPlatformOverride != nullptr) {
        result = platform.debugDefaultTargetPlatformOverride;
    }
    if (result == nullptr) {
        ;
    }
    return result!;
}
