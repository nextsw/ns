#include "duration.hpp"
Duration::Duration(int days, int hours, int microseconds, int milliseconds, int minutes, int seconds) {
    {
        this._microseconds(microseconds + microsecondsPerMillisecond * milliseconds + microsecondsPerSecond * seconds + microsecondsPerMinute * minutes + microsecondsPerHour * hours + microsecondsPerDay * days);
    }
}

Duration Duration::+(Duration other) {
    return Duration._microseconds(_duration + other._duration);
}

Duration Duration::-(Duration other) {
    return Duration._microseconds(_duration - other._duration);
}

Duration Duration::*(num factor) {
    return Duration._microseconds((_duration * factor).round());
}

Duration Duration::~/(int quotient) {
    if (quotient == 0)     {
        ;
    }
    return Duration._microseconds(_duration ~/ quotient);
}

bool Duration::<(Duration other) {
    return this._duration < other._duration;
}

bool Duration::>(Duration other) {
    return this._duration > other._duration;
}

bool Duration::<=(Duration other) {
    return this._duration <= other._duration;
}

bool Duration::>=(Duration other) {
    return this._duration >= other._duration;
}

int Duration::inDays() {
    return _duration ~/ Duration.microsecondsPerDay;
}

int Duration::inHours() {
    return _duration ~/ Duration.microsecondsPerHour;
}

int Duration::inMinutes() {
    return _duration ~/ Duration.microsecondsPerMinute;
}

int Duration::inSeconds() {
    return _duration ~/ Duration.microsecondsPerSecond;
}

int Duration::inMilliseconds() {
    return _duration ~/ Duration.microsecondsPerMillisecond;
}

int Duration::inMicroseconds() {
    return _duration;
}

bool Duration::==(Object other) {
    return other is Duration && _duration == other.inMicroseconds;
}

int Duration::hashCode() {
    return _duration.hashCode;
}

int Duration::compareTo(Duration other) {
    return _duration.compareTo(other._duration);
}

String Duration::toString() {
    auto microseconds = inMicroseconds;
    auto sign = ( < 0)? "-" : "";
    auto hours = microseconds ~/ microsecondsPerHour;
    microseconds = microseconds.remainder(microsecondsPerHour);
    if ( < 0)     {
        microseconds = -microseconds;
    }
    auto minutes = microseconds ~/ microsecondsPerMinute;
    microseconds = microseconds.remainder(microsecondsPerMinute);
    auto minutesPadding =  < 10? "0" : "";
    auto seconds = microseconds ~/ microsecondsPerSecond;
    microseconds = microseconds.remainder(microsecondsPerSecond);
    auto secondsPadding =  < 10? "0" : "";
    auto paddedMicroseconds = microseconds.toString().padLeft(6, "0");
    return "$sign${hours.abs()}:$minutesPadding$minutes:$secondsPadding$seconds.$paddedMicroseconds";
}

bool Duration::isNegative() {
    return  < 0;
}

Duration Duration::abs() {
    return Duration._microseconds(_duration.abs());
}

Duration Duration::-() {
    return Duration._microseconds(0 - _duration);
}
