#ifndef MINIJAVA_PRINTER_H
#define MINIJAVA_PRINTER_H

#include "program.h"
#include "argument.h"
#include "class_declaration.h"
#include "expression.h"
#include "id.h"
#include "method_declaration.h"
#include "method_modifier.h"
#include "print_visitor.h"
#include "statement.h"
#include "type.h"
#include "var_declaration.h"

#include <string>
#include <fstream>

namespace AST {

    class PrintVisitor: public Visitor
    {
    public:
        explicit PrintVisitor(std::string path);
        ~PrintVisitor() override;

        void printEdge(const Visitable* from, const Visitable* to);
        void printVertex(const Visitable* node, std::string label);
        void printEdge(const Visitable* from, const Visitable* to, std::string label);

        virtual void visit(const Program*);
        virtual void visit(const MainClass*);
        virtual void visit(const ClassDeclaration*);
        virtual void visit(const VarDeclaration*);
        virtual void visit(const MethodDeclaration*);
        virtual void visit(const Argument*);
        virtual void visit(const Statements*);
        virtual void visit(const IfElseStatement*);
        virtual void visit(const WhileStatement*);
        virtual void visit(const SystemOutStatement*);
        virtual void visit(const AssignStatement*);
        virtual void visit(const ArrayAssignStatement*);
        virtual void visit(const BinaryExpression*);
        virtual void visit(const ArrayMemberExpression*);
        virtual void visit(const ArrayLengthExpression*);
        virtual void visit(const CallMemberExpression*);
        virtual void visit(const IntegerExpression*);
        virtual void visit(const BooleanExpression*);
        virtual void visit(const ThisExpression*);
        virtual void visit(const IntArrayExpression*);
        virtual void visit(const ObjectExpression*);
        virtual void visit(const NotExpression*);
        virtual void visit(const IdExpression*);
        virtual void visit(const Id*);

    private:
        std::ofstream output;

    };

}

#endif // MINIJAVA_PRINTER_H
