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
        explicit ExpressionList(ExpressionList* previousList, IExpression* expression, Coordinates coordinates):
                coordinates_(coordinates)
        {
            expressions_.clear();
            if (previousList != nullptr)
            {
                expressions_ = std::move(previousList->getExpressions());
            }
            expressions_.push_back(expression);
        }

        explicit ExpressionList(IExpression* expression, Coordinates coordinates):
                coordinates_(coordinates)
        {
            expressions_.clear();
            expressions_.push_back(expression);
        }

        std::vector<IExpression*> getExpressions()
        {
            return expressions_;
        }

        std::vector<IExpression*> expressions_;
        Coordinates coordinates_;
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
        explicit BinaryExpression(BinaryExpressionValue type, IExpression* left, IExpression* right, Coordinates coordinates):
                type_(type), left_(left), right_(right), coordinates_(coordinates)
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
        Coordinates coordinates_;
    };

    class ArrayMemberExpression: public IExpression
    {
    public:
        explicit ArrayMemberExpression(IExpression* object, IExpression* index, Coordinates coordinates):
                object_(object), index_(index), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> object_;
        std::unique_ptr<IExpression> index_;
        Coordinates coordinates_;
    };

    class ArrayLengthExpression: public IExpression
    {
    public:
        explicit ArrayLengthExpression(IExpression* object, Coordinates coordinates):
                object_(object), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> object_;
        Coordinates coordinates_;
    };

    class CallMemberExpression: public IExpression
    {
    public:
        explicit CallMemberExpression(IExpression* expression, Id* id, ExpressionList* parameters, Coordinates coordinates):
                expression_(expression), id_(id), coordinates_(coordinates)
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
        Coordinates coordinates_;
    };

    class IntegerExpression: public IExpression
    {
    public:
        explicit IntegerExpression(int value, Coordinates coordinates):
                value_(value), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        int value_;
        Coordinates coordinates_;
    };

    enum BooleanExpressionValue
    {
        T_TRUE,
        T_FALSE
    };

    class BooleanExpression: public IExpression
    {
    public:
        explicit BooleanExpression(BooleanExpressionValue value, Coordinates coordinates):
                value_(value), coordinates_(coordinates)
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
        Coordinates coordinates_;
    };

    class ThisExpression: public IExpression
    {
    public:
        ThisExpression(Coordinates coordinates):
                coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        Coordinates coordinates_;
    };

    class IntArrayExpression: public IExpression
    {
    public:
        explicit IntArrayExpression(IExpression* size, Coordinates coordinates):
                size_(size), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> size_;
        Coordinates coordinates_;
    };

    class ObjectExpression: public IExpression
    {
    public:
        explicit ObjectExpression(Id* id, Coordinates coordinates):
                id_(id), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> id_;
        Coordinates coordinates_;
    };

    class NotExpression: public IExpression
    {
    public:
        explicit NotExpression(IExpression* expression, Coordinates coordinates):
                expression_(expression), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<IExpression> expression_;
        Coordinates coordinates_;
    };

    class IdExpression: public IExpression
    {
    public:
        explicit IdExpression(Id* id, Coordinates coordinates):
                id_(id), coordinates_(coordinates)
        {}

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> id_;
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_EXPRESSION_H
