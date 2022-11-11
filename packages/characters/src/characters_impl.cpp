#include "characters_impl.hpp"
CharacterRange StringCharactersCls::iterator() {
    return StringCharacterRangeCls->_(stringValue, 0, 0);
}

CharacterRange StringCharactersCls::iteratorAtEnd() {
    return StringCharacterRangeCls->_(stringValue, stringValue->length, stringValue->length);
}

String StringCharactersCls::first() {
    return stringValue->isEmpty()?  : stringValue->substring(0, make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak)->nextBreak());
}

String StringCharactersCls::last() {
    return stringValue->isEmpty()?  : stringValue->substring(make<BackBreaksCls>(stringValue, stringValue->length, 0, stateEoTNoBreak)->nextBreak());
}

String StringCharactersCls::single() {
    if (stringValue->isEmpty())     {
        ;
    }
    auto firstEnd = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak)->nextBreak();
    if (firstEnd == stringValue->length)     {
        return stringValue;
    }
    ;
}

bool StringCharactersCls::isEmpty() {
    return stringValue->isEmpty();
}

bool StringCharactersCls::isNotEmpty() {
    return stringValue->isNotEmpty();
}

int StringCharactersCls::length() {
    if (stringValue->isEmpty())     {
        return 0;
    }
    auto brk = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak);
    auto length = 0;
    while (brk->nextBreak() >= 0) {
        length++;
    }
    return length;
}

Iterable<T> StringCharactersCls::whereTypetemplate<typename T> () {
    Iterable<Object> self = this;
    if (is<Iterable<T>>(self)) {
        return as<IterableCls>(self)-><T>map([=] (Unknown  x)         {
            x;
        });
    }
    return <T>empty();
}

String StringCharactersCls::join(String separator) {
    if (separator == __s(""))     {
        return stringValue;
    }
    return _explodeReplace(stringValue, 0, stringValue->length, separator, __s(""));
}

String StringCharactersCls::lastWhere(String orElse() , bool test(String element) ) {
    auto cursor = stringValue->length;
    auto brk = make<BackBreaksCls>(stringValue, cursor, 0, stateEoTNoBreak);
    auto next = 0;
    while ((next = brk->nextBreak()) >= 0) {
        auto current = stringValue->substring(next, cursor);
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

String StringCharactersCls::elementAt(int index) {
    RangeErrorCls->checkNotNegative(index, __s("index"));
    auto count = 0;
    if (stringValue->isNotEmpty()) {
        auto breaks = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak);
        auto start = 0;
        auto end = 0;
        while ((end = breaks->nextBreak()) >= 0) {
            if (count == index)             {
                return stringValue->substring(start, end);
            }
            count++;
            start = end;
        }
    }
    ;
}

bool StringCharactersCls::contains(Object singleCharacterString) {
    if (!is<String>(singleCharacterString))     {
        return false;
    }
    if (singleCharacterString->isEmpty)     {
        return false;
    }
    auto next = make<BreaksCls>(singleCharacterString, 0, singleCharacterString->length, stateSoTNoBreak)->nextBreak();
    if (next != singleCharacterString->length)     {
        return false;
    }
    return _indexOf(stringValue, singleCharacterString, 0, stringValue->length) >= 0;
}

bool StringCharactersCls::startsWith(Characters characters) {
    auto length = stringValue->length;
    auto otherString = characters->stringValue;
    if (otherString->isEmpty())     {
        return true;
    }
    return stringValue->startsWith(otherString) && isGraphemeClusterBoundary(stringValue, 0, length, otherString->length);
}

bool StringCharactersCls::endsWith(Characters characters) {
    auto length = stringValue->length;
    auto otherString = characters->stringValue;
    if (otherString->isEmpty())     {
        return true;
    }
    auto otherLength = otherString->length;
    auto start = stringValue->length - otherLength;
    return start >= 0 && stringValue->startsWith(otherString, start) && isGraphemeClusterBoundary(stringValue, 0, length, start);
}

Characters StringCharactersCls::replaceAll(Characters pattern, Characters replacement) {
    return _rangeAll()->replaceAll(pattern, replacement)?->source or this;
}

Characters StringCharactersCls::replaceFirst(Characters pattern, Characters replacement) {
    return _rangeAll()->replaceFirst(pattern, replacement)?->source or this;
}

Iterable<Characters> StringCharactersCls::split(int maxParts, Characters pattern) {
    if (maxParts == 1 || stringValue->isEmpty()) {
        yield yield;
        this;
        return;
    }
    auto patternString = pattern->stringValue;
    auto start = 0;
    if (patternString->isNotEmpty()) {
        do {
            auto match = _indexOf(stringValue, patternString, start, stringValue->length);
            if ( < 0)             {
                            break;
            }
            yield yield;
            make<StringCharactersCls>(stringValue->substring(start, match));
            start = match + patternString->length;
            maxParts--;
        } while (maxParts != 1);
    } else {
        auto breaks = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak);
        do {
            auto match = breaks->nextBreak();
            if ( < 0)             {
                return;
            }
            yield yield;
            make<StringCharactersCls>(stringValue->substring(start, match));
            start = match;
            maxParts--;
        } while (maxParts != 1);
        if (start == stringValue->length)         {
            return;
        }
    }
    yield yield;
    make<StringCharactersCls>(stringValue->substring(start));
}

bool StringCharactersCls::containsAll(Characters characters) {
    return _indexOf(stringValue, characters->stringValue, 0, stringValue->length) >= 0;
}

Characters StringCharactersCls::skip(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    return _skip(count);
}

Characters StringCharactersCls::take(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    return _take(count);
}

Characters StringCharactersCls::getRange(int end, int start) {
    RangeErrorCls->checkNotNegative(start, __s("start"));
    if (end == nullptr)     {
        return _skip(start);
    }
    if ( < start)     {
        ;
    }
    if (end == start)     {
        return CharactersCls::empty;
    }
    if (start == 0)     {
        return _take(end);
    }
    if (stringValue->isEmpty())     {
        return this;
    }
    auto breaks = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak);
    auto startIndex = _skipIndices(start, 0, breaks);
    if (startIndex == stringValue->length)     {
        return CharactersCls::empty;
    }
    auto endIndex = _skipIndices(end - start, start, breaks);
    return make<StringCharactersCls>(stringValue->substring(startIndex, endIndex));
}

Characters StringCharactersCls::characterAt(int position) {
    auto breaks = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak);
    auto start = 0;
    while (position > 0) {
        position--;
        start = breaks->nextBreak();
        if ( < 0)         {
            ;
        }
    }
    auto end = breaks->nextBreak();
    if ( < 0)     {
        ;
    }
    if (start == 0 && end == stringValue->length)     {
        return this;
    }
    return make<StringCharactersCls>(stringValue->substring(start, end));
}

Characters StringCharactersCls::skipWhile(bool test(String ) ) {
    if (stringValue->isNotEmpty()) {
        auto stringLength = stringValue->length;
        auto breaks = make<BreaksCls>(stringValue, 0, stringLength, stateSoTNoBreak);
        auto index = 0;
        auto startIndex = 0;
        while ((index = breaks->nextBreak()) >= 0) {
            if (!test(stringValue->substring(startIndex, index))) {
                if (startIndex == 0)                 {
                    return this;
                }
                if (startIndex == stringLength)                 {
                    return CharactersCls::empty;
                }
                return make<StringCharactersCls>(stringValue->substring(startIndex));
            }
            startIndex = index;
        }
    }
    return CharactersCls::empty;
}

Characters StringCharactersCls::takeWhile(bool test(String ) ) {
    if (stringValue->isNotEmpty()) {
        auto breaks = make<BreaksCls>(stringValue, 0, stringValue->length, stateSoTNoBreak);
        auto index = 0;
        auto endIndex = 0;
        while ((index = breaks->nextBreak()) >= 0) {
            if (!test(stringValue->substring(endIndex, index))) {
                if (endIndex == 0)                 {
                    return CharactersCls::empty;
                }
                return make<StringCharactersCls>(stringValue->substring(0, endIndex));
            }
            endIndex = index;
        }
    }
    return this;
}

Characters StringCharactersCls::where(bool test(String ) ) {
    auto string = super->where(test)->join();
    if (stringValue->isEmpty)     {
        return CharactersCls::empty;
    }
    return make<StringCharactersCls>(stringValue);
}

Characters StringCharactersCls::+(Characters characters) {
    return make<StringCharactersCls>(stringValue + characters->stringValue);
}

Characters StringCharactersCls::skipLast(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    if (count == 0)     {
        return this;
    }
    if (stringValue->isNotEmpty()) {
        auto breaks = make<BackBreaksCls>(stringValue, stringValue->length, 0, stateEoTNoBreak);
        auto endIndex = stringValue->length;
        while (count > 0) {
            auto index = breaks->nextBreak();
            if (index >= 0) {
                endIndex = index;
                count--;
            } else {
                return CharactersCls::empty;
            }
        }
        if (endIndex > 0)         {
            return make<StringCharactersCls>(stringValue->substring(0, endIndex));
        }
    }
    return CharactersCls::empty;
}

Characters StringCharactersCls::skipLastWhile(bool test(String ) ) {
    if (stringValue->isNotEmpty()) {
        auto breaks = make<BackBreaksCls>(stringValue, stringValue->length, 0, stateEoTNoBreak);
        auto index = 0;
        auto end = stringValue->length;
        while ((index = breaks->nextBreak()) >= 0) {
            if (!test(stringValue->substring(index, end))) {
                if (end == stringValue->length)                 {
                    return this;
                }
                return end == 0? CharactersCls::empty : make<StringCharactersCls>(stringValue->substring(0, end));
            }
            end = index;
        }
    }
    return CharactersCls::empty;
}

Characters StringCharactersCls::takeLast(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    if (count == 0)     {
        return CharactersCls::empty;
    }
    if (stringValue->isNotEmpty()) {
        auto breaks = make<BackBreaksCls>(stringValue, stringValue->length, 0, stateEoTNoBreak);
        auto startIndex = stringValue->length;
        while (count > 0) {
            auto index = breaks->nextBreak();
            if (index >= 0) {
                startIndex = index;
                count--;
            } else {
                return this;
            }
        }
        if (startIndex > 0) {
            return make<StringCharactersCls>(stringValue->substring(startIndex));
        }
    }
    return this;
}

Characters StringCharactersCls::takeLastWhile(bool test(String ) ) {
    if (stringValue->isNotEmpty()) {
        auto breaks = make<BackBreaksCls>(stringValue, stringValue->length, 0, stateEoTNoBreak);
        auto index = 0;
        auto start = stringValue->length;
        while ((index = breaks->nextBreak()) >= 0) {
            if (!test(stringValue->substring(index, start))) {
                if (start == stringValue->length)                 {
                    return CharactersCls::empty;
                }
                return make<StringCharactersCls>(stringValue->substring(start));
            }
            start = index;
        }
    }
    return this;
}

Characters StringCharactersCls::toLowerCase() {
    return make<StringCharactersCls>(stringValue->toLowerCase());
}

Characters StringCharactersCls::toUpperCase() {
    return make<StringCharactersCls>(stringValue->toUpperCase());
}

bool StringCharactersCls::==(Object other) {
    return is<Characters>(other) && stringValue == other->stringValue;
}

int StringCharactersCls::hashCode() {
    return stringValue->hashCode;
}

String StringCharactersCls::toString() {
    return stringValue;
}

CharacterRange StringCharactersCls::findFirst(Characters characters) {
    auto range = _rangeAll();
    if (range->collapseToFirst(characters))     {
        return range;
    }
    return nullptr;
}

CharacterRange StringCharactersCls::findLast(Characters characters) {
    auto range = _rangeAll();
    if (range->collapseToLast(characters))     {
        return range;
    }
    return nullptr;
}

StringCharacterRange StringCharactersCls::_rangeAll() {
    return StringCharacterRangeCls->_(stringValue, 0, stringValue->length);
}

int StringCharactersCls::_skipIndices(Breaks breaks, int count, int cursor) {
    if (count == 0 || cursor == stringValue->length)     {
        return cursor;
    }
    breaks = make<BreaksCls>(stringValue, cursor, stringValue->length, stateSoTNoBreak);
    do {
        auto nextBreak = breaks->nextBreak();
        if ( < 0)         {
                    break;
        }
        cursor = nextBreak;
    } while (--count > 0);
    return cursor;
}

Characters StringCharactersCls::_skip(int count) {
    auto start = _skipIndices(count, 0, nullptr);
    if (start == stringValue->length)     {
        return CharactersCls::empty;
    }
    return make<StringCharactersCls>(stringValue->substring(start));
}

Characters StringCharactersCls::_take(int count) {
    auto end = _skipIndices(count, 0, nullptr);
    if (end == stringValue->length)     {
        return this;
    }
    return make<StringCharactersCls>(stringValue->substring(0, end));
}

StringCharacterRangeCls::StringCharacterRangeCls(String stringValue) {
    {
        this->_(stringValue, 0, 0);
    }
}

void StringCharacterRangeCls::at(int endIndex, int startIndex, String stringValue) {
    RangeErrorCls->checkValidRange(startIndex, endIndex, stringValue->length, __s("startIndex"), __s("endIndex"));
    return _expandRange(stringValue, startIndex, endIndex or startIndex);
}

String StringCharacterRangeCls::current() {
    return _currentCache ??= _string->substring(_start, _end);
}

bool StringCharacterRangeCls::moveNext(int count) {
    return _advanceEnd(count, _end);
}

bool StringCharacterRangeCls::moveBack(int count) {
    return _retractStart(count, _start);
}

Iterable<int> StringCharacterRangeCls::utf16CodeUnits() {
    return _string->codeUnits->getRange(_start, _end);
}

Runes StringCharacterRangeCls::runes() {
    return make<RunesCls>(current());
}

CharacterRange StringCharacterRangeCls::copy() {
    return StringCharacterRangeCls->_(_string, _start, _end);
}

void StringCharacterRangeCls::collapseToEnd() {
    _move(_end, _end);
}

void StringCharacterRangeCls::collapseToStart() {
    _move(_start, _start);
}

bool StringCharacterRangeCls::dropFirst(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    if (_start == _end)     {
        return count == 0;
    }
    auto breaks = make<BreaksCls>(_string, _start, _end, stateSoTNoBreak);
    while (count > 0) {
        auto nextBreak = breaks->nextBreak();
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

bool StringCharacterRangeCls::dropTo(Characters target) {
    if (_start == _end)     {
        return target->isEmpty;
    }
    auto targetString = target->stringValue;
    auto index = _indexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(index + targetString->length, _end);
        return true;
    }
    return false;
}

bool StringCharacterRangeCls::dropUntil(Characters target) {
    if (_start == _end)     {
        return target->isEmpty;
    }
    auto targetString = target->stringValue;
    auto index = _indexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(index, _end);
        return true;
    }
    _move(_end, _end);
    return false;
}

void StringCharacterRangeCls::dropWhile(bool test(String ) ) {
    if (_start == _end)     {
        return;
    }
    auto breaks = make<BreaksCls>(_string, _start, _end, stateSoTNoBreak);
    auto cursor = _start;
    auto next = 0;
    while ((next = breaks->nextBreak()) >= 0) {
        if (!test(_string->substring(cursor, next))) {
                        break;
        }
        cursor = next;
    }
    _move(cursor, _end);
}

bool StringCharacterRangeCls::dropLast(int count) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    auto breaks = make<BackBreaksCls>(_string, _end, _start, stateEoTNoBreak);
    while (count > 0) {
        auto nextBreak = breaks->nextBreak();
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

bool StringCharacterRangeCls::dropBackTo(Characters target) {
    if (_start == _end)     {
        return target->isEmpty;
    }
    auto targetString = target->stringValue;
    auto index = _lastIndexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(_start, index);
        return true;
    }
    return false;
}

bool StringCharacterRangeCls::dropBackUntil(Characters target) {
    if (_start == _end)     {
        return target->isEmpty;
    }
    auto targetString = target->stringValue;
    auto index = _lastIndexOf(_string, targetString, _start, _end);
    if (index >= 0) {
        _move(_start, index + targetString->length);
        return true;
    }
    _move(_start, _start);
    return false;
}

void StringCharacterRangeCls::dropBackWhile(bool test(String ) ) {
    if (_start == _end)     {
        return;
    }
    auto breaks = make<BackBreaksCls>(_string, _end, _start, stateEoTNoBreak);
    auto cursor = _end;
    auto next = 0;
    while ((next = breaks->nextBreak()) >= 0) {
        if (!test(_string->substring(next, cursor))) {
                        break;
        }
        cursor = next;
    }
    _move(_start, cursor);
}

bool StringCharacterRangeCls::expandNext(int count) {
    return _advanceEnd(count, _start);
}

bool StringCharacterRangeCls::expandTo(Characters target) {
    auto targetString = target->stringValue;
    auto index = _indexOf(_string, targetString, _end, _string->length);
    if (index >= 0) {
        _move(_start, index + targetString->length);
        return true;
    }
    return false;
}

void StringCharacterRangeCls::expandWhile(bool test(String character) ) {
    auto breaks = _breaksFromEnd();
    auto cursor = _end;
    auto next = 0;
    while ((next = breaks->nextBreak()) >= 0) {
        if (!test(_string->substring(cursor, next))) {
                        break;
        }
        cursor = next;
    }
    _move(_start, cursor);
}

void StringCharacterRangeCls::expandAll() {
    _move(_start, _string->length);
}

bool StringCharacterRangeCls::expandBack(int count) {
    return _retractStart(count, _end);
}

bool StringCharacterRangeCls::expandBackTo(Characters target) {
    auto targetString = target->stringValue;
    auto index = _lastIndexOf(_string, targetString, 0, _start);
    if (index >= 0) {
        _move(index, _end);
        return true;
    }
    return false;
}

void StringCharacterRangeCls::expandBackWhile(bool test(String character) ) {
    auto breaks = _backBreaksFromStart();
    auto cursor = _start;
    auto next = 0;
    while ((next = breaks->nextBreak()) >= 0) {
        if (!test(_string->substring(next, cursor))) {
            _move(cursor, _end);
            return;
        }
        cursor = next;
    }
    _move(0, _end);
}

bool StringCharacterRangeCls::expandBackUntil(Characters target) {
    return _retractStartUntil(target->stringValue, _end);
}

void StringCharacterRangeCls::expandBackAll() {
    _move(0, _end);
}

bool StringCharacterRangeCls::expandUntil(Characters target) {
    return _advanceEndUntil(target->stringValue, _start);
}

bool StringCharacterRangeCls::isEmpty() {
    return _start == _end;
}

bool StringCharacterRangeCls::isNotEmpty() {
    return _start != _end;
}

bool StringCharacterRangeCls::moveBackUntil(Characters target) {
    auto targetString = target->stringValue;
    return _retractStartUntil(targetString, _start);
}

bool StringCharacterRangeCls::collapseToFirst(Characters target) {
    return _moveNextPattern(target->stringValue, _start, _end);
}

bool StringCharacterRangeCls::collapseToLast(Characters target) {
    return _movePreviousPattern(target->stringValue, _start, _end);
}

bool StringCharacterRangeCls::moveUntil(Characters target) {
    auto targetString = target->stringValue;
    return _advanceEndUntil(targetString, _end);
}

CharacterRange StringCharacterRangeCls::replaceFirst(Characters pattern, Characters replacement) {
    auto patternString = pattern->stringValue;
    auto replacementString = replacement->stringValue;
    String replaced;
    if (patternString->isEmpty()) {
        replaced = _string->replaceRange(_start, _start, replacementString);
    } else {
        auto index = _indexOf(_string, patternString, _start, _end);
        if (index >= 0) {
            replaced = _string->replaceRange(index, index + patternString->length, replacementString);
        } else {
            return nullptr;
        }
    }
    auto newEnd = replaced->length - _string->length + _end;
    return _expandRange(replaced, _start, newEnd);
}

CharacterRange StringCharacterRangeCls::replaceAll(Characters pattern, Characters replacement) {
    auto patternString = pattern->stringValue;
    auto replacementString = replacement->stringValue;
    if (patternString->isEmpty()) {
        auto replaced = _explodeReplace(_string, _start, _end, replacementString, replacementString);
        auto newEnd = replaced->length - (_string->length - _end);
        return _expandRange(replaced, _start, newEnd);
    }
    if (_start == _end)     {
        return nullptr;
    }
    auto start = 0;
    auto cursor = _start;
    StringBuffer buffer;
    while ((cursor = _indexOf(_string, patternString, cursor, _end)) >= 0) {
            auto _c1 = (buffer ??= make<StringBufferCls>());    _c1.auto _c2 = write(_string->substring(start, cursor));    _c2.write(replacementString);    _c2;_c1;
        cursor = patternString->length;
        start = cursor;
    }
    if (buffer == nullptr)     {
        return nullptr;
    }
    buffer->write(_string->substring(start));
    auto replaced = buffer->toString();
    auto newEnd = replaced->length - (_string->length - _end);
    return _expandRange(replaced, _start, newEnd);
}

CharacterRange StringCharacterRangeCls::replaceRange(Characters replacement) {
    auto replacementString = replacement->stringValue;
    auto resultString = _string->replaceRange(_start, _end, replacementString);
    return _expandRange(resultString, _start, _start + replacementString->length);
}

Characters StringCharacterRangeCls::source() {
    return make<CharactersCls>(_string);
}

bool StringCharacterRangeCls::startsWith(Characters characters) {
    return _startsWith(_start, _end, characters->stringValue);
}

bool StringCharacterRangeCls::endsWith(Characters characters) {
    return _endsWith(_start, _end, characters->stringValue);
}

bool StringCharacterRangeCls::isFollowedBy(Characters characters) {
    return _startsWith(_end, _string->length, characters->stringValue);
}

bool StringCharacterRangeCls::isPrecededBy(Characters characters) {
    return _endsWith(0, _start, characters->stringValue);
}

bool StringCharacterRangeCls::moveBackTo(Characters target) {
    auto targetString = target->stringValue;
    auto index = _lastIndexOf(_string, targetString, 0, _start);
    if (index >= 0) {
        _move(index, index + targetString->length);
        return true;
    }
    return false;
}

bool StringCharacterRangeCls::moveTo(Characters target) {
    auto targetString = target->stringValue;
    auto index = _indexOf(_string, targetString, _end, _string->length);
    if (index >= 0) {
        _move(index, index + targetString->length);
        return true;
    }
    return false;
}

Characters StringCharacterRangeCls::charactersAfter() {
    return make<StringCharactersCls>(_string->substring(_end));
}

Characters StringCharacterRangeCls::charactersBefore() {
    return make<StringCharactersCls>(_string->substring(0, _start));
}

Characters StringCharacterRangeCls::currentCharacters() {
    return make<StringCharactersCls>(current());
}

void StringCharacterRangeCls::moveBackAll() {
    _move(0, _start);
}

void StringCharacterRangeCls::moveNextAll() {
    _move(_end, _string->length);
}

String StringCharacterRangeCls::stringAfter() {
    return _string->substring(_end);
}

int StringCharacterRangeCls::stringAfterLength() {
    return _string->length - _end;
}

String StringCharacterRangeCls::stringBefore() {
    return _string->substring(0, _start);
}

int StringCharacterRangeCls::stringBeforeLength() {
    return _start;
}

Iterable<CharacterRange> StringCharacterRangeCls::split(int maxParts, Characters pattern) {
    if (maxParts == 1 || _start == _end) {
        yield yield;
        this;
        return;
    }
    auto patternString = pattern->stringValue;
    auto start = _start;
    if (patternString->isNotEmpty()) {
        do {
            auto match = _indexOf(_string, patternString, start, _end);
            if ( < 0)             {
                            break;
            }
            yield yield;
            StringCharacterRangeCls->_(_string, start, match);
            start = match + patternString->length;
            maxParts--;
        } while (maxParts != 1);
        yield yield;
        StringCharacterRangeCls->_(_string, start, _end);
    } else {
        auto breaks = make<BreaksCls>(_string, _start, _end, stateSoTNoBreak);
        do {
            auto match = breaks->nextBreak();
            if ( < 0)             {
                return;
            }
            yield yield;
            StringCharacterRangeCls->_(_string, start, match);
            start = match;
            maxParts--;
        } while (maxParts != 1);
        if ( < _end) {
            yield yield;
            StringCharacterRangeCls->_(_string, start, _end);
        }
    }
}

void StringCharacterRangeCls::_move(int end, int start) {
    _start = start;
    _end = end;
    _currentCache = nullptr;
}

Breaks StringCharacterRangeCls::_breaksFromEnd() {
    return make<BreaksCls>(_string, _end, _string->length, stateSoTNoBreak);
}

BackBreaks StringCharacterRangeCls::_backBreaksFromStart() {
    return make<BackBreaksCls>(_string, _start, 0, stateEoTNoBreak);
}

bool StringCharacterRangeCls::_advanceEnd(int count, int newStart) {
    if (count > 0) {
        auto state = stateSoTNoBreak;
        auto index = _end;
        while ( < _string->length) {
            auto char = _string->codeUnitAt(index);
            auto category = categoryControl;
            auto nextIndex = index + 1;
            if (char & 0xFC00 != 0xD800) {
                category = low(char);
            } else             {
                if ( < _string->length) {
                auto nextChar = _string->codeUnitAt(nextIndex);
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
        _move(newStart, _string->length);
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

bool StringCharacterRangeCls::_moveNextPattern(int end, String patternString, int start) {
    auto offset = _indexOf(_string, patternString, start, end);
    if (offset >= 0) {
        _move(offset, offset + patternString->length);
        return true;
    }
    return false;
}

bool StringCharacterRangeCls::_retractStart(int count, int newEnd) {
    RangeErrorCls->checkNotNegative(count, __s("count"));
    auto breaks = _backBreaksFromStart();
    auto start = _start;
    while (count > 0) {
        auto nextBreak = breaks->nextBreak();
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

bool StringCharacterRangeCls::_movePreviousPattern(int end, String patternString, int start) {
    auto offset = _lastIndexOf(_string, patternString, start, end);
    if (offset >= 0) {
        _move(offset, offset + patternString->length);
        return true;
    }
    return false;
}

bool StringCharacterRangeCls::_retractStartUntil(int newEnd, String targetString) {
    auto index = _lastIndexOf(_string, targetString, 0, _start);
    if (index >= 0) {
        _move(index + targetString->length, newEnd);
        return true;
    }
    _move(0, newEnd);
    return false;
}

bool StringCharacterRangeCls::_advanceEndUntil(int newStart, String targetString) {
    auto index = _indexOf(_string, targetString, _end, _string->length);
    if (index >= 0) {
        _move(newStart, index);
        return true;
    }
    _move(newStart, _string->length);
    return false;
}

StringCharacterRange StringCharacterRangeCls::_expandRange(int end, int start, String stringValue) {
    start = previousBreak(stringValue, 0, stringValue->length, start);
    if (end != start) {
        end = nextBreak(stringValue, 0, stringValue->length, end);
    }
    return StringCharacterRangeCls->_(stringValue, start, end);
}

bool StringCharacterRangeCls::_endsWith(int end, int start, String stringValue) {
    auto length = stringValue->length;
    auto stringStart = end - length;
    return stringStart >= start && _string->startsWith(stringValue, stringStart) && isGraphemeClusterBoundary(_string, start, end, stringStart);
}

bool StringCharacterRangeCls::_startsWith(int end, int start, String stringValue) {
    auto length = stringValue->length;
    auto stringEnd = start + length;
    return stringEnd <= end && _string->startsWith(stringValue, start) && isGraphemeClusterBoundary(_string, start, end, stringEnd);
}

String _explodeReplace(int end, String internalReplacement, String outerReplacement, int start, String stringValue) {
    if (start == end) {
        return stringValue->replaceRange(start, start, outerReplacement);
    }
    auto buffer = make<StringBufferCls>(stringValue->substring(0, start));
    auto breaks = make<BreaksCls>(stringValue, start, end, stateSoTNoBreak);
    auto index = 0;
    auto replacement = outerReplacement;
    while ((index = breaks->nextBreak()) >= 0) {
            auto _c1 = buffer;    _c1.auto _c2 = write(replacement);    _c2.write(stringValue->substring(start, index));    _c2;_c1;
        start = index;
        replacement = internalReplacement;
    }
    auto _c3 = buffer;_c3.auto _c4 = write(outerReplacement);_c4.write(stringValue->substring(end));_c4;_c3;
    return buffer->toString();
}

int _indexOf(int end, String pattern, String source, int start) {
    auto patternLength = pattern->length;
    if (patternLength == 0)     {
        return start;
    }
    auto realEnd = end - patternLength;
    if ( < start)     {
        return -1;
    }
    auto rest = source->length - realEnd;
    if (rest <= (realEnd - start) * 2) {
        auto index = 0;
        while ( < realEnd && (index = source->indexOf(pattern, start)) >= 0) {
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
    auto breaks = make<BreaksCls>(source, start, end, stateSoT);
    auto index = 0;
    while ((index = breaks->nextBreak()) >= 0) {
        auto endIndex = index + pattern->length;
        if (endIndex > end)         {
                    break;
        }
        if (source->startsWith(pattern, index) && isGraphemeClusterBoundary(source, start, end, endIndex)) {
            return index;
        }
    }
    return -1;
}

int _lastIndexOf(int end, String pattern, String source, int start) {
    auto patternLength = pattern->length;
    if (patternLength == 0)     {
        return end;
    }
    auto realEnd = end - patternLength;
    if ( < start)     {
        return -1;
    }
    if (realEnd * 2 > start) {
        auto index = 0;
        while (realEnd >= start && (index = source->lastIndexOf(pattern, realEnd)) >= 0) {
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
    auto breaks = make<BackBreaksCls>(source, end, start, stateEoT);
    auto index = 0;
    while ((index = breaks->nextBreak()) >= 0) {
        auto startIndex = index - pattern->length;
        if ( < start)         {
                    break;
        }
        if (source->startsWith(pattern, startIndex) && isGraphemeClusterBoundary(source, start, end, startIndex)) {
            return startIndex;
        }
    }
    return -1;
}
