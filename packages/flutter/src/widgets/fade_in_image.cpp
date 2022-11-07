#include "fade_in_image.hpp"
FadeInImage::FadeInImage(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, ImageProvider image, ImageErrorWidgetBuilder imageErrorBuilder, String imageSemanticLabel, Unknown, bool matchTextDirection, ImageProvider placeholder, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, ImageRepeat repeat, double width) {
    {
        assert(placeholder != nullptr);
        assert(image != nullptr);
        assert(fadeOutDuration != nullptr);
        assert(fadeOutCurve != nullptr);
        assert(fadeInDuration != nullptr);
        assert(fadeInCurve != nullptr);
        assert(alignment != nullptr);
        assert(repeat != nullptr);
        assert(matchTextDirection != nullptr);
    }
}

void FadeInImage::memoryNetwork(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown, bool matchTextDirection, Uint8List placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width)

void FadeInImage::assetNetwork(AlignmentGeometry alignment, AssetBundle bundle, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown, bool matchTextDirection, String placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width)

State<FadeInImage> FadeInImage::createState() {
    return _FadeInImageState();
}

Widget _FadeInImageState::build(BuildContext context) {
    Widget result = _image(widget.image, widget.imageErrorBuilder, _imageAnimation, widget.fit, );
    if (!widget.excludeFromSemantics) {
        result = Semantics(widget.imageSemanticLabel != nullptr, true, widget.imageSemanticLabel ?? "", result);
    }
    return result;
}

Image _FadeInImageState::_image(ImageErrorWidgetBuilder errorBuilder, BoxFit fit, ImageFrameBuilder frameBuilder, ImageProvider image, Animation<double> opacity) {
    assert(image != nullptr);
    return Image(image, errorBuilder, frameBuilder, opacity, widget.width, widget.height, fit, widget.alignment, widget.repeat, widget.matchTextDirection, true, true);
}

_AnimatedFadeOutFadeInState _AnimatedFadeOutFadeIn::createState() {
    return _AnimatedFadeOutFadeInState();
}

_AnimatedFadeOutFadeIn::_AnimatedFadeOutFadeIn(Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, bool isTargetLoaded, Widget placeholder, ProxyAnimation placeholderProxyAnimation, Widget target, ProxyAnimation targetProxyAnimation, bool wasSynchronouslyLoaded) {
    {
        assert(target != nullptr);
        assert(placeholder != nullptr);
        assert(isTargetLoaded != nullptr);
        assert(fadeOutDuration != nullptr);
        assert(fadeOutCurve != nullptr);
        assert(fadeInDuration != nullptr);
        assert(fadeInCurve != nullptr);
        assert(!wasSynchronouslyLoaded || isTargetLoaded);
        super(fadeInDuration + fadeOutDuration);
    }
}

void _AnimatedFadeOutFadeInState::forEachTween(TweenVisitor<dynamic> visitor) {
    _targetOpacity = (;
    _placeholderOpacity = (;
}

void _AnimatedFadeOutFadeInState::didUpdateTweens() {
    if (widget.wasSynchronouslyLoaded) {
        return;
    }
    _placeholderOpacityAnimation = ;
    _targetOpacityAnimation = animation.drive(<double>TweenSequence());
    widget.targetProxyAnimation.parent = _targetOpacityAnimation;
    widget.placeholderProxyAnimation.parent = _placeholderOpacityAnimation;
}

Widget _AnimatedFadeOutFadeInState::build(BuildContext context) {
    if (widget.wasSynchronouslyLoaded || _placeholderOpacityAnimation!.isCompleted) {
        return widget.target;
    }
    return Stack(StackFit.passthrough, AlignmentDirectional.center, TextDirection.ltr, );
}

void _AnimatedFadeOutFadeInState::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Animation<double>>DiagnosticsProperty("targetOpacity", _targetOpacityAnimation));
    properties.add(<Animation<double>>DiagnosticsProperty("placeholderOpacity", _placeholderOpacityAnimation));
}
