#ifndef PACKAGES_CHARACTERS_CHARACTERS
#define PACKAGES_CHARACTERS_CHARACTERS
#include <base.hpp>

#include <dart/core/core.hpp>

String _data;

String _start;

int low(int codeUnit);

int high(int lead, int tail);

auto  _stateMachine;

int move(int inputCategory, int state);

auto  _backStateMachine;

int moveBack(int inputCategory, int state);



#endif