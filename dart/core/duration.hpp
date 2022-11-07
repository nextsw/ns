#ifndef DURATION_H
#define DURATION_H
#include <memory>




class Duration {
public:
    static const int microsecondsPerMillisecond;

    static const int millisecondsPerSecond;

    static const int secondsPerMinute;

    static const int minutesPerHour;

    static const int hoursPerDay;

    static const int microsecondsPerSecond;

    static const int microsecondsPerMinute;

    static const int microsecondsPerHour;

    static const int microsecondsPerDay;

    static const int millisecondsPerMinute;

    static const int millisecondsPerHour;

    static const int millisecondsPerDay;

    static const int secondsPerHour;

    static const int secondsPerDay;

    static const int minutesPerDay;

    static const Duration zero;


     Duration(int days, int hours, int microseconds, int milliseconds, int minutes, int seconds);

    Duration +(Duration other);

    Duration -(Duration other);

    Duration *(num factor);

    Duration ~/(int quotient);

    bool <(Duration other);

    bool >(Duration other);

    bool <=(Duration other);

    bool >=(Duration other);

    int inDays();

    int inHours();

    int inMinutes();

    int inSeconds();

    int inMilliseconds();

    int inMicroseconds();

    bool ==(Object other);

    int hashCode();

    int compareTo(Duration other);

    String toString();

    bool isNegative();

    Duration abs();

    Duration -();

private:
    int _duration;


    void  _microseconds(int _duration);

};

#endif