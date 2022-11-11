#include "widget_inspector.hpp"
void _ProxyLayerCls::addToScene(SceneBuilder builder) {
    _layer->addToScene(builder);
}

bool _ProxyLayerCls::findAnnotationstemplate<typename S> (Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return _layer->findAnnotations(result, localPositiononlyFirst);
}

void _MulticastCanvasCls::clipPath(bool doAntiAlias, Path path) {
    _main->clipPath(pathdoAntiAlias);
    _screenshot->clipPath(pathdoAntiAlias);
}

void _MulticastCanvasCls::clipRRect(bool doAntiAlias, RRect rrect) {
    _main->clipRRect(rrectdoAntiAlias);
    _screenshot->clipRRect(rrectdoAntiAlias);
}

void _MulticastCanvasCls::clipRect(ClipOp clipOp, bool doAntiAlias, Rect rect) {
    _main->clipRect(rectclipOp, doAntiAlias);
    _screenshot->clipRect(rectclipOp, doAntiAlias);
}

void _MulticastCanvasCls::drawArc(Paint paint, Rect rect, double startAngle, double sweepAngle, bool useCenter) {
    _main->drawArc(rect, startAngle, sweepAngle, useCenter, paint);
    _screenshot->drawArc(rect, startAngle, sweepAngle, useCenter, paint);
}

void _MulticastCanvasCls::drawAtlas(Image atlas, BlendMode blendMode, List<Color> colors, Rect cullRect, Paint paint, List<Rect> rects, List<RSTransform> transforms) {
    _main->drawAtlas(atlas, transforms, rects, colors, blendMode, cullRect, paint);
    _screenshot->drawAtlas(atlas, transforms, rects, colors, blendMode, cullRect, paint);
}

void _MulticastCanvasCls::drawCircle(Offset c, Paint paint, double radius) {
    _main->drawCircle(c, radius, paint);
    _screenshot->drawCircle(c, radius, paint);
}

void _MulticastCanvasCls::drawColor(BlendMode blendMode, Color color) {
    _main->drawColor(color, blendMode);
    _screenshot->drawColor(color, blendMode);
}

void _MulticastCanvasCls::drawDRRect(RRect inner, RRect outer, Paint paint) {
    _main->drawDRRect(outer, inner, paint);
    _screenshot->drawDRRect(outer, inner, paint);
}

void _MulticastCanvasCls::drawImage(Image image, Offset p, Paint paint) {
    _main->drawImage(image, p, paint);
    _screenshot->drawImage(image, p, paint);
}

void _MulticastCanvasCls::drawImageNine(Rect center, Rect dst, Image image, Paint paint) {
    _main->drawImageNine(image, center, dst, paint);
    _screenshot->drawImageNine(image, center, dst, paint);
}

void _MulticastCanvasCls::drawImageRect(Rect dst, Image image, Paint paint, Rect src) {
    _main->drawImageRect(image, src, dst, paint);
    _screenshot->drawImageRect(image, src, dst, paint);
}

void _MulticastCanvasCls::drawLine(Offset p1, Offset p2, Paint paint) {
    _main->drawLine(p1, p2, paint);
    _screenshot->drawLine(p1, p2, paint);
}

void _MulticastCanvasCls::drawOval(Paint paint, Rect rect) {
    _main->drawOval(rect, paint);
    _screenshot->drawOval(rect, paint);
}

void _MulticastCanvasCls::drawPaint(Paint paint) {
    _main->drawPaint(paint);
    _screenshot->drawPaint(paint);
}

void _MulticastCanvasCls::drawParagraph(Offset offset, Paragraph paragraph) {
    _main->drawParagraph(paragraph, offset);
    _screenshot->drawParagraph(paragraph, offset);
}

void _MulticastCanvasCls::drawPath(Paint paint, Path path) {
    _main->drawPath(path, paint);
    _screenshot->drawPath(path, paint);
}

void _MulticastCanvasCls::drawPicture(Picture picture) {
    _main->drawPicture(picture);
    _screenshot->drawPicture(picture);
}

void _MulticastCanvasCls::drawPoints(Paint paint, PointMode pointMode, List<Offset> points) {
    _main->drawPoints(pointMode, points, paint);
    _screenshot->drawPoints(pointMode, points, paint);
}

void _MulticastCanvasCls::drawRRect(Paint paint, RRect rrect) {
    _main->drawRRect(rrect, paint);
    _screenshot->drawRRect(rrect, paint);
}

void _MulticastCanvasCls::drawRawAtlas(Image atlas, BlendMode blendMode, Int32List colors, Rect cullRect, Paint paint, Float32List rects, Float32List rstTransforms) {
    _main->drawRawAtlas(atlas, rstTransforms, rects, colors, blendMode, cullRect, paint);
    _screenshot->drawRawAtlas(atlas, rstTransforms, rects, colors, blendMode, cullRect, paint);
}

void _MulticastCanvasCls::drawRawPoints(Paint paint, PointMode pointMode, Float32List points) {
    _main->drawRawPoints(pointMode, points, paint);
    _screenshot->drawRawPoints(pointMode, points, paint);
}

void _MulticastCanvasCls::drawRect(Paint paint, Rect rect) {
    _main->drawRect(rect, paint);
    _screenshot->drawRect(rect, paint);
}

void _MulticastCanvasCls::drawShadow(Color color, double elevation, Path path, bool transparentOccluder) {
    _main->drawShadow(path, color, elevation, transparentOccluder);
    _screenshot->drawShadow(path, color, elevation, transparentOccluder);
}

void _MulticastCanvasCls::drawVertices(BlendMode blendMode, Paint paint, Vertices vertices) {
    _main->drawVertices(vertices, blendMode, paint);
    _screenshot->drawVertices(vertices, blendMode, paint);
}

int _MulticastCanvasCls::getSaveCount() {
    return _main->getSaveCount();
}

void _MulticastCanvasCls::restore() {
    _main->restore();
    _screenshot->restore();
}

void _MulticastCanvasCls::rotate(double radians) {
    _main->rotate(radians);
    _screenshot->rotate(radians);
}

void _MulticastCanvasCls::save() {
    _main->save();
    _screenshot->save();
}

void _MulticastCanvasCls::saveLayer(Rect bounds, Paint paint) {
    _main->saveLayer(bounds, paint);
    _screenshot->saveLayer(bounds, paint);
}

void _MulticastCanvasCls::scale(double sx, double sy) {
    _main->scale(sx, sy);
    _screenshot->scale(sx, sy);
}

void _MulticastCanvasCls::skew(double sx, double sy) {
    _main->skew(sx, sy);
    _screenshot->skew(sx, sy);
}

void _MulticastCanvasCls::transform(Float64List matrix4) {
    _main->transform(matrix4);
    _screenshot->transform(matrix4);
}

void _MulticastCanvasCls::translate(double dx, double dy) {
    _main->translate(dx, dy);
    _screenshot->translate(dx, dy);
}

dynamic _MulticastCanvasCls::noSuchMethod(Invocation invocation) {
    super->noSuchMethod(invocation);
}

_MulticastCanvasCls::_MulticastCanvasCls(Canvas main, Canvas screenshot) {
    {
        assert(main != nullptr);
        assert(screenshot != nullptr);
        _main = main;
        _screenshot = screenshot;
    }
}

Rect _calculateSubtreeBoundsHelper(RenderObject object, Matrix4 transform) {
    Rect bounds = MatrixUtilsCls->transformRect(transform, object->semanticBounds());
    object->visitChildren([=] (RenderObject child) {
        Matrix4 childTransform = transform->clone();
        object->applyPaintTransform(child, childTransform);
        Rect childBounds = _calculateSubtreeBoundsHelper(child, childTransform);
        Rect paintClip = object->describeApproximatePaintClip(child);
        if (paintClip != nullptr) {
            Rect transformedPaintClip = MatrixUtilsCls->transformRect(transform, paintClip);
            childBounds = childBounds->intersect(transformedPaintClip);
        }
        if (childBounds->isFinite() && !childBounds->isEmpty()) {
            bounds = bounds->isEmpty()? childBounds : bounds->expandToInclude(childBounds);
        }
    });
    return bounds;
}

Rect _calculateSubtreeBounds(RenderObject object) {
    return _calculateSubtreeBoundsHelper(object, Matrix4Cls->identity());
}

void _ScreenshotContainerLayerCls::addToScene(SceneBuilder builder) {
    addChildrenToScene(builder);
}

Offset _ScreenshotDataCls::screenshotOffset() {
    assert(foundTarget);
    return containerLayer->offset;
}

void _ScreenshotDataCls::screenshotOffset(Offset offset) {
    containerLayer->offset = offset;
}

_ScreenshotDataCls::_ScreenshotDataCls(RenderObject target) {
    {
        assert(target != nullptr);
        containerLayer = make<_ScreenshotContainerLayerCls>();
    }
}

Canvas _ScreenshotPaintingContextCls::canvas() {
    if (_data->includeInScreenshot) {
        if (_screenshotCanvas == nullptr) {
            _startRecordingScreenshot();
        }
        assert(_screenshotCanvas != nullptr);
        return _data->includeInRegularContext? _multicastCanvas! : _screenshotCanvas!;
    } else {
        assert(_data->includeInRegularContext);
        return super->canvas;
    }
}

void _ScreenshotPaintingContextCls::stopRecordingIfNeeded() {
    super->stopRecordingIfNeeded();
    _stopRecordingScreenshotIfNeeded();
}

void _ScreenshotPaintingContextCls::appendLayer(Layer layer) {
    if (_data->includeInRegularContext) {
        super->appendLayer(layer);
        if (_data->includeInScreenshot) {
            assert(!_isScreenshotRecording());
            _data->containerLayer->append(make<_ProxyLayerCls>(layer));
        }
    } else {
        assert(!_isScreenshotRecording());
        assert(_data->includeInScreenshot);
        layer->remove();
        _data->containerLayer->append(layer);
        return;
    }
}

PaintingContext _ScreenshotPaintingContextCls::createChildContext(Rect bounds, ContainerLayer childLayer) {
    if (_data->foundTarget) {
        return super->createChildContext(childLayer, bounds);
    } else {
        return make<_ScreenshotPaintingContextCls>(childLayer, bounds, _data);
    }
}

void _ScreenshotPaintingContextCls::paintChild(RenderObject child, Offset offset) {
    bool isScreenshotTarget = identical(child, _data->target);
    if (isScreenshotTarget) {
        assert(!_data->includeInScreenshot);
        assert(!_data->foundTarget);
        _data->foundTarget = true;
        _data->screenshotOffset = offset;
        _data->includeInScreenshot = true;
    }
    super->paintChild(child, offset);
    if (isScreenshotTarget) {
        _stopRecordingScreenshotIfNeeded();
        _data->includeInScreenshot = false;
    }
}

Future<Image> _ScreenshotPaintingContextCls::toImage(bool debugPaint, double pixelRatio, Rect renderBounds, RenderObject renderObject) {
    RenderObject repaintBoundary = renderObject;
    while (repaintBoundary != nullptr && !repaintBoundary->isRepaintBoundary()) {
        repaintBoundary = as<RenderObject>(repaintBoundary->parent!);
    }
    assert(repaintBoundary != nullptr);
    _ScreenshotData data = make<_ScreenshotDataCls>(renderObject);
    _ScreenshotPaintingContext context = make<_ScreenshotPaintingContextCls>(repaintBoundary->debugLayer()!, repaintBoundary->paintBounds(), data);
    if (identical(renderObject, repaintBoundary)) {
        data->containerLayer->append(make<_ProxyLayerCls>(repaintBoundary->debugLayer()!));
        data->foundTarget = true;
        OffsetLayer offsetLayer = as<OffsetLayer>(repaintBoundary->debugLayer()!);
        data->screenshotOffset() = offsetLayer->offset;
    } else {
        PaintingContextCls->debugInstrumentRepaintCompositedChild(repaintBoundarycontext);
    }
    if (debugPaint && !debugPaintSizeEnabled) {
        data->includeInRegularContext = false;
        context->stopRecordingIfNeeded();
        assert(data->foundTarget);
        data->includeInScreenshot = true;
        debugPaintSizeEnabled = true;
        try {
            renderObject->debugPaint(context, data->screenshotOffset());
        } finally {
            debugPaintSizeEnabled = false;
            context->stopRecordingIfNeeded();
        };
    }
    repaintBoundary->debugLayer()!->buildScene(ui->make<SceneBuilderCls>());
    return data->containerLayer->toImage(renderBoundspixelRatio);
}

_ScreenshotPaintingContextCls::_ScreenshotPaintingContextCls(ContainerLayer containerLayer, Rect estimatedBounds, _ScreenshotData screenshotData) : PaintingContext(containerLayer, estimatedBounds) {
    {
        _data = screenshotData;
    }
}

bool _ScreenshotPaintingContextCls::_isScreenshotRecording() {
    bool hasScreenshotCanvas = _screenshotCanvas != nullptr;
    assert([=] () {
        if (hasScreenshotCanvas) {
            assert(_screenshotCurrentLayer != nullptr);
            assert(_screenshotRecorder != nullptr);
            assert(_screenshotCanvas != nullptr);
        } else {
            assert(_screenshotCurrentLayer == nullptr);
            assert(_screenshotRecorder == nullptr);
            assert(_screenshotCanvas == nullptr);
        }
        return true;
    }());
    return hasScreenshotCanvas;
}

void _ScreenshotPaintingContextCls::_startRecordingScreenshot() {
    assert(_data->includeInScreenshot);
    assert(!_isScreenshotRecording());
    _screenshotCurrentLayer = make<PictureLayerCls>(estimatedBounds);
    _screenshotRecorder = ui->make<PictureRecorderCls>();
    _screenshotCanvas = make<CanvasCls>(_screenshotRecorder!);
    _data->containerLayer->append(_screenshotCurrentLayer!);
    if (_data->includeInRegularContext) {
        _multicastCanvas = make<_MulticastCanvasCls>(super->canvas, _screenshotCanvas!);
    } else {
        _multicastCanvas = nullptr;
    }
}

void _ScreenshotPaintingContextCls::_stopRecordingScreenshotIfNeeded() {
    if (!_isScreenshotRecording()) {
        return;
    }
    _screenshotCurrentLayer!->picture = _screenshotRecorder!->endRecording();
    _screenshotCurrentLayer = nullptr;
    _screenshotRecorder = nullptr;
    _multicastCanvas = nullptr;
    _screenshotCanvas = nullptr;
}

_DiagnosticsPathNodeCls::_DiagnosticsPathNodeCls(int childIndex, List<DiagnosticsNode> children, DiagnosticsNode node) {
    {
        assert(node != nullptr);
        assert(children != nullptr);
    }
}

List<_DiagnosticsPathNode> _followDiagnosticableChain(List<Diagnosticable> chain, String name, DiagnosticsTreeStyle style) {
    List<_DiagnosticsPathNode> path = makeList();
    if (chain->isEmpty) {
        return path;
    }
    DiagnosticsNode diagnostic = chain->first->toDiagnosticsNode(name, style);
    for (;  < chain->length; i = 1) {
        Diagnosticable target = chain[i];
        bool foundMatch = false;
        List<DiagnosticsNode> children = diagnostic->getChildren();
        for (;  < children->length; j = 1) {
            DiagnosticsNode child = children[j];
            if (child->value == target) {
                foundMatch = true;
                path->add(make<_DiagnosticsPathNodeCls>(diagnostic, children, j));
                diagnostic = child;
                                break;
            }
        }
        assert(foundMatch);
    }
    path->add(make<_DiagnosticsPathNodeCls>(diagnostic, diagnostic->getChildren()));
    return path;
}

WidgetInspectorService WidgetInspectorServiceCls::instance() {
    return _instance;
}

void WidgetInspectorServiceCls::instance(WidgetInspectorService instance) {
    _instance = instance;
}

List<String> WidgetInspectorServiceCls::pubRootDirectories() {
    return _pubRootDirectories == nullptr? makeList() : <String>from(_pubRootDirectories!);
}

void WidgetInspectorServiceCls::registerServiceExtension(ServiceExtensionCallback callback, String name) {
    _registerServiceExtensionCallback(__s("inspector.$name"), callback);
}

Future<void> WidgetInspectorServiceCls::forceRebuild() {
    WidgetsBinding binding = WidgetsBindingCls::instance;
    if (binding->renderViewElement() != nullptr) {
        binding->buildOwner()!->reassemble(binding->renderViewElement()!, nullptr);
        return binding->endOfFrame;
    }
    return <void>value();
}

bool WidgetInspectorServiceCls::isStructuredErrorsEnabled() {
    bool enabled = false;
    assert([=] () {
        enabled = boolValue->fromEnvironment(__s("flutter.inspector.structuredErrors")!kIsWeb);
        return true;
    }());
    return enabled;
}

void WidgetInspectorServiceCls::initServiceExtensions(RegisterServiceExtensionCallback registerServiceExtensionCallback) {
    FlutterExceptionHandler defaultExceptionHandler = FlutterErrorCls::presentError;
    if (isStructuredErrorsEnabled()) {
        FlutterErrorCls::presentError = _reportStructuredError;
    }
    _registerServiceExtensionCallback = registerServiceExtensionCallback;
    assert(!_debugServiceExtensionsRegistered);
    assert([=] () {
        _debugServiceExtensionsRegistered = true;
        return true;
    }());
    SchedulerBindingCls::instance->addPersistentFrameCallback(_onFrameStart);
    _registerBoolServiceExtension(__s("structuredErrors"), [=] ()     {
        FlutterErrorCls::presentError == _reportStructuredError;
    }, [=] (bool value) {
        FlutterErrorCls::presentError = value? _reportStructuredError : defaultExceptionHandler;
        return <void>value();
    });
    _registerBoolServiceExtension(__s("show"), [=] ()     {
        WidgetsAppCls::debugShowWidgetInspectorOverride;
    }, [=] (bool value) {
        if (WidgetsAppCls::debugShowWidgetInspectorOverride == value) {
            return <void>value();
        }
        WidgetsAppCls::debugShowWidgetInspectorOverride = value;
        return forceRebuild();
    });
    if (isWidgetCreationTracked()) {
        _registerBoolServiceExtension(__s("trackRebuildDirtyWidgets"), [=] ()         {
            _trackRebuildDirtyWidgets;
        }, [=] (bool value) {
            if (value == _trackRebuildDirtyWidgets) {
                return;
            }
            _rebuildStats->resetCounts();
            _trackRebuildDirtyWidgets = value;
            if (value) {
                assert(debugOnRebuildDirtyWidget == nullptr);
                debugOnRebuildDirtyWidget = _onRebuildWidget;
                await await forceRebuild();
                return;
            } else {
                debugOnRebuildDirtyWidget = nullptr;
                return;
            }
        });
        _registerBoolServiceExtension(__s("trackRepaintWidgets"), [=] ()         {
            _trackRepaintWidgets;
        }, [=] (bool value) {
            if (value == _trackRepaintWidgets) {
                return;
            }
            _repaintStats->resetCounts();
            _trackRepaintWidgets = value;
            if (value) {
                assert(debugOnProfilePaint == nullptr);
                debugOnProfilePaint = _onPaint;
                InlineMethod;
                RenderObject root = RendererBindingCls::instance->renderView;
                markTreeNeedsPaint(root);
            } else {
                debugOnProfilePaint = nullptr;
            }
        });
    }
    _registerSignalServiceExtension(__s("disposeAllGroups"), [=] () {
        disposeAllGroups();
        return nullptr;
    });
    _registerObjectGroupServiceExtension(__s("disposeGroup"), [=] (String name) {
        disposeGroup(name);
        return nullptr;
    });
    _registerSignalServiceExtension(__s("isWidgetTreeReady"), isWidgetTreeReady);
    _registerServiceExtensionWithArg(__s("disposeId"), [=] (String objectId,String objectGroup) {
        disposeId(objectId, objectGroup);
        return nullptr;
    });
    _registerServiceExtensionVarArgs(__s("setPubRootDirectories"), [=] (List<String> args) {
        setPubRootDirectories(args);
        return nullptr;
    });
    _registerServiceExtensionVarArgs(__s("addPubRootDirectories"), [=] (List<String> args) {
        addPubRootDirectories(args);
        return nullptr;
    });
    _registerServiceExtensionVarArgs(__s("removePubRootDirectories"), [=] (List<String> args) {
        removePubRootDirectories(args);
        return nullptr;
    });
    _registerServiceExtensionWithArg(__s("setSelectionById"), setSelectionById);
    _registerServiceExtensionWithArg(__s("getParentChain"), _getParentChain);
    _registerServiceExtensionWithArg(__s("getProperties"), _getProperties);
    _registerServiceExtensionWithArg(__s("getChildren"), _getChildren);
    _registerServiceExtensionWithArg(__s("getChildrenSummaryTree"), _getChildrenSummaryTree);
    _registerServiceExtensionWithArg(__s("getChildrenDetailsSubtree"), _getChildrenDetailsSubtree);
    _registerObjectGroupServiceExtension(__s("getRootWidget"), _getRootWidget);
    _registerObjectGroupServiceExtension(__s("getRootRenderObject"), _getRootRenderObject);
    _registerObjectGroupServiceExtension(__s("getRootWidgetSummaryTree"), _getRootWidgetSummaryTree);
    registerServiceExtension(__s("getDetailsSubtree"), [=] (Map<String, String> parameters) {
        assert(parameters->containsKey(__s("objectGroup")));
        String subtreeDepth = parameters[__s("subtreeDepth")];
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("result"), _getDetailsSubtree(parameters[__s("arg")], parameters[__s("objectGroup")], subtreeDepth != nullptr? intValue->parse(subtreeDepth) : 2));return list1;
    });
    _registerServiceExtensionWithArg(__s("getSelectedRenderObject"), _getSelectedRenderObject);
    _registerServiceExtensionWithArg(__s("getSelectedWidget"), _getSelectedWidget);
    _registerServiceExtensionWithArg(__s("getSelectedSummaryWidget"), _getSelectedSummaryWidget);
    _registerSignalServiceExtension(__s("isWidgetCreationTracked"), isWidgetCreationTracked);
    registerServiceExtension(__s("screenshot"), [=] (Map<String, String> parameters) {
        assert(parameters->containsKey(__s("id")));
        assert(parameters->containsKey(__s("width")));
        assert(parameters->containsKey(__s("height")));
        Image image = await screenshot(toObject(parameters[__s("id")])double->parse(parameters[__s("width")]!), double->parse(parameters[__s("height")]!), parameters->containsKey(__s("margin"))? double->parse(parameters[__s("margin")]!) : 0.0, parameters->containsKey(__s("maxPixelRatio"))? double->parse(parameters[__s("maxPixelRatio")]!) : 1.0, parameters[__s("debugPaint")] == __s("true"));
        if (image == nullptr) {
                    Map<String, Object> map2 = make<MapCls<>>();        map2.set(__s("result"), nullptr);return list2;
        }
        ByteData byteData = await image->toByteData(ui->ImageByteFormatCls::png);
            Map<String, Object> map3 = make<MapCls<>>();    map3.set(__s("result"), base64->encoder->convert(Uint8ListCls->view(byteData!->buffer)));return list3;
    });
}

void WidgetInspectorServiceCls::disposeAllGroups() {
    _groups->clear();
    _idToReferenceData->clear();
    _objectToId->clear();
    _nextId = 0;
}

void WidgetInspectorServiceCls::resetAllState() {
    disposeAllGroups();
    selection->clear();
    resetPubRootDirectories();
}

void WidgetInspectorServiceCls::disposeGroup(String name) {
    Set<_InspectorReferenceData> references = _groups->remove(name);
    if (references == nullptr) {
        return;
    }
    references->forEach(_decrementReferenceCount);
}

String WidgetInspectorServiceCls::toId(String groupName, Object object) {
    if (object == nullptr) {
        return nullptr;
    }
    Set<_InspectorReferenceData> group = _groups->putIfAbsent(groupName, [=] () {
    <_InspectorReferenceData>identity();
});
    String id = _objectToId[object];
    _InspectorReferenceData referenceData;
    if (id == nullptr) {
        id = __s("inspector-$_nextId");
        _nextId = 1;
        _objectToId[object] = id;
        referenceData = make<_InspectorReferenceDataCls>(object);
        _idToReferenceData[id] = referenceData;
        group->add(referenceData);
    } else {
        referenceData = _idToReferenceData[id]!;
        if (group->add(referenceData)) {
            referenceData->count = 1;
        }
    }
    return id;
}

bool WidgetInspectorServiceCls::isWidgetTreeReady(String groupName) {
    return WidgetsBindingCls::instance != nullptr && WidgetsBindingCls::instance->debugDidSendFirstFrameEvent;
}

Object WidgetInspectorServiceCls::toObject(String groupName, String id) {
    if (id == nullptr) {
        return nullptr;
    }
    _InspectorReferenceData data = _idToReferenceData[id];
    if (data == nullptr) {
        ;
    }
    return data->object;
}

Object WidgetInspectorServiceCls::toObjectForSourceLocation(String groupName, String id) {
    Object object = toObject(id);
    if (is<Element>(object)) {
        return as<ElementCls>(object)->widget;
    }
    return object;
}

void WidgetInspectorServiceCls::disposeId(String groupName, String id) {
    if (id == nullptr) {
        return;
    }
    _InspectorReferenceData referenceData = _idToReferenceData[id];
    if (referenceData == nullptr) {
        ;
    }
    if (_groups[groupName]?->remove(referenceData) != true) {
        ;
    }
    _decrementReferenceCount(referenceData);
}

void WidgetInspectorServiceCls::setPubRootDirectories(List<String> pubRootDirectories) {
    addPubRootDirectories(pubRootDirectories);
}

void WidgetInspectorServiceCls::resetPubRootDirectories() {
    _pubRootDirectories = makeList();
    _isLocalCreationCache->clear();
}

void WidgetInspectorServiceCls::addPubRootDirectories(List<String> pubRootDirectories) {
    pubRootDirectories = pubRootDirectories-><String>map([=] (String directory)     {
        UriCls->parse(directory)->path;
    })->toList();
    Set<String> directorySet = <String>from(pubRootDirectories);
    if (_pubRootDirectories != nullptr) {
        directorySet->addAll(_pubRootDirectories!);
    }
    _pubRootDirectories = directorySet->toList();
    _isLocalCreationCache->clear();
}

void WidgetInspectorServiceCls::removePubRootDirectories(List<String> pubRootDirectories) {
    if (_pubRootDirectories == nullptr) {
        return;
    }
    pubRootDirectories = pubRootDirectories-><String>map([=] (String directory)     {
        UriCls->parse(directory)->path;
    })->toList();
    Set<String> directorySet = <String>from(_pubRootDirectories!);
    directorySet->removeAll(pubRootDirectories);
    _pubRootDirectories = directorySet->toList();
    _isLocalCreationCache->clear();
}

bool WidgetInspectorServiceCls::setSelectionById(String groupName, String id) {
    return setSelection(toObject(id), groupName);
}

bool WidgetInspectorServiceCls::setSelection(String groupName, Object object) {
    if (is<Element>(object) || is<RenderObject>(object)) {
        if (is<Element>(object)) {
            if (as<ElementCls>(object) == selection->currentElement) {
                return false;
            }
            selection->currentElement = as<ElementCls>(object);
            developer->inspect(selection->currentElement);
        } else {
            if (object == selection->current) {
                return false;
            }
            selection->current = as<RenderObject>(object!);
            developer->inspect(selection->current);
        }
        if (selectionChangedCallback != nullptr) {
            if (SchedulerBindingCls::instance->schedulerPhase == SchedulerPhaseCls::idle) {
                selectionChangedCallback!();
            } else {
                SchedulerBindingCls::instance->scheduleTask(selectionChangedCallback!, PriorityCls::touch);
            }
        }
        return true;
    }
    return false;
}

String WidgetInspectorServiceCls::devToolsInspectorUri(String inspectorRef) {
    assert(activeDevToolsServerAddress != nullptr);
    assert(connectedVmServiceUri != nullptr);
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("uri"), connectedVmServiceUri);map1.set(__s("inspectorRef"), inspectorRef);Uri uri = UriCls->parse(activeDevToolsServerAddress!)->replace(list1);
    String devToolsInspectorUri = uri->toString();
    int startQueryParamIndex = devToolsInspectorUri->indexOf(__s("?"));
    assert(startQueryParamIndex != -1);
    return __s("${devToolsInspectorUri.substring(0, startQueryParamIndex)}/#/inspector${devToolsInspectorUri.substring(startQueryParamIndex)}");
}

String WidgetInspectorServiceCls::getParentChain(String groupName, String id) {
    return _safeJsonEncode(_getParentChain(id, groupName));
}

String WidgetInspectorServiceCls::getProperties(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getProperties(diagnosticsNodeId, groupName));
}

String WidgetInspectorServiceCls::getChildren(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getChildren(diagnosticsNodeId, groupName));
}

String WidgetInspectorServiceCls::getChildrenSummaryTree(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getChildrenSummaryTree(diagnosticsNodeId, groupName));
}

String WidgetInspectorServiceCls::getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName) {
    return _safeJsonEncode(_getChildrenDetailsSubtree(diagnosticsNodeId, groupName));
}

String WidgetInspectorServiceCls::getRootWidget(String groupName) {
    return _safeJsonEncode(_getRootWidget(groupName));
}

String WidgetInspectorServiceCls::getRootWidgetSummaryTree(String groupName) {
    return _safeJsonEncode(_getRootWidgetSummaryTree(groupName));
}

String WidgetInspectorServiceCls::getRootRenderObject(String groupName) {
    return _safeJsonEncode(_getRootRenderObject(groupName));
}

String WidgetInspectorServiceCls::getDetailsSubtree(String groupName, String id, int subtreeDepth) {
    return _safeJsonEncode(_getDetailsSubtree(id, groupName, subtreeDepth));
}

String WidgetInspectorServiceCls::getSelectedRenderObject(String groupName, String previousSelectionId) {
    return _safeJsonEncode(_getSelectedRenderObject(previousSelectionId, groupName));
}

String WidgetInspectorServiceCls::getSelectedWidget(String groupName, String previousSelectionId) {
    return _safeJsonEncode(_getSelectedWidget(previousSelectionId, groupName));
}

Future<Image> WidgetInspectorServiceCls::screenshot(bool debugPaint, double height, double margin, double maxPixelRatio, Object object, double width) {
    if (!is<Element>(object) && !is<RenderObject>(object)) {
        return nullptr;
    }
    RenderObject renderObject = is<Element>(object)? object->renderObject : (as<RenderObject>(object));
    if (renderObject == nullptr || !renderObject->attached) {
        return nullptr;
    }
    if (renderObject->debugNeedsLayout()) {
        PipelineOwner owner = renderObject->owner!;
        assert(owner != nullptr);
        assert(!owner->debugDoingLayout());
            auto _c1 = owner;    _c1.auto _c2 = flushLayout();    _c2.auto _c3 = flushCompositingBits();    _c3.flushPaint();    _c3;    _c2;_c1;
        if (renderObject->debugNeedsLayout()) {
            return nullptr;
        }
    }
    Rect renderBounds = _calculateSubtreeBounds(renderObject);
    if (margin != 0.0) {
        renderBounds = renderBounds->inflate(margin);
    }
    if (renderBounds->isEmpty()) {
        return nullptr;
    }
    double pixelRatio = math->min(maxPixelRatio, math->min(width / renderBounds->width, height / renderBounds->height));
    return _ScreenshotPaintingContextCls->toImage(renderObject, renderBoundspixelRatio, debugPaint);
}

String WidgetInspectorServiceCls::getSelectedSummaryWidget(String groupName, String previousSelectionId) {
    return _safeJsonEncode(_getSelectedSummaryWidget(previousSelectionId, groupName));
}

bool WidgetInspectorServiceCls::isWidgetCreationTracked() {
    _widgetCreationTracked = is<_HasCreationLocation>(make<_WidgetForTypeTestsCls>());
    return _widgetCreationTracked!;
}

void WidgetInspectorServiceCls::postEvent(Map<Object, Object> eventData, String eventKind) {
    developer->postEvent(eventKind, eventData);
}

void WidgetInspectorServiceCls::performReassemble() {
    _clearStats();
    _resetErrorCount();
}

void WidgetInspectorServiceCls::_registerSignalServiceExtension(FutureOr<Object> callback() , String name) {
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("result"), await callback());return list1;
    });
}

void WidgetInspectorServiceCls::_registerObjectGroupServiceExtension(FutureOr<Object> callback(String objectGroup) , String name) {
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("result"), await callback(parameters[__s("objectGroup")]!));return list1;
    });
}

void WidgetInspectorServiceCls::_registerBoolServiceExtension(AsyncValueGetter<bool> getter, String name, AsyncValueSetter<bool> setter) {
    assert(name != nullptr);
    assert(getter != nullptr);
    assert(setter != nullptr);
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        if (parameters->containsKey(__s("enabled"))) {
            bool value = parameters[__s("enabled")] == __s("true");
            await await setter(value);
            _postExtensionStateChangedEvent(name, value);
        }
            Map<String, dynamic> map1 = make<MapCls<>>();    map1.set(__s("enabled"), await getter()? __s("true") : __s("false"));return list1;
    });
}

void WidgetInspectorServiceCls::_postExtensionStateChangedEvent(String name, Object value) {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("extension"), __s("ext.flutter.inspector.$name"));map1.set(__s("value"), value);postEvent(__s("Flutter.ServiceExtensionStateChanged"), list1);
}

void WidgetInspectorServiceCls::_registerServiceExtensionWithArg(FutureOr<Object> callback(String objectGroup, String objectId) , String name) {
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        assert(parameters->containsKey(__s("objectGroup")));
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("result"), await callback(parameters[__s("arg")], parameters[__s("objectGroup")]!));return list1;
    });
}

void WidgetInspectorServiceCls::_registerServiceExtensionVarArgs(FutureOr<Object> callback(List<String> args) , String name) {
    registerServiceExtension(name, [=] (Map<String, String> parameters) {
        List<String> args = makeList();
        int index = 0;
        while (true) {
            String name = __s("arg$index");
            if (parameters->containsKey(name)) {
                args->add(parameters[name]!);
            } else {
                                break;
            }
            index++;
        }
        assert(index == parameters->length || (index == parameters->length - 1 && parameters->containsKey(__s("isolateId"))));
            Map<String, Object> map1 = make<MapCls<>>();    map1.set(__s("result"), await callback(args));return list1;
    });
}

void WidgetInspectorServiceCls::_reportStructuredError(FlutterErrorDetails details) {
    Map<String, Object> errorJson = _nodeToJson(details->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(_consoleObjectGroup, 5, true, 5, this))!;
    errorJson[__s("errorsSinceReload")] = _errorsSinceReload;
    if (_errorsSinceReload == 0) {
        errorJson[__s("renderedErrorText")] = make<TextTreeRendererCls>(FlutterErrorCls::wrapWidth, 5)->render(details->toDiagnosticsNode(DiagnosticsTreeStyleCls::error))->trimRight();
    } else {
        errorJson[__s("renderedErrorText")] = __s("Another exception was thrown: ${details.summary}");
    }
    _errorsSinceReload = 1;
    postEvent(__s("Flutter.Error"), errorJson);
}

void WidgetInspectorServiceCls::_resetErrorCount() {
    _errorsSinceReload = 0;
}

void WidgetInspectorServiceCls::_clearStats() {
    _rebuildStats->resetCounts();
    _repaintStats->resetCounts();
}

void WidgetInspectorServiceCls::_decrementReferenceCount(_InspectorReferenceData reference) {
    reference->count = 1;
    assert(reference->count >= 0);
    if (reference->count == 0) {
        String id = _objectToId->remove(reference->object);
        assert(id != nullptr);
        _idToReferenceData->remove(id);
    }
}

String WidgetInspectorServiceCls::_devToolsInspectorUriForElement(Element element) {
    if (activeDevToolsServerAddress != nullptr && connectedVmServiceUri != nullptr) {
        String inspectorRef = toId(element, _consoleObjectGroup);
        if (inspectorRef != nullptr) {
            return devToolsInspectorUri(inspectorRef);
        }
    }
    return nullptr;
}

List<Object> WidgetInspectorServiceCls::_getParentChain(String groupName, String id) {
    Object value = toObject(id);
    List<_DiagnosticsPathNode> path;
    if (is<RenderObject>(value)) {
        path = _getRenderObjectParentChain(as<RenderObjectCls>(value), groupName)!;
    } else     {
        if (is<Element>(value)) {
        path = _getElementParentChain(as<ElementCls>(value), groupName);
    } else {
        ;
    }
;
    }    return path-><Object>map([=] (_DiagnosticsPathNode node)     {
        _pathNodeToJson(node, make<InspectorSerializationDelegateCls>(groupName, this));
    })->toList();
}

Map<String, Object> WidgetInspectorServiceCls::_pathNodeToJson(InspectorSerializationDelegate delegate, _DiagnosticsPathNode pathNode) {
    if (pathNode == nullptr) {
        return nullptr;
    }
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("node"), _nodeToJson(pathNode->node, delegate));map1.set(__s("children"), _nodesToJson(pathNode->children, delegatepathNode->node));map1.set(__s("childIndex"), pathNode->childIndex);return list1;
}

List<Element> WidgetInspectorServiceCls::_getRawElementParentChain(Element element, int numLocalParents) {
    List<Element> elements = element->debugGetDiagnosticChain();
    if (numLocalParents != nullptr) {
        for (;  < elements->length; i = 1) {
            if (_isValueCreatedByLocalProject(elements[i])) {
                numLocalParents = numLocalParents! - 1;
                if (numLocalParents <= 0) {
                    elements = elements->take(i + 1)->toList();
                                        break;
                }
            }
        }
    }
    return elements->reversed->toList();
}

List<_DiagnosticsPathNode> WidgetInspectorServiceCls::_getElementParentChain(Element element, String groupName, int numLocalParents) {
    return _followDiagnosticableChain(_getRawElementParentChain(elementnumLocalParents)) or makeList();
}

List<_DiagnosticsPathNode> WidgetInspectorServiceCls::_getRenderObjectParentChain(String groupName, RenderObject renderObject) {
    List<RenderObject> chain = makeList();
    while (renderObject != nullptr) {
        chain->add(renderObject);
        renderObject = as<RenderObject>(renderObject->parent);
    }
    return _followDiagnosticableChain(chain->reversed->toList());
}

Map<String, Object> WidgetInspectorServiceCls::_nodeToJson(InspectorSerializationDelegate delegate, DiagnosticsNode node) {
    return node?->toJsonMap(delegate);
}

bool WidgetInspectorServiceCls::_isValueCreatedByLocalProject(Object value) {
    _Location creationLocation = _getCreationLocation(value);
    if (creationLocation == nullptr) {
        return false;
    }
    return _isLocalCreationLocation(creationLocation->file);
}

bool WidgetInspectorServiceCls::_isLocalCreationLocationImpl(String locationUri) {
    String file = UriCls->parse(locationUri)->path;
    if (_pubRootDirectories == nullptr) {
        return !file->contains(__s("packages/flutter/"));
    }
    for (String directory : _pubRootDirectories!) {
        if (file->startsWith(directory)) {
            return true;
        }
    }
    return false;
}

bool WidgetInspectorServiceCls::_isLocalCreationLocation(String locationUri) {
    bool cachedValue = _isLocalCreationCache[locationUri];
    if (cachedValue != nullptr) {
        return cachedValue;
    }
    bool result = _isLocalCreationLocationImpl(locationUri);
    _isLocalCreationCache[locationUri] = result;
    return result;
}

String WidgetInspectorServiceCls::_safeJsonEncode(Object object) {
    String jsonString = json->encode(object);
    _serializeRing[_serializeRingIndex] = jsonString;
    _serializeRingIndex = (_serializeRingIndex + 1) % _serializeRing->length;
    return jsonString;
}

List<DiagnosticsNode> WidgetInspectorServiceCls::_truncateNodes(int maxDescendentsTruncatableNode, Iterable<DiagnosticsNode> nodes) {
    if (nodes->every([=] (DiagnosticsNode node)     {
        is<Element>(node->value);
    }) && isWidgetCreationTracked()) {
        List<DiagnosticsNode> localNodes = nodes->where([=] (DiagnosticsNode node) {
    _isValueCreatedByLocalProject(node->value);
})->toList();
        if (localNodes->isNotEmpty) {
            return localNodes;
        }
    }
    return nodes->take(maxDescendentsTruncatableNode)->toList();
}

List<Map<String, Object>> WidgetInspectorServiceCls::_nodesToJson(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes, DiagnosticsNode parent) {
    return DiagnosticsNodeCls->toJsonList(nodes, parent, delegate);
}

List<Object> WidgetInspectorServiceCls::_getProperties(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = as<DiagnosticsNode>(toObject(diagnosticsNodeId));
    return _nodesToJson(node == nullptr? makeList() : node->getProperties(), make<InspectorSerializationDelegateCls>(groupName, this)node);
}

List<Object> WidgetInspectorServiceCls::_getChildren(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = as<DiagnosticsNode>(toObject(diagnosticsNodeId));
    InspectorSerializationDelegate delegate = make<InspectorSerializationDelegateCls>(groupName, this);
    return _nodesToJson(node == nullptr? makeList() : _getChildrenFiltered(node, delegate), delegatenode);
}

List<Object> WidgetInspectorServiceCls::_getChildrenSummaryTree(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = as<DiagnosticsNode>(toObject(diagnosticsNodeId));
    InspectorSerializationDelegate delegate = make<InspectorSerializationDelegateCls>(groupName, true, this);
    return _nodesToJson(node == nullptr? makeList() : _getChildrenFiltered(node, delegate), delegatenode);
}

List<Object> WidgetInspectorServiceCls::_getChildrenDetailsSubtree(String diagnosticsNodeId, String groupName) {
    DiagnosticsNode node = as<DiagnosticsNode>(toObject(diagnosticsNodeId));
    InspectorSerializationDelegate delegate = make<InspectorSerializationDelegateCls>(groupName, true, this);
    return _nodesToJson(node == nullptr? makeList() : _getChildrenFiltered(node, delegate), delegatenode);
}

bool WidgetInspectorServiceCls::_shouldShowInSummaryTree(DiagnosticsNode node) {
    if (node->level == DiagnosticLevelCls::error) {
        return true;
    }
    Object value = node->value;
    if (!is<Diagnosticable>(value)) {
        return true;
    }
    if (!is<Element>(value) || !isWidgetCreationTracked()) {
        return true;
    }
    return _isValueCreatedByLocalProject(value);
}

List<DiagnosticsNode> WidgetInspectorServiceCls::_getChildrenFiltered(InspectorSerializationDelegate delegate, DiagnosticsNode node) {
    return _filterChildren(node->getChildren(), delegate);
}

List<DiagnosticsNode> WidgetInspectorServiceCls::_filterChildren(InspectorSerializationDelegate delegate, List<DiagnosticsNode> nodes) {
    List<DiagnosticsNode> list1 = make<ListCls<>>();for (DiagnosticsNode child : nodes) {    ;}{    list1.add(ArrayItem);}List<DiagnosticsNode> children = list1;
    return children;
}

Map<String, Object> WidgetInspectorServiceCls::_getRootWidget(String groupName) {
    return _nodeToJson(WidgetsBindingCls::instance->renderViewElement?->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(groupName, this));
}

Map<String, Object> WidgetInspectorServiceCls::_getRootWidgetSummaryTree(String groupName) {
    return _nodeToJson(WidgetsBindingCls::instance->renderViewElement?->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(groupName, 1000000, true, this));
}

Map<String, Object> WidgetInspectorServiceCls::_getRootRenderObject(String groupName) {
    return _nodeToJson(RendererBindingCls::instance->renderView->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(groupName, this));
}

Map<String, Object> WidgetInspectorServiceCls::_getDetailsSubtree(String groupName, String id, int subtreeDepth) {
    DiagnosticsNode root = as<DiagnosticsNode>(toObject(id));
    if (root == nullptr) {
        return nullptr;
    }
    return _nodeToJson(root, make<InspectorSerializationDelegateCls>(groupName, subtreeDepth, true, this));
}

Map<String, Object> WidgetInspectorServiceCls::_getSelectedRenderObject(String groupName, String previousSelectionId) {
    DiagnosticsNode previousSelection = as<DiagnosticsNode>(toObject(previousSelectionId));
    RenderObject current = selection->current;
    return _nodeToJson(current == previousSelection?->value? previousSelection : current?->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(groupName, this));
}

Map<String, Object> WidgetInspectorServiceCls::_getSelectedWidget(String groupName, String previousSelectionId) {
    DiagnosticsNode previousSelection = as<DiagnosticsNode>(toObject(previousSelectionId));
    Element current = selection->currentElement;
    return _nodeToJson(current == previousSelection?->value? previousSelection : current?->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(groupName, this));
}

Map<String, Object> WidgetInspectorServiceCls::_getSelectedSummaryWidget(String groupName, String previousSelectionId) {
    if (!isWidgetCreationTracked()) {
        return _getSelectedWidget(previousSelectionId, groupName);
    }
    DiagnosticsNode previousSelection = as<DiagnosticsNode>(toObject(previousSelectionId));
    Element current = selection->currentElement;
    if (current != nullptr && !_isValueCreatedByLocalProject(current)) {
        Element firstLocal;
        for (Element candidate : current->debugGetDiagnosticChain()) {
            if (_isValueCreatedByLocalProject(candidate)) {
                firstLocal = candidate;
                                break;
            }
        }
        current = firstLocal;
    }
    return _nodeToJson(current == previousSelection?->value? previousSelection : current?->toDiagnosticsNode(), make<InspectorSerializationDelegateCls>(groupName, this));
}

void WidgetInspectorServiceCls::_onFrameStart(Duration timeStamp) {
    _frameStart = timeStamp;
    SchedulerBindingCls::instance->addPostFrameCallback(_onFrameEnd);
}

void WidgetInspectorServiceCls::_onFrameEnd(Duration timeStamp) {
    if (_trackRebuildDirtyWidgets) {
        _postStatsEvent(__s("Flutter.RebuiltWidgets"), _rebuildStats);
    }
    if (_trackRepaintWidgets) {
        _postStatsEvent(__s("Flutter.RepaintWidgets"), _repaintStats);
    }
}

void WidgetInspectorServiceCls::_postStatsEvent(String eventName, _ElementLocationStatsTracker stats) {
    postEvent(eventName, stats->exportToJson(_frameStart));
}

void WidgetInspectorServiceCls::_onRebuildWidget(bool builtOnce, Element element) {
    _rebuildStats->add(element);
}

void WidgetInspectorServiceCls::_onPaint(RenderObject renderObject) {
    try {
        Element element = (as<DebugCreator>(renderObject->debugCreator))?->element;
        if (!is<RenderObjectElement>(element)) {
            return;
        }
        _repaintStats->add(element);
        element->visitAncestorElements([=] (Element ancestor) {
            if (is<RenderObjectElement>(ancestor)) {
                return false;
            }
            _repaintStats->add(ancestor);
            return true;
        });
    } catch (Unknown exception) {
        FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(exception, stack, __s("widget inspector library"), make<ErrorDescriptionCls>(__s("while tracking widget repaints"))));
    };
}

int _LocationCountCls::count() {
    return _count;
}

void _LocationCountCls::reset() {
    _count = 0;
}

void _LocationCountCls::increment() {
    _count++;
}

void _ElementLocationStatsTrackerCls::add(Element element) {
    Object widget = element->widget;
    if (!is<_HasCreationLocation>(widget)) {
        return;
    }
    _HasCreationLocation creationLocationSource = widget;
    _Location location = creationLocationSource->_location();
    int id = _toLocationId(location);
    _LocationCount entry;
    if (id >= _stats->length || _stats[id] == nullptr) {
        while (id >= _stats->length) {
            _stats->add(nullptr);
        }
        entry = make<_LocationCountCls>(location, id, WidgetInspectorServiceCls::instance->_isLocalCreationLocation(location->file));
        if (entry->local) {
            newLocations->add(entry);
        }
        _stats[id] = entry;
    } else {
        entry = _stats[id]!;
    }
    if (entry->local) {
        if (entry->count == 0) {
            active->add(entry);
        }
        entry->increment();
    }
}

void _ElementLocationStatsTrackerCls::resetCounts() {
    for (_LocationCount entry : active) {
        entry->reset();
    }
    active->clear();
}

Map<String, dynamic> _ElementLocationStatsTrackerCls::exportToJson(Duration startTime) {
    List<int> events = <int>filled(active->length * 2, 0);
    int j = 0;
    for (_LocationCount stat : active) {
        events[j++] = stat->id;
        events[j++] = stat->count;
    }
    Map<String, dynamic> map1 = make<MapCls<>>();map1.set(__s("startTime"), startTime->inMicroseconds());map1.set(__s("events"), events);Map<String, dynamic> json = list1;
    if (newLocations->isNotEmpty) {
        Map<String, List<int>> locationsJson = makeMap(makeList(), makeList();
        for (_LocationCount entry : newLocations) {
            _Location location = entry->location;
            List<int> jsonForFile = locationsJson->putIfAbsent(location->file, [=] () {
    makeList();
});
                    auto _c2 = jsonForFile;        _c2.auto _c3 = add(entry->id);        _c3.auto _c4 = add(location->line);        _c4.add(location->column);        _c4;        _c3;_c2;
        }
        json[__s("newLocations")] = locationsJson;
    }
    if (newLocations->isNotEmpty) {
        Map<String, Map<String, List<Object>>> fileLocationsMap = makeMap(makeList(), makeList();
        for (_LocationCount entry : newLocations) {
            _Location location = entry->location;
                    Map<String, List<Object>> map5 = make<MapCls<>>();        map5.set(__s("ids"), makeList());        map5.set(__s("lines"), makeList());        map5.set(__s("columns"), makeList());        map5.set(__s("names"), makeList());Map<String, List<Object>> locations = fileLocationsMap->putIfAbsent(location->file, [=] () {
    list5;
});
            locations[__s("ids")]!->add(entry->id);
            locations[__s("lines")]!->add(location->line);
            locations[__s("columns")]!->add(location->column);
            locations[__s("names")]!->add(location->name);
        }
        json[__s("locations")] = fileLocationsMap;
    }
    resetCounts();
    newLocations->clear();
    return json;
}

Element _WidgetForTypeTestsCls::createElement() {
    return ;
}

WidgetInspectorCls::WidgetInspectorCls(Widget child, Unknown key, InspectorSelectButtonBuilder selectButtonBuilder) {
    {
        assert(child != nullptr);
    }
}

State<WidgetInspector> WidgetInspectorCls::createState() {
    return make<_WidgetInspectorStateCls>();
}

void _WidgetInspectorStateCls::initState() {
    super->initState();
    _selectionChangedCallback = [=] () {
        setState([=] () {
        });
    };
    WidgetInspectorServiceCls::instance->selectionChangedCallback = _selectionChangedCallback;
}

void _WidgetInspectorStateCls::dispose() {
    if (WidgetInspectorServiceCls::instance->selectionChangedCallback == _selectionChangedCallback) {
        WidgetInspectorServiceCls::instance->selectionChangedCallback = nullptr;
    }
    super->dispose();
}

List<RenderObject> _WidgetInspectorStateCls::hitTest(Offset position, RenderObject root) {
    List<RenderObject> regularHits = makeList();
    List<RenderObject> edgeHits = makeList();
    _hitTestHelper(regularHits, edgeHits, position, root, root->getTransformTo(nullptr));
    InlineMethod;
    regularHits->sort([=] (RenderObject a,RenderObject b)     {
        area(a)->compareTo(area(b));
    });
    Set<RenderObject> set1 = make<SetCls<>>();for (auto _x1 : edgeHits) {{    set1.add(_x1);}for (auto _x1 : regularHits) {{    set1.add(_x1);}Set<RenderObject> hits = list1;
    return hits->toList();
}

Widget _WidgetInspectorStateCls::build(BuildContext context) {
    List<Widget> list1 = make<ListCls<>>();list1.add(ArrayItem);if (!isSelectMode && widget->selectButtonBuilder != nullptr) {    list1.add(ArrayItem);}list1.add(ArrayItem);return make<StackCls>(list1);
}

_WidgetInspectorStateCls::_WidgetInspectorStateCls() {
    {
        selection = WidgetInspectorServiceCls::instance->selection;
    }
}

bool _WidgetInspectorStateCls::_hitTestHelper(List<RenderObject> edgeHits, List<RenderObject> hits, RenderObject object, Offset position, Matrix4 transform) {
    bool hit = false;
    Matrix4 inverse = Matrix4Cls->tryInvert(transform);
    if (inverse == nullptr) {
        return false;
    }
    Offset localPosition = MatrixUtilsCls->transformPoint(inverse, position);
    List<DiagnosticsNode> children = object->debugDescribeChildren();
    for (; i >= 0; i = 1) {
        DiagnosticsNode diagnostics = children[i];
        assert(diagnostics != nullptr);
        if (diagnostics->style == DiagnosticsTreeStyleCls::offstage || !is<RenderObject>(diagnostics->value)) {
            continue;
        }
        RenderObject child = as<RenderObject>(diagnostics->value!);
        Rect paintClip = object->describeApproximatePaintClip(child);
        if (paintClip != nullptr && !paintClip->contains(localPosition)) {
            continue;
        }
        Matrix4 childTransform = transform->clone();
        object->applyPaintTransform(child, childTransform);
        if (_hitTestHelper(hits, edgeHits, position, child, childTransform)) {
            hit = true;
        }
    }
    Rect bounds = object->semanticBounds();
    if (bounds->contains(localPosition)) {
        hit = true;
        if (!bounds->deflate(_edgeHitMargin)->contains(localPosition)) {
            edgeHits->add(object);
        }
    }
    if (hit) {
        hits->add(object);
    }
    return hit;
}

void _WidgetInspectorStateCls::_inspectAt(Offset position) {
    if (!isSelectMode) {
        return;
    }
    RenderIgnorePointer ignorePointer = as<RenderIgnorePointer>(_ignorePointerKey->currentContext()!->findRenderObject()!);
    RenderObject userRender = ignorePointer->child!;
    List<RenderObject> selected = hitTest(position, userRender);
    setState([=] () {
        selection->candidates = selected;
    });
}

void _WidgetInspectorStateCls::_handlePanDown(DragDownDetails event) {
    _lastPointerLocation = event->globalPosition;
    _inspectAt(event->globalPosition);
}

void _WidgetInspectorStateCls::_handlePanUpdate(DragUpdateDetails event) {
    _lastPointerLocation = event->globalPosition;
    _inspectAt(event->globalPosition);
}

void _WidgetInspectorStateCls::_handlePanEnd(DragEndDetails details) {
    Rect bounds = (OffsetCls::zero & (WidgetsBindingCls::instance->window->physicalSize() / WidgetsBindingCls::instance->window->devicePixelRatio))->deflate(_kOffScreenMargin);
    if (!bounds->contains(_lastPointerLocation!)) {
        setState([=] () {
            selection->clear();
        });
    }
}

void _WidgetInspectorStateCls::_handleTap() {
    if (!isSelectMode) {
        return;
    }
    if (_lastPointerLocation != nullptr) {
        _inspectAt(_lastPointerLocation!);
        developer->inspect(selection->current);
    }
    setState([=] () {
        if (widget->selectButtonBuilder != nullptr) {
            isSelectMode = false;
        }
    });
}

void _WidgetInspectorStateCls::_handleEnableSelect() {
    setState([=] () {
        isSelectMode = true;
    });
}

List<RenderObject> InspectorSelectionCls::candidates() {
    return _candidates;
}

void InspectorSelectionCls::candidates(List<RenderObject> value) {
    _candidates = value;
    _index = 0;
    _computeCurrent();
}

int InspectorSelectionCls::index() {
    return _index;
}

void InspectorSelectionCls::index(int value) {
    _index = value;
    _computeCurrent();
}

void InspectorSelectionCls::clear() {
    _candidates = makeList();
    _index = 0;
    _computeCurrent();
}

RenderObject InspectorSelectionCls::current() {
    return active()? _current : nullptr;
}

void InspectorSelectionCls::current(RenderObject value) {
    if (_current != value) {
        _current = value;
        _currentElement = (as<DebugCreator>(value?->debugCreator))?->element;
    }
}

Element InspectorSelectionCls::currentElement() {
    return _currentElement?->debugIsDefunct() or true? nullptr : _currentElement;
}

void InspectorSelectionCls::currentElement(Element element) {
    if (element?->debugIsDefunct() or false) {
        _currentElement = nullptr;
        _current = nullptr;
        return;
    }
    if (currentElement() != element) {
        _currentElement = element;
        _current = element!->findRenderObject();
    }
}

bool InspectorSelectionCls::active() {
    return _current != nullptr && _current!->attached;
}

void InspectorSelectionCls::_computeCurrent() {
    if ( < candidates->length) {
        _current = candidates[index];
        _currentElement = (as<DebugCreator>(_current?->debugCreator))?->element;
    } else {
        _current = nullptr;
        _currentElement = nullptr;
    }
}

_RenderInspectorOverlay _InspectorOverlayCls::createRenderObject(BuildContext context) {
    return make<_RenderInspectorOverlayCls>(selection);
}

void _InspectorOverlayCls::updateRenderObject(BuildContext context, _RenderInspectorOverlay renderObject) {
    renderObject->selection = selection;
}

InspectorSelection _RenderInspectorOverlayCls::selection() {
    return _selection;
}

void _RenderInspectorOverlayCls::selection(InspectorSelection value) {
    if (value != _selection) {
        _selection = value;
    }
    markNeedsPaint();
}

bool _RenderInspectorOverlayCls::sizedByParent() {
    return true;
}

bool _RenderInspectorOverlayCls::alwaysNeedsCompositing() {
    return true;
}

Size _RenderInspectorOverlayCls::computeDryLayout(BoxConstraints constraints) {
    return constraints->constrain(SizeCls::infinite);
}

void _RenderInspectorOverlayCls::paint(PaintingContext context, Offset offset) {
    assert(needsCompositing);
    context->addLayer(make<_InspectorOverlayLayerCls>(RectCls->fromLTWH(offset->dx, offset->dy, size->width, size->height), selection, is<RenderObject>(parent)? as<RenderObject>(parent!) : nullptr));
}

_RenderInspectorOverlayCls::_RenderInspectorOverlayCls(InspectorSelection selection) {
    {
        _selection = selection;
        assert(selection != nullptr);
    }
}

bool _TransformedRectCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_TransformedRect>(other) && other->rect == rect && other->transform == transform;
}

int _TransformedRectCls::hashCode() {
    return ObjectCls->hash(rect, transform);
}

_TransformedRectCls::_TransformedRectCls(RenderObject ancestor, RenderObject object) {
    {
        rect = object->semanticBounds();
        transform = object->getTransformTo(ancestor);
    }
}

bool _InspectorOverlayRenderStateCls::==(Object other) {
    if (other->runtimeType() != runtimeType) {
        return false;
    }
    return is<_InspectorOverlayRenderState>(other) && other->overlayRect == overlayRect && other->selected == selected && <_TransformedRect>listEquals(other->candidates, candidates) && other->tooltip == tooltip;
}

int _InspectorOverlayRenderStateCls::hashCode() {
    return ObjectCls->hash(overlayRect, selected, ObjectCls->hashAll(candidates), tooltip);
}

void _InspectorOverlayLayerCls::addToScene(SceneBuilder builder) {
    if (!selection->active()) {
        return;
    }
    RenderObject selected = selection->current!;
    if (!_isInInspectorRenderObjectTree(selected)) {
        return;
    }
    List<_TransformedRect> candidates = makeList();
    for (RenderObject candidate : selection->candidates) {
        if (candidate == selected || !candidate->attached || !_isInInspectorRenderObjectTree(candidate)) {
            continue;
        }
        candidates->add(make<_TransformedRectCls>(candidate, rootRenderObject));
    }
    _InspectorOverlayRenderState state = make<_InspectorOverlayRenderStateCls>(overlayRect, make<_TransformedRectCls>(selected, rootRenderObject), selection->currentElement()!->toStringShort(), TextDirectionCls::ltr, candidates);
    if (state != _lastState) {
        _lastState = state;
        _picture = _buildPicture(state);
    }
    builder->addPicture(OffsetCls::zero, _picture);
}

bool _InspectorOverlayLayerCls::findAnnotationstemplate<typename S> (Offset localPosition, bool onlyFirst, AnnotationResult<S> result) {
    return false;
}

_InspectorOverlayLayerCls::_InspectorOverlayLayerCls(Rect overlayRect, RenderObject rootRenderObject, InspectorSelection selection) {
    {
        assert(overlayRect != nullptr);
        assert(selection != nullptr);
    }
    {
        bool inDebugMode = false;
        assert([=] () {
            inDebugMode = true;
            return true;
        }());
        if (inDebugMode == false) {
            ;
        }
    }
}

Picture _InspectorOverlayLayerCls::_buildPicture(_InspectorOverlayRenderState state) {
    PictureRecorder recorder = ui->make<PictureRecorderCls>();
    Canvas canvas = make<CanvasCls>(recorder, state->overlayRect);
    Size size = state->overlayRect->size;
    canvas->translate(state->overlayRect->left, state->overlayRect->top);
    auto _c1 = make<PaintCls>();_c1.style = auto _c2 = PaintingStyleCls::fill;_c2.color = _kHighlightedRenderObjectFillColor;_c2;Paint fillPaint = _c1;
    auto _c3 = make<PaintCls>();_c3.style = auto _c4 = PaintingStyleCls::stroke;_c4.strokeWidth = auto _c5 = 1.0;_c5.color = _kHighlightedRenderObjectBorderColor;_c5;_c4;Paint borderPaint = _c3;
    Rect selectedPaintRect = state->selected->rect->deflate(0.5);
    auto _c6 = canvas;_c6.auto _c7 = save();_c7.auto _c8 = transform(state->selected->transform->storage());_c8.auto _c9 = drawRect(selectedPaintRect, fillPaint);_c9.auto _c10 = drawRect(selectedPaintRect, borderPaint);_c10.restore();_c10;_c9;_c8;_c7;_c6;
    for (_TransformedRect transformedRect : state->candidates) {
            auto _c11 = canvas;    _c11.auto _c12 = save();    _c12.auto _c13 = transform(transformedRect->transform->storage());    _c13.auto _c14 = drawRect(transformedRect->rect->deflate(0.5), borderPaint);    _c14.restore();    _c14;    _c13;    _c12;_c11;
    }
    Rect targetRect = MatrixUtilsCls->transformRect(state->selected->transform, state->selected->rect);
    Offset target = make<OffsetCls>(targetRect->left, targetRect->center->dy);
    double offsetFromWidget = 9.0;
    double verticalOffset = (targetRect->height) / 2 + offsetFromWidget;
    _paintDescription(canvas, state->tooltip, state->textDirection, target, verticalOffset, size, targetRect);
    return recorder->endRecording();
}

void _InspectorOverlayLayerCls::_paintDescription(Canvas canvas, String message, Size size, Offset target, Rect targetRect, TextDirection textDirection, double verticalOffset) {
    canvas->save();
    double maxWidth = size->width - 2 * (_kScreenEdgeMargin + _kTooltipPadding);
    TextSpan textSpan = as<TextSpan>(_textPainter?->text);
    if (_textPainter == nullptr || textSpan!->text != message || _textPainterMaxWidth != maxWidth) {
        _textPainterMaxWidth = maxWidth;
            auto _c1 = make<TextPainterCls>();    _c1.maxLines = auto _c2 = _kMaxTooltipLines;    _c2.ellipsis = auto _c3 = __s("...");    _c3.text = auto _c4 = make<TextSpanCls>(_messageStyle, message);    _c4.textDirection = auto _c5 = textDirection;    _c5.layout(maxWidth);    _c5;    _c4;    _c3;    _c2;_textPainter = _c1;
    }
    Size tooltipSize = _textPainter!->size + make<OffsetCls>(_kTooltipPadding * 2, _kTooltipPadding * 2);
    Offset tipOffset = positionDependentBox(size, tooltipSize, target, verticalOffset, false);
    auto _c6 = make<PaintCls>();_c6.style = auto _c7 = PaintingStyleCls::fill;_c7.color = _kTooltipBackgroundColor;_c7;Paint tooltipBackground = _c6;
    canvas->drawRect(RectCls->fromPoints(tipOffset, tipOffset->translate(tooltipSize->width, tooltipSize->height)), tooltipBackground);
    double wedgeY = tipOffset->dy;
    bool tooltipBelow = tipOffset->dy > target->dy;
    if (!tooltipBelow) {
        wedgeY = tooltipSize->height;
    }
    double wedgeSize = _kTooltipPadding * 2;
    double wedgeX = math->max(tipOffset->dx, target->dx) + wedgeSize * 2;
    wedgeX = math->min(wedgeX, tipOffset->dx + tooltipSize->width - wedgeSize * 2);
    List<Offset> wedge = makeList(ArrayItem, ArrayItem, ArrayItem);
    auto _c8 = make<PathCls>();_c8.addPolygon(wedge, true);canvas->drawPath(_c8, tooltipBackground);
    _textPainter!->paint(canvas, tipOffset + make<OffsetCls>(_kTooltipPadding, _kTooltipPadding));
    canvas->restore();
}

bool _InspectorOverlayLayerCls::_isInInspectorRenderObjectTree(RenderObject child) {
    RenderObject current = as<RenderObject>(child->parent);
    while (current != nullptr) {
        if (is<RenderStack>(current) && is<_RenderInspectorOverlay>(current->lastChild)) {
            return rootRenderObject == current;
        }
        current = as<RenderObject>(current->parent);
    }
    return false;
}

Map<String, Object> _LocationCls::toJsonMap() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("file"), file);map1.set(__s("line"), line);map1.set(__s("column"), column);Map<String, Object> json = list1;
    if (name != nullptr) {
        json[__s("name")] = name;
    }
    return json;
}

String _LocationCls::toString() {
    List<String> parts = makeList();
    if (name != nullptr) {
        parts->add(name!);
    }
    parts->add(file);
    auto _c1 = parts;_c1.auto _c2 = add(__s("$line"));_c2.add(__s("$column"));_c2;_c1;
    return parts->join(__s(":"));
}

bool _isDebugCreator(DiagnosticsNode node) {
    return is<DiagnosticsDebugCreator>(node);
}

Iterable<DiagnosticsNode> debugTransformDebugCreator(Iterable<DiagnosticsNode> properties) {
    if (!kDebugMode) {
        return makeList();
    }
    List<DiagnosticsNode> pending = makeList();
    ErrorSummary errorSummary;
    for (DiagnosticsNode node : properties) {
        if (is<ErrorSummary>(node)) {
            errorSummary = as<ErrorSummaryCls>(node);
                        break;
        }
    }
    bool foundStackTrace = false;
    List<DiagnosticsNode> result = makeList();
    for (DiagnosticsNode node : properties) {
        if (!foundStackTrace && is<DiagnosticsStackTrace>(node)) {
            foundStackTrace = true;
        }
        if (_isDebugCreator(node)) {
            result->addAll(_parseDiagnosticsNode(node, errorSummary));
        } else {
            if (foundStackTrace) {
                pending->add(node);
            } else {
                result->add(node);
            }
        }
    }
    result->addAll(pending);
    return result;
}

Iterable<DiagnosticsNode> _parseDiagnosticsNode(ErrorSummary errorSummary, DiagnosticsNode node) {
    assert(_isDebugCreator(node));
    try {
        DebugCreator debugCreator = as<DebugCreator>(node->value!);
        Element element = debugCreator->element;
        return _describeRelevantUserCode(element, errorSummary);
    } catch (Unknown error) {
        scheduleMicrotask([=] () {
            FlutterErrorCls->reportError(make<FlutterErrorDetailsCls>(error, stack, __s("widget inspector"), [=] ()             {
                makeList(ArrayItem);
            }));
        });
        return makeList();
    };
}

Iterable<DiagnosticsNode> _describeRelevantUserCode(Element element, ErrorSummary errorSummary) {
    if (!WidgetInspectorServiceCls->instance->isWidgetCreationTracked()) {
        return makeList(ArrayItem, ArrayItem);
    }
    InlineMethod;
    List<DiagnosticsNode> nodes = makeList();
    InlineMethod;
    if (processElement(element)) {
        element->visitAncestorElements(processElement);
    }
    return nodes;
}

DevToolsDeepLinkPropertyCls::DevToolsDeepLinkPropertyCls(String description, String url) : DiagnosticsProperty<String>(__s(""), urldescription, DiagnosticLevelCls::info) {
    {
        assert(description != nullptr);
        assert(url != nullptr);
    }
}

bool debugIsLocalCreationLocation(Object object) {
    bool isLocal = false;
    assert([=] () {
        _Location location = _getCreationLocation(object);
        if (location != nullptr) {
            isLocal = WidgetInspectorServiceCls::instance->_isLocalCreationLocation(location->file);
        }
        return true;
    }());
    return isLocal;
}

bool debugIsWidgetLocalCreation(Widget widget) {
    _Location location = _getObjectCreationLocation(widget);
    return location != nullptr && WidgetInspectorServiceCls::instance->_isLocalCreationLocation(location->file);
}

String _describeCreationLocation(Object object) {
    _Location location = _getCreationLocation(object);
    return location?->toString();
}

_Location _getObjectCreationLocation(Object object) {
    return is<_HasCreationLocation>(object)? object->_location : nullptr;
}

_Location _getCreationLocation(Object object) {
    Object candidate = is<Element>(object) && !object->debugIsDefunct? object->widget : object;
    return candidate == nullptr? nullptr : _getObjectCreationLocation(candidate);
}

int _toLocationId(_Location location) {
    int id = _locationToId[location];
    if (id != nullptr) {
        return id;
    }
    id = _locations->length;
    _locations->add(location);
    _locationToId[location] = id;
    return id;
}

Map<String, Object> InspectorSerializationDelegateCls::additionalNodeProperties(DiagnosticsNode node) {
    Map<String, Object> result = makeMap(makeList(), makeList();
    Object value = node->value;
    if (_interactive()) {
        result[__s("objectId")] = service->toId(node, groupName!);
        result[__s("valueId")] = service->toId(value, groupName!);
    }
    if (summaryTree) {
        result[__s("summaryTree")] = true;
    }
    _Location creationLocation = _getCreationLocation(value);
    if (creationLocation != nullptr) {
        result[__s("locationId")] = _toLocationId(creationLocation);
        result[__s("creationLocation")] = creationLocation->toJsonMap();
        if (service->_isLocalCreationLocation(creationLocation->file)) {
            _nodesCreatedByLocalProject->add(node);
            result[__s("createdByLocalProject")] = true;
        }
    }
    if (addAdditionalPropertiesCallback != nullptr) {
        result->addAll(addAdditionalPropertiesCallback!(node, this) or makeMap(makeList(), makeList());
    }
    return result;
}

DiagnosticsSerializationDelegate InspectorSerializationDelegateCls::delegateForNode(DiagnosticsNode node) {
    return summaryTree || subtreeDepth > 1 || service->_shouldShowInSummaryTree(node)? copyWith(subtreeDepth - 1) : this;
}

List<DiagnosticsNode> InspectorSerializationDelegateCls::filterChildren(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    return service->_filterChildren(nodes, this);
}

List<DiagnosticsNode> InspectorSerializationDelegateCls::filterProperties(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    bool createdByLocalProject = _nodesCreatedByLocalProject->contains(owner);
    return nodes->where([=] (DiagnosticsNode node) {
        return !node->isFiltered(createdByLocalProject? DiagnosticLevelCls::fine : DiagnosticLevelCls::info);
    })->toList();
}

List<DiagnosticsNode> InspectorSerializationDelegateCls::truncateNodesList(List<DiagnosticsNode> nodes, DiagnosticsNode owner) {
    if (maxDescendentsTruncatableNode >= 0 && owner!->allowTruncate == true && nodes->length > maxDescendentsTruncatableNode) {
        nodes = service->_truncateNodes(nodes, maxDescendentsTruncatableNode);
    }
    return nodes;
}

DiagnosticsSerializationDelegate InspectorSerializationDelegateCls::copyWith(bool includeProperties, int subtreeDepth) {
    return make<InspectorSerializationDelegateCls>(groupName, summaryTree, maxDescendentsTruncatableNode, expandPropertyValues, subtreeDepth or this->subtreeDepth, includeProperties or this->includeProperties, service, addAdditionalPropertiesCallback);
}

bool InspectorSerializationDelegateCls::_interactive() {
    return groupName != nullptr;
}
