#ifndef PACKAGES_FLUTTER_SRC_SCHEDULER_DEBUG
#define PACKAGES_FLUTTER_SRC_SCHEDULER_DEBUG
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>

bool debugPrintBeginFrameBanner;

bool debugPrintEndFrameBanner;

bool debugPrintScheduleFrameStacks;

bool debugAssertAllSchedulerVarsUnset(String reason);



#endif