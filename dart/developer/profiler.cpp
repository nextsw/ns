#include "profiler.hpp"
MetricCls::MetricCls(String description, String name) {
    {
        if ((name == __s("vm")) || name->contains(__s("/"))) {
            throw make<ArgumentErrorCls>(__s("Invalid Metric name."));
        }
    }
}

double GaugeCls::value() {
    return _value;
}

void GaugeCls::value(double v) {
    if ( < min) {
        v = min;
    } else     {
        if (v > max) {
        v = max;
    }
;
    }    _value = v;
}

GaugeCls::GaugeCls(String description, double max, double min, String name) : Metric(name, description) {
    {
        _value = min;
    }
    {
        ArgumentErrorCls->checkNotNull(min, __s("min"));
        ArgumentErrorCls->checkNotNull(max, __s("max"));
        if (!( < max))         {
            throw make<ArgumentErrorCls>(__s("min must be less than max"));
        }
    }
}

Map GaugeCls::_toJSON() {
    map1.set(__s("type"), __s("Gauge"));map1.set(__s("id"), __s("metrics/$name"));map1.set(__s("name"), name);map1.set(__s("description"), description);map1.set(__s("value"), value());map1.set(__s("min"), min);map1.set(__s("max"), max);auto map = list1;
    return map;
}

CounterCls::CounterCls(String description, String name) : Metric(name, description) {
}

double CounterCls::value() {
    return _value;
}

void CounterCls::value(double v) {
    _value = v;
}

Map CounterCls::_toJSON() {
    map1.set(__s("type"), __s("Counter"));map1.set(__s("id"), __s("metrics/$name"));map1.set(__s("name"), name);map1.set(__s("description"), description);map1.set(__s("value"), value());auto map = list1;
    return map;
}

void MetricsCls::register(Metric metric) {
    ArgumentErrorCls->checkNotNull(metric, __s("metric"));
    if (_metrics[metric->name] != nullptr) {
        throw make<ArgumentErrorCls>(__s("Registered metrics have unique names"));
    }
    _metrics[metric->name] = metric;
}

void MetricsCls::deregister(Metric metric) {
    ArgumentErrorCls->checkNotNull(metric, __s("metric"));
    _metrics->remove(metric->name);
}

String MetricsCls::_printMetric(String id) {
    auto metric = _metrics[id];
    if (metric == nullptr) {
        return nullptr;
    }
    return json->encode(metric->_toJSON());
}

String MetricsCls::_printMetrics() {
    auto metrics = makeList();
    for (auto metric : _metrics->values) {
        metrics->add(metric->_toJSON());
    }
    map1.set(__s("type"), __s("MetricList"));map1.set(__s("metrics"), metrics);auto map = list1;
    return json->encode(map);
}
