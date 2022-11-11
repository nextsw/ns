#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_GRID_PAPER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_GRID_PAPER
#include <base.hpp>

#include <dart/core/core.hpp>
#include "basic.hpp"
#include "framework.hpp"


class _GridPaperPainterCls : public CustomPainterCls {
public:
    Color color;

    double interval;

    int divisions;

    int subdivisions;


    virtual void paint(Canvas canvas, Size size);

    virtual bool shouldRepaint(_GridPaperPainter oldPainter);

    virtual bool hitTest(Offset position);

private:

     _GridPaperPainterCls(Color color, int divisions, double interval, int subdivisions);
};
using _GridPaperPainter = std::shared_ptr<_GridPaperPainterCls>;

class GridPaperCls : public StatelessWidgetCls {
public:
    Color color;

    double interval;

    int divisions;

    int subdivisions;

    Widget child;


     GridPaperCls(Widget child, Color color, int divisions, double interval, Key key, int subdivisions);

    virtual Widget build(BuildContext context);

private:

};
using GridPaper = std::shared_ptr<GridPaperCls>;


#endif