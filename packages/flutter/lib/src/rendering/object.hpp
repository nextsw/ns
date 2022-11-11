#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_OBJECT
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_OBJECT
#include <base.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <dart/developer/developer.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include "debug.hpp"
#include "layer.hpp"


class ParentDataCls : public ObjectCls {
public:

    virtual void detach();

    virtual String toString();

private:

};
using ParentData = std::shared_ptr<ParentDataCls>;

class PaintingContextCls : public ClipContextCls {
public:
    Rect estimatedBounds;


     PaintingContextCls(ContainerLayer _containerLayer, Rect estimatedBounds);

    static void repaintCompositedChild(RenderObject child, bool debugAlsoPaintedParent);

    static void updateLayerProperties(RenderObject child);

    static void debugInstrumentRepaintCompositedChild(RenderObject child, PaintingContext customContext, bool debugAlsoPaintedParent);

    virtual void paintChild(RenderObject child, Offset offset);

    virtual void appendLayer(Layer layer);

    virtual Canvas canvas();

    virtual VoidCallback addCompositionCallback(CompositionCallback callback);

    virtual void stopRecordingIfNeeded();

    virtual void setIsComplexHint();

    virtual void setWillChangeHint();

    virtual void addLayer(Layer layer);

    virtual void pushLayer(ContainerLayer childLayer, PaintingContextCallback painter, Offset offset, Rect childPaintBounds);

    virtual PaintingContext createChildContext(ContainerLayer childLayer, Rect bounds);

    virtual ClipRectLayer pushClipRect(bool needsCompositing, Offset offset, Rect clipRect, PaintingContextCallback painter, Clip clipBehavior, ClipRectLayer oldLayer);

    virtual ClipRRectLayer pushClipRRect(bool needsCompositing, Offset offset, Rect bounds, RRect clipRRect, PaintingContextCallback painter, Clip clipBehavior, ClipRRectLayer oldLayer);

    virtual ClipPathLayer pushClipPath(bool needsCompositing, Offset offset, Rect bounds, Path clipPath, PaintingContextCallback painter, Clip clipBehavior, ClipPathLayer oldLayer);

    virtual ColorFilterLayer pushColorFilter(Offset offset, ColorFilter colorFilter, PaintingContextCallback painter, ColorFilterLayer oldLayer);

    virtual TransformLayer pushTransform(bool needsCompositing, Offset offset, Matrix4 transform, PaintingContextCallback painter, TransformLayer oldLayer);

    virtual OpacityLayer pushOpacity(Offset offset, int alpha, PaintingContextCallback painter, OpacityLayer oldLayer);

    virtual String toString();

private:
    ContainerLayer _containerLayer;

    PictureLayer _currentLayer;

    PictureRecorder _recorder;

    Canvas _canvas;


    static void _repaintCompositedChild(RenderObject child, PaintingContext childContext, bool debugAlsoPaintedParent);

    virtual void _compositeChild(RenderObject child, Offset offset);

    virtual bool _isRecording();

    virtual void _startRecording();

};
using PaintingContext = std::shared_ptr<PaintingContextCls>;

class ConstraintsCls : public ObjectCls {
public:

     ConstraintsCls();
    virtual bool isTight();
    virtual bool isNormalized();
    virtual bool debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint);

private:

};
using Constraints = std::shared_ptr<ConstraintsCls>;

class SemanticsHandleCls : public ObjectCls {
public:
    VoidCallback listener;


    virtual void dispose();

private:
    PipelineOwner _owner;


    virtual void  _(PipelineOwner owner, VoidCallback listener);

};
using SemanticsHandle = std::shared_ptr<SemanticsHandleCls>;

class PipelineOwnerCls : public ObjectCls {
public:
    VoidCallback onNeedVisualUpdate;

    VoidCallback onSemanticsOwnerCreated;

    VoidCallback onSemanticsOwnerDisposed;


     PipelineOwnerCls(VoidCallback onNeedVisualUpdate, VoidCallback onSemanticsOwnerCreated, VoidCallback onSemanticsOwnerDisposed);
    virtual void requestVisualUpdate();

    virtual AbstractNode rootNode();

    virtual void  rootNode(AbstractNode value);

    virtual bool debugDoingLayout();

    virtual void flushLayout();

    virtual void flushCompositingBits();

    virtual bool debugDoingPaint();

    virtual void flushPaint();

    virtual SemanticsOwner semanticsOwner();

    virtual int debugOutstandingSemanticsHandles();

    virtual SemanticsHandle ensureSemantics(VoidCallback listener);

    virtual void flushSemantics();

private:
    AbstractNode _rootNode;

    bool _shouldMergeDirtyNodes;

    List<RenderObject> _nodesNeedingLayout;

    bool _debugDoingLayout;

    bool _debugAllowMutationsToDirtySubtrees;

    List<RenderObject> _nodesNeedingCompositingBitsUpdate;

    List<RenderObject> _nodesNeedingPaint;

    bool _debugDoingPaint;

    SemanticsOwner _semanticsOwner;

    int _outstandingSemanticsHandles;

    bool _debugDoingSemantics;

    Set<RenderObject> _nodesNeedingSemantics;


    virtual void _enableMutationsToDirtySubtrees(VoidCallback callback);

    virtual void _didDisposeSemanticsHandle();

};
using PipelineOwner = std::shared_ptr<PipelineOwnerCls>;

class RenderObjectCls : public AbstractNodeCls {
public:
    ParentData parentData;

    Object debugCreator;

    static bool debugCheckingIntrinsics;


     RenderObjectCls();

    virtual void reassemble();

    virtual bool debugDisposed();

    virtual void dispose();

    virtual void setupParentData(RenderObject child);

    virtual void adoptChild(RenderObject child);

    virtual void dropChild(RenderObject child);

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual bool debugDoingThisResize();

    virtual bool debugDoingThisLayout();

    static RenderObject debugActiveLayout();

    virtual bool debugCanParentUseSize();

    virtual PipelineOwner owner();

    virtual void attach(PipelineOwner owner);

    virtual bool debugNeedsLayout();

    virtual bool debugDoingThisLayoutWithCallback();

    virtual Constraints constraints();

    virtual void debugAssertDoesMeetConstraints();
    virtual void markNeedsLayout();

    virtual void markParentNeedsLayout();

    virtual void markNeedsLayoutForSizedByParentChange();

    virtual void scheduleInitialLayout();

    virtual void layout(Constraints constraints, bool parentUsesSize);

    virtual void debugResetSize();

    virtual bool sizedByParent();

    virtual void performResize();
    virtual void performLayout();
    template<typename T>
 virtual void invokeLayoutCallback(LayoutCallback<T> callback);

    virtual bool debugDoingThisPaint();

    static RenderObject debugActivePaint();

    virtual bool isRepaintBoundary();

    virtual void debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent);

    virtual bool alwaysNeedsCompositing();

    virtual OffsetLayer updateCompositedLayer(OffsetLayer oldLayer);

    virtual ContainerLayer layer();

    virtual void  layer(ContainerLayer newLayer);

    virtual ContainerLayer debugLayer();

    virtual void markNeedsCompositingBitsUpdate();

    virtual bool needsCompositing();

    virtual bool debugNeedsPaint();

    virtual bool debugNeedsCompositedLayerUpdate();

    virtual void markNeedsPaint();

    virtual void markNeedsCompositedLayerUpdate();

    virtual void scheduleInitialPaint(ContainerLayer rootLayer);

    virtual void replaceRootLayer(OffsetLayer rootLayer);

    virtual Rect paintBounds();
    virtual void debugPaint(PaintingContext context, Offset offset);

    virtual void paint(PaintingContext context, Offset offset);

    virtual void applyPaintTransform(RenderObject child, Matrix4 transform);

    virtual bool paintsChild(RenderObject child);

    virtual Matrix4 getTransformTo(RenderObject ancestor);

    virtual Rect describeApproximatePaintClip(RenderObject child);

    virtual Rect describeSemanticsClip(RenderObject child);

    virtual void scheduleInitialSemantics();

    virtual void describeSemanticsConfiguration(SemanticsConfiguration config);

    virtual void sendSemanticsEvent(SemanticsEvent semanticsEvent);

    virtual Rect semanticBounds();
    virtual SemanticsNode debugSemantics();

    virtual void clearSemantics();

    virtual void markNeedsSemanticsUpdate();

    virtual void visitChildrenForSemantics(RenderObjectVisitor visitor);

    virtual void assembleSemanticsNode(SemanticsNode node, SemanticsConfiguration config, Iterable<SemanticsNode> children);

    virtual void handleEvent(PointerEvent event, HitTestEntry entry);

    virtual String toStringShort();

    virtual String toString(DiagnosticLevel minLevel);

    virtual String toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    virtual String toStringShallow(String joiner, DiagnosticLevel minLevel);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual List<DiagnosticsNode> debugDescribeChildren();

    virtual void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    virtual DiagnosticsNode describeForError(String name, DiagnosticsTreeStyle style);

private:
    bool _debugDisposed;

    bool _debugDoingThisResize;

    bool _debugDoingThisLayout;

    static RenderObject _debugActiveLayout;

    bool _debugCanParentUseSize;

    bool _debugMutationsLocked;

    bool _needsLayout;

    RenderObject _relayoutBoundary;

    bool _doingThisLayoutWithCallback;

    Constraints _constraints;

    bool _debugDoingThisPaint;

    static RenderObject _debugActivePaint;

    bool _wasRepaintBoundary;

    LayerHandle<ContainerLayer> _layerHandle;

    bool _needsCompositingBitsUpdate;

    bool _needsCompositing;

    bool _needsPaint;

    bool _needsCompositedLayerUpdate;

    SemanticsConfiguration _cachedSemanticsConfiguration;

    bool _needsSemanticsUpdate;

    SemanticsNode _semantics;


    virtual void _debugReportException(String method, Object exception, StackTrace stack);

    virtual bool _debugCanPerformMutations();

    virtual bool _debugSubtreeRelayoutRootAlreadyMarkedNeedsLayout();

    virtual void _cleanRelayoutBoundary();

    virtual void _propagateRelayoutBoundary();

    static void _cleanChildRelayoutBoundary(RenderObject child);

    static void _propagateRelayoutBoundaryToChild(RenderObject child);

    virtual void _layoutWithoutResize();

    virtual void _updateCompositingBits();

    virtual void _skippedPaintingOnLayer();

    virtual void _paintWithContext(PaintingContext context, Offset offset);

    virtual SemanticsConfiguration _semanticsConfiguration();

    virtual void _updateSemantics();

    virtual _SemanticsFragment _getSemanticsForParent(bool mergeIntoParent);

};
using RenderObject = std::shared_ptr<RenderObjectCls>;

template<typename ChildType>
class RenderObjectWithChildMixinCls : public ObjectCls {
public:

    virtual bool debugValidateChild(RenderObject child);

    virtual ChildType child();

    virtual void  child(ChildType value);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void redepthChildren();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    ChildType _child;


};
template<typename ChildType>
using RenderObjectWithChildMixin = std::shared_ptr<RenderObjectWithChildMixinCls<ChildType>>;

template<typename ChildType>
class ContainerParentDataMixinCls : public ObjectCls {
public:
    ChildType previousSibling;

    ChildType nextSibling;


    virtual void detach();

private:

};
template<typename ChildType>
using ContainerParentDataMixin = std::shared_ptr<ContainerParentDataMixinCls<ChildType>>;

template<typename ChildType, typename ParentDataType>
class ContainerRenderObjectMixinCls : public ObjectCls {
public:

    virtual int childCount();

    virtual bool debugValidateChild(RenderObject child);

    virtual void insert(ChildType child, ChildType after);

    virtual void add(ChildType child);

    virtual void addAll(List<ChildType> children);

    virtual void remove(ChildType child);

    virtual void removeAll();

    virtual void move(ChildType child, ChildType after);

    virtual void attach(PipelineOwner owner);

    virtual void detach();

    virtual void redepthChildren();

    virtual void visitChildren(RenderObjectVisitor visitor);

    virtual ChildType firstChild();

    virtual ChildType lastChild();

    virtual ChildType childBefore(ChildType child);

    virtual ChildType childAfter(ChildType child);

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    int _childCount;

    ChildType _firstChild;

    ChildType _lastChild;


    virtual bool _debugUltimatePreviousSiblingOf(ChildType child, ChildType equals);

    virtual bool _debugUltimateNextSiblingOf(ChildType child, ChildType equals);

    virtual void _insertIntoChildList(ChildType child, ChildType after);

    virtual void _removeFromChildList(ChildType child);

};
template<typename ChildType, typename ParentDataType>
using ContainerRenderObjectMixin = std::shared_ptr<ContainerRenderObjectMixinCls<ChildType, ParentDataType>>;

class RelayoutWhenSystemFontsChangeMixinCls : public ObjectCls {
public:

    virtual void systemFontsDidChange();

    virtual void attach(PipelineOwner owner);

    virtual void detach();

private:

};
using RelayoutWhenSystemFontsChangeMixin = std::shared_ptr<RelayoutWhenSystemFontsChangeMixinCls>;

class _SemanticsFragmentCls : public ObjectCls {
public:
    bool dropsSemanticsOfPreviousSiblings;


    virtual void addAll(Iterable<_InterestingSemanticsFragment> fragments);
    virtual List<_InterestingSemanticsFragment> interestingFragments();
private:

     _SemanticsFragmentCls(bool dropsSemanticsOfPreviousSiblings);

};
using _SemanticsFragment = std::shared_ptr<_SemanticsFragmentCls>;

class _ContainerSemanticsFragmentCls : public _SemanticsFragmentCls {
public:
    List<_InterestingSemanticsFragment> interestingFragments;


    virtual void addAll(Iterable<_InterestingSemanticsFragment> fragments);

private:

     _ContainerSemanticsFragmentCls(bool dropsSemanticsOfPreviousSiblings);
};
using _ContainerSemanticsFragment = std::shared_ptr<_ContainerSemanticsFragmentCls>;

class _InterestingSemanticsFragmentCls : public _SemanticsFragmentCls {
public:

    virtual RenderObject owner();

    virtual void compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result);
    virtual SemanticsConfiguration config();
    virtual void markAsExplicit();
    virtual void addAll(Iterable<_InterestingSemanticsFragment> fragments) override;
    virtual bool hasConfigForParent();

    virtual List<_InterestingSemanticsFragment> interestingFragments();

    virtual void addTags(Iterable<SemanticsTag> tags);

    virtual void addAncestor(RenderObject ancestor);

private:
    List<RenderObject> _ancestorChain;

    Set<SemanticsTag> _tagsForChildren;


     _InterestingSemanticsFragmentCls(bool dropsSemanticsOfPreviousSiblings, RenderObject owner);

};
using _InterestingSemanticsFragment = std::shared_ptr<_InterestingSemanticsFragmentCls>;

class _RootSemanticsFragmentCls : public _InterestingSemanticsFragmentCls {
public:

    virtual void compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result);

    virtual SemanticsConfiguration config();

    virtual void markAsExplicit();

    virtual void addAll(Iterable<_InterestingSemanticsFragment> fragments);

private:
    List<_InterestingSemanticsFragment> _children;


     _RootSemanticsFragmentCls(bool dropsSemanticsOfPreviousSiblings, Unknown owner);
};
using _RootSemanticsFragment = std::shared_ptr<_RootSemanticsFragmentCls>;

class _SwitchableSemanticsFragmentCls : public _InterestingSemanticsFragmentCls {
public:

    virtual void compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result);

    virtual SemanticsConfiguration config();

    virtual void addAll(Iterable<_InterestingSemanticsFragment> fragments);

    virtual void markAsExplicit();

private:
    bool _mergeIntoParent;

    SemanticsConfiguration _config;

    bool _isConfigWritable;

    List<_InterestingSemanticsFragment> _children;

    bool _isExplicit;


     _SwitchableSemanticsFragmentCls(SemanticsConfiguration config, bool dropsSemanticsOfPreviousSiblings, bool mergeIntoParent, Unknown owner);

    virtual void _ensureConfigIsWritable();

    virtual bool _needsGeometryUpdate();

};
using _SwitchableSemanticsFragment = std::shared_ptr<_SwitchableSemanticsFragmentCls>;

class _SemanticsGeometryCls : public ObjectCls {
public:

    virtual Matrix4 transform();

    virtual Rect semanticsClipRect();

    virtual Rect paintClipRect();

    virtual Rect rect();

    virtual bool dropFromTree();

    virtual bool markAsHidden();

private:
    Rect _paintClipRect;

    Rect _semanticsClipRect;

    Matrix4 _transform;

    Rect _rect;

    static Matrix4 _temporaryTransformHolder;

    bool _markAsHidden;


     _SemanticsGeometryCls(List<RenderObject> ancestors, Rect parentPaintClipRect, Rect parentSemanticsClipRect);

    virtual void _computeValues(Rect parentSemanticsClipRect, Rect parentPaintClipRect, List<RenderObject> ancestors);

    static Rect _transformRect(Rect rect, Matrix4 transform);

    static void _applyIntermediatePaintTransforms(RenderObject ancestor, RenderObject child, Matrix4 transform, Matrix4 clipRectTransform);

    static Rect _intersectRects(Rect a, Rect b);

};
using _SemanticsGeometry = std::shared_ptr<_SemanticsGeometryCls>;

class DiagnosticsDebugCreatorCls : public DiagnosticsPropertyCls<Object> {
public:

     DiagnosticsDebugCreatorCls(Object value);

private:

};
using DiagnosticsDebugCreator = std::shared_ptr<DiagnosticsDebugCreatorCls>;


#endif