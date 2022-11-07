#ifndef TEAM_H
#define TEAM_H
#include <memory>
#include "arena.hpp"

#include "arena.hpp"
#include "binding.hpp"



class _CombiningGestureArenaEntry {
public:

    void resolve(GestureDisposition disposition);

private:
    _CombiningGestureArenaMember _combiner;

    GestureArenaMember _member;


     _CombiningGestureArenaEntry(_CombiningGestureArenaMember _combiner, GestureArenaMember _member);

};

class _CombiningGestureArenaMember : GestureArenaMember {
public:

    void acceptGesture(int pointer);

    void rejectGesture(int pointer);

private:
    GestureArenaTeam _owner;

    List<GestureArenaMember> _members;

    int _pointer;

    bool _resolved;

    GestureArenaMember _winner;

    GestureArenaEntry _entry;


     _CombiningGestureArenaMember(GestureArenaTeam _owner, int _pointer);

    void _close();

    GestureArenaEntry _add(GestureArenaMember member, int pointer);

    void _resolve(GestureDisposition disposition, GestureArenaMember member);

};

class GestureArenaTeam {
public:
    GestureArenaMember captain;


    GestureArenaEntry add(GestureArenaMember member, int pointer);

private:
    Map<int, _CombiningGestureArenaMember> _combiners;


};

#endif