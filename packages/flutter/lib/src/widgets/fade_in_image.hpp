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
    ImageProvider<any> placeholder;

    ImageErrorWidgetBuilder placeholderErrorBuilder;

    ImageProvider<any> image;

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


     FadeInImageCls(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, ImageProvider<any> image, ImageErrorWidgetBuilder imageErrorBuilder, String imageSemanticLabel, Key key, bool matchTextDirection, ImageProvider<any> placeholder, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, ImageRepeat repeat, double width);

    virtual void  memoryNetwork(Unknown alignment, Unknown excludeFromSemantics, Unknown fadeInCurve, Unknown fadeInDuration, Unknown fadeOutCurve, Unknown fadeOutDuration, Unknown fit, Unknown height, String image, int imageCacheHeight, int imageCacheWidth, Unknown imageErrorBuilder, double imageScale, Unknown imageSemanticLabel, Unknown key, Unknown matchTextDirection, Uint8List placeholder, int placeholderCacheHeight, int placeholderCacheWidth, Unknown placeholderErrorBuilder, Unknown placeholderFit, double placeholderScale, Unknown repeat, Unknown width);

    virtual void  assetNetwork(Unknown alignment, AssetBundle bundle, Unknown excludeFromSemantics, Unknown fadeInCurve, Unknown fadeInDuration, Unknown fadeOutCurve, Unknown fadeOutDuration, Unknown fit, Unknown height, String image, int imageCacheHeight, int imageCacheWidth, Unknown imageErrorBuilder, double imageScale, Unknown imageSemanticLabel, Unknown key, Unknown matchTextDirection, String placeholder, int placeholderCacheHeight, int placeholderCacheWidth, Unknown placeholderErrorBuilder, Unknown placeholderFit, double placeholderScale, Unknown repeat, Unknown width);

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


    virtual Image _image(ImageErrorWidgetBuilder errorBuilder, BoxFit fit, ImageFrameBuilder frameBuilder, ImageProvider<any> image, Animation<double> opacity);

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

    virtual void forEachTween(TweenVisitor<Object> visitor);

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