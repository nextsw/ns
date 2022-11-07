#ifndef VIEW_H
#define VIEW_H
#include <memory>

#include <developer/developer.hpp>
#include <io/io.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "binding.hpp"
#include "box.hpp"
#include "debug.hpp"
#include "layer.hpp"
#include "object.hpp"



class ViewConfiguration {
public:
    Size size;

    double devicePixelRatio;


     ViewConfiguration(double devicePixelRatio, Size size);

    Matrix4 toMatrix();

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class RenderView : RenderObject {
public:
    bool automaticSystemUiAdjustment;


     RenderView(RenderBox child, ViewConfiguration configuration, FlutterView window);

    Size size();

    ViewConfiguration configuration();

    void  configuration(ViewConfiguration value);

    void prepareInitialFrame();

    void debugAssertDoesMeetConstraints();

    void performResize();

    void performLayout();

    bool hitTest(Offset position, HitTestResult result);

    HitTestResult hitTestMouseTrackers(Offset position);

    bool isRepaintBoundary();

    void paint(PaintingContext context, Offset offset);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    void compositeFrame();

    Rect paintBounds();

    Rect semanticBounds();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Size _size;

    ViewConfiguration _configuration;

    FlutterView _window;

    Matrix4 _rootTransform;


    TransformLayer _updateMatricesAndCreateNewRootLayer();

    void _updateSystemChrome();

};

#endif