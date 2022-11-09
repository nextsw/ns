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
    if (quotient == 0)     {
        ;
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
    return other is Duration && _duration == other->inMicroseconds;
}

int DurationCls::hashCode() {
    return _duration->hashCode;
}

int DurationCls::compareTo(Duration other) {
    return _duration->compareTo(other->_duration);
}

String DurationCls::toString() {
    auto microseconds = inMicroseconds;
    auto sign = ( < 0)? "-" : "";
    auto hours = microseconds ~/ microsecondsPerHour;
    microseconds = microseconds->remainder(microsecondsPerHour);
    if ( < 0)     {
        microseconds = -microseconds;
    }
    auto minutes = microseconds ~/ microsecondsPerMinute;
    microseconds = microseconds->remainder(microsecondsPerMinute);
    auto minutesPadding =  < 10? "0" : "";
    auto seconds = microseconds ~/ microsecondsPerSecond;
    microseconds = microseconds->remainder(microsecondsPerSecond);
    auto secondsPadding =  < 10? "0" : "";
    auto paddedMicroseconds = microseconds->toString()->padLeft(6, "0");
    return "$sign${hours.abs()}:$minutesPadding$minutes:$secondsPadding$seconds.$paddedMicroseconds";
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
