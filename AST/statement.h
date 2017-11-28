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
        explicit StatementList(StatementList* previousList, IStatement* statement)
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

        std::vector<IStatement*> statements_;
    };

    class Statements: public IStatement
    {
    public:
        explicit Statements(StatementList* statements)
        {
            statements_.clear();
            statements_= std::move(statements->getStatements());
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::vector<IStatement*> statements_;
    };

    class IfElseStatement: public IStatement
    {
    public:
        explicit IfElseStatement(IExpression* condition, IStatement* actionIf, IStatement* actionElse):
                condition_(condition), actionIf_(actionIf), actionElse_(actionElse)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        IExpression* condition_;
        IStatement* actionIf_;
        IStatement* actionElse_;
    };

    class WhileStatement: public IStatement
    {
    public:
        explicit WhileStatement(IExpression* condition, IStatement* action):
                condition_(condition), action_(action)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> condition_;
        std::unique_ptr<IStatement> action_;
    };

    class SystemOutStatement: public IStatement
    {
    public:
        explicit SystemOutStatement(IExpression* toPrint):
                toPrint_(toPrint)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> toPrint_;
    };

    class AssignStatement: public IStatement
    {
    public:
        explicit AssignStatement(Id* lValue, IExpression* rValue):
                lValue_(lValue), rValue_(rValue)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> lValue_;
        std::unique_ptr<IExpression> rValue_;
    };

    class ArrayAssignStatement: public IStatement
    {
    public:
        explicit ArrayAssignStatement(Id* lValue, IExpression* index, IExpression* rValue):
                lValue_(lValue), index_(index), rValue_(rValue)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> lValue_;
        std::unique_ptr<IExpression> index_;
        std::unique_ptr<IExpression> rValue_;
    };

}

#endif // MINIJAVA_STATEMENT_H
