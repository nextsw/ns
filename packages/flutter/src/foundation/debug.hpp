#ifndef DEBUG_H
#define DEBUG_H
#include <memory>
#include <ui.hpp>
#include "print.hpp"

#include <ui/ui.hpp>
#include "assertions.hpp"
#include "platform.hpp"
#include "print.hpp"


bool debugAssertAllFoundationVarsUnset(DebugPrintCallback debugPrintOverride, String reason);

bool debugInstrumentationEnabled;

Future<T> debugInstrumentAction<T>(FunctionType action, String description);

int debugDoublePrecision;

String debugFormatDouble(double value);

Brightness debugBrightnessOverride;

String activeDevToolsServerAddress;

String connectedVmServiceUri;


#endif