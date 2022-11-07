#ifndef TABLE_H
#define TABLE_H
#include <memory>



const String _data;

const String _start;

int low(int codeUnit);

int high(int lead, int tail);

const auto  _stateMachine;

int move(int inputCategory, int state);

const auto  _backStateMachine;

int moveBack(int inputCategory, int state);


#endif