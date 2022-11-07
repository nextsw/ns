#ifndef ARENA_H
#define ARENA_H
#include <memory>

#include <async/async.hpp>
#include <flutter/foundation.hpp>
#include "debug.hpp"



enum GestureDisposition{
    accepted,
    rejected,
} // end GestureDisposition

class GestureArenaMember {
public:

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

private:

};

class GestureArenaEntry {
public:

    void resolve(GestureDisposition disposition);

private:
    GestureArenaManager _arena;

    int _pointer;

    GestureArenaMember _member;


    void  _(GestureArenaManager _arena, GestureArenaMember _member, int _pointer);

};

class _GestureArena {
public:
    List<GestureArenaMember> members;

    bool isOpen;

    bool isHeld;

    bool hasPendingSweep;

    GestureArenaMember eagerWinner;


    void add(GestureArenaMember member);

    String toString();

private:

};

class GestureArenaManager {
public:

    GestureArenaEntry add(GestureArenaMember member, int pointer);

    void close(int pointer);

    void sweep(int pointer);

    void hold(int pointer);

    void release(int pointer);

private:
    Map<int, _GestureArena> _arenas;


    void _resolve(GestureDisposition disposition, GestureArenaMember member, int pointer);

    void _tryToResolveArena(int pointer, _GestureArena state);

    void _resolveByDefault(int pointer, _GestureArena state);

    void _resolveInFavorOf(GestureArenaMember member, int pointer, _GestureArena state);

    bool _debugLogDiagnostic(String message, int pointer, _GestureArena state);

};

#endif