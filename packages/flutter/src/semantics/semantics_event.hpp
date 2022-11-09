#ifndef PACKAGES_FLUTTER_SRC_SEMANTICS_SEMANTICS_EVENT
#define PACKAGES_FLUTTER_SRC_SEMANTICS_SEMANTICS_EVENT
#include <base.hpp>
#include <dart/ui/ui.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>


class SemanticsEventCls : public ObjectCls {
public:
    String type;


     SemanticsEventCls(String type);
    virtual Map<String, dynamic> toMap(int nodeId);

    virtual Map<String, dynamic> getDataMap();
    virtual String toString();

private:

};
using SemanticsEvent = std::shared_ptr<SemanticsEventCls>;

class AnnounceSemanticsEventCls : public SemanticsEventCls {
public:
    String message;

    TextDirection textDirection;


     AnnounceSemanticsEventCls(String message, TextDirection textDirection);

    virtual Map<String, dynamic> getDataMap();

private:

};
using AnnounceSemanticsEvent = std::shared_ptr<AnnounceSemanticsEventCls>;

class TooltipSemanticsEventCls : public SemanticsEventCls {
public:
    String message;


     TooltipSemanticsEventCls(String message);

    virtual Map<String, dynamic> getDataMap();

private:

};
using TooltipSemanticsEvent = std::shared_ptr<TooltipSemanticsEventCls>;

class LongPressSemanticsEventCls : public SemanticsEventCls {
public:

     LongPressSemanticsEventCls();

    virtual Map<String, dynamic> getDataMap();

private:

};
using LongPressSemanticsEvent = std::shared_ptr<LongPressSemanticsEventCls>;

class TapSemanticEventCls : public SemanticsEventCls {
public:

     TapSemanticEventCls();

    virtual Map<String, dynamic> getDataMap();

private:

};
using TapSemanticEvent = std::shared_ptr<TapSemanticEventCls>;


#endif