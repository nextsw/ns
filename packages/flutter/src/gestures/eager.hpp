#ifndef EAGER_H
#define EAGER_H
#include <memory>
#include <ui.hpp>
#include "events.hpp"

#include "recognizer.hpp"



class EagerGestureRecognizer : OneSequenceGestureRecognizer {
public:

     EagerGestureRecognizer(Unknown, Unknown);

    void addAllowedPointer(PointerDownEvent event);

    String debugDescription();

    void didStopTrackingLastPointer(int pointer);

    void handleEvent(PointerEvent event);

private:

};

#endif