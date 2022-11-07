#include "converter.hpp"
int _synthesiseDownButtons(int buttons, PointerDeviceKind kind) {
    ;
}

Iterable<PointerEvent> PointerEventConverter::expand(Iterable<PointerData> data, double devicePixelRatio) {
    return data.where().map();
}

double PointerEventConverter::_toLogicalPixels(double devicePixelRatio, double physicalPixels) {
    return physicalPixels / devicePixelRatio;
}
