#ifndef TABLE_VISITOR_H
#define TABLE_VISITOR_H

#include "Table.h"
#include "../AST/visitor.h"
#include "../AST/node_types.h"
#include "../SymbolTable/Table.h"

namespace SymbolTable {

    class TableVisitor : public AST::Visitor {

    public:
        void ParseProgram(AST::Program* program);

        void visit(const AST::Program*) override;
        void visit(const AST::MainClass*) override;
        void visit(const AST::ClassDeclaration*) override;
        void visit(const AST::VarDeclaration*) override {}
        void visit(const AST::MethodDeclaration*) override {}
        void visit(const AST::Argument*) override {}
        void visit(const AST::IType*) override {}
        void visit(const AST::Statements*) override {}
        void visit(const AST::IfElseStatement*) override {}
        void visit(const AST::WhileStatement*) override {}
        void visit(const AST::SystemOutStatement*) override {}
        void visit(const AST::AssignStatement*) override {}
        void visit(const AST::ArrayAssignStatement*) override {}
        void visit(const AST::BinaryExpression*) override {}
        void visit(const AST::ArrayMemberExpression*) override {}
        void visit(const AST::ArrayLengthExpression*) override {}
        void visit(const AST::CallMemberExpression*) override {}
        void visit(const AST::IntegerExpression*) override {}
        void visit(const AST::BooleanExpression*) override {}
        void visit(const AST::ThisExpression*) override {}
        void visit(const AST::IntArrayExpression*) override {}
        void visit(const AST::ObjectExpression*) override {}
        void visit(const AST::NotExpression*) override {}
        void visit(const AST::IdExpression*) override {}
        void visit(const AST::Id*) override {}

    private:
        Table table{};
        Position fromCoords(const AST::Coordinates& coords) { return {coords.Column, coords.Row}; }
        TypeInfo fromType(const AST::IType* type);
        void printClassInfo(const ClassInfo* classInfo);
        void printVariable(const VariableInfo* varInfo);
        void printType(const TypeInfo& varInfo);
    };

}

#endif
