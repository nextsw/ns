#include "annotations.hpp"
CategoryCls::CategoryCls(List<String> sections) {
    {
        assert(sections != nullptr);
    }
}

DocumentationIconCls::DocumentationIconCls(String url) {
    {
        assert(url != nullptr);
    }
}

SummaryCls::SummaryCls(String text) {
    {
        assert(text != nullptr);
    }
}
