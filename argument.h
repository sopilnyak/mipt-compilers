#ifndef MINIJAVA_ARGUMENT_H
#define MINIJAVA_ARGUMENT_H

#include "visitable.h"
#include <vector>

class Argument: public Visitable
{
public:
    explicit Argument(IType* type, Id* id):
            type_(type), id_(id)
    {}

    void accept(Visitor* visitor) override
    {
        visitor->visit(this);
    }

    IType* type_;
    Id* id_;
};

class ArgumentList
{
public:
    explicit ArgumentList(ArgumentList* previousList, IType* type, Id* id)
    {
        arguments_.clear();
        if (previousList != nullptr)
        {
            arguments_ = std::move(previousList->getArguments());
        }
        arguments_.push_back(new Argument(type, id));
    }

    ArgumentList(IType* type, Id* id)
    {
        Argument* argument = new Argument(type, id);
        arguments_.clear();
        arguments_.push_back(argument);
    }

    std::vector<Argument*> getArguments() const
    {
        return arguments_;
    }

    std::vector<Argument*> arguments_;
};

#endif // MINIJAVA_ARGUMENT_H