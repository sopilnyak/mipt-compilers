#include "SymbolTableVisitor/TableVisitor.h"
#include "syntax_analyzer.tab.h"

extern std::unique_ptr<AST::Program> program;

int main() {
    yyparse();
    SymbolTable::TableVisitor visitor;
    visitor.ParseProgram(program.get());
}
