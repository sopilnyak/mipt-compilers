#ifndef MINIJAVA_VISITABLE_H
#define MINIJAVA_VISITABLE_H

class Visitor;

class Visitable
{
public:
    virtual void accept(Visitor* visitor) = 0;
    virtual ~Visitable() = default;
};

#endif // MINIJAVA_VISITABLE_H
