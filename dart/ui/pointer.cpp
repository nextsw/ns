#include "pointer.hpp"
String PointerDataCls::toString() {
    return __s("PointerData(x: %s$%s;");
}

String PointerDataCls::toStringFull() {
    return __s("%sembedderId: $%stimeStamp: $%schange: $%skind: $%ssignalKind: $%sdevice: $%spointerIdentifier: $%sphysicalX: $%sphysicalY: $%sphysicalDeltaX: $%sphysicalDeltaY: $%sbuttons: $%ssynthesized: $%spressure: $%spressureMin: $%spressureMax: $%sdistance: $%sdistanceMax: $%ssize: $%sradiusMajor: $%sradiusMinor: $%sradiusMin: $%sradiusMax: $%sorientation: $%stilt: $%splatformData: $%sscrollDeltaX: $%sscrollDeltaY: $%spanX: $%spanY: $%spanDeltaX: $%spanDeltaY: $%sscale: $%srotation: $%s);");
}

PointerDataPacketCls::PointerDataPacketCls(List<PointerData> data) {
    {
        assert(data != nullptr);
    }
}
