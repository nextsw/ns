#include "ticker_provider.hpp"
TickerModeCls::TickerModeCls(Widget child, bool enabled, Unknown key) {
    {
        assert(enabled != nullptr);
    }
}

bool TickerModeCls::of(BuildContext context) {
    _EffectiveTickerMode widget = context-><_EffectiveTickerMode>dependOnInheritedWidgetOfExactType();
    return widget?->enabled ?? true;
}

ValueNotifier<bool> TickerModeCls::getNotifier(BuildContext context) {
    _EffectiveTickerMode widget = ((_EffectiveTickerMode)context-><_EffectiveTickerMode>getElementForInheritedWidgetOfExactType()?->widget);
    return widget?->notifier ?? <bool>make<ValueNotifierCls>(true);
}

State<TickerMode> TickerModeCls::createState() {
    return make<_TickerModeStateCls>();
}

void _TickerModeStateCls::didChangeDependencies() {
    super->didChangeDependencies();
    _ancestorTicketMode = TickerModeCls->of(context);
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
    return make<_EffectiveTickerModeCls>(_effectiveMode->value, _effectiveMode, widget->child);
}

void _TickerModeStateCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("requested mode"widget->enabled, "enabled", "disabled", true));
}

void _TickerModeStateCls::_updateEffectiveMode() {
    _effectiveMode->value = _ancestorTicketMode && widget->enabled;
}

bool _EffectiveTickerModeCls::updateShouldNotify(_EffectiveTickerMode oldWidget) {
    return enabled != oldWidget->enabled;
}

void _EffectiveTickerModeCls::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(make<FlagPropertyCls>("effective mode"enabled, "enabled", "disabled", true));
}

_EffectiveTickerModeCls::_EffectiveTickerModeCls(Unknown child, bool enabled, ValueNotifier<bool> notifier) {
    {
        assert(enabled != nullptr);
    }
}

template<typename T : StatefulWidget> Ticker SingleTickerProviderStateMixinCls<T>::createTicker(TickerCallback onTick) {
    assert([=] () {
        if (_ticker == nullptr) {
            return true;
        }
        ;
    }());
    _ticker = make<TickerCls>(onTickkDebugMode? "created by ${describeIdentity(this)}" : nullptr);
    _updateTickerModeNotifier();
    _updateTicker();
    return _ticker!;
}

template<typename T : StatefulWidget> void SingleTickerProviderStateMixinCls<T>::dispose() {
    assert([=] () {
        if (_ticker == nullptr || !_ticker!->isActive) {
            return true;
        }
        ;
    }());
    _tickerModeNotifier?->removeListener(_updateTicker);
    _tickerModeNotifier = nullptr;
    super->dispose();
}

template<typename T : StatefulWidget> void SingleTickerProviderStateMixinCls<T>::activate() {
    super->activate();
    _updateTickerModeNotifier();
    _updateTicker();
}

template<typename T : StatefulWidget> void SingleTickerProviderStateMixinCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    String tickerDescription;
    if (_ticker != nullptr) {
        if (_ticker!->isActive && _ticker!->muted) {
            tickerDescription = "active but muted";
        } else         {
            if (_ticker!->isActive) {
            tickerDescription = "active";
        } else         {
            if (_ticker!->muted) {
            tickerDescription = "inactive and muted";
        } else {
            tickerDescription = "inactive";
        }
;
        };
        }    }
    properties->add(<Ticker>make<DiagnosticsPropertyCls>("ticker", _tickertickerDescription, false, nullptr));
}

template<typename T : StatefulWidget> void SingleTickerProviderStateMixinCls<T>::_updateTicker() {
    if (_ticker != nullptr) {
        _ticker!->muted = !_tickerModeNotifier!->value;
    }
}

template<typename T : StatefulWidget> void SingleTickerProviderStateMixinCls<T>::_updateTickerModeNotifier() {
    ValueNotifier<bool> newNotifier = TickerModeCls->getNotifier(context);
    if (newNotifier == _tickerModeNotifier) {
        return;
    }
    _tickerModeNotifier?->removeListener(_updateTicker);
    newNotifier->addListener(_updateTicker);
    _tickerModeNotifier = newNotifier;
}

template<typename T : StatefulWidget> Ticker TickerProviderStateMixinCls<T>::createTicker(TickerCallback onTick) {
    if (_tickerModeNotifier == nullptr) {
        _updateTickerModeNotifier();
    }
    assert(_tickerModeNotifier != nullptr);
    _tickers = makeSet();
    auto _c1 = make<_WidgetTickerCls>(onTick, thiskDebugMode? "created by ${describeIdentity(this)}" : nullptr);_c1.muted = !_tickerModeNotifier!->value;_WidgetTicker result = _c1;
    _tickers!->add(result);
    return result;
}

template<typename T : StatefulWidget> void TickerProviderStateMixinCls<T>::activate() {
    super->activate();
    _updateTickerModeNotifier();
    _updateTickers();
}

template<typename T : StatefulWidget> void TickerProviderStateMixinCls<T>::dispose() {
    assert([=] () {
        if (_tickers != nullptr) {
            for (Ticker ticker : _tickers!) {
                if (ticker->isActive) {
                    ;
                }
            }
        }
        return true;
    }());
    _tickerModeNotifier?->removeListener(_updateTickers);
    _tickerModeNotifier = nullptr;
    super->dispose();
}

template<typename T : StatefulWidget> void TickerProviderStateMixinCls<T>::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super->debugFillProperties(properties);
    properties->add(<Set<Ticker>>make<DiagnosticsPropertyCls>("tickers", _tickers_tickers != nullptr? "tracking ${_tickers!.length} ticker${_tickers!.length == 1 ? "" : "s"}" : nullptr, nullptr));
}

template<typename T : StatefulWidget> void TickerProviderStateMixinCls<T>::_removeTicker(_WidgetTicker ticker) {
    assert(_tickers != nullptr);
    assert(_tickers!->contains(ticker));
    _tickers!->remove(ticker);
}

template<typename T : StatefulWidget> void TickerProviderStateMixinCls<T>::_updateTickers() {
    if (_tickers != nullptr) {
        bool muted = !_tickerModeNotifier!->value;
        for (Ticker ticker : _tickers!) {
            ticker->muted = muted;
        }
    }
}

template<typename T : StatefulWidget> void TickerProviderStateMixinCls<T>::_updateTickerModeNotifier() {
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
