#ifndef DART_DEVELOPER_DEVELOPER
#define DART_DEVELOPER_DEVELOPER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/internal/internal.hpp>
#include <dart/async/async.hpp>
#include <dart/convert/convert.hpp>
#include <dart/isolate/isolate.hpp>

bool debugger(String message, bool when);
Object inspect(Object object);
void log(String message, Object error, int level, String name, int sequenceNumber, StackTrace stackTrace, DateTime time, Zone zone);

// Parts
#include "extension.hpp"
#include "profiler.hpp"
#include "service.hpp"
#include "timeline.hpp"

#endif