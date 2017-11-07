#ifndef MINIJAVA_ID_H
#define MINIJAVA_ID_H

#include "visitor.h"
#include <string>

class Id: public Visitable
{
public:
    explicit Id(const std::string &name)
    {
        if (!name.empty())
        {
            name_ = name;
        }
    }

    void accept(Visitor* visitor) override
    {
        visitor->visit(this);
    }

    std::string getName() {
        return name_;
    }

    std::string name_;
};

#endif // MINIJAVA_ID_H
