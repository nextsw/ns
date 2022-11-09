#ifndef PACKAGES_FLUTTER_SRC_ANIMATION_LISTENER_HELPERS
#define PACKAGES_FLUTTER_SRC_ANIMATION_LISTENER_HELPERS
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "animation.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "animation.hpp"


class AnimationLazyListenerMixinCls : public ObjectCls {
public:

    virtual void didRegisterListener();

    virtual void didUnregisterListener();

    virtual void didStartListening();
    virtual void didStopListening();
    virtual bool isListening();

private:
    int _listenerCounter;


};
using AnimationLazyListenerMixin = std::shared_ptr<AnimationLazyListenerMixinCls>;

class AnimationEagerListenerMixinCls : public ObjectCls {
public:

    virtual void didRegisterListener();

    virtual void didUnregisterListener();

    virtual void dispose();

private:

};
using AnimationEagerListenerMixin = std::shared_ptr<AnimationEagerListenerMixinCls>;

class AnimationLocalListenersMixinCls : public ObjectCls {
public:

    virtual void didRegisterListener();
    virtual void didUnregisterListener();
    virtual void addListener(VoidCallback listener);

    virtual void removeListener(VoidCallback listener);

    virtual void clearListeners();

    virtual void notifyListeners();

private:
    ObserverList<VoidCallback> _listeners;


};
using AnimationLocalListenersMixin = std::shared_ptr<AnimationLocalListenersMixinCls>;

class AnimationLocalStatusListenersMixinCls : public ObjectCls {
public:

    virtual void didRegisterListener();
    virtual void didUnregisterListener();
    virtual void addStatusListener(AnimationStatusListener listener);

    virtual void removeStatusListener(AnimationStatusListener listener);

    virtual void clearStatusListeners();

    virtual void notifyStatusListeners(AnimationStatus status);

private:
    ObserverList<AnimationStatusListener> _statusListeners;


};
using AnimationLocalStatusListenersMixin = std::shared_ptr<AnimationLocalStatusListenersMixinCls>;


#endif