#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_PRINT
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_PRINT
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>

DebugPrintCallback debugPrint;

void debugPrintSynchronously(String message, int wrapWidth);

void debugPrintThrottled(String message, int wrapWidth);

int _debugPrintedCharacters;

int _kDebugPrintCapacity;

Duration _kDebugPrintPauseTime;

Queue<String> _debugPrintBuffer;

Stopwatch _debugPrintStopwatch;

Completer<void> _debugPrintCompleter;

bool _debugPrintScheduled;

void _debugPrintTask();

Future<void> debugPrintDone();

RegExp _indentPattern;


enum _WordWrapParseMode{
    inSpace,
    inWord,
    atBreak,
} // end _WordWrapParseMode
Iterable<String> debugWordWrap(String message, int width, String wrapIndent);



#endif