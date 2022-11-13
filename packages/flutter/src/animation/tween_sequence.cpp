#include "tween_sequence.hpp"
template<typename T>
TweenSequenceCls<T>::TweenSequenceCls(List<TweenSequenceItem<T>> items) {
    {
        assert(items != nullptr);
        assert(items->isNotEmpty());
    }
    {
        _items->addAll(items);
        double totalWeight = 0.0;
        for (TweenSequenceItem<T> item : _items) {
            totalWeight += item->weight;
        }
        assert(totalWeight > 0.0);
        double start = 0.0;
        for (;  < _items->length(); i += 1) {
            double end = i == _items->length() - 1? 1.0 : start + _items[i]->weight / totalWeight;
            _intervals->add(make<_IntervalCls>(start, end));
            start = end;
        }
    }
}

template<typename T>
T TweenSequenceCls<T>::transform(double t) {
    assert(t >= 0.0 && t <= 1.0);
    if (t == 1.0) {
        return _evaluateAt(t, _items->length() - 1);
    }
    for (;  < _items->length(); index++) {
        if (_intervals[index]->contains(t)) {
            return _evaluateAt(t, index);
        }
    }
    throw make<StateErrorCls>(__sf("TweenSequence.evaluate() could not find an interval for %s", t));
}

template<typename T>
String TweenSequenceCls<T>::toString() {
    return __sf("TweenSequence(%s items)", _items->length());
}

template<typename T>
T TweenSequenceCls<T>::_evaluateAt(double t, int index) {
    TweenSequenceItem<T> element = _items[index];
    double tInterval = _intervals[index]->value(t);
    return element->tween->transform(tInterval);
}

FlippedTweenSequenceCls::FlippedTweenSequenceCls(List<TweenSequenceItem<T>> items) {
    {
        assert(items != nullptr);
    }
}

double FlippedTweenSequenceCls::transform(double t) {
    return 1 - super->transform(1 - t);
}

template<typename T>
TweenSequenceItemCls<T>::TweenSequenceItemCls(Animatable<T> tween, double weight) {
    {
        assert(tween != nullptr);
        assert(weight != nullptr);
        assert(weight > 0.0);
    }
}

bool _IntervalCls::contains(double t) {
    return t >= start &&  < end;
}

double _IntervalCls::value(double t) {
    return (t - start) / (end - start);
}

String _IntervalCls::toString() {
    return __sf("<%s, %s>", start, end);
}

_IntervalCls::_IntervalCls(double start, double end) {
    {
        assert(end > start);
    }
}
