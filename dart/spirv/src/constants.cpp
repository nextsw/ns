#include "constants.hpp"
String _operatorString(_Operator op) {
    return _operatorStrings[op]!;
}

bool _isCompoundAssignment(_Operator op) {
    return _compoundAssignmentOperators.contains(op);
}
