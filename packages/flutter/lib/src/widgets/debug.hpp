#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DEBUG
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_DEBUG
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <dart/developer/developer.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "basic.hpp"
#include "framework.hpp"
#include "localizations.hpp"
#include "media_query.hpp"
#include "overlay.hpp"
#include "table.hpp"

bool debugPrintRebuildDirtyWidgets;

RebuildDirtyWidgetCallback debugOnRebuildDirtyWidget;

bool debugPrintBuildScope;

bool debugPrintScheduleBuildForStacks;

bool debugPrintGlobalKeyedWidgetLifecycle;

bool debugProfileBuildsEnabled;

bool debugProfileBuildsEnabledUserWidgets;

bool debugEnhanceBuildTimelineArguments;

bool debugHighlightDeprecatedWidgets;

Key _firstNonUniqueKey(Iterable<Widget> widgets);

bool debugChildrenHaveDuplicateKeys(Iterable<Widget> children, Widget parent);

bool debugItemsHaveDuplicateKeys(Iterable<Widget> items);

bool debugCheckHasTable(BuildContext context);

bool debugCheckHasMediaQuery(BuildContext context);

bool debugCheckHasDirectionality(String alternative, BuildContext context, String hint, String why);

void debugWidgetBuilderValue(Widget built, Widget widget);

bool debugCheckHasWidgetsLocalizations(BuildContext context);

bool debugCheckHasOverlay(BuildContext context);

bool debugAssertAllWidgetVarsUnset(String reason);



#endif