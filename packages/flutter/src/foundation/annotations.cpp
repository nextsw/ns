#include "annotations.hpp"
Category::Category(List<String> sections) {
    {
        assert(sections != nullptr);
    }
}

DocumentationIcon::DocumentationIcon(String url) {
    {
        assert(url != nullptr);
    }
}

Summary::Summary(String text) {
    {
        assert(text != nullptr);
    }
}
