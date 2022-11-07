#ifndef LISTENER_HELPERS_H
#define LISTENER_HELPERS_H
#include <memory>
#include <ui.hpp>
#include "animation.hpp"

#include <flutter/foundation.hpp>
#include "animation.hpp"



class AnimationLazyListenerMixin {
public:

    void didRegisterListener();

    void didUnregisterListener();

    void didStartListening();

    void didStopListening();

    bool isListening();

private:
    int _listenerCounter;


};

class AnimationEagerListenerMixin {
public:

    void didRegisterListener();

    void didUnregisterListener();

    void dispose();

private:

};

class AnimationLocalListenersMixin {
public:

    void didRegisterListener();

    void didUnregisterListener();

    void addListener(VoidCallback listener);

    void removeListener(VoidCallback listener);

    void clearListeners();

    void notifyListeners();

private:
    ObserverList<VoidCallback> _listeners;


};

class AnimationLocalStatusListenersMixin {
public:

    void didRegisterListener();

    void didUnregisterListener();

    void addStatusListener(AnimationStatusListener listener);

    void removeStatusListener(AnimationStatusListener listener);

    void clearStatusListeners();

    void notifyStatusListeners(AnimationStatus status);

private:
    ObserverList<AnimationStatusListener> _statusListeners;


};

#endif