#ifndef MINIJAVA_ID_H
#define MINIJAVA_ID_H

#include "visitor.h"
#include <string>

namespace AST {

    class Id: public Visitable
    {
    public:
        explicit Id(const std::string &name, Coordinates coordinates):
                coordinates_(coordinates)
        {
            if (!name.empty())
            {
                name_ = name;
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::string getName() {
            return name_;
        }

        std::string name_;
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_ID_H
