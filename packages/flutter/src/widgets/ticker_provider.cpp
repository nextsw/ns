#include "ticker_provider.hpp"
TickerMode::TickerMode(Widget child, bool enabled, Unknown) {
    {
        assert(enabled != nullptr);
    }
}

bool TickerMode::of(BuildContext context) {
    _EffectiveTickerMode widget = context.<_EffectiveTickerMode>dependOnInheritedWidgetOfExactType();
    return widget?.enabled ?? true;
}

ValueNotifier<bool> TickerMode::getNotifier(BuildContext context) {
    _EffectiveTickerMode widget = (;
    return widget?.notifier ?? <bool>ValueNotifier(true);
}

State<TickerMode> TickerMode::createState() {
    return _TickerModeState();
}

void _TickerModeState::didChangeDependencies() {
    super.didChangeDependencies();
    _ancestorTicketMode = TickerMode.of(context);
    _updateEffectiveMode();
}

void _TickerModeState::didUpdateWidget(TickerMode oldWidget) {
    super.didUpdateWidget(oldWidget);
    _updateEffectiveMode();
}

void _TickerModeState::dispose() {
    _effectiveMode.dispose();
    super.dispose();
}

Widget _TickerModeState::build(BuildContext context) {
    return _EffectiveTickerMode(_effectiveMode.value, _effectiveMode, widget.child);
}

void _TickerModeState::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("requested mode"widget.enabled, "enabled", "disabled", true));
}

void _TickerModeState::_updateEffectiveMode() {
    _effectiveMode.value = _ancestorTicketMode && widget.enabled;
}

bool _EffectiveTickerMode::updateShouldNotify(_EffectiveTickerMode oldWidget) {
    return enabled != oldWidget.enabled;
}

void _EffectiveTickerMode::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(FlagProperty("effective mode"enabled, "enabled", "disabled", true));
}

_EffectiveTickerMode::_EffectiveTickerMode(Unknown, bool enabled, ValueNotifier<bool> notifier) {
    {
        assert(enabled != nullptr);
    }
}

Ticker SingleTickerProviderStateMixin::createTicker(TickerCallback onTick) {
    assert(());
    _ticker = Ticker(onTickkDebugMode? "created by ${describeIdentity(this)}" : nullptr);
    _updateTickerModeNotifier();
    _updateTicker();
    return _ticker!;
}

void SingleTickerProviderStateMixin::dispose() {
    assert(());
    _tickerModeNotifier?.removeListener(_updateTicker);
    _tickerModeNotifier = nullptr;
    super.dispose();
}

void SingleTickerProviderStateMixin::activate() {
    super.activate();
    _updateTickerModeNotifier();
    _updateTicker();
}

void SingleTickerProviderStateMixin::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    String tickerDescription;
    if (_ticker != nullptr) {
        if (_ticker!.isActive && _ticker!.muted) {
            tickerDescription = "active but muted";
        } else         {
            if (_ticker!.isActive) {
            tickerDescription = "active";
        } else         {
            if (_ticker!.muted) {
            tickerDescription = "inactive and muted";
        } else {
            tickerDescription = "inactive";
        }
;
        };
        }    }
    properties.add(<Ticker>DiagnosticsProperty("ticker", _tickertickerDescription, false, nullptr));
}

void SingleTickerProviderStateMixin::_updateTicker() {
    if (_ticker != nullptr) {
        _ticker!.muted = !_tickerModeNotifier!.value;
    }
}

void SingleTickerProviderStateMixin::_updateTickerModeNotifier() {
    ValueNotifier<bool> newNotifier = TickerMode.getNotifier(context);
    if (newNotifier == _tickerModeNotifier) {
        return;
    }
    _tickerModeNotifier?.removeListener(_updateTicker);
    newNotifier.addListener(_updateTicker);
    _tickerModeNotifier = newNotifier;
}

Ticker TickerProviderStateMixin::createTicker(TickerCallback onTick) {
    if (_tickerModeNotifier == nullptr) {
        _updateTickerModeNotifier();
    }
    assert(_tickerModeNotifier != nullptr);
    _tickers = ;
    _WidgetTicker result = ;
    _tickers!.add(result);
    return result;
}

void TickerProviderStateMixin::activate() {
    super.activate();
    _updateTickerModeNotifier();
    _updateTickers();
}

void TickerProviderStateMixin::dispose() {
    assert(());
    _tickerModeNotifier?.removeListener(_updateTickers);
    _tickerModeNotifier = nullptr;
    super.dispose();
}

void TickerProviderStateMixin::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(<Set<Ticker>>DiagnosticsProperty("tickers", _tickers_tickers != nullptr? "tracking ${_tickers!.length} ticker${_tickers!.length == 1 ? "" : "s"}" : nullptr, nullptr));
}

void TickerProviderStateMixin::_removeTicker(_WidgetTicker ticker) {
    assert(_tickers != nullptr);
    assert(_tickers!.contains(ticker));
    _tickers!.remove(ticker);
}

void TickerProviderStateMixin::_updateTickers() {
    if (_tickers != nullptr) {
        bool muted = !_tickerModeNotifier!.value;
        for (Ticker ticker : _tickers!) {
            ticker.muted = muted;
        }
    }
}

void TickerProviderStateMixin::_updateTickerModeNotifier() {
    ValueNotifier<bool> newNotifier = TickerMode.getNotifier(context);
    if (newNotifier == _tickerModeNotifier) {
        return;
    }
    _tickerModeNotifier?.removeListener(_updateTickers);
    newNotifier.addListener(_updateTickers);
    _tickerModeNotifier = newNotifier;
}

void _WidgetTicker::dispose() {
    _creator._removeTicker(this);
    super.dispose();
}
