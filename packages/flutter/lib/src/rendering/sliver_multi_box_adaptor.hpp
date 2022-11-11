#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_MULTI_BOX_ADAPTOR
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_SLIVER_MULTI_BOX_ADAPTOR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"


class RenderSliverBoxChildManagerCls : public ObjectCls {
public:

    virtual void createChild(int index, RenderBox after);
    virtual void removeChild(RenderBox child);
    virtual double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);
    virtual int childCount();
    virtual void didAdoptChild(RenderBox child);
    virtual void setDidUnderflow(bool value);
    virtual void didStartLayout();

    virtual void didFinishLayout();

    virtual bool debugAssertChildListLocked();

private:

};
using RenderSliverBoxChildManager = std::shared_ptr<RenderSliverBoxChildManagerCls>;

class KeepAliveParentDataMixinCls : public ObjectCls {
public:
    bool keepAlive;


    virtual bool keptAlive();
private:

};
using KeepAliveParentDataMixin = std::shared_ptr<KeepAliveParentDataMixinCls>;

class RenderSliverWithKeepAliveMixinCls : public ObjectCls {
public:

    virtual void setupParentData(RenderObject child);

private:

};
using RenderSliverWithKeepAliveMixin = std::shared_ptr<RenderSliverWithKeepAliveMixinCls>;

class SliverMultiBoxAdaptorParentDataCls : public SliverLogicalParentDataCls {
public:
    int index;


    virtual bool keptAlive();

    virtual String toString();

private:
    bool _keptAlive;


};
using SliverMultiBoxAdaptorParentData = std::shared_ptr<SliverMultiBoxAdaptorParentDataCls>;

class RenderSliverMultiBoxAdaptorCls : public RenderSliverCls {
public:

     RenderSliverMultiBoxAdaptorCls(RenderSliverBoxChildManager childManager);

    virtual void setupParentData(RenderObject child);

    virtual RenderSliverBoxChildManager childManager();

    virtual bool debugChildIntegrityEnabled();

    virtual void  debugChildIntegrityEnabled(bool enabled);

    virtual void adoptChild(RenderObject child);

    virtual void insert(RenderBox child, RenderBox after);

    virtual void move(RenderBox child, RenderBox after);

    virtual void remove(RenderBox child);

    virtual void removeAll();

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void redepthChildren();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual bool addInitialChild(int index, double layoutOffset);

    virtual RenderBox insertAndLayoutLeadingChild(BoxConstraints childConstraints, bool parentUsesSize);

    virtual RenderBox insertAndLayoutChild(BoxConstraints childConstraints, RenderBox after, bool parentUsesSize);

    virtual void collectGarbage(int leadingGarbage, int trailingGarbage);

    virtual int indexOf(RenderBox child);

    virtual double paintExtentOf(RenderBox child);

    virtual bool hitTestChildren(SliverHitTestResult result, double crossAxisPosition, double mainAxisPosition);

    virtual double childMainAxisPosition(RenderBox child);

    virtual double childScrollOffset(RenderObject child);

    virtual bool paintsChild(RenderBox child);

    virtual void applyPaintTransform(RenderBox child, Matrix4 transform);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual bool debugAssertChildListIsNonEmptyAndContiguous();

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    RenderSliverBoxChildManager _childManager;

    Map<int, RenderBox> _keepAliveBucket;

    List<RenderBox> _debugDanglingKeepAlives;

    bool _debugChildIntegrityEnabled;


    virtual bool _debugAssertChildListLocked();

    virtual bool _debugVerifyChildOrder();

    virtual void _createOrObtainChild(int index, RenderBox after);

    virtual void _destroyOrCacheChild(RenderBox child);

};
using RenderSliverMultiBoxAdaptor = std::shared_ptr<RenderSliverMultiBoxAdaptorCls>;


#endif