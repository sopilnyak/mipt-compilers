#ifndef MINIJAVA_VISITABLE_H
#define MINIJAVA_VISITABLE_H

namespace AST {

    struct Coordinates
    {
        int Row;
        int Column;
        Coordinates(int row, int column):
                Row(row),
                Column(column)
        {}
        Coordinates(const Coordinates& coordinates) :
                Row(coordinates.Row), Column(coordinates.Column)
        {}
    };

    class Visitor;

    class Visitable
    {
    public:
        virtual void accept(Visitor* visitor) = 0;
        virtual ~Visitable() = default;
    };

}

#endif // MINIJAVA_VISITABLE_H
