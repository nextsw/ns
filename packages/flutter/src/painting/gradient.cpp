#include "gradient.hpp"
Color _sample(List<Color> colors, List<double> stops, double t) {
    assert(colors != nullptr);
    assert(colors->isNotEmpty());
    assert(stops != nullptr);
    assert(stops->isNotEmpty());
    assert(t != nullptr);
    if (t <= stops->first) {
        return colors->first;
    }
    if (t >= stops->last) {
        return colors->last;
    }
    int index = stops->lastIndexWhere([=] (double s) {
    s <= t;
});
    assert(index != -1);
    return ColorCls->lerp(colors[index], colors[index + 1], (t - stops[index]) / (stops[index + 1] - stops[index]))!;
}

_ColorsAndStops _interpolateColorsAndStops(List<Color> aColors, List<double> aStops, List<Color> bColors, List<double> bStops, double t) {
    assert(aColors->length() >= 2);
    assert(bColors->length() >= 2);
    assert(aStops->length() == aColors->length());
    assert(bStops->length() == bColors->length());
    auto _c1 = <double>make<SplayTreeSetCls>();_c1.auto _c2 = addAll(aStops);_c2.addAll(bStops);_c2;SplayTreeSet<double> stops = _c1;
    List<double> interpolatedStops = stops->toList(false);
    List<Color> interpolatedColors = interpolatedStops-><Color>map([=] (double stop) {
    ColorCls->lerp(_sample(aColors, aStops, stop), _sample(bColors, bStops, stop), t)!;
})->toList(false);
    return make<_ColorsAndStopsCls>(interpolatedColors, interpolatedStops);
}

Matrix4 GradientRotationCls::transform(Rect bounds, TextDirection textDirection) {
    assert(bounds != nullptr);
    double sinRadians = math->sin(radians);
    double oneMinusCosRadians = 1 - math->cos(radians);
    Offset center = bounds->center();
    double originX = sinRadians * center->dy() + oneMinusCosRadians * center->dx();
    double originY = -sinRadians * center->dx() + oneMinusCosRadians * center->dy();
    auto _c1 = Matrix4Cls->identity();_c1.auto _c2 = translate(originX, originY);_c2.rotateZ(radians);_c2;return _c1;
}

bool GradientRotationCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<GradientRotation>(other) && other->radians == radians;
}

int GradientRotationCls::hashCode() {
    return radians->hashCode();
}

String GradientRotationCls::toString() {
    return __s("%s$%s;");
}

GradientCls::GradientCls(List<Color> colors, List<double> stops, GradientTransform transform) {
    {
        assert(colors != nullptr);
    }
}

Gradient GradientCls::lerpFrom(Gradient a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    return nullptr;
}

Gradient GradientCls::lerpTo(Gradient b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    return nullptr;
}

Gradient GradientCls::lerp(Gradient a, Gradient b, double t) {
    assert(t != nullptr);
    Gradient result;
    if (b != nullptr) {
        result = b->lerpFrom(a, t);
    }
    if (result == nullptr && a != nullptr) {
        result = a->lerpTo(b, t);
    }
    if (result != nullptr) {
        return result;
    }
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    assert(a != nullptr && b != nullptr);
    return  < 0.5? a!->scale(1.0 - (t * 2.0)) : b!->scale((t - 0.5) * 2.0);
}

List<double> GradientCls::_impliedStops() {
    if (stops != nullptr) {
        return stops!;
    }
    assert(colors->length() >= 2, __s("colors list must have at least two colors"));
    double separation = 1.0 / (colors->length() - 1);
    return <double>generate(colors->length(), [=] (int index) {
        index * separation;
    }, false);
}

Float64List GradientCls::_resolveTransform(Rect bounds, TextDirection textDirection) {
    return transform?->transform(bounds, textDirection)?->storage();
}

LinearGradientCls::LinearGradientCls(AlignmentGeometry begin, List<Color> colors, AlignmentGeometry end, List<double> stops, TileMode tileMode, GradientTransform transform) {
    {
        assert(begin != nullptr);
        assert(end != nullptr);
        assert(tileMode != nullptr);
    }
}

Shader LinearGradientCls::createShader(Rect rect, TextDirection textDirection) {
    return ui->GradientCls->linear(begin->resolve(textDirection)->withinRect(rect), end->resolve(textDirection)->withinRect(rect), colors, _impliedStops(), tileMode, _resolveTransform(rect, textDirection));
}

LinearGradient LinearGradientCls::scale(double factor) {
    return make<LinearGradientCls>(begin, end, colors-><Color>map([=] (Color color) {
        ColorCls->lerp(nullptr, color, factor)!;
    })->toList(), stops, tileMode);
}

Gradient LinearGradientCls::lerpFrom(Gradient a, double t) {
    if (a == nullptr || (is<LinearGradient>(a))) {
        return LinearGradientCls->lerp(as<LinearGradient>(a), this, t);
    }
    return super->lerpFrom(a, t);
}

Gradient LinearGradientCls::lerpTo(Gradient b, double t) {
    if (b == nullptr || (is<LinearGradient>(b))) {
        return LinearGradientCls->lerp(this, as<LinearGradient>(b), t);
    }
    return super->lerpTo(b, t);
}

LinearGradient LinearGradientCls::lerp(LinearGradient a, LinearGradient b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->scale(t);
    }
    if (b == nullptr) {
        return a->scale(1.0 - t);
    }
    _ColorsAndStops interpolated = _interpolateColorsAndStops(a->colors, a->_impliedStops(), b->colors, b->_impliedStops(), t);
    return make<LinearGradientCls>(AlignmentGeometryCls->lerp(a->begin, b->begin, t)!, AlignmentGeometryCls->lerp(a->end, b->end, t)!, interpolated->colors, interpolated->stops,  < 0.5? a->tileMode : b->tileMode);
}

bool LinearGradientCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<LinearGradient>(other) && other->begin == begin && other->end == end && other->tileMode == tileMode && other->transform == transform && <Color>listEquals(other->colors, colors) && <double>listEquals(other->stops, stops);
}

int LinearGradientCls::hashCode() {
    return ObjectCls->hash(begin, end, tileMode, transform, ObjectCls->hashAll(colors), stops == nullptr? nullptr : ObjectCls->hashAll(stops!));
}

String LinearGradientCls::toString() {
    List<String> list1 = make<ListCls<>>();list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);if (stops != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);if (transform != nullptr) {    list1.add(ArrayItem);}List<String> description = list1;
    return __s("%s$%s;");
}

RadialGradientCls::RadialGradientCls(AlignmentGeometry center, List<Color> colors, AlignmentGeometry focal, double focalRadius, double radius, List<double> stops, TileMode tileMode, GradientTransform transform) {
    {
        assert(center != nullptr);
        assert(radius != nullptr);
        assert(tileMode != nullptr);
        assert(focalRadius != nullptr);
    }
}

Shader RadialGradientCls::createShader(Rect rect, TextDirection textDirection) {
    return ui->GradientCls->radial(center->resolve(textDirection)->withinRect(rect), radius * rect->shortestSide(), colors, _impliedStops(), tileMode, _resolveTransform(rect, textDirection), focal == nullptr? nullptr : focal!->resolve(textDirection)->withinRect(rect), focalRadius * rect->shortestSide());
}

RadialGradient RadialGradientCls::scale(double factor) {
    return make<RadialGradientCls>(center, radius, colors-><Color>map([=] (Color color) {
        ColorCls->lerp(nullptr, color, factor)!;
    })->toList(), stops, tileMode, focal, focalRadius);
}

Gradient RadialGradientCls::lerpFrom(Gradient a, double t) {
    if (a == nullptr || (is<RadialGradient>(a))) {
        return RadialGradientCls->lerp(as<RadialGradient>(a), this, t);
    }
    return super->lerpFrom(a, t);
}

Gradient RadialGradientCls::lerpTo(Gradient b, double t) {
    if (b == nullptr || (is<RadialGradient>(b))) {
        return RadialGradientCls->lerp(this, as<RadialGradient>(b), t);
    }
    return super->lerpTo(b, t);
}

RadialGradient RadialGradientCls::lerp(RadialGradient a, RadialGradient b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->scale(t);
    }
    if (b == nullptr) {
        return a->scale(1.0 - t);
    }
    _ColorsAndStops interpolated = _interpolateColorsAndStops(a->colors, a->_impliedStops(), b->colors, b->_impliedStops(), t);
    return make<RadialGradientCls>(AlignmentGeometryCls->lerp(a->center, b->center, t)!, math->max(0.0, ui->lerpDouble(a->radius, b->radius, t)!), interpolated->colors, interpolated->stops,  < 0.5? a->tileMode : b->tileMode, AlignmentGeometryCls->lerp(a->focal, b->focal, t), math->max(0.0, ui->lerpDouble(a->focalRadius, b->focalRadius, t)!));
}

bool RadialGradientCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<RadialGradient>(other) && other->center == center && other->radius == radius && other->tileMode == tileMode && other->transform == transform && <Color>listEquals(other->colors, colors) && <double>listEquals(other->stops, stops) && other->focal == focal && other->focalRadius == focalRadius;
}

int RadialGradientCls::hashCode() {
    return ObjectCls->hash(center, radius, tileMode, transform, ObjectCls->hashAll(colors), stops == nullptr? nullptr : ObjectCls->hashAll(stops!), focal, focalRadius);
}

String RadialGradientCls::toString() {
    List<String> list1 = make<ListCls<>>();list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);if (stops != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);if (focal != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);if (transform != nullptr) {    list1.add(ArrayItem);}List<String> description = list1;
    return __s("%s$%s;");
}

SweepGradientCls::SweepGradientCls(AlignmentGeometry center, List<Color> colors, double endAngle, double startAngle, List<double> stops, TileMode tileMode, GradientTransform transform) {
    {
        assert(center != nullptr);
        assert(startAngle != nullptr);
        assert(endAngle != nullptr);
        assert(tileMode != nullptr);
    }
}

Shader SweepGradientCls::createShader(Rect rect, TextDirection textDirection) {
    return ui->GradientCls->sweep(center->resolve(textDirection)->withinRect(rect), colors, _impliedStops(), tileMode, startAngle, endAngle, _resolveTransform(rect, textDirection));
}

SweepGradient SweepGradientCls::scale(double factor) {
    return make<SweepGradientCls>(center, startAngle, endAngle, colors-><Color>map([=] (Color color) {
        ColorCls->lerp(nullptr, color, factor)!;
    })->toList(), stops, tileMode);
}

Gradient SweepGradientCls::lerpFrom(Gradient a, double t) {
    if (a == nullptr || (is<SweepGradient>(a))) {
        return SweepGradientCls->lerp(as<SweepGradient>(a), this, t);
    }
    return super->lerpFrom(a, t);
}

Gradient SweepGradientCls::lerpTo(Gradient b, double t) {
    if (b == nullptr || (is<SweepGradient>(b))) {
        return SweepGradientCls->lerp(this, as<SweepGradient>(b), t);
    }
    return super->lerpTo(b, t);
}

SweepGradient SweepGradientCls::lerp(SweepGradient a, SweepGradient b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!->scale(t);
    }
    if (b == nullptr) {
        return a->scale(1.0 - t);
    }
    _ColorsAndStops interpolated = _interpolateColorsAndStops(a->colors, a->_impliedStops(), b->colors, b->_impliedStops(), t);
    return make<SweepGradientCls>(AlignmentGeometryCls->lerp(a->center, b->center, t)!, math->max(0.0, ui->lerpDouble(a->startAngle, b->startAngle, t)!), math->max(0.0, ui->lerpDouble(a->endAngle, b->endAngle, t)!), interpolated->colors, interpolated->stops,  < 0.5? a->tileMode : b->tileMode);
}

bool SweepGradientCls::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<SweepGradient>(other) && other->center == center && other->startAngle == startAngle && other->endAngle == endAngle && other->tileMode == tileMode && other->transform == transform && <Color>listEquals(other->colors, colors) && <double>listEquals(other->stops, stops);
}

int SweepGradientCls::hashCode() {
    return ObjectCls->hash(center, startAngle, endAngle, tileMode, transform, ObjectCls->hashAll(colors), stops == nullptr? nullptr : ObjectCls->hashAll(stops!));
}

String SweepGradientCls::toString() {
    List<String> list1 = make<ListCls<>>();list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);list1.add(ArrayItem);if (stops != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);if (transform != nullptr) {    list1.add(ArrayItem);}List<String> description = list1;
    return __s("%s$%s;");
}
