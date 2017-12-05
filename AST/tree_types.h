#ifndef TREETYPES_H
#define TREETYPES_H

#include "visitor.h"

namespace AST {

template <typename T>
VISIT_NODE(Sequence<T>)

}

#endif // TREETYPES_H
