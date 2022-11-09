#include "disposable_build_context.hpp"
template<typename T : State> DisposableBuildContextCls<T>::DisposableBuildContextCls(T _state) {
    {
        assert(_state != nullptr);
        assert(_state->mounted, "A DisposableBuildContext was given a BuildContext for an Element that is not mounted.");
    }
}

template<typename T : State> BuildContext DisposableBuildContextCls<T>::context() {
    assert(_debugValidate());
    if (_state == nullptr) {
        return nullptr;
    }
    return _state!->context;
}

template<typename T : State> void DisposableBuildContextCls<T>::dispose() {
    _state = nullptr;
}

template<typename T : State> bool DisposableBuildContextCls<T>::_debugValidate() {
    assert(_state == nullptr || _state!->mounted, "A DisposableBuildContext tried to access the BuildContext of a disposed State object. This can happen when the creator of this DisposableBuildContext fails to call dispose when it is disposed.");
    return true;
}
