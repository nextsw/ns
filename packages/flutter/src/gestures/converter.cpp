#include "converter.hpp"
int _synthesiseDownButtons(int buttons, PointerDeviceKind kind) {
    ;
}

Iterable<PointerEvent> PointerEventConverterCls::expand(Iterable<PointerData> data, double devicePixelRatio) {
    return data->where([=] (PointerData datum)     {
        datum->signalKind != ui->PointerSignalKindCls::unknown;
    })->map([=] (PointerData datum) {
        Offset position = make<OffsetCls>(datum->physicalX, datum->physicalY) / devicePixelRatio;
        assert(position != nullptr);
        Offset delta = make<OffsetCls>(datum->physicalDeltaX, datum->physicalDeltaY) / devicePixelRatio;
        double radiusMinor = _toLogicalPixels(datum->radiusMinor, devicePixelRatio);
        double radiusMajor = _toLogicalPixels(datum->radiusMajor, devicePixelRatio);
        double radiusMin = _toLogicalPixels(datum->radiusMin, devicePixelRatio);
        double radiusMax = _toLogicalPixels(datum->radiusMax, devicePixelRatio);
        Duration timeStamp = datum->timeStamp;
        PointerDeviceKind kind = datum->kind;
        assert(datum->change != nullptr);
        ;
    });
}

double PointerEventConverterCls::_toLogicalPixels(double devicePixelRatio, double physicalPixels) {
    return physicalPixels / devicePixelRatio;
}
