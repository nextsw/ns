#include "team.hpp"
void _CombiningGestureArenaEntry::resolve(GestureDisposition disposition) {
    _combiner._resolve(_member, disposition);
}

void _CombiningGestureArenaMember::acceptGesture(int pointer) {
    assert(_pointer == pointer);
    assert(_winner != nullptr || _members.isNotEmpty);
    _close();
    _winner = _owner.captain ?? _members[0];
    for (GestureArenaMember member : _members) {
        if (member != _winner) {
            member.rejectGesture(pointer);
        }
    }
    _winner!.acceptGesture(pointer);
}

void _CombiningGestureArenaMember::rejectGesture(int pointer) {
    assert(_pointer == pointer);
    _close();
    for (GestureArenaMember member : _members) {
        member.rejectGesture(pointer);
    }
}

void _CombiningGestureArenaMember::_close() {
    assert(!_resolved);
    _resolved = true;
    _CombiningGestureArenaMember combiner = _owner._combiners.remove(_pointer);
    assert(combiner == this);
}

GestureArenaEntry _CombiningGestureArenaMember::_add(GestureArenaMember member, int pointer) {
    assert(!_resolved);
    assert(_pointer == pointer);
    _members.add(member);
    _entry = GestureBinding.instance.gestureArena.add(pointer, this);
    return _CombiningGestureArenaEntry(this, member);
}

void _CombiningGestureArenaMember::_resolve(GestureDisposition disposition, GestureArenaMember member) {
    if (_resolved) {
        return;
    }
    if (disposition == GestureDisposition.rejected) {
        _members.remove(member);
        member.rejectGesture(_pointer);
        if (_members.isEmpty) {
            _entry!.resolve(disposition);
        }
    } else {
        assert(disposition == GestureDisposition.accepted);
        _winner = _owner.captain ?? member;
        _entry!.resolve(disposition);
    }
}

GestureArenaEntry GestureArenaTeam::add(GestureArenaMember member, int pointer) {
    _CombiningGestureArenaMember combiner = _combiners.putIfAbsent(pointer, );
    return combiner._add(pointer, member);
}
