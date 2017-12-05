#ifndef MINIJAVA_ARGUMENT_H
#define MINIJAVA_ARGUMENT_H

#include "visitable.h"
#include <vector>
#include <memory>

namespace AST {

    class Argument: public Visitable
    {
    public:
        explicit Argument(IType* type, Id* id, Coordinates coordinates):
                type_(type), id_(id), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        Coordinates coordinates_;
        std::unique_ptr<IType> type_{};
        std::unique_ptr<Id> id_{};
    };

    class ArgumentList
    {
    public:
        explicit ArgumentList(ArgumentList* previousList, IType* type, Id* id, Coordinates coordinates):
                coordinates_(coordinates)
        {
            arguments_.clear();
            if (previousList != nullptr)
            {
                arguments_ = std::move(previousList->getArguments());
            }
            arguments_.push_back(new Argument(type, id, coordinates_));
        }

        ArgumentList(IType* type, Id* id, Coordinates coordinates):
                coordinates_(coordinates)
        {
            Argument* argument = new Argument(type, id, coordinates);
            arguments_.clear();
            arguments_.push_back(argument);
        }

        std::vector<Argument*> getArguments() const
        {
            return arguments_;
        }

        std::vector<Argument*> arguments_{};
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_ARGUMENT_H
