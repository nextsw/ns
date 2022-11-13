#include "ticker_provider.hpp"
TickerModeCls::TickerModeCls(Widget child, bool enabled, Key key) {
    {
        assert(enabled != nullptr);
    }
}

bool TickerModeCls::of(BuildContext context) {
    _EffectiveTickerMode widget = context-><_EffectiveTickerMode>dependOnInheritedWidgetOfExactType();
    return widget?->enabled | true;
}

ValueNotifier<bool> TickerModeCls::getNotifier(BuildContext context) {
    _EffectiveTickerMode widget = as<_EffectiveTickerMode>(context-><_EffectiveTickerMode>getElementForInheritedWidgetOfExactType()?->widget());
    return widget?->notifier | <bool>make<ValueNotifierCls>(true);
}

State<TickerMode> TickerModeCls::createState() {
    return make<_TickerModeStateCls>();
}

void _TickerModeStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _ancestorTicketMode = TickerModeCls->of(context());
    _updateEffectiveMode();
}

void _TickerModeStateCls::didUpdateWidget(TickerMode oldWidget) {
    super->didUpdateWidget(oldWidget);
    _updateEffectiveMode();
}

void _TickerModeStateCls::dispose() {
    _effectiveMode->dispose();
    super->dispose();
}

Widget _TickerModeStateCls::build(BuildContext context) {
    return make<_EffectiveTickerModeCls>(_effectiveMode->value(), _effectiveMode, widget()->child);
}

void _TickerModeStateCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("requested mode"), widget()->enabled, __s("enabled"), __s("disabled"), true));
}

void _TickerModeStateCls::_updateEffectiveMode() {
    _effectiveMode->value() = _ancestorTicketMode && widget()->enabled;
}

bool _EffectiveTickerModeCls::updateShouldNotify(_EffectiveTickerMode oldWidget) {
    return enabled != oldWidget->enabled;
}

void _EffectiveTickerModeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>(__s("effective mode"), enabled, __s("enabled"), __s("disabled"), true));
}

_EffectiveTickerModeCls::_EffectiveTickerModeCls(Widget child, bool enabled, ValueNotifier<bool> notifier) {
    {
        assert(enabled != nullptr);
    }
}

template<typename T>
Ticker SingleTickerProviderStateMixinCls<T>::createTicker(TickerCallback onTick) {
    assert([=] () {
        if (_ticker == nullptr) {
            return true;
        }
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem));
    }());
    _ticker = make<TickerCls>(onTick, kDebugMode? __sf("created by %s", describeIdentity(this)) : nullptr);
    _updateTickerModeNotifier();
    _updateTicker();
    return _ticker!;
}

template<typename T>
void SingleTickerProviderStateMixinCls<T>::dispose() {
    assert([=] () {
        if (_ticker == nullptr || !_ticker!->isActive()) {
            return true;
        }
        throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
    }());
    _tickerModeNotifier?->removeListener(_updateTicker);
    _tickerModeNotifier = nullptr;
    super->dispose();
}

template<typename T>
void SingleTickerProviderStateMixinCls<T>::activate() {
    super->activate();
    _updateTickerModeNotifier();
    _updateTicker();
}

template<typename T>
void SingleTickerProviderStateMixinCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    String tickerDescription;
    if (_ticker != nullptr) {
        if (_ticker!->isActive() && _ticker!->muted()) {
            tickerDescription = __s("active but muted");
        } else {
            if (_ticker!->isActive()) {
            tickerDescription = __s("active");
        } else {
            if (_ticker!->muted()) {
            tickerDescription = __s("inactive and muted");
        } else {
            tickerDescription = __s("inactive");
        }
;
        };
        }    }
    properties->add(<Ticker>make<DiagnosticsPropertyCls>(__s("ticker"), _ticker, tickerDescription, false, nullptr));
}

template<typename T>
void SingleTickerProviderStateMixinCls<T>::_updateTicker() {
    if (_ticker != nullptr) {
        _ticker!->muted() = !_tickerModeNotifier!->value();
    }
}

template<typename T>
void SingleTickerProviderStateMixinCls<T>::_updateTickerModeNotifier() {
    ValueNotifier<bool> newNotifier = TickerModeCls->getNotifier(context);
    if (newNotifier == _tickerModeNotifier) {
        return;
    }
    _tickerModeNotifier?->removeListener(_updateTicker);
    newNotifier->addListener(_updateTicker);
    _tickerModeNotifier = newNotifier;
}

template<typename T>
Ticker TickerProviderStateMixinCls<T>::createTicker(TickerCallback onTick) {
    if (_tickerModeNotifier == nullptr) {
        _updateTickerModeNotifier();
    }
    assert(_tickerModeNotifier != nullptr);
    _tickers |= makeSet();
    auto _c1 = make<_WidgetTickerCls>(onTick, this, kDebugMode? __sf("created by %s", describeIdentity(this)) : nullptr);_c1.muted = !_tickerModeNotifier!->value();_WidgetTicker result = _c1;
    _tickers!->add(result);
    return result;
}

template<typename T>
void TickerProviderStateMixinCls<T>::activate() {
    super->activate();
    _updateTickerModeNotifier();
    _updateTickers();
}

template<typename T>
void TickerProviderStateMixinCls<T>::dispose() {
    assert([=] () {
        if (_tickers != nullptr) {
            for (Ticker ticker : _tickers!) {
                if (ticker->isActive) {
                    throw FlutterErrorCls->fromParts(makeList(ArrayItem, ArrayItem, ArrayItem, ArrayItem));
                }
            }
        }
        return true;
    }());
    _tickerModeNotifier?->removeListener(_updateTickers);
    _tickerModeNotifier = nullptr;
    super->dispose();
}

template<typename T>
void TickerProviderStateMixinCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Set<Ticker>>make<DiagnosticsPropertyCls>(__s("tickers"), _tickers, _tickers != nullptr? __sf("tracking %s ticker%s", _tickers!->length(), _tickers!->length() == 1? __s("") : __s("s")) : nullptr, nullptr));
}

template<typename T>
void TickerProviderStateMixinCls<T>::_removeTicker(_WidgetTicker ticker) {
    assert(_tickers != nullptr);
    assert(_tickers!->contains(ticker));
    _tickers!->remove(ticker);
}

template<typename T>
void TickerProviderStateMixinCls<T>::_updateTickers() {
    if (_tickers != nullptr) {
        bool muted = !_tickerModeNotifier!->value();
        for (Ticker ticker : _tickers!) {
            ticker->muted = muted;
        }
    }
}

template<typename T>
void TickerProviderStateMixinCls<T>::_updateTickerModeNotifier() {
    ValueNotifier<bool> newNotifier = TickerModeCls->getNotifier(context);
    if (newNotifier == _tickerModeNotifier) {
        return;
    }
    _tickerModeNotifier?->removeListener(_updateTickers);
    newNotifier->addListener(_updateTickers);
    _tickerModeNotifier = newNotifier;
}

void _WidgetTickerCls::dispose() {
    _creator->_removeTicker(this);
    super->dispose();
}

_WidgetTickerCls::_WidgetTickerCls(TickerCallback onTick, TickerProviderStateMixin<any> _creator, String debugLabel) : Ticker(onTickonTick) {
}
