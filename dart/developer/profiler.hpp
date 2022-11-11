#ifndef DART_DEVELOPER_PROFILER
#define DART_DEVELOPER_PROFILER
#include <base.hpp>

#include <dart/core/core.hpp>


class UserTagCls : public ObjectCls {
public:
    static auto  MAX_USER_TAGS;


     UserTagCls(String label);
    virtual String label();
    virtual UserTag makeCurrent();
    static UserTag defaultTag();
private:

};
using UserTag = std::shared_ptr<UserTagCls>;
UserTag getCurrentTag();

class MetricCls : public ObjectCls {
public:
    String name;

    String description;


     MetricCls(String name, String description);

private:

    virtual Map _toJSON();
};
using Metric = std::shared_ptr<MetricCls>;

class GaugeCls : public MetricCls {
public:
    double min;

    double max;


    virtual double value();

    virtual void  value(double v);

     GaugeCls(String name, String description, double min, double max);

private:
    double _value;


    virtual Map _toJSON();

};
using Gauge = std::shared_ptr<GaugeCls>;

class CounterCls : public MetricCls {
public:

     CounterCls(String name, String description);

    virtual double value();

    virtual void  value(double v);

private:
    double _value;


    virtual Map _toJSON();

};
using Counter = std::shared_ptr<CounterCls>;

class MetricsCls : public ObjectCls {
public:

    static void register(Metric metric);

    static void deregister(Metric metric);

private:
    static Map<String, Metric> _metrics;


    static String _printMetric(String id);

    static String _printMetrics();

};
using Metrics = std::shared_ptr<MetricsCls>;


#endif