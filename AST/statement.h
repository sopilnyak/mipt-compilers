#ifndef MINIJAVA_STATEMENT_H
#define MINIJAVA_STATEMENT_H

#include "visitable.h"
#include "visitor.h"
#include "method_declaration.h"

#include <vector>
#include <string>
#include <memory>

namespace AST {

    class IStatement: public Visitable
    {
    public:
        IStatement() = default;
        virtual ~IStatement() = default;
        virtual void accept(Visitor* visitor) {};
    };

    class StatementList: public IStatement
    {
    public:
        explicit StatementList(StatementList* previousList, IStatement* statement, Coordinates coordinates):
                coordinates_(coordinates)
        {
            statements_.clear();
            if (previousList != nullptr)
            {
                statements_ = std::move(previousList->getStatements());
            }
            statements_.push_back(statement);
        }

        std::vector<IStatement*> getStatements()
        {
            return statements_;
        }

        std::vector<IStatement*> statements_{};
        Coordinates coordinates_;
    };

    class Statements: public IStatement
    {
    public:
        explicit Statements(StatementList* statements, Coordinates coordinates):
                coordinates_(coordinates)
        {
            statements_.clear();
            statements_= std::move(statements->getStatements());
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::vector<IStatement*> statements_{};
        Coordinates coordinates_;
    };

    class IfElseStatement: public IStatement
    {
    public:
        explicit IfElseStatement(IExpression* condition, IStatement* actionIf, IStatement* actionElse, Coordinates coordinates):
                condition_(condition), actionIf_(actionIf), actionElse_(actionElse), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        IExpression* condition_{};
        IStatement* actionIf_;
        IStatement* actionElse_;
        Coordinates coordinates_;
    };

    class WhileStatement: public IStatement
    {
    public:
        explicit WhileStatement(IExpression* condition, IStatement* action, Coordinates coordinates):
                condition_(condition), action_(action), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> condition_{};
        std::unique_ptr<IStatement> action_{};
        Coordinates coordinates_;
    };

    class SystemOutStatement: public IStatement
    {
    public:
        explicit SystemOutStatement(IExpression* toPrint, Coordinates coordinates):
                toPrint_(toPrint), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> toPrint_{};
        Coordinates coordinates_;
    };

    class AssignStatement: public IStatement
    {
    public:
        explicit AssignStatement(Id* lhs, IExpression* rhs, Coordinates coordinates):
                lhs_(lhs), rhs_(rhs), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> lhs_{};
        std::unique_ptr<IExpression> rhs_{};
        Coordinates coordinates_;
    };

    class ArrayAssignStatement: public IStatement
    {
    public:
        explicit ArrayAssignStatement(Id* lhs, IExpression* index, IExpression* rhs, Coordinates coordinates):
                lhs_(lhs), index_(index), rhs_(rhs), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> lhs_{};
        std::unique_ptr<IExpression> index_{};
        std::unique_ptr<IExpression> rhs_{};
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_STATEMENT_H
