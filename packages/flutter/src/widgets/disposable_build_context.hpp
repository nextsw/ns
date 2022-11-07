#ifndef DISPOSABLE_BUILD_CONTEXT_H
#define DISPOSABLE_BUILD_CONTEXT_H
#include <memory>

#include "framework.hpp"



class DisposableBuildContext<T extends State> {
public:

     DisposableBuildContext(T _state);

    BuildContext context();

    void dispose();

private:
    T _state;


    bool _debugValidate();

};

#endif