#ifndef TITLE_H
#define TITLE_H
#include <memory>

#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "basic.hpp"
#include "framework.hpp"



class Title : StatelessWidget {
public:
    String title;

    Color color;

    Widget child;


     Title(Widget child, Color color, Unknown, String title);

    Widget build(BuildContext context);

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:

};

#endif