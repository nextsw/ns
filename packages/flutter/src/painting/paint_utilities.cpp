#include "paint_utilities.hpp"
void paintZigZag(Canvas canvas, Offset end, Paint paint, Offset start, double width, int zigs) {
    assert(zigs->isFinite);
    assert(zigs > 0);
    canvas->save();
    canvas->translate(start->dx(), start->dy());
    end = end - start;
    canvas->rotate(math->atan2(end->dy(), end->dx()));
    double length = end->distance();
    double spacing = length / (zigs * 2.0);
    auto _c1 = make<PathCls>();_c1.moveTo(0.0, 0.0);Path path = _c1;
    for (;  < zigs; index = 1) {
        double x = (index * 2.0 + 1.0) * spacing;
        double y = width * ((index % 2.0) * 2.0 - 1.0);
        path->lineTo(x, y);
    }
    path->lineTo(length, 0.0);
    canvas->drawPath(path, paint);
    canvas->restore();
}
