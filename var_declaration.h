#ifndef MINIJAVA_VAR_DECLARATION_H
#define MINIJAVA_VAR_DECLARATION_H

#include "visitor.h"
#include <vector>

class VarDeclaration: public Visitable
{
public:
    explicit VarDeclaration(IType* type, Id* id):
            type_(type), id_(id)
    {}

    void accept(Visitor* visitor) override
    {
        visitor->visit(this);
    }

    IType* type_;
    Id* id_;
};

class VarDeclarationList
{
public:
    explicit VarDeclarationList(VarDeclarationList* previousList, VarDeclaration* declaration)
    {
        var_declarations_.clear();
        if (previousList != nullptr)
        {
            var_declarations_ = std::move(previousList->getVarDeclarations());
        }
        var_declarations_.push_back(declaration);
    }

    std::vector<VarDeclaration*> getVarDeclarations()
    {
        return var_declarations_;
    }

    std::vector<VarDeclaration*> var_declarations_;
};

#endif //MINIJAVA_VAR_DECLARATION_H
