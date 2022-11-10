#include "pointer.hpp"
String PointerDataCls::toString() {
    return __s("PointerData(x: $physicalX, y: $physicalY)");
}

String PointerDataCls::toStringFull() {
    return __s("$runtimeType(embedderId: $embedderId, timeStamp: $timeStamp, change: $change, kind: $kind, signalKind: $signalKind, device: $device, pointerIdentifier: $pointerIdentifier, physicalX: $physicalX, physicalY: $physicalY, physicalDeltaX: $physicalDeltaX, physicalDeltaY: $physicalDeltaY, buttons: $buttons, synthesized: $synthesized, pressure: $pressure, pressureMin: $pressureMin, pressureMax: $pressureMax, distance: $distance, distanceMax: $distanceMax, size: $size, radiusMajor: $radiusMajor, radiusMinor: $radiusMinor, radiusMin: $radiusMin, radiusMax: $radiusMax, orientation: $orientation, tilt: $tilt, platformData: $platformData, scrollDeltaX: $scrollDeltaX, scrollDeltaY: $scrollDeltaY, panX: $panX, panY: $panY, panDeltaX: $panDeltaX, panDeltaY: $panDeltaY, scale: $scale, rotation: $rotation)");
}

PointerDataPacketCls::PointerDataPacketCls(List<PointerData> data) {
    {
        assert(data != nullptr);
    }
}
