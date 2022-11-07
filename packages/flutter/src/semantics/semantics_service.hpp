#ifndef SEMANTICS_SERVICE_H
#define SEMANTICS_SERVICE_H
#include <memory>
#include <ui.hpp>

#include <ui/ui.hpp>
#include <flutter/services.hpp>
#include "semantics_event.hpp"



class SemanticsService {
public:

    static Future<void> announce(String message, TextDirection textDirection);

    static Future<void> tooltip(String message);

private:

    void  _();

};

#endif