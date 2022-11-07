#ifndef SLIVER_MULTI_BOX_ADAPTOR_H
#define SLIVER_MULTI_BOX_ADAPTOR_H
#include <memory>

#include <flutter/foundation.hpp>
#include <vector_math/vector_math_64.hpp>
#include "box.hpp"
#include "object.hpp"
#include "sliver.hpp"



class RenderSliverBoxChildManager {
public:

    void createChild(RenderBox after, int index);

    void removeChild(RenderBox child);

    double estimateMaxScrollOffset(SliverConstraints constraints, int firstIndex, int lastIndex, double leadingScrollOffset, double trailingScrollOffset);

    int childCount();

    void didAdoptChild(RenderBox child);

    void setDidUnderflow(bool value);

    void didStartLayout();

    void didFinishLayout();

    bool debugAssertChildListLocked();

private:

};

class KeepAliveParentDataMixin {
public:
    bool keepAlive;


    bool keptAlive();

private:

};

class RenderSliverWithKeepAliveMixin {
public:

    void setupParentData(RenderObject child);

private:

};

class SliverMultiBoxAdaptorParentData : SliverLogicalParentData {
public:
    int index;


    bool keptAlive();

    String toString();

private:
    bool _keptAlive;


};

class RenderSliverMultiBoxAdaptor : RenderSliver {
public:

     RenderSliverMultiBoxAdaptor(RenderSliverBoxChildManager childManager);

    void setupParentData(RenderObject child);

    RenderSliverBoxChildManager childManager();

    bool debugChildIntegrityEnabled();

    void  debugChildIntegrityEnabled(bool enabled);

    void adoptChild(RenderObject child);

    void insert(RenderBox after, RenderBox child);

    void move(RenderBox after, RenderBox child);

    void remove(RenderBox child);

    void removeAll();

    void attach(PipelineOwner owner);

    void detach();

    void redepthChildren();

    void visitChildren(RenderObjectVisitor visitor);

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    bool addInitialChild(int index, double layoutOffset);

    RenderBox insertAndLayoutLeadingChild(BoxConstraints childConstraints, bool parentUsesSize);

    RenderBox insertAndLayoutChild(RenderBox after, BoxConstraints childConstraints, bool parentUsesSize);

    void collectGarbage(int leadingGarbage, int trailingGarbage);

    int indexOf(RenderBox child);

    double paintExtentOf(RenderBox child);

    bool hitTestChildren(double crossAxisPosition, double mainAxisPosition, SliverHitTestResult result);

    double childMainAxisPosition(RenderBox child);

    double childScrollOffset(RenderObject child);

    bool paintsChild(RenderBox child);

    void applyPaintTransform(RenderBox child, Matrix4 transform);

    void paint(PaintingContext context, Offset offset);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool debugAssertChildListIsNonEmptyAndContiguous();

    List<DiagnosticsNode> debugDescribeChildren();

private:
    RenderSliverBoxChildManager _childManager;

    Map<int, RenderBox> _keepAliveBucket;

    List<RenderBox> _debugDanglingKeepAlives;

    bool _debugChildIntegrityEnabled;


    bool _debugAssertChildListLocked();

    bool _debugVerifyChildOrder();

    void _createOrObtainChild(RenderBox after, int index);

    void _destroyOrCacheChild(RenderBox child);

};

#endif