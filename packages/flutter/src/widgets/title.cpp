#include "title.hpp"
Title::Title(Widget child, Color color, Unknown, String title) {
    {
        assert(title != nullptr);
        assert(color != nullptr && color.alpha == 0xFF);
    }
}

Widget Title::build(BuildContext context) {
    SystemChrome.setApplicationSwitcherDescription(ApplicationSwitcherDescription(title, color.value));
    return child;
}

void Title::debugFillProperties(DiagnosticPropertiesBuilder properties) {
    super.debugFillProperties(properties);
    properties.add(StringProperty("title", title""));
    properties.add(ColorProperty("color", colornullptr));
}
