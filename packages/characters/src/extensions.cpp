#include "extensions.hpp"
Characters StringCharactersCls::characters() {
    return make<CharactersCls>(this);
}
