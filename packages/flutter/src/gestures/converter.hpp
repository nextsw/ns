#ifndef PACKAGES_FLUTTER_SRC_GESTURES_CONVERTER
#define PACKAGES_FLUTTER_SRC_GESTURES_CONVERTER
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include "events.hpp"

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "events.hpp"

int _synthesiseDownButtons(int buttons, PointerDeviceKind kind);


class PointerEventConverterCls : public ObjectCls {
public:

    static Iterable<PointerEvent> expand(Iterable<PointerData> data, double devicePixelRatio);

private:

    virtual void  _();
    static double _toLogicalPixels(double physicalPixels, double devicePixelRatio);

};
using PointerEventConverter = std::shared_ptr<PointerEventConverterCls>;


#endif