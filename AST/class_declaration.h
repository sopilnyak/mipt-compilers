#ifndef MINIJAVA_CLASS_DECLARATION_H
#define MINIJAVA_CLASS_DECLARATION_H

#include "visitor.h"
#include "var_declaration.h"
#include "method_declaration.h"

#include <vector>

namespace AST {

    class ClassDeclaration: public Visitable
    {
    public:
        explicit ClassDeclaration(Id* id, Id* parentId, VarDeclarationList* vars, MethodDeclarationList* methods, Coordinates coordinates):
                id_(id), parentId_(parentId), coordinates_(coordinates)
        {
            vars_.clear();
            if (vars != nullptr) {
                vars_ = std::move(vars->getVarDeclarations());
            }

            methods_.clear();
            if (methods != nullptr) {
                methods_ = std::move(methods->getMethods());
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> id_;
        std::unique_ptr<Id> parentId_;
        std::vector<VarDeclaration*> vars_{};
        std::vector<MethodDeclaration*> methods_{};
        Coordinates coordinates_;
    };

    class ClassDeclarationList
    {
    public:
        explicit ClassDeclarationList(ClassDeclarationList* previousList, ClassDeclaration* classDeclaration, Coordinates coordinates):
                coordinates_(coordinates)
        {
            class_declarations_.clear();
            if (previousList != nullptr)
            {
                class_declarations_ = std::move(previousList->getClassDeclarations());
            }
            class_declarations_.push_back(classDeclaration);
        }

        std::vector<ClassDeclaration*> getClassDeclarations()
        {
            return class_declarations_;
        }

        std::vector<ClassDeclaration*> class_declarations_{};
        Coordinates coordinates_;
    };

    class MainClass: public Visitable
    {
    public:
        explicit MainClass(Id* id, Id* parameters, StatementList* statements, Coordinates coordinates):
        id_(id), parameters_(parameters), coordinates_(coordinates)
        {
            statements_.clear();
            if (statements != nullptr) {
                statements_ = std::move(statements->getStatements());
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<Id> id_;
        Id* parameters_{};
        std::vector<IStatement*> statements_{};
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_CLASS_DECLARATION_H
