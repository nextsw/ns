#ifndef DART_CORE_DURATION
#define DART_CORE_DURATION
#include <base.hpp>

#include <dart/core/core.hpp>


class DurationCls : public ObjectCls {
public:
    static int microsecondsPerMillisecond;

    static int millisecondsPerSecond;

    static int secondsPerMinute;

    static int minutesPerHour;

    static int hoursPerDay;

    static int microsecondsPerSecond;

    static int microsecondsPerMinute;

    static int microsecondsPerHour;

    static int microsecondsPerDay;

    static int millisecondsPerMinute;

    static int millisecondsPerHour;

    static int millisecondsPerDay;

    static int secondsPerHour;

    static int secondsPerDay;

    static int minutesPerDay;

    static Duration zero;


     DurationCls(int days, int hours, int microseconds, int milliseconds, int minutes, int seconds);

    virtual Duration operator+(Duration other);

    virtual Duration operator-(Duration other);

    virtual Duration operator*(num factor);

    virtual Duration operator~/(int quotient);

    virtual bool operator<(Duration other);

    virtual bool operator>(Duration other);

    virtual bool operator<=(Duration other);

    virtual bool operator>=(Duration other);

    virtual int inDays();

    virtual int inHours();

    virtual int inMinutes();

    virtual int inSeconds();

    virtual int inMilliseconds();

    virtual int inMicroseconds();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual int compareTo(Duration other);

    virtual String toString();

    virtual bool isNegative();

    virtual Duration abs();

    virtual Duration operator-();

private:
    int _duration;


    virtual void  _microseconds(int _duration);
};
using Duration = std::shared_ptr<DurationCls>;


#endif