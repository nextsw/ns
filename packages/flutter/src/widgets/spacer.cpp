#include "spacer.hpp"
Spacer::Spacer(int flex, Unknown) {
    {
        assert(flex != nullptr);
        assert(flex > 0);
    }
}

Widget Spacer::build(BuildContext context) {
    return Expanded(flex, const SizedBox.shrink());
}
