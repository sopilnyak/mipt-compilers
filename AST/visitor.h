#ifndef MINIJAVA_VISITOR_H
#define MINIJAVA_VISITOR_H

#include "visitable.h"

namespace AST {

    class Program;
    class MainClass;
    class ClassDeclarationList;
    class ClassDeclaration;

    class VarDeclarationList;
    class VarDeclaration;

    class MethodDeclarationList;
    class MethodDeclaration;
    class MethodModifier;

    class ArgumentList;
    class Argument;

    class IType;
    class PrimitiveType;
    class ClassType;

    class IStatement;
    class Statements;
    class StatementList;
    class IfElseStatement;
    class WhileStatement;
    class SystemOutStatement;
    class AssignStatement;
    class ArrayAssignStatement;

    class IExpression;
    class ExpressionList;
    class BinaryExpression;
    class ArrayMemberExpression;
    class ArrayLengthExpression;
    class CallMemberExpression;
    class IntegerExpression;
    class BooleanExpression;
    class ThisExpression;
    class IntArrayExpression;
    class ObjectExpression;
    class NotExpression;
    class IdExpression;

    class Id;

    class Visitor
    {
    public:
        virtual void visit(const Program*) = 0;
        virtual void visit(const MainClass*) = 0;
        virtual void visit(const ClassDeclaration*) = 0;
        virtual void visit(const VarDeclaration*) = 0;
        virtual void visit(const MethodDeclaration*) = 0;
        virtual void visit(const Argument*) = 0;
        virtual void visit(const Statements*) = 0;
        virtual void visit(const IfElseStatement*) = 0;
        virtual void visit(const WhileStatement*) = 0;
        virtual void visit(const SystemOutStatement*) = 0;
        virtual void visit(const AssignStatement*) = 0;
        virtual void visit(const ArrayAssignStatement*) = 0;
        virtual void visit(const BinaryExpression*) = 0;
        virtual void visit(const ArrayMemberExpression*) = 0;
        virtual void visit(const ArrayLengthExpression*) = 0;
        virtual void visit(const CallMemberExpression*) = 0;
        virtual void visit(const IntegerExpression*) = 0;
        virtual void visit(const BooleanExpression*) = 0;
        virtual void visit(const ThisExpression*) = 0;
        virtual void visit(const IntArrayExpression*) = 0;
        virtual void visit(const ObjectExpression*) = 0;
        virtual void visit(const NotExpression*) = 0;
        virtual void visit(const IdExpression*) = 0;
        virtual void visit(const Id*) = 0;
        virtual ~Visitor() = default;
    };

}

#endif // MINIJAVA_VISITOR_H
