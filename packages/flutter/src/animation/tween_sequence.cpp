#include "tween_sequence.hpp"
TweenSequence::TweenSequence(List<TweenSequenceItem<T>> items) {
    {
        assert(items != nullptr);
        assert(items.isNotEmpty);
    }
    {
        _items.addAll(items);
        double totalWeight = 0.0;
        for (TweenSequenceItem<T> item : _items) {
            totalWeight = item.weight;
        }
        assert(totalWeight > 0.0);
        double start = 0.0;
        for (;  < _items.length; i = 1) {
            double end = i == _items.length - 1? 1.0 : start + _items[i].weight / totalWeight;
            _intervals.add(_Interval(start, end));
            start = end;
        }
    }
}

T TweenSequence::transform(double t) {
    assert(t >= 0.0 && t <= 1.0);
    if (t == 1.0) {
        return _evaluateAt(t, _items.length - 1);
    }
    for (;  < _items.length; index++) {
        if (_intervals[index].contains(t)) {
            return _evaluateAt(t, index);
        }
    }
    ;
}

String TweenSequence::toString() {
    return "TweenSequence(${_items.length} items)";
}

T TweenSequence::_evaluateAt(int index, double t) {
    TweenSequenceItem<T> element = _items[index];
    double tInterval = _intervals[index].value(t);
    return element.tween.transform(tInterval);
}

FlippedTweenSequence::FlippedTweenSequence(Unknown) {
    {
        assert(items != nullptr);
    }
}

double FlippedTweenSequence::transform(double t) {
    return 1 - super.transform(1 - t);
}

TweenSequenceItem::TweenSequenceItem(Animatable<T> tween, double weight) {
    {
        assert(tween != nullptr);
        assert(weight != nullptr);
        assert(weight > 0.0);
    }
}

bool _Interval::contains(double t) {
    return t >= start &&  < end;
}

double _Interval::value(double t) {
    return (t - start) / (end - start);
}

String _Interval::toString() {
    return "<$start, $end>";
}

_Interval::_Interval(double end, double start) {
    {
        assert(end > start);
    }
}
