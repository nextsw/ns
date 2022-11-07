#ifndef GRID_PAPER_H
#define GRID_PAPER_H
#include <memory>

#include "basic.hpp"
#include "framework.hpp"



class _GridPaperPainter : CustomPainter {
public:
    Color color;

    double interval;

    int divisions;

    int subdivisions;


    void paint(Canvas canvas, Size size);

    bool shouldRepaint(_GridPaperPainter oldPainter);

    bool hitTest(Offset position);

private:

     _GridPaperPainter(Color color, int divisions, double interval, int subdivisions);

};

class GridPaper : StatelessWidget {
public:
    Color color;

    double interval;

    int divisions;

    int subdivisions;

    Widget child;


     GridPaper(Widget child, Color color, int divisions, double interval, Unknown, int subdivisions);

    Widget build(BuildContext context);

private:

};

#endif