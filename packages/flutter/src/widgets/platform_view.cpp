#include "platform_view.hpp"
AndroidView::AndroidView(Clip clipBehavior, dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Unknown, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType) {
    {
        assert(viewType != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(creationParams == nullptr || creationParamsCodec != nullptr);
        assert(clipBehavior != nullptr);
    }
}

State<AndroidView> AndroidView::createState() {
    return _AndroidViewState();
}

UiKitView::UiKitView(dynamic creationParams, MessageCodec<dynamic> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Unknown, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType) {
    {
        assert(viewType != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(creationParams == nullptr || creationParamsCodec != nullptr);
    }
}

State<UiKitView> UiKitView::createState() {
    return _UiKitViewState();
}

HtmlElementView::HtmlElementView(Unknown, PlatformViewCreatedCallback onPlatformViewCreated, String viewType) {
    {
        assert(viewType != nullptr);
        assert(kIsWeb, "HtmlElementView is only available on Flutter Web.");
    }
}

Widget HtmlElementView::build(BuildContext context) {
    return PlatformViewLink(viewType, _createHtmlElementView, );
}

_HtmlElementViewController HtmlElementView::_createHtmlElementView(PlatformViewCreationParams params) {
    _HtmlElementViewController controller = _HtmlElementViewController(params.id, viewType);
    controller._initialize().then();
    return controller;
}

Future<void> _HtmlElementViewController::clearFocus() {
}

Future<void> _HtmlElementViewController::dispatchPointerEvent(PointerEvent event) {
}

Future<void> _HtmlElementViewController::dispose() {
    if (_initialized) {
        await await SystemChannels.platform_views.<void>invokeMethod("dispose", viewId);
    }
}

Future<void> _HtmlElementViewController::_initialize() {
    Map<String, dynamic> args = ;
    await await SystemChannels.platform_views.<void>invokeMethod("create", args);
    _initialized = true;
}

Widget _AndroidViewState::build(BuildContext context) {
    return Focus(_focusNode, _onFocusChange, _AndroidPlatformView(_controller, widget.hitTestBehavior, widget.gestureRecognizers ?? _emptyRecognizersSet, widget.clipBehavior));
}

void _AndroidViewState::didChangeDependencies() {
    super.didChangeDependencies();
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    _initializeOnce();
    if (didChangeLayoutDirection) {
        _controller.setLayoutDirection(_layoutDirection!);
    }
}

void _AndroidViewState::didUpdateWidget(AndroidView oldWidget) {
    super.didUpdateWidget(oldWidget);
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    if (widget.viewType != oldWidget.viewType) {
        _controller.dispose();
        _createNewAndroidView();
        return;
    }
    if (didChangeLayoutDirection) {
        _controller.setLayoutDirection(_layoutDirection!);
    }
}

void _AndroidViewState::dispose() {
    _controller.dispose();
    super.dispose();
}

void _AndroidViewState::_initializeOnce() {
    if (_initialized) {
        return;
    }
    _initialized = true;
    _createNewAndroidView();
    _focusNode = FocusNode("AndroidView(id: $_id)");
}

TextDirection _AndroidViewState::_findLayoutDirection() {
    assert(widget.layoutDirection != nullptr || debugCheckHasDirectionality(context));
    return widget.layoutDirection ?? Directionality.of(context);
}

void _AndroidViewState::_createNewAndroidView() {
    _id = platformViewsRegistry.getNextPlatformViewId();
    _controller = PlatformViewsService.initAndroidView(_id!, widget.viewType, _layoutDirection!, widget.creationParams, widget.creationParamsCodec, );
    if (widget.onPlatformViewCreated != nullptr) {
        _controller.addOnPlatformViewCreatedListener(widget.onPlatformViewCreated!);
    }
}

void _AndroidViewState::_onFocusChange(bool isFocused) {
    if (!_controller.isCreated) {
        return;
    }
    if (!isFocused) {
        _controller.clearFocus().catchError();
        return;
    }
    SystemChannels.textInput.<void>invokeMethod("TextInput.setPlatformViewClient", ).catchError();
}

Widget _UiKitViewState::build(BuildContext context) {
    UiKitViewController controller = _controller;
    if (controller == nullptr) {
        return const SizedBox.expand();
    }
    return Focus(_focusNode, , _UiKitPlatformView(_controller!, widget.hitTestBehavior, widget.gestureRecognizers ?? _emptyRecognizersSet));
}

void _UiKitViewState::didChangeDependencies() {
    super.didChangeDependencies();
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    _initializeOnce();
    if (didChangeLayoutDirection) {
        _controller?.setLayoutDirection(_layoutDirection!);
    }
}

void _UiKitViewState::didUpdateWidget(UiKitView oldWidget) {
    super.didUpdateWidget(oldWidget);
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    if (widget.viewType != oldWidget.viewType) {
        _controller?.dispose();
        _createNewUiKitView();
        return;
    }
    if (didChangeLayoutDirection) {
        _controller?.setLayoutDirection(_layoutDirection!);
    }
}

void _UiKitViewState::dispose() {
    _controller?.dispose();
    super.dispose();
}

void _UiKitViewState::_initializeOnce() {
    if (_initialized) {
        return;
    }
    _initialized = true;
    _createNewUiKitView();
}

TextDirection _UiKitViewState::_findLayoutDirection() {
    assert(widget.layoutDirection != nullptr || debugCheckHasDirectionality(context));
    return widget.layoutDirection ?? Directionality.of(context);
}

Future<void> _UiKitViewState::_createNewUiKitView() {
    int id = platformViewsRegistry.getNextPlatformViewId();
    UiKitViewController controller = await PlatformViewsService.initUiKitView(id, widget.viewType, _layoutDirection!, widget.creationParams, widget.creationParamsCodec, );
    if (!mounted) {
        controller.dispose();
        return;
    }
    widget.onPlatformViewCreated?.call(id);
    setState();
}

void _UiKitViewState::_onFocusChange(UiKitViewController controller, bool isFocused) {
    if (!isFocused) {
        return;
    }
    SystemChannels.textInput.<void>invokeMethod("TextInput.setPlatformViewClient", );
}

RenderObject _AndroidPlatformView::createRenderObject(BuildContext context) {
    return RenderAndroidView(controller, hitTestBehavior, gestureRecognizers, clipBehavior);
}

void _AndroidPlatformView::updateRenderObject(BuildContext context, RenderAndroidView renderObject) {
    renderObject.controller = controller;
    renderObject.hitTestBehavior = hitTestBehavior;
    renderObject.updateGestureRecognizers(gestureRecognizers);
    renderObject.clipBehavior = clipBehavior;
}

_AndroidPlatformView::_AndroidPlatformView(Clip clipBehavior, AndroidViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderObject _UiKitPlatformView::createRenderObject(BuildContext context) {
    return RenderUiKitView(controller, hitTestBehavior, gestureRecognizers);
}

void _UiKitPlatformView::updateRenderObject(BuildContext context, RenderUiKitView renderObject) {
    renderObject.viewController = controller;
    renderObject.hitTestBehavior = hitTestBehavior;
    renderObject.updateGestureRecognizers(gestureRecognizers);
}

_UiKitPlatformView::_UiKitPlatformView(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
    }
}

void PlatformViewCreationParams::_(int id, ValueChanged<bool> onFocusChanged, PlatformViewCreatedCallback onPlatformViewCreated, String viewType)

PlatformViewLink::PlatformViewLink(Unknown, CreatePlatformViewCallback onCreatePlatformView, PlatformViewSurfaceFactory surfaceFactory, String viewType) {
    {
        assert(surfaceFactory != nullptr);
        assert(onCreatePlatformView != nullptr);
        assert(viewType != nullptr);
        _surfaceFactory = surfaceFactory;
        _onCreatePlatformView = onCreatePlatformView;
    }
}

State<StatefulWidget> PlatformViewLink::createState() {
    return _PlatformViewLinkState();
}

Widget _PlatformViewLinkState::build(BuildContext context) {
    PlatformViewController controller = _controller;
    if (controller == nullptr) {
        return const SizedBox.expand();
    }
    if (!_platformViewCreated) {
        return _PlatformViewPlaceHolder();
    }
    _surface = widget._surfaceFactory(context, controller);
    return Focus(_focusNode, _handleFrameworkFocusChanged, _surface!);
}

void _PlatformViewLinkState::initState() {
    _focusNode = FocusNode("PlatformView(id: $_id)");
    _initialize();
    super.initState();
}

void _PlatformViewLinkState::didUpdateWidget(PlatformViewLink oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (widget.viewType != oldWidget.viewType) {
        _controller?.dispose();
        _surface = nullptr;
        _initialize();
    }
}

void _PlatformViewLinkState::dispose() {
    _controller?.dispose();
    _controller = nullptr;
    super.dispose();
}

void _PlatformViewLinkState::_initialize() {
    _id = platformViewsRegistry.getNextPlatformViewId();
    _controller = widget._onCreatePlatformView(PlatformViewCreationParams._(_id!, widget.viewType, _onPlatformViewCreated, _handlePlatformFocusChanged));
}

void _PlatformViewLinkState::_onPlatformViewCreated(int id) {
    setState();
}

void _PlatformViewLinkState::_handleFrameworkFocusChanged(bool isFocused) {
    if (!isFocused) {
        _controller?.clearFocus();
    }
    SystemChannels.textInput.<void>invokeMethod("TextInput.setPlatformViewClient", );
}

void _PlatformViewLinkState::_handlePlatformFocusChanged(bool isFocused) {
    if (isFocused) {
        _focusNode!.requestFocus();
    }
}

PlatformViewSurface::PlatformViewSurface(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Unknown) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
    }
}

RenderObject PlatformViewSurface::createRenderObject(BuildContext context) {
    return PlatformViewRenderBox(controller, gestureRecognizers, hitTestBehavior);
}

void PlatformViewSurface::updateRenderObject(BuildContext context, PlatformViewRenderBox renderObject) {
    ;
}

AndroidViewSurface::AndroidViewSurface(AndroidViewController controller, Unknown, Unknown, Unknown) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
    }
}

RenderObject AndroidViewSurface::createRenderObject(BuildContext context) {
    AndroidViewController viewController = (;
    if (viewController is ExpensiveAndroidViewController) {
        PlatformViewRenderBox renderBox = (;
        viewController.pointTransformer = ;
        return renderBox;
    }
    RenderAndroidView renderBox = RenderAndroidView(viewController, gestureRecognizers, hitTestBehavior);
    viewController.pointTransformer = ;
    return renderBox;
}

void _PlatformViewPlaceholderBox::performLayout() {
    super.performLayout();
    onLayout(size);
}

_PlatformViewPlaceholderBox::_PlatformViewPlaceholderBox(_OnLayoutCallback onLayout) {
    {
        super(const BoxConstraints.tightFor(double.infinity, double.infinity));
    }
}

_PlatformViewPlaceholderBox _PlatformViewPlaceHolder::createRenderObject(BuildContext context) {
    return _PlatformViewPlaceholderBox(onLayout);
}

void _PlatformViewPlaceHolder::updateRenderObject(BuildContext context, _PlatformViewPlaceholderBox renderObject) {
    renderObject.onLayout = onLayout;
}
