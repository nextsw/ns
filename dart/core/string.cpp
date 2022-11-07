#include "string.hpp"
RuneIterator Runes::iterator() {
    return RuneIterator(string);
}

int Runes::last() {
    if (string.length == 0) {
        ;
    }
    int length = string.length;
    int code = string.codeUnitAt(length - 1);
    if (_isTrailSurrogate(code) && string.length > 1) {
        int previousCode = string.codeUnitAt(length - 2);
        if (_isLeadSurrogate(previousCode)) {
            return _combineSurrogatePair(previousCode, code);
        }
    }
    return code;
}

bool _isLeadSurrogate(int code) {
    return (code & 0xFC00) == 0xD800;
}

bool _isTrailSurrogate(int code) {
    return (code & 0xFC00) == 0xDC00;
}

int _combineSurrogatePair(int end, int start) {
    return 0x10000 + ((start & 0x3FF) << 10) + (end & 0x3FF);
}

RuneIterator::RuneIterator(String string) {
    {
        this.string = string;
        _position = 0;
        _nextPosition = 0;
    }
}

void RuneIterator::at(int index, String string) {
    RangeError.checkValueInInterval(index, 0, string.length);
    _checkSplitSurrogate(index);
}

int RuneIterator::rawIndex() {
    return (_position != _nextPosition)? _position : -1;
}

void RuneIterator::rawIndex(int rawIndex) {
    RangeError.checkValidIndex(rawIndex, string, "rawIndex");
    reset(rawIndex);
    moveNext();
}

void RuneIterator::reset(int rawIndex) {
    RangeError.checkValueInInterval(rawIndex, 0, string.length, "rawIndex");
    _checkSplitSurrogate(rawIndex);
    _position = _nextPosition = rawIndex;
    _currentCodePoint = -1;
}

int RuneIterator::current() {
    return _currentCodePoint;
}

int RuneIterator::currentSize() {
    return _nextPosition - _position;
}

String RuneIterator::currentAsString() {
    if (_position == _nextPosition)     {
        return "";
    }
    if (_position + 1 == _nextPosition)     {
        return string[_position];
    }
    return string.substring(_position, _nextPosition);
}

bool RuneIterator::moveNext() {
    _position = _nextPosition;
    if (_position == string.length) {
        _currentCodePoint = -1;
        return false;
    }
    int codeUnit = string.codeUnitAt(_position);
    int nextPosition = _position + 1;
    if (_isLeadSurrogate(codeUnit) &&  < string.length) {
        int nextCodeUnit = string.codeUnitAt(nextPosition);
        if (_isTrailSurrogate(nextCodeUnit)) {
            _nextPosition = nextPosition + 1;
            _currentCodePoint = _combineSurrogatePair(codeUnit, nextCodeUnit);
            return true;
        }
    }
    _nextPosition = nextPosition;
    _currentCodePoint = codeUnit;
    return true;
}

bool RuneIterator::movePrevious() {
    _nextPosition = _position;
    if (_position == 0) {
        _currentCodePoint = -1;
        return false;
    }
    int position = _position - 1;
    int codeUnit = string.codeUnitAt(position);
    if (_isTrailSurrogate(codeUnit) && position > 0) {
        int prevCodeUnit = string.codeUnitAt(position - 1);
        if (_isLeadSurrogate(prevCodeUnit)) {
            _position = position - 1;
            _currentCodePoint = _combineSurrogatePair(prevCodeUnit, codeUnit);
            return true;
        }
    }
    _position = position;
    _currentCodePoint = codeUnit;
    return true;
}

void RuneIterator::_checkSplitSurrogate(int index) {
    if (index > 0 &&  < string.length && _isLeadSurrogate(string.codeUnitAt(index - 1)) && _isTrailSurrogate(string.codeUnitAt(index))) {
        ;
    }
}
