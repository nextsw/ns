#include "gradient.hpp"
Color _sample(List<Color> colors, List<double> stops, double t) {
    assert(colors != nullptr);
    assert(colors.isNotEmpty);
    assert(stops != nullptr);
    assert(stops.isNotEmpty);
    assert(t != nullptr);
    if (t <= stops.first) {
        return colors.first;
    }
    if (t >= stops.last) {
        return colors.last;
    }
    int index = stops.lastIndexWhere();
    assert(index != -1);
    return Color.lerp(colors[index], colors[index + 1], (t - stops[index]) / (stops[index + 1] - stops[index]))!;
}

_ColorsAndStops _interpolateColorsAndStops(List<Color> aColors, List<double> aStops, List<Color> bColors, List<double> bStops, double t) {
    assert(aColors.length >= 2);
    assert(bColors.length >= 2);
    assert(aStops.length == aColors.length);
    assert(bStops.length == bColors.length);
    SplayTreeSet<double> stops = ;
    List<double> interpolatedStops = stops.toList(false);
    List<Color> interpolatedColors = interpolatedStops.<Color>map().toList(false);
    return _ColorsAndStops(interpolatedColors, interpolatedStops);
}

Matrix4 GradientRotation::transform(Rect bounds, TextDirection textDirection) {
    assert(bounds != nullptr);
    double sinRadians = math.sin(radians);
    double oneMinusCosRadians = 1 - math.cos(radians);
    Offset center = bounds.center;
    double originX = sinRadians * center.dy + oneMinusCosRadians * center.dx;
    double originY = -sinRadians * center.dx + oneMinusCosRadians * center.dy;
    return ;
}

bool GradientRotation::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is GradientRotation && other.radians == radians;
}

int GradientRotation::hashCode() {
    return radians.hashCode;
}

String GradientRotation::toString() {
    return "${objectRuntimeType(this, 'GradientRotation')}(radians: ${debugFormatDouble(radians)})";
}

Gradient::Gradient(List<Color> colors, List<double> stops, GradientTransform transform) {
    {
        assert(colors != nullptr);
    }
}

Gradient Gradient::lerpFrom(Gradient a, double t) {
    if (a == nullptr) {
        return scale(t);
    }
    return nullptr;
}

Gradient Gradient::lerpTo(Gradient b, double t) {
    if (b == nullptr) {
        return scale(1.0 - t);
    }
    return nullptr;
}

Gradient Gradient::lerp(Gradient a, Gradient b, double t) {
    assert(t != nullptr);
    Gradient result;
    if (b != nullptr) {
        result = b.lerpFrom(a, t);
    }
    if (result == nullptr && a != nullptr) {
        result = a.lerpTo(b, t);
    }
    if (result != nullptr) {
        return result;
    }
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    assert(a != nullptr && b != nullptr);
    return  < 0.5? a!.scale(1.0 - (t * 2.0)) : b!.scale((t - 0.5) * 2.0);
}

List<double> Gradient::_impliedStops() {
    if (stops != nullptr) {
        return stops!;
    }
    assert(colors.length >= 2, "colors list must have at least two colors");
    double separation = 1.0 / (colors.length - 1);
    return <double>generate(colors.length, false);
}

Float64List Gradient::_resolveTransform(Rect bounds, TextDirection textDirection) {
    return transform?.transform(boundstextDirection)?.storage;
}

LinearGradient::LinearGradient(AlignmentGeometry begin, Unknown, AlignmentGeometry end, Unknown, TileMode tileMode, Unknown) {
    {
        assert(begin != nullptr);
        assert(end != nullptr);
        assert(tileMode != nullptr);
    }
}

Shader LinearGradient::createShader(Rect rect, TextDirection textDirection) {
    return ui.Gradient.linear(begin.resolve(textDirection).withinRect(rect), end.resolve(textDirection).withinRect(rect), colors, _impliedStops(), tileMode, _resolveTransform(rect, textDirection));
}

LinearGradient LinearGradient::scale(double factor) {
    return LinearGradient(begin, end, colors.<Color>map().toList(), stops, tileMode);
}

Gradient LinearGradient::lerpFrom(Gradient a, double t) {
    if (a == nullptr || (a is LinearGradient)) {
        return LinearGradient.lerp((, this, t);
    }
    return super.lerpFrom(a, t);
}

Gradient LinearGradient::lerpTo(Gradient b, double t) {
    if (b == nullptr || (b is LinearGradient)) {
        return LinearGradient.lerp(this, (, t);
    }
    return super.lerpTo(b, t);
}

LinearGradient LinearGradient::lerp(LinearGradient a, LinearGradient b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.scale(t);
    }
    if (b == nullptr) {
        return a.scale(1.0 - t);
    }
    _ColorsAndStops interpolated = _interpolateColorsAndStops(a.colors, a._impliedStops(), b.colors, b._impliedStops(), t);
    return LinearGradient(AlignmentGeometry.lerp(a.begin, b.begin, t)!, AlignmentGeometry.lerp(a.end, b.end, t)!, interpolated.colors, interpolated.stops,  < 0.5? a.tileMode : b.tileMode);
}

bool LinearGradient::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is LinearGradient && other.begin == begin && other.end == end && other.tileMode == tileMode && other.transform == transform && <Color>listEquals(other.colors, colors) && <double>listEquals(other.stops, stops);
}

int LinearGradient::hashCode() {
    return Object.hash(begin, end, tileMode, transform, Object.hashAll(colors), stops == nullptr? nullptr : Object.hashAll(stops!));
}

String LinearGradient::toString() {
    List<String> description = ;
    return "${objectRuntimeType(this, 'LinearGradient')}(${description.join(', ')})";
}

RadialGradient::RadialGradient(AlignmentGeometry center, Unknown, AlignmentGeometry focal, double focalRadius, double radius, Unknown, TileMode tileMode, Unknown) {
    {
        assert(center != nullptr);
        assert(radius != nullptr);
        assert(tileMode != nullptr);
        assert(focalRadius != nullptr);
    }
}

Shader RadialGradient::createShader(Rect rect, TextDirection textDirection) {
    return ui.Gradient.radial(center.resolve(textDirection).withinRect(rect), radius * rect.shortestSide, colors, _impliedStops(), tileMode, _resolveTransform(rect, textDirection), focal == nullptr? nullptr : focal!.resolve(textDirection).withinRect(rect), focalRadius * rect.shortestSide);
}

RadialGradient RadialGradient::scale(double factor) {
    return RadialGradient(center, radius, colors.<Color>map().toList(), stops, tileMode, focal, focalRadius);
}

Gradient RadialGradient::lerpFrom(Gradient a, double t) {
    if (a == nullptr || (a is RadialGradient)) {
        return RadialGradient.lerp((, this, t);
    }
    return super.lerpFrom(a, t);
}

Gradient RadialGradient::lerpTo(Gradient b, double t) {
    if (b == nullptr || (b is RadialGradient)) {
        return RadialGradient.lerp(this, (, t);
    }
    return super.lerpTo(b, t);
}

RadialGradient RadialGradient::lerp(RadialGradient a, RadialGradient b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.scale(t);
    }
    if (b == nullptr) {
        return a.scale(1.0 - t);
    }
    _ColorsAndStops interpolated = _interpolateColorsAndStops(a.colors, a._impliedStops(), b.colors, b._impliedStops(), t);
    return RadialGradient(AlignmentGeometry.lerp(a.center, b.center, t)!, math.max(0.0, ui.lerpDouble(a.radius, b.radius, t)!), interpolated.colors, interpolated.stops,  < 0.5? a.tileMode : b.tileMode, AlignmentGeometry.lerp(a.focal, b.focal, t), math.max(0.0, ui.lerpDouble(a.focalRadius, b.focalRadius, t)!));
}

bool RadialGradient::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is RadialGradient && other.center == center && other.radius == radius && other.tileMode == tileMode && other.transform == transform && <Color>listEquals(other.colors, colors) && <double>listEquals(other.stops, stops) && other.focal == focal && other.focalRadius == focalRadius;
}

int RadialGradient::hashCode() {
    return Object.hash(center, radius, tileMode, transform, Object.hashAll(colors), stops == nullptr? nullptr : Object.hashAll(stops!), focal, focalRadius);
}

String RadialGradient::toString() {
    List<String> description = ;
    return "${objectRuntimeType(this, 'RadialGradient')}(${description.join(', ')})";
}

SweepGradient::SweepGradient(AlignmentGeometry center, Unknown, double endAngle, double startAngle, Unknown, TileMode tileMode, Unknown) {
    {
        assert(center != nullptr);
        assert(startAngle != nullptr);
        assert(endAngle != nullptr);
        assert(tileMode != nullptr);
    }
}

Shader SweepGradient::createShader(Rect rect, TextDirection textDirection) {
    return ui.Gradient.sweep(center.resolve(textDirection).withinRect(rect), colors, _impliedStops(), tileMode, startAngle, endAngle, _resolveTransform(rect, textDirection));
}

SweepGradient SweepGradient::scale(double factor) {
    return SweepGradient(center, startAngle, endAngle, colors.<Color>map().toList(), stops, tileMode);
}

Gradient SweepGradient::lerpFrom(Gradient a, double t) {
    if (a == nullptr || (a is SweepGradient)) {
        return SweepGradient.lerp((, this, t);
    }
    return super.lerpFrom(a, t);
}

Gradient SweepGradient::lerpTo(Gradient b, double t) {
    if (b == nullptr || (b is SweepGradient)) {
        return SweepGradient.lerp(this, (, t);
    }
    return super.lerpTo(b, t);
}

SweepGradient SweepGradient::lerp(SweepGradient a, SweepGradient b, double t) {
    assert(t != nullptr);
    if (a == nullptr && b == nullptr) {
        return nullptr;
    }
    if (a == nullptr) {
        return b!.scale(t);
    }
    if (b == nullptr) {
        return a.scale(1.0 - t);
    }
    _ColorsAndStops interpolated = _interpolateColorsAndStops(a.colors, a._impliedStops(), b.colors, b._impliedStops(), t);
    return SweepGradient(AlignmentGeometry.lerp(a.center, b.center, t)!, math.max(0.0, ui.lerpDouble(a.startAngle, b.startAngle, t)!), math.max(0.0, ui.lerpDouble(a.endAngle, b.endAngle, t)!), interpolated.colors, interpolated.stops,  < 0.5? a.tileMode : b.tileMode);
}

bool SweepGradient::==(Object other) {
    if (identical(this, other)) {
        return true;
    }
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is SweepGradient && other.center == center && other.startAngle == startAngle && other.endAngle == endAngle && other.tileMode == tileMode && other.transform == transform && <Color>listEquals(other.colors, colors) && <double>listEquals(other.stops, stops);
}

int SweepGradient::hashCode() {
    return Object.hash(center, startAngle, endAngle, tileMode, transform, Object.hashAll(colors), stops == nullptr? nullptr : Object.hashAll(stops!));
}

String SweepGradient::toString() {
    List<String> description = ;
    return "${objectRuntimeType(this, 'SweepGradient')}(${description.join(', ')})";
}
