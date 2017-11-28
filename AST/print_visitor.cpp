#include "print_visitor.h"

#include <memory>

namespace AST {

    PrintVisitor::PrintVisitor(std::string path)
    {
        output.open(path);
        output << "digraph g {\n";
    }

    PrintVisitor::~PrintVisitor()
    {
        output << "}";
        output.close();
    }

    void PrintVisitor::visit(const Program* node)
    {
        printVertex(node, "Program");
        node->main_->accept(this);
        printEdge(node, node->main_.get());

        for (auto el : node->classes_)
        {
            el->accept(this);
            printEdge(node, el);
        }
    }

    void PrintVisitor::visit(const MainClass* node)
    {
        printVertex(node, "MainClass");
        node->id_->accept(this);
        printEdge(node, node->id_.get());
        node->parameters_->accept(this);
        printEdge(node, node->parameters_, "parameter_id");

        for (auto statement : node->statements_)
        {
            statement->accept(this);
            printEdge(node, statement, "statement");
        }
    }
    void PrintVisitor::visit(const ClassDeclaration* node)
    {
        printVertex(node, "Class");
        node->id_->accept(this);
        printEdge(node, node->id_.get());
        for (auto method : node->methods_)
        {
            method->accept(this);
            printEdge(node, method);
        }
    }

    void PrintVisitor::visit(const Id* node)
    {
        printVertex(node, "id:" + node->name_);
    }

    void PrintVisitor::visit(const SystemOutStatement* node)
    {
        printVertex(node, "System.Out.Println");
        node->toPrint_->accept(this);
        printEdge(node, node->toPrint_.get());
    }

    void PrintVisitor::visit(const CallMemberExpression* node)
    {
        printVertex(node, "CallMember");
        node->id_->accept(this);
        printEdge(node, node->id_.get());
        node->expression_->accept(this);
        printEdge(node, node->expression_.get(), "expression");
        for (auto parameter : node->parameters_)
        {
            parameter->accept(this);
            printEdge(node, parameter, "parameter");
        }
    }

    void PrintVisitor::visit(const IntegerExpression* node)
    {
        printVertex(node, "int " + std::to_string(node->value_));
    }

    void PrintVisitor::visit(const BinaryExpression* node){
        printVertex(node, node->string_type_);
        node->left_->accept(this);
        node->right_->accept(this);
        printEdge(node, node->left_.get(), "left");
        printEdge(node, node->right_.get(), "right");
    }

    void PrintVisitor::visit(const BooleanExpression* node)  {
        printVertex(node, node->string_value_);
    }

    void PrintVisitor::visit(const MethodDeclaration* node)  {
        printVertex(node, "( " + node->modifier_->string_modifier_ + " " + node->type_->type_name_ + ") method");
        node->id_->accept(this);
        printEdge(node, node->id_.get());

        for (auto var : node->vars_)
        {
            var->accept(this);
            printEdge(node, var, "var");
        }

        for (auto statement : node->statements_)
        {
            statement->accept(this);
            printEdge(node, statement);
        }

        for (auto argument : node->arguments_)
        {
            argument->accept(this);
            printEdge(node, argument, "argument");
        }

        node->expression_->accept(this);
        printEdge(node, node->expression_.get(), "return");
    }

    void PrintVisitor::visit(const AssignStatement* node)  {
        printVertex(node, "=");
        node->lValue_->accept(this);
        node->rValue_->accept(this);
        printEdge(node, node->lValue_.get(), "left");
        printEdge(node, node->rValue_.get(), "right");
    }

    void PrintVisitor::visit(const IfElseStatement* node)
    {
        printVertex(node, "if");
        node->condition_->accept(this);
        printEdge(node, node->condition_, "condition");
        node->actionIf_->accept(this);
        printEdge(node, node->actionIf_, "if");
        node->actionElse_->accept(this);
        printEdge(node, node->actionElse_, "else");
    }

    void PrintVisitor::visit(const NotExpression* node)
    {
        printVertex(node, "Not");
        node->expression_->accept(this);
        printEdge(node, node->expression_.get());
    }

    void PrintVisitor::visit(const IntArrayExpression* node)
    {
        printVertex(node, "new int[]");
        node->size_->accept(this);
        printEdge(node, node->size_.get(), "size");
    }

    void PrintVisitor::visit(const ObjectExpression* node)
    {
        printVertex(node, "new");
        node->id_->accept(this);
        printEdge(node, node->id_.get());
    }

    void PrintVisitor::visit(const ArrayAssignStatement* node)
    {
        printVertex(node, "=");
        node->lValue_->accept(this);
        printEdge(node, node->lValue_.get(), "array");
        node->index_->accept(this);
        printEdge(node, node->index_.get(), "index");
        node->rValue_->accept(this);
        printEdge(node, node->rValue_.get());
    }

    void PrintVisitor::visit(const ArrayLengthExpression* node)
    {
        printVertex(node, "getLength");
        node->object_->accept(this);
        printEdge(node, node->object_.get(), "object");
    }

    void PrintVisitor::visit(const IdExpression* node)
    {
        printVertex(node, "idExpression");
        node->id_->accept(this);
        printEdge(node, node->id_.get(), "id");
    }

    void PrintVisitor::visit(const Statements* node)  {
        printVertex(node, "Statements");
        for (auto statement : node->statements_){
            statement->accept(this);
            printEdge(node, statement);
        }
    }

    void PrintVisitor::visit(const ArrayMemberExpression* node) {
        printVertex(node, "ArrayMember");
        node->object_->accept(this);
        node->index_->accept(this);
        printEdge(node, node->object_.get(), "object");
        printEdge(node, node->index_.get(), "position");
    }

    void PrintVisitor::visit(const Argument* node) {
        printVertex(node, node->type_->type_name_);
        node->id_->accept(this);
        printEdge(node, node->id_.get());
    }

    void PrintVisitor::visit(const VarDeclaration* node)
    {
        printVertex(node, node->type_->type_name_ +" "+ node->id_->name_);
    }

    void PrintVisitor::visit(const ThisExpression* node)
    {
        printVertex(node, "this");
    }

    void PrintVisitor::visit(const WhileStatement* node)
    {
        printVertex(node, "while");
        node->condition_->accept(this);
        printEdge(node, node->condition_.get(), "condition");
        node->action_->accept(this);
        printEdge(node, node->action_.get(), "action");
    }

    void PrintVisitor::printEdge(const Visitable* from, const Visitable* to)
    {
        output << "node" << from << "->" << "node" << to << "\n";
    }

    void PrintVisitor::printVertex(const Visitable* node, const std::string label)
    {
        output << "node" << node << "[label=\"" << label << "\"]\n";
    }

    void PrintVisitor::printEdge(const Visitable* from, const Visitable* to, std::string label)
    {
        output << "node" << from << "->" << "node" << to << "[label=\"" << label << "\"]\n";
    }

}