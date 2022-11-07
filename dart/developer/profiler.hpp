#ifndef PROFILER_H
#define PROFILER_H
#include <memory>




class UserTag {
public:
    static const auto  MAX_USER_TAGS;


    external  UserTag(String label);

    String label();

    UserTag makeCurrent();

    external static UserTag defaultTag();

private:

};
external UserTag getCurrentTag();


class Metric {
public:
    String name;

    String description;


     Metric(String description, String name);

private:

    Map _toJSON();

};

class Gauge : Metric {
public:
    double min;

    double max;


    double value();

    void  value(double v);

     Gauge(String description, double max, double min, String name);

private:
    double _value;


    Map _toJSON();

};

class Counter : Metric {
public:

     Counter(String description, String name);

    double value();

    void  value(double v);

private:
    double _value;


    Map _toJSON();

};

class Metrics {
public:

    static void register(Metric metric);

    static void deregister(Metric metric);

private:
    static Map<String, Metric> _metrics;


    static String _printMetric(String id);

    static String _printMetrics();

};

#endif