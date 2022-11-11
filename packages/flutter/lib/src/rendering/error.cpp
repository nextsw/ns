#include "error.hpp"
RenderErrorBoxCls::RenderErrorBoxCls(String message) {
    {
        try {
            if (message != __s("")) {
                ParagraphBuilder builder = ui->make<ParagraphBuilderCls>(paragraphStyle);
                builder->pushStyle(textStyle);
                builder->addText(message);
                _paragraph = builder->build();
            } else {
                _paragraph = nullptr;
            }
        } catch (Unknown error) {
        };
    }
}

double RenderErrorBoxCls::computeMaxIntrinsicWidth(double height) {
    return _kMaxWidth;
}

double RenderErrorBoxCls::computeMaxIntrinsicHeight(double width) {
    return _kMaxHeight;
}

bool RenderErrorBoxCls::sizedByParent() {
    return true;
}

bool RenderErrorBoxCls::hitTestSelf(Offset position) {
    return true;
}

Size RenderErrorBoxCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->constrain(make<SizeCls>(_kMaxWidth, _kMaxHeight));
}

void RenderErrorBoxCls::paint(PaintingContext context, Offset offset) {
    try {
            auto _c1 = make<PaintCls>();    _c1.color = backgroundColor;context->canvas()->drawRect(offset & size, _c1);
        if (_paragraph != nullptr) {
            double width = size->width;
            double left = 0.0;
            double top = 0.0;
            if (width > padding->left + minimumWidth + padding->right) {
                width -= padding->left + padding->right;
                left += padding->left;
            }
            _paragraph!->layout(ui->make<ParagraphConstraintsCls>(width));
            if (size->height > padding->top + _paragraph!->height() + padding->bottom) {
                top += padding->top;
            }
            context->canvas()->drawParagraph(_paragraph!, offset + make<OffsetCls>(left, top));
        }
    } catch (Unknown error) {
    };
}

Color RenderErrorBoxCls::_initBackgroundColor() {
    Color result = make<ColorCls>(0xF0C0C0C0);
    assert([=] () {
        result = make<ColorCls>(0xF0900000);
        return true;
    }());
    return result;
}

TextStyle RenderErrorBoxCls::_initTextStyle() {
    TextStyle result = ui->make<TextStyleCls>(make<ColorCls>(0xFF303030), __s("sans-serif"), 18.0);
    assert([=] () {
        result = ui->make<TextStyleCls>(make<ColorCls>(0xFFFFFF66), __s("monospace"), 14.0, FontWeightCls::bold);
        return true;
    }());
    return result;
}
