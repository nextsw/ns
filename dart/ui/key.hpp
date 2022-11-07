#ifndef KEY_H
#define KEY_H
#include <memory>




enum KeyEventType{
    down,
    up,
    repeat,
} // end KeyEventType

class KeyData {
public:
    Duration timeStamp;

    KeyEventType type;

    int physical;

    int logical;

    String character;

    bool synthesized;


     KeyData(String character, int logical, int physical, bool synthesized, Duration timeStamp, KeyEventType type);

    String toString();

    String toStringFull();

private:

    static int _nonValueBits(int n);

    String _logicalToString();

    String _escapeCharacter();

    String _quotedCharCode();

    static String _typeToString(KeyEventType type);

};

#endif