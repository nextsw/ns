#ifndef DEBUG_H
#define DEBUG_H
#include <memory>

#include <flutter/foundation.hpp>


bool debugPrintHitTestResults;

bool debugPrintMouseHoverEvents;

bool debugPrintGestureArenaDiagnostics;

bool debugPrintRecognizerCallbacksTrace;

bool debugPrintResamplingMargin;

bool debugAssertAllGesturesVarsUnset(String reason);


#endif