#ifndef DEVELOPER_H
#define DEVELOPER_H
#include <memory>

#include <internal/internal.hpp>
#include <async/async.hpp>
#include <convert/convert.hpp>
#include <isolate/isolate.hpp>

// Parts
#include "extension.hpp"
#include "profiler.hpp"
#include "service.hpp"
#include "timeline.hpp"

external bool debugger(String message, bool when);

external Object inspect(Object object);

external void log(Object error, int level, String message, String name, int sequenceNumber, StackTrace stackTrace, DateTime time, Zone zone);


#endif