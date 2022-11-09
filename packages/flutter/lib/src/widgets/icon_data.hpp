#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON_DATA
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_ICON_DATA
#include <base.hpp>

#include <dart/core/core.hpp>
#include <packages/flutter/lib/foundation.hpp>


class IconDataCls : public ObjectCls {
public:
    int codePoint;

    String fontFamily;

    String fontPackage;

    bool matchTextDirection;


     IconDataCls(int codePoint, String fontFamily, String fontPackage, bool matchTextDirection);
    virtual bool operator==(Object other);

    virtual int hashCode();

    virtual String toString();

private:

};
using IconData = std::shared_ptr<IconDataCls>;

class IconDataPropertyCls : public DiagnosticsPropertyCls<IconData> {
public:

     IconDataPropertyCls(Unknown ifNull, Unknown level, String name, Unknown showName, Unknown style, Unknown value);

    virtual Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};
using IconDataProperty = std::shared_ptr<IconDataPropertyCls>;


#endif