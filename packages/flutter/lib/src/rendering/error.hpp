#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_ERROR
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_ERROR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "box.hpp"
#include "object.hpp"

double _kMaxWidth;

double _kMaxHeight;


class RenderErrorBoxCls : public RenderBoxCls {
public:
    String message;

    static EdgeInsets padding;

    static double minimumWidth;

    static Color backgroundColor;

    static TextStyle textStyle;

    static ParagraphStyle paragraphStyle;


     RenderErrorBoxCls(String message);

    virtual double computeMaxIntrinsicWidth(double height);

    virtual double computeMaxIntrinsicHeight(double width);

    virtual bool sizedByParent();

    virtual bool hitTestSelf(Offset position);

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

private:
    Paragraph _paragraph;


    static Color _initBackgroundColor();

    static TextStyle _initTextStyle();

};
using RenderErrorBox = std::shared_ptr<RenderErrorBoxCls>;


#endif