#ifndef CLIPBOARD_H
#define CLIPBOARD_H
#include <memory>

#include <flutter/foundation.hpp>
#include "system_channels.hpp"



class ClipboardData {
public:
    String text;


     ClipboardData(String text);

private:

};

class Clipboard {
public:
    static const String kTextPlain;


    static Future<void> setData(ClipboardData data);

    static Future<ClipboardData> getData(String format);

    static Future<bool> hasStrings();

private:

    void  _();

};

#endif