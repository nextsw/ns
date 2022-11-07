#ifndef SEMANTICS_EVENT_H
#define SEMANTICS_EVENT_H
#include <memory>
#include <ui.hpp>

#include <flutter/foundation.hpp>
#include <flutter/painting.hpp>



class SemanticsEvent {
public:
    String type;


     SemanticsEvent(String type);

    Map<String, dynamic> toMap(int nodeId);

    Map<String, dynamic> getDataMap();

    String toString();

private:

};

class AnnounceSemanticsEvent : SemanticsEvent {
public:
    String message;

    TextDirection textDirection;


     AnnounceSemanticsEvent(String message, TextDirection textDirection);

    Map<String, dynamic> getDataMap();

private:

};

class TooltipSemanticsEvent : SemanticsEvent {
public:
    String message;


     TooltipSemanticsEvent(String message);

    Map<String, dynamic> getDataMap();

private:

};

class LongPressSemanticsEvent : SemanticsEvent {
public:

     LongPressSemanticsEvent();

    Map<String, dynamic> getDataMap();

private:

};

class TapSemanticEvent : SemanticsEvent {
public:

     TapSemanticEvent();

    Map<String, dynamic> getDataMap();

private:

};

#endif