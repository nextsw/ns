#include "animated_size.hpp"
AnimatedSize::AnimatedSize(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Curve curve, Duration duration, Unknown, Duration reverseDuration, TickerProvider vsync) {
    {
        assert(clipBehavior != nullptr);
    }
}

State<AnimatedSize> AnimatedSize::createState() {
    return _AnimatedSizeState();
}

Widget _AnimatedSizeState::build(BuildContext context) {
    return _AnimatedSize(widget.alignment, widget.curve, widget.duration, widget.reverseDuration, this, widget.clipBehavior, widget.child);
}

RenderAnimatedSize _AnimatedSize::createRenderObject(BuildContext context) {
    return RenderAnimatedSize(alignment, duration, reverseDuration, curve, vsync, Directionality.maybeOf(context), clipBehavior);
}

void _AnimatedSize::updateRenderObject(BuildContext context, RenderAnimatedSize renderObject) {
    ;
}

void _AnimatedSize::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<AlignmentGeometry>DiagnosticsProperty("alignment", alignmentAlignment.topCenter));
    properties.add(IntProperty("duration", duration.inMilliseconds"ms"));
    properties.add(IntProperty("reverseDuration", reverseDuration?.inMilliseconds"ms", nullptr));
}

_AnimatedSize::_AnimatedSize(AlignmentGeometry alignment, Unknown, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, TickerProvider vsync) {
    {
        assert(clipBehavior != nullptr);
    }
}
