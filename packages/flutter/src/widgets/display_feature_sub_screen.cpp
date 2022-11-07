#include "display_feature_sub_screen.hpp"
Widget DisplayFeatureSubScreen::build(BuildContext context) {
    assert(anchorPoint != nullptr || debugCheckHasDirectionality(context"to determine which sub-screen DisplayFeatureSubScreen uses", "Alternatively, consider specifying the 'anchorPoint' argument on the DisplayFeatureSubScreen."));
    MediaQueryData mediaQuery = MediaQuery.of(context);
    Size parentSize = mediaQuery.size;
    Rect wantedBounds = Offset.zero & parentSize;
    Offset resolvedAnchorPoint = _capOffset(anchorPoint ?? _fallbackAnchorPoint(context), parentSize);
    Iterable<Rect> subScreens = subScreensInBounds(wantedBounds, avoidBounds(mediaQuery));
    Rect closestSubScreen = _closestToAnchorPoint(subScreens, resolvedAnchorPoint);
    return Padding(EdgeInsets.only(closestSubScreen.left, closestSubScreen.top, parentSize.width - closestSubScreen.right, parentSize.height - closestSubScreen.bottom), MediaQuery(mediaQuery.removeDisplayFeatures(closestSubScreen), child));
}

Iterable<Rect> DisplayFeatureSubScreen::avoidBounds(MediaQueryData mediaQuery) {
    return mediaQuery.displayFeatures.where().map();
}

Iterable<Rect> DisplayFeatureSubScreen::subScreensInBounds(Iterable<Rect> avoidBounds, Rect wantedBounds) {
    Iterable<Rect> subScreens = ;
    for (Rect bounds : avoidBounds) {
        List<Rect> newSubScreens = ;
        for (Rect screen : subScreens) {
            if (screen.top >= bounds.top && screen.bottom <= bounds.bottom) {
                if (screen.left < bounds.left) {
                    newSubScreens.add(Rect.fromLTWH(screen.left, screen.top, bounds.left - screen.left, screen.height));
                }
                if (screen.right > bounds.right) {
                    newSubScreens.add(Rect.fromLTWH(bounds.right, screen.top, screen.right - bounds.right, screen.height));
                }
            } else             {
                if (screen.left >= bounds.left && screen.right <= bounds.right) {
                if (screen.top < bounds.top) {
                    newSubScreens.add(Rect.fromLTWH(screen.left, screen.top, screen.width, bounds.top - screen.top));
                }
                if (screen.bottom > bounds.bottom) {
                    newSubScreens.add(Rect.fromLTWH(screen.left, bounds.bottom, screen.width, screen.bottom - bounds.bottom));
                }
            } else {
                newSubScreens.add(screen);
            }
;
            }        }
        subScreens = newSubScreens;
    }
    return subScreens;
}

Offset DisplayFeatureSubScreen::_fallbackAnchorPoint(BuildContext context) {
    TextDirection textDirection = Directionality.of(context);
    ;
}

Rect DisplayFeatureSubScreen::_closestToAnchorPoint(Offset anchorPoint, Iterable<Rect> subScreens) {
    Rect closestScreen = subScreens.first;
    double closestDistance = _distanceFromPointToRect(anchorPoint, closestScreen);
    for (Rect screen : subScreens) {
        double subScreenDistance = _distanceFromPointToRect(anchorPoint, screen);
        if ( < closestDistance) {
            closestScreen = screen;
            closestDistance = subScreenDistance;
        }
    }
    return closestScreen;
}

double DisplayFeatureSubScreen::_distanceFromPointToRect(Offset point, Rect rect) {
    if (point.dx < rect.left) {
        if (point.dy < rect.top) {
            return (point - rect.topLeft).distance;
        } else         {
            if (point.dy > rect.bottom) {
            return (point - rect.bottomLeft).distance;
        } else {
            return rect.left - point.dx;
        }
;
        }    } else     {
        if (point.dx > rect.right) {
        if (point.dy < rect.top) {
            return (point - rect.topRight).distance;
        } else         {
            if (point.dy > rect.bottom) {
            return (point - rect.bottomRight).distance;
        } else {
            return point.dx - rect.right;
        }
;
        }    } else {
        if (point.dy < rect.top) {
            return rect.top - point.dy;
        } else         {
            if (point.dy > rect.bottom) {
            return point.dy - rect.bottom;
        } else {
            return 0;
        }
;
        }    }
;
    }}

Offset DisplayFeatureSubScreen::_capOffset(Size maximum, Offset offset) {
    if (offset.dx >= 0 && offset.dx <= maximum.width && offset.dy >= 0 && offset.dy <= maximum.height) {
        return offset;
    } else {
        return Offset(math.min(math.max(0, offset.dx), maximum.width), math.min(math.max(0, offset.dy), maximum.height));
    }
}
