#ifndef LAYER_H
#define LAYER_H
#include <memory>

#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/gestures.hpp>
#include <flutter/painting.hpp>
#include <flutter/scheduler.hpp>
#include <vector_math/vector_math_64.hpp>
#include "debug.hpp"



class AnnotationEntry<T> {
public:
    T annotation;

    Offset localPosition;


     AnnotationEntry(T annotation, Offset localPosition);

    String toString();

private:

};

class AnnotationResult<T> {
public:

    void add(AnnotationEntry<T> entry);

    Iterable<AnnotationEntry<T>> entries();

    Iterable<T> annotations();

private:
    List<AnnotationEntry<T>> _entries;


};

class Layer : AbstractNode {
public:
    Object debugCreator;


    bool subtreeHasCompositionCallbacks();

    Rect describeClipBounds();

    VoidCallback addCompositionCallback(CompositionCallback callback);

    bool debugDisposed();

    int debugHandleCount();

    void dispose();

    ContainerLayer parent();

    void markNeedsAddToScene();

    void debugMarkClean();

    bool alwaysNeedsAddToScene();

    bool debugSubtreeNeedsAddToScene();

    EngineLayer engineLayer();

    void  engineLayer(EngineLayer value);

    void updateSubtreeNeedsAddToScene();

    Layer nextSibling();

    Layer previousSibling();

    void dropChild(Layer child);

    void adoptChild(Layer child);

    void remove();

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    S find<S extends Object>(Offset localPosition);

    AnnotationResult<S> findAllAnnotations<S extends Object>(Offset localPosition);

    void addToScene(SceneBuilder builder);

    String toStringShort();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Map<int, VoidCallback> _callbacks;

    static int _nextCallbackId;

    int _compositionCallbackCount;

    bool _debugMutationsLocked;

    bool _debugDisposed;

    LayerHandle<Layer> _parentHandle;

    int _refCount;

    bool _needsAddToScene;

    EngineLayer _engineLayer;

    Layer _nextSibling;

    Layer _previousSibling;


    void _updateSubtreeCompositionObserverCount(int delta);

    void _fireCompositionCallbacks(bool includeChildren);

    void _unref();

    void _addToSceneWithRetainedRendering(SceneBuilder builder);

};

class LayerHandle<T extends Layer> {
public:

     LayerHandle(T _layer);

    T layer();

    void  layer(T layer);

    String toString();

private:
    T _layer;


};

class PictureLayer : Layer {
public:
    Rect canvasBounds;


     PictureLayer(Rect canvasBounds);

    Picture picture();

    void  picture(Picture picture);

    bool isComplexHint();

    void  isComplexHint(bool value);

    bool willChangeHint();

    void  willChangeHint(bool value);

    void dispose();

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    Picture _picture;

    bool _isComplexHint;

    bool _willChangeHint;


};

class TextureLayer : Layer {
public:
    Rect rect;

    int textureId;

    bool freeze;

    FilterQuality filterQuality;


     TextureLayer(FilterQuality filterQuality, bool freeze, Rect rect, int textureId);

    void addToScene(SceneBuilder builder);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:

};

class PlatformViewLayer : Layer {
public:
    Rect rect;

    int viewId;


     PlatformViewLayer(Rect rect, int viewId);

    void addToScene(SceneBuilder builder);

private:

};

class PerformanceOverlayLayer : Layer {
public:
    int optionsMask;

    int rasterizerThreshold;

    bool checkerboardRasterCacheImages;

    bool checkerboardOffscreenLayers;


     PerformanceOverlayLayer(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, Rect overlayRect, int rasterizerThreshold);

    Rect overlayRect();

    void  overlayRect(Rect value);

    void addToScene(SceneBuilder builder);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    Rect _overlayRect;


};

class ContainerLayer : Layer {
public:

    Layer firstChild();

    Layer lastChild();

    bool hasChildren();

    Scene buildScene(SceneBuilder builder);

    void dispose();

    void updateSubtreeNeedsAddToScene();

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void attach(Object owner);

    void detach();

    void append(Layer child);

    void removeAllChildren();

    void addToScene(SceneBuilder builder);

    void addChildrenToScene(SceneBuilder builder);

    void applyTransform(Layer child, Matrix4 transform);

    List<Layer> depthFirstIterateChildren();

    List<DiagnosticsNode> debugDescribeChildren();

private:
    Layer _firstChild;

    Layer _lastChild;


    void _fireCompositionCallbacks(bool includeChildren);

    bool _debugUltimatePreviousSiblingOf(Layer child, Layer equals);

    bool _debugUltimateNextSiblingOf(Layer child, Layer equals);

    void _removeChild(Layer child);

};

class OffsetLayer : ContainerLayer {
public:

     OffsetLayer(Offset offset);

    Offset offset();

    void  offset(Offset value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void applyTransform(Layer child, Matrix4 transform);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

    Future<Image> toImage(Rect bounds, double pixelRatio);

private:
    Offset _offset;


};

class ClipRectLayer : ContainerLayer {
public:

     ClipRectLayer(Clip clipBehavior, Rect clipRect);

    Rect clipRect();

    void  clipRect(Rect value);

    Rect describeClipBounds();

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Rect _clipRect;

    Clip _clipBehavior;


};

class ClipRRectLayer : ContainerLayer {
public:

     ClipRRectLayer(Clip clipBehavior, RRect clipRRect);

    RRect clipRRect();

    void  clipRRect(RRect value);

    Rect describeClipBounds();

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    RRect _clipRRect;

    Clip _clipBehavior;


};

class ClipPathLayer : ContainerLayer {
public:

     ClipPathLayer(Clip clipBehavior, Path clipPath);

    Path clipPath();

    void  clipPath(Path value);

    Rect describeClipBounds();

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Path _clipPath;

    Clip _clipBehavior;


};

class ColorFilterLayer : ContainerLayer {
public:

     ColorFilterLayer(ColorFilter colorFilter);

    ColorFilter colorFilter();

    void  colorFilter(ColorFilter value);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ColorFilter _colorFilter;


};

class ImageFilterLayer : ContainerLayer {
public:

     ImageFilterLayer(ImageFilter imageFilter);

    ImageFilter imageFilter();

    void  imageFilter(ImageFilter value);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ImageFilter _imageFilter;


};

class TransformLayer : OffsetLayer {
public:

     TransformLayer(Unknown, Matrix4 transform);

    Matrix4 transform();

    void  transform(Matrix4 value);

    void addToScene(SceneBuilder builder);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void applyTransform(Layer child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Matrix4 _transform;

    Matrix4 _lastEffectiveTransform;

    Matrix4 _invertedTransform;

    bool _inverseDirty;


    Offset _transformOffset(Offset localPosition);

};

class OpacityLayer : OffsetLayer {
public:

     OpacityLayer(int alpha, Unknown);

    int alpha();

    void  alpha(int value);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;


};

class ShaderMaskLayer : ContainerLayer {
public:

     ShaderMaskLayer(BlendMode blendMode, Rect maskRect, Shader shader);

    Shader shader();

    void  shader(Shader value);

    Rect maskRect();

    void  maskRect(Rect value);

    BlendMode blendMode();

    void  blendMode(BlendMode value);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Shader _shader;

    Rect _maskRect;

    BlendMode _blendMode;


};

class BackdropFilterLayer : ContainerLayer {
public:

     BackdropFilterLayer(BlendMode blendMode, ImageFilter filter);

    ImageFilter filter();

    void  filter(ImageFilter value);

    BlendMode blendMode();

    void  blendMode(BlendMode value);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ImageFilter _filter;

    BlendMode _blendMode;


};

class PhysicalModelLayer : ContainerLayer {
public:

     PhysicalModelLayer(Clip clipBehavior, Path clipPath, Color color, double elevation, Color shadowColor);

    Path clipPath();

    void  clipPath(Path value);

    Clip clipBehavior();

    void  clipBehavior(Clip value);

    double elevation();

    void  elevation(double value);

    Color color();

    void  color(Color value);

    Color shadowColor();

    void  shadowColor(Color value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void addToScene(SceneBuilder builder);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Path _clipPath;

    Clip _clipBehavior;

    double _elevation;

    Color _color;

    Color _shadowColor;


};

class LayerLink {
public:
    Size leaderSize;


    LeaderLayer leader();

    String toString();

private:
    LeaderLayer _leader;

    Set<LeaderLayer> _debugPreviousLeaders;

    bool _debugLeaderCheckScheduled;


    void _registerLeader(LeaderLayer leader);

    void _unregisterLeader(LeaderLayer leader);

    void _debugScheduleLeadersCleanUpCheck();

};

class LeaderLayer : ContainerLayer {
public:

     LeaderLayer(LayerLink link, Offset offset);

    LayerLink link();

    void  link(LayerLink value);

    Offset offset();

    void  offset(Offset value);

    void attach(Object owner);

    void detach();

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void addToScene(SceneBuilder builder);

    void applyTransform(Layer child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    Offset _offset;


};

class FollowerLayer : ContainerLayer {
public:
    bool showWhenUnlinked;

    Offset unlinkedOffset;

    Offset linkedOffset;


     FollowerLayer(LayerLink link, Offset linkedOffset, bool showWhenUnlinked, Offset unlinkedOffset);

    LayerLink link();

    void  link(LayerLink value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    Matrix4 getLastTransform();

    bool alwaysNeedsAddToScene();

    void addToScene(SceneBuilder builder);

    void applyTransform(Layer child, Matrix4 transform);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    Offset _lastOffset;

    Matrix4 _lastTransform;

    Matrix4 _invertedTransform;

    bool _inverseDirty;


    Offset _transformOffset(Offset localPosition);

    static Matrix4 _collectTransformForLayerChain(List<ContainerLayer> layers);

    static Layer _pathsToCommonAncestor(Layer a, List<ContainerLayer> ancestorsA, List<ContainerLayer> ancestorsB, Layer b);

    bool _debugCheckLeaderBeforeFollower(List<ContainerLayer> followerToCommonAncestor, List<ContainerLayer> leaderToCommonAncestor);

    void _establishTransform();

};

class AnnotatedRegionLayer<T extends Object> : ContainerLayer {
public:
    T value;

    Size size;

    Offset offset;

    bool opaque;


     AnnotatedRegionLayer(Offset offset, bool opaque, Size size, T value);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif