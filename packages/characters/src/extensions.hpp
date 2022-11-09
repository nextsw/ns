#ifndef PACKAGES_CHARACTERS_SRC_EXTENSIONS
#define PACKAGES_CHARACTERS_SRC_EXTENSIONS
#include <base.hpp>

#include <dart/core/core.hpp>
#include "characters.hpp"


class StringCharactersCls : public ObjectCls {
public:

    virtual Characters characters();

private:

};
using StringCharacters = std::shared_ptr<StringCharactersCls>;


#endif