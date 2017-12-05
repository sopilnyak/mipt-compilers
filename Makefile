FLAGS = -ISymbolTable -ISyntaxTree -I. -ITypeChecker --std=c++14
PARSER_OBJ = syntax_analyzer.o flex_analyzer.o print_visitor.o

SYMBOL_TABLE_DIR = SymbolTable
SYMBOL_TABLE_SRC = $(wildcard $(SYMBOL_TABLE_DIR)/*.cpp)
SYMBOL_TABLE_OBJ = $(SYMBOL_TABLE_SRC:$(SYMBOL_TABLE_DIR)/%.cpp=./%.o)
SYMBOL_TABLE_VISITOR_DIR = SymbolTableVisitor
SYMBOL_TABLE_VISITOR_SRC = $(wildcard $(SYMBOL_TABLE_VISITOR_DIR)/*.cpp)
SYMBOL_TABLE_VISITOR = $(SYMBOL_TABLE_VISITOR_SRC:$(SYMBOL_TABLE_VISITOR_DIR)/%.cpp=./%.o)

all: ast table

table: $(SYMBOL_TABLE_OBJ) $(SYMBOL_TABLE_VISITOR) syntax_analyzer.o flex_analyzer.o print_visitor.o table.o
	g++ -g -o table $(SYMBOL_TABLE_OBJ) $(SYMBOL_TABLE_VISITOR) syntax_analyzer.o flex_analyzer.o print_visitor.o table.o $(FLAGS) -lfl

table.o: table.cpp
	g++ -g -c table.cpp -o table.o $(FLAGS)

ast: $(PARSER_OBJ) ast.o
	g++ -g -o ast print_visitor.o flex_analyzer.o syntax_analyzer.o ast.o -lfl

ast.o:
	g++ -g -c abstract_syntax_tree.cpp -o ast.o $(FLAGS)

syntax_analyzer.o: syntax_analyzer.y
	bison -dt --verbose syntax_analyzer.y && g++ -g -c --std=c++14 syntax_analyzer.tab.c -o syntax_analyzer.o

flex_analyzer.o: flex_analyzer.l
	flex flex_analyzer.l && g++ -g -c lex.yy.c -o flex_analyzer.o

./%.o: $(SYMBOL_TABLE_DIR)/%.cpp
	g++ -g -c $< -o $@ $(FLAGS)

./%.o: $(SYMBOL_TABLE_VISITOR_DIR)/%.cpp
	g++ -g -c $< -o $@ $(FLAGS)

print_visitor.o: AST/print_visitor.cpp
	g++ -g -c AST/print_visitor.cpp -o print_visitor.o $(FLAGS)

clean:
	rm ast table *.o syntax_analyzer.tab.h syntax_analyzer.tab.c lex.yy.c
