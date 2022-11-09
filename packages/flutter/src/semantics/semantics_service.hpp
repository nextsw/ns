#ifndef PACKAGES_FLUTTER_SRC_SEMANTICS_SEMANTICS_SERVICE
#define PACKAGES_FLUTTER_SRC_SEMANTICS_SEMANTICS_SERVICE
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <dart/ui/ui.hpp>
#include <packages/flutter/flutter.hpp>
#include "semantics_event.hpp"


class SemanticsServiceCls : public ObjectCls {
public:

    static Future<void> announce(String message, TextDirection textDirection);

    static Future<void> tooltip(String message);

private:

    virtual void  _();
};
using SemanticsService = std::shared_ptr<SemanticsServiceCls>;


#endif