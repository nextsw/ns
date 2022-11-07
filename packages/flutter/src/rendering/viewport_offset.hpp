#ifndef VIEWPORT_OFFSET_H
#define VIEWPORT_OFFSET_H
#include <memory>

#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>



enum ScrollDirection{
    idle,
    forward,
    reverse,
} // end ScrollDirection
ScrollDirection flipScrollDirection(ScrollDirection direction);


class ViewportOffset : ChangeNotifier {
public:

     ViewportOffset();

    void  fixed(double value);

    void  zero();

    double pixels();

    bool hasPixels();

    bool applyViewportDimension(double viewportDimension);

    bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);

    void correctBy(double correction);

    void jumpTo(double pixels);

    Future<void> animateTo(Curve curve, Duration duration, double to);

    Future<void> moveTo(bool clamp, Curve curve, Duration duration, double to);

    ScrollDirection userScrollDirection();

    bool allowImplicitScrolling();

    String toString();

    void debugFillDescription(List<String> description);

private:

};

class _FixedViewportOffset : ViewportOffset {
public:

    void  zero();

    double pixels();

    bool hasPixels();

    bool applyViewportDimension(double viewportDimension);

    bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);

    void correctBy(double correction);

    void jumpTo(double pixels);

    Future<void> animateTo(Curve curve, Duration duration, double to);

    ScrollDirection userScrollDirection();

    bool allowImplicitScrolling();

private:
    double _pixels;


     _FixedViewportOffset(double _pixels);

};

#endif