#include "grid_paper.hpp"
void _GridPaperPainterCls::paint(Canvas canvas, Size size) {
    auto _c1 = make<PaintCls>();_c1.color = color;Paint linePaint = _c1;
    double allDivisions = (divisions * subdivisions)->toDouble();
    for (; x <= size->width(); x += interval / allDivisions) {
        linePaint->strokeWidth() = (x % interval == 0.0)? 1.0 : (x % (interval / subdivisions) == 0.0)? 0.5 : 0.25;
        canvas->drawLine(make<OffsetCls>(x, 0.0), make<OffsetCls>(x, size->height()), linePaint);
    }
    for (; y <= size->height(); y += interval / allDivisions) {
        linePaint->strokeWidth() = (y % interval == 0.0)? 1.0 : (y % (interval / subdivisions) == 0.0)? 0.5 : 0.25;
        canvas->drawLine(make<OffsetCls>(0.0, y), make<OffsetCls>(size->width(), y), linePaint);
    }
}

bool _GridPaperPainterCls::shouldRepaint(_GridPaperPainter oldPainter) {
    return oldPainter->color != color || oldPainter->interval != interval || oldPainter->divisions != divisions || oldPainter->subdivisions != subdivisions;
}

bool _GridPaperPainterCls::hitTest(Offset position) {
    return false;
}

GridPaperCls::GridPaperCls(Widget child, Color color, int divisions, double interval, Key key, int subdivisions) {
    {
        assert(divisions > 0, __s("The "divisions" property must be greater than zero. If there were no divisions, the grid paper would not paint anything."));
        assert(subdivisions > 0, __s("The "subdivisions" property must be greater than zero. If there were no subdivisions, the grid paper would not paint anything."));
    }
}

Widget GridPaperCls::build(BuildContext context) {
    return make<CustomPaintCls>(make<_GridPaperPainterCls>(color, interval, divisions, subdivisions), child);
}
