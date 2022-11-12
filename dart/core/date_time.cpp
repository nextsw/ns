#include "date_time.hpp"
DateTimeCls::DateTimeCls(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond) {
    {
        this->_internal(year, month, day, hour, minute, second, millisecond, microsecond, false);
    }
}

void DateTimeCls::utc(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond)

void DateTimeCls::now()

DateTime DateTimeCls::parse(String formattedString) {
    auto re = _parseFormat;
    Match match = re->firstMatch(formattedString);
    if (match != nullptr) {
        InlineMethod;
        InlineMethod;
        int years = intValue->parse(match[1]!);
        int month = intValue->parse(match[2]!);
        int day = intValue->parse(match[3]!);
        int hour = parseIntOrZero(match[4]);
        int minute = parseIntOrZero(match[5]);
        int second = parseIntOrZero(match[6]);
        int milliAndMicroseconds = parseMilliAndMicroseconds(match[7]);
        int millisecond = milliAndMicroseconds ~/ DurationCls::microsecondsPerMillisecond;
        int microsecond = as<int>(milliAndMicroseconds->remainder(DurationCls::microsecondsPerMillisecond));
        bool isUtc = false;
        if (match[8] != nullptr) {
            isUtc = true;
            String tzSign = match[9];
            if (tzSign != nullptr) {
                int sign = (tzSign == __s("-"))? -1 : 1;
                int hourDifference = intValue->parse(match[10]!);
                int minuteDifference = parseIntOrZero(match[11]);
                minuteDifference += 60 * hourDifference;
                minute -= sign * minuteDifference;
            }
        }
        int value = _brokenDownDateToValue(years, month, day, hour, minute, second, millisecond, microsecond, isUtc);
        if (value == nullptr) {
            throw make<FormatExceptionCls>(__s("Time out of range"), formattedString);
        }
        return DateTimeCls->_withValue(value, isUtc);
    } else {
        throw make<FormatExceptionCls>(__s("Invalid date format"), formattedString);
    }
}

DateTime DateTimeCls::tryParse(String formattedString) {
    try {
        return parse(formattedString);
    } catch (FormatException null) {
        return nullptr;
    };
}

int DateTimeCls::hashCode() {
    return (_value ^ (_value >> 30)) & 0x3FFFFFFF;
}

DateTime DateTimeCls::toLocal() {
    if (isUtc) {
        return DateTimeCls->_withValue(_value, false);
    }
    return this;
}

DateTime DateTimeCls::toUtc() {
    if (isUtc) {
        return this;
    }
    return DateTimeCls->_withValue(_value, true);
}

String DateTimeCls::toString() {
    String y = _fourDigits(year());
    String m = _twoDigits(month());
    String d = _twoDigits(day());
    String h = _twoDigits(hour());
    String min = _twoDigits(minute());
    String sec = _twoDigits(second());
    String ms = _threeDigits(millisecond());
    String us = microsecond() == 0? __s("") : _threeDigits(microsecond());
    if (isUtc) {
        return __s("%s$%s$%s$%s$%s$%s$%s$%s;");
    } else {
        return __s("%s$%s$%s$%s$%s$%s$%s$%s;");
    }
}

String DateTimeCls::toIso8601String() {
    String y = (year() >= -9999 && year() <= 9999)? _fourDigits(year()) : _sixDigits(year());
    String m = _twoDigits(month());
    String d = _twoDigits(day());
    String h = _twoDigits(hour());
    String min = _twoDigits(minute());
    String sec = _twoDigits(second());
    String ms = _threeDigits(millisecond());
    String us = microsecond() == 0? __s("") : _threeDigits(microsecond());
    if (isUtc) {
        return __s("%s$%s$%s$%s$%s$%s$%s$%s;");
    } else {
        return __s("%s$%s$%s$%s$%s$%s$%s$%s;");
    }
}

void DateTimeCls::_withValue(int _value, bool isUtc) {
    if (millisecondsSinceEpoch()->abs() > _maxMillisecondsSinceEpoch || (millisecondsSinceEpoch()->abs() == _maxMillisecondsSinceEpoch && microsecond() != 0)) {
        throw make<ArgumentErrorCls>(__s("DateTime is outside valid range: %s)"));
    }
    checkNotNullable(isUtc, __s("isUtc"));
}

String DateTimeCls::_fourDigits(int n) {
    int absN = n->abs();
    String sign =  < 0? __s("-") : __s("");
    if (absN >= 1000) {
        return __s("%s;");
    }
    if (absN >= 100) {
        return __s("%s$%s;");
    }
    if (absN >= 10) {
        return __s("%s$%s;");
    }
    return __s("%s$%s;");
}

String DateTimeCls::_sixDigits(int n) {
    assert( < -9999 || n > 9999);
    int absN = n->abs();
    String sign =  < 0? __s("-") : __s("+");
    if (absN >= 100000) {
        return __s("%s$%s;");
    }
    return __s("%s$%s;");
}

String DateTimeCls::_threeDigits(int n) {
    if (n >= 100) {
        return __s("%s;");
    }
    if (n >= 10) {
        return __s("0%s;");
    }
    return __s("00%s;");
}

String DateTimeCls::_twoDigits(int n) {
    if (n >= 10) {
        return __s("%s;");
    }
    return __s("0%s;");
}
