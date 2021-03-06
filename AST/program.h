#ifndef MINIJAVA_PROGRAM_H
#define MINIJAVA_PROGRAM_H

#include "visitor.h"
#include "class_declaration.h"

#include <vector>
#include <iostream>

namespace AST {

    class Program: public Visitable
    {
    public:
        explicit Program(MainClass* main, ClassDeclarationList* classes, Coordinates coordinates):
                main_(main), coordinates_(coordinates)
        {
            classes_.clear();
            if (classes != nullptr) {
                classes_ = std::move(classes->getClassDeclarations());
            }
        }

        void accept(Visitor* visitor) override
        {
            visitor->visit(this);
        }

        std::unique_ptr<MainClass> main_;
        std::vector<ClassDeclaration*> classes_{};
        Coordinates coordinates_;
    };

}

#endif // MINIJAVA_PROGRAM_H
