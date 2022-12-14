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

    template<typename S>
 virtual bool findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst);

private:
    Layer _layer;


     _ProxyLayerCls(Layer _layer);
};
using _ProxyLayer = std::shared_ptr<_ProxyLayerCls>;

class _MulticastCanvasCls : public ObjectCls {
public:

    virtual void clipPath(Path path, bool doAntiAlias);

    virtual void clipRRect(RRect rrect, bool doAntiAlias);

    virtual void clipRect(Rect rect, ClipOp clipOp, bool doAntiAlias);

    virtual void drawArc(Rect rect, double startAngle, double sweepAngle, bool useCenter, Paint paint);

    virtual void drawAtlas(Image atlas, List<RSTransform> transforms, List<Rect> rects, List<Color> colors, BlendMode blendMode, Rect cullRect, Paint paint);

    virtual void drawCircle(Offset c, double radius, Paint paint);

    virtual void drawColor(Color color, BlendMode blendMode);

    virtual void drawDRRect(RRect outer, RRect inner, Paint paint);

    virtual void drawImage(Image image, Offset p, Paint paint);

    virtual void drawImageNine(Image image, Rect center, Rect dst, Paint paint);

    virtual void drawImageRect(Image image, Rect src, Rect dst, Paint paint);

    virtual void drawLine(Offset p1, Offset p2, Paint paint);

    virtual void drawOval(Rect rect, Paint paint);

    virtual void drawPaint(Paint paint);

    virtual void drawParagraph(Paragraph paragraph, Offset offset);

    virtual void drawPath(Path path, Paint paint);

    virtual void drawPicture(Picture picture);

    virtual void drawPoints(PointMode pointMode, List<Offset> points, Paint paint);

    virtual void drawRRect(RRect rrect, Paint paint);

    virtual void drawRawAtlas(Image atlas, Float32List rstTransforms, Float32List rects, Int32List colors, BlendMode blendMode, Rect cullRect, Paint paint);

    virtual void drawRawPoints(PointMode pointMode, Float32List points, Paint paint);

    virtual void drawRect(Rect rect, Paint paint);

    virtual void drawShadow(Path path, Color color, double elevation, bool transparentOccluder);

    virtual void drawVertices(Vertices vertices, BlendMode blendMode, Paint paint);

    virtual int getSaveCount();

    virtual void restore();

    virtual void rotate(double radians);

    virtual void save();

    virtual void saveLayer(Rect bounds, Paint paint);

    virtual void scale(double sx, double sy);

    virtual void skew(double sx, double sy);

    virtual void transform(Float64List matrix4);

    virtual void translate(double dx, double dy);

    virtual Object noSuchMethod(Invocation invocation);

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

    virtual PaintingContext createChildContext(ContainerLayer childLayer, Rect bounds);

    virtual void paintChild(RenderObject child, Offset offset);

    static Future<Image> toImage(RenderObject renderObject, Rect renderBounds, bool debugPaint, double pixelRatio);

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

    virtual String toId(Object object, String groupName);

    virtual bool isWidgetTreeReady(String groupName);

    virtual Object toObject(String id, String groupName);

    virtual Object toObjectForSourceLocation(String id, String groupName);

    virtual void disposeId(String id, String groupName);

    virtual void setPubRootDirectories(List<String> pubRootDirectories);

    virtual void resetPubRootDirectories();

    virtual void addPubRootDirectories(List<String> pubRootDirectories);

    virtual void removePubRootDirectories(List<String> pubRootDirectories);

    virtual bool setSelectionById(String id, String groupName);

    virtual bool setSelection(Object object, String groupName);

    virtual String devToolsInspectorUri(String inspectorRef);

    virtual String getParentChain(String id, String groupName);

    virtual String getProperties(String diagnosticsNodeId, String groupName);

    virtual String getChildren(String diagnosticsNodeId, String groupName);

    virtual String getChildrenSummaryTree(String diagnosticsNodeId, String groupName);

    virtual String getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName);

    virtual String getRootWidget(String groupName);

    virtual String getRootWidgetSummaryTree(String groupName);

    virtual String getRootRenderObject(String groupName);

    virtual String getDetailsSubtree(String id, String groupName, int subtreeDepth);

    virtual String getSelectedRenderObject(String previousSelectionId, String groupName);

    virtual String getSelectedWidget(String previousSelectionId, String groupName);

    virtual Future<Image> screenshot(Object object, bool debugPaint, double height, double margin, double maxPixelRatio, double width);

    virtual String getSelectedSummaryWidget(String previousSelectionId, String groupName);

    virtual bool isWidgetCreationTracked();

    virtual void postEvent(String eventKind, Map<Object, Object> eventData);

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


    virtual void _registerSignalServiceExtension(std::function<FutureOr<Object>()> callback, String name);

    virtual void _registerObjectGroupServiceExtension(std::function<FutureOr<Object>(String objectGroup)> callback, String name);

    virtual void _registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter);

    virtual void _postExtensionStateChangedEvent(String name, Object value);

    virtual void _registerServiceExtensionWithArg(std::function<FutureOr<Object>(String objectId, String objectGroup)> callback, String name);

    virtual void _registerServiceExtensionVarArgs(std::function<FutureOr<Object>(List<String> args)> callback, String name);

    virtual void _reportStructuredError(FlutterErrorDetails details);

    virtual void _resetErrorCount();

    virtual void _clearStats();

    virtual void _decrementReferenceCount(_InspectorReferenceData reference);

    virtual String _devToolsInspectorUriForElement(Element element);

    virtual List<Object> _getParentChain(String id, String groupName);

    virtual Map<String, Object> _pathNodeToJson(_DiagnosticsPathNode pathNode, InspectorSerializationDelegate delegate);

    virtual List<Element> _getRawElementParentChain(Element element, int numLocalParents);

    virtual List<_DiagnosticsPathNode> _getElementParentChain(Element element, String groupName, int numLocalParents);

    virtual List<_DiagnosticsPathNode> _getRenderObjectParentChain(RenderObject renderObject, String groupName);

    virtual Map<String, Object> _nodeToJson(DiagnosticsNode node, InspectorSerializationDelegate delegate);

    virtual bool _isValueCreatedByLocalProject(Object value);

    virtual bool _isLocalCreationLocationImpl(String locationUri);

    virtual bool _isLocalCreationLocation(String locationUri);

    virtual String _safeJsonEncode(Object object);

    virtual List<DiagnosticsNode> _truncateNodes(Iterable<DiagnosticsNode> nodes, int maxDescendentsTruncatableNode);

    virtual List<Map<String, Object>> _nodesToJson(List<DiagnosticsNode> nodes, InspectorSerializationDelegate delegate, DiagnosticsNode parent);

    virtual List<Object> _getProperties(String diagnosticsNodeId, String groupName);

    virtual List<Object> _getChildren(String diagnosticsNodeId, String groupName);

    virtual List<Object> _getChildrenSummaryTree(String diagnosticsNodeId, String groupName);

    virtual List<Object> _getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName);

    virtual bool _shouldShowInSummaryTree(DiagnosticsNode node);

    virtual List<DiagnosticsNode> _getChildrenFiltered(DiagnosticsNode node, InspectorSerializationDelegate delegate);

    virtual List<DiagnosticsNode> _filterChildren(List<DiagnosticsNode> nodes, InspectorSerializationDelegate delegate);

    virtual Map<String, Object> _getRootWidget(String groupName);

    virtual Map<String, Object> _getRootWidgetSummaryTree(String groupName);

    virtual Map<String, Object> _getRootRenderObject(String groupName);

    virtual Map<String, Object> _getDetailsSubtree(String id, String groupName, int subtreeDepth);

    virtual Map<String, Object> _getSelectedRenderObject(String previousSelectionId, String groupName);

    virtual Map<String, Object> _getSelectedWidget(String previousSelectionId, String groupName);

    virtual Map<String, Object> _getSelectedSummaryWidget(String previousSelectionId, String groupName);

    virtual void _onFrameStart(Duration timeStamp);

    virtual void _onFrameEnd(Duration timeStamp);

    virtual void _postStatsEvent(String eventName, _ElementLocationStatsTracker stats);

    virtual void _onRebuildWidget(Element element, bool builtOnce);

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

    virtual Map<String, Object> exportToJson(Duration startTime);

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


     WidgetInspectorCls(Widget child, Key key, InspectorSelectButtonBuilder selectButtonBuilder);

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

    GlobalKey<any> _ignorePointerKey;

    static double _edgeHitMargin;

    InspectorSelectionChangedCallback _selectionChangedCallback;


     _WidgetInspectorStateCls();

    virtual bool _hitTestHelper(List<RenderObject> hits, List<RenderObject> edgeHits, Offset position, RenderObject object, Matrix4 transform);

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

     _TransformedRectCls(RenderObject object, RenderObject ancestor);

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

    template<typename S>
 virtual bool findAnnotations(AnnotationResult<S> result, Offset localPosition, bool onlyFirst);

private:
    _InspectorOverlayRenderState _lastState;

    Picture _picture;

    TextPainter _textPainter;

    double _textPainterMaxWidth;


     _InspectorOverlayLayerCls(Rect overlayRect, RenderObject rootRenderObject, InspectorSelection selection);

    virtual Picture _buildPicture(_InspectorOverlayRenderState state);

    virtual void _paintDescription(Canvas canvas, String message, TextDirection textDirection, Offset target, double verticalOffset, Size size, Rect targetRect);

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

Iterable<DiagnosticsNode> _parseDiagnosticsNode(DiagnosticsNode node, ErrorSummary errorSummary);

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

    std::function<Map<String, Object>(DiagnosticsNode , InspectorSerializationDelegate )> addAdditionalPropertiesCallback;


     InspectorSerializationDelegateCls(std::function<Map<String, Object>(DiagnosticsNode , InspectorSerializationDelegate )> addAdditionalPropertiesCallback, bool expandPropertyValues, String groupName, bool includeProperties, int maxDescendentsTruncatableNode, WidgetInspectorService service, int subtreeDepth, bool summaryTree);
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