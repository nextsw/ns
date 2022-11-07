#ifndef POINTER_H
#define POINTER_H
#include <memory>




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

class PointerData {
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


     PointerData(int buttons, PointerChange change, int device, double distance, double distanceMax, int embedderId, PointerDeviceKind kind, bool obscured, double orientation, double panDeltaX, double panDeltaY, double panX, double panY, double physicalDeltaX, double physicalDeltaY, double physicalX, double physicalY, int platformData, int pointerIdentifier, double pressure, double pressureMax, double pressureMin, double radiusMajor, double radiusMax, double radiusMin, double radiusMinor, double rotation, double scale, double scrollDeltaX, double scrollDeltaY, PointerSignalKind signalKind, double size, bool synthesized, double tilt, Duration timeStamp);

    String toString();

    String toStringFull();

private:

};

class PointerDataPacket {
public:
    List<PointerData> data;


     PointerDataPacket(List<PointerData> data);

private:

};

#endif