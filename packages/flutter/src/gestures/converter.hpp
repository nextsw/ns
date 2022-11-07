#ifndef CONVERTER_H
#define CONVERTER_H
#include <memory>
#include <ui.hpp>
#include "events.hpp"

#include <ui/ui.hpp>
#include "events.hpp"


int _synthesiseDownButtons(int buttons, PointerDeviceKind kind);


class PointerEventConverter {
public:

    static Iterable<PointerEvent> expand(Iterable<PointerData> data, double devicePixelRatio);

private:

    void  _();

    static double _toLogicalPixels(double devicePixelRatio, double physicalPixels);

};

#endif