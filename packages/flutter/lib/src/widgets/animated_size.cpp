#include "animated_size.hpp"
AnimatedSizeCls::AnimatedSizeCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Curve curve, Duration duration, Key key, Duration reverseDuration, TickerProvider vsync) {
    {
        assert(clipBehavior != nullptr);
    }
}

State<AnimatedSize> AnimatedSizeCls::createState() {
    return make<_AnimatedSizeStateCls>();
}

Widget _AnimatedSizeStateCls::build(BuildContext context) {
    return make<_AnimatedSizeCls>(widget()->alignment, widget()->curve, widget()->duration, widget()->reverseDuration, this, widget()->clipBehavior, widget()->child);
}

RenderAnimatedSize _AnimatedSizeCls::createRenderObject(BuildContext context) {
    return make<RenderAnimatedSizeCls>(alignment, duration, reverseDuration, curve, vsync, DirectionalityCls->maybeOf(context), clipBehavior);
}

void _AnimatedSizeCls::updateRenderObject(BuildContext context, RenderAnimatedSize renderObject) {
    auto _c1 = renderObject;_c1.alignment = auto _c2 = alignment;_c2.duration = auto _c3 = duration;_c3.reverseDuration = auto _c4 = reverseDuration;_c4.curve = auto _c5 = curve;_c5.vsync = auto _c6 = vsync;_c6.textDirection = auto _c7 = DirectionalityCls->maybeOf(context);_c7.clipBehavior = clipBehavior;_c7;_c6;_c5;_c4;_c3;_c2;_c1;
}

void _AnimatedSizeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<AlignmentGeometry>make<DiagnosticsPropertyCls>(__s("alignment"), alignment, AlignmentCls::topCenter));
    properties->add(make<IntPropertyCls>(__s("duration"), duration->inMilliseconds(), __s("ms")));
    properties->add(make<IntPropertyCls>(__s("reverseDuration"), reverseDuration?->inMilliseconds(), __s("ms"), nullptr));
}

_AnimatedSizeCls::_AnimatedSizeCls(AlignmentGeometry alignment, Widget child, Clip clipBehavior, Curve curve, Duration duration, Duration reverseDuration, TickerProvider vsync) {
    {
        assert(clipBehavior != nullptr);
    }
}
