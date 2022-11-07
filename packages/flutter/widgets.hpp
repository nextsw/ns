#ifndef WIDGETS_H
#define WIDGETS_H
#include <memory>
#include <characters/characters.hpp>
#include <vector_math/vector_math_64.hpp>
#include "foundation.hpp"
#include "rendering.hpp"
#include "src/widgets/actions.hpp"
#include "src/widgets/animated_cross_fade.hpp"
#include "src/widgets/animated_list.hpp"
#include "src/widgets/animated_size.hpp"
#include "src/widgets/animated_switcher.hpp"
#include "src/widgets/annotated_region.hpp"
#include "src/widgets/app.hpp"
#include "src/widgets/async.hpp"
#include "src/widgets/autocomplete.hpp"
#include "src/widgets/autofill.hpp"
#include "src/widgets/automatic_keep_alive.hpp"
#include "src/widgets/banner.hpp"
#include "src/widgets/basic.hpp"
#include "src/widgets/binding.hpp"
#include "src/widgets/bottom_navigation_bar_item.hpp"
#include "src/widgets/color_filter.hpp"
#include "src/widgets/container.hpp"
#include "src/widgets/debug.hpp"
#include "src/widgets/default_selection_style.hpp"
#include "src/widgets/default_text_editing_shortcuts.hpp"
#include "src/widgets/desktop_text_selection_toolbar_layout_delegate.hpp"
#include "src/widgets/dismissible.hpp"
#include "src/widgets/display_feature_sub_screen.hpp"
#include "src/widgets/disposable_build_context.hpp"
#include "src/widgets/drag_target.hpp"
#include "src/widgets/draggable_scrollable_sheet.hpp"
#include "src/widgets/dual_transition_builder.hpp"
#include "src/widgets/editable_text.hpp"
#include "src/widgets/fade_in_image.hpp"
#include "src/widgets/focus_manager.hpp"
#include "src/widgets/focus_scope.hpp"
#include "src/widgets/focus_traversal.hpp"
#include "src/widgets/form.hpp"
#include "src/widgets/framework.hpp"
#include "src/widgets/gesture_detector.hpp"
#include "src/widgets/grid_paper.hpp"
#include "src/widgets/heroes.hpp"
#include "src/widgets/icon.hpp"
#include "src/widgets/icon_data.hpp"
#include "src/widgets/icon_theme.hpp"
#include "src/widgets/icon_theme_data.hpp"
#include "src/widgets/image.hpp"
#include "src/widgets/image_filter.hpp"
#include "src/widgets/image_icon.hpp"
#include "src/widgets/implicit_animations.hpp"
#include "src/widgets/inherited_model.hpp"
#include "src/widgets/inherited_notifier.hpp"
#include "src/widgets/inherited_theme.hpp"
#include "src/widgets/interactive_viewer.hpp"
#include "src/widgets/keyboard_listener.hpp"
#include "src/widgets/layout_builder.hpp"
#include "src/widgets/list_wheel_scroll_view.hpp"
#include "src/widgets/localizations.hpp"
#include "src/widgets/media_query.hpp"
#include "src/widgets/modal_barrier.hpp"
#include "src/widgets/navigation_toolbar.hpp"
#include "src/widgets/navigator.hpp"
#include "src/widgets/nested_scroll_view.hpp"
#include "src/widgets/notification_listener.hpp"
#include "src/widgets/orientation_builder.hpp"
#include "src/widgets/overflow_bar.hpp"
#include "src/widgets/overlay.hpp"
#include "src/widgets/overscroll_indicator.hpp"
#include "src/widgets/page_storage.hpp"
#include "src/widgets/page_view.hpp"
#include "src/widgets/pages.hpp"
#include "src/widgets/performance_overlay.hpp"
#include "src/widgets/placeholder.hpp"
#include "src/widgets/platform_menu_bar.hpp"
#include "src/widgets/platform_view.hpp"
#include "src/widgets/preferred_size.hpp"
#include "src/widgets/primary_scroll_controller.hpp"
#include "src/widgets/raw_keyboard_listener.hpp"
#include "src/widgets/reorderable_list.hpp"
#include "src/widgets/restoration.hpp"
#include "src/widgets/restoration_properties.hpp"
#include "src/widgets/router.hpp"
#include "src/widgets/routes.hpp"
#include "src/widgets/safe_area.hpp"
#include "src/widgets/scroll_activity.hpp"
#include "src/widgets/scroll_aware_image_provider.hpp"
#include "src/widgets/scroll_configuration.hpp"
#include "src/widgets/scroll_context.hpp"
#include "src/widgets/scroll_controller.hpp"
#include "src/widgets/scroll_metrics.hpp"
#include "src/widgets/scroll_notification.hpp"
#include "src/widgets/scroll_notification_observer.hpp"
#include "src/widgets/scroll_physics.hpp"
#include "src/widgets/scroll_position.hpp"
#include "src/widgets/scroll_position_with_single_context.hpp"
#include "src/widgets/scroll_simulation.hpp"
#include "src/widgets/scroll_view.hpp"
#include "src/widgets/scrollable.hpp"
#include "src/widgets/scrollbar.hpp"
#include "src/widgets/selectable_region.hpp"
#include "src/widgets/selection_container.hpp"
#include "src/widgets/semantics_debugger.hpp"
#include "src/widgets/shared_app_data.hpp"
#include "src/widgets/shortcuts.hpp"
#include "src/widgets/single_child_scroll_view.hpp"
#include "src/widgets/size_changed_layout_notifier.hpp"
#include "src/widgets/sliver.hpp"
#include "src/widgets/sliver_fill.hpp"
#include "src/widgets/sliver_layout_builder.hpp"
#include "src/widgets/sliver_persistent_header.hpp"
#include "src/widgets/sliver_prototype_extent_list.hpp"
#include "src/widgets/slotted_render_object_widget.hpp"
#include "src/widgets/spacer.hpp"
#include "src/widgets/status_transitions.hpp"
#include "src/widgets/table.hpp"
#include "src/widgets/text.hpp"
#include "src/widgets/text_editing_intents.hpp"
#include "src/widgets/text_selection.hpp"
#include "src/widgets/text_selection_toolbar_layout_delegate.hpp"
#include "src/widgets/texture.hpp"
#include "src/widgets/ticker_provider.hpp"
#include "src/widgets/title.hpp"
#include "src/widgets/transitions.hpp"
#include "src/widgets/tween_animation_builder.hpp"
#include "src/widgets/unique_widget.hpp"
#include "src/widgets/value_listenable_builder.hpp"
#include "src/widgets/viewport.hpp"
#include "src/widgets/visibility.hpp"
#include "src/widgets/widget_inspector.hpp"
#include "src/widgets/widget_span.hpp"
#include "src/widgets/will_pop_scope.hpp"




#endif