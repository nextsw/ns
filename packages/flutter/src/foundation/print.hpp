#ifndef PRINT_H
#define PRINT_H
#include <memory>

#include <async/async.hpp>
#include <collection/collection.hpp>


DebugPrintCallback debugPrint;

void debugPrintSynchronously(String message, int wrapWidth);

void debugPrintThrottled(String message, int wrapWidth);

int _debugPrintedCharacters;

const int _kDebugPrintCapacity;

const Duration _kDebugPrintPauseTime;

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