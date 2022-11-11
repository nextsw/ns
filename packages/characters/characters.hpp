#ifndef PACKAGES_CHARACTERS_CHARACTERS
#define PACKAGES_CHARACTERS_CHARACTERS
#include <base.hpp>

#include <dart/core/core.hpp>

String _data;

String _start;

int low(int codeUnit);

int high(int lead, int tail);

auto  _stateMachine;

int move(int state, int inputCategory);

auto  _backStateMachine;

int moveBack(int state, int inputCategory);



#endif