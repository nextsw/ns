#include "notched_shapes.hpp"
Path CircularNotchedRectangleCls::getOuterPath(Rect host, Rect guest) {
    if (guest == nullptr || !host->overlaps(guest)) {
            auto _c1 = make<PathCls>();    _c1.addRect(host);return _c1;
    }
    double notchRadius = guest->width() / 2.0;
    double s1 = 15.0;
    double s2 = 1.0;
    double r = notchRadius;
    double a = -1.0 * r - s2;
    double b = host->top - guest->center()->dy();
    double n2 = math->sqrt(b * b * r * r * (a * a + b * b - r * r));
    double p2xA = ((a * r * r) - n2) / (a * a + b * b);
    double p2xB = ((a * r * r) + n2) / (a * a + b * b);
    double p2yA = math->sqrt(r * r - p2xA * p2xA);
    double p2yB = math->sqrt(r * r - p2xB * p2xB);
    List<Offset> p = <Offset>filled(6, nullptr);
    p[0] = make<OffsetCls>(a - s1, b);
    p[1] = make<OffsetCls>(a, b);
    double cmp =  < 0? -1.0 : 1.0;
    p[2] = cmp * p2yA > cmp * p2yB? make<OffsetCls>(p2xA, p2yA) : make<OffsetCls>(p2xB, p2yB);
    p[3] = make<OffsetCls>(-1.0 * p[2]!->dx(), p[2]!->dy());
    p[4] = make<OffsetCls>(-1.0 * p[1]!->dx(), p[1]!->dy());
    p[5] = make<OffsetCls>(-1.0 * p[0]!->dx(), p[0]!->dy());
    for (;  < p->length(); i += 1) {
        p[i] = p[i]! + guest->center();
    }
    auto _c2 = make<PathCls>();_c2.auto _c3 = moveTo(host->left, host->top);_c3.auto _c4 = lineTo(p[0]!->dx(), p[0]!->dy());_c4.auto _c5 = quadraticBezierTo(p[1]!->dx(), p[1]!->dy(), p[2]!->dx(), p[2]!->dy());_c5.auto _c6 = arcToPoint(p[3]!RadiusCls->circular(notchRadius), false);_c6.auto _c7 = quadraticBezierTo(p[4]!->dx(), p[4]!->dy(), p[5]!->dx(), p[5]!->dy());_c7.auto _c8 = lineTo(host->right, host->top);_c8.auto _c9 = lineTo(host->right, host->bottom);_c9.auto _c10 = lineTo(host->left, host->bottom);_c10.close();_c10;_c9;_c8;_c7;_c6;_c5;_c4;_c3;return _c2;
}

Path AutomaticNotchedShapeCls::getOuterPath(Rect hostRect, Rect guestRect) {
    Path hostPath = host->getOuterPath(hostRect);
    if (guest != nullptr && guestRect != nullptr) {
        Path guestPath = guest!->getOuterPath(guestRect);
        return PathCls->combine(PathOperationCls::difference, hostPath, guestPath);
    }
    return hostPath;
}
