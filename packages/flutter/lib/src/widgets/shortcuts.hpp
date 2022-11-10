#ifndef PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SHORTCUTS
#define PACKAGES_FLUTTER_LIB_SRC_WIDGETS_SHORTCUTS
#include <base.hpp>

#include <dart/core/core.hpp>
#include <dart/collection/collection.hpp>
#include <packages/flutter/lib/foundation.hpp>
#include <packages/flutter/flutter.hpp>
#include "actions.hpp"
#include "focus_manager.hpp"
#include "focus_scope.hpp"
#include "framework.hpp"
#include "platform_menu_bar.hpp"


template<typename T> class KeySetCls : public ObjectCls {
public:
    int hashCode;


     KeySetCls(T key1, T key2, T key3, T key4);

    virtual void  fromSet(Set<T> keys);

    virtual Set<T> keys();

    virtual bool operator==(Object other);

private:
    HashSet<T> _keys;

    static List<int> _tempHashStore3;

    static List<int> _tempHashStore4;


    template<typename T>  static int _computeHashCode(Set<T> keys);

};
template<typename T> using KeySet = std::shared_ptr<KeySetCls<T>>;

class ShortcutActivatorCls : public ObjectCls {
public:

     ShortcutActivatorCls();
    virtual Iterable<LogicalKeyboardKey> triggers();
    virtual bool accepts(RawKeyEvent event, RawKeyboard state);
    static bool isActivatedBy(ShortcutActivator activator, RawKeyEvent event);

    virtual String debugDescribeKeys();
private:

};
using ShortcutActivator = std::shared_ptr<ShortcutActivatorCls>;

class LogicalKeySetCls : public KeySetCls<LogicalKeyboardKey> {
public:

     LogicalKeySetCls(Unknown key1, Unknown key2, Unknown key3, Unknown key4);
    virtual void  fromSet(Unknown keys);

    virtual Iterable<LogicalKeyboardKey> triggers();

    virtual bool accepts(RawKeyEvent event, RawKeyboard state);

    virtual String debugDescribeKeys();

    virtual void debugFillProperties(DiagnosticPropertiesBuilder properties);

private:
    Set<LogicalKeyboardKey> _triggers;

    static Set<LogicalKeyboardKey> _modifiers;

    static Map<LogicalKeyboardKey, List<LogicalKeyboardKey>> _unmapSynonyms;


};
using LogicalKeySet = std::shared_ptr<LogicalKeySetCls>;


#endif