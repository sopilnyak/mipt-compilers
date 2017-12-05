#ifndef MINIJAVA_METHOD_MODIFIER_H
#define MINIJAVA_METHOD_MODIFIER_H

#include "visitor.h"

namespace AST {

    enum MethodModifierValue
    {
        T_PUBLIC,
        T_PRIVATE
    };

    class MethodModifier
    {
    public:
        explicit MethodModifier(MethodModifierValue modifier, Coordinates coordinates):
                modifier_(modifier), coordinates_(coordinates)
        {
            switch (modifier) {
                case T_PUBLIC:
                    string_modifier_ = "public";
                case T_PRIVATE:
                    string_modifier_ = "private";
            }
        }

        MethodModifierValue modifier_;
        std::string string_modifier_;
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_METHOD_MODIFIER_H
