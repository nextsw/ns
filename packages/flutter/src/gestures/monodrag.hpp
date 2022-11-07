#ifndef MONODRAG_H
#define MONODRAG_H
#include <memory>
#include <ui.hpp>
#include <flutter/foundation.hpp>
#include "drag.hpp"
#include "drag_details.hpp"
#include "events.hpp"
#include "recognizer.hpp"
#include "velocity_tracker.hpp"

#include <flutter/foundation.hpp>
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