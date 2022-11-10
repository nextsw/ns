#ifndef PACKAGES_FLUTTER_LIB_SRC_RENDERING_LAYER
#define PACKAGES_FLUTTER_LIB_SRC_RENDERING_LAYER
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/flutter/flutter.hpp>
#include <packages/vector_math/vector_math.hpp>
#include "debug.hpp"


template<typename T> class AnnotationEntryCls : public ObjectCls {
public:
    T annotation;

    Offset localPosition;


     AnnotationEntryCls(T annotation, Offset localPosition);

    virtual String toString();

private:

};
template<typename T> using AnnotationEntry = std::shared_ptr<AnnotationEntryCls<T>>;

template<typename T> class AnnotationResultCls : public ObjectCls {
public:

    virtual void add(AnnotationEntry<T> entry);

    virtual Iterable<AnnotationEntry<T>> entries();

    virtual Iterable<T> annotations();

private:
    List<AnnotationEntry<T>> _entries;


};
template<typename T> using AnnotationResult = std::shared_ptr<AnnotationResultCls<T>>;

class LayerCls : public AbstractNodeCls {
public:
    Object debugCreator;


    virtual bool subtreeHasCompositionCallbacks();

    virtual Rect describeClipBounds();

    virtual VoidCallback addCompositionCallback(CompositionCallback callback);

    virtual bool debugDisposed();

    virtual int debugHandleCount();

    virtual void dispose();

    virtual ContainerLayer parent();

    virtual void markNeedsAddToScene();

    virtual void debugMarkClean();

    virtual bool alwaysNeedsAddToScene();

    virtual bool debugSubtreeNeedsAddToScene();

    virtual EngineLayer engineLayer();

    virtual void  engineLayer(EngineLayer value);

    virtual void updateSubtreeNeedsAddToScene();

    virtual Layer nextSibling();

    virtual Layer previousSibling();

    virtual void dropChild(Layer child);

    virtual void adoptChild(Layer child);

    virtual void remove();

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    template<typename S>  virtual S find(Offset localPosition);

    template<typename S>  virtual AnnotationResult<S> findAllAnnotations(Offset localPosition);

    virtual void addToScene(SceneBuilder builder);
    virtual String toStringShort();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

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


    virtual void _updateSubtreeCompositionObserverCount(int delta);

    virtual void _fireCompositionCallbacks(bool includeChildren);

    virtual void _unref();

    virtual void _addToSceneWithRetainedRendering(SceneBuilder builder);

};
using Layer = std::shared_ptr<LayerCls>;

template<typename T> class LayerHandleCls : public ObjectCls {
public:

     LayerHandleCls(T _layer);

    virtual T layer();

    virtual void  layer(T layer);

    virtual String toString();

private:
    T _layer;


};
template<typename T> using LayerHandle = std::shared_ptr<LayerHandleCls<T>>;

class PictureLayerCls : public LayerCls {
public:
    Rect canvasBounds;


     PictureLayerCls(Rect canvasBounds);
    virtual Picture picture();

    virtual void  picture(Picture picture);

    virtual bool isComplexHint();

    virtual void  isComplexHint(bool value);

    virtual bool willChangeHint();

    virtual void  willChangeHint(bool value);

    virtual void dispose();

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    Picture _picture;

    bool _isComplexHint;

    bool _willChangeHint;


};
using PictureLayer = std::shared_ptr<PictureLayerCls>;

class TextureLayerCls : public LayerCls {
public:
    Rect rect;

    int textureId;

    bool freeze;

    FilterQuality filterQuality;


     TextureLayerCls(FilterQuality filterQuality, bool freeze, Rect rect, int textureId);

    virtual void addToScene(SceneBuilder builder);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:

};
using TextureLayer = std::shared_ptr<TextureLayerCls>;

class PlatformViewLayerCls : public LayerCls {
public:
    Rect rect;

    int viewId;


     PlatformViewLayerCls(Rect rect, int viewId);

    virtual void addToScene(SceneBuilder builder);

private:

};
using PlatformViewLayer = std::shared_ptr<PlatformViewLayerCls>;

class PerformanceOverlayLayerCls : public LayerCls {
public:
    int optionsMask;

    int rasterizerThreshold;

    bool checkerboardRasterCacheImages;

    bool checkerboardOffscreenLayers;


     PerformanceOverlayLayerCls(bool checkerboardOffscreenLayers, bool checkerboardRasterCacheImages, int optionsMask, Rect overlayRect, int rasterizerThreshold);

    virtual Rect overlayRect();

    virtual void  overlayRect(Rect value);

    virtual void addToScene(SceneBuilder builder);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    Rect _overlayRect;


};
using PerformanceOverlayLayer = std::shared_ptr<PerformanceOverlayLayerCls>;

class ContainerLayerCls : public LayerCls {
public:

    virtual Layer firstChild();

    virtual Layer lastChild();

    virtual bool hasChildren();

    virtual Scene buildScene(SceneBuilder builder);

    virtual void dispose();

    virtual void updateSubtreeNeedsAddToScene();

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void attach(Object owner);

    virtual void detach();

    virtual void append(Layer child);

    virtual void removeAllChildren();

    virtual void addToScene(SceneBuilder builder);

    virtual void addChildrenToScene(SceneBuilder builder);

    virtual void applyTransform(Layer child, Matrix4 transform);

    virtual List<Layer> depthFirstIterateChildren();

    virtual List<DiagnosticsNode> debugDescribeChildren();

private:
    Layer _firstChild;

    Layer _lastChild;


    virtual void _fireCompositionCallbacks(bool includeChildren);

    virtual bool _debugUltimatePreviousSiblingOf(Layer child, Layer equals);

    virtual bool _debugUltimateNextSiblingOf(Layer child, Layer equals);

    virtual void _removeChild(Layer child);

};
using ContainerLayer = std::shared_ptr<ContainerLayerCls>;

class OffsetLayerCls : public ContainerLayerCls {
public:

     OffsetLayerCls(Offset offset);

    virtual Offset offset();

    virtual void  offset(Offset value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void applyTransform(Layer child, Matrix4 transform);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

    virtual Future<Image> toImage(Rect bounds, double pixelRatio);

private:
    Offset _offset;


};
using OffsetLayer = std::shared_ptr<OffsetLayerCls>;

class ClipRectLayerCls : public ContainerLayerCls {
public:

     ClipRectLayerCls(Clip clipBehavior, Rect clipRect);

    virtual Rect clipRect();

    virtual void  clipRect(Rect value);

    virtual Rect describeClipBounds();

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Rect _clipRect;

    Clip _clipBehavior;


};
using ClipRectLayer = std::shared_ptr<ClipRectLayerCls>;

class ClipRRectLayerCls : public ContainerLayerCls {
public:

     ClipRRectLayerCls(Clip clipBehavior, RRect clipRRect);

    virtual RRect clipRRect();

    virtual void  clipRRect(RRect value);

    virtual Rect describeClipBounds();

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    RRect _clipRRect;

    Clip _clipBehavior;


};
using ClipRRectLayer = std::shared_ptr<ClipRRectLayerCls>;

class ClipPathLayerCls : public ContainerLayerCls {
public:

     ClipPathLayerCls(Clip clipBehavior, Path clipPath);

    virtual Path clipPath();

    virtual void  clipPath(Path value);

    virtual Rect describeClipBounds();

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Path _clipPath;

    Clip _clipBehavior;


};
using ClipPathLayer = std::shared_ptr<ClipPathLayerCls>;

class ColorFilterLayerCls : public ContainerLayerCls {
public:

     ColorFilterLayerCls(ColorFilter colorFilter);

    virtual ColorFilter colorFilter();

    virtual void  colorFilter(ColorFilter value);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ColorFilter _colorFilter;


};
using ColorFilterLayer = std::shared_ptr<ColorFilterLayerCls>;

class ImageFilterLayerCls : public ContainerLayerCls {
public:

     ImageFilterLayerCls(ImageFilter imageFilter);

    virtual ImageFilter imageFilter();

    virtual void  imageFilter(ImageFilter value);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ImageFilter _imageFilter;


};
using ImageFilterLayer = std::shared_ptr<ImageFilterLayerCls>;

class TransformLayerCls : public OffsetLayerCls {
public:

     TransformLayerCls(Unknown offset, Matrix4 transform);

    virtual Matrix4 transform();

    virtual void  transform(Matrix4 value);

    virtual void addToScene(SceneBuilder builder);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void applyTransform(Layer child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Matrix4 _transform;

    Matrix4 _lastEffectiveTransform;

    Matrix4 _invertedTransform;

    bool _inverseDirty;


    virtual Offset _transformOffset(Offset localPosition);

};
using TransformLayer = std::shared_ptr<TransformLayerCls>;

class OpacityLayerCls : public OffsetLayerCls {
public:

     OpacityLayerCls(int alpha, Unknown offset);

    virtual int alpha();

    virtual void  alpha(int value);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    int _alpha;


};
using OpacityLayer = std::shared_ptr<OpacityLayerCls>;

class ShaderMaskLayerCls : public ContainerLayerCls {
public:

     ShaderMaskLayerCls(BlendMode blendMode, Rect maskRect, Shader shader);

    virtual Shader shader();

    virtual void  shader(Shader value);

    virtual Rect maskRect();

    virtual void  maskRect(Rect value);

    virtual BlendMode blendMode();

    virtual void  blendMode(BlendMode value);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Shader _shader;

    Rect _maskRect;

    BlendMode _blendMode;


};
using ShaderMaskLayer = std::shared_ptr<ShaderMaskLayerCls>;

class BackdropFilterLayerCls : public ContainerLayerCls {
public:

     BackdropFilterLayerCls(BlendMode blendMode, ImageFilter filter);

    virtual ImageFilter filter();

    virtual void  filter(ImageFilter value);

    virtual BlendMode blendMode();

    virtual void  blendMode(BlendMode value);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    ImageFilter _filter;

    BlendMode _blendMode;


};
using BackdropFilterLayer = std::shared_ptr<BackdropFilterLayerCls>;

class PhysicalModelLayerCls : public ContainerLayerCls {
public:

     PhysicalModelLayerCls(Clip clipBehavior, Path clipPath, Color color, double elevation, Color shadowColor);

    virtual Path clipPath();

    virtual void  clipPath(Path value);

    virtual Clip clipBehavior();

    virtual void  clipBehavior(Clip value);

    virtual double elevation();

    virtual void  elevation(double value);

    virtual Color color();

    virtual void  color(Color value);

    virtual Color shadowColor();

    virtual void  shadowColor(Color value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void addToScene(SceneBuilder builder);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Path _clipPath;

    Clip _clipBehavior;

    double _elevation;

    Color _color;

    Color _shadowColor;


};
using PhysicalModelLayer = std::shared_ptr<PhysicalModelLayerCls>;

class LayerLinkCls : public ObjectCls {
public:
    Size leaderSize;


    virtual LeaderLayer leader();

    virtual String toString();

private:
    LeaderLayer _leader;

    Set<LeaderLayer> _debugPreviousLeaders;

    bool _debugLeaderCheckScheduled;


    virtual void _registerLeader(LeaderLayer leader);

    virtual void _unregisterLeader(LeaderLayer leader);

    virtual void _debugScheduleLeadersCleanUpCheck();

};
using LayerLink = std::shared_ptr<LayerLinkCls>;

class LeaderLayerCls : public ContainerLayerCls {
public:

     LeaderLayerCls(LayerLink link, Offset offset);

    virtual LayerLink link();

    virtual void  link(LayerLink value);

    virtual Offset offset();

    virtual void  offset(Offset value);

    virtual void attach(Object owner);

    virtual void detach();

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void addToScene(SceneBuilder builder);

    virtual void applyTransform(Layer child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    Offset _offset;


};
using LeaderLayer = std::shared_ptr<LeaderLayerCls>;

class FollowerLayerCls : public ContainerLayerCls {
public:
    bool showWhenUnlinked;

    Offset unlinkedOffset;

    Offset linkedOffset;


     FollowerLayerCls(LayerLink link, Offset linkedOffset, bool showWhenUnlinked, Offset unlinkedOffset);

    virtual LayerLink link();

    virtual void  link(LayerLink value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual Matrix4 getLastTransform();

    virtual bool alwaysNeedsAddToScene();

    virtual void addToScene(SceneBuilder builder);

    virtual void applyTransform(Layer child, Matrix4 transform);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    LayerLink _link;

    Offset _lastOffset;

    Matrix4 _lastTransform;

    Matrix4 _invertedTransform;

    bool _inverseDirty;


    virtual Offset _transformOffset(Offset localPosition);

    static Matrix4 _collectTransformForLayerChain(List<ContainerLayer> layers);

    static Layer _pathsToCommonAncestor(Layer a, List<ContainerLayer> ancestorsA, List<ContainerLayer> ancestorsB, Layer b);

    virtual bool _debugCheckLeaderBeforeFollower(List<ContainerLayer> followerToCommonAncestor, List<ContainerLayer> leaderToCommonAncestor);

    virtual void _establishTransform();

};
using FollowerLayer = std::shared_ptr<FollowerLayerCls>;

template<typename T> class AnnotatedRegionLayerCls : public ContainerLayerCls {
public:
    T value;

    Size size;

    Offset offset;

    bool opaque;


     AnnotatedRegionLayerCls(Offset offset, bool opaque, Size size, T value);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
template<typename T> using AnnotatedRegionLayer = std::shared_ptr<AnnotatedRegionLayerCls<T>>;


#endif