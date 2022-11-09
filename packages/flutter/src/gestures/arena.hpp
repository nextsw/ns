#ifndef PACKAGES_FLUTTER_SRC_GESTURES_ARENA
#define PACKAGES_FLUTTER_SRC_GESTURES_ARENA
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/async/async.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include "debug.hpp"


enum GestureDisposition{
    accepted,
    rejected,
} // end GestureDisposition

class GestureArenaMemberCls : public ObjectCls {
public:

    virtual void acceptGesture(int pointer);
    virtual void rejectGesture(int pointer);
private:

};
using GestureArenaMember = std::shared_ptr<GestureArenaMemberCls>;

class GestureArenaEntryCls : public ObjectCls {
public:

    virtual void resolve(GestureDisposition disposition);

private:
    GestureArenaManager _arena;

    int _pointer;

    GestureArenaMember _member;


    virtual void  _(GestureArenaManager _arena, GestureArenaMember _member, int _pointer);
};
using GestureArenaEntry = std::shared_ptr<GestureArenaEntryCls>;

class _GestureArenaCls : public ObjectCls {
public:
    List<GestureArenaMember> members;

    bool isOpen;

    bool isHeld;

    bool hasPendingSweep;

    GestureArenaMember eagerWinner;


    virtual void add(GestureArenaMember member);

    virtual String toString();

private:

};
using _GestureArena = std::shared_ptr<_GestureArenaCls>;

class GestureArenaManagerCls : public ObjectCls {
public:

    virtual GestureArenaEntry add(GestureArenaMember member, int pointer);

    virtual void close(int pointer);

    virtual void sweep(int pointer);

    virtual void hold(int pointer);

    virtual void release(int pointer);

private:
    Map<int, _GestureArena> _arenas;


    virtual void _resolve(GestureDisposition disposition, GestureArenaMember member, int pointer);

    virtual void _tryToResolveArena(int pointer, _GestureArena state);

    virtual void _resolveByDefault(int pointer, _GestureArena state);

    virtual void _resolveInFavorOf(GestureArenaMember member, int pointer, _GestureArena state);

    virtual bool _debugLogDiagnostic(String message, int pointer, _GestureArena state);

};
using GestureArenaManager = std::shared_ptr<GestureArenaManagerCls>;


#endif