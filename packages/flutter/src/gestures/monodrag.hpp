#ifndef PACKAGES_FLUTTER_SRC_GESTURES_MONODRAG
#define PACKAGES_FLUTTER_SRC_GESTURES_MONODRAG
#include <base.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "drag.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "constants.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"


enum _DragState{
    ready,
    possible,
    accepted,
} // end _DragState


#endif