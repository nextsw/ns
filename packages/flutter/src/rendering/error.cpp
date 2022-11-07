#include "error.hpp"
RenderErrorBox::RenderErrorBox(String message) {
    {
        ;
    }
}

double RenderErrorBox::computeMaxIntrinsicWidth(double height) {
    return _kMaxWidth;
}

double RenderErrorBox::computeMaxIntrinsicHeight(double width) {
    return _kMaxHeight;
}

bool RenderErrorBox::sizedByParent() {
    return true;
}

bool RenderErrorBox::hitTestSelf(Offset position) {
    return true;
}

Size RenderErrorBox::computeDryLayout(BoxConstraints constraints) {
    return constraints.constrain(const Size(_kMaxWidth, _kMaxHeight));
}

void RenderErrorBox::paint(PaintingContext context, Offset offset) {
    ;
}

Color RenderErrorBox::_initBackgroundColor() {
    Color result = const Color(0xF0C0C0C0);
    assert(());
    return result;
}

TextStyle RenderErrorBox::_initTextStyle() {
    TextStyle result = ui.TextStyle(const Color(0xFF303030), "sans-serif", 18.0);
    assert(());
    return result;
}
