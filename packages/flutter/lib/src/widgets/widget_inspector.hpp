#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_WIDGET_INSPECTOR
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_WIDGET_INSPECTOR
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <dart/collection/collection.hpp>
#include <dart/convert/convert.hpp>
#include <dart/developer/developer.hpp>
#include <dart/math/math.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/lib/rendering.hpp>
#include <packages/flutter/flutter.hpp>
#include "app.hpp"
#include "basic.hpp"
#include "binding.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"


class _ProxyLayerCls : public LayerCls {
public:

    virtual void addToScene(SceneBuilder builder);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    Layer _layer;


     _ProxyLayerCls(Layer _layer);
};
using _ProxyLayer = std::shared_ptr<_ProxyLayerCls>;

class _MulticastCanvasCls : public ObjectCls {
public:

    virtual void clipPath(bool doAntiAlias, Path path);

    virtual void clipRRect(bool doAntiAlias, RRect rrect);

    virtual void clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect);

    virtual void drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter);

    virtual void drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms);

    virtual void drawCircle(Offset c, Paint paint, double radius);

    virtual void drawColor(BlendMode blendMode, Color color);

    virtual void drawDRRect(RRect inner, RRect outer, Paint paint);

    virtual void drawImage(Image image, Offset p, Paint paint);

    virtual void drawImageNine(Rect center, Rect dst, Image image, Paint paint);

    virtual void drawImageRect(Rect dst, Image image, Paint paint, Rect src);

    virtual void drawLine(Offset p1, Offset p2, Paint paint);

    virtual void drawOval(Paint paint, Rect rect);

    virtual void drawPaint(Paint paint);

    virtual void drawParagraph(Offset offset, Paragraph paragraph);

    virtual void drawPath(Paint paint, Path path);

    virtual void drawPicture(Picture picture);

    virtual void drawPoints(Paint paint, PointMode pointMode, List<Offset> points);

    virtual void drawRRect(Paint paint, RRect rrect);

    virtual void drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms);

    virtual void drawRawPoints(Paint paint, PointMode pointMode, Float32List points);

    virtual void drawRect(Paint paint, Rect rect);

    virtual void drawShadow(Color color, double elevation, Path path, bool transparentOccluder);

    virtual void drawVertices(BlendMode blendMode, Paint paint, Vertices vertices);

    virtual int getSaveCount();

    virtual void restore();

    virtual void rotate(double radians);

    virtual void save();

    virtual void saveLayer(Rect bounds, Paint paint);

    virtual void scale(double sx, double sy);

    virtual void skew(double sx, double sy);

    virtual void transform(Float64List matrix4);

    virtual void translate(double dx, double dy);

    virtual dynamic noSuchMethod(Invocation invocation);

private:
    Canvas _main;

    Canvas _screenshot;


     _MulticastCanvasCls(Canvas main, Canvas screenshot);

};
using _MulticastCanvas = std::shared_ptr<_MulticastCanvasCls>;
Rect _calculateSubtreeBoundsHelper(RenderObject object, Matrix4 transform);

Rect _calculateSubtreeBounds(RenderObject object);


class _ScreenshotContainerLayerCls : public OffsetLayerCls {
public:

    virtual void addToScene(SceneBuilder builder);

private:

};
using _ScreenshotContainerLayer = std::shared_ptr<_ScreenshotContainerLayerCls>;

class _ScreenshotDataCls : public ObjectCls {
public:
    RenderObject target;

    OffsetLayer containerLayer;

    bool foundTarget;

    bool includeInScreenshot;

    bool includeInRegularContext;


    virtual Offset screenshotOffset();

    virtual void  screenshotOffset(Offset offset);

private:

     _ScreenshotDataCls(RenderObject target);

};
using _ScreenshotData = std::shared_ptr<_ScreenshotDataCls>;

class _ScreenshotPaintingContextCls : public PaintingContextCls {
public:

    virtual Canvas canvas();

    virtual void stopRecordingIfNeeded();

    virtual void appendLayer(Layer layer);

    virtual PaintingContext createChildContext(Rect bounds, ContainerLayer childLayer);

    virtual void paintChild(RenderObject child, Offset offset);

    static Future<Image> toImage(bool debugPaint, double pixelRatio, Rect renderBounds, RenderObject renderObject);

private:
    _ScreenshotData _data;

    PictureLayer _screenshotCurrentLayer;

    PictureRecorder _screenshotRecorder;

    Canvas _screenshotCanvas;

    _MulticastCanvas _multicastCanvas;


     _ScreenshotPaintingContextCls(ContainerLayer containerLayer, Rect estimatedBounds, _ScreenshotData screenshotData);

    virtual bool _isScreenshotRecording();

    virtual void _startRecordingScreenshot();

    virtual void _stopRecordingScreenshotIfNeeded();

};
using _ScreenshotPaintingContext = std::shared_ptr<_ScreenshotPaintingContextCls>;

class _DiagnosticsPathNodeCls : public ObjectCls {
public:
    DiagnosticsNode node;

    List<DiagnosticsNode> children;

    int childIndex;


private:

     _DiagnosticsPathNodeCls(int childIndex, List<DiagnosticsNode> children, DiagnosticsNode node);

};
using _DiagnosticsPathNode = std::shared_ptr<_DiagnosticsPathNodeCls>;
List<_DiagnosticsPathNode> _followDiagnosticableChain(List<Diagnosticable> chain, String name, DiagnosticsTreeStyle style);


class _InspectorReferenceDataCls : public ObjectCls {
public:
    Object object;

    int count;


private:

     _InspectorReferenceDataCls(Object object);
};
using _InspectorReferenceData = std::shared_ptr<_InspectorReferenceDataCls>;

class _WidgetInspectorServiceCls : public ObjectCls {
public:

private:

};
using _WidgetInspectorService = std::shared_ptr<_WidgetInspectorServiceCls>;

class WidgetInspectorServiceCls : public ObjectCls {
public:
    InspectorSelection selection;

    InspectorSelectionChangedCallback selectionChangedCallback;


    static WidgetInspectorService instance();

    static void  instance(WidgetInspectorService instance);

    virtual List<String> pubRootDirectories();

    virtual void registerServiceExtension(ServiceExtensionCallback callback, String name);

    virtual Future<void> forceRebuild();

    virtual bool isStructuredErrorsEnabled();

    virtual void initServiceExtensions(RegisterServiceExtensionCallback registerServiceExtensionCallback);

    virtual void disposeAllGroups();

    virtual void resetAllState();

    virtual void disposeGroup(String name);

    virtual String toId(String groupName, Object object);

    virtual bool isWidgetTreeReady(String groupName);

    virtual Object toObject(String groupName, String id);

    virtual Object toObjectForSourceLocation(String groupName, String id);

    virtual void disposeId(String groupName, String id);

    virtual void setPubRootDirectories(List<String> pubRootDirectories);

    virtual void resetPubRootDirectories();

    virtual void addPubRootDirectories(List<String> pubRootDirectories);

    virtual void removePubRootDirectories(List<String> pubRootDirectories);

    virtual bool setSelectionById(String groupName, String id);

    virtual bool setSelection(String groupName, Object object);

    virtual String devToolsInspectorUri(String inspectorRef);

    virtual String getParentChain(String groupName, String id);

    virtual String getProperties(String diagnosticsNodeId, String groupName);

    virtual String getChildren(String diagnosticsNodeId, String groupName);

    virtual String getChildrenSummaryTree(String diagnosticsNodeId, String groupName);

    virtual String getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName);

    virtual String getRootWidget(String groupName);

    virtual String getRootWidgetSummaryTree(String groupName);

    virtual String getRootRenderObject(String groupName);

    virtual String getDetailsSubtree(String groupName, String id, int subtreeDepth);

    virtual String getSelectedRenderObject(String groupName, String previousSelectionId);

    virtual String getSelectedWidget(String groupName, String previousSelectionId);

    virtual Future<Image> screenshot(bool debugPaint, double height, double margin, double maxPixelRatio, Object object, double width);

    virtual String getSelectedSummaryWidget(String groupName, String previousSelectionId);

    virtual bool isWidgetCreationTracked();

    virtual void postEvent(Map<Object, Object> eventData, String eventKind);

    virtual void performReassemble();

private:
    List<String> _serializeRing;

    int _serializeRingIndex;

    static WidgetInspectorService _instance;

    static bool _debugServiceExtensionsRegistered;

    Map<String, Set<_InspectorReferenceData>> _groups;

    Map<String, _InspectorReferenceData> _idToReferenceData;

    Map<Object, String> _objectToId;

    int _nextId;

    List<String> _pubRootDirectories;

    HashMap<String, bool> _isLocalCreationCache;

    bool _trackRebuildDirtyWidgets;

    bool _trackRepaintWidgets;

    RegisterServiceExtensionCallback _registerServiceExtensionCallback;

    static String _consoleObjectGroup;

    int _errorsSinceReload;

    bool _widgetCreationTracked;

    Duration _frameStart;

    _ElementLocationStatsTracker _rebuildStats;

    _ElementLocationStatsTracker _repaintStats;


    virtual void _registerSignalServiceExtension(FutureOr<Object> callback() , String name);

    virtual void _registerObjectGroupServiceExtension(FutureOr<Object> callback(String objectGroup) , String name);

    virtual void _registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter);

    virtual void _postExtensionStateChangedEvent(String name, Object value);

    virtual void _registerServiceExtensionWithArg(FutureOr<Object> callback(String objectGroup, String objectId) , String name);

    virtual void _registerServiceExtensionVarArgs(FutureOr<Object> callback(List<String> args) , String name);

    virtual void _reportStructuredError(FlutterErrorDetails details);

    virtual void _resetErrorCount();

    virtual void _clearStats();

    virtual void _decrementReferenceCount(_InspectorReferenceData reference);

    virtual String _devToolsInspectorUriForElement(Element element);

    virtual List<Object> _getParentChain(String groupName, String id);

    virtual Map<String, Object> _pathNodeToJson(InspectorSerializationDelegate delegate, _DiagnosticsPathNode pathNode);

    virtual List<Element> _getRawElementParentChain(Element element, int numLocalParents);

    virtual List<_DiagnosticsPathNode> _getElementParentChain(Element element, String groupName, int numLocalParents);

    virtual List<_DiagnosticsPathNode> _getRenderObjectParentChain(String groupName, RenderObject renderObject);

    virtual Map<String, Object> _nodeToJson(InspectorSerializationDelegate delegate, DiagnosticsNode node);

    virtual bool _isValueCreatedByLocalProject(Object value);

    virtual bool _isLocalCreationLocationImpl(String locationUri);

    virtual bool _isLocalCreationLocation(String locationUri);

    virtual String _safeJsonEncode(Object object);

    virtual List<DiagnosticsNode> _truncateNodes(int maxDescendentsTruncatableNode, Iterable<DiagnosticsNode> nodes);

    virtual List<Map<String, Object>> _nodesToJson(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent);

    virtual List<Object> _getProperties(String diagnosticsNodeId, String groupName);

    virtual List<Object> _getChildren(String diagnosticsNodeId, String groupName);

    virtual List<Object> _getChildrenSummaryTree(String diagnosticsNodeId, String groupName);

    virtual List<Object> _getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName);

    virtual bool _shouldShowInSummaryTree(DiagnosticsNode node);

    virtual List<DiagnosticsNode> _getChildrenFiltered(InspectorSerializationDelegate delegate, DiagnosticsNode node);

    virtual List<DiagnosticsNode> _filterChildren(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes);

    virtual Map<String, Object> _getRootWidget(String groupName);

    virtual Map<String, Object> _getRootWidgetSummaryTree(String groupName);

    virtual Map<String, Object> _getRootRenderObject(String groupName);

    virtual Map<String, Object> _getDetailsSubtree(String groupName, String id, int subtreeDepth);

    virtual Map<String, Object> _getSelectedRenderObject(String groupName, String previousSelectionId);

    virtual Map<String, Object> _getSelectedWidget(String groupName, String previousSelectionId);

    virtual Map<String, Object> _getSelectedSummaryWidget(String groupName, String previousSelectionId);

    virtual void _onFrameStart(Duration timeStamp);

    virtual void _onFrameEnd(Duration timeStamp);

    virtual void _postStatsEvent(String eventName, _ElementLocationStatsTracker stats);

    virtual void _onRebuildWidget(bool builtOnce, Element element);

    virtual void _onPaint(RenderObject renderObject);

};
using WidgetInspectorService = std::shared_ptr<WidgetInspectorServiceCls>;

class _LocationCountCls : public ObjectCls {
public:
    int id;

    bool local;

    _Location location;


    virtual int count();

    virtual void reset();

    virtual void increment();

private:
    int _count;


     _LocationCountCls(int id, bool local, _Location location);
};
using _LocationCount = std::shared_ptr<_LocationCountCls>;

class _ElementLocationStatsTrackerCls : public ObjectCls {
public:
    List<_LocationCount> active;

    List<_LocationCount> newLocations;


    virtual void add(Element element);

    virtual void resetCounts();

    virtual Map<String, dynamic> exportToJson(Duration startTime);

private:
    List<_LocationCount> _stats;


};
using _ElementLocationStatsTracker = std::shared_ptr<_ElementLocationStatsTrackerCls>;

class _WidgetForTypeTestsCls : public WidgetCls {
public:

    virtual Element createElement();

private:

     _WidgetForTypeTestsCls();
};
using _WidgetForTypeTests = std::shared_ptr<_WidgetForTypeTestsCls>;

class WidgetInspectorCls : public StatefulWidgetCls {
public:
    Widget child;

    InspectorSelectButtonBuilder selectButtonBuilder;


     WidgetInspectorCls(Widget child, Unknown key, InspectorSelectButtonBuilder selectButtonBuilder);

    virtual State<WidgetInspector> createState();

private:

};
using WidgetInspector = std::shared_ptr<WidgetInspectorCls>;

class _WidgetInspectorStateCls : public StateCls<WidgetInspector> {
public:
    InspectorSelection selection;

    bool isSelectMode;


    virtual void initState();

    virtual void dispose();

    virtual List<RenderObject> hitTest(Offset position, RenderObject root);

    virtual Widget build(BuildContext context);

private:
    Offset _lastPointerLocation;

    GlobalKey _ignorePointerKey;

    static double _edgeHitMargin;

    InspectorSelectionChangedCallback _selectionChangedCallback;


     _WidgetInspectorStateCls();

    virtual bool _hitTestHelper(List<RenderObject> edgeHits, List<RenderObject> hits, RenderObject object, Offset position, Matrix4 transform);

    virtual void _inspectAt(Offset position);

    virtual void _handlePanDown(DragDownDetails event);

    virtual void _handlePanUpdate(DragUpdateDetails event);

    virtual void _handlePanEnd(DragEndDetails details);

    virtual void _handleTap();

    virtual void _handleEnableSelect();

};
using _WidgetInspectorState = std::shared_ptr<_WidgetInspectorStateCls>;

class InspectorSelectionCls : public ObjectCls {
public:

    virtual List<RenderObject> candidates();

    virtual void  candidates(List<RenderObject> value);

    virtual int index();

    virtual void  index(int value);

    virtual void clear();

    virtual RenderObject current();

    virtual void  current(RenderObject value);

    virtual Element currentElement();

    virtual void  currentElement(Element element);

    virtual bool active();

private:
    List<RenderObject> _candidates;

    int _index;

    RenderObject _current;

    Element _currentElement;


    virtual void _computeCurrent();

};
using InspectorSelection = std::shared_ptr<InspectorSelectionCls>;

class _InspectorOverlayCls : public LeafRenderObjectWidgetCls {
public:
    InspectorSelection selection;


    virtual _RenderInspectorOverlay createRenderObject(BuildContext context);

    virtual void updateRenderObject(BuildContext context, _RenderInspectorOverlay renderObject);

private:

     _InspectorOverlayCls(InspectorSelection selection);
};
using _InspectorOverlay = std::shared_ptr<_InspectorOverlayCls>;

class _RenderInspectorOverlayCls : public RenderBoxCls {
public:

    virtual InspectorSelection selection();

    virtual void  selection(InspectorSelection value);

    virtual bool sizedByParent();

    virtual bool alwaysNeedsCompositing();

    virtual Size computeDryLayout(BoxConstraints constraints);

    virtual void paint(PaintingContext context, Offset offset);

private:
    InspectorSelection _selection;


     _RenderInspectorOverlayCls(InspectorSelection selection);

};
using _RenderInspectorOverlay = std::shared_ptr<_RenderInspectorOverlayCls>;

class _TransformedRectCls : public ObjectCls {
public:
    Rect rect;

    Matrix4 transform;


    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _TransformedRectCls(RenderObject ancestor, RenderObject object);

};
using _TransformedRect = std::shared_ptr<_TransformedRectCls>;

class _InspectorOverlayRenderStateCls : public ObjectCls {
public:
    Rect overlayRect;

    _TransformedRect selected;

    List<_TransformedRect> candidates;

    String tooltip;

    TextDirection textDirection;


    virtual bool operator==(Object other);

    virtual int hashCode();

private:

     _InspectorOverlayRenderStateCls(List<_TransformedRect> candidates, Rect overlayRect, _TransformedRect selected, TextDirection textDirection, String tooltip);
};
using _InspectorOverlayRenderState = std::shared_ptr<_InspectorOverlayRenderStateCls>;
int _kMaxTooltipLines;

Color _kTooltipBackgroundColor;

Color _kHighlightedRenderObjectFillColor;

Color _kHighlightedRenderObjectBorderColor;


class _InspectorOverlayLayerCls : public LayerCls {
public:
    InspectorSelection selection;

    Rect overlayRect;

    RenderObject rootRenderObject;


    virtual void addToScene(SceneBuilder builder);

    template<typename S>  virtual bool findAnnotations(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    _InspectorOverlayRenderState _lastState;

    Picture _picture;

    TextPainter _textPainter;

    double _textPainterMaxWidth;


     _InspectorOverlayLayerCls(Rect overlayRect, RenderObject rootRenderObject, InspectorSelection selection);

    virtual Picture _buildPicture(_InspectorOverlayRenderState state);

    virtual void _paintDescription(Canvas canvas, String message, Size size, Offset target, Rect targetRect, TextDirection textDirection, double verticalOffset);

    virtual bool _isInInspectorRenderObjectTree(RenderObject child);

};
using _InspectorOverlayLayer = std::shared_ptr<_InspectorOverlayLayerCls>;
double _kScreenEdgeMargin;

double _kTooltipPadding;

double _kInspectButtonMargin;

double _kOffScreenMargin;

TextStyle _messageStyle;


class _HasCreationLocationCls : public ObjectCls {
public:

private:

    virtual _Location _location();
};
using _HasCreationLocation = std::shared_ptr<_HasCreationLocationCls>;

class _LocationCls : public ObjectCls {
public:
    String file;

    int line;

    int column;

    String name;


    virtual Map<String, Object> toJsonMap();

    virtual String toString();

private:

     _LocationCls(int column, String file, int line, String name);
};
using _Location = std::shared_ptr<_LocationCls>;
bool _isDebugCreator(DiagnosticsNode node);

Iterable<DiagnosticsNode> debugTransformDebugCreator(Iterable<DiagnosticsNode> properties);

Iterable<DiagnosticsNode> _parseDiagnosticsNode(ErrorSummary errorSummary, DiagnosticsNode node);

Iterable<DiagnosticsNode> _describeRelevantUserCode(Element element, ErrorSummary errorSummary);


class DevToolsDeepLinkPropertyCls : public DiagnosticsPropertyCls<String> {
public:

     DevToolsDeepLinkPropertyCls(String description, String url);

private:

};
using DevToolsDeepLinkProperty = std::shared_ptr<DevToolsDeepLinkPropertyCls>;
bool debugIsLocalCreationLocation(Object object);

bool debugIsWidgetLocalCreation(Widget widget);

String _describeCreationLocation(Object object);

_Location _getObjectCreationLocation(Object object);

_Location _getCreationLocation(Object object);

Map<_Location, int> _locationToId;

List<_Location> _locations;

int _toLocationId(_Location location);


class InspectorSerializationDelegateCls : public ObjectCls {
public:
    WidgetInspectorService service;

    String groupName;

    bool summaryTree;

    int maxDescendentsTruncatableNode;

    bool includeProperties;

    int subtreeDepth;

    bool expandPropertyValues;

    Map<String, Object> Function(DiagnosticsNode , InspectorSerializationDelegate ) addAdditionalPropertiesCallback;


     InspectorSerializationDelegateCls(Map<String, Object> Function(DiagnosticsNode , InspectorSerializationDelegate ) addAdditionalPropertiesCallback, bool expandPropertyValues, String groupName, bool includeProperties, int maxDescendentsTruncatableNode, WidgetInspectorService service, int subtreeDepth, bool summaryTree);
    virtual Map<String, Object> additionalNodeProperties(DiagnosticsNode node);

    virtual DiagnosticsSerializationDelegate delegateForNode(DiagnosticsNode node);

    virtual List<DiagnosticsNode> filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    virtual List<DiagnosticsNode> filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    virtual List<DiagnosticsNode> truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    virtual DiagnosticsSerializationDelegate copyWith(bool includeProperties, int subtreeDepth);

private:
    List<DiagnosticsNode> _nodesCreatedByLocalProject;


    virtual bool _interactive();

};
using InspectorSerializationDelegate = std::shared_ptr<InspectorSerializationDelegateCls>;


#endif