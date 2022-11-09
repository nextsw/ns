#ifndef DART_UI_KEY
#define DART_UI_KEY
#include <base.hpp>

#include <dart/core/core.hpp>


enum KeyEventType{
    down,
    up,
    repeat,
} // end KeyEventType

class KeyDataCls : public ObjectCls {
public:
    Duration timeStamp;

    KeyEventType type;

    int physical;

    int logical;

    String character;

    bool synthesized;


     KeyDataCls(String character, int logical, int physical, bool synthesized, Duration timeStamp, KeyEventType type);
    virtual String toString();

    virtual String toStringFull();

private:

    static int _nonValueBits(int n);

    virtual String _logicalToString();

    virtual String _escapeCharacter();

    virtual String _quotedCharCode();

    static String _typeToString(KeyEventType type);

};
using KeyData = std::shared_ptr<KeyDataCls>;


#endif