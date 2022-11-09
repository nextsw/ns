#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FADE_IN_IMAGE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_FADE_IN_IMAGE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "image.hpp"
#include "implicit_animations.hpp"


class FadeInImageCls : public StatefulWidgetCls {
public:
    ImageProvider placeholder;

    ImageErrorWidgetBuilder placeholderErrorBuilder;

    ImageProvider image;

    ImageErrorWidgetBuilder imageErrorBuilder;

    Duration fadeOutDuration;

    Curve fadeOutCurve;

    Duration fadeInDuration;

    Curve fadeInCurve;

    double width;

    double height;

    BoxFit fit;

    BoxFit placeholderFit;

    AlignmentGeometry alignment;

    ImageRepeat repeat;

    bool matchTextDirection;

    bool excludeFromSemantics;

    String imageSemanticLabel;


     FadeInImageCls(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, ImageProvider image, ImageErrorWidgetBuilder imageErrorBuilder, String imageSemanticLabel, Unknown key, bool matchTextDirection, ImageProvider placeholder, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, ImageRepeat repeat, double width);

    virtual void  memoryNetwork(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown key, bool matchTextDirection, Uint8List placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width);

    virtual void  assetNetwork(AlignmentGeometry alignment, AssetBundle bundle, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown key, bool matchTextDirection, String placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width);

    virtual State<FadeInImage> createState();

private:

};
using FadeInImage = std::shared_ptr<FadeInImageCls>;

class _FadeInImageStateCls : public StateCls<FadeInImage> {
public:
    bool targetLoaded;


    virtual Widget build(BuildContext context);

private:
    static Animation<double> _kOpaqueAnimation;

    ProxyAnimation _imageAnimation;

    ProxyAnimation _placeholderAnimation;


    virtual Image _image(ImageErrorWidgetBuilder errorBuilder, BoxFit fit, ImageFrameBuilder frameBuilder, ImageProvider image, Animation<double> opacity);

};
using _FadeInImageState = std::shared_ptr<_FadeInImageStateCls>;

class _AnimatedFadeOutFadeInCls : public ImplicitlyAnimatedWidgetCls {
public:
    Widget target;

    ProxyAnimation targetProxyAnimation;

    Widget placeholder;

    ProxyAnimation placeholderProxyAnimation;

    bool isTargetLoaded;

    Duration fadeInDuration;

    Duration fadeOutDuration;

    Curve fadeInCurve;

    Curve fadeOutCurve;

    bool wasSynchronouslyLoaded;


    virtual _AnimatedFadeOutFadeInState createState();

private:

     _AnimatedFadeOutFadeInCls(Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, bool isTargetLoaded, Widget placeholder, ProxyAnimation placeholderProxyAnimation, Widget target, ProxyAnimation targetProxyAnimation, bool wasSynchronouslyLoaded);

};
using _AnimatedFadeOutFadeIn = std::shared_ptr<_AnimatedFadeOutFadeInCls>;

class _AnimatedFadeOutFadeInStateCls : public ImplicitlyAnimatedWidgetStateCls<_AnimatedFadeOutFadeIn> {
public:

    virtual void forEachTween(TweenVisitor<dynamic> visitor);

    virtual void didUpdateTweens();

    virtual Widget build(BuildContext context);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Tween<double> _targetOpacity;

    Tween<double> _placeholderOpacity;

    Animation<double> _targetOpacityAnimation;

    Animation<double> _placeholderOpacityAnimation;


};
using _AnimatedFadeOutFadeInState = std::shared_ptr<_AnimatedFadeOutFadeInStateCls>;


#endif