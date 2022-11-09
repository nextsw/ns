#ifndef DART_UI_HASH_CODES
#define DART_UI_HASH_CODES
#include <base.hpp>

#include <dart/core/core.hpp>


class _HashEndCls : public ObjectCls {
public:

private:

     _HashEndCls();
};
using _HashEnd = std::shared_ptr<_HashEndCls>;
_HashEnd _hashEnd;


class _JenkinsCls : public ObjectCls {
public:

    static int combine(int hash, Object o);

    static int finish(int hash);

private:

};
using _Jenkins = std::shared_ptr<_JenkinsCls>;
int hashValues(Object arg01, Object arg02, Object arg03, Object arg04, Object arg05, Object arg06, Object arg07, Object arg08, Object arg09, Object arg10, Object arg11, Object arg12, Object arg13, Object arg14, Object arg15, Object arg16, Object arg17, Object arg18, Object arg19, Object arg20);

int hashList(Iterable<Object> arguments);



#endif