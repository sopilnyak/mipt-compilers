#include "print_visitor.h"
#include "syntax_analyzer.tab.h"
#include <iostream>

extern Program* program;

int main() 
{
    yyparse();
    std::cout << "Parsed" << std::endl;

    PrintVisitor* printer = new PrintVisitor("./output.gv");
    std::cout << "Printer created" << std::endl;
    program->accept(printer);
    std::cout << "Printer accepted" << std::endl;

    delete printer;

    return 0;
}
