#ifndef MINIJAVA_EXPRESSION_H
#define MINIJAVA_EXPRESSION_H

#include "visitor.h"

#include <vector>
#include <string>

namespace AST {

    class IExpression: public Visitable
    {
    public:
        IExpression() = default;
        virtual ~IExpression() {}
        virtual void accept(Visitor* visitor) {};
    };

    class ExpressionList: public IExpression
    {
    public:
        explicit ExpressionList(ExpressionList* previousList, IExpression* expression)
        {
            expressions_.clear();
            if (previousList != nullptr)
            {
                expressions_ = std::move(previousList->getExpressions());
            }
            expressions_.push_back(expression);
        }

        explicit ExpressionList(IExpression* expression)
        {
            expressions_.clear();
            expressions_.push_back(expression);
        }

        std::vector<IExpression*> getExpressions()
        {
            return expressions_;
        }

        std::vector<IExpression*> expressions_;
    };

    enum BinaryExpressionValue
    {
        T_AND,
        T_OR,
        T_LESS,
        T_PLUS,
        T_MINUS,
        T_MULTIPLY,
        T_MOD
    };

    class BinaryExpression: public IExpression
    {
    public:
        explicit BinaryExpression(BinaryExpressionValue type, IExpression* left, IExpression* right):
                type_(type), left_(left), right_(right)
        {
            switch (type) {
                case T_AND:
                    string_type_ = "and";
                    break;
                case T_OR:
                    string_type_ = "or";
                    break;
                case T_LESS:
                    string_type_ = "<";
                    break;
                case T_MINUS:
                    string_type_ = "-";
                    break;
                case T_PLUS:
                    string_type_ = "+";
                    break;
                case T_MULTIPLY:
                    string_type_ = "*";
                    break;
                case T_MOD:
                    string_type_ = "%";
                    break;
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        BinaryExpressionValue type_;
        std::string string_type_;
        std::unique_ptr<IExpression> left_;
        std::unique_ptr<IExpression> right_;
    };

    class ArrayMemberExpression: public IExpression
    {
    public:
        explicit ArrayMemberExpression(IExpression* object, IExpression* index):
                object_(object), index_(index)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> object_;
        std::unique_ptr<IExpression> index_;
    };

    class ArrayLengthExpression: public IExpression
    {
    public:
        explicit ArrayLengthExpression(IExpression* object):
                object_(object)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> object_;
    };

    class CallMemberExpression: public IExpression
    {
    public:
        explicit CallMemberExpression(IExpression* expression, Id* id, ExpressionList* parameters):
                expression_(expression), id_(id)
        {
            parameters_.clear();
            if (parameters != nullptr) {
                parameters_ = std::move(parameters->getExpressions());
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> expression_;
        std::unique_ptr<Id> id_;
        std::vector<IExpression*> parameters_;
    };

    class IntegerExpression: public IExpression
    {
    public:
        explicit IntegerExpression(int value):
                value_(value)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        int value_;
    };

    enum BooleanExpressionValue
    {
        T_TRUE,
        T_FALSE
    };

    class BooleanExpression: public IExpression
    {
    public:
        explicit BooleanExpression(BooleanExpressionValue value):
                value_(value)
        {
            switch (value) {
                case T_TRUE:
                    string_value_ = "true";
                    break;
                case T_FALSE:
                    string_value_= "false";
                    break;
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        BooleanExpressionValue value_;
        std::string string_value_;
    };

    class ThisExpression: public IExpression
    {
    public:
        ThisExpression() = default;

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }
    };

    class IntArrayExpression: public IExpression
    {
    public:
        explicit IntArrayExpression(IExpression* size):
                size_(size)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> size_;
    };

    class ObjectExpression: public IExpression
    {
    public:
        explicit ObjectExpression(Id* id):
                id_(id)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> id_;
    };

    class NotExpression: public IExpression
    {
    public:
        explicit NotExpression(IExpression* expression):
                expression_(expression)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> expression_;
    };

    class IdExpression: public IExpression
    {
    public:
        explicit IdExpression(Id* id):
                id_(id)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> id_;
    };

}

#endif // MINIJAVA_EXPRESSION_H
