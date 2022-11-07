#include "listener_helpers.hpp"
void AnimationLazyListenerMixin::didRegisterListener() {
    assert(_listenerCounter >= 0);
    if (_listenerCounter == 0) {
        didStartListening();
    }
    _listenerCounter = 1;
}

void AnimationLazyListenerMixin::didUnregisterListener() {
    assert(_listenerCounter >= 1);
    _listenerCounter = 1;
    if (_listenerCounter == 0) {
        didStopListening();
    }
}

bool AnimationLazyListenerMixin::isListening() {
    return _listenerCounter > 0;
}

void AnimationEagerListenerMixin::didRegisterListener() {
}

void AnimationEagerListenerMixin::didUnregisterListener() {
}

void AnimationEagerListenerMixin::dispose() {
}

void AnimationLocalListenersMixin::addListener(VoidCallback listener) {
    didRegisterListener();
    _listeners.add(listener);
}

void AnimationLocalListenersMixin::removeListener(VoidCallback listener) {
    bool removed = _listeners.remove(listener);
    if (removed) {
        didUnregisterListener();
    }
}

void AnimationLocalListenersMixin::clearListeners() {
    _listeners.clear();
}

void AnimationLocalListenersMixin::notifyListeners() {
    List<VoidCallback> localListeners = _listeners.toList(false);
    for (VoidCallback listener : localListeners) {
        InformationCollector collector;
        assert(());
        ;
    }
}

void AnimationLocalStatusListenersMixin::addStatusListener(AnimationStatusListener listener) {
    didRegisterListener();
    _statusListeners.add(listener);
}

void AnimationLocalStatusListenersMixin::removeStatusListener(AnimationStatusListener listener) {
    bool removed = _statusListeners.remove(listener);
    if (removed) {
        didUnregisterListener();
    }
}

void AnimationLocalStatusListenersMixin::clearStatusListeners() {
    _statusListeners.clear();
}

void AnimationLocalStatusListenersMixin::notifyStatusListeners(AnimationStatus status) {
    List<AnimationStatusListener> localListeners = _statusListeners.toList(false);
    for (AnimationStatusListener listener : localListeners) {
        ;
    }
}
