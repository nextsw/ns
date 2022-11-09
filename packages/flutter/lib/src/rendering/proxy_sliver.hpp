#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_PROXY_SLIVER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_PROXY_SLIVER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "layer.hpp"
#include "object.hpp"
#include "proxy_box.hpp"
#include "sliver.hpp"


class RenderProxySliverCls : public RenderSliverCls {
public:

     RenderProxySliverCls(RenderSliver child);

    virtual void setupParentData(RenderObject child);

    virtual void performLayout();

    virtual void paint(PaintingContext context, Offset offset);

    virtual bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    virtual double childMainAxisPosition(RenderSliver child);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

private:

};
using RenderProxySliver = std::shared_ptr<RenderProxySliverCls>;

class RenderSliverOpacityCls : public RenderProxySliverCls {
public:

     RenderSliverOpacityCls(bool alwaysIncludeSemantics, double opacity, RenderSliver sliver);

    virtual bool alwaysNeedsCompositing();

    virtual double opacity();

    virtual void  opacity(double value);

    virtual bool alwaysIncludeSemantics();

    virtual void  alwaysIncludeSemantics(bool value);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;

    double _opacity;

    bool _alwaysIncludeSemantics;


};
using RenderSliverOpacity = std::shared_ptr<RenderSliverOpacityCls>;

class RenderSliverIgnorePointerCls : public RenderProxySliverCls {
public:

     RenderSliverIgnorePointerCls(bool ignoring, bool ignoringSemantics, RenderSliver sliver);

    virtual bool ignoring();

    virtual void  ignoring(bool value);

    virtual bool ignoringSemantics();

    virtual void  ignoringSemantics(bool value);

    virtual bool hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    bool _ignoring;

    bool _ignoringSemantics;


    virtual bool _effectiveIgnoringSemantics();

};
using RenderSliverIgnorePointer = std::shared_ptr<RenderSliverIgnorePointerCls>;

class RenderSliverOffstageCls : public RenderProxySliverCls {
public:

     RenderSliverOffstageCls(bool offstage, RenderSliver sliver);

    virtual bool offstage();

    virtual void  offstage(bool value);

    virtual void performLayout();

    virtual bool hitTest(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    virtual bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    bool _offstage;


};
using RenderSliverOffstage = std::shared_ptr<RenderSliverOffstageCls>;

class RenderSliverAnimatedOpacityCls : public RenderProxySliverCls {
public:

     RenderSliverAnimatedOpacityCls(bool alwaysIncludeSemantics, Animation<double> opacity, RenderSliver sliver);

private:

};
using RenderSliverAnimatedOpacity = std::shared_ptr<RenderSliverAnimatedOpacityCls>;


#endif