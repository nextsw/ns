#include "arena.hpp"
void GestureArenaEntry::resolve(GestureDisposition disposition) {
    _arena._resolve(_pointer, _member, disposition);
}

void _GestureArena::add(GestureArenaMember member) {
    assert(isOpen);
    members.add(member);
}

String _GestureArena::toString() {
    StringBuffer buffer = StringBuffer();
    if (members.isEmpty) {
        buffer.write("<empty>");
    } else {
        buffer.write(members.<String>map().join(", "));
    }
    if (isOpen) {
        buffer.write(" [open]");
    }
    if (isHeld) {
        buffer.write(" [held]");
    }
    if (hasPendingSweep) {
        buffer.write(" [hasPendingSweep]");
    }
    return buffer.toString();
}

GestureArenaEntry GestureArenaManager::add(GestureArenaMember member, int pointer) {
    _GestureArena state = _arenas.putIfAbsent(pointer, );
    state.add(member);
    assert(_debugLogDiagnostic(pointer, "Adding: $member"));
    return GestureArenaEntry._(this, pointer, member);
}

void GestureArenaManager::close(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    state.isOpen = false;
    assert(_debugLogDiagnostic(pointer, "Closing", state));
    _tryToResolveArena(pointer, state);
}

void GestureArenaManager::sweep(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    assert(!state.isOpen);
    if (state.isHeld) {
        state.hasPendingSweep = true;
        assert(_debugLogDiagnostic(pointer, "Delaying sweep", state));
        return;
    }
    assert(_debugLogDiagnostic(pointer, "Sweeping", state));
    _arenas.remove(pointer);
    if (state.members.isNotEmpty) {
        assert(_debugLogDiagnostic(pointer, "Winner: ${state.members.first}"));
        state.members.first.acceptGesture(pointer);
        for (;  < state.members.length; i++) {
            state.members[i].rejectGesture(pointer);
        }
    }
}

void GestureArenaManager::hold(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    state.isHeld = true;
    assert(_debugLogDiagnostic(pointer, "Holding", state));
}

void GestureArenaManager::release(int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    state.isHeld = false;
    assert(_debugLogDiagnostic(pointer, "Releasing", state));
    if (state.hasPendingSweep) {
        sweep(pointer);
    }
}

void GestureArenaManager::_resolve(GestureDisposition disposition, GestureArenaMember member, int pointer) {
    _GestureArena state = _arenas[pointer];
    if (state == nullptr) {
        return;
    }
    assert(_debugLogDiagnostic(pointer, "${ disposition == GestureDisposition.accepted ? "Accepting" : "Rejecting" }: $member"));
    assert(state.members.contains(member));
    if (disposition == GestureDisposition.rejected) {
        state.members.remove(member);
        member.rejectGesture(pointer);
        if (!state.isOpen) {
            _tryToResolveArena(pointer, state);
        }
    } else {
        assert(disposition == GestureDisposition.accepted);
        if (state.isOpen) {
            state.eagerWinner = member;
        } else {
            assert(_debugLogDiagnostic(pointer, "Self-declared winner: $member"));
            _resolveInFavorOf(pointer, state, member);
        }
    }
}

void GestureArenaManager::_tryToResolveArena(int pointer, _GestureArena state) {
    assert(_arenas[pointer] == state);
    assert(!state.isOpen);
    if (state.members.length == 1) {
        scheduleMicrotask();
    } else     {
        if (state.members.isEmpty) {
        _arenas.remove(pointer);
        assert(_debugLogDiagnostic(pointer, "Arena empty."));
    } else     {
        if (state.eagerWinner != nullptr) {
        assert(_debugLogDiagnostic(pointer, "Eager winner: ${state.eagerWinner}"));
        _resolveInFavorOf(pointer, state, state.eagerWinner!);
    }
;
    };
    }}

void GestureArenaManager::_resolveByDefault(int pointer, _GestureArena state) {
    if (!_arenas.containsKey(pointer)) {
        return;
    }
    assert(_arenas[pointer] == state);
    assert(!state.isOpen);
    List<GestureArenaMember> members = state.members;
    assert(members.length == 1);
    _arenas.remove(pointer);
    assert(_debugLogDiagnostic(pointer, "Default winner: ${state.members.first}"));
    state.members.first.acceptGesture(pointer);
}

void GestureArenaManager::_resolveInFavorOf(GestureArenaMember member, int pointer, _GestureArena state) {
    assert(state == _arenas[pointer]);
    assert(state != nullptr);
    assert(state.eagerWinner == nullptr || state.eagerWinner == member);
    assert(!state.isOpen);
    _arenas.remove(pointer);
    for (GestureArenaMember rejectedMember : state.members) {
        if (rejectedMember != member) {
            rejectedMember.rejectGesture(pointer);
        }
    }
    member.acceptGesture(pointer);
}

bool GestureArenaManager::_debugLogDiagnostic(String message, int pointer, _GestureArena state) {
    assert(());
    return true;
}
