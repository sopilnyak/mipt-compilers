#include "AST/print_visitor.h"
#include "syntax_analyzer.tab.h"

extern AST::Program* program;

int main() 
{
    yyparse();

    AST::PrintVisitor* printer = new AST::PrintVisitor("./output.gv");
    program->accept(printer);

    delete printer;

    return 0;
}
