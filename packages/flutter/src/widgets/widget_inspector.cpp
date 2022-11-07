#include "widget_inspector.hpp"
void _ProxyLayer::addToScene(SceneBuilder builder) {
    _layer.addToScene(builder);
}

bool _ProxyLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return _layer.findAnnotations(result, localPositiononlyFirst);
}

void _MulticastCanvas::clipPath(bool doAntiAlias, Path path) {
    _main.clipPath(pathdoAntiAlias);
    _screenshot.clipPath(pathdoAntiAlias);
}

void _MulticastCanvas::clipRRect(bool doAntiAlias, RRect rrect) {
    _main.clipRRect(rrectdoAntiAlias);
    _screenshot.clipRRect(rrectdoAntiAlias);
}

void _MulticastCanvas::clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect) {
    _main.clipRect(rectclipOp, doAntiAlias);
    _screenshot.clipRect(rectclipOp, doAntiAlias);
}

void _MulticastCanvas::drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter) {
    _main.drawArc(rect, startAngle, sweepAngle, useCenter, paint);
    _screenshot.drawArc(rect, startAngle, sweepAngle, useCenter, paint);
}

void _MulticastCanvas::drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms) {
    _main.drawAtlas(atlas, transforms, rects, colors, blendMode, cullRect, paint);
    _screenshot.drawAtlas(atlas, transforms, rects, colors, blendMode, cullRect, paint);
}

void _MulticastCanvas::drawCircle(Offset c, Paint paint, double radius) {
    _main.drawCircle(c, radius, paint);
    _screenshot.drawCircle(c, radius, paint);
}

void _MulticastCanvas::drawColor(BlendMode blendMode, Color color) {
    _main.drawColor(color, blendMode);
    _screenshot.drawColor(color, blendMode);
}

void _MulticastCanvas::drawDRRect(RRect inner, RRect outer, Paint paint) {
    _main.drawDRRect(outer, inner, paint);
    _screenshot.drawDRRect(outer, inner, paint);
}

void _MulticastCanvas::drawImage(Image image, Offset p, Paint paint) {
    _main.drawImage(image, p, paint);
    _screenshot.drawImage(image, p, paint);
}

void _MulticastCanvas::drawImageNine(Rect center, Rect dst, Image image, Paint paint) {
    _main.drawImageNine(image, center, dst, paint);
    _screenshot.drawImageNine(image, center, dst, paint);
}

void _MulticastCanvas::drawImageRect(Rect dst, Image image, Paint paint, Rect src) {
    _main.drawImageRect(image, src, dst, paint);
    _screenshot.drawImageRect(image, src, dst, paint);
}

void _MulticastCanvas::drawLine(Offset p1, Offset p2, Paint paint) {
    _main.drawLine(p1, p2, paint);
    _screenshot.drawLine(p1, p2, paint);
}

void _MulticastCanvas::drawOval(Paint paint, Rect rect) {
    _main.drawOval(rect, paint);
    _screenshot.drawOval(rect, paint);
}

void _MulticastCanvas::drawPaint(Paint paint) {
    _main.drawPaint(paint);
    _screenshot.drawPaint(paint);
}

void _MulticastCanvas::drawParagraph(Offset offset, Paragraph paragraph) {
    _main.drawParagraph(paragraph, offset);
    _screenshot.drawParagraph(paragraph, offset);
}

void _MulticastCanvas::drawPath(Paint paint, Path path) {
    _main.drawPath(path, paint);
    _screenshot.drawPath(path, paint);
}

void _MulticastCanvas::drawPicture(Picture picture) {
    _main.drawPicture(picture);
    _screenshot.drawPicture(picture);
}

void _MulticastCanvas::drawPoints(Paint paint, PointMode pointMode, List<Offset> points) {
    _main.drawPoints(pointMode, points, paint);
    _screenshot.drawPoints(pointMode, points, paint);
}

void _MulticastCanvas::drawRRect(Paint paint, RRect rrect) {
    _main.drawRRect(rrect, paint);
    _screenshot.drawRRect(rrect, paint);
}

void _MulticastCanvas::drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms) {
    _main.drawRawAtlas(atlas, rstTransforms, rects, colors, blendMode, cullRect, paint);
    _screenshot.drawRawAtlas(atlas, rstTransforms, rects, colors, blendMode, cullRect, paint);
}

void _MulticastCanvas::drawRawPoints(Paint paint, PointMode pointMode, Float32List points) {
    _main.drawRawPoints(pointMode, points, paint);
    _screenshot.drawRawPoints(pointMode, points, paint);
}

void _MulticastCanvas::drawRect(Paint paint, Rect rect) {
    _main.drawRect(rect, paint);
    _screenshot.drawRect(rect, paint);
}

void _MulticastCanvas::drawShadow(Color color, double elevation, Path path, bool transparentOccluder) {
    _main.drawShadow(path, color, elevation, transparentOccluder);
    _screenshot.drawShadow(path, color, elevation, transparentOccluder);
}

void _MulticastCanvas::drawVertices(BlendMode blendMode, Paint paint, Vertices vertices) {
    _main.drawVertices(vertices, blendMode, paint);
    _screenshot.drawVertices(vertices, blendMode, paint);
}

int _MulticastCanvas::getSaveCount() {
    return _main.getSaveCount();
}

void _MulticastCanvas::restore() {
    _main.restore();
    _screenshot.restore();
}

void _MulticastCanvas::rotate(double radians) {
    _main.rotate(radians);
    _screenshot.rotate(radians);
}

void _MulticastCanvas::save() {
    _main.save();
    _screenshot.save();
}

void _MulticastCanvas::saveLayer(Rect bounds, Paint paint) {
    _main.saveLayer(bounds, paint);
    _screenshot.saveLayer(bounds, paint);
}

void _MulticastCanvas::scale(double sx, double sy) {
    _main.scale(sx, sy);
    _screenshot.scale(sx, sy);
}

void _MulticastCanvas::skew(double sx, double sy) {
    _main.skew(sx, sy);
    _screenshot.skew(sx, sy);
}

void _MulticastCanvas::transform(Float64List matrix4) {
    _main.transform(matrix4);
    _screenshot.transform(matrix4);
}

void _MulticastCanvas::translate(double dx, double dy) {
    _main.translate(dx, dy);
    _screenshot.translate(dx, dy);
}

dynamic _MulticastCanvas::noSuchMethod(Invocation invocation) {
    super.noSuchMethod(invocation);
}

_MulticastCanvas::_MulticastCanvas(Canvas main, Canvas screenshot) {
    {
        assert(main != nullptr);
        assert(screenshot != nullptr);
        _main = main;
        _screenshot = screenshot;
    }
}

Rect _calculateSubtreeBoundsHelper(RenderObject object, Matrix4 transform) {
    Rect bounds = MatrixUtils.transformRect(transform, object.semanticBounds);
    object.visitChildren();
    return bounds;
}

Rect _calculateSubtreeBounds(RenderObject object) {
    return _calculateSubtreeBoundsHelper(object, Matrix4.identity());
}

void _ScreenshotContainerLayer::addToScene(SceneBuilder builder) {
    addChildrenToScene(builder);
}

Offset _ScreenshotData::screenshotOffset() {
    assert(foundTarget);
    return containerLayer.offset;
}

void _ScreenshotData::screenshotOffset(Offset offset) {
    containerLayer.offset = offset;
}

_ScreenshotData::_ScreenshotData(RenderObject target) {
    {
        assert(target != nullptr);
        containerLayer = _ScreenshotContainerLayer();
    }
}

Canvas _ScreenshotPaintingContext::canvas() {
    if (_data.includeInScreenshot) {
        if (_screenshotCanvas == nullptr) {
            _startRecordingScreenshot();
        }
        assert(_screenshotCanvas != nullptr);
        return _data.includeInRegularContext? _multicastCanvas! : _screenshotCanvas!;
    } else {
        assert(_data.includeInRegularContext);
        return super.canvas;
    }
}

void _ScreenshotPaintingContext::stopRecordingIfNeeded() {
    super.stopRecordingIfNeeded();
    _stopRecordingScreenshotIfNeeded();
}

void _ScreenshotPaintingContext::appendLayer(Layer layer) {
    if (_data.includeInRegularContext) {
        super.appendLayer(layer);
        if (_data.includeInScreenshot) {
            assert(!_isScreenshotRecording);
            _data.containerLayer.append(_ProxyLayer(layer));
        }
    } else {
        assert(!_isScreenshotRecording);
        assert(_data.includeInScreenshot);
        layer.remove();
        _data.containerLayer.append(layer);
        return;
    }
}

PaintingContext _ScreenshotPaintingContext::createChildContext(Rect bounds, ContainerLayer childLayer) {
    if (_data.foundTarget) {
        return super.createChildContext(childLayer, bounds);
    } else {
        return _ScreenshotPaintingContext(childLayer, bounds, _data);
    }
}

void _ScreenshotPaintingContext::paintChild(RenderObject child, Offset offset) {
    bool isScreenshotTarget = identical(child, _data.target);
    if (isScreenshotTarget) {
        assert(!_data.includeInScreenshot);
        assert(!_data.foundTarget);
        _data.foundTarget = true;
        _data.screenshotOffset = offset;
        _data.includeInScreenshot = true;
    }
    super.paintChild(child, offset);
    if (isScreenshotTarget) {
        _stopRecordingScreenshotIfNeeded();
        _data.includeInScreenshot = false;
    }
}

Future<Image> _ScreenshotPaintingContext::toImage(bool debugPaint, double pixelRatio, Rect renderBounds, RenderObject renderObject) {
    RenderObject repaintBoundary = renderObject;
    while (repaintBoundary != nullptr && !repaintBoundary.isRepaintBoundary) {
        repaintBoundary = (;
    }
    assert(repaintBoundary != nullptr);
    _ScreenshotData data = _ScreenshotData(renderObject);
    _ScreenshotPaintingContext context = _ScreenshotPaintingContext(repaintBoundary.debugLayer!, repaintBoundary.paintBounds, data);
    if (identical(renderObject, repaintBoundary)) {
        data.containerLayer.append(_ProxyLayer(repaintBoundary.debugLayer!));
        data.foundTarget = true;
        OffsetLayer offsetLayer = (;
        data.screenshotOffset = offsetLayer.offset;
    } else {
        PaintingContext.debugInstrumentRepaintCompositedChild(repaintBoundarycontext);
    }
    if (debugPaint && !debugPaintSizeEnabled) {
        data.includeInRegularContext = false;
        context.stopRecordingIfNeeded();
        assert(data.foundTarget);
        data.includeInScreenshot = true;
        debugPaintSizeEnabled = true;
        ;
    }
    repaintBoundary.debugLayer!.buildScene(ui.SceneBuilder());
    return data.containerLayer.toImage(renderBoundspixelRatio);
}

_ScreenshotPaintingContext::_ScreenshotPaintingContext(ContainerLayer containerLayer, Rect estimatedBounds, _ScreenshotData screenshotData) {
    {
        _data = screenshotData;
        super(containerLayer, estimatedBounds);
    }
}

bool _ScreenshotPaintingContext::_isScreenshotRecording() {
    bool hasScreenshotCanvas = _screenshotCanvas != nullptr;
    assert(());
    return hasScreenshotCanvas;
}

void _ScreenshotPaintingContext::_startRecordingScreenshot() {
    assert(_data.includeInScreenshot);
    assert(!_isScreenshotRecording);
    _screenshotCurrentLayer = PictureLayer(estimatedBounds);
    _screenshotRecorder = ui.PictureRecorder();
    _screenshotCanvas = Canvas(_screenshotRecorder!);
    _data.containerLayer.append(_screenshotCurrentLayer!);
    if (_data.includeInRegularContext) {
        _multicastCanvas = _MulticastCanvas(super.canvas, _screenshotCanvas!);
    } else {
        _multicastCanvas = nullptr;
    }
}

void _ScreenshotPaintingContext::_stopRecordingScreenshotIfNeeded() {
    if (!_isScreenshotRecording) {
        return;
    }
    _screenshotCurrentLayer!.picture = _screenshotRecorder!.endRecording();
    _screenshotCurrentLayer = nullptr;
    _screenshotRecorder = nullptr;
    _multicastCanvas = nullptr;
    _screenshotCanvas = nullptr;
}

_DiagnosticsPathNode::_DiagnosticsPathNode(int childIndex, List<DiagnosticsNode> children, DiagnosticsNode node) {
    {
        assert(node != nullptr);
        assert(children != nullptr);
    }
}

List<_DiagnosticsPathNode> _followDiagnosticableChain(List<Diagnosticable> chain, String name, DiagnosticsTreeStyle style) {
    List<_DiagnosticsPathNode> path = ;
    if (chain.isEmpty) {
        return path;
    }
    DiagnosticsNode diagnostic = chain.first.toDiagnosticsNode(name, style);
    for (;  < chain.length; i = 1) {
        Diagnosticable target = chain[i];
        bool foundMatch = false;
        List<DiagnosticsNode> children = diagnostic.getChildren();
        for (;  < children.length; j = 1) {
            DiagnosticsNode child = children[j];
            if (child.value == target) {
                foundMatch = true;
                path.add(_DiagnosticsPathNode(diagnostic, children, j));
                diagnostic = child;
                                break;
            }
        }
        assert(foundMatch);
    }
    path.add(_DiagnosticsPathNode(diagnostic, diagnostic.getChildren()));
    return path;
}

WidgetInspectorService WidgetInspectorService::instance() {
    return _instance;
}

void WidgetInspectorService::instance(WidgetInspectorService instance) {
    _instance = instance;
}

List<String> WidgetInspectorService::pubRootDirectories() {
    return _pubRootDirectories == nullptr? const  : <String>from(_pubRootDirectories!);
}

void WidgetInspectorService::registerServiceExtension(ServiceExtensionCallback callback, String name) {
    _registerServiceExtensionCallback("inspector.$name", callback);
}

Future<void> WidgetInspectorService::forceRebuild() {
    WidgetsBinding binding = WidgetsBinding.instance;
    if (binding.renderViewElement != nullptr) {
        binding.buildOwner!.reassemble(binding.renderViewElement!, nullptr);
        return binding.endOfFrame;
    }
    return <void>value();
}

bool WidgetInspectorService::isStructuredErrorsEnabled() {
    bool enabled = false;
    assert(());
    return enabled;
}

void WidgetInspectorService::initServiceExtensions(RegisterServiceExtensionCallback registerServiceExtensionCallback) {
    FlutterExceptionHandler defaultExceptionHandler = FlutterError.presentError;
    if (isStructuredErrorsEnabled()) {
        FlutterError.presentError = _reportStructuredError;
    }
    _registerServiceExtensionCallback = registerServiceExtensionCallback;
    assert(!_debugServiceExtensionsRegistered);
    assert(());
    SchedulerBinding.instance.addPersistentFrameCallback(_onFrameStart);
    _registerBoolServiceExtension("structuredErrors", , );
    _registerBoolServiceExtension("show", , );
    if (isWidgetCreationTracked()) {
        _registerBoolServiceExtension("trackRebuildDirtyWidgets", , );
        _registerBoolServiceExtension("trackRepaintWidgets", , );
    }
    _registerSignalServiceExtension("disposeAllGroups", );
    _registerObjectGroupServiceExtension("disposeGroup", );
    _registerSignalServiceExtension("isWidgetTreeReady", isWidgetTreeReady);
    _registerServiceExtensionWithArg("disposeId", );
    _registerServiceExtensionVarArgs("setPubRootDirectories", );
    _registerServiceExtensionVarArgs("addPubRootDirectories", );
    _registerServiceExtensionVarArgs("removePubRootDirectories", );
    _registerServiceExtensionWithArg("setSelectionById", setSelectionById);
    _registerServiceExtensionWithArg("getParentChain", _getParentChain);
    _registerServiceExtensionWithArg("getProperties", _getProperties);
    _registerServiceExtensionWithArg("getChildren", _getChildren);
    _registerServiceExtensionWithArg("getChildrenSummaryTree", _getChildrenSummaryTree);
    _registerServiceExtensionWithArg("getChildrenDetailsSubtree", _getChildrenDetailsSubtree);
    _registerObjectGroupServiceExtension("getRootWidget", _getRootWidget);
    _registerObjectGroupServiceExtension("getRootRenderObject", _getRootRenderObject);
    _registerObjectGroupServiceExtension("getRootWidgetSummaryTree", _getRootWidgetSummaryTree);
    registerServiceExtension("getDetailsSubtree", );
    _registerServiceExtensionWithArg("getSelectedRenderObject", _getSelectedRenderObject);
    _registerServiceExtensionWithArg("getSelectedWidget", _getSelectedWidget);
    _registerServiceExtensionWithArg("getSelectedSummaryWidget", _getSelectedSummaryWidget);
    _registerSignalServiceExtension("isWidgetCreationTracked", isWidgetCreationTracked);
    registerServiceExtension("screenshot", );
}

void WidgetInspectorService::disposeAllGroups() {
    _groups.clear();
    _idToReferenceData.clear();
    _objectToId.clear();
    _nextId = 0;
}

void WidgetInspectorService::resetAllState() {
    disposeAllGroups();
    selection.clear();
    resetPubRootDirectories();
}

void WidgetInspectorService::disposeGroup(String name) {
    Set<_InspectorReferenceData> references = _groups.remove(name);
    if (references == nullptr) {
        return;
    }
    references.forEach(_decrementReferenceCount);
}

String WidgetInspectorService::toId(String groupName, Object object) {
    if (object == nullptr) {
        return nullptr;
    }
    Set<_InspectorReferenceData> group = _groups.putIfAbsent(groupName, );
    String id = _objectToId[object];
    _InspectorReferenceData referenceData;
    if (id == nullptr) {
        id = "inspector-$_nextId";
        _nextId = 1;
        _objectToId[object] = id;
        referenceData = _InspectorReferenceData(object);
        _idToReferenceData[id] = referenceData;
        group.add(referenceData);
    } else {
        referenceData = _idToReferenceData[id]!;
        if (group.add(referenceData)) {
            referenceData.count = 1;
        }
    }
    return id;
}

bool WidgetInspectorService::isWidgetTreeReady(String groupName) {
    return WidgetsBinding.instance != nullptr && WidgetsBinding.instance.debugDidSendFirstFrameEvent;
}

Object WidgetInspectorService::toObject(String groupName, String id) {
    if (id == nullptr) {
        return nullptr;
    }
    _InspectorReferenceData data = _idToReferenceData[id];
    if (data == nullptr) {
        ;
    }
    return data.object;
}

Object WidgetInspectorService::toObjectForSourceLocation(String groupName, String id) {
    Object object = toObject(id);
    if (object is Element) {
        return object.widget;
    }
    return object;
}

void WidgetInspectorService::disposeId(String groupName, String id) {
    if (id == nullptr) {
        return;
    }
    _InspectorReferenceData referenceData = _idToReferenceData[id];
    if (referenceData == nullptr) {
        ;
    }
    if (_groups[groupName]?.remove(referenceData) != true) {
        ;
    }
    _decrementReferenceCount(referenceData);
}

void WidgetInspectorService::setPubRootDirectories(List<String> pubRootDirectories) {
    addPubRootDirectories(pubRootDirectories);
}

void WidgetInspectorService::resetPubRootDirectories() {
    _pubRootDirectories = ;
    _isLocalCreationCache.clear();
}

void WidgetInspectorService::addPubRootDirectories(List<String> pubRootDirectories) {
    pubRootDirectories = pubRootDirectories.<String>map().toList();
    Set<String> directorySet = <String>from(pubRootDirectories);
    if (_pubRootDirectories != nullptr) {
        directorySet.addAll(_pubRootDirectories!);
    }
    _pubRootDirectories = directorySet.toList();
    _isLocalCreationCache.clear();
}

void WidgetInspectorService::removePubRootDirectories(List<String> pubRootDirectories) {
    if (_pubRootDirectories == nullptr) {
        return;
    }
    pubRootDirectories = pubRootDirectories.<String>map().toList();
    Set<String> directorySet = <String>from(_pubRootDirectories!);
    directorySet.removeAll(pubRootDirectories);
    _pubRootDirectories = directorySet.toList();
    _isLocalCreationCache.clear();
}

bool WidgetInspectorService::setSelectionById(String groupName, String id) {
    return setSelection(toObject(id), groupName);
}

bool WidgetInspectorService::setSelection(String groupName, Object object) {
    if (object is Element || object is RenderObject) {
        if (object is Element) {
            if (object == selection.currentElement) {
                return false;
            }
            selection.currentElement = object;
            developer.inspect(selection.currentElement);
        } else {
            if (object == selection.current) {
                return false;
            }
            selection.current = (;
            developer.inspect(selection.current);
        }
        if (selectionChangedCallback != nullptr) {
            if (SchedulerBinding.instance.schedulerPhase == SchedulerPhase.idle) {
                selectionChangedCallback!();
            } else {
                SchedulerBinding.instance.scheduleTask(selectionChangedCallback!, Priority.touch);
            }
        }
        return true;
    }
    return false;
}

String WidgetInspectorService::devToolsInspectorUri(String inspectorRef) {
    assert(activeDevToolsServerAddress != nullptr);
    assert(connectedVmServiceUri != nullptr);
    Uri uri = Uri.parse(activeDevToolsServerAddress!).replace();
    String devToolsInspectorUri = uri.toString();
    int startQueryParamIndex = devToolsInspectorUri.indexOf("?");
    assert(startQueryParamIndex != -1);
    return "${devToolsInspectorUri.substring(0, startQueryParamIndex)}/#/inspector${devToolsInspectorUri.substring(startQueryParamIndex)}";
}

String WidgetInspectorService::getParentChain(String groupName, String id) {
    return _safeJsonEncode(_getParentChain(id, groupName));
}

String WidgetInspectorService::getProperties(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getProperties(diagnosticsNodeId, groupName));
}

String WidgetInspectorService::getChildren(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getChildren(diagnosticsNodeId, groupName));
}

String WidgetInspectorService::getChildrenSummaryTree(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getChildrenSummaryTree(diagnosticsNodeId, groupName));
}

String WidgetInspectorService::getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getChildrenDetailsSubtree(diagnosticsNodeId, groupName));
}

String WidgetInspectorService::getRootWidget(String groupName) {
    return _safeJsonEncode(_getRootWidget(groupName));
}

String WidgetInspectorService::getRootWidgetSummaryTree(String groupName) {
    return _safeJsonEncode(_getRootWidgetSummaryTree(groupName));
}

String WidgetInspectorService::getRootRenderObject(String groupName) {
    return _safeJsonEncode(_getRootRenderObject(groupName));
}

String WidgetInspectorService::getDetailsSubtree(String groupName, String id, int subtreeDepth) {
    return _safeJsonEncode(_getDetailsSubtree(id, groupName, subtreeDepth));
}

String WidgetInspectorService::getSelectedRenderObject(String groupName, String previousSelectionId) {
    return _safeJsonEncode(_getSelectedRenderObject(previousSelectionId, groupName));
}

String WidgetInspectorService::getSelectedWidget(String groupName, String previousSelectionId) {
    return _safeJsonEncode(_getSelectedWidget(previousSelectionId, groupName));
}

Future<Image> WidgetInspectorService::screenshot(bool debugPaint, double height, double margin, double maxPixelRatio, Object object, double width) {
    if (object is! Element && object is! RenderObject) {
        return nullptr;
    }
    RenderObject renderObject = object is Element? object.renderObject : (();
    if (renderObject == nullptr || !renderObject.attached) {
        return nullptr;
    }
    if (renderObject.debugNeedsLayout) {
        PipelineOwner owner = renderObject.owner!;
        assert(owner != nullptr);
        assert(!owner.debugDoingLayout);
        ;
        if (renderObject.debugNeedsLayout) {
            return nullptr;
        }
    }
    Rect renderBounds = _calculateSubtreeBounds(renderObject);
    if (margin != 0.0) {
        renderBounds = renderBounds.inflate(margin);
    }
    if (renderBounds.isEmpty) {
        return nullptr;
    }
    double pixelRatio = math.min(maxPixelRatio, math.min(width / renderBounds.width, height / renderBounds.height));
    return _ScreenshotPaintingContext.toImage(renderObject, renderBoundspixelRatio, debugPaint);
}

String WidgetInspectorService::getSelectedSummaryWidget(String groupName, String previousSelectionId) {
    return _safeJsonEncode(_getSelectedSummaryWidget(previousSelectionId, groupName));
}

bool WidgetInspectorService::isWidgetCreationTracked() {
    _widgetCreationTracked = const _WidgetForTypeTests() is _HasCreationLocation;
    return _widgetCreationTracked!;
}

void WidgetInspectorService::postEvent(Map<Object, Object> eventData, String eventKind) {
    developer.postEvent(eventKind, eventData);
}

void WidgetInspectorService::performReassemble() {
    _clearStats();
    _resetErrorCount();
}

void WidgetInspectorService::_registerSignalServiceExtension(FunctionType callback, String name) {
    registerServiceExtension(name, );
}

void WidgetInspectorService::_registerObjectGroupServiceExtension(FunctionType callback, String name) {
    registerServiceExtension(name, );
}

void WidgetInspectorService::_registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, );
}

void WidgetInspectorService::_postExtensionStateChangedEvent(String name, Object value) {
    postEvent("Flutter.ServiceExtensionStateChanged", );
}

void WidgetInspectorService::_registerServiceExtensionWithArg(FunctionType callback, String name) {
    registerServiceExtension(name, );
}

void WidgetInspectorService::_registerServiceExtensionVarArgs(FunctionType callback, String name) {
    registerServiceExtension(name, );
}

void WidgetInspectorService::_reportStructuredError(FlutterErrorDetails details) {
    Map<String, Object> errorJson = _nodeToJson(details.toDiagnosticsNode(), InspectorSerializationDelegate(_consoleObjectGroup, 5, true, 5, this))!;
    errorJson["errorsSinceReload"] = _errorsSinceReload;
    if (_errorsSinceReload == 0) {
        errorJson["renderedErrorText"] = TextTreeRenderer(FlutterError.wrapWidth, 5).render(details.toDiagnosticsNode(DiagnosticsTreeStyle.error)).trimRight();
    } else {
        errorJson["renderedErrorText"] = "Another exception was thrown: ${details.summary}";
    }
    _errorsSinceReload = 1;
    postEvent("Flutter.Error", errorJson);
}

void WidgetInspectorService::_resetErrorCount() {
    _errorsSinceReload = 0;
}

void WidgetInspectorService::_clearStats() {
    _rebuildStats.resetCounts();
    _repaintStats.resetCounts();
}

void WidgetInspectorService::_decrementReferenceCount(_InspectorReferenceData reference) {
    reference.count = 1;
    assert(reference.count >= 0);
    if (reference.count == 0) {
        String id = _objectToId.remove(reference.object);
        assert(id != nullptr);
        _idToReferenceData.remove(id);
    }
}

String WidgetInspectorService::_devToolsInspectorUriForElement(Element element) {
    if (activeDevToolsServerAddress != nullptr && connectedVmServiceUri != nullptr) {
        String inspectorRef = toId(element, _consoleObjectGroup);
        if (inspectorRef != nullptr) {
            return devToolsInspectorUri(inspectorRef);
        }
    }
    return nullptr;
}

List<Object> WidgetInspectorService::_getParentChain(String groupName, String id) {
    Object value = toObject(id);
    List<_DiagnosticsPathNode> path;
    if (value is RenderObject) {
        path = _getRenderObjectParentChain(value, groupName)!;
    } else     {
        if (value is Element) {
        path = _getElementParentChain(value, groupName);
    } else {
        ;
    }
;
    }    return path.<Object>map().toList();
}

Map<String, Object> WidgetInspectorService::_pathNodeToJson(InspectorSerializationDelegate delegate, _DiagnosticsPathNode pathNode) {
    if (pathNode == nullptr) {
        return nullptr;
    }
    return ;
}

List<Element> WidgetInspectorService::_getRawElementParentChain(Element element, int numLocalParents) {
    List<Element> elements = element.debugGetDiagnosticChain();
    if (numLocalParents != nullptr) {
        for (;  < elements.length; i = 1) {
            if (_isValueCreatedByLocalProject(elements[i])) {
                numLocalParents = numLocalParents! - 1;
                if (numLocalParents <= 0) {
                    elements = elements.take(i + 1).toList();
                                        break;
                }
            }
        }
    }
    return elements.reversed.toList();
}

List<_DiagnosticsPathNode> WidgetInspectorService::_getElementParentChain(Element element, String groupName, int numLocalParents) {
    return _followDiagnosticableChain(_getRawElementParentChain(elementnumLocalParents)) ?? const ;
}

List<_DiagnosticsPathNode> WidgetInspectorService::_getRenderObjectParentChain(String groupName, RenderObject renderObject) {
    List<RenderObject> chain = ;
    while (renderObject != nullptr) {
        chain.add(renderObject);
        renderObject = (;
    }
    return _followDiagnosticableChain(chain.reversed.toList());
}

Map<String, Object> WidgetInspectorService::_nodeToJson(InspectorSerializationDelegate delegate, DiagnosticsNode node) {
    return node?.toJsonMap(delegate);
}

bool WidgetInspectorService::_isValueCreatedByLocalProject(Object value) {
    _Location creationLocation = _getCreationLocation(value);
    if (creationLocation == nullptr) {
        return false;
    }
    return _isLocalCreationLocation(creationLocation.file);
}

bool WidgetInspectorService::_isLocalCreationLocationImpl(String locationUri) {
    String file = Uri.parse(locationUri).path;
    if (_pubRootDirectories == nullptr) {
        return !file.contains("packages/flutter/");
    }
    for (String directory : _pubRootDirectories!) {
        if (file.startsWith(directory)) {
            return true;
        }
    }
    return false;
}

bool WidgetInspectorService::_isLocalCreationLocation(String locationUri) {
    bool cachedValue = _isLocalCreationCache[locationUri];
    if (cachedValue != nullptr) {
        return cachedValue;
    }
    bool result = _isLocalCreationLocationImpl(locationUri);
    _isLocalCreationCache[locationUri] = result;
    return result;
}

String WidgetInspectorService::_safeJsonEncode(Object object) {
    String jsonString = json.encode(object);
    _serializeRing[_serializeRingIndex] = jsonString;
    _serializeRingIndex = (_serializeRingIndex + 1) % _serializeRing.length;
    return jsonString;
}

List<DiagnosticsNode> WidgetInspectorService::_truncateNodes(int maxDescendentsTruncatableNode, Iterable<DiagnosticsNode> nodes) {
    if (nodes.every() && isWidgetCreationTracked()) {
        List<DiagnosticsNode> localNodes = nodes.where().toList();
        if (localNodes.isNotEmpty) {
            return localNodes;
        }
    }
    return nodes.take(maxDescendentsTruncatableNode).toList();
}

List<Map<String, Object>> WidgetInspectorService::_nodesToJson(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent) {
    return DiagnosticsNode.toJsonList(nodes, parent, delegate);
}

List<Object> WidgetInspectorService::_getProperties(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = (;
    return _nodesToJson(node == nullptr? const  : node.getProperties(), InspectorSerializationDelegate(groupName, this)node);
}

List<Object> WidgetInspectorService::_getChildren(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = (;
    InspectorSerializationDelegate delegate = InspectorSerializationDelegate(groupName, this);
    return _nodesToJson(node == nullptr? const  : _getChildrenFiltered(node, delegate), delegatenode);
}

List<Object> WidgetInspectorService::_getChildrenSummaryTree(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = (;
    InspectorSerializationDelegate delegate = InspectorSerializationDelegate(groupName, true, this);
    return _nodesToJson(node == nullptr? const  : _getChildrenFiltered(node, delegate), delegatenode);
}

List<Object> WidgetInspectorService::_getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = (;
    InspectorSerializationDelegate delegate = InspectorSerializationDelegate(groupName, true, this);
    return _nodesToJson(node == nullptr? const  : _getChildrenFiltered(node, delegate), delegatenode);
}

bool WidgetInspectorService::_shouldShowInSummaryTree(DiagnosticsNode node) {
    if (node.level == DiagnosticLevel.error) {
        return true;
    }
    Object value = node.value;
    if (value is! Diagnosticable) {
        return true;
    }
    if (value is! Element || !isWidgetCreationTracked()) {
        return true;
    }
    return _isValueCreatedByLocalProject(value);
}

List<DiagnosticsNode> WidgetInspectorService::_getChildrenFiltered(InspectorSerializationDelegate delegate, DiagnosticsNode node) {
    return _filterChildren(node.getChildren(), delegate);
}

List<DiagnosticsNode> WidgetInspectorService::_filterChildren(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes) {
    List<DiagnosticsNode> children = ;
    return children;
}

Map<String, Object> WidgetInspectorService::_getRootWidget(String groupName) {
    return _nodeToJson(WidgetsBinding.instance.renderViewElement?.toDiagnosticsNode(), InspectorSerializationDelegate(groupName, this));
}

Map<String, Object> WidgetInspectorService::_getRootWidgetSummaryTree(String groupName) {
    return _nodeToJson(WidgetsBinding.instance.renderViewElement?.toDiagnosticsNode(), InspectorSerializationDelegate(groupName, 1000000, true, this));
}

Map<String, Object> WidgetInspectorService::_getRootRenderObject(String groupName) {
    return _nodeToJson(RendererBinding.instance.renderView.toDiagnosticsNode(), InspectorSerializationDelegate(groupName, this));
}

Map<String, Object> WidgetInspectorService::_getDetailsSubtree(String groupName, String id, int subtreeDepth) {
    DiagnosticsNode root = (;
    if (root == nullptr) {
        return nullptr;
    }
    return _nodeToJson(root, InspectorSerializationDelegate(groupName, subtreeDepth, true, this));
}

Map<String, Object> WidgetInspectorService::_getSelectedRenderObject(String groupName, String previousSelectionId) {
    DiagnosticsNode previousSelection = (;
    RenderObject current = selection.current;
    return _nodeToJson(current == previousSelection?.value? previousSelection : current?.toDiagnosticsNode(), InspectorSerializationDelegate(groupName, this));
}

Map<String, Object> WidgetInspectorService::_getSelectedWidget(String groupName, String previousSelectionId) {
    DiagnosticsNode previousSelection = (;
    Element current = selection.currentElement;
    return _nodeToJson(current == previousSelection?.value? previousSelection : current?.toDiagnosticsNode(), InspectorSerializationDelegate(groupName, this));
}

Map<String, Object> WidgetInspectorService::_getSelectedSummaryWidget(String groupName, String previousSelectionId) {
    if (!isWidgetCreationTracked()) {
        return _getSelectedWidget(previousSelectionId, groupName);
    }
    DiagnosticsNode previousSelection = (;
    Element current = selection.currentElement;
    if (current != nullptr && !_isValueCreatedByLocalProject(current)) {
        Element firstLocal;
        for (Element candidate : current.debugGetDiagnosticChain()) {
            if (_isValueCreatedByLocalProject(candidate)) {
                firstLocal = candidate;
                                break;
            }
        }
        current = firstLocal;
    }
    return _nodeToJson(current == previousSelection?.value? previousSelection : current?.toDiagnosticsNode(), InspectorSerializationDelegate(groupName, this));
}

void WidgetInspectorService::_onFrameStart(Duration timeStamp) {
    _frameStart = timeStamp;
    SchedulerBinding.instance.addPostFrameCallback(_onFrameEnd);
}

void WidgetInspectorService::_onFrameEnd(Duration timeStamp) {
    if (_trackRebuildDirtyWidgets) {
        _postStatsEvent("Flutter.RebuiltWidgets", _rebuildStats);
    }
    if (_trackRepaintWidgets) {
        _postStatsEvent("Flutter.RepaintWidgets", _repaintStats);
    }
}

void WidgetInspectorService::_postStatsEvent(String eventName, _ElementLocationStatsTracker stats) {
    postEvent(eventName, stats.exportToJson(_frameStart));
}

void WidgetInspectorService::_onRebuildWidget(bool builtOnce, Element element) {
    _rebuildStats.add(element);
}

void WidgetInspectorService::_onPaint(RenderObject renderObject) {
    ;
}

int _LocationCount::count() {
    return _count;
}

void _LocationCount::reset() {
    _count = 0;
}

void _LocationCount::increment() {
    _count++;
}

void _ElementLocationStatsTracker::add(Element element) {
    Object widget = element.widget;
    if (widget is! _HasCreationLocation) {
        return;
    }
    _HasCreationLocation creationLocationSource = widget;
    _Location location = creationLocationSource._location;
    int id = _toLocationId(location);
    _LocationCount entry;
    if (id >= _stats.length || _stats[id] == nullptr) {
        while (id >= _stats.length) {
            _stats.add(nullptr);
        }
        entry = _LocationCount(location, id, WidgetInspectorService.instance._isLocalCreationLocation(location.file));
        if (entry.local) {
            newLocations.add(entry);
        }
        _stats[id] = entry;
    } else {
        entry = _stats[id]!;
    }
    if (entry.local) {
        if (entry.count == 0) {
            active.add(entry);
        }
        entry.increment();
    }
}

void _ElementLocationStatsTracker::resetCounts() {
    for (_LocationCount entry : active) {
        entry.reset();
    }
    active.clear();
}

Map<String, dynamic> _ElementLocationStatsTracker::exportToJson(Duration startTime) {
    List<int> events = <int>filled(active.length * 2, 0);
    int j = 0;
    for (_LocationCount stat : active) {
        events[j++] = stat.id;
        events[j++] = stat.count;
    }
    Map<String, dynamic> json = ;
    if (newLocations.isNotEmpty) {
        Map<String, List<int>> locationsJson = ;
        for (_LocationCount entry : newLocations) {
            _Location location = entry.location;
            List<int> jsonForFile = locationsJson.putIfAbsent(location.file, );
            ;
        }
        json["newLocations"] = locationsJson;
    }
    if (newLocations.isNotEmpty) {
        Map<String, Map<String, List<Object>>> fileLocationsMap = ;
        for (_LocationCount entry : newLocations) {
            _Location location = entry.location;
            Map<String, List<Object>> locations = fileLocationsMap.putIfAbsent(location.file, );
            locations["ids"]!.add(entry.id);
            locations["lines"]!.add(location.line);
            locations["columns"]!.add(location.column);
            locations["names"]!.add(location.name);
        }
        json["locations"] = fileLocationsMap;
    }
    resetCounts();
    newLocations.clear();
    return json;
}

Element _WidgetForTypeTests::createElement() {
    return ;
}

WidgetInspector::WidgetInspector(Widget child, Unknown, InspectorSelectButtonBuilder selectButtonBuilder) {
    {
        assert(child != nullptr);
    }
}

State<WidgetInspector> WidgetInspector::createState() {
    return _WidgetInspectorState();
}

void _WidgetInspectorState::initState() {
    super.initState();
    _selectionChangedCallback = ;
    WidgetInspectorService.instance.selectionChangedCallback = _selectionChangedCallback;
}

void _WidgetInspectorState::dispose() {
    if (WidgetInspectorService.instance.selectionChangedCallback == _selectionChangedCallback) {
        WidgetInspectorService.instance.selectionChangedCallback = nullptr;
    }
    super.dispose();
}

List<RenderObject> _WidgetInspectorState::hitTest(Offset position, RenderObject root) {
    List<RenderObject> regularHits = ;
    List<RenderObject> edgeHits = ;
    _hitTestHelper(regularHits, edgeHits, position, root, root.getTransformTo(nullptr));
    ;
    regularHits.sort();
    Set<RenderObject> hits = ;
    return hits.toList();
}

Widget _WidgetInspectorState::build(BuildContext context) {
    return Stack();
}

_WidgetInspectorState::_WidgetInspectorState() {
    {
        selection = WidgetInspectorService.instance.selection;
    }
}

bool _WidgetInspectorState::_hitTestHelper(List<RenderObject> edgeHits, List<RenderObject> hits, RenderObject object, Offset position, Matrix4 transform) {
    bool hit = false;
    Matrix4 inverse = Matrix4.tryInvert(transform);
    if (inverse == nullptr) {
        return false;
    }
    Offset localPosition = MatrixUtils.transformPoint(inverse, position);
    List<DiagnosticsNode> children = object.debugDescribeChildren();
    for (; i >= 0; i = 1) {
        DiagnosticsNode diagnostics = children[i];
        assert(diagnostics != nullptr);
        if (diagnostics.style == DiagnosticsTreeStyle.offstage || diagnostics.value is! RenderObject) {
            continue;
        }
        RenderObject child = (;
        Rect paintClip = object.describeApproximatePaintClip(child);
        if (paintClip != nullptr && !paintClip.contains(localPosition)) {
            continue;
        }
        Matrix4 childTransform = transform.clone();
        object.applyPaintTransform(child, childTransform);
        if (_hitTestHelper(hits, edgeHits, position, child, childTransform)) {
            hit = true;
        }
    }
    Rect bounds = object.semanticBounds;
    if (bounds.contains(localPosition)) {
        hit = true;
        if (!bounds.deflate(_edgeHitMargin).contains(localPosition)) {
            edgeHits.add(object);
        }
    }
    if (hit) {
        hits.add(object);
    }
    return hit;
}

void _WidgetInspectorState::_inspectAt(Offset position) {
    if (!isSelectMode) {
        return;
    }
    RenderIgnorePointer ignorePointer = (;
    RenderObject userRender = ignorePointer.child!;
    List<RenderObject> selected = hitTest(position, userRender);
    setState();
}

void _WidgetInspectorState::_handlePanDown(DragDownDetails event) {
    _lastPointerLocation = event.globalPosition;
    _inspectAt(event.globalPosition);
}

void _WidgetInspectorState::_handlePanUpdate(DragUpdateDetails event) {
    _lastPointerLocation = event.globalPosition;
    _inspectAt(event.globalPosition);
}

void _WidgetInspectorState::_handlePanEnd(DragEndDetails details) {
    Rect bounds = (Offset.zero & (WidgetsBinding.instance.window.physicalSize / WidgetsBinding.instance.window.devicePixelRatio)).deflate(_kOffScreenMargin);
    if (!bounds.contains(_lastPointerLocation!)) {
        setState();
    }
}

void _WidgetInspectorState::_handleTap() {
    if (!isSelectMode) {
        return;
    }
    if (_lastPointerLocation != nullptr) {
        _inspectAt(_lastPointerLocation!);
        developer.inspect(selection.current);
    }
    setState();
}

void _WidgetInspectorState::_handleEnableSelect() {
    setState();
}

List<RenderObject> InspectorSelection::candidates() {
    return _candidates;
}

void InspectorSelection::candidates(List<RenderObject> value) {
    _candidates = value;
    _index = 0;
    _computeCurrent();
}

int InspectorSelection::index() {
    return _index;
}

void InspectorSelection::index(int value) {
    _index = value;
    _computeCurrent();
}

void InspectorSelection::clear() {
    _candidates = ;
    _index = 0;
    _computeCurrent();
}

RenderObject InspectorSelection::current() {
    return active? _current : nullptr;
}

void InspectorSelection::current(RenderObject value) {
    if (_current != value) {
        _current = value;
        _currentElement = (()?.element;
    }
}

Element InspectorSelection::currentElement() {
    return _currentElement?.debugIsDefunct ?? true? nullptr : _currentElement;
}

void InspectorSelection::currentElement(Element element) {
    if (element?.debugIsDefunct ?? false) {
        _currentElement = nullptr;
        _current = nullptr;
        return;
    }
    if (currentElement != element) {
        _currentElement = element;
        _current = element!.findRenderObject();
    }
}

bool InspectorSelection::active() {
    return _current != nullptr && _current!.attached;
}

void InspectorSelection::_computeCurrent() {
    if ( < candidates.length) {
        _current = candidates[index];
        _currentElement = (()?.element;
    } else {
        _current = nullptr;
        _currentElement = nullptr;
    }
}

_RenderInspectorOverlay _InspectorOverlay::createRenderObject(BuildContext context) {
    return _RenderInspectorOverlay(selection);
}

void _InspectorOverlay::updateRenderObject(BuildContext context, _RenderInspectorOverlay renderObject) {
    renderObject.selection = selection;
}

InspectorSelection _RenderInspectorOverlay::selection() {
    return _selection;
}

void _RenderInspectorOverlay::selection(InspectorSelection value) {
    if (value != _selection) {
        _selection = value;
    }
    markNeedsPaint();
}

bool _RenderInspectorOverlay::sizedByParent() {
    return true;
}

bool _RenderInspectorOverlay::alwaysNeedsCompositing() {
    return true;
}

Size _RenderInspectorOverlay::computeDryLayout(BoxConstraints constraints) {
    return constraints.constrain(Size.infinite);
}

void _RenderInspectorOverlay::paint(PaintingContext context, Offset offset) {
    assert(needsCompositing);
    context.addLayer(_InspectorOverlayLayer(Rect.fromLTWH(offset.dx, offset.dy, size.width, size.height), selection, parent is RenderObject? ( : nullptr));
}

_RenderInspectorOverlay::_RenderInspectorOverlay(InspectorSelection selection) {
    {
        _selection = selection;
        assert(selection != nullptr);
    }
}

bool _TransformedRect::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _TransformedRect && other.rect == rect && other.transform == transform;
}

int _TransformedRect::hashCode() {
    return Object.hash(rect, transform);
}

_TransformedRect::_TransformedRect(RenderObject ancestor, RenderObject object) {
    {
        rect = object.semanticBounds;
        transform = object.getTransformTo(ancestor);
    }
}

bool _InspectorOverlayRenderState::==(Object other) {
    if (other.runtimeType != runtimeType) {
        return false;
    }
    return other is _InspectorOverlayRenderState && other.overlayRect == overlayRect && other.selected == selected && <_TransformedRect>listEquals(other.candidates, candidates) && other.tooltip == tooltip;
}

int _InspectorOverlayRenderState::hashCode() {
    return Object.hash(overlayRect, selected, Object.hashAll(candidates), tooltip);
}

void _InspectorOverlayLayer::addToScene(SceneBuilder builder) {
    if (!selection.active) {
        return;
    }
    RenderObject selected = selection.current!;
    if (!_isInInspectorRenderObjectTree(selected)) {
        return;
    }
    List<_TransformedRect> candidates = ;
    for (RenderObject candidate : selection.candidates) {
        if (candidate == selected || !candidate.attached || !_isInInspectorRenderObjectTree(candidate)) {
            continue;
        }
        candidates.add(_TransformedRect(candidate, rootRenderObject));
    }
    _InspectorOverlayRenderState state = _InspectorOverlayRenderState(overlayRect, _TransformedRect(selected, rootRenderObject), selection.currentElement!.toStringShort(), TextDirection.ltr, candidates);
    if (state != _lastState) {
        _lastState = state;
        _picture = _buildPicture(state);
    }
    builder.addPicture(Offset.zero, _picture);
}

bool _InspectorOverlayLayer::findAnnotations<S extends Object>(Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return false;
}

_InspectorOverlayLayer::_InspectorOverlayLayer(Rect overlayRect, RenderObject rootRenderObject, InspectorSelection selection) {
    {
        assert(overlayRect != nullptr);
        assert(selection != nullptr);
    }
    {
        bool inDebugMode = false;
        assert(());
        if (inDebugMode == false) {
            ;
        }
    }
}

Picture _InspectorOverlayLayer::_buildPicture(_InspectorOverlayRenderState state) {
    PictureRecorder recorder = ui.PictureRecorder();
    Canvas canvas = Canvas(recorder, state.overlayRect);
    Size size = state.overlayRect.size;
    canvas.translate(state.overlayRect.left, state.overlayRect.top);
    Paint fillPaint = ;
    Paint borderPaint = ;
    Rect selectedPaintRect = state.selected.rect.deflate(0.5);
    ;
    for (_TransformedRect transformedRect : state.candidates) {
        ;
    }
    Rect targetRect = MatrixUtils.transformRect(state.selected.transform, state.selected.rect);
    Offset target = Offset(targetRect.left, targetRect.center.dy);
    double offsetFromWidget = 9.0;
    double verticalOffset = (targetRect.height) / 2 + offsetFromWidget;
    _paintDescription(canvas, state.tooltip, state.textDirection, target, verticalOffset, size, targetRect);
    return recorder.endRecording();
}

void _InspectorOverlayLayer::_paintDescription(Canvas canvas, String message, Size size, Offset target, Rect targetRect, TextDirection textDirection, double verticalOffset) {
    canvas.save();
    double maxWidth = size.width - 2 * (_kScreenEdgeMargin + _kTooltipPadding);
    TextSpan textSpan = (;
    if (_textPainter == nullptr || textSpan!.text != message || _textPainterMaxWidth != maxWidth) {
        _textPainterMaxWidth = maxWidth;
        _textPainter = ;
    }
    Size tooltipSize = _textPainter!.size + const Offset(_kTooltipPadding * 2, _kTooltipPadding * 2);
    Offset tipOffset = positionDependentBox(size, tooltipSize, target, verticalOffset, false);
    Paint tooltipBackground = ;
    canvas.drawRect(Rect.fromPoints(tipOffset, tipOffset.translate(tooltipSize.width, tooltipSize.height)), tooltipBackground);
    double wedgeY = tipOffset.dy;
    bool tooltipBelow = tipOffset.dy > target.dy;
    if (!tooltipBelow) {
        wedgeY = tooltipSize.height;
    }
    double wedgeSize = _kTooltipPadding * 2;
    double wedgeX = math.max(tipOffset.dx, target.dx) + wedgeSize * 2;
    wedgeX = math.min(wedgeX, tipOffset.dx + tooltipSize.width - wedgeSize * 2);
    List<Offset> wedge = ;
    canvas.drawPath(, tooltipBackground);
    _textPainter!.paint(canvas, tipOffset + const Offset(_kTooltipPadding, _kTooltipPadding));
    canvas.restore();
}

bool _InspectorOverlayLayer::_isInInspectorRenderObjectTree(RenderObject child) {
    RenderObject current = (;
    while (current != nullptr) {
        if (current is RenderStack && current.lastChild is _RenderInspectorOverlay) {
            return rootRenderObject == current;
        }
        current = (;
    }
    return false;
}

Map<String, Object> _Location::toJsonMap() {
    Map<String, Object> json = ;
    if (name != nullptr) {
        json["name"] = name;
    }
    return json;
}

String _Location::toString() {
    List<String> parts = ;
    if (name != nullptr) {
        parts.add(name!);
    }
    parts.add(file);
    ;
    return parts.join(":");
}

bool _isDebugCreator(DiagnosticsNode node) {
    return node is DiagnosticsDebugCreator;
}

Iterable<DiagnosticsNode> debugTransformDebugCreator(Iterable<DiagnosticsNode> properties) {
    if (!kDebugMode) {
        return ;
    }
    List<DiagnosticsNode> pending = ;
    ErrorSummary errorSummary;
    for (DiagnosticsNode node : properties) {
        if (node is ErrorSummary) {
            errorSummary = node;
                        break;
        }
    }
    bool foundStackTrace = false;
    List<DiagnosticsNode> result = ;
    for (DiagnosticsNode node : properties) {
        if (!foundStackTrace && node is DiagnosticsStackTrace) {
            foundStackTrace = true;
        }
        if (_isDebugCreator(node)) {
            result.addAll(_parseDiagnosticsNode(node, errorSummary));
        } else {
            if (foundStackTrace) {
                pending.add(node);
            } else {
                result.add(node);
            }
        }
    }
    result.addAll(pending);
    return result;
}

Iterable<DiagnosticsNode> _parseDiagnosticsNode(ErrorSummary errorSummary, DiagnosticsNode node) {
    assert(_isDebugCreator(node));
    ;
}

Iterable<DiagnosticsNode> _describeRelevantUserCode(Element element, ErrorSummary errorSummary) {
    if (!WidgetInspectorService.instance.isWidgetCreationTracked()) {
        return ;
    }
    ;
    List<DiagnosticsNode> nodes = ;
    ;
    if (processElement(element)) {
        element.visitAncestorElements(processElement);
    }
    return nodes;
}

DevToolsDeepLinkProperty::DevToolsDeepLinkProperty(String description, String url) {
    {
        assert(description != nullptr);
        assert(url != nullptr);
        super("", urldescription, DiagnosticLevel.info);
    }
}

bool debugIsLocalCreationLocation(Object object) {
    bool isLocal = false;
    assert(());
    return isLocal;
}

bool debugIsWidgetLocalCreation(Widget widget) {
    _Location location = _getObjectCreationLocation(widget);
    return location != nullptr && WidgetInspectorService.instance._isLocalCreationLocation(location.file);
}

String _describeCreationLocation(Object object) {
    _Location location = _getCreationLocation(object);
    return location?.toString();
}

_Location _getObjectCreationLocation(Object object) {
    return object is _HasCreationLocation? object._location : nullptr;
}

_Location _getCreationLocation(Object object) {
    Object candidate = object is Element && !object.debugIsDefunct? object.widget : object;
    return candidate == nullptr? nullptr : _getObjectCreationLocation(candidate);
}

int _toLocationId(_Location location) {
    int id = _locationToId[location];
    if (id != nullptr) {
        return id;
    }
    id = _locations.length;
    _locations.add(location);
    _locationToId[location] = id;
    return id;
}

Map<String, Object> InspectorSerializationDelegate::additionalNodeProperties(DiagnosticsNode node) {
    Map<String, Object> result = ;
    Object value = node.value;
    if (_interactive) {
        result["objectId"] = service.toId(node, groupName!);
        result["valueId"] = service.toId(value, groupName!);
    }
    if (summaryTree) {
        result["summaryTree"] = true;
    }
    _Location creationLocation = _getCreationLocation(value);
    if (creationLocation != nullptr) {
        result["locationId"] = _toLocationId(creationLocation);
        result["creationLocation"] = creationLocation.toJsonMap();
        if (service._isLocalCreationLocation(creationLocation.file)) {
            _nodesCreatedByLocalProject.add(node);
            result["createdByLocalProject"] = true;
        }
    }
    if (addAdditionalPropertiesCallback != nullptr) {
        result.addAll(addAdditionalPropertiesCallback!(node, this) ?? );
    }
    return result;
}

DiagnosticsSerializationDelegate InspectorSerializationDelegate::delegateForNode(DiagnosticsNode node) {
    return summaryTree || subtreeDepth > 1 || service._shouldShowInSummaryTree(node)? copyWith(subtreeDepth - 1) : this;
}

List<DiagnosticsNode> InspectorSerializationDelegate::filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return service._filterChildren(nodes, this);
}

List<DiagnosticsNode> InspectorSerializationDelegate::filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    bool createdByLocalProject = _nodesCreatedByLocalProject.contains(owner);
    return nodes.where().toList();
}

List<DiagnosticsNode> InspectorSerializationDelegate::truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    if (maxDescendentsTruncatableNode >= 0 && owner!.allowTruncate == true && nodes.length > maxDescendentsTruncatableNode) {
        nodes = service._truncateNodes(nodes, maxDescendentsTruncatableNode);
    }
    return nodes;
}

DiagnosticsSerializationDelegate InspectorSerializationDelegate::copyWith(bool includeProperties, int subtreeDepth) {
    return InspectorSerializationDelegate(groupName, summaryTree, maxDescendentsTruncatableNode, expandPropertyValues, subtreeDepth ?? this.subtreeDepth, includeProperties ?? this.includeProperties, service, addAdditionalPropertiesCallback);
}

bool InspectorSerializationDelegate::_interactive() {
    return groupName != nullptr;
}
