#ifndef MINIJAVA_METHOD_DECLARATION_H
#define MINIJAVA_METHOD_DECLARATION_H

#include "visitor.h"
#include "var_declaration.h"
#include "statement.h"
#include "argument.h"

#include <vector>
#include <memory>

namespace AST {

    class MethodDeclaration: public Visitable
    {
    public:
        explicit MethodDeclaration(MethodModifier* modifier, IType* type, Id* id,
                          ArgumentList* arguments, VarDeclarationList* vars,
                          StatementList* statements, IExpression* expression):
                modifier_(modifier),
                type_(type),
                id_(id),
                expression_(expression)
        {
            arguments_.clear();
            if (arguments != nullptr) {
                arguments_ = std::move(arguments->getArguments());
            }

            vars_.clear();
            if (vars != nullptr) {
                vars_ = std::move(vars->getVarDeclarations());
            }

            statements_.clear();
            if (statements != nullptr) {
                statements_ = std::move(statements->getStatements());
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<MethodModifier> modifier_;
        std::unique_ptr<IType> type_;
        std::unique_ptr<Id> id_;
        std::vector<Argument*> arguments_;
        std::vector<VarDeclaration*> vars_;
        std::vector<IStatement*> statements_;
        std::unique_ptr<IExpression> expression_;
    };

    class MethodDeclarationList
    {
    public:
        explicit MethodDeclarationList(MethodDeclarationList* previousList, MethodDeclaration* method)
        {
            methods_.clear();
            if (previousList != nullptr)
            {
                methods_ = std::move(previousList->getMethods());
            }
            methods_.push_back(method);
        }

        std::vector<MethodDeclaration*> getMethods() {
            return methods_;
        }

        std::vector<MethodDeclaration*> methods_;
    };

}

#endif // MINIJAVA_METHOD_DECLARATION_H
