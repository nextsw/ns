#ifndef PACKAGES_FLUTTER_SRC_GESTURES_DEBUG
#define PACKAGES_FLUTTER_SRC_GESTURES_DEBUG
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>

bool debugPrintHitTestResults;

bool debugPrintMouseHoverEvents;

bool debugPrintGestureArenaDiagnostics;

bool debugPrintRecognizerCallbacksTrace;

bool debugPrintResamplingMargin;

bool debugAssertAllGesturesVarsUnset(String reason);



#endif