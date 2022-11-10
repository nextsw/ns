#include "string.hpp"
RuneIterator RunesCls::iterator() {
    return make<RuneIteratorCls>(stringValue);
}

int RunesCls::last() {
    if (stringValue->length() == 0) {
        ;
    }
    int length = stringValue->length();
    int code = stringValue->codeUnitAt(length - 1);
    if (_isTrailSurrogate(code) && stringValue->length() > 1) {
        int previousCode = stringValue->codeUnitAt(length - 2);
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

RuneIteratorCls::RuneIteratorCls(String stringValue) {
    {
        this->stringValue = stringValue;
        _position = 0;
        _nextPosition = 0;
    }
}

void RuneIteratorCls::at(int index, String stringValue) {
    RangeErrorCls->checkValueInInterval(index, 0, stringValue->length());
    _checkSplitSurrogate(index);
}

int RuneIteratorCls::rawIndex() {
    return (_position != _nextPosition)? _position : -1;
}

void RuneIteratorCls::rawIndex(int rawIndex) {
    RangeErrorCls->checkValidIndex(rawIndex(), stringValue, __s("rawIndex"));
    reset(rawIndex());
    moveNext();
}

void RuneIteratorCls::reset(int rawIndex) {
    RangeErrorCls->checkValueInInterval(rawIndex(), 0, stringValue->length(), __s("rawIndex"));
    _checkSplitSurrogate(rawIndex());
    _position = _nextPosition = rawIndex();
    _currentCodePoint = -1;
}

int RuneIteratorCls::current() {
    return _currentCodePoint;
}

int RuneIteratorCls::currentSize() {
    return _nextPosition - _position;
}

String RuneIteratorCls::currentAsString() {
    if (_position == _nextPosition)     {
        return __s("");
    }
    if (_position + 1 == _nextPosition)     {
        return stringValue[_position];
    }
    return stringValue->substring(_position, _nextPosition);
}

bool RuneIteratorCls::moveNext() {
    _position = _nextPosition;
    if (_position == stringValue->length()) {
        _currentCodePoint = -1;
        return false;
    }
    int codeUnit = stringValue->codeUnitAt(_position);
    int nextPosition = _position + 1;
    if (_isLeadSurrogate(codeUnit) &&  < stringValue->length()) {
        int nextCodeUnit = stringValue->codeUnitAt(nextPosition);
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

bool RuneIteratorCls::movePrevious() {
    _nextPosition = _position;
    if (_position == 0) {
        _currentCodePoint = -1;
        return false;
    }
    int position = _position - 1;
    int codeUnit = stringValue->codeUnitAt(position);
    if (_isTrailSurrogate(codeUnit) && position > 0) {
        int prevCodeUnit = stringValue->codeUnitAt(position - 1);
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

void RuneIteratorCls::_checkSplitSurrogate(int index) {
    if (index > 0 &&  < stringValue->length() && _isLeadSurrogate(stringValue->codeUnitAt(index - 1)) && _isTrailSurrogate(stringValue->codeUnitAt(index))) {
        ;
    }
}
