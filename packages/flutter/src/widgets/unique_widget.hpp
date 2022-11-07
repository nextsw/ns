#ifndef UNIQUE_WIDGET_H
#define UNIQUE_WIDGET_H
#include <memory>

#include "framework.hpp"



class UniqueWidget<T extends State<StatefulWidget>> : StatefulWidget {
public:

     UniqueWidget(GlobalKey<T> key);

    T createState();

    T currentState();

private:

};

#endif