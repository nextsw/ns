#ifndef SPACER_H
#define SPACER_H
#include <memory>

#include "basic.hpp"
#include "framework.hpp"



class Spacer : StatelessWidget {
public:
    int flex;


     Spacer(int flex, Unknown);

    Widget build(BuildContext context);

private:

};

#endif