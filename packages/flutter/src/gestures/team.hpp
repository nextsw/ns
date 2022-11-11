#ifndef PACKAGES_FLUTTER_SRC_GESTURES_TEAM
#define PACKAGES_FLUTTER_SRC_GESTURES_TEAM
#include <base.hpp>
#include "arena.hpp"

#include <dart/core/core.hpp>
#include "arena.hpp"
#include "binding.hpp"


class _CombiningGestureArenaEntryCls : public ObjectCls {
public:

    virtual void resolve(GestureDisposition disposition);

private:
    _CombiningGestureArenaMember _combiner;

    GestureArenaMember _member;


     _CombiningGestureArenaEntryCls(_CombiningGestureArenaMember _combiner, GestureArenaMember _member);
};
using _CombiningGestureArenaEntry = std::shared_ptr<_CombiningGestureArenaEntryCls>;

class _CombiningGestureArenaMemberCls : public GestureArenaMemberCls {
public:

    virtual void acceptGesture(int pointer);

    virtual void rejectGesture(int pointer);

private:
    GestureArenaTeam _owner;

    List<GestureArenaMember> _members;

    int _pointer;

    bool _resolved;

    GestureArenaMember _winner;

    GestureArenaEntry _entry;


     _CombiningGestureArenaMemberCls(GestureArenaTeam _owner, int _pointer);
    virtual void _close();

    virtual GestureArenaEntry _add(int pointer, GestureArenaMember member);

    virtual void _resolve(GestureArenaMember member, GestureDisposition disposition);

};
using _CombiningGestureArenaMember = std::shared_ptr<_CombiningGestureArenaMemberCls>;

class GestureArenaTeamCls : public ObjectCls {
public:
    GestureArenaMember captain;


    virtual GestureArenaEntry add(int pointer, GestureArenaMember member);

private:
    Map<int, _CombiningGestureArenaMember> _combiners;


};
using GestureArenaTeam = std::shared_ptr<GestureArenaTeamCls>;


#endif