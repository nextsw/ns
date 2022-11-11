#include "team.hpp"
void _CombiningGestureArenaEntryCls::resolve(GestureDisposition disposition) {
    _combiner->_resolve(_member, disposition);
}

void _CombiningGestureArenaMemberCls::acceptGesture(int pointer) {
    assert(_pointer == pointer);
    assert(_winner != nullptr || _members->isNotEmpty());
    _close();
    _winner |= _owner->captain | _members[0];
    for (GestureArenaMember member : _members) {
        if (member != _winner) {
            member->rejectGesture(pointer);
        }
    }
    _winner!->acceptGesture(pointer);
}

void _CombiningGestureArenaMemberCls::rejectGesture(int pointer) {
    assert(_pointer == pointer);
    _close();
    for (GestureArenaMember member : _members) {
        member->rejectGesture(pointer);
    }
}

void _CombiningGestureArenaMemberCls::_close() {
    assert(!_resolved);
    _resolved = true;
    _CombiningGestureArenaMember combiner = _owner->_combiners->remove(_pointer);
    assert(combiner == this);
}

GestureArenaEntry _CombiningGestureArenaMemberCls::_add(int pointer, GestureArenaMember member) {
    assert(!_resolved);
    assert(_pointer == pointer);
    _members->add(member);
    _entry |= GestureBindingCls::instance->gestureArena->add(pointer, this);
    return make<_CombiningGestureArenaEntryCls>(this, member);
}

void _CombiningGestureArenaMemberCls::_resolve(GestureArenaMember member, GestureDisposition disposition) {
    if (_resolved) {
        return;
    }
    if (disposition == GestureDispositionCls::rejected) {
        _members->remove(member);
        member->rejectGesture(_pointer);
        if (_members->isEmpty()) {
            _entry!->resolve(disposition);
        }
    } else {
        assert(disposition == GestureDispositionCls::accepted);
        _winner |= _owner->captain | member;
        _entry!->resolve(disposition);
    }
}

GestureArenaEntry GestureArenaTeamCls::add(int pointer, GestureArenaMember member) {
    _CombiningGestureArenaMember combiner = _combiners->putIfAbsent(pointer, [=] () {
    make<_CombiningGestureArenaMemberCls>(this, pointer);
});
    return combiner->_add(pointer, member);
}
