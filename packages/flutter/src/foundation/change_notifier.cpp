#include "change_notifier.hpp"
bool ChangeNotifier::debugAssertNotDisposed(ChangeNotifier notifier) {
    assert(());
    return true;
}

bool ChangeNotifier::hasListeners() {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    return _count > 0;
}

void ChangeNotifier::addListener(VoidCallback listener) {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    if (_count == _listeners.length) {
        if (_count == 0) {
            _listeners = <VoidCallback>filled(1, nullptr);
        } else {
            List<VoidCallback> newListeners = <VoidCallback>filled(_listeners.length * 2, nullptr);
            for (;  < _count; i++) {
                newListeners[i] = _listeners[i];
            }
            _listeners = newListeners;
        }
    }
    _listeners[_count++] = listener;
}

void ChangeNotifier::removeListener(VoidCallback listener) {
    for (;  < _count; i++) {
        VoidCallback listenerAtIndex = _listeners[i];
        if (listenerAtIndex == listener) {
            if (_notificationCallStackDepth > 0) {
                _listeners[i] = nullptr;
                _reentrantlyRemovedListeners++;
            } else {
                _removeAt(i);
            }
                        break;
        }
    }
}

void ChangeNotifier::dispose() {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    assert(());
    _listeners = _emptyListeners;
    _count = 0;
}

void ChangeNotifier::notifyListeners() {
    assert(ChangeNotifier.debugAssertNotDisposed(this));
    if (_count == 0) {
        return;
    }
    _notificationCallStackDepth++;
    int end = _count;
    for (;  < end; i++) {
        ;
    }
    _notificationCallStackDepth--;
    if (_notificationCallStackDepth == 0 && _reentrantlyRemovedListeners > 0) {
        int newLength = _count - _reentrantlyRemovedListeners;
        if (newLength * 2 <= _listeners.length) {
            List<VoidCallback> newListeners = <VoidCallback>filled(newLength, nullptr);
            int newIndex = 0;
            for (;  < _count; i++) {
                VoidCallback listener = _listeners[i];
                if (listener != nullptr) {
                    newListeners[newIndex++] = listener;
                }
            }
            _listeners = newListeners;
        } else {
            for (;  < newLength; i = 1) {
                if (_listeners[i] == nullptr) {
                    int swapIndex = i + 1;
                    while (_listeners[swapIndex] == nullptr) {
                        swapIndex = 1;
                    }
                    _listeners[i] = _listeners[swapIndex];
                    _listeners[swapIndex] = nullptr;
                }
            }
        }
        _reentrantlyRemovedListeners = 0;
        _count = newLength;
    }
}

void ChangeNotifier::_removeAt(int index) {
    _count = 1;
    if (_count * 2 <= _listeners.length) {
        List<VoidCallback> newListeners = <VoidCallback>filled(_count, nullptr);
        for (;  < index; i++) {
            newListeners[i] = _listeners[i];
        }
        for (;  < _count; i++) {
            newListeners[i] = _listeners[i + 1];
        }
        _listeners = newListeners;
    } else {
        for (;  < _count; i++) {
            _listeners[i] = _listeners[i + 1];
        }
        _listeners[_count] = nullptr;
    }
}

void _MergingListenable::addListener(VoidCallback listener) {
    for (Listenable child : _children) {
        child?.addListener(listener);
    }
}

void _MergingListenable::removeListener(VoidCallback listener) {
    for (Listenable child : _children) {
        child?.removeListener(listener);
    }
}

String _MergingListenable::toString() {
    return "Listenable.merge([${_children.join(", ")}])";
}

T ValueNotifier::value() {
    return _value;
}

void ValueNotifier::value(T newValue) {
    if (_value == newValue) {
        return;
    }
    _value = newValue;
    notifyListeners();
}

String ValueNotifier::toString() {
    return "${describeIdentity(this)}($value)";
}
