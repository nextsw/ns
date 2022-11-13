#include "_platform_io.hpp"
TargetPlatform defaultTargetPlatform() {
    TargetPlatform result;
    if (PlatformCls::isAndroid) {
        result = platform->TargetPlatformCls::android;
    } else {
        if (PlatformCls::isIOS) {
        result = platform->TargetPlatformCls::iOS;
    } else {
        if (PlatformCls::isFuchsia) {
        result = platform->TargetPlatformCls::fuchsia;
    } else {
        if (PlatformCls::isLinux) {
        result = platform->TargetPlatformCls::linux;
    } else {
        if (PlatformCls::isMacOS) {
        result = platform->TargetPlatformCls::macOS;
    } else {
        if (PlatformCls::isWindows) {
        result = platform->TargetPlatformCls::windows;
    }
;
    };
    };
    };
    };
    }    assert([=] () {
        if (PlatformCls::environment->containsKey(__s("FLUTTER_TEST"))) {
            result = platform->TargetPlatformCls::android;
        }
        return true;
    }());
    if (platform->debugDefaultTargetPlatformOverride != nullptr) {
        result = platform->debugDefaultTargetPlatformOverride;
    }
    if (result == nullptr) {
        throw make<FlutterErrorCls>(__sf("Unknown platform.\n%s was not recognized as a target platform. Consider updating the list of TargetPlatforms to include this platform.", PlatformCls::operatingSystem));
    }
    return result!;
}
