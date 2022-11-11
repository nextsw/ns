#include "duration.hpp"
DurationCls::DurationCls(int days, int hours, int microseconds, int milliseconds, int minutes, int seconds) {
    {
        this->_microseconds(microseconds + microsecondsPerMillisecond * milliseconds + microsecondsPerSecond * seconds + microsecondsPerMinute * minutes + microsecondsPerHour * hours + microsecondsPerDay * days);
    }
}

Duration DurationCls::+(Duration other) {
    return DurationCls->_microseconds(_duration + other->_duration);
}

Duration DurationCls::-(Duration other) {
    return DurationCls->_microseconds(_duration - other->_duration);
}

Duration DurationCls::*(num factor) {
    return DurationCls->_microseconds((_duration * factor)->round());
}

Duration DurationCls::~/(int quotient) {
    if (quotient == 0) {
        throw make<IntegerDivisionByZeroExceptionCls>();
    }
    return DurationCls->_microseconds(_duration ~/ quotient);
}

bool DurationCls::<(Duration other) {
    return this->_duration < other->_duration;
}

bool DurationCls::>(Duration other) {
    return this->_duration > other->_duration;
}

bool DurationCls::<=(Duration other) {
    return this->_duration <= other->_duration;
}

bool DurationCls::>=(Duration other) {
    return this->_duration >= other->_duration;
}

int DurationCls::inDays() {
    return _duration ~/ DurationCls::microsecondsPerDay;
}

int DurationCls::inHours() {
    return _duration ~/ DurationCls::microsecondsPerHour;
}

int DurationCls::inMinutes() {
    return _duration ~/ DurationCls::microsecondsPerMinute;
}

int DurationCls::inSeconds() {
    return _duration ~/ DurationCls::microsecondsPerSecond;
}

int DurationCls::inMilliseconds() {
    return _duration ~/ DurationCls::microsecondsPerMillisecond;
}

int DurationCls::inMicroseconds() {
    return _duration;
}

bool DurationCls::==(Object other) {
    return is<Duration>(other) && _duration == other->inMicroseconds;
}

int DurationCls::hashCode() {
    return _duration->hashCode();
}

int DurationCls::compareTo(Duration other) {
    return _duration->compareTo(other->_duration);
}

String DurationCls::toString() {
    auto microseconds = inMicroseconds();
    auto sign = ( < 0)? __s("-") : __s("");
    auto hours = microseconds ~/ microsecondsPerHour;
    microseconds = microseconds->remainder(microsecondsPerHour);
    if ( < 0) {
        microseconds = -microseconds;
    }
    auto minutes = microseconds ~/ microsecondsPerMinute;
    microseconds = microseconds->remainder(microsecondsPerMinute);
    auto minutesPadding =  < 10? __s("0") : __s("");
    auto seconds = microseconds ~/ microsecondsPerSecond;
    microseconds = microseconds->remainder(microsecondsPerSecond);
    auto secondsPadding =  < 10? __s("0") : __s("");
    auto paddedMicroseconds = microseconds->toString()->padLeft(6, __s("0"));
    return __s("$sign${hours.abs()}:$minutesPadding$minutes:$secondsPadding$seconds.$paddedMicroseconds");
}

bool DurationCls::isNegative() {
    return  < 0;
}

Duration DurationCls::abs() {
    return DurationCls->_microseconds(_duration->abs());
}

Duration DurationCls::-() {
    return DurationCls->_microseconds(0 - _duration);
}
