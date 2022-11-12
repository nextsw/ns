#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_PLATFORM
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_PLATFORM
#include <base.hpp>

#include <dart/core/core.hpp>
#include "_platform_io.hpp"

TargetPlatform defaultTargetPlatform();


enum TargetPlatform{
    android,
    fuchsia,
    iOS,
    linux,
    macOS,
    windows,
} // end TargetPlatform
TargetPlatform debugDefaultTargetPlatformOverride;



#endif