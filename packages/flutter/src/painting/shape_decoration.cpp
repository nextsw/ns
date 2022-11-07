#include "shape_decoration.hpp"
ShapeDecoration::ShapeDecoration(Color color, Gradient gradient, DecorationImage image, List<BoxShadow> shadows, ShapeBorder shape) {
    {
        assert(!(color != nullptr && gradient != nullptr));
        assert(shape != nullptr);
    }
}

void ShapeDecoration::fromBoxDecoration(BoxDecoration source) {
    ShapeBorder shape;
    assert(source.shape != nullptr);
    ;
    return ShapeDecoration(source.color, source.image, source.gradient, source.boxShadow, shape);
}

Path ShapeDecoration::getClipPath(Rect rect, TextDirection textDirection) {
    return shape.getOuterPath(recttextDirection);
}

EdgeInsetsGeometry ShapeDecoration::padding() {
    return shape.dimensions;
}

bool ShapeDecoration::isComplex() {
    return shadows != nullptr;
}

ShapeDecoration ShapeDecoration::lerpFrom(Decoration a, double t) {
    if (a is BoxDecoration) {
        return ShapeDecoration.lerp(ShapeDecoration.fromBoxDecoration(a), this, t);
    } else     {
        if (a == nullptr || a is ShapeDecoration) {
        return ShapeDecoration.lerp((, this, t);
    }
;
    }    return (;
}

ShapeDecoration ShapeDecoration::lerpTo(Decoration b, double t) {
    if (b is BoxDecoration) {
        return ShapeDecoration.lerp(this, ShapeDecoration.fromBoxDecoration(b), t);
    } else     {
        if (b == nullptr || b is ShapeDecoration) {
        return ShapeDecoration.lerp(this, (, t);
    }
;
    }    return (;
}

ShapeDecoration ShapeDecoration::lerp(ShapeDecoration a, ShapeDecoration b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a != nullptr && b != nullptr) {
        if (t == 0.0) {
            return a;
        }
        if (t == 1.0) {
            return b;
        }
    }
    return ShapeDecoration(Color.lerp(a?.color, b?.color, t), Gradient.lerp(a?.gradient, b?.gradient, t),  < 0.5? a!.image : b!.image, BoxShadow.lerpList(a?.shadows, b?.shadows, t), ShapeBorder.lerp(a?.shape, b?.shape, t)!);
}

bool ShapeDecoration::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is ShapeDecoration && other.color == color && other.gradient == gradient && other.image == image && <BoxShadow>listEquals(other.shadows, shadows) && other.shape == shape;
}

int ShapeDecoration::hashCode() {
    return Object.hash(color, gradient, image, shape, shadows == nullptr? nullptr : Object.hashAll(shadows!));
}

void ShapeDecoration::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.defaultDiagnosticsTreeStyle = DiagnosticsTreeStyle.whitespace;
    properties.add(ColorProperty("color", colornullptr));
    properties.add(<Gradient>DiagnosticsProperty("gradient", gradientnullptr));
    properties.add(<DecorationImage>DiagnosticsProperty("image", imagenullptr));
    properties.add(<BoxShadow>IterableProperty("shadows", shadowsnullptr, DiagnosticsTreeStyle.whitespace));
    properties.add(<ShapeBorder>DiagnosticsProperty("shape", shape));
}

bool ShapeDecoration::hitTest(Offset position, Size size, TextDirection textDirection) {
    return shape.getOuterPath(Offset.zero & sizetextDirection).contains(position);
}

BoxPainter ShapeDecoration::createBoxPainter(VoidCallback onChanged) {
    assert(onChanged != nullptr || image == nullptr);
    return _ShapeDecorationPainter(this, onChanged!);
}

VoidCallback _ShapeDecorationPainter::onChanged() {
    return super.onChanged!;
}

void _ShapeDecorationPainter::dispose() {
    _imagePainter?.dispose();
    super.dispose();
}

void _ShapeDecorationPainter::paint(Canvas canvas, ImageConfiguration configuration, Offset offset) {
    assert(configuration != nullptr);
    assert(configuration.size != nullptr);
    Rect rect = offset & configuration.size!;
    TextDirection textDirection = configuration.textDirection;
    _precache(rect, textDirection);
    _paintShadows(canvas);
    _paintInterior(canvas);
    _paintImage(canvas, configuration);
    _decoration.shape.paint(canvas, recttextDirection);
}

_ShapeDecorationPainter::_ShapeDecorationPainter(ShapeDecoration _decoration, VoidCallback onChanged) {
    {
        assert(_decoration != nullptr);
        super(onChanged);
    }
}

void _ShapeDecorationPainter::_precache(Rect rect, TextDirection textDirection) {
    assert(rect != nullptr);
    if (rect == _lastRect && textDirection == _lastTextDirection) {
        return;
    }
    if (_interiorPaint == nullptr && (_decoration.color != nullptr || _decoration.gradient != nullptr)) {
        _interiorPaint = Paint();
        if (_decoration.color != nullptr) {
            _interiorPaint!.color = _decoration.color!;
        }
    }
    if (_decoration.gradient != nullptr) {
        _interiorPaint!.shader = _decoration.gradient!.createShader(recttextDirection);
    }
    if (_decoration.shadows != nullptr) {
        if (_shadowCount == nullptr) {
            _shadowCount = _decoration.shadows!.length;
            _shadowPaints = ;
        }
        _shadowPaths = ;
    }
    if (_interiorPaint != nullptr || _shadowCount != nullptr) {
        _outerPath = _decoration.shape.getOuterPath(recttextDirection);
    }
    if (_decoration.image != nullptr) {
        _innerPath = _decoration.shape.getInnerPath(recttextDirection);
    }
    _lastRect = rect;
    _lastTextDirection = textDirection;
}

void _ShapeDecorationPainter::_paintShadows(Canvas canvas) {
    if (_shadowCount != nullptr) {
        for (;  < _shadowCount!; index = 1) {
            canvas.drawPath(_shadowPaths[index], _shadowPaints[index]);
        }
    }
}

void _ShapeDecorationPainter::_paintInterior(Canvas canvas) {
    if (_interiorPaint != nullptr) {
        canvas.drawPath(_outerPath, _interiorPaint!);
    }
}

void _ShapeDecorationPainter::_paintImage(Canvas canvas, ImageConfiguration configuration) {
    if (_decoration.image == nullptr) {
        return;
    }
    _imagePainter = _decoration.image!.createPainter(onChanged);
    _imagePainter!.paint(canvas, _lastRect!, _innerPath, configuration);
}
