#include "print.hpp"
void debugPrintSynchronously(String message, int wrapWidth) {
    if (message != nullptr && wrapWidth != nullptr) {
        print(message->split(__s("\n"))-><String>expand([=] (String line)         {
            debugWordWrap(line, wrapWidth);
        })->join(__s("\n")));
    } else {
        print(message);
    }
}

void debugPrintThrottled(String message, int wrapWidth) {
    List<String> messageLines = message?->split(__s("\n")) or makeList(ArrayItem);
    if (wrapWidth != nullptr) {
        _debugPrintBuffer->addAll(messageLines-><String>expand([=] (String line)         {
            debugWordWrap(line, wrapWidth);
        }));
    } else {
        _debugPrintBuffer->addAll(messageLines);
    }
    if (!_debugPrintScheduled) {
        _debugPrintTask();
    }
}

void _debugPrintTask() {
    _debugPrintScheduled = false;
    if (_debugPrintStopwatch->elapsed > _kDebugPrintPauseTime) {
        _debugPrintStopwatch->stop();
        _debugPrintStopwatch->reset();
        _debugPrintedCharacters = 0;
    }
    while ( < _kDebugPrintCapacity && _debugPrintBuffer->isNotEmpty) {
        String line = _debugPrintBuffer->removeFirst();
        _debugPrintedCharacters = line->length();
        print(line);
    }
    if (_debugPrintBuffer->isNotEmpty) {
        _debugPrintScheduled = true;
        _debugPrintedCharacters = 0;
        make<TimerCls>(_kDebugPrintPauseTime, _debugPrintTask);
        _debugPrintCompleter = <void>make<CompleterCls>();
    } else {
        _debugPrintStopwatch->start();
        _debugPrintCompleter?->complete();
        _debugPrintCompleter = nullptr;
    }
}

Future<void> debugPrintDone() {
    return _debugPrintCompleter?->future or <void>value();
}

Iterable<String> debugWordWrap(String message, int width, String wrapIndent) {
    if (message->length() < width || message->trimLeft()[0] == __s("#")) {
        return makeList(ArrayItem);
    }
    List<String> wrapped = makeList();
    Match prefixMatch = _indentPattern->matchAsPrefix(message)!;
    String prefix = wrapIndent + __s(" ") * prefixMatch->group(0)!->length();
    int start = 0;
    int startForLengthCalculations = 0;
    bool addPrefix = false;
    int index = prefix->length();
    _WordWrapParseMode mode = _WordWrapParseModeCls::inSpace;
    int lastWordStart;
    int lastWordEnd;
    while (true) {
        ;
    }
}
