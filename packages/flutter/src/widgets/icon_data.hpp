#ifndef ICON_DATA_H
#define ICON_DATA_H
#include <memory>

#include <flutter/foundation.hpp>



class IconData {
public:
    int codePoint;

    String fontFamily;

    String fontPackage;

    bool matchTextDirection;


     IconData(int codePoint, String fontFamily, String fontPackage, bool matchTextDirection);

    bool ==(Object other);

    int hashCode();

    String toString();

private:

};

class IconDataProperty : DiagnosticsProperty<IconData> {
public:

     IconDataProperty(Unknown, Unknown, String name, Unknown, Unknown, Unknown);

    Map<String, Object> toJsonMap(DiagnosticsSerializationDelegate delegate);

private:

};

#endif