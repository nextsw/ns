#include "grid_paper.hpp"
void _GridPaperPainter::paint(Canvas canvas, Size size) {
    Paint linePaint = ;
    double allDivisions = (divisions * subdivisions).toDouble();
    for (; x <= size.width; x = interval / allDivisions) {
        linePaint.strokeWidth = (x % interval == 0.0)? 1.0 : (x % (interval / subdivisions) == 0.0)? 0.5 : 0.25;
        canvas.drawLine(Offset(x, 0.0), Offset(x, size.height), linePaint);
    }
    for (; y <= size.height; y = interval / allDivisions) {
        linePaint.strokeWidth = (y % interval == 0.0)? 1.0 : (y % (interval / subdivisions) == 0.0)? 0.5 : 0.25;
        canvas.drawLine(Offset(0.0, y), Offset(size.width, y), linePaint);
    }
}

bool _GridPaperPainter::shouldRepaint(_GridPaperPainter oldPainter) {
    return oldPainter.color != color || oldPainter.interval != interval || oldPainter.divisions != divisions || oldPainter.subdivisions != subdivisions;
}

bool _GridPaperPainter::hitTest(Offset position) {
    return false;
}

GridPaper::GridPaper(Widget child, Color color, int divisions, double interval, Unknown, int subdivisions) {
    {
        assert(divisions > 0, "The "divisions" property must be greater than zero. If there were no divisions, the grid paper would not paint anything.");
        assert(subdivisions > 0, "The "subdivisions" property must be greater than zero. If there were no subdivisions, the grid paper would not paint anything.");
    }
}

Widget GridPaper::build(BuildContext context) {
    return CustomPaint(_GridPaperPainter(color, interval, divisions, subdivisions), child);
}
