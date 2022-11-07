#ifndef PROXY_SLIVER_H
#define PROXY_SLIVER_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "layer.hpp"
#include "object.hpp"
#include "proxy_box.hpp"
#include "sliver.hpp"



class RenderProxySliver : RenderSliver {
public:

     RenderProxySliver(RenderSliver child);

    void setupParentData(RenderObject child);

    void performLayout();

    void paint(PaintingContext context, Offset offset);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    double childMainAxisPosition(RenderSliver child);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

private:

};

class RenderSliverOpacity : RenderProxySliver {
public:

     RenderSliverOpacity(bool alwaysIncludeSemantics, double opacity, RenderSliver sliver);

    bool alwaysNeedsCompositing();

    double opacity();

    void  opacity(double value);

    bool alwaysIncludeSemantics();

    void  alwaysIncludeSemantics(bool value);

    void paint(PaintingContext context, Offset offset);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;

    double _opacity;

    bool _alwaysIncludeSemantics;


};

class RenderSliverIgnorePointer : RenderProxySliver {
public:

     RenderSliverIgnorePointer(bool ignoring, bool ignoringSemantics, RenderSliver sliver);

    bool ignoring();

    void  ignoring(bool value);

    bool ignoringSemantics();

    void  ignoringSemantics(bool value);

    bool hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _ignoring;

    bool _ignoringSemantics;


    bool _effectiveIgnoringSemantics();

};

class RenderSliverOffstage : RenderProxySliver {
public:

     RenderSliverOffstage(bool offstage, RenderSliver sliver);

    bool offstage();

    void  offstage(bool value);

    void performLayout();

    bool hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    void paint(PaintingContext context, Offset offset);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    bool _offstage;


};

class RenderSliverAnimatedOpacity : RenderProxySliver {
public:

     RenderSliverAnimatedOpacity(bool alwaysIncludeSemantics, Animation<double> opacity, RenderSliver sliver);

private:

};

#endif