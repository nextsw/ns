#ifndef FADE_IN_IMAGE_H
#define FADE_IN_IMAGE_H
#include <memory>

#include <flutter/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "image.hpp"
#include "implicit_animations.hpp"



class FadeInImage : StatefulWidget {
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


     FadeInImage(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, ImageProvider image, ImageErrorWidgetBuilder imageErrorBuilder, String imageSemanticLabel, Unknown, bool matchTextDirection, ImageProvider placeholder, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, ImageRepeat repeat, double width);

    void  memoryNetwork(AlignmentGeometry alignment, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown, bool matchTextDirection, Uint8List placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width);

    void  assetNetwork(AlignmentGeometry alignment, AssetBundle bundle, bool excludeFromSemantics, Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, BoxFit fit, double height, String image, int imageCacheHeight, int imageCacheWidth, ImageErrorWidgetBuilder imageErrorBuilder, double imageScale, String imageSemanticLabel, Unknown, bool matchTextDirection, String placeholder, int placeholderCacheHeight, int placeholderCacheWidth, ImageErrorWidgetBuilder placeholderErrorBuilder, BoxFit placeholderFit, double placeholderScale, ImageRepeat repeat, double width);

    State<FadeInImage> createState();

private:

};

class _FadeInImageState : State<FadeInImage> {
public:
    bool targetLoaded;


    Widget build(BuildContext context);

private:
    static const Animation<double> _kOpaqueAnimation;

    ProxyAnimation _imageAnimation;

    ProxyAnimation _placeholderAnimation;


    Image _image(ImageErrorWidgetBuilder errorBuilder, BoxFit fit, ImageFrameBuilder frameBuilder, ImageProvider image, Animation<double> opacity);

};

class _AnimatedFadeOutFadeIn : ImplicitlyAnimatedWidget {
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


    _AnimatedFadeOutFadeInState createState();

private:

     _AnimatedFadeOutFadeIn(Curve fadeInCurve, Duration fadeInDuration, Curve fadeOutCurve, Duration fadeOutDuration, bool isTargetLoaded, Widget placeholder, ProxyAnimation placeholderProxyAnimation, Widget target, ProxyAnimation targetProxyAnimation, bool wasSynchronouslyLoaded);

};

class _AnimatedFadeOutFadeInState : ImplicitlyAnimatedWidgetState<_AnimatedFadeOutFadeIn> {
public:

    void forEachTween(TweenVisitor<dynamic> visitor);

    void didUpdateTweens();

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Tween<double> _targetOpacity;

    Tween<double> _placeholderOpacity;

    Animation<double> _targetOpacityAnimation;

    Animation<double> _placeholderOpacityAnimation;


};

#endif