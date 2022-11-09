#ifndef PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_UNICODE
#define PACKAGES_FLUTTER_LIB_SRC_FOUNDATION_UNICODE
#include <base.hpp>

#include <dart/core/core.hpp>


class UnicodeCls : public ObjectCls {
public:
    static String LRE;

    static String RLE;

    static String PDF;

    static String LRO;

    static String RLO;

    static String LRI;

    static String RLI;

    static String FSI;

    static String PDI;

    static String LRM;

    static String RLM;

    static String ALM;


private:

    virtual void  _();
};
using Unicode = std::shared_ptr<UnicodeCls>;


#endif