#include "notched_shapes.hpp"
Path CircularNotchedRectangle::getOuterPath(Rect guest, Rect host) {
    if (guest == nullptr || !host.overlaps(guest)) {
        return ;
    }
    double notchRadius = guest.width / 2.0;
    double s1 = 15.0;
    double s2 = 1.0;
    double r = notchRadius;
    double a = -1.0 * r - s2;
    double b = host.top - guest.center.dy;
    double n2 = math.sqrt(b * b * r * r * (a * a + b * b - r * r));
    double p2xA = ((a * r * r) - n2) / (a * a + b * b);
    double p2xB = ((a * r * r) + n2) / (a * a + b * b);
    double p2yA = math.sqrt(r * r - p2xA * p2xA);
    double p2yB = math.sqrt(r * r - p2xB * p2xB);
    List<Offset> p = <Offset>filled(6, nullptr);
    p[0] = Offset(a - s1, b);
    p[1] = Offset(a, b);
    double cmp =  < 0? -1.0 : 1.0;
    p[2] = cmp * p2yA > cmp * p2yB? Offset(p2xA, p2yA) : Offset(p2xB, p2yB);
    p[3] = Offset(-1.0 * p[2]!.dx, p[2]!.dy);
    p[4] = Offset(-1.0 * p[1]!.dx, p[1]!.dy);
    p[5] = Offset(-1.0 * p[0]!.dx, p[0]!.dy);
    for (;  < p.length; i = 1) {
        p[i] = p[i]! + guest.center;
    }
    return ;
}

Path AutomaticNotchedShape::getOuterPath(Rect guestRect, Rect hostRect) {
    Path hostPath = host.getOuterPath(hostRect);
    if (guest != nullptr && guestRect != nullptr) {
        Path guestPath = guest!.getOuterPath(guestRect);
        return Path.combine(PathOperation.difference, hostPath, guestPath);
    }
    return hostPath;
}
