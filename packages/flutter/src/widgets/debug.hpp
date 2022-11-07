#ifndef DEBUG_H
#define DEBUG_H
#include <memory>

#include <collection/collection.hpp>
#include <developer/developer.hpp>
#include <flutter/foundation.hpp>
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