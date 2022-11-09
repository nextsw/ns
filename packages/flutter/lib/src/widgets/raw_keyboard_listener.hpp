#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_RAW_KEYBOARD_LISTENER
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_RAW_KEYBOARD_LISTENER
#include <base.hpp>
#include <packages/flutter/flutter.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"


class RawKeyboardListenerCls : public StatefulWidgetCls {
public:
    FocusNode focusNode;

    bool autofocus;

    bool includeSemantics;

    ValueChanged<RawKeyEvent> onKey;

    Widget child;


     RawKeyboardListenerCls(bool autofocus, Widget child, FocusNode focusNode, bool includeSemantics, Unknown key, ValueChanged<RawKeyEvent> onKey);

    virtual State<RawKeyboardListener> createState();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};
using RawKeyboardListener = std::shared_ptr<RawKeyboardListenerCls>;

class _RawKeyboardListenerStateCls : public StateCls<RawKeyboardListener> {
public:

    virtual void initState();

    virtual void didUpdateWidget(RawKeyboardListener oldWidget);

    virtual void dispose();

    virtual Widget build(BuildContext context);

private:
    bool _listening;


    virtual void _handleFocusChanged();

    virtual void _attachKeyboardIfDetached();

    virtual void _detachKeyboardIfAttached();

    virtual void _handleRawKeyEvent(RawKeyEvent event);

};
using _RawKeyboardListenerState = std::shared_ptr<_RawKeyboardListenerStateCls>;


#endif