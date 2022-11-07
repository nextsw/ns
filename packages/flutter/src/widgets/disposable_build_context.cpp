#include "disposable_build_context.hpp"
DisposableBuildContext::DisposableBuildContext(T _state) {
    {
        assert(_state != nullptr);
        assert(_state.mounted, "A DisposableBuildContext was given a BuildContext for an Element that is not mounted.");
    }
}

BuildContext DisposableBuildContext::context() {
    assert(_debugValidate());
    if (_state == nullptr) {
        return nullptr;
    }
    return _state!.context;
}

void DisposableBuildContext::dispose() {
    _state = nullptr;
}

bool DisposableBuildContext::_debugValidate() {
    assert(_state == nullptr || _state!.mounted, "A DisposableBuildContext tried to access the BuildContext of a disposed State object. This can happen when the creator of this DisposableBuildContext fails to call dispose when it is disposed.");
    return true;
}
