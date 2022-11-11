#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_VIEW
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_VIEW
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <dart/io/io.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "binding.hpp"
#include "box.hpp"
#include "debug.hpp"
#include "layer.hpp"
#include "object.hpp"


class ViewConfigurationCls : public ObjectCls {
public:
    Size size;

    double devicePixelRatio;


     ViewConfigurationCls(double devicePixelRatio, Size size);
    virtual Matrix4 toMatrix();

    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using ViewConfiguration = std::shared_ptr<ViewConfigurationCls>;

class RenderViewCls : public RenderObjectCls {
public:
    bool automaticSystemUiAdjustment;


     RenderViewCls(RenderBox child, ViewConfiguration configuration, FlutterView window);

    virtual Size size();

    virtual ViewConfiguration configuration();

    virtual void  configuration(ViewConfiguration value);

    virtual void prepareInitialFrame();

    virtual void debugAssertDoesMeetConstraints();

    virtual void performResize();

    virtual void performLayout();

    virtual bool hitTest(HitTestResult result, Offset position);

    virtual HitTestResult hitTestMouseTrackers(Offset position);

    virtual bool isRepaintBoundary();

    virtual void paint(PaintingContext context, Offset offset);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual void compositeFrame();

    virtual Rect paintBounds();

    virtual Rect semanticBounds();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Size _size;

    ViewConfiguration _configuration;

    FlutterView _window;

    Matrix4 _rootTransform;


    virtual TransformLayer _updateMatricesAndCreateNewRootLayer();

    virtual void _updateSystemChrome();

};
using RenderView = std::shared_ptr<RenderViewCls>;


#endif