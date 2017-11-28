all: ast

clean:
	rm ast flex_analyzer.o syntax_analyzer.o print_visitor.o syntax_analyzer.tab.h syntax_analyzer.tab.c lex.yy.c

ast: syntax_analyzer.o flex_analyzer.o print_visitor.o ast.o
	g++ -g -o ast print_visitor.o flex_analyzer.o syntax_analyzer.o ast.o -lfl

ast.o:
	g++ -g -c abstract_syntax_tree.cpp -o ast.o

syntax_analyzer.o: syntax_analyzer.y
	bison -dt --verbose syntax_analyzer.y && g++ -g -c --std=c++14 syntax_analyzer.tab.c -o syntax_analyzer.o

flex_analyzer.o: flex_analyzer.l
	flex flex_analyzer.l && g++ -g -c lex.yy.c -o flex_analyzer.o

print_visitor.o: print_visitor.cpp
	g++ -g -c print_visitor.cpp -o print_visitor.o
