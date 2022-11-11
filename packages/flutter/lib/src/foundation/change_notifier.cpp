#include "change_notifier.hpp"
bool ChangeNotifierCls::debugAssertNotDisposed(ChangeNotifier notifier) {
    assert([=] () {
        if (notifier->_debugDisposed) {
            ;
        }
        return true;
    }());
    return true;
}

bool ChangeNotifierCls::hasListeners() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    return _count > 0;
}

void ChangeNotifierCls::addListener(VoidCallback listener) {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    if (_count == _listeners->length()) {
        if (_count == 0) {
            _listeners = <VoidCallback>filled(1, nullptr);
        } else {
            List<VoidCallback> newListeners = <VoidCallback>filled(_listeners->length() * 2, nullptr);
            for (;  < _count; i++) {
                newListeners[i] = _listeners[i];
            }
            _listeners = newListeners;
        }
    }
    _listeners[_count++] = listener;
}

void ChangeNotifierCls::removeListener(VoidCallback listener) {
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

void ChangeNotifierCls::dispose() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    assert([=] () {
        _debugDisposed = true;
        return true;
    }());
    _listeners = _emptyListeners;
    _count = 0;
}

void ChangeNotifierCls::notifyListeners() {
    assert(ChangeNotifierCls->debugAssertNotDisposed(this));
    if (_count == 0) {
        return;
    }
    _notificationCallStackDepth++;
    int end = _count;
    for (;  < end; i++) {
        try {
            _listeners[i]?->call();
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("foundation library"), make<ErrorDescriptionCls>(__s("while dispatching notifications for $runtimeType")), [=] ()             {
                makeList(ArrayItem);
            }));
        };
    }
    _notificationCallStackDepth--;
    if (_notificationCallStackDepth == 0 && _reentrantlyRemovedListeners > 0) {
        int newLength = _count - _reentrantlyRemovedListeners;
        if (newLength * 2 <= _listeners->length()) {
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

void ChangeNotifierCls::_removeAt(int index) {
    _count = 1;
    if (_count * 2 <= _listeners->length()) {
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

void _MergingListenableCls::addListener(VoidCallback listener) {
    for (Listenable child : _children) {
        child?->addListener(listener);
    }
}

void _MergingListenableCls::removeListener(VoidCallback listener) {
    for (Listenable child : _children) {
        child?->removeListener(listener);
    }
}

String _MergingListenableCls::toString() {
    return __s("Listenable.merge([${_children.join(", ")}])");
}

template<typename T> T ValueNotifierCls<T>::value() {
    return _value;
}

template<typename T> void ValueNotifierCls<T>::value(T newValue) {
    if (_value == newValue) {
        return;
    }
    _value = newValue;
    notifyListeners();
}

template<typename T> String ValueNotifierCls<T>::toString() {
    return __s("${describeIdentity(this)}($value)");
}
