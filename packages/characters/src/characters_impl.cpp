#include "characters_impl.hpp"
CharacterRange StringCharacters::iterator() {
    return StringCharacterRange._(string, 0, 0);
}

CharacterRange StringCharacters::iteratorAtEnd() {
    return StringCharacterRange._(string, string.length, string.length);
}

String StringCharacters::first() {
    return string.isEmpty?  : string.substring(0, Breaks(string, 0, string.length, stateSoTNoBreak).nextBreak());
}

String StringCharacters::last() {
    return string.isEmpty?  : string.substring(BackBreaks(string, string.length, 0, stateEoTNoBreak).nextBreak());
}

String StringCharacters::single() {
    if (string.isEmpty)     {
        ;
    }
    auto firstEnd = Breaks(string, 0, string.length, stateSoTNoBreak).nextBreak();
    if (firstEnd == string.length)     {
        return string;
    }
    ;
}

bool StringCharacters::isEmpty() {
    return string.isEmpty;
}

bool StringCharacters::isNotEmpty() {
    return string.isNotEmpty;
}

int StringCharacters::length() {
    if (string.isEmpty)     {
        return 0;
    }
    auto brk = Breaks(string, 0, string.length, stateSoTNoBreak);
    auto length = 0;
    while (brk.nextBreak() >= 0) {
        length++;
    }
    return length;
}

Iterable<T> StringCharacters::whereType<T>() {
    Iterable<Object> self = this;
    if (self is Iterable<T>) {
        return self.<T>map();
    }
    return <T>empty();
}

String StringCharacters::join(String separator) {
    if (separator == "")     {
        return string;
    }
    return _explodeReplace(string, 0, string.length, separator, "");
}

String StringCharacters::lastWhere(FunctionType orElse, FunctionType test) {
    auto cursor = string.length;
    auto brk = BackBreaks(string, cursor, 0, stateEoTNoBreak);
    auto next = 0;
    while ((next = brk.nextBreak()) >= 0) {
        auto current = string.substring(next, cursor);
        if (test(current))         {
            return current;
        }
        cursor = next;
    }
    if (orElse != nullptr)     {
        return orElse();
    }
    ;
}

String StringCharacters::elementAt(int index) {
    RangeError.checkNotNegative(index, "index");
    auto count = 0;
    if (string.isNotEmpty) {
        auto breaks = Breaks(string, 0, string.length, stateSoTNoBreak);
        auto start = 0;
        auto end = 0;
        while ((end = breaks.nextBreak()) >= 0) {
            if (count == index)             {
                return string.substring(start, end);
            }
            count++;
            start = end;
        }
    }
    ;
}

bool StringCharacters::contains(Object singleCharacterString) {
    if (singleCharacterString is! String)     {
        return false;
    }
    if (singleCharacterString.isEmpty)     {
        return false;
    }
    auto next = Breaks(singleCharacterString, 0, singleCharacterString.length, stateSoTNoBreak).nextBreak();
    if (next != singleCharacterString.length)     {
        return false;
    }
    return _indexOf(string, singleCharacterString, 0, string.length) >= 0;
}

bool StringCharacters::startsWith(Characters characters) {
    auto length = string.length;
    auto otherString = characters.string;
    if (otherString.isEmpty)     {
        return true;
    }
    return string.startsWith(otherString) && isGraphemeClusterBoundary(string, 0, length, otherString.length);
}

bool StringCharacters::endsWith(Characters characters) {
    auto length = string.length;
    auto otherString = characters.string;
    if (otherString.isEmpty)     {
        return true;
    }
    auto otherLength = otherString.length;
    auto start = string.length - otherLength;
    return start >= 0 && string.startsWith(otherString, start) && isGraphemeClusterBoundary(string, 0, length, start);
}

Characters StringCharacters::replaceAll(Characters pattern, Characters replacement) {
    return _rangeAll.replaceAll(pattern, replacement)?.source ?? this;
}

Characters StringCharacters::replaceFirst(Characters pattern, Characters replacement) {
    return _rangeAll.replaceFirst(pattern, replacement)?.source ?? this;
}

Iterable<Characters> StringCharacters::split(int maxParts, Characters pattern) {
    if (maxParts == 1 || string.isEmpty) {
        yield yield;
        this;
        return;
    }
    auto patternString = pattern.string;
    auto start = 0;
    if (patternString.isNotEmpty) {
        do {
            auto match = _indexOf(string, patternString, start, string.length);
            if ( < 0)             {
                            break;
            }
            yield yield;
            StringCharacters(string.substring(start, match));
            start = match + patternString.length;
            maxParts--;
        } while (maxParts != 1);
    } else {
        auto breaks = Breaks(string, 0, string.length, stateSoTNoBreak);
        do {
            auto match = breaks.nextBreak();
            if ( < 0)             {
                return;
            }
            yield yield;
            StringCharacters(string.substring(start, match));
            start = match;
            maxParts--;
        } while (maxParts != 1);
        if (start == string.length)         {
            return;
        }
    }
    yield yield;
    StringCharacters(string.substring(start));
}

bool StringCharacters::containsAll(Characters characters) {
    return _indexOf(string, characters.string, 0, string.length) >= 0;
}

Characters StringCharacters::skip(int count) {
    RangeError.checkNotNegative(count, "count");
    return _skip(count);
}

Characters StringCharacters::take(int count) {
    RangeError.checkNotNegative(count, "count");
    return _take(count);
}

Characters StringCharacters::getRange(int end, int start) {
    RangeError.checkNotNegative(start, "start");
    if (end == nullptr)     {
        return _skip(start);
    }
    if ( < start)     {
        ;
    }
    if (end == start)     {
        return Characters.empty;
    }
    if (start == 0)     {
        return _take(end);
    }
    if (string.isEmpty)     {
        return this;
    }
    auto breaks = Breaks(string, 0, string.length, stateSoTNoBreak);
    auto startIndex = _skipIndices(start, 0, breaks);
    if (startIndex == string.length)     {
        return Characters.empty;
    }
    auto endIndex = _skipIndices(end - start, start, breaks);
    return StringCharacters(string.substring(startIndex, endIndex));
}

Characters StringCharacters::characterAt(int position) {
    auto breaks = Breaks(string, 0, string.length, stateSoTNoBreak);
    auto start = 0;
    while (position > 0) {
        position--;
        start = breaks.nextBreak();
        if ( < 0)         {
            ;
        }
    }
    auto end = breaks.nextBreak();
    if ( < 0)     {
        ;
    }
    if (start == 0 && end == string.length)     {
        return this;
    }
    return StringCharacters(string.substring(start, end));
}

Characters StringCharacters::skipWhile(FunctionType test) {
    if (string.isNotEmpty) {
        auto stringLength = string.length;
        auto breaks = Breaks(string, 0, stringLength, stateSoTNoBreak);
        auto index = 0;
        auto startIndex = 0;
        while ((index = breaks.nextBreak()) >= 0) {
            if (!test(string.substring(startIndex, index))) {
                if (startIndex == 0)                 {
                    return this;
                }
                if (startIndex == stringLength)                 {
                    return Characters.empty;
                }
                return StringCharacters(string.substring(startIndex));
            }
            startIndex = index;
        }
    }
    return Characters.empty;
}

Characters StringCharacters::takeWhile(FunctionType test) {
    if (string.isNotEmpty) {
        auto breaks = Breaks(string, 0, string.length, stateSoTNoBreak);
        auto index = 0;
        auto endIndex = 0;
        while ((index = breaks.nextBreak()) >= 0) {
            if (!test(string.substring(endIndex, index))) {
                if (endIndex == 0)                 {
                    return Characters.empty;
                }
                return StringCharacters(string.substring(0, endIndex));
            }
            endIndex = index;
        }
    }
    return this;
}

Characters StringCharacters::where(FunctionType test) {
    auto string = super.where(test).join();
    if (string.isEmpty)     {
        return Characters.empty;
    }
    return StringCharacters(string);
}

Characters StringCharacters::+(Characters characters) {
    return StringCharacters(string + characters.string);
}

Characters StringCharacters::skipLast(int count) {
    RangeError.checkNotNegative(count, "count");
    if (count == 0)     {
        return this;
    }
    if (string.isNotEmpty) {
        auto breaks = BackBreaks(string, string.length, 0, stateEoTNoBreak);
        auto endIndex = string.length;
        while (count > 0) {
            auto index = breaks.nextBreak();
            if (index >= 0) {
                endIndex = index;
                count--;
            } else {
                return Characters.empty;
            }
        }
        if (endIndex > 0)         {
            return StringCharacters(string.substring(0, endIndex));
        }
    }
    return Characters.empty;
}

Characters StringCharacters::skipLastWhile(FunctionType test) {
    if (string.isNotEmpty) {
        auto breaks = BackBreaks(string, string.length, 0, stateEoTNoBreak);
        auto index = 0;
        auto end = string.length;
        while ((index = breaks.nextBreak()) >= 0) {
            if (!test(string.substring(index, end))) {
                if (end == string.length)                 {
                    return this;
                }
                return end == 0? Characters.empty : StringCharacters(string.substring(0, end));
            }
            end = index;
        }
    }
    return Characters.empty;
}

Characters StringCharacters::takeLast(int count) {
    RangeError.checkNotNegative(count, "count");
    if (count == 0)     {
        return Characters.empty;
    }
    if (string.isNotEmpty) {
        auto breaks = BackBreaks(string, string.length, 0, stateEoTNoBreak);
        auto startIndex = string.length;
        while (count > 0) {
            auto index = breaks.nextBreak();
            if (index >= 0) {
                startIndex = index;
                count--;
            } else {
                return this;
            }
        }
        if (startIndex > 0) {
            return StringCharacters(string.substring(startIndex));
        }
    }
    return this;
}

Characters StringCharacters::takeLastWhile(FunctionType test) {
    if (string.isNotEmpty) {
        auto breaks = BackBreaks(string, string.length, 0, stateEoTNoBreak);
        auto index = 0;
        auto start = string.length;
        while ((index = breaks.nextBreak()) >= 0) {
            if (!test(string.substring(index, start))) {
                if (start == string.length)                 {
                    return Characters.empty;
                }
                return StringCharacters(string.substring(start));
            }
            start = index;
        }
    }
    return this;
}

Characters StringCharacters::toLowerCase() {
    return StringCharacters(string.toLowerCase());
}

Characters StringCharacters::toUpperCase() {
    return StringCharacters(string.toUpperCase());
}

bool StringCharacters::==(Object other) {
    return other is Characters && string == other.string;
}

int StringCharacters::hashCode() {
    return string.hashCode;
}

String StringCharacters::toString() {
    return string;
}

CharacterRange StringCharacters::findFirst(Characters characters) {
    auto range = _rangeAll;
    if (range.collapseToFirst(characters))     {
        return range;
    }
    return nullptr;
}

CharacterRange StringCharacters::findLast(Characters characters) {
    auto range = _rangeAll;
    if (range.collapseToLast(characters))     {
        return range;
    }
    return nullptr;
}

StringCharacterRange StringCharacters::_rangeAll() {
    return StringCharacterRange._(string, 0, string.length);
}

int StringCharacters::_skipIndices(Breaks breaks, int count, int cursor) {
    if (count == 0 || cursor == string.length)     {
        return cursor;
    }
    breaks = Breaks(string, cursor, string.length, stateSoTNoBreak);
    do {
        auto nextBreak = breaks.nextBreak();
        if ( < 0)         {
                    break;
        }
        cursor = nextBreak;
    } while (--count > 0);
    return cursor;
}

Characters StringCharacters::_skip(int count) {
    auto start = _skipIndices(count, 0, nullptr);
    if (start == string.length)     {
        return Characters.empty;
    }
    return StringCharacters(string.substring(start));
}

Characters StringCharacters::_take(int count) {
    auto end = _skipIndices(count, 0, nullptr);
    if (end == string.length)     {
        return this;
    }
    return StringCharacters(string.substring(0, end));
}

StringCharacterRange::StringCharacterRange(String string) {
    {
        this._(string, 0, 0);
    }
}

void StringCharacterRange::at(int endIndex, int startIndex, String string) {
    RangeError.checkValidRange(startIndex, endIndex, string.length, "startIndex", "endIndex");
    return _expandRange(string, startIndex, endIndex ?? startIndex);
}

String StringCharacterRange::current() {
    return _currentCache ??= _string.substring(_start, _end);
}

bool StringCharacterRange::moveNext(int count) {
    return _advanceEnd(count, _end);
}

bool StringCharacterRange::moveBack(int count) {
    return _retractStart(count, _start);
}

Iterable<int> StringCharacterRange::utf16CodeUnits() {
    return _string.codeUnits.getRange(_start, _end);
}

Runes StringCharacterRange::runes() {
    return Runes(current);
}

CharacterRange StringCharacterRange::copy() {
    return StringCharacterRange._(_string, _start, _end);
}

void StringCharacterRange::collapseToEnd() {
    _move(_end, _end);
}

void StringCharacterRange::collapseToStart() {
    _move(_start, _start);
}

bool StringCharacterRange::dropFirst(int count) {
    RangeError.checkNotNegative(count, "count");
    if (_start == _end)     {
        return count == 0;
    }
    auto breaks = Breaks(_string, _start, _end, stateSoTNoBreak);
    while (count > 0) {
        auto nextBreak = breaks.nextBreak();
        if (nextBreak >= 0) {
            _start = nextBreak;
            _currentCache = nullptr;
            count--;
        } else {
            return false;
        }
    }
    return true;
}

bool StringCharacterRange::dropTo(Characters target) {
    if (_start == _end)     {
        return target.isEmpty;
    }
    auto targetString = target.string;
    auto index = _indexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(index + targetString.length, _end);
        return true;
    }
    return false;
}

bool StringCharacterRange::dropUntil(Characters target) {
    if (_start == _end)     {
        return target.isEmpty;
    }
    auto targetString = target.string;
    auto index = _indexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(index, _end);
        return true;
    }
    _move(_end, _end);
    return false;
}

void StringCharacterRange::dropWhile(FunctionType test) {
    if (_start == _end)     {
        return;
    }
    auto breaks = Breaks(_string, _start, _end, stateSoTNoBreak);
    auto cursor = _start;
    auto next = 0;
    while ((next = breaks.nextBreak()) >= 0) {
        if (!test(_string.substring(cursor, next))) {
                        break;
        }
        cursor = next;
    }
    _move(cursor, _end);
}

bool StringCharacterRange::dropLast(int count) {
    RangeError.checkNotNegative(count, "count");
    auto breaks = BackBreaks(_string, _end, _start, stateEoTNoBreak);
    while (count > 0) {
        auto nextBreak = breaks.nextBreak();
        if (nextBreak >= 0) {
            _end = nextBreak;
            _currentCache = nullptr;
            count--;
        } else {
            return false;
        }
    }
    return true;
}

bool StringCharacterRange::dropBackTo(Characters target) {
    if (_start == _end)     {
        return target.isEmpty;
    }
    auto targetString = target.string;
    auto index = _lastIndexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(_start, index);
        return true;
    }
    return false;
}

bool StringCharacterRange::dropBackUntil(Characters target) {
    if (_start == _end)     {
        return target.isEmpty;
    }
    auto targetString = target.string;
    auto index = _lastIndexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(_start, index + targetString.length);
        return true;
    }
    _move(_start, _start);
    return false;
}

void StringCharacterRange::dropBackWhile(FunctionType test) {
    if (_start == _end)     {
        return;
    }
    auto breaks = BackBreaks(_string, _end, _start, stateEoTNoBreak);
    auto cursor = _end;
    auto next = 0;
    while ((next = breaks.nextBreak()) >= 0) {
        if (!test(_string.substring(next, cursor))) {
                        break;
        }
        cursor = next;
    }
    _move(_start, cursor);
}

bool StringCharacterRange::expandNext(int count) {
    return _advanceEnd(count, _start);
}

bool StringCharacterRange::expandTo(Characters target) {
    auto targetString = target.string;
    auto index = _indexOf(_string, targetString, _end, _string.length);
    if (index >= 0) {
        _move(_start, index + targetString.length);
        return true;
    }
    return false;
}

void StringCharacterRange::expandWhile(FunctionType test) {
    auto breaks = _breaksFromEnd();
    auto cursor = _end;
    auto next = 0;
    while ((next = breaks.nextBreak()) >= 0) {
        if (!test(_string.substring(cursor, next))) {
                        break;
        }
        cursor = next;
    }
    _move(_start, cursor);
}

void StringCharacterRange::expandAll() {
    _move(_start, _string.length);
}

bool StringCharacterRange::expandBack(int count) {
    return _retractStart(count, _end);
}

bool StringCharacterRange::expandBackTo(Characters target) {
    auto targetString = target.string;
    auto index = _lastIndexOf(_string, targetString, 0, _start);
    if (index >= 0) {
        _move(index, _end);
        return true;
    }
    return false;
}

void StringCharacterRange::expandBackWhile(FunctionType test) {
    auto breaks = _backBreaksFromStart();
    auto cursor = _start;
    auto next = 0;
    while ((next = breaks.nextBreak()) >= 0) {
        if (!test(_string.substring(next, cursor))) {
            _move(cursor, _end);
            return;
        }
        cursor = next;
    }
    _move(0, _end);
}

bool StringCharacterRange::expandBackUntil(Characters target) {
    return _retractStartUntil(target.string, _end);
}

void StringCharacterRange::expandBackAll() {
    _move(0, _end);
}

bool StringCharacterRange::expandUntil(Characters target) {
    return _advanceEndUntil(target.string, _start);
}

bool StringCharacterRange::isEmpty() {
    return _start == _end;
}

bool StringCharacterRange::isNotEmpty() {
    return _start != _end;
}

bool StringCharacterRange::moveBackUntil(Characters target) {
    auto targetString = target.string;
    return _retractStartUntil(targetString, _start);
}

bool StringCharacterRange::collapseToFirst(Characters target) {
    return _moveNextPattern(target.string, _start, _end);
}

bool StringCharacterRange::collapseToLast(Characters target) {
    return _movePreviousPattern(target.string, _start, _end);
}

bool StringCharacterRange::moveUntil(Characters target) {
    auto targetString = target.string;
    return _advanceEndUntil(targetString, _end);
}

CharacterRange StringCharacterRange::replaceFirst(Characters pattern, Characters replacement) {
    auto patternString = pattern.string;
    auto replacementString = replacement.string;
    String replaced;
    if (patternString.isEmpty) {
        replaced = _string.replaceRange(_start, _start, replacementString);
    } else {
        auto index = _indexOf(_string, patternString, _start, _end);
        if (index >= 0) {
            replaced = _string.replaceRange(index, index + patternString.length, replacementString);
        } else {
            return nullptr;
        }
    }
    auto newEnd = replaced.length - _string.length + _end;
    return _expandRange(replaced, _start, newEnd);
}

CharacterRange StringCharacterRange::replaceAll(Characters pattern, Characters replacement) {
    auto patternString = pattern.string;
    auto replacementString = replacement.string;
    if (patternString.isEmpty) {
        auto replaced = _explodeReplace(_string, _start, _end, replacementString, replacementString);
        auto newEnd = replaced.length - (_string.length - _end);
        return _expandRange(replaced, _start, newEnd);
    }
    if (_start == _end)     {
        return nullptr;
    }
    auto start = 0;
    auto cursor = _start;
    StringBuffer buffer;
    while ((cursor = _indexOf(_string, patternString, cursor, _end)) >= 0) {
        ;
        cursor = patternString.length;
        start = cursor;
    }
    if (buffer == nullptr)     {
        return nullptr;
    }
    buffer.write(_string.substring(start));
    auto replaced = buffer.toString();
    auto newEnd = replaced.length - (_string.length - _end);
    return _expandRange(replaced, _start, newEnd);
}

CharacterRange StringCharacterRange::replaceRange(Characters replacement) {
    auto replacementString = replacement.string;
    auto resultString = _string.replaceRange(_start, _end, replacementString);
    return _expandRange(resultString, _start, _start + replacementString.length);
}

Characters StringCharacterRange::source() {
    return Characters(_string);
}

bool StringCharacterRange::startsWith(Characters characters) {
    return _startsWith(_start, _end, characters.string);
}

bool StringCharacterRange::endsWith(Characters characters) {
    return _endsWith(_start, _end, characters.string);
}

bool StringCharacterRange::isFollowedBy(Characters characters) {
    return _startsWith(_end, _string.length, characters.string);
}

bool StringCharacterRange::isPrecededBy(Characters characters) {
    return _endsWith(0, _start, characters.string);
}

bool StringCharacterRange::moveBackTo(Characters target) {
    auto targetString = target.string;
    auto index = _lastIndexOf(_string, targetString, 0, _start);
    if (index >= 0) {
        _move(index, index + targetString.length);
        return true;
    }
    return false;
}

bool StringCharacterRange::moveTo(Characters target) {
    auto targetString = target.string;
    auto index = _indexOf(_string, targetString, _end, _string.length);
    if (index >= 0) {
        _move(index, index + targetString.length);
        return true;
    }
    return false;
}

Characters StringCharacterRange::charactersAfter() {
    return StringCharacters(_string.substring(_end));
}

Characters StringCharacterRange::charactersBefore() {
    return StringCharacters(_string.substring(0, _start));
}

Characters StringCharacterRange::currentCharacters() {
    return StringCharacters(current);
}

void StringCharacterRange::moveBackAll() {
    _move(0, _start);
}

void StringCharacterRange::moveNextAll() {
    _move(_end, _string.length);
}

String StringCharacterRange::stringAfter() {
    return _string.substring(_end);
}

int StringCharacterRange::stringAfterLength() {
    return _string.length - _end;
}

String StringCharacterRange::stringBefore() {
    return _string.substring(0, _start);
}

int StringCharacterRange::stringBeforeLength() {
    return _start;
}

Iterable<CharacterRange> StringCharacterRange::split(int maxParts, Characters pattern) {
    if (maxParts == 1 || _start == _end) {
        yield yield;
        this;
        return;
    }
    auto patternString = pattern.string;
    auto start = _start;
    if (patternString.isNotEmpty) {
        do {
            auto match = _indexOf(_string, patternString, start, _end);
            if ( < 0)             {
                            break;
            }
            yield yield;
            StringCharacterRange._(_string, start, match);
            start = match + patternString.length;
            maxParts--;
        } while (maxParts != 1);
        yield yield;
        StringCharacterRange._(_string, start, _end);
    } else {
        auto breaks = Breaks(_string, _start, _end, stateSoTNoBreak);
        do {
            auto match = breaks.nextBreak();
            if ( < 0)             {
                return;
            }
            yield yield;
            StringCharacterRange._(_string, start, match);
            start = match;
            maxParts--;
        } while (maxParts != 1);
        if ( < _end) {
            yield yield;
            StringCharacterRange._(_string, start, _end);
        }
    }
}

void StringCharacterRange::_move(int end, int start) {
    _start = start;
    _end = end;
    _currentCache = nullptr;
}

Breaks StringCharacterRange::_breaksFromEnd() {
    return Breaks(_string, _end, _string.length, stateSoTNoBreak);
}

BackBreaks StringCharacterRange::_backBreaksFromStart() {
    return BackBreaks(_string, _start, 0, stateEoTNoBreak);
}

bool StringCharacterRange::_advanceEnd(int count, int newStart) {
    if (count > 0) {
        auto state = stateSoTNoBreak;
        auto index = _end;
        while ( < _string.length) {
            auto char = _string.codeUnitAt(index);
            auto category = categoryControl;
            auto nextIndex = index + 1;
            if (char & 0xFC00 != 0xD800) {
                category = low(char);
            } else             {
                if ( < _string.length) {
                auto nextChar = _string.codeUnitAt(nextIndex);
                if (nextChar & 0xFC00 == 0xDC00) {
                    nextIndex = 1;
                    category = high(char, nextChar);
                }
            }
;
            }            state = move(state, category);
            if (state & stateNoBreak == 0 && --count == 0) {
                _move(newStart, index);
                return true;
            }
            index = nextIndex;
        }
        _move(newStart, _string.length);
        return count == 1 && state != stateSoTNoBreak;
    } else     {
        if (count == 0) {
        _move(newStart, _end);
        return true;
    } else {
        ;
    }
;
    }}

bool StringCharacterRange::_moveNextPattern(int end, String patternString, int start) {
    auto offset = _indexOf(_string, patternString, start, end);
    if (offset >= 0) {
        _move(offset, offset + patternString.length);
        return true;
    }
    return false;
}

bool StringCharacterRange::_retractStart(int count, int newEnd) {
    RangeError.checkNotNegative(count, "count");
    auto breaks = _backBreaksFromStart();
    auto start = _start;
    while (count > 0) {
        auto nextBreak = breaks.nextBreak();
        if (nextBreak >= 0) {
            start = nextBreak;
        } else {
                        break;
        }
        count--;
    }
    _move(start, newEnd);
    return count == 0;
}

bool StringCharacterRange::_movePreviousPattern(int end, String patternString, int start) {
    auto offset = _lastIndexOf(_string, patternString, start, end);
    if (offset >= 0) {
        _move(offset, offset + patternString.length);
        return true;
    }
    return false;
}

bool StringCharacterRange::_retractStartUntil(int newEnd, String targetString) {
    auto index = _lastIndexOf(_string, targetString, 0, _start);
    if (index >= 0) {
        _move(index + targetString.length, newEnd);
        return true;
    }
    _move(0, newEnd);
    return false;
}

bool StringCharacterRange::_advanceEndUntil(int newStart, String targetString) {
    auto index = _indexOf(_string, targetString, _end, _string.length);
    if (index >= 0) {
        _move(newStart, index);
        return true;
    }
    _move(newStart, _string.length);
    return false;
}

StringCharacterRange StringCharacterRange::_expandRange(int end, int start, String string) {
    start = previousBreak(string, 0, string.length, start);
    if (end != start) {
        end = nextBreak(string, 0, string.length, end);
    }
    return StringCharacterRange._(string, start, end);
}

bool StringCharacterRange::_endsWith(int end, int start, String string) {
    auto length = string.length;
    auto stringStart = end - length;
    return stringStart >= start && _string.startsWith(string, stringStart) && isGraphemeClusterBoundary(_string, start, end, stringStart);
}

bool StringCharacterRange::_startsWith(int end, int start, String string) {
    auto length = string.length;
    auto stringEnd = start + length;
    return stringEnd <= end && _string.startsWith(string, start) && isGraphemeClusterBoundary(_string, start, end, stringEnd);
}

String _explodeReplace(int end, String internalReplacement, String outerReplacement, int start, String string) {
    if (start == end) {
        return string.replaceRange(start, start, outerReplacement);
    }
    auto buffer = StringBuffer(string.substring(0, start));
    auto breaks = Breaks(string, start, end, stateSoTNoBreak);
    auto index = 0;
    auto replacement = outerReplacement;
    while ((index = breaks.nextBreak()) >= 0) {
        ;
        start = index;
        replacement = internalReplacement;
    }
    ;
    return buffer.toString();
}

int _indexOf(int end, String pattern, String source, int start) {
    auto patternLength = pattern.length;
    if (patternLength == 0)     {
        return start;
    }
    auto realEnd = end - patternLength;
    if ( < start)     {
        return -1;
    }
    auto rest = source.length - realEnd;
    if (rest <= (realEnd - start) * 2) {
        auto index = 0;
        while ( < realEnd && (index = source.indexOf(pattern, start)) >= 0) {
            if (index > realEnd)             {
                return -1;
            }
            if (isGraphemeClusterBoundary(source, start, end, index) && isGraphemeClusterBoundary(source, start, end, index + patternLength)) {
                return index;
            }
            start = index + 1;
        }
        return -1;
    }
    return _gcIndexOf(source, pattern, start, end);
}

int _gcIndexOf(int end, String pattern, String source, int start) {
    auto breaks = Breaks(source, start, end, stateSoT);
    auto index = 0;
    while ((index = breaks.nextBreak()) >= 0) {
        auto endIndex = index + pattern.length;
        if (endIndex > end)         {
                    break;
        }
        if (source.startsWith(pattern, index) && isGraphemeClusterBoundary(source, start, end, endIndex)) {
            return index;
        }
    }
    return -1;
}

int _lastIndexOf(int end, String pattern, String source, int start) {
    auto patternLength = pattern.length;
    if (patternLength == 0)     {
        return end;
    }
    auto realEnd = end - patternLength;
    if ( < start)     {
        return -1;
    }
    if (realEnd * 2 > start) {
        auto index = 0;
        while (realEnd >= start && (index = source.lastIndexOf(pattern, realEnd)) >= 0) {
            if ( < start)             {
                return -1;
            }
            if (isGraphemeClusterBoundary(source, start, end, index) && isGraphemeClusterBoundary(source, start, end, index + patternLength)) {
                return index;
            }
            realEnd = index - 1;
        }
        return -1;
    }
    return _gcLastIndexOf(source, pattern, start, end);
}

int _gcLastIndexOf(int end, String pattern, String source, int start) {
    auto breaks = BackBreaks(source, end, start, stateEoT);
    auto index = 0;
    while ((index = breaks.nextBreak()) >= 0) {
        auto startIndex = index - pattern.length;
        if ( < start)         {
                    break;
        }
        if (source.startsWith(pattern, startIndex) && isGraphemeClusterBoundary(source, start, end, startIndex)) {
            return startIndex;
        }
    }
    return -1;
}
