#include "profiler.hpp"
Metric::Metric(String description, String name) {
    {
        if ((name == "vm") || name.contains("/")) {
            ;
        }
    }
}

double Gauge::value() {
    return _value;
}

void Gauge::value(double v) {
    if ( < min) {
        v = min;
    } else     {
        if (v > max) {
        v = max;
    }
;
    }    _value = v;
}

Gauge::Gauge(String description, double max, double min, String name) {
    {
        _value = min;
        super(name, description);
    }
    {
        ArgumentError.checkNotNull(min, "min");
        ArgumentError.checkNotNull(max, "max");
        if (!( < max))         {
            ;
        }
    }
}

Map Gauge::_toJSON() {
    auto map = ;
    return map;
}

Counter::Counter(String description, String name) {
    {
        super(name, description);
    }
}

double Counter::value() {
    return _value;
}

void Counter::value(double v) {
    _value = v;
}

Map Counter::_toJSON() {
    auto map = ;
    return map;
}

void Metrics::register(Metric metric) {
    ArgumentError.checkNotNull(metric, "metric");
    if (_metrics[metric.name] != nullptr) {
        ;
    }
    _metrics[metric.name] = metric;
}

void Metrics::deregister(Metric metric) {
    ArgumentError.checkNotNull(metric, "metric");
    _metrics.remove(metric.name);
}

String Metrics::_printMetric(String id) {
    auto metric = _metrics[id];
    if (metric == nullptr) {
        return nullptr;
    }
    return json.encode(metric._toJSON());
}

String Metrics::_printMetrics() {
    auto metrics = ;
    for (auto metric : _metrics.values) {
        metrics.add(metric._toJSON());
    }
    auto map = ;
    return json.encode(map);
}
