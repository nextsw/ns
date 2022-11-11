#include "arena.hpp"
void GestureArenaEntryCls::resolve(GestureDisposition disposition) {
    _arena->_resolve(_pointer, _member, disposition);
}

void _GestureArenaCls::add(GestureArenaMember member) {
    assert(isOpen);
    members->add(member);
}

String _GestureArenaCls::toString() {
    StringBuffer buffer = make<StringBufferCls>();
    if (members->isEmpty) {
        buffer->write(__s("<empty>"));
    } else {
        buffer->write(members-><String>map([=] (GestureArenaMember member) {
            if (member == eagerWinner) {
                return __s("$member (eager winner)");
            }
            return __s("$member");
        })->join(__s(", ")));
    }
    if (isOpen) {
        buffer->write(__s(" [open]"));
    }
    if (isHeld) {
        buffer->write(__s(" [held]"));
    }
    if (hasPendingSweep) {
        buffer->write(__s(" [hasPendingSweep]"));
    }
    return buffer->toString();
}

GestureArenaEntry GestureArenaManagerCls::add(GestureArenaMember member, int pointer) {
    _GestureArena state = _arenas->putIfAbsent(pointer, [=] () {
    assert(_debugLogDiagnostic(pointer, __s("★ Opening new gesture arena.")));
    return make<_GestureArenaCls>();
});
    state->add(member);
    assert(_debugLogDiagnostic(pointer, __s("Adding: $member")));
    return GestureArenaEntryCls->_(this, pointer, member);
}

void GestureArenaManagerCls::close(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    state->isOpen = false;
    assert(_debugLogDiagnostic(pointer, __s("Closing"), state));
    _tryToResolveArena(pointer, state);
}

void GestureArenaManagerCls::sweep(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    assert(!state->isOpen);
    if (state->isHeld) {
        state->hasPendingSweep = true;
        assert(_debugLogDiagnostic(pointer, __s("Delaying sweep"), state));
        return;
    }
    assert(_debugLogDiagnostic(pointer, __s("Sweeping"), state));
    _arenas->remove(pointer);
    if (state->members->isNotEmpty) {
        assert(_debugLogDiagnostic(pointer, __s("Winner: ${state.members.first}")));
        state->members->first->acceptGesture(pointer);
        for (;  < state->members->length(); i++) {
            state->members[i]->rejectGesture(pointer);
        }
    }
}

void GestureArenaManagerCls::hold(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    state->isHeld = true;
    assert(_debugLogDiagnostic(pointer, __s("Holding"), state));
}

void GestureArenaManagerCls::release(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    state->isHeld = false;
    assert(_debugLogDiagnostic(pointer, __s("Releasing"), state));
    if (state->hasPendingSweep) {
        sweep(pointer);
    }
}

void GestureArenaManagerCls::_resolve(GestureDisposition disposition, GestureArenaMember member, int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    assert(_debugLogDiagnostic(pointer, __s("${ disposition == GestureDisposition.accepted ? "Accepting" : "Rejecting" }: $member")));
    assert(state->members->contains(member));
    if (disposition == GestureDispositionCls::rejected) {
        state->members->remove(member);
        member->rejectGesture(pointer);
        if (!state->isOpen) {
            _tryToResolveArena(pointer, state);
        }
    } else {
        assert(disposition == GestureDispositionCls::accepted);
        if (state->isOpen) {
            state->eagerWinner = member;
        } else {
            assert(_debugLogDiagnostic(pointer, __s("Self-declared winner: $member")));
            _resolveInFavorOf(pointer, state, member);
        }
    }
}

void GestureArenaManagerCls::_tryToResolveArena(int pointer, _GestureArena state) {
    assert(_arenas[pointer] == state);
    assert(!state->isOpen);
    if (state->members->length() == 1) {
        scheduleMicrotask([=] ()         {
            _resolveByDefault(pointer, state);
        });
    } else     {
        if (state->members->isEmpty) {
        _arenas->remove(pointer);
        assert(_debugLogDiagnostic(pointer, __s("Arena empty.")));
    } else     {
        if (state->eagerWinner != nullptr) {
        assert(_debugLogDiagnostic(pointer, __s("Eager winner: ${state.eagerWinner}")));
        _resolveInFavorOf(pointer, state, state->eagerWinner!);
    }
;
    };
    }}

void GestureArenaManagerCls::_resolveByDefault(int pointer, _GestureArena state) {
    if (!_arenas->containsKey(pointer)) {
        return;
    }
    assert(_arenas[pointer] == state);
    assert(!state->isOpen);
    List<GestureArenaMember> members = state->members;
    assert(members->length() == 1);
    _arenas->remove(pointer);
    assert(_debugLogDiagnostic(pointer, __s("Default winner: ${state.members.first}")));
    state->members->first->acceptGesture(pointer);
}

void GestureArenaManagerCls::_resolveInFavorOf(GestureArenaMember member, int pointer, _GestureArena state) {
    assert(state == _arenas[pointer]);
    assert(state != nullptr);
    assert(state->eagerWinner == nullptr || state->eagerWinner == member);
    assert(!state->isOpen);
    _arenas->remove(pointer);
    for (GestureArenaMember rejectedMember : state->members) {
        if (rejectedMember != member) {
            rejectedMember->rejectGesture(pointer);
        }
    }
    member->acceptGesture(pointer);
}

bool GestureArenaManagerCls::_debugLogDiagnostic(String message, int pointer, _GestureArena state) {
    assert([=] () {
        if (debugPrintGestureArenaDiagnostics) {
            int count = state?->members->length();
            String s = count != 1? __s("s") : __s("");
            debugPrint(__s("Gesture arena ${pointer.toString().padRight(4)} ❙ $message${ count != null ? " with $count member$s." : ""}"));
        }
        return true;
    }());
    return true;
}
