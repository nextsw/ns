#ifndef ERROR_H
#define ERROR_H
#include <memory>

#include <ui/ui.hpp>
#include "box.hpp"
#include "object.hpp"


const double _kMaxWidth;

const double _kMaxHeight;


class RenderErrorBox : RenderBox {
public:
    String message;

    static EdgeInsets padding;

    static double minimumWidth;

    static Color backgroundColor;

    static TextStyle textStyle;

    static ParagraphStyle paragraphStyle;


     RenderErrorBox(String message);

    double computeMaxIntrinsicWidth(double height);

    double computeMaxIntrinsicHeight(double width);

    bool sizedByParent();

    bool hitTestSelf(Offset position);

    Size computeDryLayout(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

private:
    Paragraph _paragraph;


    static Color _initBackgroundColor();

    static TextStyle _initTextStyle();

};

#endif