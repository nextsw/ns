#include "pointer.hpp"
String PointerDataCls::toString() {
    return __sf("PointerData(x: %s, y: %s)", physicalX, physicalY);
}

String PointerDataCls::toStringFull() {
    return __sf("%s(embedderId: %s, timeStamp: %s, change: %s, kind: %s, signalKind: %s, device: %s, pointerIdentifier: %s, physicalX: %s, physicalY: %s, physicalDeltaX: %s, physicalDeltaY: %s, buttons: %s, synthesized: %s, pressure: %s, pressureMin: %s, pressureMax: %s, distance: %s, distanceMax: %s, size: %s, radiusMajor: %s, radiusMinor: %s, radiusMin: %s, radiusMax: %s, orientation: %s, tilt: %s, platformData: %s, scrollDeltaX: %s, scrollDeltaY: %s, panX: %s, panY: %s, panDeltaX: %s, panDeltaY: %s, scale: %s, rotation: %s)", runtimeType, embedderId, timeStamp, change, kind, signalKind, device, pointerIdentifier, physicalX, physicalY, physicalDeltaX, physicalDeltaY, buttons, synthesized, pressure, pressureMin, pressureMax, distance, distanceMax, size, radiusMajor, radiusMinor, radiusMin, radiusMax, orientation, tilt, platformData, scrollDeltaX, scrollDeltaY, panX, panY, panDeltaX, panDeltaY, scale, rotation);
}

PointerDataPacketCls::PointerDataPacketCls(List<PointerData> data) {
    {
        assert(data != nullptr);
    }
}
