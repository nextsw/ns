#include "profiler.hpp"
MetricCls::MetricCls(String description, String name) {
    {
        if ((name == "vm") || name->contains("/")) {
            ;
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

GaugeCls::GaugeCls(String description, double max, double min, String name) {
    {
        _value = min;
    }
    {
        ArgumentErrorCls->checkNotNull(min, "min");
        ArgumentErrorCls->checkNotNull(max, "max");
        if (!( < max))         {
            ;
        }
    }
}

Map GaugeCls::_toJSON() {
    map1.set("type", "Gauge");map1.set("id", "metrics/$name");map1.set("name", name);map1.set("description", description);map1.set("value", value);map1.set("min", min);map1.set("max", max);auto map = list1;
    return map;
}

CounterCls::CounterCls(String description, String name) {
}

double CounterCls::value() {
    return _value;
}

void CounterCls::value(double v) {
    _value = v;
}

Map CounterCls::_toJSON() {
    map1.set("type", "Counter");map1.set("id", "metrics/$name");map1.set("name", name);map1.set("description", description);map1.set("value", value);auto map = list1;
    return map;
}

void MetricsCls::register(Metric metric) {
    ArgumentErrorCls->checkNotNull(metric, "metric");
    if (_metrics[metric->name] != nullptr) {
        ;
    }
    _metrics[metric->name] = metric;
}

void MetricsCls::deregister(Metric metric) {
    ArgumentErrorCls->checkNotNull(metric, "metric");
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
    map1.set("type", "MetricList");map1.set("metrics", metrics);auto map = list1;
    return json->encode(map);
}
