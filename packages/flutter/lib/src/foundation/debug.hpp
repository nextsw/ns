#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_DEBUG
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_DEBUG
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "print.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "assertions.hpp"
#include "platform.hpp"
#include "print.hpp"

bool debugAssertAllFoundationVarsUnset(DebugPrintCallback debugPrintOverride, String reason);

bool debugInstrumentationEnabled;

template<typename T>  Future<T> debugInstrumentAction(Future<T> action() , String description);

int debugDoublePrecision;

String debugFormatDouble(double value);

Brightness debugBrightnessOverride;

String activeDevToolsServerAddress;

String connectedVmServiceUri;



#endif