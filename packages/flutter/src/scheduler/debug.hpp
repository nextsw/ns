#ifndef DEBUG_H
#define DEBUG_H
#include <memory>

#include <flutter/foundation.hpp>


bool debugPrintBeginFrameBanner;

bool debugPrintEndFrameBanner;

bool debugPrintScheduleFrameStacks;

bool debugAssertAllSchedulerVarsUnset(String reason);


#endif