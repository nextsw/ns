#include "characters.hpp"
int low(int codeUnit) {
    auto chunkStart = _start->codeUnitAt(codeUnit >> 6);
    auto index = chunkStart + (codeUnit & 63);
    auto bit = index & 1;
    auto pair = _data->codeUnitAt(index >> 1);
    return (pair >> 4) & -bit | (pair & 0xF) & (bit - 1);
}

int high(int lead, int tail) {
    auto chunkStart = _start->codeUnitAt(1024 + (0x3ff & lead));
    auto index = chunkStart + (0x3ff & tail);
    auto bit = index & 1;
    auto pair = _data->codeUnitAt(index >> 1);
    return (pair >> 4) & -bit | (pair & 0xF) & (bit - 1);
}

int move(int state, int inputCategory) {
    return _stateMachine->codeUnitAt((state & 0xF0) | inputCategory);
}

int moveBack(int state, int inputCategory) {
    return _backStateMachine->codeUnitAt((state & 0xF0) | inputCategory);
}
