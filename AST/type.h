#ifndef MINIJAVA_TYPE_H
#define MINIJAVA_TYPE_H

#include "id.h"
#include "visitable.h"

#include <string>

namespace AST {

    enum TypeValue {
        T_INT_ARRAY,
        T_BOOLEAN,
        T_INT,
        T_CLASS
    };

    class IType : public Visitable
    {
    public:
        std::string type_name_;
        TypeValue type_value_;

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }
    };

    class PrimitiveType: public IType
    {
    public:
        PrimitiveType(TypeValue type, Coordinates coordinates):
                IType(), type_value_(type), coordinates_(coordinates)
        {
            if (type_value_ == T_INT_ARRAY) {
                type_name_ = "int[]";
            }
            if (type_value_ == T_BOOLEAN) {
                type_name_ = "boolean";
            }
            if (type_value_ == T_INT) {
                type_name_ = "int";
            }
        }
        TypeValue type_value_;
        Coordinates coordinates_;
    };

    class ClassType: public IType
    {
    public:
        ClassType(Id* id_, Coordinates coordinates):
                id(id_), coordinates_(coordinates),

        IType() {
            type_name_ = id->getName();
            type_value_ = T_CLASS;
        }

        std::unique_ptr<Id> id;
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_TYPE_H
