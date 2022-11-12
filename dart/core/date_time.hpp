#ifndef DART_CORE_DATE_TIME
#define DART_CORE_DATE_TIME
#include <base.hpp>

#include <dart/core/core.hpp>


class DateTimeCls : public ObjectCls {
public:
    static int monday;

    static int tuesday;

    static int wednesday;

    static int thursday;

    static int friday;

    static int saturday;

    static int sunday;

    static int daysPerWeek;

    static int january;

    static int february;

    static int march;

    static int april;

    static int may;

    static int june;

    static int july;

    static int august;

    static int september;

    static int october;

    static int november;

    static int december;

    static int monthsPerYear;

    bool isUtc;


     DateTimeCls(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond);

    virtual void  utc(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond);

    virtual void  now();

    static DateTime parse(String formattedString);

    static DateTime tryParse(String formattedString);

    void  fromMillisecondsSinceEpoch(int millisecondsSinceEpoch, bool isUtc);
    void  fromMicrosecondsSinceEpoch(int microsecondsSinceEpoch, bool isUtc);
    bool operator==(Object other);
    bool isBefore(DateTime other);
    bool isAfter(DateTime other);
    bool isAtSameMomentAs(DateTime other);
    int compareTo(DateTime other);
    virtual int hashCode();

    virtual DateTime toLocal();

    virtual DateTime toUtc();

    virtual String toString();

    virtual String toIso8601String();

    DateTime add(Duration duration);
    DateTime subtract(Duration duration);
    Duration difference(DateTime other);
    int millisecondsSinceEpoch();
    int microsecondsSinceEpoch();
    String timeZoneName();
    Duration timeZoneOffset();
    int year();
    int month();
    int day();
    int hour();
    int minute();
    int second();
    int millisecond();
    int microsecond();
    int weekday();
private:
    int _value;

    static int _maxMillisecondsSinceEpoch;

    static RegExp _parseFormat;


    virtual void  _withValue(int _value, bool isUtc);

    static String _fourDigits(int n);

    static String _sixDigits(int n);

    static String _threeDigits(int n);

    static String _twoDigits(int n);

    void  _internal(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond, bool isUtc);
    void  _now();
    static int _brokenDownDateToValue(int year, int month, int day, int hour, int minute, int second, int millisecond, int microsecond, bool isUtc);
};
using DateTime = std::shared_ptr<DateTimeCls>;


#endif