#ifndef PACKAGES_FLUTTER_SRC_GESTURES_EAGER
#define PACKAGES_FLUTTER_SRC_GESTURES_EAGER
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include "recognizer.hpp"


class EagerGestureRecognizerCls : public OneSequenceGestureRecognizerCls {
public:

     EagerGestureRecognizerCls(Unknown kind, Unknown supportedDevices);
    virtual void addAllowedPointer(PointerDownEvent event);

    virtual String debugDescription();

    virtual void didStopTrackingLastPointer(int pointer);

    virtual void handleEvent(PointerEvent event);

private:

};
using EagerGestureRecognizer = std::shared_ptr<EagerGestureRecognizerCls>;


#endif