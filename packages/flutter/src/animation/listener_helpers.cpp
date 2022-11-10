#include "listener_helpers.hpp"
void AnimationLazyListenerMixinCls::didRegisterListener() {
    assert(_listenerCounter >= 0);
    if (_listenerCounter == 0) {
        didStartListening();
    }
    _listenerCounter = 1;
}

void AnimationLazyListenerMixinCls::didUnregisterListener() {
    assert(_listenerCounter >= 1);
    _listenerCounter = 1;
    if (_listenerCounter == 0) {
        didStopListening();
    }
}

bool AnimationLazyListenerMixinCls::isListening() {
    return _listenerCounter > 0;
}

void AnimationEagerListenerMixinCls::didRegisterListener() {
}

void AnimationEagerListenerMixinCls::didUnregisterListener() {
}

void AnimationEagerListenerMixinCls::dispose() {
}

void AnimationLocalListenersMixinCls::addListener(VoidCallback listener) {
    didRegisterListener();
    _listeners->add(listener);
}

void AnimationLocalListenersMixinCls::removeListener(VoidCallback listener) {
    bool removed = _listeners->remove(listener);
    if (removed) {
        didUnregisterListener();
    }
}

void AnimationLocalListenersMixinCls::clearListeners() {
    _listeners->clear();
}

void AnimationLocalListenersMixinCls::notifyListeners() {
    List<VoidCallback> localListeners = _listeners->toList(false);
    for (VoidCallback listener : localListeners) {
        InformationCollector collector;
        assert([=] () {
            collector = [=] ()             {
                makeList(ArrayItem);
            };
            return true;
        }());
        try {
            if (_listeners->contains(listener)) {
                listener();
            }
        } catch (Unknown exception) {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("animation library"), make<ErrorDescriptionCls>(__s("while notifying listeners for $runtimeType")), collector));
        };
    }
}

void AnimationLocalStatusListenersMixinCls::addStatusListener(AnimationStatusListener listener) {
    didRegisterListener();
    _statusListeners->add(listener);
}

void AnimationLocalStatusListenersMixinCls::removeStatusListener(AnimationStatusListener listener) {
    bool removed = _statusListeners->remove(listener);
    if (removed) {
        didUnregisterListener();
    }
}

void AnimationLocalStatusListenersMixinCls::clearStatusListeners() {
    _statusListeners->clear();
}

void AnimationLocalStatusListenersMixinCls::notifyStatusListeners(AnimationStatus status) {
    List<AnimationStatusListener> localListeners = _statusListeners->toList(false);
    for (AnimationStatusListener listener : localListeners) {
        try {
            if (_statusListeners->contains(listener)) {
                listener(status);
            }
        } catch (Unknown exception) {
            InformationCollector collector;
            assert([=] () {
                collector = [=] ()                 {
                    makeList(ArrayItem);
                };
                return true;
            }());
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("animation library"), make<ErrorDescriptionCls>(__s("while notifying status listeners for $runtimeType")), collector));
        };
    }
}
