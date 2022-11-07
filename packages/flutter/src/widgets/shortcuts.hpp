#ifndef SHORTCUTS_H
#define SHORTCUTS_H
#include <memory>

#include <collection/collection.hpp>
#include <flutter/foundation.hpp>
#include <flutter/services.hpp>
#include "actions.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "platform_menu_bar.hpp"



class KeySet<T extends KeyboardKey> {
public:
    int hashCode;


     KeySet(T key1, T key2, T key3, T key4);

    void  fromSet(Set<T> keys);

    Set<T> keys();

    bool ==(Object other);

private:
    HashSet<T> _keys;

    static List<int> _tempHashStore3;

    static List<int> _tempHashStore4;


    static int _computeHashCode<T>(Set<T> keys);

};

class ShortcutActivator {
public:

     ShortcutActivator();

    Iterable<LogicalKeyboardKey> triggers();

    bool accepts(RawKeyEvent event, RawKeyboard state);

    static bool isActivatedBy(ShortcutActivator activator, RawKeyEvent event);

    String debugDescribeKeys();

private:

};

class LogicalKeySet : KeySet<LogicalKeyboardKey> {
public:

     LogicalKeySet(Unknown, Unknown, Unknown, Unknown);

    void  fromSet(Unknown);

    Iterable<LogicalKeyboardKey> triggers();

    bool accepts(RawKeyEvent event, RawKeyboard state);

    String debugDescribeKeys();

    void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<LogicalKeyboardKey> _triggers;

    static Set<LogicalKeyboardKey> _modifiers;

    static Map<LogicalKeyboardKey, List<LogicalKeyboardKey>> _unmapSynonyms;


};

#endif