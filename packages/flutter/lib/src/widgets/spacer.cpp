#include "spacer.hpp"
SpacerCls::SpacerCls(int flex, Unknown key) {
    {
        assert(flex != nullptr);
        assert(flex > 0);
    }
}

Widget SpacerCls::build(BuildContext context) {
    return make<ExpandedCls>(flex, SizedBoxCls->shrink());
}
