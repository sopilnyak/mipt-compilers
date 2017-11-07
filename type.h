#ifndef MINIJAVA_TYPE_H
#define MINIJAVA_TYPE_H

#include "id.h"

#include <string>

enum PrimitiveTypeValue {
    T_INT_ARRAY,
    T_BOOLEAN,
    T_INT
};

class IType
{
public:
    std::string type_name_;
};

class PrimitiveType: public IType
{
public:
    explicit PrimitiveType(PrimitiveTypeValue type):
            type_(type)
    {
        if (type_ == T_INT_ARRAY) {
            type_name_ = "int[]";
        }
        if (type_ == T_BOOLEAN) {
            type_name_ = "boolean";
        }
        if (type_ == T_INT) {
            type_name_ = "int";
        }
    }

    PrimitiveTypeValue type_;
};

class ClassType: public IType
{
public:
    explicit ClassType(Id* id_):
            id(id_)
    {
        type_name_ = id->getName();
    }

    std::unique_ptr<Id> id;
};

#endif // MINIJAVA_TYPE_H
