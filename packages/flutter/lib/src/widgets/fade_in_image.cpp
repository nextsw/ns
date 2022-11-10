#include "fade_in_image.hpp"
FadeInImageCls::FadeInImageCls(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, ImageProvider image, ImageErrorWidgetBuilder imageErrorBuilder, String imageSemanticLabel, Unknown key, bool matchTextDirection, ImageProvider placeholder, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, ImageRepeat repeat, double width) {
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

void FadeInImageCls::memoryNetwork(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown key, bool matchTextDirection, Uint8List placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width)

void FadeInImageCls::assetNetwork(AlignmentGeometry alignment, AssetBundle bundle, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown key, bool matchTextDirection, String placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width)

State<FadeInImage> FadeInImageCls::createState() {
    return make<_FadeInImageStateCls>();
}

Widget _FadeInImageStateCls::build(BuildContext context) {
    Widget result = _image(widget->image, widget->imageErrorBuilder, _imageAnimation, widget->fit, [=] (BuildContext context,Widget child,int frame,bool wasSynchronouslyLoaded) {
    if (wasSynchronouslyLoaded || frame != nullptr) {
        targetLoaded = true;
    }
    return make<_AnimatedFadeOutFadeInCls>(child, _imageAnimation, _image(widget->placeholder, widget->placeholderErrorBuilder, _placeholderAnimation, widget->placeholderFit or widget->fit), _placeholderAnimation, targetLoaded, wasSynchronouslyLoaded, widget->fadeInDuration, widget->fadeOutDuration, widget->fadeInCurve, widget->fadeOutCurve);
});
    if (!widget->excludeFromSemantics) {
        result = make<SemanticsCls>(widget->imageSemanticLabel != nullptr, true, widget->imageSemanticLabel or __s(""), result);
    }
    return result;
}

Image _FadeInImageStateCls::_image(ImageErrorWidgetBuilder errorBuilder, BoxFit fit, ImageFrameBuilder frameBuilder, ImageProvider image, Animation<double> opacity) {
    assert(image != nullptr);
    return make<ImageCls>(image, errorBuilder, frameBuilder, opacity, widget->width, widget->height, fit, widget->alignment, widget->repeat, widget->matchTextDirection, true, true);
}

_AnimatedFadeOutFadeInState _AnimatedFadeOutFadeInCls::createState() {
    return make<_AnimatedFadeOutFadeInStateCls>();
}

_AnimatedFadeOutFadeInCls::_AnimatedFadeOutFadeInCls(Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, bool isTargetLoaded, Widget placeholder, ProxyAnimation placeholderProxyAnimation, Widget target, ProxyAnimation targetProxyAnimation, bool wasSynchronouslyLoaded) : ImplicitlyAnimatedWidget(fadeInDuration + fadeOutDuration) {
    {
        assert(target != nullptr);
        assert(placeholder != nullptr);
        assert(isTargetLoaded != nullptr);
        assert(fadeOutDuration != nullptr);
        assert(fadeOutCurve != nullptr);
        assert(fadeInDuration != nullptr);
        assert(fadeInCurve != nullptr);
        assert(!wasSynchronouslyLoaded || isTargetLoaded);
    }
}

void _AnimatedFadeOutFadeInStateCls::forEachTween(TweenVisitor<dynamic> visitor) {
    _targetOpacity = as<Tween<double>>(visitor(_targetOpacity, widget->isTargetLoaded? 1.0 : 0.0, [=] (dynamic value)     {
        <double>make<TweenCls>(as<double>(value));
    }));
    _placeholderOpacity = as<Tween<double>>(visitor(_placeholderOpacity, widget->isTargetLoaded? 0.0 : 1.0, [=] (dynamic value)     {
        <double>make<TweenCls>(as<double>(value));
    }));
}

void _AnimatedFadeOutFadeInStateCls::didUpdateTweens() {
    if (widget->wasSynchronouslyLoaded) {
        return;
    }
        });_placeholderOpacityAnimation =             }        auto _c1 = animation->drive(<double>make<TweenSequenceCls>(makeList(ArrayItem, ArrayItem)));        _c1.addStatusListener([=] (AnimationStatus status) {                if (_placeholderOpacityAnimation!->isCompleted()) {                    setState([=] () {                    });_c1;
    _targetOpacityAnimation = animation->drive(<double>make<TweenSequenceCls>(makeList(ArrayItem, ArrayItem)));
    widget->targetProxyAnimation->parent = _targetOpacityAnimation;
    widget->placeholderProxyAnimation->parent = _placeholderOpacityAnimation;
}

Widget _AnimatedFadeOutFadeInStateCls::build(BuildContext context) {
    if (widget->wasSynchronouslyLoaded || _placeholderOpacityAnimation!->isCompleted()) {
        return widget->target;
    }
    return make<StackCls>(StackFitCls::passthrough, AlignmentDirectionalCls::center, TextDirectionCls::ltr, makeList(ArrayItem, ArrayItem));
}

void _AnimatedFadeOutFadeInStateCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("targetOpacity"), _targetOpacityAnimation));
    properties->add(<Animation<double>>make<DiagnosticsPropertyCls>(__s("placeholderOpacity"), _placeholderOpacityAnimation));
}
