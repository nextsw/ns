#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_VIEWPORT_OFFSET
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_VIEWPORT_OFFSET
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>


enum ScrollDirection{
    idle,
    forward,
    reverse,
} // end ScrollDirection
ScrollDirection flipScrollDirection(ScrollDirection direction);


class ViewportOffsetCls : public ChangeNotifierCls {
public:

     ViewportOffsetCls();
    virtual void  fixed(double value);
    virtual void  zero();
    virtual double pixels();
    virtual bool hasPixels();
    virtual bool applyViewportDimension(double viewportDimension);
    virtual bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);
    virtual void correctBy(double correction);
    virtual void jumpTo(double pixels);
    virtual Future<void> animateTo(Curve curve, Duration duration, double to);
    virtual Future<void> moveTo(bool clamp, Curve curve, Duration duration, double to);

    virtual ScrollDirection userScrollDirection();
    virtual bool allowImplicitScrolling();
    virtual String toString();

    virtual void debugFillDescription(List<String> description);

private:

};
using ViewportOffset = std::shared_ptr<ViewportOffsetCls>;

class _FixedViewportOffsetCls : public ViewportOffsetCls {
public:

    virtual void  zero();

    virtual double pixels();

    virtual bool hasPixels();

    virtual bool applyViewportDimension(double viewportDimension);

    virtual bool applyContentDimensions(double maxScrollExtent, double minScrollExtent);

    virtual void correctBy(double correction);

    virtual void jumpTo(double pixels);

    virtual Future<void> animateTo(Curve curve, Duration duration, double to);

    virtual ScrollDirection userScrollDirection();

    virtual bool allowImplicitScrolling();

private:
    double _pixels;


     _FixedViewportOffsetCls(double _pixels);
};
using _FixedViewportOffset = std::shared_ptr<_FixedViewportOffsetCls>;


#endif