#ifndef WIDGET_INSPECTOR_H
#define WIDGET_INSPECTOR_H
#include <memory>

#include <async/async.hpp>
#include <collection/collection.hpp>
#include <convert/convert.hpp>
#include <developer/developer.hpp>
#include <math/math.hpp>
#include <ui/ui.hpp>
#include <flutter/foundation.hpp>
#include <flutter/rendering.hpp>
#include <flutter/scheduler.hpp>
#include "app.hpp"
#include "basic.hpp"
#include "binding.hpp"
#include "debug.hpp"
#include "framework.hpp"
#include "gesture_detector.hpp"



class _ProxyLayer : Layer {
public:

    void addToScene(SceneBuilder builder);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    Layer _layer;


     _ProxyLayer(Layer _layer);

};

class _MulticastCanvas {
public:

    void clipPath(bool doAntiAlias, Path path);

    void clipRRect(bool doAntiAlias, RRect rrect);

    void clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect);

    void drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter);

    void drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms);

    void drawCircle(Offset c, Paint paint, double radius);

    void drawColor(BlendMode blendMode, Color color);

    void drawDRRect(RRect inner, RRect outer, Paint paint);

    void drawImage(Image image, Offset p, Paint paint);

    void drawImageNine(Rect center, Rect dst, Image image, Paint paint);

    void drawImageRect(Rect dst, Image image, Paint paint, Rect src);

    void drawLine(Offset p1, Offset p2, Paint paint);

    void drawOval(Paint paint, Rect rect);

    void drawPaint(Paint paint);

    void drawParagraph(Offset offset, Paragraph paragraph);

    void drawPath(Paint paint, Path path);

    void drawPicture(Picture picture);

    void drawPoints(Paint paint, PointMode pointMode, List<Offset> points);

    void drawRRect(Paint paint, RRect rrect);

    void drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms);

    void drawRawPoints(Paint paint, PointMode pointMode, Float32List points);

    void drawRect(Paint paint, Rect rect);

    void drawShadow(Color color, double elevation, Path path, bool transparentOccluder);

    void drawVertices(BlendMode blendMode, Paint paint, Vertices vertices);

    int getSaveCount();

    void restore();

    void rotate(double radians);

    void save();

    void saveLayer(Rect bounds, Paint paint);

    void scale(double sx, double sy);

    void skew(double sx, double sy);

    void transform(Float64List matrix4);

    void translate(double dx, double dy);

    dynamic noSuchMethod(Invocation invocation);

private:
    Canvas _main;

    Canvas _screenshot;


     _MulticastCanvas(Canvas main, Canvas screenshot);

};
Rect _calculateSubtreeBoundsHelper(RenderObject object, Matrix4 transform);

Rect _calculateSubtreeBounds(RenderObject object);


class _ScreenshotContainerLayer : OffsetLayer {
public:

    void addToScene(SceneBuilder builder);

private:

};

class _ScreenshotData {
public:
    RenderObject target;

    OffsetLayer containerLayer;

    bool foundTarget;

    bool includeInScreenshot;

    bool includeInRegularContext;


    Offset screenshotOffset();

    void  screenshotOffset(Offset offset);

private:

     _ScreenshotData(RenderObject target);

};

class _ScreenshotPaintingContext : PaintingContext {
public:

    Canvas canvas();

    void stopRecordingIfNeeded();

    void appendLayer(Layer layer);

    PaintingContext createChildContext(Rect bounds, ContainerLayer childLayer);

    void paintChild(RenderObject child, Offset offset);

    static Future<Image> toImage(bool debugPaint, double pixelRatio, Rect renderBounds, RenderObject renderObject);

private:
    _ScreenshotData _data;

    PictureLayer _screenshotCurrentLayer;

    PictureRecorder _screenshotRecorder;

    Canvas _screenshotCanvas;

    _MulticastCanvas _multicastCanvas;


     _ScreenshotPaintingContext(ContainerLayer containerLayer, Rect estimatedBounds, _ScreenshotData screenshotData);

    bool _isScreenshotRecording();

    void _startRecordingScreenshot();

    void _stopRecordingScreenshotIfNeeded();

};

class _DiagnosticsPathNode {
public:
    DiagnosticsNode node;

    List<DiagnosticsNode> children;

    int childIndex;


private:

     _DiagnosticsPathNode(int childIndex, List<DiagnosticsNode> children, DiagnosticsNode node);

};
List<_DiagnosticsPathNode> _followDiagnosticableChain(List<Diagnosticable> chain, String name, DiagnosticsTreeStyle style);


class _InspectorReferenceData {
public:
    Object object;

    int count;


private:

     _InspectorReferenceData(Object object);

};

class _WidgetInspectorService {
public:

private:

};

class WidgetInspectorService {
public:
    InspectorSelection selection;

    InspectorSelectionChangedCallback selectionChangedCallback;


    static WidgetInspectorService instance();

    static void  instance(WidgetInspectorService instance);

    List<String> pubRootDirectories();

    void registerServiceExtension(ServiceExtensionCallback callback, String name);

    Future<void> forceRebuild();

    bool isStructuredErrorsEnabled();

    void initServiceExtensions(RegisterServiceExtensionCallback registerServiceExtensionCallback);

    void disposeAllGroups();

    void resetAllState();

    void disposeGroup(String name);

    String toId(String groupName, Object object);

    bool isWidgetTreeReady(String groupName);

    Object toObject(String groupName, String id);

    Object toObjectForSourceLocation(String groupName, String id);

    void disposeId(String groupName, String id);

    void setPubRootDirectories(List<String> pubRootDirectories);

    void resetPubRootDirectories();

    void addPubRootDirectories(List<String> pubRootDirectories);

    void removePubRootDirectories(List<String> pubRootDirectories);

    bool setSelectionById(String groupName, String id);

    bool setSelection(String groupName, Object object);

    String devToolsInspectorUri(String inspectorRef);

    String getParentChain(String groupName, String id);

    String getProperties(String diagnosticsNodeId, String groupName);

    String getChildren(String diagnosticsNodeId, String groupName);

    String getChildrenSummaryTree(String diagnosticsNodeId, String groupName);

    String getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName);

    String getRootWidget(String groupName);

    String getRootWidgetSummaryTree(String groupName);

    String getRootRenderObject(String groupName);

    String getDetailsSubtree(String groupName, String id, int subtreeDepth);

    String getSelectedRenderObject(String groupName, String previousSelectionId);

    String getSelectedWidget(String groupName, String previousSelectionId);

    Future<Image> screenshot(bool debugPaint, double height, double margin, double maxPixelRatio, Object object, double width);

    String getSelectedSummaryWidget(String groupName, String previousSelectionId);

    bool isWidgetCreationTracked();

    void postEvent(Map<Object, Object> eventData, String eventKind);

    void performReassemble();

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

    static const String _consoleObjectGroup;

    int _errorsSinceReload;

    bool _widgetCreationTracked;

    Duration _frameStart;

    _ElementLocationStatsTracker _rebuildStats;

    _ElementLocationStatsTracker _repaintStats;


    void _registerSignalServiceExtension(FunctionType callback, String name);

    void _registerObjectGroupServiceExtension(FunctionType callback, String name);

    void _registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter);

    void _postExtensionStateChangedEvent(String name, Object value);

    void _registerServiceExtensionWithArg(FunctionType callback, String name);

    void _registerServiceExtensionVarArgs(FunctionType callback, String name);

    void _reportStructuredError(FlutterErrorDetails details);

    void _resetErrorCount();

    void _clearStats();

    void _decrementReferenceCount(_InspectorReferenceData reference);

    String _devToolsInspectorUriForElement(Element element);

    List<Object> _getParentChain(String groupName, String id);

    Map<String, Object> _pathNodeToJson(InspectorSerializationDelegate delegate, _DiagnosticsPathNode pathNode);

    List<Element> _getRawElementParentChain(Element element, int numLocalParents);

    List<_DiagnosticsPathNode> _getElementParentChain(Element element, String groupName, int numLocalParents);

    List<_DiagnosticsPathNode> _getRenderObjectParentChain(String groupName, RenderObject renderObject);

    Map<String, Object> _nodeToJson(InspectorSerializationDelegate delegate, DiagnosticsNode node);

    bool _isValueCreatedByLocalProject(Object value);

    bool _isLocalCreationLocationImpl(String locationUri);

    bool _isLocalCreationLocation(String locationUri);

    String _safeJsonEncode(Object object);

    List<DiagnosticsNode> _truncateNodes(int maxDescendentsTruncatableNode, Iterable<DiagnosticsNode> nodes);

    List<Map<String, Object>> _nodesToJson(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent);

    List<Object> _getProperties(String diagnosticsNodeId, String groupName);

    List<Object> _getChildren(String diagnosticsNodeId, String groupName);

    List<Object> _getChildrenSummaryTree(String diagnosticsNodeId, String groupName);

    List<Object> _getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName);

    bool _shouldShowInSummaryTree(DiagnosticsNode node);

    List<DiagnosticsNode> _getChildrenFiltered(InspectorSerializationDelegate delegate, DiagnosticsNode node);

    List<DiagnosticsNode> _filterChildren(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes);

    Map<String, Object> _getRootWidget(String groupName);

    Map<String, Object> _getRootWidgetSummaryTree(String groupName);

    Map<String, Object> _getRootRenderObject(String groupName);

    Map<String, Object> _getDetailsSubtree(String groupName, String id, int subtreeDepth);

    Map<String, Object> _getSelectedRenderObject(String groupName, String previousSelectionId);

    Map<String, Object> _getSelectedWidget(String groupName, String previousSelectionId);

    Map<String, Object> _getSelectedSummaryWidget(String groupName, String previousSelectionId);

    void _onFrameStart(Duration timeStamp);

    void _onFrameEnd(Duration timeStamp);

    void _postStatsEvent(String eventName, _ElementLocationStatsTracker stats);

    void _onRebuildWidget(bool builtOnce, Element element);

    void _onPaint(RenderObject renderObject);

};

class _LocationCount {
public:
    int id;

    bool local;

    _Location location;


    int count();

    void reset();

    void increment();

private:
    int _count;


     _LocationCount(int id, bool local, _Location location);

};

class _ElementLocationStatsTracker {
public:
    List<_LocationCount> active;

    List<_LocationCount> newLocations;


    void add(Element element);

    void resetCounts();

    Map<String, dynamic> exportToJson(Duration startTime);

private:
    List<_LocationCount> _stats;


};

class _WidgetForTypeTests : Widget {
public:

    Element createElement();

private:

     _WidgetForTypeTests();

};

class WidgetInspector : StatefulWidget {
public:
    Widget child;

    InspectorSelectButtonBuilder selectButtonBuilder;


     WidgetInspector(Widget child, Unknown, InspectorSelectButtonBuilder selectButtonBuilder);

    State<WidgetInspector> createState();

private:

};

class _WidgetInspectorState : State<WidgetInspector> {
public:
    InspectorSelection selection;

    bool isSelectMode;


    void initState();

    void dispose();

    List<RenderObject> hitTest(Offset position, RenderObject root);

    Widget build(BuildContext context);

private:
    Offset _lastPointerLocation;

    GlobalKey _ignorePointerKey;

    static const double _edgeHitMargin;

    InspectorSelectionChangedCallback _selectionChangedCallback;


     _WidgetInspectorState();

    bool _hitTestHelper(List<RenderObject> edgeHits, List<RenderObject> hits, RenderObject object, Offset position, Matrix4 transform);

    void _inspectAt(Offset position);

    void _handlePanDown(DragDownDetails event);

    void _handlePanUpdate(DragUpdateDetails event);

    void _handlePanEnd(DragEndDetails details);

    void _handleTap();

    void _handleEnableSelect();

};

class InspectorSelection {
public:

    List<RenderObject> candidates();

    void  candidates(List<RenderObject> value);

    int index();

    void  index(int value);

    void clear();

    RenderObject current();

    void  current(RenderObject value);

    Element currentElement();

    void  currentElement(Element element);

    bool active();

private:
    List<RenderObject> _candidates;

    int _index;

    RenderObject _current;

    Element _currentElement;


    void _computeCurrent();

};

class _InspectorOverlay : LeafRenderObjectWidget {
public:
    InspectorSelection selection;


    _RenderInspectorOverlay createRenderObject(BuildContext context);

    void updateRenderObject(BuildContext context, _RenderInspectorOverlay renderObject);

private:

     _InspectorOverlay(InspectorSelection selection);

};

class _RenderInspectorOverlay : RenderBox {
public:

    InspectorSelection selection();

    void  selection(InspectorSelection value);

    bool sizedByParent();

    bool alwaysNeedsCompositing();

    Size computeDryLayout(BoxConstraints constraints);

    void paint(PaintingContext context, Offset offset);

private:
    InspectorSelection _selection;


     _RenderInspectorOverlay(InspectorSelection selection);

};

class _TransformedRect {
public:
    Rect rect;

    Matrix4 transform;


    bool ==(Object other);

    int hashCode();

private:

     _TransformedRect(RenderObject ancestor, RenderObject object);

};

class _InspectorOverlayRenderState {
public:
    Rect overlayRect;

    _TransformedRect selected;

    List<_TransformedRect> candidates;

    String tooltip;

    TextDirection textDirection;


    bool ==(Object other);

    int hashCode();

private:

     _InspectorOverlayRenderState(List<_TransformedRect> candidates, Rect overlayRect, _TransformedRect selected, TextDirection textDirection, String tooltip);

};
const int _kMaxTooltipLines;

const Color _kTooltipBackgroundColor;

const Color _kHighlightedRenderObjectFillColor;

const Color _kHighlightedRenderObjectBorderColor;


class _InspectorOverlayLayer : Layer {
public:
    InspectorSelection selection;

    Rect overlayRect;

    RenderObject rootRenderObject;


    void addToScene(SceneBuilder builder);

    bool findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result);

private:
    _InspectorOverlayRenderState _lastState;

    Picture _picture;

    TextPainter _textPainter;

    double _textPainterMaxWidth;


     _InspectorOverlayLayer(Rect overlayRect, RenderObject rootRenderObject, InspectorSelection selection);

    Picture _buildPicture(_InspectorOverlayRenderState state);

    void _paintDescription(Canvas canvas, String message, Size size, Offset target, Rect targetRect, TextDirection textDirection, double verticalOffset);

    bool _isInInspectorRenderObjectTree(RenderObject child);

};
const double _kScreenEdgeMargin;

const double _kTooltipPadding;

const double _kInspectButtonMargin;

const double _kOffScreenMargin;

const TextStyle _messageStyle;


class _HasCreationLocation {
public:

private:

    _Location _location();

};

class _Location {
public:
    String file;

    int line;

    int column;

    String name;


    Map<String, Object> toJsonMap();

    String toString();

private:

     _Location(int column, String file, int line, String name);

};
bool _isDebugCreator(DiagnosticsNode node);

Iterable<DiagnosticsNode> debugTransformDebugCreator(Iterable<DiagnosticsNode> properties);

Iterable<DiagnosticsNode> _parseDiagnosticsNode(ErrorSummary errorSummary, DiagnosticsNode node);

Iterable<DiagnosticsNode> _describeRelevantUserCode(Element element, ErrorSummary errorSummary);


class DevToolsDeepLinkProperty : DiagnosticsProperty<String> {
public:

     DevToolsDeepLinkProperty(String description, String url);

private:

};
bool debugIsLocalCreationLocation(Object object);

bool debugIsWidgetLocalCreation(Widget widget);

String _describeCreationLocation(Object object);

_Location _getObjectCreationLocation(Object object);

_Location _getCreationLocation(Object object);

Map<_Location, int> _locationToId;

List<_Location> _locations;

int _toLocationId(_Location location);


class InspectorSerializationDelegate {
public:
    WidgetInspectorService service;

    String groupName;

    bool summaryTree;

    int maxDescendentsTruncatableNode;

    bool includeProperties;

    int subtreeDepth;

    bool expandPropertyValues;

    FunctionType addAdditionalPropertiesCallback;


     InspectorSerializationDelegate(FunctionType addAdditionalPropertiesCallback, bool expandPropertyValues, String groupName, bool includeProperties, int maxDescendentsTruncatableNode, WidgetInspectorService service, int subtreeDepth, bool summaryTree);

    Map<String, Object> additionalNodeProperties(DiagnosticsNode node);

    DiagnosticsSerializationDelegate delegateForNode(DiagnosticsNode node);

    List<DiagnosticsNode> filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    List<DiagnosticsNode> filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    List<DiagnosticsNode> truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner);

    DiagnosticsSerializationDelegate copyWith(bool includeProperties, int subtreeDepth);

private:
    List<DiagnosticsNode> _nodesCreatedByLocalProject;


    bool _interactive();

};

#endif