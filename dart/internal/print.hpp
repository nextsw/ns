#ifndef DART_INTERNAL_PRINT
#define DART_INTERNAL_PRINT
#include <base.hpp>

#include <dart/core/core.hpp>

std::function<void(String )> printToZone;

void printToConsole(String line);


#endif