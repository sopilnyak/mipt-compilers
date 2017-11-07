#ifndef MINIJAVA_PROGRAM_H
#define MINIJAVA_PROGRAM_H

#include "visitor.h"
#include "class_declaration.h"

#include <vector>
#include <iostream>

class Program: public Visitable
{
public:
    explicit Program(MainClass* main, ClassDeclarationList* classes):
            main_(main)
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

    MainClass* main_;
    std::vector<ClassDeclaration*> classes_;
};

#endif // MINIJAVA_PROGRAM_H
