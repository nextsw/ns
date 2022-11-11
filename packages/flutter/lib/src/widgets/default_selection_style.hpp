#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DEFAULT_SELECTION_STYLE
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DEFAULT_SELECTION_STYLE
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include "framework.hpp"
#include "inherited_theme.hpp"


class DefaultSelectionStyleCls : public InheritedThemeCls {
public:
    Color cursorColor;

    Color selectionColor;


     DefaultSelectionStyleCls(Unknown child, Color cursorColor, Unknown key, Color selectionColor);
    virtual void  fallback(Unknown key);

    static DefaultSelectionStyle of(BuildContext context);

    virtual Widget wrap(BuildContext context, Widget child);

    virtual bool updateShouldNotify(DefaultSelectionStyle oldWidget);

private:

};
using DefaultSelectionStyle = std::shared_ptr<DefaultSelectionStyleCls>;

class _NullWidgetCls : public StatelessWidgetCls {
public:

    virtual Widget build(BuildContext context);

private:

     _NullWidgetCls();
};
using _NullWidget = std::shared_ptr<_NullWidgetCls>;


#endif