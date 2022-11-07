#ifndef OBJECT_H
#define OBJECT_H
#include <memory>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/painting.hpp>

#include <developer/developer.hpp>
#include <ui/ui.hpp>
#include <flutter/animation.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/painting.hpp>
#include <flutter/semantics.hpp>
#include "debug.hpp"
#include "layer.hpp"



class ParentData {
public:

    void detach();

    String toString();

private:

};

class PaintingContext : ClipContext {
public:
    Rect estimatedBounds;


     PaintingContext(ContainerLayer _containerLayer, Rect estimatedBounds);

    static void repaintCompositedChild(RenderObject child, bool debugAlsoPaintedParent);

    static void updateLayerProperties(RenderObject child);

    static void debugInstrumentRepaintCompositedChild(RenderObject child, PaintingContext customContext, bool debugAlsoPaintedParent);

    void paintChild(RenderObject child, Offset offset);

    void appendLayer(Layer layer);

    Canvas canvas();

    VoidCallback addCompositionCallback(CompositionCallback callback);

    void stopRecordingIfNeeded();

    void setIsComplexHint();

    void setWillChangeHint();

    void addLayer(Layer layer);

    void pushLayer(ContainerLayer childLayer, Rect childPaintBounds, Offset offset, PaintingContextCallback painter);

    PaintingContext createChildContext(Rect bounds, ContainerLayer childLayer);

    ClipRectLayer pushClipRect(Clip clipBehavior, Rect clipRect, bool needsCompositing, Offset offset, ClipRectLayer oldLayer, PaintingContextCallback painter);

    ClipRRectLayer pushClipRRect(Rect bounds, Clip clipBehavior, RRect clipRRect, bool needsCompositing, Offset offset, ClipRRectLayer oldLayer, PaintingContextCallback painter);

    ClipPathLayer pushClipPath(Rect bounds, Clip clipBehavior, Path clipPath, bool needsCompositing, Offset offset, ClipPathLayer oldLayer, PaintingContextCallback painter);

    ColorFilterLayer pushColorFilter(ColorFilter colorFilter, Offset offset, ColorFilterLayer oldLayer, PaintingContextCallback painter);

    TransformLayer pushTransform(bool needsCompositing, Offset offset, TransformLayer oldLayer, PaintingContextCallback painter, Matrix4 transform);

    OpacityLayer pushOpacity(int alpha, Offset offset, OpacityLayer oldLayer, PaintingContextCallback painter);

    String toString();

private:
    ContainerLayer _containerLayer;

    PictureLayer _currentLayer;

    PictureRecorder _recorder;

    Canvas _canvas;


    static void _repaintCompositedChild(RenderObject child, PaintingContext childContext, bool debugAlsoPaintedParent);

    void _compositeChild(RenderObject child, Offset offset);

    bool _isRecording();

    void _startRecording();

};

class Constraints {
public:

     Constraints();

    bool isTight();

    bool isNormalized();

    bool debugAssertIsValid(InformationCollector informationCollector, bool isAppliedConstraint);

private:

};

class SemanticsHandle {
public:
    VoidCallback listener;


    void dispose();

private:
    PipelineOwner _owner;


    void  _(VoidCallback listener, PipelineOwner owner);

};

class PipelineOwner {
public:
    VoidCallback onNeedVisualUpdate;

    VoidCallback onSemanticsOwnerCreated;

    VoidCallback onSemanticsOwnerDisposed;


     PipelineOwner(VoidCallback onNeedVisualUpdate, VoidCallback onSemanticsOwnerCreated, VoidCallback onSemanticsOwnerDisposed);

    void requestVisualUpdate();

    AbstractNode rootNode();

    void  rootNode(AbstractNode value);

    bool debugDoingLayout();

    void flushLayout();

    void flushCompositingBits();

    bool debugDoingPaint();

    void flushPaint();

    SemanticsOwner semanticsOwner();

    int debugOutstandingSemanticsHandles();

    SemanticsHandle ensureSemantics(VoidCallback listener);

    void flushSemantics();

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


    void _enableMutationsToDirtySubtrees(VoidCallback callback);

    void _didDisposeSemanticsHandle();

};

class RenderObject : AbstractNode {
public:
    ParentData parentData;

    Object debugCreator;

    static bool debugCheckingIntrinsics;


     RenderObject();

    void reassemble();

    bool debugDisposed();

    void dispose();

    void setupParentData(RenderObject child);

    void adoptChild(RenderObject child);

    void dropChild(RenderObject child);

    void visitChildren(RenderObjectVisitor visitor);

    bool debugDoingThisResize();

    bool debugDoingThisLayout();

    static RenderObject debugActiveLayout();

    bool debugCanParentUseSize();

    PipelineOwner owner();

    void attach(PipelineOwner owner);

    bool debugNeedsLayout();

    bool debugDoingThisLayoutWithCallback();

    Constraints constraints();

    void debugAssertDoesMeetConstraints();

    void markNeedsLayout();

    void markParentNeedsLayout();

    void markNeedsLayoutForSizedByParentChange();

    void scheduleInitialLayout();

    void layout(Constraints constraints, bool parentUsesSize);

    void debugResetSize();

    bool sizedByParent();

    void performResize();

    void performLayout();

    void invokeLayoutCallback<T extends Constraints>(LayoutCallback<T> callback);

    bool debugDoingThisPaint();

    static RenderObject debugActivePaint();

    bool isRepaintBoundary();

    void debugRegisterRepaintBoundaryPaint(bool includedChild, bool includedParent);

    bool alwaysNeedsCompositing();

    OffsetLayer updateCompositedLayer(OffsetLayer oldLayer);

    ContainerLayer layer();

    void  layer(ContainerLayer newLayer);

    ContainerLayer debugLayer();

    void markNeedsCompositingBitsUpdate();

    bool needsCompositing();

    bool debugNeedsPaint();

    bool debugNeedsCompositedLayerUpdate();

    void markNeedsPaint();

    void markNeedsCompositedLayerUpdate();

    void scheduleInitialPaint(ContainerLayer rootLayer);

    void replaceRootLayer(OffsetLayer rootLayer);

    Rect paintBounds();

    void debugPaint(PaintingContext context, Offset offset);

    void paint(PaintingContext context, Offset offset);

    void applyPaintTransform(RenderObject child, Matrix4 transform);

    bool paintsChild(RenderObject child);

    Matrix4 getTransformTo(RenderObject ancestor);

    Rect describeApproximatePaintClip(RenderObject child);

    Rect describeSemanticsClip(RenderObject child);

    void scheduleInitialSemantics();

    void describeSemanticsConfiguration(SemanticsConfiguration config);

    void sendSemanticsEvent(SemanticsEvent semanticsEvent);

    Rect semanticBounds();

    SemanticsNode debugSemantics();

    void clearSemantics();

    void markNeedsSemanticsUpdate();

    void visitChildrenForSemantics(RenderObjectVisitor visitor);

    void assembleSemanticsNode(Iterable<SemanticsNode> children, SemanticsConfiguration config, SemanticsNode node);

    void handleEvent(HitTestEntry entry, PointerEvent event);

    String toStringShort();

    String toString(DiagnosticLevel minLevel);

    String toStringDeep(DiagnosticLevel minLevel, String prefixLineOne, String prefixOtherLines);

    String toStringShallow(String joiner, DiagnosticLevel minLevel);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    List<DiagnosticsNode> debugDescribeChildren();

    void showOnScreen(Curve curve, RenderObject descendant, Duration duration, Rect rect);

    DiagnosticsNode describeForError(String name, DiagnosticsTreeStyle style);

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


    void _debugReportException(Object exception, String method, StackTrace stack);

    bool _debugCanPerformMutations();

    bool _debugSubtreeRelayoutRootAlreadyMarkedNeedsLayout();

    void _cleanRelayoutBoundary();

    void _propagateRelayoutBoundary();

    static void _cleanChildRelayoutBoundary(RenderObject child);

    static void _propagateRelayoutBoundaryToChild(RenderObject child);

    void _layoutWithoutResize();

    void _updateCompositingBits();

    void _skippedPaintingOnLayer();

    void _paintWithContext(PaintingContext context, Offset offset);

    SemanticsConfiguration _semanticsConfiguration();

    void _updateSemantics();

    _SemanticsFragment _getSemanticsForParent(bool mergeIntoParent);

};

class RenderObjectWithChildMixin<ChildType extends RenderObject> {
public:

    bool debugValidateChild(RenderObject child);

    ChildType child();

    void  child(ChildType value);

    void attach(PipelineOwner owner);

    void detach();

    void redepthChildren();

    void visitChildren(RenderObjectVisitor visitor);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    ChildType _child;


};

class ContainerParentDataMixin<ChildType extends RenderObject> {
public:
    ChildType previousSibling;

    ChildType nextSibling;


    void detach();

private:

};

class ContainerRenderObjectMixin<ChildType extends RenderObject, ParentDataType extends ContainerParentDataMixin<ChildType>> {
public:

    int childCount();

    bool debugValidateChild(RenderObject child);

    void insert(ChildType after, ChildType child);

    void add(ChildType child);

    void addAll(List<ChildType> children);

    void remove(ChildType child);

    void removeAll();

    void move(ChildType after, ChildType child);

    void attach(PipelineOwner owner);

    void detach();

    void redepthChildren();

    void visitChildren(RenderObjectVisitor visitor);

    ChildType firstChild();

    ChildType lastChild();

    ChildType childBefore(ChildType child);

    ChildType childAfter(ChildType child);

    List<DiagnosticsNode> debugDescribeChildren();

private:
    int _childCount;

    ChildType _firstChild;

    ChildType _lastChild;


    bool _debugUltimatePreviousSiblingOf(ChildType child, ChildType equals);

    bool _debugUltimateNextSiblingOf(ChildType child, ChildType equals);

    void _insertIntoChildList(ChildType after, ChildType child);

    void _removeFromChildList(ChildType child);

};

class RelayoutWhenSystemFontsChangeMixin {
public:

    void systemFontsDidChange();

    void attach(PipelineOwner owner);

    void detach();

private:

};

class _SemanticsFragment {
public:
    bool dropsSemanticsOfPreviousSiblings;


    void addAll(Iterable<_InterestingSemanticsFragment> fragments);

    List<_InterestingSemanticsFragment> interestingFragments();

private:

     _SemanticsFragment(bool dropsSemanticsOfPreviousSiblings);

};

class _ContainerSemanticsFragment : _SemanticsFragment {
public:
    List<_InterestingSemanticsFragment> interestingFragments;


    void addAll(Iterable<_InterestingSemanticsFragment> fragments);

private:

     _ContainerSemanticsFragment(Unknown);

};

class _InterestingSemanticsFragment : _SemanticsFragment {
public:

    RenderObject owner();

    void compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result);

    SemanticsConfiguration config();

    void markAsExplicit();

    void addAll(Iterable<_InterestingSemanticsFragment> fragments);

    bool hasConfigForParent();

    List<_InterestingSemanticsFragment> interestingFragments();

    void addTags(Iterable<SemanticsTag> tags);

    void addAncestor(RenderObject ancestor);

private:
    List<RenderObject> _ancestorChain;

    Set<SemanticsTag> _tagsForChildren;


     _InterestingSemanticsFragment(Unknown, RenderObject owner);

};

class _RootSemanticsFragment : _InterestingSemanticsFragment {
public:

    void compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result);

    SemanticsConfiguration config();

    void markAsExplicit();

    void addAll(Iterable<_InterestingSemanticsFragment> fragments);

private:
    List<_InterestingSemanticsFragment> _children;


     _RootSemanticsFragment(Unknown, Unknown);

};

class _SwitchableSemanticsFragment : _InterestingSemanticsFragment {
public:

    void compileChildren(double elevationAdjustment, Rect parentPaintClipRect, Rect parentSemanticsClipRect, List<SemanticsNode> result);

    SemanticsConfiguration config();

    void addAll(Iterable<_InterestingSemanticsFragment> fragments);

    void markAsExplicit();

private:
    bool _mergeIntoParent;

    SemanticsConfiguration _config;

    bool _isConfigWritable;

    List<_InterestingSemanticsFragment> _children;

    bool _isExplicit;


     _SwitchableSemanticsFragment(SemanticsConfiguration config, Unknown, bool mergeIntoParent, Unknown);

    void _ensureConfigIsWritable();

    bool _needsGeometryUpdate();

};

class _SemanticsGeometry {
public:

    Matrix4 transform();

    Rect semanticsClipRect();

    Rect paintClipRect();

    Rect rect();

    bool dropFromTree();

    bool markAsHidden();

private:
    Rect _paintClipRect;

    Rect _semanticsClipRect;

    Matrix4 _transform;

    Rect _rect;

    static Matrix4 _temporaryTransformHolder;

    bool _markAsHidden;


     _SemanticsGeometry(List<RenderObject> ancestors, Rect parentPaintClipRect, Rect parentSemanticsClipRect);

    void _computeValues(List<RenderObject> ancestors, Rect parentPaintClipRect, Rect parentSemanticsClipRect);

    static Rect _transformRect(Rect rect, Matrix4 transform);

    static void _applyIntermediatePaintTransforms(RenderObject ancestor, RenderObject child, Matrix4 clipRectTransform, Matrix4 transform);

    static Rect _intersectRects(Rect a, Rect b);

};

class DiagnosticsDebugCreator : DiagnosticsProperty<Object> {
public:

     DiagnosticsDebugCreator(Object value);

private:

};

#endif