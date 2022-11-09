#ifndef DART_UI_POINTER
#define DART_UI_POINTER
#include <base.hpp>

#include <dart/core/core.hpp>


enum PointerChange{
    cancel,
    add,
    remove,
    hover,
    down,
    move,
    up,
    panZoomStart,
    panZoomUpdate,
    panZoomEnd,
} // end PointerChange

enum PointerDeviceKind{
    touch,
    mouse,
    stylus,
    invertedStylus,
    trackpad,
    unknown,
} // end PointerDeviceKind

enum PointerSignalKind{
    none,
    scroll,
    unknown,
} // end PointerSignalKind

class PointerDataCls : public ObjectCls {
public:
    int embedderId;

    Duration timeStamp;

    PointerChange change;

    PointerDeviceKind kind;

    PointerSignalKind signalKind;

    int device;

    int pointerIdentifier;

    double physicalX;

    double physicalY;

    double physicalDeltaX;

    double physicalDeltaY;

    int buttons;

    bool obscured;

    bool synthesized;

    double pressure;

    double pressureMin;

    double pressureMax;

    double distance;

    double distanceMax;

    double size;

    double radiusMajor;

    double radiusMinor;

    double radiusMin;

    double radiusMax;

    double orientation;

    double tilt;

    int platformData;

    double scrollDeltaX;

    double scrollDeltaY;

    double panX;

    double panY;

    double panDeltaX;

    double panDeltaY;

    double scale;

    double rotation;


     PointerDataCls(int buttons, PointerChange change, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, double panDeltaX, double panDeltaY, double panX, double panY, double physicalDeltaX, double physicalDeltaY, double physicalX, double physicalY, int platformData, int pointerIdentifier, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double rotation, double scale, double scrollDeltaX, double scrollDeltaY, PointerSignalKind signalKind, double size, bool synthesized, double tilt, Duration timeStamp);
    virtual String toString();

    virtual String toStringFull();

private:

};
using PointerData = std::shared_ptr<PointerDataCls>;

class PointerDataPacketCls : public ObjectCls {
public:
    List<PointerData> data;


     PointerDataPacketCls(List<PointerData> data);

private:

};
using PointerDataPacket = std::shared_ptr<PointerDataPacketCls>;


#endif