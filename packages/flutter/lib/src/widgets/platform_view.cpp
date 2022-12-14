#include "platform_view.hpp"
AndroidViewCls::AndroidViewCls(Clip clipBehavior, Object creationParams, MessageCodec<Object> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType) {
    {
        assert(viewType != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(creationParams == nullptr || creationParamsCodec != nullptr);
        assert(clipBehavior != nullptr);
    }
}

State<AndroidView> AndroidViewCls::createState() {
    return make<_AndroidViewStateCls>();
}

UiKitViewCls::UiKitViewCls(Object creationParams, MessageCodec<Object> creationParamsCodec, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key, TextDirection layoutDirection, PlatformViewCreatedCallback onPlatformViewCreated, String viewType) {
    {
        assert(viewType != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(creationParams == nullptr || creationParamsCodec != nullptr);
    }
}

State<UiKitView> UiKitViewCls::createState() {
    return make<_UiKitViewStateCls>();
}

HtmlElementViewCls::HtmlElementViewCls(Key key, PlatformViewCreatedCallback onPlatformViewCreated, String viewType) {
    {
        assert(viewType != nullptr);
        assert(kIsWeb, __s("HtmlElementView is only available on Flutter Web."));
    }
}

Widget HtmlElementViewCls::build(BuildContext context) {
    return make<PlatformViewLinkCls>(viewType, _createHtmlElementView, [=] (BuildContext context,PlatformViewController controller) {
        return make<PlatformViewSurfaceCls>(controller, makeSet(), PlatformViewHitTestBehaviorCls::opaque);
    });
}

_HtmlElementViewController HtmlElementViewCls::_createHtmlElementView(PlatformViewCreationParams params) {
    _HtmlElementViewController controller = make<_HtmlElementViewControllerCls>(params->id, viewType);
    controller->_initialize()->then([=] (Unknown  _) {
        params->onPlatformViewCreated(params->id);
        onPlatformViewCreated?->call(params->id);
    });
    return controller;
}

Future<void> _HtmlElementViewControllerCls::clearFocus() {
}

Future<void> _HtmlElementViewControllerCls::dispatchPointerEvent(PointerEvent event) {
}

Future<void> _HtmlElementViewControllerCls::dispose() {
    if (_initialized) {
        await SystemChannelsCls::platform_views-><void>invokeMethod(__s("dispose"), viewId);
    }
}

Future<void> _HtmlElementViewControllerCls::_initialize() {
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("id"), viewId);map1.set(__s("viewType"), viewType);Map<String, Object> args = list1;
    await SystemChannelsCls::platform_views-><void>invokeMethod(__s("create"), args);
    _initialized = true;
}

Widget _AndroidViewStateCls::build(BuildContext context) {
    return make<FocusCls>(_focusNode, _onFocusChange, make<_AndroidPlatformViewCls>(_controller, widget()->hitTestBehavior, widget()->gestureRecognizers | _emptyRecognizersSet, widget()->clipBehavior));
}

void _AndroidViewStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    _initializeOnce();
    if (didChangeLayoutDirection) {
        _controller->setLayoutDirection(_layoutDirection!);
    }
}

void _AndroidViewStateCls::didUpdateWidget(AndroidView oldWidget) {
    super->didUpdateWidget(oldWidget);
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    if (widget()->viewType != oldWidget->viewType) {
        _controller->dispose();
        _createNewAndroidView();
        return;
    }
    if (didChangeLayoutDirection) {
        _controller->setLayoutDirection(_layoutDirection!);
    }
}

void _AndroidViewStateCls::dispose() {
    _controller->dispose();
    super->dispose();
}

void _AndroidViewStateCls::_initializeOnce() {
    if (_initialized) {
        return;
    }
    _initialized = true;
    _createNewAndroidView();
    _focusNode = make<FocusNodeCls>(__sf("AndroidView(id: %s)", _id));
}

TextDirection _AndroidViewStateCls::_findLayoutDirection() {
    assert(widget()->layoutDirection != nullptr || debugCheckHasDirectionality(context()));
    return widget()->layoutDirection | DirectionalityCls->of(context());
}

void _AndroidViewStateCls::_createNewAndroidView() {
    _id = platformViewsRegistry->getNextPlatformViewId();
    _controller = PlatformViewsServiceCls->initAndroidView(_id!, widget()->viewType, _layoutDirection!, widget()->creationParams, widget()->creationParamsCodec, [=] () {
        _focusNode!->requestFocus();
    });
    if (widget()->onPlatformViewCreated != nullptr) {
        _controller->addOnPlatformViewCreatedListener(widget()->onPlatformViewCreated!);
    }
}

void _AndroidViewStateCls::_onFocusChange(bool isFocused) {
    if (!_controller->isCreated()) {
        return;
    }
    if (!isFocused) {
        _controller->clearFocus()->catchError([=] (Object e) {
            if (is<MissingPluginException>(e)) {
                return;
            }
        });
        return;
    }
    SystemChannelsCls::textInput-><void>invokeMethod(__s("TextInput.setPlatformViewClient"), list1)->catchError([=] (Object e) {
        if (is<MissingPluginException>(e)) {
                    Map<String, Object> map1 = make<MapCls<>>();        map1.set(__s("platformViewId"), _id);return;
        }
    });
}

Widget _UiKitViewStateCls::build(BuildContext context) {
    UiKitViewController controller = _controller;
    if (controller == nullptr) {
        return SizedBoxCls->expand();
    }
    return make<FocusCls>(_focusNode, [=] (bool isFocused) {
        _onFocusChange(isFocused, controller);
    }, make<_UiKitPlatformViewCls>(_controller!, widget()->hitTestBehavior, widget()->gestureRecognizers | _emptyRecognizersSet));
}

void _UiKitViewStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    _initializeOnce();
    if (didChangeLayoutDirection) {
        _controller?->setLayoutDirection(_layoutDirection!);
    }
}

void _UiKitViewStateCls::didUpdateWidget(UiKitView oldWidget) {
    super->didUpdateWidget(oldWidget);
    TextDirection newLayoutDirection = _findLayoutDirection();
    bool didChangeLayoutDirection = _layoutDirection != newLayoutDirection;
    _layoutDirection = newLayoutDirection;
    if (widget()->viewType != oldWidget->viewType) {
        _controller?->dispose();
        _createNewUiKitView();
        return;
    }
    if (didChangeLayoutDirection) {
        _controller?->setLayoutDirection(_layoutDirection!);
    }
}

void _UiKitViewStateCls::dispose() {
    _controller?->dispose();
    super->dispose();
}

void _UiKitViewStateCls::_initializeOnce() {
    if (_initialized) {
        return;
    }
    _initialized = true;
    _createNewUiKitView();
}

TextDirection _UiKitViewStateCls::_findLayoutDirection() {
    assert(widget()->layoutDirection != nullptr || debugCheckHasDirectionality(context()));
    return widget()->layoutDirection | DirectionalityCls->of(context());
}

Future<void> _UiKitViewStateCls::_createNewUiKitView() {
    int id = platformViewsRegistry->getNextPlatformViewId();
    UiKitViewController controller = await PlatformViewsServiceCls->initUiKitView(id, widget()->viewType, _layoutDirection!, widget()->creationParams, widget()->creationParamsCodec, [=] () {
    _focusNode->requestFocus();
});
    if (!mounted()) {
        controller->dispose();
        return;
    }
    widget()->onPlatformViewCreated?->call(id);
    setState([=] () {
        _controller = controller;
        _focusNode = make<FocusNodeCls>(__sf("UiKitView(id: %s)", id));
    });
}

void _UiKitViewStateCls::_onFocusChange(bool isFocused, UiKitViewController controller) {
    if (!isFocused) {
        return;
    }
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("platformViewId"), controller->id);SystemChannelsCls::textInput-><void>invokeMethod(__s("TextInput.setPlatformViewClient"), list1);
}

RenderObject _AndroidPlatformViewCls::createRenderObject(BuildContext context) {
    return make<RenderAndroidViewCls>(controller, hitTestBehavior, gestureRecognizers, clipBehavior);
}

void _AndroidPlatformViewCls::updateRenderObject(BuildContext context, RenderAndroidView renderObject) {
    renderObject->controller = controller;
    renderObject->hitTestBehavior = hitTestBehavior;
    renderObject->updateGestureRecognizers(gestureRecognizers);
    renderObject->clipBehavior = clipBehavior;
}

_AndroidPlatformViewCls::_AndroidPlatformViewCls(Clip clipBehavior, AndroidViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
        assert(clipBehavior != nullptr);
    }
}

RenderObject _UiKitPlatformViewCls::createRenderObject(BuildContext context) {
    return make<RenderUiKitViewCls>(controller, hitTestBehavior, gestureRecognizers);
}

void _UiKitPlatformViewCls::updateRenderObject(BuildContext context, RenderUiKitView renderObject) {
    renderObject->viewController() = controller;
    renderObject->hitTestBehavior = hitTestBehavior;
    renderObject->updateGestureRecognizers(gestureRecognizers);
}

_UiKitPlatformViewCls::_UiKitPlatformViewCls(UiKitViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
    }
}

void PlatformViewCreationParamsCls::_(Unknown id, Unknown onFocusChanged, Unknown onPlatformViewCreated, Unknown viewType)

PlatformViewLinkCls::PlatformViewLinkCls(Key key, CreatePlatformViewCallback onCreatePlatformView, PlatformViewSurfaceFactory surfaceFactory, String viewType) {
    {
        assert(surfaceFactory != nullptr);
        assert(onCreatePlatformView != nullptr);
        assert(viewType != nullptr);
        _surfaceFactory = surfaceFactory;
        _onCreatePlatformView = onCreatePlatformView;
    }
}

State<StatefulWidget> PlatformViewLinkCls::createState() {
    return make<_PlatformViewLinkStateCls>();
}

Widget _PlatformViewLinkStateCls::build(BuildContext context) {
    PlatformViewController controller = _controller;
    if (controller == nullptr) {
        return SizedBoxCls->expand();
    }
    if (!_platformViewCreated) {
        return make<_PlatformViewPlaceHolderCls>([=] (Size size) {
            if (controller->awaitingCreation()) {
                controller->create(size);
            }
        });
    }
    _surface |= widget()->_surfaceFactory(context, controller);
    return make<FocusCls>(_focusNode, _handleFrameworkFocusChanged, _surface!);
}

void _PlatformViewLinkStateCls::initState() {
    _focusNode = make<FocusNodeCls>(__sf("PlatformView(id: %s)", _id));
    _initialize();
    super->initState();
}

void _PlatformViewLinkStateCls::didUpdateWidget(PlatformViewLink oldWidget) {
    super->didUpdateWidget(oldWidget);
    if (widget()->viewType != oldWidget->viewType) {
        _controller?->dispose();
        _surface = nullptr;
        _initialize();
    }
}

void _PlatformViewLinkStateCls::dispose() {
    _controller?->dispose();
    _controller = nullptr;
    super->dispose();
}

void _PlatformViewLinkStateCls::_initialize() {
    _id = platformViewsRegistry->getNextPlatformViewId();
    _controller = widget()->_onCreatePlatformView(PlatformViewCreationParamsCls->_(_id!, widget()->viewType, _onPlatformViewCreated, _handlePlatformFocusChanged));
}

void _PlatformViewLinkStateCls::_onPlatformViewCreated(int id) {
    setState([=] () {
        _platformViewCreated = true;
    });
}

void _PlatformViewLinkStateCls::_handleFrameworkFocusChanged(bool isFocused) {
    if (!isFocused) {
        _controller?->clearFocus();
    }
    Map<String, Object> map1 = make<MapCls<>>();map1.set(__s("platformViewId"), _id);SystemChannelsCls::textInput-><void>invokeMethod(__s("TextInput.setPlatformViewClient"), list1);
}

void _PlatformViewLinkStateCls::_handlePlatformFocusChanged(bool isFocused) {
    if (isFocused) {
        _focusNode!->requestFocus();
    }
}

PlatformViewSurfaceCls::PlatformViewSurfaceCls(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
    }
}

RenderObject PlatformViewSurfaceCls::createRenderObject(BuildContext context) {
    return make<PlatformViewRenderBoxCls>(controller, gestureRecognizers, hitTestBehavior);
}

void PlatformViewSurfaceCls::updateRenderObject(BuildContext context, PlatformViewRenderBox renderObject) {
    auto _c1 = renderObject;_c1.controller = auto _c2 = controller;_c2.hitTestBehavior = auto _c3 = hitTestBehavior;_c3.updateGestureRecognizers(gestureRecognizers);_c3;_c2;_c1;
}

AndroidViewSurfaceCls::AndroidViewSurfaceCls(PlatformViewController controller, Set<Factory<OneSequenceGestureRecognizer>> gestureRecognizers, PlatformViewHitTestBehavior hitTestBehavior, Key key) {
    {
        assert(controller != nullptr);
        assert(hitTestBehavior != nullptr);
        assert(gestureRecognizers != nullptr);
    }
}

RenderObject AndroidViewSurfaceCls::createRenderObject(BuildContext context) {
    AndroidViewController viewController = as<AndroidViewController>(controller);
    if (is<ExpensiveAndroidViewController>(viewController)) {
        PlatformViewRenderBox renderBox = as<PlatformViewRenderBox>(super->createRenderObject(context));
        as<ExpensiveAndroidViewControllerCls>(viewController)->pointTransformer() = [=] (Offset position) {
            renderBox->globalToLocal(position);
        };
        return renderBox;
    }
    RenderAndroidView renderBox = make<RenderAndroidViewCls>(viewController, gestureRecognizers, hitTestBehavior);
    viewController->pointTransformer() = [=] (Offset position) {
        renderBox->globalToLocal(position);
    };
    return renderBox;
}

void _PlatformViewPlaceholderBoxCls::performLayout() {
    super->performLayout();
    onLayout(size());
}

_PlatformViewPlaceholderBoxCls::_PlatformViewPlaceholderBoxCls(_OnLayoutCallback onLayout) : RenderConstrainedBox(BoxConstraintsCls->tightFor(double->infinity, double->infinity)) {
}

_PlatformViewPlaceholderBox _PlatformViewPlaceHolderCls::createRenderObject(BuildContext context) {
    return make<_PlatformViewPlaceholderBoxCls>(onLayout);
}

void _PlatformViewPlaceHolderCls::updateRenderObject(BuildContext context, _PlatformViewPlaceholderBox renderObject) {
    renderObject->onLayout = onLayout;
}
