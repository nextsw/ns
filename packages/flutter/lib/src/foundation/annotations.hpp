#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_ANNOTATIONS
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_ANNOTATIONS
#include <base.hpp>

#include <dart/core/core.hpp>


class CategoryCls : public ObjectCls {
public:
    List<String> sections;


     CategoryCls(List<String> sections);

private:

};
using Category = std::shared_ptr<CategoryCls>;

class DocumentationIconCls : public ObjectCls {
public:
    String url;


     DocumentationIconCls(String url);

private:

};
using DocumentationIcon = std::shared_ptr<DocumentationIconCls>;

class SummaryCls : public ObjectCls {
public:
    String text;


     SummaryCls(String text);

private:

};
using Summary = std::shared_ptr<SummaryCls>;


#endif